#include <iostream>
#include <iomanip>
using namespace std;

void takeInput(float *, float *);
void conversion(float *, float *, int *, float *);
void print(float *, float*, int *, float *);

int main(void){
    float lb{0};
    float ou{0};
    int kg{0};
    float g{0};
    
    // cin >> n;

    cout << "\nNomunbayasgalan Amarbayasgalan\n";

    while(lb != -1){
        takeInput(&lb, &ou);

        conversion(&lb, &ou, &kg, &g);

        if(lb != -1){
            print(&lb, &ou, &kg, &g);
        }else{
            cout << "Thank you for using the program" << endl;
        }
    }

    return 0;
}

void takeInput(float* lb, float* ou){
    cout << "Enter pounds and ounces seperated by a space or '-1' to exit program: ";
    cin >> *lb;
    if(*lb != -1){
        cin >> *ou;
    }
}

void conversion(float* lb, float* ou, int* kg, float* g){
    *g = *lb * 453.592 + *ou * 28.349;
    int dummyg = *g;
    *kg = *g / 1000;
    *g = dummyg % 1000;
}

void print(float* lb, float* ou, int* kg, float* g){
    cout << setprecision(2) << fixed;
    cout << "Pounds: " << *lb << ", Ounces: " << *ou << endl;
    cout << "Kilograms: " << *kg << ", Grams: " << *g << endl;
}

/*
    TEST RUNS:

    Nomunbayasgalan Amarbayasgalan
    Enter pounds and ounces seperated by a space: 5 6
    Pounds: 5, Ounces: 6
    Kilograms: 2, Grams: 2438.05



*/