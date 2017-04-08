#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int duration, records;
    float payment, car_price;
    while (cin >> duration >> payment >> car_price >> records && duration > 0){
        float debt = car_price;
        //First depreciation
        int month;
        float depreciation;
        cin >> month >> depreciation;
        car_price -= car_price*depreciation;
        float month_deprec[duration];
        for (int i = 0; i<duration; i++) month_deprec[i] = -1.0;
        records--;
        while (records--){
            cin >> month >> depreciation;
            month_deprec[month-1] = depreciation;
            //printf("M: %d Dep: %.3f\n", month, depreciation); 
        }
        float currValue = depreciation;
        for (int i = 0; i<duration; i++){
            if (month_deprec[i] != -1.0) 
                currValue = month_deprec[i];
            else month_deprec[i] = currValue;
        }
        //for (int i = 0; i<duration; i++) printf("M: %d Dep: %.3f\n", i+1, month_deprec[i]);        
        month = 0;
        while (debt >= car_price){
            printf("On month %d, debt is %.3f and car_price %.3f\n", month, debt, car_price);
            month++;
            debt -= payment;
            car_price -= car_price*month_deprec[month-1];
        }
        cout << month << " month" << ((month>1) ? "s" : "") << endl;
    }
}