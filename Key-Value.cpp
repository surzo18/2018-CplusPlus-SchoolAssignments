#include <iostream>

using namespace std;

class KeyValue
{
private:
    int key;
    double value;
    KeyValue *next;

public:
    KeyValue(int k, double v);
    ~KeyValue();
    int GetKey();
    double GetValue();
    KeyValue *CreateNext(int k,double v);
    KeyValue *GetNext();
};

KeyValue::KeyValue(int k, double v)
{
   key = k;
   value = v;
   next = nullptr;
}

KeyValue::~KeyValue()
{
   cout <<"Zmazane: "<<key<<endl;
   if(next != nullptr){
    delete next;
    next=nullptr;
   }
}

int KeyValue::GetKey()
{
     return key;
}

double KeyValue::GetValue()
{
    return value;
}

KeyValue *KeyValue::CreateNext(int k, double v)
{
   this->next = new KeyValue (k, v);
   return this-> next;
}

KeyValue *KeyValue::GetNext()
{
    return next;
}
int main()
{
     KeyValue *kv1 = new KeyValue(0,0);
     KeyValue *kvCurrent = kv1;

     for (int i=0; i<1000;i++){
        kvCurrent=kvCurrent -> CreateNext(i,1);
        cout << kvCurrent->GetKey()<<endl;
     }
     delete kv1;
     return 0;
}



