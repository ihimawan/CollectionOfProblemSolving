#include <sstream>

using namespace std;

int main (){
    stringstream ss;
    ss << "l 321";
    
    char x;
    int y;
    
    ss >> x;
    ss >> y;
    cout << x << y;
    
}