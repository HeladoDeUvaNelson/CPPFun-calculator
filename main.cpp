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
                    bool exprInside = false;
                    
                    int j = 1;
                    while (stopWhile && i-j != -1 && i-j != tempValue && expression[i-j] != '*' && expression[i-j] != '/'){
                        if (expression[i-j] == '+' || expression[i-j] == '-'){
                            tempValueLessI += expression[i-j];
                            unOrderNums += tempValueLessI;
                            stopWhile = false;
                            exprInside = true;
                        }else {
                            tempValueLessI += expression[i-j];
                            if (i-j == 0){
                                unOrderNums += tempValueLessI;
                                exprInside = true;
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
                                exprInside = true;
                            }else {
                                exprOrdered[exprOrdered.length()-1] = expression[i];
                                exprInside = true;
                            }
                            exprOrdered += tempValuePlusI;
                            stopWhile = false;
                            exprInside = true;
                        }else {
                            tempValuePlusI += expression[i+j];
                            if (expression.length() == i+j+1){
                                if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                    exprOrdered += expression[i];
                                    exprInside = true;
                                }else {
                                    exprOrdered[exprOrdered.length()-1] = expression[i];
                                    exprInside = true;
                                }
                                exprOrdered += tempValuePlusI;
                                stopWhile = false;
                                exprInside = true;
                            }
                        }
                        tempValue = i+j;
                        j++;
                    }

                    if (unOrderNums.length() > 0 || exprInside){
                        operators.push_back(1);
                    }

                }else if (expression[i] == '-' && i != 0){
                    string unOrderNums;
                    string tempValueLessI;
                    string tempValuePlusI;
                    bool exprInside = false;
                    
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
                                exprInside = true;
                            }else {
                                exprOrdered[exprOrdered.length()-1] = expression[i];
                                exprInside = true;
                            }
                            exprOrdered += tempValuePlusI;
                            stopWhile = false;
                            exprInside = true;
                        }else {
                            tempValuePlusI += expression[i+j];
                            if (expression.length() == i+j+1){
                                if (exprOrdered[exprOrdered.length()-1] != '+' && exprOrdered[exprOrdered.length()-1] != '-'){
                                exprOrdered += expression[i];
                                exprInside = true;
                                }else {
                                    exprOrdered[exprOrdered.length()-1] = expression[i];
                                    exprInside = true;
                                }
                                exprOrdered += tempValuePlusI;
                                stopWhile = false;
                            }
                        }
                        tempValue = i+j;
                        j++;
                    }

                    if (unOrderNums.length() > 0 || exprInside){
                        operators.push_back(2);
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
                            if (exprOrdered[i] == '*' && i != lastIteration && i > lastIteration || exprOrdered[i] == '/' && i != lastIteration && i > lastIteration){
                                operPosition = i;
                                lastIteration = i;
                                i = 1;
                            }else {  
                                i++;
                            }
                        }
                        
                }else if (oper == 1 || oper == 2){
                    while (operPosition == 0){
                            if (exprOrdered[i] == '+' && i != lastIteration && i > lastIteration || exprOrdered[i] == '-' && i != lastIteration && i > lastIteration){
                                operPosition = i;
                                lastIteration = i;
                                i = 1;
                            }else {  
                                i++;
                            }
                        }
                }

                        while (stopWhile){
                            if (numbersFilled == 0){
                                if (operPosition-i > -1 && exprOrdered[operPosition-i] != '+' && exprOrdered[operPosition-i] != '-' && exprOrdered[operPosition-i] != '*' && exprOrdered[operPosition-i] != '/'){
                                    numAUnOrdered += exprOrdered[operPosition-i];
                                }else if (exprOrdered[operPosition-i] == '+' || exprOrdered[operPosition-i] == '-') {
                                    numAUnOrdered += exprOrdered[operPosition-i];
                                    numbersFilled++;
                                    i = 1;
                                    for (int j = 1; j <= numAUnOrdered.length(); j++){
                                        numA += numAUnOrdered[numAUnOrdered.length()-j];
                                    }
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
                                    lastIteration = operPosition;
                                    stopWhile = false;
                                }
                                i++;
                            }
                        }

                cout << numA + " A\n";
                cout << numB + " B\n";

                switch (oper){
                    case 1:
                        if (numB.length() > 0){
                            if (result == 0){
                                result = stoi(numA) + stoi(numB);
                            }else {
                                cout << result << + " result\n";
                                result = result + stoi(numB);
                            }
                        }

                        break;

                    case 2:
                        if (numB.length() > 0){
                            if (result == 0 && numOfIterations == 0){
                                result = stoi(numA) - stoi(numB);
                            }else {
                                result = result - stoi(numB);
                            }
                        }
                        break;

                    case 3:
                        if (numA.length() > 0){
                            int tempResult = 0;
                                tempResult = stoi(numA) * stoi(numB);
                                result += tempResult;
                        }else {
                            result = result * stoi(numB);
                        }
                        break;

                    case 4:
                        if (numA.length() > 0){
                            int tempResult = 0;
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
