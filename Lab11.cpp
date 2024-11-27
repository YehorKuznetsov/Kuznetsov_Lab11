#include <iostream>
#include <regex>
#include <string>


using namespace std;

struct Mail {
private:
    string sender = nullptr;
    string recipient = nullptr;
    string postalCode;

public:
    Mail(string s, string r, string p) : sender(move(s)), recipient(move(r)), postalCode(move(p)) {}

    [[nodiscard]] string getPostalCode() const {
        return postalCode;
    }
};

string checkRegion(const string& postalCode) {
    regex ukraineRegex("^\\d{5}$");
    if (regex_match(postalCode, ukraineRegex)) {
        return "Ukraine";
    }
    return "Unknown region";
}

int main() {
    const Mail mail("Vasya", "Volodya", "12345");
    cout << "Postal Code: " << mail.getPostalCode() << endl;
    cout << "Region: " << checkRegion(mail.getPostalCode()) << endl;
    return 0;
}

