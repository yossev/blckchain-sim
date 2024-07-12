#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h> // For SHA-256 hashing

class Block {
public:
    Block(uint32_t indexIn, const auto &dataIn);

    std::string getHash(); // Getter for block hash
    void mineBlock(uint32_t difficulty); // method to mine the block
    std::string prevHash;
    std::string calculateHash() const;
    
private:
    int64_t timestamp;
    uint32_t index; // Index of the block
    std::string data;
    std::string hash;
    uint64_t nonce;
};



#endif