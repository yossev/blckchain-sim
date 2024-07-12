#include <iostream>
#include "blockchain.h"
#include "block.h"
#include "transaction.h"


int main(){
    Blockchain myBlockchain;

    std::cout << "Mining block 1..." << std::endl;
    myBlockchain.addBlock(Block(1, "Transaction Data 1"));

    std::cout << "Mining block 2..." << std::endl;
    myBlockchain.addBlock(Block(2, "Transaction Data 2"));


    return 0;
}