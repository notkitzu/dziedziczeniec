#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class towar
{
	public:
	    struct marka
        {
            int id;
            float cena;
            string marka, model;
        };
	    vector <struct marka> wektor;
        void wprowadz();
        void wypisz();
        void zapiszDoPliku(const char *);
};

class marka : public towar
{
	public:
	void x()
	{
		towar::wprowadz();
		towar::wypisz();
		towar::zapiszDoPliku("wypisz.txt");
	}	
};

void towar::wprowadz()
{
    struct marka podaj;
    {
        cout << "Podaj id, marke, model i cene: ";
        cin >> podaj.id
            >> podaj.marka
            >> podaj.model
            >> podaj.cena;
        wektor.push_back(podaj);
    }
}

void towar::wypisz()
{
    for (vector<struct marka>::iterator it = wektor.begin(); it != wektor.end(); ++it)
    {
        cout<<"\n\n"<< it->id<<"\n"
        << it->marka<<"\n"
        << it->model<<"\n"
		<< it->cena<<"pln";
    }
}

void towar::zapiszDoPliku(const char *nazwa)
{
    ofstream plik;
    plik.open(nazwa);
    for (vector<struct marka>::iterator it = wektor.begin(); it != wektor.end(); ++it)
    {
        plik<<"{ Id: "
			<< it->id << "\ }\n" 
            << "{ marka: "<< it->marka <<" }\n" 
            << "{ model: " << it->model <<" }\n"
			<< "{ cena: "<< it->cena << "pln }\n";
    }	
    plik.close();  
}

int main(int argc, char** argv) {
    
    marka Y;
    Y.x();
    
return 0;
}
