#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;
int *matica=new int[0];
int velkostMatice=sizeof(*matica/4);
int num_lines=0;// riadky v subore
bool is_number(string str)
	{
	for(int i = 0;i < (str.length() - 1);i++) {
		if((int)str[i] < 10) {
			return true;
		} else {
			return false;
		}
	}
	}

void Realoc(int prvok) //prida jeden prvok do matice
{
    int *kopiaMatice = new int[velkostMatice];

    for(int i=0;i < velkostMatice;i++)
    {
        kopiaMatice[i]=matica[i];
    }
    velkostMatice++;
    delete[] matica;

    matica = new int[velkostMatice];

    for(int i=0;i<(velkostMatice-1);i++)
    {
        matica[i]=kopiaMatice[i];
    }
    delete[] kopiaMatice;

    matica[velkostMatice-1]=prvok;
}

bool ZvolVstup() //vyberie vstup 0 pre klavesnicu 1 pre subor
{
    bool a;
    cout<<"Zadaj ako zadat vstup 1= Zo suboru 0 = Z klávesnice po riadkoch"<<endl;
    cin>>a;
    if(cin.fail())
    {
            cin.clear();
            cin.ignore();
            cout<<"MusíŠ zadat 1 alebo 0"<<endl;
            return ZvolVstup();
    }
    return a;
}

void zadajVstup()//nacita prvy riadok matice
{
    bool a=1;
    cout<<"Zadaj 1 riadok matice ukonci zadanim niecoho ineho ako cisla"<<endl;
    for(int i=0; a==1;i++)
    {
        int vstupne_cislo;
        cin>>vstupne_cislo;
        if(cin.fail())
        {
            a=0;
            break;
        }
        else
        {
            if(i==velkostMatice)
            {
                Realoc(i);
            }
            else
            {
                matica[i]=vstupne_cislo;
            }

        }
    }
    velkostMatice--;
}

int ZadajCislo(int riadok)//zadavanie cisel do dalsich riadkov pomocou enteru vzdy
{
    cin.clear();
    cin.ignore();
    int vstupne_cislo;

    cout<<"Zadaj "<<riadok+1<<" riadok oddeluj cisla enterom"<<endl;
    cin>>vstupne_cislo;
        if(cin.fail())
        {
            cout<<"musis zadat cislo"<<endl;
            return ZadajCislo(riadok);
        }
        else
        {
            return  vstupne_cislo;
        }

}

bool vstupZoSuboru()
{
    string line;
    string vstupne_cislo;
    fstream subor;
    subor.open("vstup2.txt");
    if(!subor.is_open())
    {
        cout<<"Nepodarilo sa nacitat subor";
        return 0;
    }
    else
    {

        while(getline(subor, line))
        {
            num_lines++;
        }
        subor.clear();
        subor.seekg(0, ios::beg);

        for(int i=0; i<num_lines*num_lines;i++) // nacita maticu do riadku
        {
            subor >> vstupne_cislo;
                    if(i==velkostMatice)
                    {
                        Realoc(i);
                    }

                         int result;
                        stringstream(vstupne_cislo) >> result;
                        matica[i]=result;


        }
    }
    subor.close();
    velkostMatice--;
    return 1;
}


bool SuborKompletMatica()
{
    for(int i=0;i<num_lines;i++)
    {
        for(int j=0;j<num_lines;j++)
        {

        }
    }
}



int main()
{
    bool Vstup=ZvolVstup();//premenna ci budu data tahane zo subora alebo z klavesnice

    if(Vstup==0) //ak klavesnica k zadavanie ak subortak nacitanie
    {
        zadajVstup();
        int FinalnaMatica[velkostMatice][velkostMatice]; //vytvoreniefinalnej matice a nasledne jej naplnenie
            for(int i=0;i<velkostMatice;i++)
            {
                for(int j=0;j<velkostMatice;j++)
                {

                    if(i==0)
                    {
                        FinalnaMatica[i][j]=matica[j];
                    }
                    else
                    {
                        FinalnaMatica[i][j]=ZadajCislo(i);

                    }
                }
            }



            /*vypis matice*/

            for(int i=0;i<velkostMatice;i++)
            {
            cout<<"|";
            for(int j=0;j<velkostMatice;j++)
            {
                cout<<" "<<FinalnaMatica[i][j];
            }
            cout<<" |"<<endl;;
            }


    }
    else
    {
        vstupZoSuboru();
        float FinalnaMatica[num_lines][num_lines]; //vytvoreniefinalnej matice a nasledne jej naplnenie
        int line=0;
        int pomoc=0;
                for(int j=0;j<=num_lines;j++)
                {
                    if(j==num_lines && num_lines !=line)
                    {
                         line++;
                         j=0;
                         pomoc=pomoc+num_lines;
                    }
                        FinalnaMatica[line][j]=(float)matica[j+pomoc];
                }
         /*vypis matice*/
         cout<<"pocet r: "<<num_lines<<endl;
            for(int i=0;i<num_lines;i++)
            {
                for(int j=0;j<num_lines;j++)
                {
                    cout<<" |"<<FinalnaMatica[i][j];
                }
                cout<<" |"<<endl;;
            }

              //GausovaMetoda
          /*  bool Gaus;
            cout<<"Chcete spravit Gausivu metodu? 1 =ano 0 =nie"<<endl;
            cin>>Gaus;
            if(Gaus==1)
            {
                for(int k=1;k<num_lines;k++)
                {
                    for(int i=k+1;i<=num_lines;i++)
                    {
                        cout<<"FinalnaMatica[k-1][k-1] je: "<<FinalnaMatica[k-1][k-1]<<" FinalnaMatica[k][k-1] je: "<<FinalnaMatica[k][k-1]<<endl;

                        float premenna=(FinalnaMatica[i-k-1][i-k-1])/FinalnaMatica[k][i-k-1]*(-1);

                        cout<<premenna<<" - Premenna je"<<endl;
                        for(int j= k;j<num_lines+1;j++)
                        {
                            cout<<"Hodnota matice [k][i]: "<<FinalnaMatica[k][i]<<endl;
                            cout<<"Hodnota matice [k-1][i]: "<<FinalnaMatica[k-1][i]<<endl;
                            FinalnaMatica[k][j-1]=FinalnaMatica[k][j-1]*premenna+FinalnaMatica[k-1][j-1];
                            cout<<"k = "<<k<<" i = "<<i<<" j = "<<j<<endl;
                        }

                        /*for(int j=k+1;j<num_lines;j++)
                        {
                         FinalnaMatica[i][j]=FinalnaMatica[i][j]-FinalnaMatica[i][k]/FinalnaMatica[k][k]*FinalnaMatica[k][j];
                        }
                    }
                }*/

                fstream subor;
                ofstream writer;
                subor.open("vstup.txt");
                writer.open("vystup.txt");
                   cout << writer << " created!" << endl;
                string retazec;
                    while(getline(subor,retazec))
                    {
                        writer<<retazec;
                    }



            for(int i=0;i<num_lines;i++)
            {
                for(int j=0;j<num_lines;j++)
                {
                    cout<<" |"<<FinalnaMatica[i][j];
                }
                cout<<" |"<<endl;;
            }

    }

    return 0;
    }




