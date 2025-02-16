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
    cout << "prvi broj: " << prviBroj << endl;
    cout << "drugi broj: " << drugiBroj << endl;
    return prviBroj && drugiBroj;
}

int main()
{
    srand(time(0));

    int brojac = 3;
    const int brojKockica = 6;
    int prviArray[brojKockica] = { 0 }, drugiArray[brojKockica] = { 0 }, treciArray[brojKockica] = { 0 };

    

    imal(prviArray, drugiArray, treciArray, brojKockica);

    

    return 0;
}