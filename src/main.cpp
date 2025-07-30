#include <iostream>
#include <fstream>
#include <iomanip>      // For std::setw and std::setprecision
#include "ApiHandler.h"
#include "json.hpp"     // Include JSON library

using json = nlohmann::json;

// Reads the API key from the .env file
std::string getApiKey() {
    std::ifstream envFile(".env");
    std::string line, key;
    while (std::getline(envFile, line)) {
        if (line.find("API_KEY=") == 0) {
            key = line.substr(8); // Remove "API_KEY=" prefix
            break;
        }
    }
    return key;
}

int main() {
    std::string apiKey = getApiKey();
    if (apiKey.empty()) {
        std::cerr << "❌ Error: API key not found in .env file.\n";
        return 1;
    }

    ApiHandler api(apiKey);

    std::string city;
    std::cout << "Enter city name: ";
    std::cin >> city;

    std::string weatherData = api.fetchWeather(city);

    try {
        json weatherJson = json::parse(weatherData);

        // Check for error in API response
        if (weatherJson.contains("cod") && weatherJson["cod"] != 200) {
            std::cerr << "❌ API Error: " << weatherJson["message"] << "\n";
            return 1;
        }

        // Extract weather data
        std::string desc      = weatherJson["weather"][0]["description"];
        double temp           = weatherJson["main"]["temp"];
        double feelsLike      = weatherJson["main"]["feels_like"];
        int humidity          = weatherJson["main"]["humidity"];
        double windSpeed      = weatherJson["wind"]["speed"];
        std::string cityName  = weatherJson["name"];
        std::string country   = weatherJson["sys"]["country"];

        // Display weather info
        std::cout << "\n=========== Weather Report ===========\n";
        std::cout << "Location     : " << cityName << ", " << country << "\n";
        std::cout << "Temperature  : " << std::fixed << std::setprecision(1)
                  << temp << "°C (Feels like " << feelsLike << "°C)\n";
        std::cout << "Humidity     : " << humidity << "%\n";
        std::cout << "Wind Speed   : " << windSpeed << " m/s\n";
        std::cout << "Description  : " << desc << "\n";
        std::cout << "===========================================\n";

    } catch (const std::exception& e) {
        std::cerr << "❌ Failed to parse weather data: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
