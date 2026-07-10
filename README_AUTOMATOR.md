Automator C++ example
=====================

What this does
- Demonstrates prompt generation for video content.
- Calls the OpenAI Chat Completions API via HTTP (libcurl + nlohmann/json).
- Shows a placeholder for uploading an existing video using an external CLI.

Requirements
- A C++ compiler (g++/clang++).
- libcurl development headers and library.
- nlohmann/json single-header (place `json.hpp` or install from package manager).
- An external uploader CLI (example uses a placeholder command `youtubeuploader`).

Setup
1. Install libcurl (Windows: MSYS2/mingw, or use your package manager).
2. Install or place `nlohmann/json.hpp` where your compiler can find it.
3. Set your OpenAI API key as an environment variable:

```powershell
setx OPENAI_API_KEY "your_api_key_here"
```

Build

```bash
g++ automator.cpp -lcurl -o automator
```

Usage

Generate a script only:

```bash
./automator "topic about C++"
```

Generate and upload an existing video file (uploader CLI required):

```bash
./automator "topic about C++" path/to/video.mp4
```

Notes & Next steps
- The uploader step calls an external CLI (`youtubeuploader`) as a placeholder. Replace `upload_video_with_cli` with your platform-specific upload code or integrate OAuth+YouTube Data API.
- Sanitize and escape inputs before using `system()` in production. Consider using a library-based uploader or direct API calls with OAuth.
- This example focuses on structure and a minimal working AI HTTP call; adapt models, parameters, and error handling as needed.

License
- Use as you like for learning and prototyping.
