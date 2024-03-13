#include <iostream>

using namespace std;
template <typename T>
struct Nodo{
    private:
        
    public:
        list <string> frutas;
        

};

int main(){
    
    list <string> frutas;

    frutas.push_back("manzanas");
    frutas.push_back("peras");
    frutas.push_back("duraznos");

    for (const auto & elemento:frutas){
        cout<<elemento<<"";
    }

    return 0;
}



