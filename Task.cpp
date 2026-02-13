#include <bits/stdc++.h>
#include "Contact.cpp"
using namespace std;
class Task{
    vector <Contact> contact; vector<string>sname; vector<string>snum; 
    public: 
    void loadContact(){
        contact.clear(); // to ensure empty vector
        ifstream fin ("Contact.txt"); 
        string line; 
        while(getline(fin, line)){
            stringstream ss(line); //makes line into stream of string
            string name; string num; string tag; string email;
            getline(ss, name, '|'); getline(ss, num, '|'); getline(ss, tag, '|'); getline(ss, email,'|'); 
            contact.push_back(Contact(name, num, tag, email)); 
        }
        fin.close() ;
    }
    void storeContact(vector <Contact> &contact){//to store contacts to local txt file
        ofstream fout("Contact.txt"); 
        for(auto &c : contact){
            fout << c.getName() << '|' << c.getNum() << '|'<< c.getTag() << '|' << c.getEmail() <<  endl; 
        }fout.close();
    }
    void seeTask(){
        cout << "Enter the Key for the respective task: " << endl;
        cout << "1 : Add Contact " << endl;
        cout << "2 : View Contact" << endl;
        cout << "3 : Update Contact" << endl;
        cout << "4 : Delete Contact " << endl;
        cout << "5 : View Stats  " << endl;
        cout << "6 : Get Contacts as Text(.txt) file " << endl;
        cout << "7 : Delete all contacts " << endl;
    }
    void addContact(string name, string num, string tag, string email){
        contact.push_back(Contact(name, num, tag, email)); 
        storeContact(contact);
    }
    void viewfromLast(){//shows all contact in reverse order, last to first
        int i = contact.size()-1; if(contact.size() == 0){cout << "No contact saved yet." << endl; return; }
        while(i>=0){
            cout << "Name: " << contact[i].getName() << endl; 
            cout << "Number: " << contact[i].getNum() << endl; 
            cout << "Tag: " << contact[i].getTag() << endl; 
            cout << "Email: " << contact[i].getEmail() << endl; cout << endl; 
            i--; 
        }
    } 
    void viewfromFirst(){
        int s = contact.size();  int i=0; 
        if(s == 0){cout << "No contact saved yet." << endl; return;}
        while(i<s){
            cout << "Name: " << contact[i].getName() << endl; 
            cout << "Number: " << contact[i].getNum() << endl; 
            cout << "Tag: " << contact[i].getTag() << endl; 
            cout << "Email: " << contact[i].getEmail() << endl; cout << endl; 
            i++; 
        }
    } //shows contact specified
    void viewfromTag(string tag){
        if(contact.size() == 0){cout << "No contact saved yet." << endl; return;}
         int s = contact.size(), i=0; bool flag = false; 
       while(i<s){
        if(tag == contact[i].getTag()){ flag = true; 
            cout << "Name: " << contact[i].getName() << endl;
            cout << "Number: " << contact[i].getNum() << endl;
            cout << "Email: " << contact[i].getEmail() << endl; cout << endl; 
        }
        i++;  
       }
       if(!flag){cout << "Tag not found!" << endl;}

    } // adds contact to one tag
    vector<string> sortName(){
        vector<string>sname; int i=0; 
        while(i<contact.size()){
            sname.push_back(contact[i].getName()); i++;
        }i=0; sort(sname.begin(), sname.end());
        return sname;
    }
    vector<string> sortNum(){
        vector<string>snum; int i =0;
        while(i<contact.size()){
            snum.push_back(contact[i].getNum()); i++; 
        }; 
        sort(snum.begin(), snum.end()); 
        return snum; 
    }
    map<string, int> getMap(){
        map<string, int> m; 
        int i=0; 
        while(i<contact.size()){
            m[contact[i].getTag()]++; i++; 
        }
        return m; 
    }
    void viewfromName(){
        if(contact.size()==0){cout << "No contact saved yet." << endl; return; }
        int i=0, j=0; vector<string>sname=sortName(); 
        while(i<sname.size()){j=0; 
            while(j<sname.size()){
                if(sname[i]==contact[j].getName()){
                    cout <<"Name: " <<contact[j].getName() << endl;
                    cout  <<"Number: " <<contact[j].getNum() <<endl;
                    cout <<"Tag: " <<contact[j].getTag() <<endl; 
                    cout << "Email: "<< contact[j].getEmail() << endl; cout << endl; 
                    break; 
                }
                else{j++;}
            }i++; 
        }
       }
    void deleteContact(string dname){ 
        int i=0; bool flag = false;
        while(i<contact.size()){
            if(dname == contact[i].getName()){
                contact.erase(contact.begin()+i); storeContact(contact); flag = true; break; }
            else{i++; }
        }if(!flag){cout << "Contact Name not found!" << endl;}
        
    } // check name or number and delete entire contact(also from tags category); 
    void updateContact(string nname){//takes name as input and makes the changes
        int i=0; bool flag = false;
        while(i<contact.size()){
            if(nname == contact[i].getName()){flag = true; 
                contact.erase(contact.begin()+i); 
                string newname, newnum, newtag, newemail; 
                cout << "Enter the updates below: " << endl; 
                cout << "Name: "; getline(cin, newname); 
                cout << "Number: "; getline(cin, newnum);
                cout << "Tag: "; getline(cin, newtag);
                cout << "Email: "; getline(cin, newemail);
                contact.push_back(Contact(newname, newnum, newtag, newemail));
                storeContact(contact); 
                 break;
            }
            else{i++; }
        }
        if(!flag){cout << "Contact Name not found!" << endl;}

    }
    bool checkDuplicate(string name, string num){ 
        vector<string>sname = sortName(); vector<string>snum = sortNum(); 
        int i =0; bool f = false; 
        while(i<sname.size()){
            if(sname[i] == name){cout << "There exists a contact with name : " << sname[i] << endl;  break; }
            else{i++; }
        }i=0; 
        while(i<snum.size()){
            if(snum[i] == num){cout << "There exists a contact with number: " << snum[i]<< endl; f = true; break; }
            else{i++; }
        }
        return f; 

    }
    void getContact(){
        system("start Contact.txt"); 
    }//extracts the contacts(entire or tag specific to txt file)
    void ContactStats(int n){
        switch(n){
            case 1: {cout << "You have saved " << contact.size()<< " contacts till now." << endl; break;}
            case 2 :{
                string t; cout << "Enter tag to check: " << endl;  
                cin >> t; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                map <string, int>m = getMap(); auto it = m.begin();bool flag = false; 
                while(it != m.end()){
                    if(it->first==t){flag = true; 
                        cout << "This tag has total " << it->second << " contacts."  << endl; break;}
                    it++; 
                }if(!flag){cout << "Tag not found!" << endl;}
                 break;
            }
        }

    } // to see how many total contacts are there or in any specific tag
    void clearAll(){
        contact.clear(); storeContact(contact);
    }
}; 