#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string expression;
    int logOut;


    do {
        vector<int> operators;
        string exprOrdered;


        cout << "Please insert your values\n" << endl;
        getline(cin, expression);

        int result = 0;
        int valuesGot = 0;
        int lastIteration = 0;
        int numOfIterations = 0;
        int tempValue = -3;
        bool stopWhile = true;
        result = 0;

        if (expression != "exit" && expression != "quit"){
            for (int i = 0; i < expression.length(); i++){
                if (expression[i] == '*'){
                    string unOrderNums;
                    operators.push_back(1);
                    int j = 1;
                    while (i-j != -1 && i-j != tempValue && expression[i-j] != '+' && expression[i-j] != '-' && expression[i-j] != '*' && expression[i-j] != '/'){
                        unOrderNums += expression[i-j];
                        if (expression[i-j-1] == '+' && i > 0 || expression[i-j-1] == '-'){
                            unOrderNums += expression[i-j-1];
                        }
                        j++;
                    }

                    for (int i = 1; i <= unOrderNums.length(); i++){
                        exprOrdered += unOrderNums[unOrderNums.length()-i];
                    }

                    exprOrdered += expression[i];
                    j = 1;

                     while (expression[i+j] != '+' && expression[i+j] != '-' && expression[i+j] != '*' && expression[i+j] != '/' && i+j <= expression.length()){
                        exprOrdered += expression[i+j];
                        tempValue = i+j;
                        j++;
                    }
                }else if (expression[i] == '/'){
                    string unOrderNums;
                    operators.push_back(2);
                    int j = 1;
                    while (i-j != -1 && i-j != tempValue && expression[i-j] != '+' && expression[i-j] != '-' && expression[i-j] != '*' && expression[i-j] != '/'){
                        unOrderNums += expression[i-j];
                        if (expression[i-j-1] == '+' && i > 0 || expression[i-j-1] == '-'){
                            unOrderNums += expression[i-j-1];
                        }
                        j++;
                    }

                    for (int i = 1; i <= unOrderNums.length(); i++){
                        exprOrdered += unOrderNums[unOrderNums.length()-i];
                    }

                    exprOrdered += expression[i];
                    j = 1;

                     while (expression[i+j] != '+' && expression[i+j] != '-' && expression[i+j] != '*' && expression[i+j] != '/' && i+j <= expression.length()){
                        exprOrdered += expression[i+j];
                        tempValue = i+j;
                        j++;
                    }
                }
            }

            cout << exprOrdered << endl;

//            for (auto oper: operators){
//
//                string numA;
//                string numB;
//
//                int numbersFilled = 0;
//
//                for (int i = 0; i < expression.length(); i++){
//                    if (result == 0 && numOfIterations == 0){
//                        if (numbersFilled == 0){
//                            if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
//                                numA += expression[i];
//                            }else if (i == 0 && expression[i] == '+' || i == 0 && expression[i] == '-') {
//                                numA += expression[i];
//                            }else {
//                                numbersFilled++;
//                            }
//                    }else if (numbersFilled == 1){
//                            if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
//                                numB += expression[i];
//                            }else {
//                                numbersFilled++;
//                                lastIteration = i+1;
//                            }
//                        }
//                    }else if (numbersFilled == 0 && i >= lastIteration){
//                        if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
//                            numB += expression[i];
//                        }else {
//                            numbersFilled++;
//                            lastIteration = i+1;
//                        }
//                    }
//                }
//
//                cout << numA + " A\n";
//                cout << numB + " B\n";
//
//                switch (oper){
//                    case 1:
//                        if (result == 0){
//                            char c = '-';
//                            size_t found = numA.find(c);
//                            if (found != string::npos){
//                                result = stoi(numA) + stoi(numB);
//                            }else {
//                                result = stoi(numA) + stoi(numB);
//                            }
//                        }else {
//                            result = result + stoi(numB);
//                        }
//
//                        break;
//
//                    case 2:
//                        if (result == 0 && numOfIterations == 0){
//                            char c = '-';
//                            size_t found = numA.find(c);
//                            if (found != string::npos){
//                                result = stoi(numA) - stoi(numB);
//                            }else {
//                                result = stoi(numA) - stoi(numB);
//                            }
//                        }else {
//                            result = result - stoi(numB);
//                        }
//                        break;
//
//                    case 3:
//                        if (result == 0 && numOfIterations == 0){
//                            char c = '-';
//                            size_t found = numA.find(c);
//                            if (found != string::npos){
//                                result = stoi(numA) * stoi(numB);
//                            }else {
//                                result = stoi(numA) * stoi(numB);
//                            }
//                        }else {
//                            result = result - stoi(numB);
//                        }
//                        break;
//
//                    case 4:
//                        if (result == 0 && numOfIterations == 0){
//                            char c = '-';
//                            size_t found = numA.find(c);
//                            if (found != string::npos){
//                                result = stoi(numA) / stoi(numB);
//                            }else {
//                                result = stoi(numA) / stoi(numB);
//                            }
//                        }else {
//                            result = result / stoi(numB);
//                        }
//                        break;
//                }
//
//                numOfIterations++;
//            }
        }

//        cout << " \n";
//        cout << result << + " \n\n";
    }
    while (expression != "exit" && expression != "quit");

    return 0;
}
