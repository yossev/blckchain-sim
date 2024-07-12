#include "blockchain.h"
#include <vector>
#include "block.h"
#include "transaction.h"

Blockchain::Blockchain(Config config) {
    difficulty = config.difficulty;
    maxPeers = config.maxPeers;
    chain.emplace_back(Block(0, "Genesis Block")); // Create Gen Block once chain is on
    std::vector<Transaction> transactionPool; // Transaction pool resides in blockchain
}

void Blockchain::addBlock(Block newBlock){
    newBlock.prevHash = getLastBlock().getHash();
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

Block Blockchain::getLastBlock(){
    return chain.back();
}
Block Blockchain::getAtIndex(int index){
    return chain[index];
}


// Chain Validation With Hash Value Validation

bool Blockchain::isChainValid(){
    for (uint32_t i = 1; i < chain.size(); i++){
        Block currentBlock = chain[i];
        Block previousBlock = chain[i-1];

        if(currentBlock.getHash() != currentBlock.calculateHash()){
            return false; // hash mismatch
        }

        if(currentBlock.prevHash != previousBlock.getHash()){
            return false;
        }
    }
    return true;
}