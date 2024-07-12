#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"


int main(){
    Blockchain myBlockchain; // create a new blockchain with the Genisis Block
    std::cout << "Test" + myBlockchain.getLastBlock().getHash() << std::endl;

    return 0;
}