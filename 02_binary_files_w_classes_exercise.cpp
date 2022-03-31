#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

class stavka {
  char naziv [20];
  int kolicina;
  public:
  // promjena izvrsava funkciju stvaranja nove stavke i promjene stavke
  void promjena(char*, int);
  void print();
  char* getNaziv();
  int getKolicina();
};

char* stavka::getNaziv(){
  return naziv;
}

int stavka::getKolicina(){
  return kolicina;
}

void stavka::promjena(char* n, int k) {
  strcpy(naziv, n);
  kolicina = k;
};

void stavka::print() {
  cout << naziv << " " << kolicina << endl;
};


int main(){
  int izbor;
  list <stavka> podaci;
  fstream dat("kupovna_lista.dat", ios::in | ios::out | ios::binary);
  do{
    cout << "===========================" << endl;
	  cout << "1. Ispis svih stavki" << endl;
	  cout << "2. Dodavanje nove stavke" << endl;
	  cout << "3. Promjena stavke" << endl;
    cout << "4. Spremanje liste u datoteku" << endl;
    cout << "5. Upis liste iz datoteke" << endl;
	  cout << "0. Izlaz" << endl << endl;
	  cout << "Izbor: ";
	  cin >> izbor;
	  switch (izbor) {
		  case 1:  
        // code block
        cout << "===========================" << endl;
        cout << "Ispis stavki:" << endl;
        cout << "===========================" << endl;
        for (list<stavka>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          (*i).print();
        }
      break;
		  case 2: {
        // code block
        stavka novo;
        char temp[20];
        int temp2;
        cout << "Upisite naziv:" << endl;
        cin >> temp;
        cout << "Upisite kolicinu:" << endl;
        cin >> temp2;
        novo.promjena(temp, temp2);
        podaci.push_back(novo);
      break;
      }
		  case 3: {
        // code block
        char naziv[20];
        int kolicina;
        bool izmjenjen = false;
        cout << "Upisite naziv:" << endl;
        cin >> naziv;
        cout << "Upisite kolicinu:" << endl;
        cin >> kolicina;
        for (list<stavka>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          if(strcmp(naziv, (*i).getNaziv()) == 0){
            (*i).promjena(naziv, kolicina);
            izmjenjen = true;
          }
        }
        if(!izmjenjen) {
          cout << "Upisana stavka nije pronadena!" << endl;
        }
      break;
      }
      case 4: {
        // code block  
        dat.close();
        remove("kupovna_lista.dat");
        ofstream ofs;
        ofs.open("kupovna_lista.dat", ios::out | ios::binary);
        ofs.seekp(0, ios::beg); 
        for (list<stavka>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          stavka novo;
          novo.promjena((*i).getNaziv(), (*i).getKolicina());
          ofs.write((char *)&novo, sizeof(stavka));
        }
        ofs.close();
        dat.open("kupovna_lista.dat", ios::in | ios::out | ios::binary);
      break;
      }
      case 5: 
        // code block
        stavka temp;
        dat.seekg(0, ios::beg); 
        dat.read((char *)&temp, sizeof(stavka));
        podaci.clear();
        while (!dat.eof()) {
        podaci.push_back(temp);
        dat.read((char *)&temp, sizeof(stavka));
        }
        dat.close();
        dat.open("kupovna_lista.dat", ios::in | ios::out | ios::binary);
      break;
    }

	} while (izbor != 0);


  return 0;
}


