// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "Command.h"

Command::Command(DefaultIO *_dio, ClientData *_data) : dio(_dio), data(_data) {}

string Command::getDec() {
    return this->description;
}

DefaultIO* Command::getIO() {
    return this->dio;
}

ClientData* Command::getData() {
    return this->data;
}


