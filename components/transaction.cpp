#include "transaction.h"
#include <iostream>

Transaction::Transaction(int transactionID, unsigned long senderAddress, unsigned long receiverAddress, std::string transactionDetails) {
    this->transactionID = transactionID;
    this->senderAddress = senderAddress;
    this->receiverAddress = receiverAddress;
    this->transactionDetails = transactionDetails;
}

std::string Transaction::getTransactionDetails(Transaction transaction) {
    std::string details;
    details += "Sender's Public Address: " + std::to_string(transaction.senderAddress) + "\n";
    details += "Receiver's Public Address: " + std::to_string(transaction.receiverAddress) + "\n";
    details += "Data Payload: " + transaction.transactionDetails + "\n";
    details += "Transaction ID: " + std::to_string(transaction.transactionID) + "\n";
    return details;
}
