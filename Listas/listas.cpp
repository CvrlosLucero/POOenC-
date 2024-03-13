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
    
};

int main()
{
    Nodo<int> n;
    
    n.set_dato(5);
    
    cout<<"El dato del nodo es: "<<n.get_dato()<<endl;
    
    Lista<int> l;
    
    l.add(5);
    l.add(6);
    l.add(7);
    
    l.print();
    
    return 0;
}