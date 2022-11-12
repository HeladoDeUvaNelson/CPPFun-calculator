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
                    operators.push_back(3);
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
                    operators.push_back(4);
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

            if (exprOrdered.length() > 0){
                exprOrdered.erase(exprOrdered.length()-1);
            }

            for (int i = 0; i < expression.length(); i++){
                if (expression[i] == '+' && i != 0){
                    string unOrderNums;
                    string tempValueLessI;
                    string tempValuePlusI;
                    operators.push_back(1);
                    int j = 1;
                    while (stopWhile && i-j != -1 && i-j != tempValue && expression[i-j] != '*' && expression[i-j] != '/'){
                        if (expression[i-j] == '+' || expression[i-j] == '-'){
                            tempValueLessI += expression[i-j];
                            unOrderNums += tempValueLessI;
                            stopWhile = false;
                        }else {
                            tempValueLessI += expression[i-j];
                            if (i-j == 0){
                                unOrderNums += tempValueLessI;
                                if (expression[i-j] != '-'){
                                    unOrderNums += '+';
                                }
                                stopWhile = false;
                            }
                        }
                        j++;
                    }

                    for (int i = 1; i <= unOrderNums.length(); i++){
                        exprOrdered += unOrderNums[unOrderNums.length()-i];
                    }

                    j = 1;
                    stopWhile = true;

                     while (stopWhile && expression[i+j] != '*' && expression[i+j] != '/' && i+j <= expression.length()){

                        if (expression[i+j] == '+' || expression[i+j] == '-'){
                            if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                exprOrdered += expression[i];
                            }else {
                                exprOrdered[exprOrdered.length()-1] = expression[i];
                            }
                            exprOrdered += tempValuePlusI;
                            stopWhile = false;
                        }else {
                            tempValuePlusI += expression[i+j];
                            if (expression.length() == i+j+1){
                                if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                    exprOrdered += expression[i];
                                }else {
                                    exprOrdered[exprOrdered.length()-1] = expression[i];
                                }
                                exprOrdered += tempValuePlusI;
                                stopWhile = false;
                            }
                        }
                        tempValue = i+j;
                        j++;
                    }

                }else if (expression[i] == '-' && i != 0){
                    string unOrderNums;
                    string tempValueLessI;
                    string tempValuePlusI;
                    operators.push_back(2);
                    int j = 1;
                    while (stopWhile && i-j != -1 && i-j != tempValue && expression[i-j] != '*' && expression[i-j] != '/'){
                        if (expression[i-j] == '+' || expression[i-j] == '-'){
                            tempValueLessI += expression[i-j];
                            unOrderNums += tempValueLessI;
                            stopWhile = false;
                        }else {
                            tempValueLessI += expression[i-j];
                            if (i-j == 0){
                                unOrderNums += tempValueLessI;
                                stopWhile = false;
                            }
                        }
                        j++;
                    }

                    for (int i = 1; i <= unOrderNums.length(); i++){
                        exprOrdered += unOrderNums[unOrderNums.length()-i];
                    }

                    j = 1;
                    stopWhile = true;

                     while (stopWhile && expression[i+j] != '*' && expression[i+j] != '/' && i+j <= expression.length()){

                        if (expression[i+j] == '+' || expression[i+j] == '-'){
                            if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                exprOrdered += expression[i];
                            }else {
                                exprOrdered[exprOrdered.length()-1] = expression[i];
                            }
                            exprOrdered += tempValuePlusI;
                            stopWhile = false;
                        }else {
                            tempValuePlusI += expression[i+j];
                            if (expression.length() == i+j+1){
                                if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                exprOrdered += expression[i];
                                }else {
                                    exprOrdered[exprOrdered.length()-1] = expression[i];
                                }
                                exprOrdered += tempValuePlusI;
                                stopWhile = false;
                            }
                        }
                        tempValue = i+j;
                        j++;
                    }
                }
            }

            cout << exprOrdered << + " exprOD\n";

            for (auto oper: operators){

                string numAUnOrdered;
                string numA;
                string numB;
                int numbersFilled = 0;
                int i = 0;
                int operPosition = 0;

                stopWhile = true;

                if (oper == 3 || oper == 4){
                        while (operPosition == 0){
                            if (exprOrdered[i] == '*' || exprOrdered[i] == '/'){
                                operPosition = i;
                                i = 1;
                            }else {  
                                i++;
                            }
                        }

                        while (stopWhile){
                            if (numbersFilled == 0){
                                if (operPosition-i > -1 && exprOrdered[operPosition-i] != '+' && exprOrdered[operPosition-i] != '-' && exprOrdered[operPosition-i] != '*' && exprOrdered[operPosition-i] != '/'){
                                    numAUnOrdered += exprOrdered[operPosition-i];
                                }else if (operPosition-i == 0 && exprOrdered[operPosition-i] == '+' || operPosition-i == 0 && exprOrdered[operPosition-i] == '-') {
                                    numAUnOrdered += exprOrdered[operPosition-i];
                                }else {
                                    numbersFilled++;
                                    i = 1;
                                    for (int j = 1; j <= numAUnOrdered.length(); j++){
                                        numA += numAUnOrdered[numAUnOrdered.length()-j];
                                    }
                                }
                                
                                if (numbersFilled == 0){
                                    i++;
                                }
                            }else if (numbersFilled == 1){
                                if (operPosition+i <= exprOrdered.length() && exprOrdered[operPosition+i] != '+' && exprOrdered[operPosition+i] != '-' && exprOrdered[operPosition+i] != '*' && exprOrdered[operPosition+i] != '/'){
                                    numB += exprOrdered[operPosition+i];
                                }else {
                                    numbersFilled++;
                                    /* lastIteration = operPosition; */
                                    stopWhile = false;
                                }
                                i++;
                            }
                        }
                }

                cout << numA + " A\n";
                cout << numB + " B\n";

                switch (oper){
                    case 1:
                        if (result == 0){
                            char c = '-';
                            size_t found = numA.find(c);
                            if (found != string::npos){
                                result = stoi(numA) + stoi(numB);
                            }else {
                                result = stoi(numA) + stoi(numB);
                            }
                        }else {
                            cout << result << + " result\n";
                            result = result + stoi(numB);
                        }

                        break;

                    case 2:
                        if (result == 0 && numOfIterations == 0){
                            char c = '-';
                            size_t found = numA.find(c);
                            if (found != string::npos){
                                result = stoi(numA) - stoi(numB);
                            }else {
                                result = stoi(numA) - stoi(numB);
                            }
                        }else {
                            result = result - stoi(numB);
                        }
                        break;

                    case 3:
                        if (result == 0 && numOfIterations == 0){
                            char c = '-';
                            size_t found = numA.find(c);
                            if (found != string::npos){
                                result = stoi(numA) * stoi(numB);
                            }else {
                                result = stoi(numA) * stoi(numB);
                            }
                        }else {
                            result = result - stoi(numB);
                        }
                        break;

                    case 4:
                        int tempResult = 0;
                        char c = '-';
                        size_t found = numA.find(c);
                        if (found != string::npos){
                            tempResult = stoi(numA) / stoi(numB);
                            result += tempResult;
                        }else {
                            tempResult = stoi(numA) / stoi(numB);
                            result += tempResult;
                        }
                        break;
                }
                numOfIterations++;
                cout << result << + " R\n";

            }
        }

        cout << " \n";
        cout << result << + " \n\n";
    }
    while (expression != "exit" && expression != "quit");

    return 0;
}
