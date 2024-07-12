
#include <vector>
#include <string>
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction{

public:
    Transaction(int transactionID, unsigned long senderAddress, unsigned long receiverAddress, std::string transactionDetails);
    std::string getTransactionDetails(Transaction transaction);
private:
    int transactionID;
    unsigned long senderAddress;
    unsigned long receiverAddress;
    std::string transactionDetails; // Data String
};


#endif