#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber()
{
    return rand() % 6 + 1;
}

void fillArray(int arr[])
{
    for (int i = 0; i < 6; i++)
        *(arr + i) = randomNumber();
}

void printArray(int arr[])
{
    for (int i = 0; i < 6; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

bool imal(int prviArray[], int drugiArray[], int treciArray[], int brojKockica) {
    int  prviBroj = 0, drugiBroj = 0;

    for (int i = 0; i < brojKockica; i++) {
        int elementPrvogNiza = *(prviArray + i);
        for (int j = 0; j < brojKockica; j++) {
            int elementDrugogNiza = *(drugiArray + j);
            if (elementPrvogNiza == elementDrugogNiza) {
                for (int k = 0; k < brojKockica; k++) {
                    int elementTrecegNiza = *(treciArray + k);
                    if (elementDrugogNiza == elementTrecegNiza) {
                        if (!prviBroj) {
                            prviBroj = elementTrecegNiza;
                        }
                        else if (prviBroj && !drugiBroj && prviBroj != elementTrecegNiza) {
                            drugiBroj = elementTrecegNiza;
                        }
                    }
                }
            }
        }
    }
    return prviBroj && drugiBroj;
}


int main()
{
    srand(time(0));

    int brojac = 3;
    const int brojKockica = 6;
    int prviArray[brojKockica] = { 0 }, drugiArray[brojKockica] = { 0 }, treciArray[brojKockica] = { 0 };

    fillArray(prviArray); fillArray(drugiArray); fillArray(treciArray);

    cout << "Bacanje 1: "; printArray(prviArray);
    cout << "Bacanje 2: "; printArray(drugiArray);
    cout << "Bacanje 3: "; printArray(treciArray);
    
    while (!imal(prviArray, drugiArray, treciArray, brojKockica)) {
        for (int i = 0; i < brojKockica; i++) {
            *(prviArray + i) = *(drugiArray + i);
            *(drugiArray + i) = *(treciArray + i);
        }

        fillArray(treciArray);
        brojac++;
        cout << "Bacanje " << brojac << ": ";
        printArray(treciArray);
        
        if (brojac == 420) break;
    }
    

    cout << endl; cout << "Ukupan broj bacanja je: " << brojac << endl;
    cout << endl; cout << "Zadnje bacene kockice su: " << endl;

    printArray(prviArray); printArray(drugiArray); printArray(treciArray);

    return 0;
}