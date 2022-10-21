#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
string to_lower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {

        // convert str[i] to lowercase
        str[i] = tolower(str[i]);

        // cout << ch;
    }
    return str;
}
void read(string file)
{
    ifstream fin;
    string line;
    fin.open(file);
    int c = 0;
    vector<string> label;
    int col = 0, row = 0;

    int blank = 0;
    while (!fin.eof())
    {
        fin >> line;
        stringstream ss(line);
        int f=0;
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            // cout<<substr<<endl;
            cout<<line<<endl;
            if (row == 0)
            {
                label.push_back(substr);
                // continue;
                break;
            }
            else if (to_lower(substr).find("lawyer") != string::npos)
            {
                cout << col + 1 << " " << label[col] << " " << substr << endl;
                break;
            }
            else if (to_lower(substr).find("provakil") != string::npos)
            {
                cout << col + 1 << " " << label[col] << " " << substr << endl;
                break;
            }
            else if (substr == "")
            {
               blank++;
               continue;
            }
            
            
        }
        row++;
    }
    cout << blank << " empty cells found\n";
}
int main()
{
    read("input.csv");
    return 0;
}