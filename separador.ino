#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> separateEmails(string emails) {
    vector<string> result;
    int start = 0;
    int end = 0;
    int len = emails.length();
    
    while (end < len) {
        if (emails[end] == ',' || emails[end] == ';') {
            result.push_back(emails.substr(start, end - start));
            start = end + 1;
        }
        end++;
    }
    
    // Adiciona o último e-mail (ou o único se não houver separadores)
    if (start < end) {
        result.push_back(emails.substr(start, end - start));
    }
    
    return result;
}

int main() {
    string emails = "email1@example.com,email2@example.com;email3@example.com,email4@example.com";
    vector<string> emailList = separateEmails(emails);
    
    for (string email : emailList) {
        cout << email << endl;
    }
    
    return 0;
}
