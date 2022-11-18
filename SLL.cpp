#include <iostream>
using namespace std;
struct Node { 
  int data; 
  Node *next;
  Node(int val=0) :data(val),next(nullptr){}
  Node(int val, Node *tempNext):data(val),next(tempNext){}
};

class LinkedList
{
        Node* head;
  public:
    
    LinkedList():head(nullptr) {}
    void insert(int val)
    {
        Node* new_node = new Node(val);
      if (head == nullptr)
      {
        head = new_node;
      }
           else
      {
        new_node->next = head;
        head = new_node;
      }
    }

    
    bool search(int val)
    {
      Node* temp = head;
      while(temp != nullptr)
      {
        if (temp->data == val)
          return true;
        temp = temp->next;
      }
      return false;
    }

    
    void Delete(int val)
    {
      Node* temp = head;
           if (temp != nullptr && temp->data == val)
      {
        head = temp->next;
        delete temp;
      }
         else
      {
        Node* curr = head;
        while(temp != nullptr && temp->data != val)
        {
         curr = temp;
         temp = temp->next;  
        }
          if(!temp)
        {
           cout << "Value not found" << endl;
           return;
        }
        curr->next = temp->next;
        delete temp;
      }  
    }
    
    	void reverse()
	{
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	
    void print()
    {
      Node* temp = head;
      while(temp != nullptr)
      {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }  
};

int main() {
  
  LinkedList l;
   l.insert(6);
  l.insert(9);
  l.insert(1);
  l.insert(3);
  l.insert(7);
  cout << "Print "<<endl;
  l.print();

  cout << "Delete  "<<endl;
  l.Delete(1);
  l.print();

  cout << "Delete  "<<endl;
  l.Delete(13);

  cout << "Print "<<endl;
  l.print();

  cout << "Search "<<endl;
  cout << l.search(7) << endl;

  cout << "Search "<<endl;
  cout << l.search(13) << endl;

  cout << "Print "<<endl;
  l.print();
  l.reverse();

 cout << "\nReversed linked list \n";
 l.print();
}



