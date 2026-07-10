// Simple automation example: generate prompts, call an AI API, and upload videos.
// Build: g++ automator.cpp -lcurl -o automator
// Requirements: libcurl, nlohmann/json.hpp (https://github.com/nlohmann/json)

#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include <sstream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string call_openai_chat(const std::string &api_key, const std::string &prompt) {
    CURL *curl = curl_easy_init();
    if (!curl) return "";

    std::string readBuffer;
    struct curl_slist *headers = nullptr;
    std::string auth = "Authorization: Bearer " + api_key;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, auth.c_str());

    json body;
    body["model"] = "gpt-3.5-turbo";
    body["messages"] = json::array({ { {"role","user"}, {"content", prompt} } });

    std::string payload = body.dump();

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        return "";
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    try {
        auto j = json::parse(readBuffer);
        if (j.contains("choices") && j["choices"].is_array() && !j["choices"].empty()) {
            auto msg = j["choices"][0]["message"]["content"].get<std::string>();
            return msg;
        }
    } catch (const std::exception &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }

    return "";
}

// Placeholder uploader: calls an external CLI (user must provide/install one).
// Example uses a hypothetical `youtubeuploader` command. Replace with your own uploader.
int upload_video_with_cli(const std::string &video_path, const std::string &title, const std::string &description) {
    std::ostringstream cmd;
    // WARNING: This uses system(); ensure you trust the uploader and escape inputs in real use.
    cmd << "youtubeuploader upload --file \"" << video_path << "\" --title \"" << title
        << "\" --description \"" << description << "\"";
    std::cout << "Running uploader: " << cmd.str() << std::endl;
    return std::system(cmd.str().c_str());
}

int main(int argc, char** argv) {
    std::string openai_key;
    const char* env = std::getenv("OPENAI_API_KEY");
    if (env) openai_key = env;

    if (openai_key.empty()) {
        std::cerr << "Please set OPENAI_API_KEY environment variable." << std::endl;
        return 1;
    }

    // Simple prompt template for generating a video script & description
    std::string topic = (argc > 1) ? argv[1] : "how to make a simple C++ game";
    std::ostringstream prompt;
    prompt << "Write a short video script (around 4-6 short paragraphs) and a concise YouTube title and description for a video about: " << topic
           << "\nInclude a short 2-3 sentence hook, 3 steps with bullet-like lines, and a call to action.";

    std::cout << "Generating script and metadata for topic: " << topic << std::endl;
    std::string ai_response = call_openai_chat(openai_key, prompt.str());
    if (ai_response.empty()) {
        std::cerr << "AI call failed or returned empty response." << std::endl;
        return 1;
    }

    // Save AI output locally
    std::string out_file = "generated_script.txt";
    std::ofstream ofs(out_file);
    ofs << ai_response;
    ofs.close();
    std::cout << "Saved AI output to " << out_file << std::endl;

    // For demo: require a path to an already-created video file to upload
    if (argc < 2) {
        std::cout << "To upload a video, run: automator <topic> <video-file-path>" << std::endl;
        return 0;
    }

    if (argc >= 3) {
        std::string video_path = argv[2];
        // Simple extraction of title/description from AI output (naive): first line -> title, rest -> description
        std::istringstream iss(ai_response);
        std::string title_line;
        std::getline(iss, title_line);
        std::string rest((std::istreambuf_iterator<char>(iss)), std::istreambuf_iterator<char>());

        int rc = upload_video_with_cli(video_path, title_line.empty() ? topic : title_line, rest);
        if (rc == 0) std::cout << "Upload command finished (exit 0). Check uploader logs for status." << std::endl;
        else std::cout << "Uploader returned non-zero exit code: " << rc << std::endl;
    }

    return 0;
}
