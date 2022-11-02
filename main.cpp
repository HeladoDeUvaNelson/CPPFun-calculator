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

        cout << "Please insert your values\n" << endl;
        getline(cin, expression);

        int result = 0;
        int valuesGot = 0;
        int lastIteration = 0;
        int numOfIterations = 0;
        result = 0;

        if (expression != "exit" && expression != "quit"){
            for (int i = 0; i < expression.length(); i++){
                if (expression[i] == '+' && i != 0){
                    operators.push_back(1);
                }else if (expression[i] == '-' && i != 0){
                    operators.push_back(2);
                }else if (expression[i] == '*'){
                    operators.push_back(3);
                }else if (expression[i] == '/'){
                    operators.push_back(4);
                }
            }

            for (auto oper: operators){

                string numA;
                string numB;

                int numbersFilled = 0;

                for (int i = 0; i < expression.length(); i++){
                    if (result == 0 && numOfIterations == 0){
                        if (numbersFilled == 0){
                            if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
                                numA += expression[i];
                            }else if (i == 0 && expression[i] == '+' || i == 0 && expression[i] == '-') {
                                numA += expression[i];
                            }else {
                                numbersFilled++;
                            }
                    }else if (numbersFilled == 1){
                            if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
                                numB += expression[i];
                            }else {
                                numbersFilled++;
                                lastIteration = i+1;
                            }
                        }
                    }else if (numbersFilled == 0 && i >= lastIteration){
                        if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/'){
                            numB += expression[i];
                        }else {
                            numbersFilled++;
                            lastIteration = i+1;
                        }
                    }
                }

                cout << numA + " A\n";
                cout << numB + " B\n";

                switch (oper){
                    case 1:
//                        cout << "sum!" << endl;
                        if (result == 0){
                            char c = '-';
                            size_t found = numA.find(c);
                            if (found != string::npos){
                                result = stoi(numA) + stoi(numB);
                            }else {
                                result = stoi(numA) + stoi(numB);
                            }
                        }else {
                            result = result + stoi(numB);
                        }

                        break;

                    case 2:
//                        cout << "rest!" << endl;
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
                        break;

                    case 4:
                        break;
                }

                numOfIterations++;
            }
        }

        cout << " \n";
        cout << result << + " \n\n";
    }
    while (expression != "exit" && expression != "quit");

    return 0;
}
