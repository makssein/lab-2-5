#include "inc/functions.hpp"
#include <fstream>

int main() {
    Elem* root = nullptr;
    std::ifstream in("../input.txt");
    char sign;
    int number;

    while (!in.eof()){
        in >> sign;
        if(sign == '+'){
            in >> number;
            add(number,root);
        }

        if(sign == '-'){
            in >> number;
            deleteElem(number, root);
        }

        if(sign == '?'){
            in >> number;
            numberDepth(number, root, 1);
        }

        if(sign == 'E') break;
    }
    return 0;
}
