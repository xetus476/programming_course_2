#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    // cin, cout
    cout << "cin/cout demo:" << endl;
    int x;
    cout << "Enter int: ";
    cin >> x;
    cout << "Entered: " << x << endl;

    // scanf, printf
    printf("scanf/printf demo:\n");
    int y;
    printf("Enter int: ");
    scanf("%d", &y);
    printf("Entered: %d\n", y);
    cin.ignore(); __BFLT16_HAS_QUIET_NAN__

    // fopen, fclose, fprintf, fscanf
    FILE *fp = fopen("demo.txt", "w");
    fprintf(fp, "Hello\n");
    fclose(fp);
    fp = fopen("demo.txt", "r");
    char buf[100];
    fscanf(fp, "%s", buf);
    printf("From file: %s\n", buf);
    fclose(fp);

    // feof, EOF
    fp = fopen("demo.txt", "r");
    printf("Char by char:\n");
    char ch;
    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch != EOF) putchar(ch);
    }
    fclose(fp);


   
    cout << "Vvedite slova (po odnomu na stroku, pustaya stroka dlya zaversheniya):" << endl;
    vector<string> words;
    string w;
    while (getline(cin, w)) {
        if (w.empty()) break;
        stringstream ss(w);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
    }

    string longestRoot = "";
    string mostImportant = "";
    int maxCount = 0;
    vector<string> rootedWords;

    for (int i = 0; i < words.size(); i++) {

        int count = 0;
        vector<string> currentRooted;

        for (int j = 0; j < words.size(); j++) {

            if (i != j) {

                if (words[j].find(words[i]) == 0)
                    count++;
                    currentRooted.push_back(words[j]);

            }
        }

        if (count > 0) {

            if (words[i].length() > longestRoot.length()) {
                longestRoot = words[i];
                rootedWords = currentRooted;
            }

            if (count > maxCount) {
                maxCount = count;
                mostImportant = words[i];
            }

        }
    }

    
    FILE *out1 = fopen("output1.txt", "w");
    if (longestRoot.empty()) {
        fprintf(out1, "NO\n");
    } else {
        fprintf(out1, "%s\n", longestRoot.c_str());
        for (auto& wd : rootedWords) {
            fprintf(out1, "%s\n", wd.c_str());
        }
    }
    fclose(out1);

    FILE *out2 = fopen("output2.txt", "w");
    if (longestRoot.empty() || mostImportant.empty()) {
        fprintf(out2, "NO\n");
    } else {
        fprintf(out2, "%s\n%s\n", longestRoot.c_str(), mostImportant.c_str());
    }
    fclose(out2);

}