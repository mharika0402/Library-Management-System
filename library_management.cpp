#include<iostream>
using namespace std;
class node{
    public:
    string bookname;
    string authorname;
    int bookno;
    string depar;
    node* next;
};
node* head=new node();
bool ischeck(int bookno){
    if(head==NULL){
        return false;
    }
    node* temp=head;
    while(temp!=NULL){
        if(temp->bookno==bookno){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void insert_new_record(string bookname,string authorname,int bookno,string depar){
    node* new_record=new node();
    new_record->bookname=bookname;
    new_record->authorname=authorname;
    new_record->bookno=bookno;
    new_record->depar=depar;
    new_record->next=NULL;
    if(ischeck(bookno)){
        cout<<"the data regarding this book is already present!!!";
        return;
    }
    if(head==NULL){
         head=new_record;
         cout<<"\nrecord entered sucessfully!!"<<endl;
         return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_record;
    cout<<"record entered sucessfully!!"<<endl;
}
void search_record(int bookno){
    if(head==NULL){
        cout<<"the record is empty!!";
        return;
    }
    node* temp=head;
    int found=0;
    while(temp!=NULL){
        if(temp->bookno==bookno){
            cout<<"Book Name:"<<temp->bookname<<endl;
            cout<<"Author Name:"<<temp->authorname<<endl;
            cout<<"Book Number:"<<temp->bookno<<endl;
            cout<<"Department:"<<temp->depar<<endl;
        }
        temp=temp->next;
        found++;
    }
    if(found==0){
        cout<<"the given book is not present in the record"<<endl;
    }
}
void delete_record(int bookno){
    int found=0;
    if(head==NULL){
        cout<<"the record is empty!!"<<endl;
        return;
    }
    node* temp=head;
    if(temp->bookno==bookno){
        head=head->next;
        temp->next=NULL;
        delete temp;
        cout<<"record deleted succesfully!"<<endl;
        found++;
    }
    else{
       node* curr=head;
        node* prev=NULL;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
            if(curr->bookno==bookno){
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
                cout<<"record deleted sucessfully"<<endl;
                found++;
                return;
            }
        }    
    }
    if(found==0){
        cout<<"invalid booknumber"<<endl;
    }
    
}
void show_record(){
    if(head==NULL){
        cout<<"The record is empty"<<endl;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
            cout<<"Book Name:"<<temp->bookname<<endl;
            cout<<"Author Name:"<<temp->authorname<<endl;
            cout<<"Book Number:"<<temp->bookno<<endl;
            cout<<"Department:"<<temp->depar<<endl;
            temp=temp->next;
    }
}
int main(){
    head=NULL;
    string bookname,authorname,depar;
    int bookno,ch;
    cout<<"1.Insert New Record\n\n2.Search Record\n\n3.Delete record\n\n4.Show All Record\n\n5.Exit\n\n";

    while(true){
        cout<<"Enter the choice:";
        cin>>ch;
        switch(ch){
            case 1:
                 cout<<"Enter the bookname:"<<endl;
                 cin>>bookname;
                 cout<<"Enter the authorname:"<<endl;
                 cin>>authorname;
                 cout<<"Enter the booknumber:"<<endl;
                 cin>>bookno;
                 cout<<"Enter the deparment from which the book is required:"<<endl;
                 cin>>depar;
                 insert_new_record(bookname,authorname,bookno,depar);
                 break;
            case 2:
                cout<<"enter the bookno which is to be searched:"<<endl;
                cin>>bookno;
                search_record(bookno);
                break;
            case 3:
                 cout<<"enter the bookno which is to be deleted:"<<endl;
                 cin>>bookno;
                 delete_record(bookno);
                 break;
            case 4:
                 show_record();
                 break;
            case 5:
                 exit;
                 break;
            default:
                 cout<<"Enter the correct choice!!"<<endl;
        }
    }

}