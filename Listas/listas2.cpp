#include<iostream>

using namespace std;

template <typename T>
class Nodo{
private:
  T dato;
  Nodo* next;
public: 
    
    Nodo(){
        next = NULL;
    }
    
    Nodo(T d){
        dato = d;
        next = NULL;
    }
   
    T get_dato(){
        return dato;
    }
    
    void set_dato(T d){
        dato = d;
    }
    
    Nodo<T>* get_next(){
        return next;
    }
    
    void set_next(Nodo<T>* n){
        next = n;
    }
    
    Nodo<T>& operator=(const Nodo<T>& f) { 
		dato = f.dato;
		next = f.next;
		return *this;
	}
	
	string to_string() {
		return std::to_string(dato);
	}

	friend std::ostream& operator<<(std::ostream& os, Nodo<T>& b) {
		return os << b.to_string();
	}
    
};

template <typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;
public:
  Lista(){
      ptr = NULL;
      size = 0;
  }
  
  ~Lista(){
      if(ptr != NULL){
          Nodo<T>* temp =  ptr;
          Nodo<T>* next_temp =  ptr->get_next();
          
          while(next_temp != NULL){
              delete temp;
              temp = next_temp;
              next_temp =  temp->get_next();
          }
          delete temp;
      }
  }
  
  void add(T d){
      Nodo<T>* n = new Nodo<T>(d);
      if(ptr == NULL){
          ptr =  n;
      }else{
          Nodo<T>* t = ptr;
          while(t->get_next() != NULL){
                t = t->get_next();
          }
          t->set_next(n);
      }
      size++;
  }

  void print(){
      Nodo<T>* t = ptr;
      while(t != NULL){
          cout<<(*t)<<endl;
          t = t->get_next();
      }
  }
  
  void insert(T dato, int pos){
      Nodo<T>* t = ptr;
      Nodo<T>* new_nodo = new Nodo<T>(dato);
      
      if(ptr == NULL || pos <= 0){
          new_nodo->set_next(ptr);
          ptr = new_nodo;
          size++;
      }else if(pos >= size){
          add(dato);
      }else{
          Nodo<T>* t = ptr;
          int i=0;
          while(i < pos-1){
                t = t->get_next();
                i++;
          }
          new_nodo->set_next(t->get_next());
          t->set_next(new_nodo);
          size++;
      }
      
  }
  
    
};

int main()
{
    Nodo<int> n;
    
    n.set_dato(5);
    
    cout<<"El dato del nodo es: "<<n.get_dato()<<endl;
    
    Lista<int> l;
   
    for(int i=0; i<10; i++){
        l.add(i);
    }
    
    l.insert(20,2);
    l.insert(21,0);
    l.insert(22,-2);
    l.insert(23,15);
    
    l.print();
    
    return 0;
}