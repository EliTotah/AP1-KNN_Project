// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "StandardIO.h"
#include "DefaultIO.h"
using namespace std;

/******************
* Function Name: execute
* Input: DefaultIO *dio, ClientData *data
* Output: an object DownloadCommand
* Function Operation:constructor of the DownloadCommand class, which is derived from the Command class. It takes two parameters:
 a DefaultIO pointer and a ClientData pointer, and initializes the corresponding member variables of the class. Also, it sets the description of the command
******************/
StandardIO::StandardIO(int _sock) : DefaultIO (_sock) {}
/******************
* Function Name: read
* Input: void
* Output: string
* Function Operation:// read function that creates a string variable 'string1' and reads a line from the standard input stream 'cin' and stores it in 'string1'
******************/
string StandardIO::read() {
    string string1;
    // scan the two vector from the user
    getline(cin, string1);
    return string1;
}
/******************
* Function Name: write
* Input: string s
* Output: void
* Function Operation:// write function that takes a string argument 's' and writes it to the standard output stream 'cout' followed by a newline
******************/
void StandardIO::write(string s) {
    cout << s << endl;
}
