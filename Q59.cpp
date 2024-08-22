#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


std::string Decode(
    const std::vector<unsigned> &cipherMsg,
    const std::vector<unsigned> &key, size_t length);
bool IsOnlyAlphabetical(const std::string &msg);
void GetNextKey(std::vector<unsigned> &currentKey);
std::string Key2Str(const std::vector<unsigned> &key);

int main()
{
    // Read cipher file
    std::ifstream ifs;
    ifs.open("resources/0059_cipher.txt");
    std::string token;
    std::vector<unsigned> cipherMsg;
    while (std::getline(ifs, token, ',')) {
        cipherMsg.push_back(std::stoi(token));
    }

    // Try keys from "aaa" to "zzz"
    std::vector<unsigned> key{ 
        static_cast<unsigned>('a'),
        static_cast<unsigned>('a'),
        static_cast<unsigned>('a'),
    };
    for (int i{ 0 }; i < 25 * 26 * 26; i++) {
        const std::string &msg = Decode(cipherMsg, key, 50);
        if (IsOnlyAlphabetical(msg)) {
            std::cout << "Key = " << Key2Str(key) << "\n";
            std::cout << msg << "\n" << std::endl;
        }
        GetNextKey(key);
    }

    // Key = "exp"
    std::cout << "-------------------- Message Found! --------------------\n";
    key = std::vector<unsigned> { 
        static_cast<unsigned>('e'),
        static_cast<unsigned>('x'),
        static_cast<unsigned>('p'),
    };
    const std::string &msg = Decode(cipherMsg, key, cipherMsg.size());
    std::cout << msg << "\n\n";
    long int sumAsciiValues{ 0 };
    for (const char &c : msg) {
        sumAsciiValues += c;
    }
    std::cout << "Sum of ascii values = " << sumAsciiValues << std::endl;
}

void GetNextKey(std::vector<unsigned> &key)
{
    unsigned max = static_cast<unsigned>('z');
    for (size_t i{ key.size() - 1 }; i >= 0; i--) {
        if (key[i] < max) {
            key[i]++;
            break;
        }
        key[i] = static_cast<unsigned>('a');
    }
}

bool IsOnlyAlphabetical(const std::string &msg)
{
    return std::find_if(msg.begin(), msg.end(),
        [](const char &c) {
            return !std::isalnum(c) && c != ' ';
        }) == msg.end();
}

std::string Decode(
    const std::vector<unsigned> &cipherMsg,
    const std::vector<unsigned> &key, size_t length)
{
    std::stringstream ss;
    size_t keyIdx{ 0 };
    for (size_t i{ 0 }; i < std::min(cipherMsg.size(), length); i++) {
        char c = static_cast<char>(
            cipherMsg[i] ^ key[keyIdx]);
        ss << c;
        keyIdx = (keyIdx + 1) % 3;
    }
    return ss.str();
}

std::string Key2Str(
    const std::vector<unsigned> &key)
{
    std::string s;
    s += static_cast<char>(key[0]);
    s += static_cast<char>(key[1]);
    s += static_cast<char>(key[2]);
    return s;
}