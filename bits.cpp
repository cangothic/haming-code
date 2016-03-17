#include <bits/stdc++.h>

using namespace std;

int main(){
    int entrada;
    cout<<"ingrese un numero en base diez"<<endl;
    while(cin>>entrada){
        bitset<16> original = entrada;
        bitset<21> paridad;
        int potenciaDeDos= 1;
        int j= 0;
        for(int i=1;i<=21;i++){
            if(i==potenciaDeDos){
                paridad[i-1] = 0;
                potenciaDeDos<<=1;
            }else{
                paridad[i-1] = original[j];
                j++;
            }
        }
        cout<<"original es "<<original<<endl;
        for(int j=1;j<=21;j=j*2){
            for(int i=1;i<=21;i++){
                if(i&j){
                    paridad[j-1]=(paridad[j-1]^paridad[i-1]);
                }
            }
        }
        cout<<"paridad es "<<paridad<<endl;
        //cout<<"ingrese el bit que quiere cambiar 1->21"<<endl;
        int cambio = (rand() % 21) +1;
        cout<<"OH NO SE HA MODIFICADO UN BIT!! "<<endl;
        paridad.flip(cambio-1);
        cout<<"AHORA TENEMOS EL BITSET "<<paridad<<"\nINTENTAREMOS RECUPERARNOS! "<<endl;
        int error = 0;
        for(int j=1;j<=21;j=j*2){
            int cuenta = 0;
            for(int i=1;i<=21;i++){
                if(i&j){
                    cuenta=(cuenta^paridad[i-1]);
                }
            }
            if(cuenta){
                cout<<"estaba mal el "<<j<<endl;
                error+=j;
            }
        }
        cout<<"el error es "<<error<<endl;
        paridad.flip(error-1);
        cout<<"nos recuperamos, el valor que habias enviado era "<<endl;
        cout<<paridad<<endl;
        cout<<"ingrese un numero en base diez"<<endl;
    }
}
