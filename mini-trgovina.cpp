#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int brojArtikla = 0;
    int izbor;
    int MAX = 50;
    string artikli[MAX];
    unsigned long long int barkod[MAX];
    float cijena[MAX];
    unsigned long long int barkod_pretraga;
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;

    datotekaUcitavanje.open("artikli.txt");
    while ( 1 )
    {
        datotekaUcitavanje >> barkod[brojArtikla];
        if (datotekaUcitavanje.eof() == true)
            break;
        datotekaUcitavanje.ignore();
        getline(datotekaUcitavanje, artikli[brojArtikla]);
        datotekaUcitavanje >> cijena [brojArtikla];
        brojArtikla;
    }
    datotekaUcitavanje.close();

    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos novog artikla" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema bar kodu artikla" << endl;
        cout << "4. Pretraga prema nazivu artikla" << endl;
        cout << "5. Izmjena podataka prema bar kodu" << endl;
        cout << "6. Ispisi sortirano prema nazivu artikla" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout << "Unesite bar kod artikla: ";
            cin >> barkod[brojArtikla];
            cout << "Unesite naziv artikla: ";
            cin.ignore();
            getline(cin, artikli[brojArtikla]);
            cout << "Unesite cijena artikla: ";
            cin >> cijena[brojArtikla];


            datotekaUpisivanje.open("artikli.txt", ios::app);
            datotekaUpisivanje << barkod[brojArtikla] << endl;
            datotekaUpisivanje << artikli[brojArtikla] << endl;
            datotekaUpisivanje << cijena[brojArtikla] << endl;
            datotekaUpisivanje.close();
            brojArtikla++;

        }
        else if( izbor == 2 )
        {
            cout << "bar kod" << "\t" << "naziv artikla" << "\t" << "cijena" << endl;
            for( int i = 0; i < brojArtikla; i++ )
            {
                cout << artikli[i] << "\t" << barkod[i] << "\t" << cijena[i] << endl;
            }
        }
        else if( izbor == 3 )
        {
            cout << "Unesite BAR kod koji zelite pronaci:" << endl;
            cin >> barkod_pretraga;
            bool pronadjen= false;
            for( int i = 0; i <brojArtikla; i++)
            {
                if (barkod_pretraga == barkod[i])
                {
                    cout << artikli[i] << "\t" << barkod[i] << "\t" << cijena[i] << endl;
                    pronadjen = true;
                    break;
                }
            }
            if (pronadjen == false)
            {
                cout << "Artikl nje pronadjen." << endl;
            }

        }
        else if( izbor == 4 )
        {
            string nazivArtikla;
            cout << "Unesite artikl koji zelite pronaci:" << endl;
            cin.ignore();
            getline(cin, nazivArtikla);
            bool pronadjen = false;
            for( int i = 0; i < brojArtikla; i++)
            {
                if (nazivArtikla == artikli[i])
                {
                    cout << artikli[i] << "\t" << barkod[i] << "\t" << cijena[i] << endl;
                    pronadjen = true;
                    break;
                }
            }
            if (pronadjen == false)
            {
                cout << "Artikl nje pronadjen." << endl;
            }
        }
        else if( izbor == 5 )
        {
            unsigned long long int barkod_pretraga;
            cout << "Upisite BAR kod po kojem razite artikl: " << endl;
            cin >> barkod_pretraga;
            bool pronadjen = false;
            for (int i = 0;i < brojArtikla; i++)
            {
                if (barkod_pretraga == barkod[i])
                    cout << "Unesite novu cijenu " << endl;
                cin >> cijena[i];
                break;
            }
        }
        else if( izbor == 6 )
        {
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
