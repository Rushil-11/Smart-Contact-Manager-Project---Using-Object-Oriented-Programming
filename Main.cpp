#include <bits/stdc++.h>
#include "Task.cpp"
using namespace std;
int main() {
    int option=1;
    while(option==1){
        Task task; 
        task.loadContact();  task.seeTask();
        int t; cin >> t; 
        switch(t){
            case 1: {
                int n;
                cout << "Enter number of contacts to enter: " << endl; cin >> n; cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                while(n>0){
                    string name; string num; string tag; string email; 
                    cout << "Name: "; getline(cin , name); 
                    cout << "Number: "; getline(cin , num);
                    if(task.checkDuplicate(name, num)){continue;  }
                    cout << "Tag: "; getline(cin , tag);
                    cout << "Email: "; getline(cin , email); 
                    task.addContact(name, num, tag, email); n--; 
                }
                break; 
        }
        case 2: {int v; 
            cout << "Choose the Option to display: "<<endl;
            cout << "1: View all Contact[last added]" << endl;
            cout << "2: View all Contact[first added]" << endl;
            cout << "3: View Contact by Name" << endl;
            cout << "4: View Contact by Tags" << endl; 
            cin >> v; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch(v){
                case 1 : {task.viewfromLast(); break; }
                case 2 : {task.viewfromFirst(); break; }
                case 3 : {task.viewfromName(); break; }
                case 4 : {string tg; cout << "Enter the tag to check: "; 
                     cin >> tg; cin.ignore(numeric_limits<streamsize>::max(), '\n');
                      task.viewfromTag(tg); break; }
                default: cout << "Enter a valid number!" << endl;
            }break;
        }
        case 3: {int n; cout << "Enter number of contacts to be updated: " ; cin >> n; 
            string nname;  
            while(n--){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the Contact Name to update: "; 
            getline(cin, nname); 
                task.updateContact(nname);
            } break;
        }
        case 4 : {int n; cout << "Enter number of contacts to be deleted: "; cin >> n; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string dname; 
            while(n--){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the Contact Name to delete: " << endl; 
            getline(cin , dname); 
            task.deleteContact(dname);
        } break;
        }
        case 5 : {
            int n; cout << "Choose an option form below: " << endl;
            cout << "1 : Total contacts saved" << endl;
            cout << "2 : Contacts in a given tag" << endl; cin >> n; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            task.ContactStats(n); break;
        }
        case 6 : {cout << "Here you have the file: " << endl; task.getContact(); break;}
        case 7 : {task.clearAll();cout << "Deleted all contacts successfully." << endl;
             break;}
        default : cout << "Enter a valid input!" << endl;
        }
        cout << "Do you want to continue? (1 for Yes / 0 for No): ";
        cin >> option;
    }
    return 0;

}