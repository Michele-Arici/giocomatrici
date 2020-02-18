#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    float matGioco[10][3], puntata;
    float zeri[10][3];
    int random, giocata;
    string uscire;
    string si = "si";
    string no="no";

    cout << "Inserire quanto vuoi puntare: ";
    cin >> puntata;

    system("cls");

    float prezzo = puntata;
    const float aumento = puntata*15/100;

    //int riga = 10;
    int riga = 9;
    int bomba=0;


    srand(time(NULL));
    for (int i=0; i<10 ; i++ )
    {
        prezzo += aumento;
        random=(rand()%3);
        for (int j=0 ; j<3 ; j++ )
        {
            if (j==random)
            {
                zeri[i][j]=0;
            }
            else
            {
                zeri[i][j] = 1;
            }
            matGioco[i][j] = prezzo;
        }
    }

    prezzo = puntata;

    for (int i=9; i>=0; i--)
    {
        cout << endl;
        cout << "| ";
        prezzo += aumento;
        for (int j=0; j<3; j++)
        {
            cout << matGioco[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------------";
    }

    do
    {
        cout << endl;
        cout << "0, 1 o 2? ";
        cin >> giocata;

        //system("cls");

        for (int i=0; i<10; i++)
        {
            cout << endl;
            for (int j=0; j<3; j++)
            {
                cout << zeri[i][j] << " ";
            }
        }

        /*if(riga==10)
        {
            for (int i=9; i>=0; i--)
            {
                cout << endl;
                cout << "| ";
                prezzo += aumento;
                for (int j=0; j<3; j++)
                {
                    cout << matGioco[i][j] << " | ";
                }
                cout << endl;
                cout << "-------------------";
            }
        }else
        {*/
        for (int i=9; i>=0; i--)
        {
            cout << endl;
            cout << "| ";
            prezzo += aumento;
            for (int j=0; j<3; j++)
            {
                if(i==(9-riga))
                {
                    matGioco[i][j] = -1;
                }
                if(matGioco[i][j] == -1)
                {
                    if (zeri[9-i][j]==0)
                    {
                        cout << " " << 'x' << "  | ";
                    }else
                    {
                        cout << " " << (char)1 << "  | ";
                    }
                }
                else
                    cout << matGioco[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------------";
        }
        //}


        cout << endl;

        if (zeri[riga][giocata] == 0)
        {
            bomba++;
            cout << "hai perso" << endl;
        }else if(riga==-1)
            {
                system("cls");
                cout << "JACKPOT! HAI VINTO " << prezzo << endl;
            }else
                {
                    do
                    {
                        cout << "Vuoi uscire e tenerti " << prezzo << " soldi? <si/no> ";
                        cin >> uscire;
                    }while (uscire!=no && uscire!=si);
                }
        system("cls");

        riga--;

    }
    while(bomba==0 && uscire==no);




    return 0;
}
