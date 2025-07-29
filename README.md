# CPP-final_project I/II

## Project Structure
```bash
WeatherApp/
├── .vscode/                    # VS Code settings for build/debug
│   ├── tasks.json             # Build command configurations (g++, Raylib, curl)
│   ├── launch.json            # Debug configurations
│   └── c_cpp_properties.json  # Include paths, C++ standards
│
├── assets/                     # Resources for Raylib
│   ├── fonts/                 # Custom fonts for UI
│   ├── images/                # Weather icons and backgrounds
│   └── sounds/                # Optional sound effects
│
├── include/                    # Header files
│   ├── ApiHandler.h           # Weather API interface
│   └── WeatherUI.h           # UI components declarations
│
├── src/                       # Source files
│   ├── main.cpp              # Application entry point
│   ├── ApiHandler.cpp        # API handling implementation
│   └── WeatherUI.cpp        # UI components implementation
│
├── libs/                      # External libraries
│   ├── raylib/               # Raylib graphics library
│   └── curl/                 # CURL for HTTP requests
│
├── build/                     # Compiled binaries
│   └── weather_app.exe       # Main executable
│
├── .env                      # API credentials (git-ignored)
├── .gitignore               # Git ignore rules
├── README.md                # Project documentation
└── CMakeLists.txt          # CMake build configuration
```

## Setup Instructions

1. Install required dependencies:
   - MinGW-w64 with g++
   - Raylib
   - libcurl

2. Configure environment:
   - Copy `.env.example` to `.env`
   - Add your OpenWeatherMap API key to `.env`

3. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the application:
   ```bash
   ./build/weather_app.exe
   ```

## Project Components

### ApiHandler
- Manages API requests to OpenWeatherMap
- Handles JSON parsing of weather data
- Implements error handling for API calls

### WeatherUI
- Renders weather information using Raylib
- Handles user input and interface updates
- Displays weather icons and temperature data

## Dependencies
- Raylib: Graphics library for rendering
- libcurl: HTTP request handling
- nlohmann/json: JSON parsing (optional)

## Contributing
1. Fork the repository
2. Create a feature branch
3. Submit a pull request

## License
MIT License
```

2. Create a `.gitignore` file:

````plaintext
// filepath: d:\cpp final\CPP-final_project-I-II\.gitignore
# Build directory
build/
bin/

# Environment variables
.env

# IDE specific files
.vscode/
*.suo
*.user
*.sln.docstates

# Compiled Object files
*.slo
*.lo
*.o
*.obj

# Precompiled Headers
*.gch
*.pch

# Compiled Dynamic libraries
*.so
*.dylib
*.dll

# Executables
*.exe
*.out
*.app