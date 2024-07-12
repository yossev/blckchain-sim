#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include "config.h"
#include <vector>
class Blockchain {
public:
    Blockchain(Config config); // constructors
    void addBlock(Block newBlock);
    Block getLastBlock();
    Block getAtIndex(int index);
    bool isChainValid();

private:
    // Blockchain difficulty is set automatically by the Blockchain network
    uint32_t difficulty;
    uint32_t maxPeers;
    std::vector<Block> chain;   
};



#endif