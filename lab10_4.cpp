#include <iostream>
using namespace std;
class Encryptor;
class Message
{
    private:
        string msg;
    public:
        Message(string m)
        {
            msg = m;
        }

       
    friend class Encryptor;
};
class Encryptor
{
    
    public:
    string encryptMessage(const Message& m) {
        string encrypted = m.msg;
        for (char& c : encrypted) {
            if (isalpha(c)) {
                if (c == 'z') c = 'a';
                else if (c == 'Z') c = 'A';
                else c++;
            }
        }
        return encrypted;
    }
        
  
};

int main()
{
    Message myMsg("HelloWorld");
    Encryptor enc;

    string result = enc.encryptMessage(myMsg);
    cout << "Encrypted Message: " << result << endl;

return 0;
}