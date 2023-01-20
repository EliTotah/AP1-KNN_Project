// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "StandardIO.h"
#include "DefaultIO.h"
using namespace std;

StandardIO::StandardIO(int _sock) : DefaultIO (_sock) {}

string StandardIO::read() {
    string string1;
    // scan the two vector from the user
    getline(cin, string1);
    return string1;
}

void StandardIO::write(string s) {
    cout << s << endl;
}
