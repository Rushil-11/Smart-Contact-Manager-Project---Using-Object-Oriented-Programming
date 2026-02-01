#include <bits/stdc++.h>
using namespace std;
    class Contact{
        private:
        string Name; string Num; string Tag; string Email;
        public:
        Contact(string name, string num, string tag, string email){
            Name = name; Num = num; Tag = tag; Email = email; 
        }
        string getName(){return Name; }
        string getNum(){return Num; }
        string getTag(){return Tag; }
        string getEmail(){return Email; }
};