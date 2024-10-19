import <iostream>;
import <sstream>;
import <fstream>;

using namespace std;

int main() {
    ifstream file{"midterm_answer_key.txt"};
    string line;
    while (getline(file, line)) {
        string word;
        int counter = 0;
        istringstream iss{line};
        while (iss >> word) ++counter;
        char decrypt_char = counter;
        cout << decrypt_char;
    }
}