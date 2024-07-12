#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>
class Blockchain {
public:
    Blockchain(); // constructor
    void addBlock(Block newBlock);
    Block getLastBlock();
    Block getAtIndex(int index);
    bool isChainValid();

private:
    // Blockchain difficulty is set automatically by the Blockchain network
    uint32_t difficulty;
    std::vector<Block> chain;

    
};



#endif