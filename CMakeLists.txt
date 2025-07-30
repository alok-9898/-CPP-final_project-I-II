cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(CURL REQUIRED)                # Finds libcurl
find_package(nlohmann_json CONFIG REQUIRED) # Finds nlohmann_json (if used)

# Add executable and source files
add_executable(weather_app 
    src/main.cpp
    src/ApiHandler.cpp
)

# Link libraries to the executable
target_link_libraries(weather_app PRIVATE
    CURL::libcurl
    nlohmann_json::nlohmann_json
)

# Include directories for header files
target_include_directories(weather_app PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Optionally add MSYS2 paths for Windows builds
list(APPEND CMAKE_PREFIX_PATH "C:/msys64/mingw64/bin")
list(APPEND CMAKE_PREFIX_PATH "C:/msys64/usr/bin")

# (Legacy) Include and link directories for curl
include_directories(include)
link_directories(libs/curl/lib)