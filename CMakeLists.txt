cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(CURL REQUIRED)

# Setup nlohmann-json
find_package(nlohmann_json CONFIG REQUIRED)

# Add executable
add_executable(weather_app 
    src/main.cpp
    src/ApiHandler.cpp
)

# Link libraries
target_link_libraries(weather_app PRIVATE
    CURL::libcurl
    nlohmann_json::nlohmann_json
)

# Include directories
target_include_directories(weather_app PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Add MSYS2 paths
list(APPEND CMAKE_PREFIX_PATH "C:/msys64/mingw64/bin")
list(APPEND CMAKE_PREFIX_PATH "C:/msys64/usr/bin")