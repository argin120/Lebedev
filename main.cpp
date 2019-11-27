#include <iostream>
#include <vector>

using namespace std;

struct turingMachineCommand
{
    int state1;
    int data1;
    int state2;
    int  data2;
    char movement;

};

int main()
{

    //cin>>inputData;
    vector <turingMachineCommand> commandList;
    vector <int> turingMachineLine;

    string inputData;
    cout<<"enter the string"<<endl;
    cin>>inputData;
    bool errorFlag = false;
    // добавление данных в вектор команд. сейчас *= 3


    for(int i = 0; i < inputData.length(); i++){
        if (inputData[i] == '0' || inputData[i] == '1'){
            int intVar = inputData[i] - 48;
            turingMachineLine.push_back(intVar);
        } else{
            cout<<"the string does not satisfy the conditions of the problem"<<endl;
            errorFlag = true;
        }
    }

    if (errorFlag)
        return -1;
    cout<<"-------------------"<<endl;
    // добавление данных в вектор команд. сейчас *= 3

    commandList.push_back ({0, 0, 0, 0, 'r'});
    commandList.push_back ({0, 1, 1, 0, 'l'});
    commandList.push_back ({1, 0, 4, 1, 'l'});
    commandList.push_back ({4, 0, 2, 1, 'r'});
    commandList.push_back ({2, 0, 3, 1, 'r'});
    commandList.push_back ({3, 1, 1, 0, 'l'});
    commandList.push_back ({3, 0, 3, 0, 's'});
    commandList.push_back ({2, 1, 2, 1, 'r'});
    commandList.push_back ({1, 1, 1, 1, 'l'});

    int n = 0; //количество итераций. ограничение 10000
    int k = 0; //текущее положение головки чтения-записи
    int currentState = 0;
    char currentMovement = 'r';
    char s;
    int p;
    while (n < 10000 && currentMovement != 's'){
            if (k == 0){
                turingMachineLine.insert(turingMachineLine.begin(), 0);
                k++ ;
            }
            if (k == turingMachineLine.size()-1)
                turingMachineLine.push_back(0);

            for (int i = 0; i < commandList.size(); i++){
                    if (commandList[i].state1 == currentState && commandList[i].data1 == turingMachineLine[k]){
                        currentState = commandList[i].state2;
                        turingMachineLine[k] = commandList[i].data2;
                        currentMovement = commandList[i].movement;
                        p = i;
                        if(commandList[i].movement == 'l')
                            k -- ;

                        if(commandList[i].movement == 'r')
                            k ++ ;
                        break;
                    }
            }

            cout<<"iteration "<<n<< " :";
            for(int j = 0; j < turingMachineLine.size(); j++){
                cout<< turingMachineLine[j]<<' ';
            }
            cout<<endl;
            n++ ;
        }
}
