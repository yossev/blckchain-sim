#include "config.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Config loadConfig(const std::string& filename) {
    Config config;

    std::ifstream configFile(filename);
    if (configFile.is_open()) {
        json configJson;
        configFile >> configJson;

        if (configJson.contains("difficulty")) {
            config.difficulty = configJson["difficulty"].get<uint32_t>();
        } else {
            std::cerr << "Config file missing 'difficulty', using default value." << std::endl;
            config.difficulty = 4; 
        }

        if (configJson.contains("maxPeers")) {
            config.maxPeers = configJson["maxPeers"].get<uint32_t>();
        } else {
            std::cerr << "Config file missing 'maxPeers', using default value." << std::endl;
            config.maxPeers = 10; 
        }
    } else {
        std::cerr << "Could not open config file, using default values." << std::endl;
        config.difficulty = 4; 
        config.maxPeers = 10;  
    }

    return config;
}
