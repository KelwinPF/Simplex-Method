#include <iostream>

using namespace std;

int main()
{
    int qtx,i,j,ineq,linhafl=0,colunaentra=0,flag = 1,cont = 0;

    cout<<"entre a quantidade de xs" << endl;
    cin>>qtx;
    cout<<"qtd de inequacoes (tem q estar =)" << endl;
    cin>>ineq;
    double teste = 0.00001;
    double fatorlimitante = 10000000,valordiv,valormult;
    double valorentra = 10000000;
    double m[ineq+1][qtx+2];

    for(i=0;i<ineq+1;i++){
        if(i==0){
            cout<<"entre com a z"<<endl;
        }else{
            cout<<"entre com a ineq: "<< i <<endl;
        }
        for(j=0;j<qtx+2;j++){
            cin>>m[i][j];
        }
    }
    cout<<endl;
    cout<<"____________________________________________________"<<endl;
    cout<<endl;

    for(i=0;i<ineq+1;i++){
        cout<<"L"<<i<<" | ";
        for(j=0;j<qtx+2;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
     }

    while(flag == 1){

        flag = 0;

        for(j=1;j<qtx+1;j++){
          if(m[0][j]<0){
            flag = 1;
          }
        }

        if(flag == 0){
            break;
        }

        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<"ITERACAO "<<cont + 1;
        cout<<endl;
        cont++;

        for(j=1;j<qtx+1;j++){
            if(m[0][j]<valorentra && m[0][j]<0){
                valorentra = m[0][j];
                colunaentra = j;
            }
        }

        cout<<"a coluna que entra e: "<<colunaentra << " com valor: " << valorentra <<endl;
        cout<<endl;

        for(i=1;i<ineq+1;i++){

            cout<<"linha "<<i<<": "<<m[i][qtx+1]<<"/"<<m[i][colunaentra]<<endl;

            if(((m[i][qtx+1]/m[i][colunaentra])<fatorlimitante) && ((m[i][qtx+1]/m[i][colunaentra])>0)){
                fatorlimitante = m[i][qtx+1]/m[i][colunaentra];
                linhafl = i;
                cout<<endl;
            }
        }

        cout<<endl;
        cout<<"a linha que sai e: "<<linhafl<<endl;
        cout<<endl;
        if(linhafl == 0){
            break;
        }

        valordiv = m[linhafl][colunaentra];
        for(j=0;j<qtx+2;j++){
            m[linhafl][j] = m[linhafl][j]/valordiv;
            if(m[linhafl][j] == -0){
                m[linhafl][j] = 0;
            }
        }


        for(i=0;i<ineq+1;i++){
            if(linhafl == i){
                continue;
            }
            valormult = m[i][colunaentra]*(-1);
            for(j=0;j<qtx+2;j++){
                if(i!=linhafl){
                    m[i][j] = m[i][j] + (valormult)*m[linhafl][j];
                    if(m[i][j]<teste && m[i][j]>0){
                        m[i][j] = 0;
                    }
                    if(m[i][j]>(teste*-1) && m[i][j]<0){
                        m[i][j] = 0;
                    }
                    if(m[i][j] == -0){
                        m[i][j] = 0;
                    }
                }
            }
        }

        for(i=0;i<ineq+1;i++){
            cout<<"L"<<i<<" | ";
            for(j=0;j<qtx+2;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    valormult = 0;
    linhafl = 0;
    colunaentra = 0;
    valordiv = 0;
    valormult = 0;
    valorentra = 10000000;
    fatorlimitante = 10000000;

    }
    return 0;
}

