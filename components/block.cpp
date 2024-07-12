#include <iostream>
#include "block.h"
#include <vector>
#include "transaction.h"
Block::Block(uint32_t indexIn, const auto &dataIn):index(indexIn), data(dataIn), nonce(0), hash(""), prevHash(""){
    timestamp = std::time(0);
    dataIn = Transaction(); // Cin for that one
}

// Take all the data of the Block and hash it.

/*

SHA256 was used because of its Collison resistance, Hiding and Puzzle Friendliness

*/
std::string Block::calculateHash() const {

    std::stringstream ss;

    ss << index << timestamp << data << nonce << prevHash;


    std::string str =  ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256; // Holds the state / context for computing the SHA_256 Hash
    SHA256_Init(&sha256); // instance of sha256
    SHA256_Update(&sha256, str.c_str(), str.size()); // feed input data into the hashing concept
    SHA256_Final(hash, &sha256); // Calculate the final hash value and store it in hash


    std::stringstream ssHash;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ssHash << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ssHash.str();
}

std::string Block::getHash(){
    return hash;
}
/*

FTF: Implement Multi Threadding for larger Blockchains

*/

// PoW Consensus
void Block::mineBlock(uint32_t difficulty){
    std::string tempHash;
    std::string str(difficulty, '0');
        while (hash.substr(0, difficulty) != str) {
            nonce++;
            tempHash = calculateHash();
            if (tempHash.substr(0, difficulty) == str) {
                hash = tempHash;
                break;
            }
        }
        std::cout << "Block mined. Hash: " << hash << ", Nonce: " << nonce << std::endl;
};
