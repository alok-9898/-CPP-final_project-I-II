#pragma once
#include <string>

// ApiHandler handles requests to the OpenWeatherMap API
class ApiHandler {
public:
    // Constructor: takes your API key
    ApiHandler(const std::string& apiKey);

    // Fetch weather data for a given city (returns JSON string)
    std::string fetchWeather(const std::string& city);

private:
    std::string apiKey; // Stores the API key
};