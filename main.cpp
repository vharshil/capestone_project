#include <iostream>
#include <string>
using namespace std;
class Reciepe{
    public :
        string name;
        string ingredients[100];
        int calories;
        string category;
        Reciepe* next;
        int n1;
};
void dis(string s1);
Reciepe* head=nullptr;
Reciepe* tail=nullptr;
void add(Reciepe* temp){
    if(head==nullptr){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
        tail->next=nullptr;
    }
}
void display(){
    Reciepe* current = head;
    while(current!=nullptr){
        cout << "Reciepe name : " << current->name << " Ingredients Name : ";
        for(int i=0;i<current->n1;i++){
            cout << current->ingredients[i] << ", ";
        }
        cout << "Calories : " << current->calories << "Category : " << current->category << endl;
        current=current->next;
    }
}
void search(string s){
    Reciepe* current=head;
    int flag1=0;
    while(current!=nullptr){
        int flag=0;
        for(int i=0;i<current->n1;i++){
            string s1=current->ingredients[i];
            if(s==s1){
                flag=1;
                flag1=1;
                break;
            }
        }
        if(flag==1){
            cout << "You can make : " << current->name << endl;
            dis(current->name);
            flag=1;
        }
        current=current->next;
    }
    if(flag1==0){
        cout << "\nNo reciepe has used this ingridientts is in our database" << endl;
    }
}
void dis(string s1){
    Reciepe *current=head;
    int flag=0;
    while(current!=nullptr){
        if(current->name==s1){
            flag=1;
            cout << "Ingredients Name : ";
            for(int i=0;i<current->n1;i++){
                cout << current->ingredients[i] << ",";
            }
            cout << "\n";
            cout << "Category : " << current->category << endl;
            cout << "Calories : " << current->calories << endl;
            break;
        }
        current=current->next;
    }
    if(flag==0){
        cout << "The reciepe is not in our database" << endl;
    }
}
void categ(string s){
    Reciepe* current=head;
    int flag=0;
    while(current!=nullptr){
        if(current->category==s){
            cout << "You can make : " << current->name << endl;
            dis(current->name);
            flag=1;
        }
        current=current->next;
    }
    if(flag==0){
        cout << "Ther is no reciepe with this category in our database" << endl;
    }
}
void meal_planner(){
    cout << "Enter all the three meals for breakfast lunch and dinner with entering after each input" << endl;
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    cout << "Breakfast description : \n \n";
    dis(s1);
    cout << "\n \nLunch description : \n \n";
    dis(s2);
    cout << "\n \nDinner description : \n \n";
    dis(s3);
}
void meal_dec(){
    cout << "Can you please enter the range of calorie in which you want to enter in this format eg : \'100\' \'150\' with space between them : ";
    int n1,n2;
    cin >> n1 >> n2;
    cout << "Enter the category of the food you want : ";
    string s;
    cin >> s;
    int flag=0;
    Reciepe* current=head;
    while(current!=nullptr){
        if(current->calories >= n1 && current->calories<=n2 && current->category==s){
            cout << "You can make : " << current->name << endl;
            dis(current->name);
            flag=1;
        }
        current=current->next;
    }
    if(flag==0){
        cout << "There is no kind of reciepe you want in the database " << endl;
    }
}
int main(){
    int n;
   cout << "Enter 1 to add Reciepe\nEnter 2 to display all reciepe\nEnter 3 to find reciepe which can be made using a particular ingredient\nEnter 4 to find using category\nEnter 5 to find details of a particular dish\nEnter 6 to plan a single meal for you if you are confused\nEnter 7 to plan your meal for a day\n0 to end\n";
    cin >> n;
    while(n){
        if(n==1){
            cout << "Enter reciepe name to be entered : ";
            Reciepe* temp=new Reciepe;
            cin >> temp->name;
            cout << "Enter the no of ingredients requirded : ";
            int n1;
            cin >> n1;
            temp->n1=n1;
            cout << "Enter name of all the ingredients we need with entering enter after typing the name of each ingredients "<< endl;
            for(int i=0;i<n1;i++){
                cin >> temp->ingredients[i];
            }
            cout << "Enter  no of calories of the reciepe : ";
            cin >> temp->calories;
            cout << "Enter the category ofthe dish : ";
            cin >> temp->category;
            temp->next=nullptr;
            add(temp);
        }
        else if(n==2){
            display();
        }
        else if(n==3){
            cout << "Enter ingredient : ";
            string s;
            cin >> s;
            search(s);
        }
        else if(n==4){
            string s1;
            cout << "Enter the category : ";
            cin >> s1;
            categ(s1);
        }
        else if(n==5){
            string s1;
            cout << "Enter the name of the reciepe you want to find details of : ";
            cin >> s1;
            dis(s1);
        }
        else if(n==6){
            meal_dec();
        }
        else if(n==7){
            meal_planner();
        }
        else{
            cout << "Wrong choice";
        }
       cout << "Enter 1 to add Reciepe\nEnter 2 to display all reciepe\nEnter 3 to find reciepe which can be made using a particular ingredient\nEnter 4 to find using category\nEnter 5 to find details of a particular dish\nEnter 6 to plan a single meal for you if you are confused\nEnter 7 to plan your meal for a day\n0 to end\n";
       cin >> n; 
    }
}