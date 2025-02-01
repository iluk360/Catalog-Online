#include <iostream>
#include <fstream>

using namespace std;

int nrNote = 0, key, i, j;
double note[999];

void menu()
{
    cout << "Tasta 1 pentru a adauga o nota." << endl;
    cout << "Tasta 2 pentru a vedea toate notele din catalog." << endl;
    cout << "Tasta 3 pentru a calcula media notelor din catalog." << endl;
    cout << "Tasta 4 pentru a afisa nota maxima si nota minima." << endl;
    cout << "Tasta 5 pentru a sorta crescator notele." << endl;
    cout << "Tasta 6 pentru a sorta descrescator notele." << endl;
    cout << "Tasta 7 pentru a cauta o nota in catalog." << endl;
    cout << "Tasta 8 pentru a vedea de cate ori apare o nota anume." << endl;
    cout << "Tasta 9 pentru a sterge o nota" << endl;
    cout << "Tasta 10 pentru a sterge toate aparitiile unei note." << endl;
    cout << "Tasta 11 pentru a reseta catalogul." << endl;
    cout << "Tasta 12 pentru a iesi." << endl << endl;
}

void insertKey()
{
    cout << "Introduce o tasta: ";
    cin >> key;
    switch(key)
    {
        case 1:
            {
                cout << "Introduce o nota: ";
                cin >> note[nrNote];
                cout << "Nota salvata." << endl << endl;
                nrNote++;
                insertKey();
                break;
            }
        case 2:
            {
                cout << "Lista note" << endl;
                for (i = 1; i <= nrNote; i++)
                {
                    cout << note[i-1] << ' ';
                }
                cout << endl;
                if (nrNote == 0) cout << "none" << endl << endl;
                insertKey();
                break;
            }
        case 3:
            {
                double s = 0;
                if (nrNote > 0)
                {
                    for (i = 0; i < nrNote; i++)
                    {
                        s += note[i];
                    }
                double medie = s / nrNote, amount = nrNote;
                cout << "Media notelor este de " << medie << ", fiind " << nrNote << " nota(e) in catalog." << endl << endl;
                }
                else cout << "Nu exista nicio nota!" << endl << endl;
                insertKey();
                break;
            }
        case 4:
            {
                int minim = 99999, maxim = 0;
                if (nrNote > 0)
                {
                    for (i = 0; i < nrNote; i++)
                    {
                        if (note[i] > maxim) maxim = note[i];
                        if (note[i] < minim) minim = note[i];
                    }
                    cout << "Nota maxima este de " << maxim << ", iar cea minima de " << minim << endl << endl;
                }
                else cout << "Nu exista nicio nota!" << endl << endl;
                insertKey();
                break;
            }
        case 5:
            {
                int sir[nrNote], aux;
                if (nrNote > 1)
                {
                    for (i = 0; i < nrNote; i++) sir[i] = note[i];
                    for (i = 0; i < nrNote - 1; i++)
                    {
                        for (j = i + 1; j <= nrNote - 1; j++)
                        {
                            if (sir[i] > sir[j])
                            {
                                aux = sir[i];
                                sir[i] = sir[j];
                                sir[j] = aux;
                            }
                        }
                    }
                    cout << "Note ordonate crescator:" << endl;
                    for (i = 0; i < nrNote; i++) cout << sir[i] << ' ';
                    cout << endl;
                }
                else cout << "Nu exista minim 2 note!" << endl << endl;
                insertKey();
                break;
            }
        case 6:
            {
                int sir[nrNote], aux;
                if (nrNote > 1)
                {
                    for (i = 0; i < nrNote; i++) sir[i] = note[i];
                    for (i = 0; i < nrNote - 1; i++)
                    {
                        for (j = i + 1; j <= nrNote - 1; j++)
                        {
                            if (sir[i] < sir[j])
                            {
                                aux = sir[i];
                                sir[i] = sir[j];
                                sir[j] = aux;
                            }
                        }
                    }
                    cout << "Note ordonate descrescator:" << endl;
                    for (i = 0; i < nrNote; i++) cout << sir[i] << ' ';
                    cout << endl;
                }
                else cout << "Nu exista minim 2 note!" << endl << endl;
                insertKey();
                break;
            }
        case 7:
            {
                int number;
                cout << "Introduce o nota: ";
                cin >> number;
                if (nrNote > 1)
                {
                    for (i = 0; i < nrNote; i++)
                    {
                        if (note[i] == number)
                        {
                            cout << "Nota " << number << " a fost gasita pe pozitia [interger] " << i << endl << endl;
                            break;
                        }
                    }
                }
                else cout << "Nu exista minim 2 note!" << endl << endl;
                insertKey();
                break;
            }
        case 8:
            {
                int number, amount = 0;
                cout << "Introduce o nota: ";
                cin >> number;
                if (nrNote > 1)
                {
                    for (i = 0; i < nrNote; i++)
                    {
                        if (note[i] == number) amount++;
                    }
                    cout << "Nota " << number << " a fost gasita de " << amount << " ori." << endl << endl;
                }
                else cout << "Nu exista minim 2 note!" << endl << endl;
                insertKey();
                break;
            }
        case 9:
            {
                int pos;
                cout << endl << "Introduce pozitia notei[interger]: ";
                cin >> pos;
                for (i = pos; i < nrNote; i++)
                {
                    note[i] = note[i+1];
                }
                note[nrNote-1] = 0;
                nrNote--;
                cout << "Nota salvata." << endl << endl;
                insertKey();
                break;
            }
        case 10:
            {
                int number;
                if (nrNote > 1)
                {
                    cout << endl << "Introduce nota: ";
                    cin >> number;
                    for (i = 0; i < nrNote; i++)
                    {
                        if (note[i] == number)
                        {
                            for (j = i; j < nrNote; j++)
                            {
                                note[j] = note[j+1];
                            }
                            note[nrNote-1] = 0;
                        }
                        nrNote--;
                    }
                    cout << "Ok." << endl << endl;
                }
                else cout << "Nu exista nicio nota!" << endl << endl;
                insertKey();
                break;
            }
        case 11:
            {
                for (int i = 0; i < nrNote; i++) note[i] = 0;
                nrNote = 0;
                cout << "Catalog resetat." << endl << endl;
                insertKey();
                break;
            }
        case 12:
            {
                break;
            }
        default:
            cout << "Tasta invalida!" << endl;
            insertKey();
    }
}

int main()
{
    cout << endl << "Bine ai venit la ViVa Catalog!" << endl << endl;
    menu();
    insertKey();
    return 0;
}
