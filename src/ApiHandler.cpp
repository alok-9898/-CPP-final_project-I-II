#include "ApiHandler.h"
#include <curl/curl.h>
#include <sstream>

// Callback for libcurl to write received data into a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Constructor: stores the API key
ApiHandler::ApiHandler(const std::string& apiKey) : apiKey(apiKey) {}

// Fetches weather data for the specified city using OpenWeatherMap API
std::string ApiHandler::fetchWeather(const std::string& city) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::ostringstream url;

    // Build the API request URL
    url << "https://api.openweathermap.org/data/2.5/weather?q=" << city
        << "&appid=" << apiKey << "&units=metric";

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl); // Perform the request
        curl_easy_cleanup(curl);       // Clean up
    }
    return readBuffer; // Return the raw JSON response
}