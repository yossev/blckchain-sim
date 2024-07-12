#include <cstdint>
#ifndef CONFIG_H
#define CONFIG_H

class Config {
public:
    static uint32_t difficulty;
    static uint32_t maxPeers;
    static void loadConfig(const auto&);
};








#endif