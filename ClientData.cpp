// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "ClientData.h"

ClientData::ClientData() {
    this->k = 5;
    this->metrica = "AUC";
}

void ClientData::setSettings(int k, string metrica){
    this->k = k;
    this->metrica = metrica;
}

void ClientData::setNonClassified(vector<string> test){
    this->NonClassified = test;
}

void ClientData::setClassified(vector <string> v){
    this->Classified = v;
}
void ClientData:: setDataBase(vector<string> train){
     this->dataBase = train;
}
int ClientData::getK(){
    return  (this->k);
}

void ClientData::setFlag() {
    this->flag = 1;
}

int ClientData::getFlag() {
    return this->flag;
}

string ClientData:: getMetrica(){
    return (this->metrica);
}

vector<string> ClientData:: getNonClassified(){
    return this->NonClassified;
}

vector<string> ClientData:: getDataBase(){
    return this->dataBase;
}

vector<string> ClientData::getClassified(){
    return this->Classified;
}
    