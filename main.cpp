#include <iostream>

using namespace std;

struct node_t {
    int value;
    node_t * next;
};

void add_el( node_t *&first ,int a){
    if(first!=NULL){
        node_t *current=first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next=new node_t;
        current=current->next;
        current->value=a;
        current->next=NULL;
        return;
    }
    first=new node_t;
    first->value=a;
    first->next=NULL;
}

void del_first(node_t *&first){
    if(first==NULL){
        cout<<"Empty object"<<endl;
        return;
    }
    node_t *p=first;
    first=first->next;
    delete p;
    return;
}

void reverse(node_t* &first){
    node_t *newfirst=first;
    while (newfirst->next != NULL) {
        newfirst=newfirst->next;
    }
    if(newfirst==first){
        return;
    }

    node_t *last=newfirst;
    node_t *current;

    while (first->next != NULL) {

        if(newfirst==first->next){
            last->next=first;
            last=last->next;
            last->next=NULL;
            first=newfirst;
            return;
        }

        current=first;
        while (current->next->next !=newfirst ) {
            current=current->next;
        }
        last->next=current->next;
        last=last->next;
        current->next=current->next->next;
        last->next=NULL;

    }
    first=newfirst;
    return;
}

void out(node_t *first){
    if(first==NULL){
        cout<<"Empty object"<<endl;
        return;
    }


    node_t *current=first;
    int size=0;
    do{
        current=current->next;
        size++;
    }
    while (current != NULL);

    ////////////////////////////////////

    for (int i=0; i<size; i++) {
        cout<<"+---+    ";
    }
    cout<<endl;
    current=first;

    do{
        cout<<"| "<<current->value<<" |--->";
        current=current->next;
    }
    while (current != NULL);

    cout<<endl;
    for (int i=0; i<size; i++) {
        cout<<"+---+    ";
    }
    cout<<endl;
}


void del_el(node_t *first){
    if(first==NULL){
        cout<<"Empty object"<<endl;
        return;
    }
    node_t *current=first;
    node_t *save;
    do{
        save=current->next;
        current=current->next;
        delete current;
        current=save;
    }
    while (current != NULL);
}
int main() {
    node_t *spisok=NULL;
    char op;
    cin>>op;
    while(op!='q'){
        switch(op){
            case '+':
                int a;
                cin>>a;
                add_el(spisok, a);
                out(spisok);
                break;
            case '-':
                del_first(spisok);
                out(spisok);
                break;
            case '=':
                out(spisok);
                break;
            case '/':
                reverse(spisok);
                out(spisok);
                break;
            default: cout<<"Error"<<endl;
                break;
        }
        cin>>op;
    }
    del_el(spisok);
    return 0;
}
