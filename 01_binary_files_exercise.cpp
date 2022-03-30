#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

struct vino {
       int sifra;
       char naziv [16];
       float cijena;       
};

bool compare(vino a, vino b){
	if(a.sifra < b.sifra)
		return 1;
	else 
		return 0;
}

int main(){
  int izbor;
  vino temp;
  list <vino> podaci;
  fstream dat("listavina.dat", ios::in | ios::out | ios::binary);
  dat.seekg(0, ios::beg); 
  dat.read((char *)&temp, sizeof(vino));
  while (!dat.eof()) {
	podaci.push_back(temp);
  cout<<temp.sifra<<" "<<temp.naziv<<" "<<temp.cijena<<endl;
  dat.read((char *)&temp, sizeof(vino));
  }
  dat.close();
  dat.open("listavina.dat", ios::in | ios::out | ios::binary);
  do{
    cout << "===========================" << endl;
	  cout << "1. Ispis liste vina" << endl; //ispo�etka u�ita sadr�aj datoteke u listu i ispi�e ga na zaslon
	  cout << "2. Dodavanje novog vina na listu" << endl; //dodaje novo vino u listu i datoteku
	  cout << "3. Izmjena cijene vina" << endl; //za jedno od vina na listi i u datoteci se mijenja �ifra
    cout << "4. Brisanje vina sa liste" << endl; //vino sa upisanom sifrom se bri�e iz liste i datoteke
    cout << "5. Sortiranje liste vina po sifri" << endl; //sortiraju se podaci o vinima u listi i datoteci po sifri
    cout << "6. Zamjena redoslijede dva vina u listi" << endl; //mijenja redoslijed dva vina u listi i datoteci
	  cout << "0. Izlaz" << endl << endl;
	  cout << "Izbor: ";
	  cin >> izbor;
	  switch (izbor) {
		  case 1:  
        // code block
        dat.seekg(0, ios::beg); 
        dat.read((char *)&temp, sizeof(vino));
        cout << "===========================" << endl;
        cout << "Lista vina:" << endl;
        cout << "===========================" << endl;
        while (!dat.eof()) {
          cout<<temp.sifra<<" "<<temp.naziv<<" "<<temp.cijena<<endl;
          dat.read((char *)&temp, sizeof(vino));
          }
          dat.close();
          dat.open("listavina.dat", ios::in | ios::out | ios::binary);
      break;
		  case 2: 
        // code block
        vino novo;
        cout << "Upisite sifru:" << endl;
        cin >> novo.sifra;
        cout << "Upisite naziv:" << endl;
        cin >> novo.naziv;
        cout << "Upisite cijenu:" << endl;
        cin >> novo.cijena;
        dat.seekg(0, ios::end);
        dat.write((char *)&novo, sizeof(vino));
        podaci.clear();
        dat.seekg(0, ios::beg); 
        dat.read((char *)&temp, sizeof(vino));
        while (!dat.eof()) {
          podaci.push_back(temp);
          dat.read((char *)&temp, sizeof(vino));
          }
          dat.close();
          dat.open("listavina.dat", ios::in | ios::out | ios::binary);
      break;
		  case 3:
        // code block
        int sifra, cijena;
        cout << "Upisite sifru:" << endl;
        cin >> sifra;
        cout << "Upisite cijenu:" << endl;
        cin >> cijena;
        dat.seekg(0, ios::beg); 
        for (list<vino>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          vino temp2;
          if((*i).sifra == sifra) {
            (*i).cijena = cijena;
          }
          temp2.sifra = (*i).sifra;
          strcpy(temp2.naziv, (*i).naziv);
          temp2.cijena = (*i).cijena;
          dat.write((char *)&temp2, sizeof(vino));
        }
      break;
      case 4: {
        // code block  
        int sifradel;
        ofstream ofs;
        ofs.open("temp.dat", ios::out | ios::binary);
        cout << "Upisite sifru vina koje zelite izbrisati:" << endl;
        cin >> sifradel;
        for (list<vino>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          vino temp2;
          if((*i).sifra != sifradel) {
          temp2.sifra = (*i).sifra;
          strcpy(temp2.naziv, (*i).naziv);
          temp2.cijena = (*i).cijena;
          ofs.write((char *)&temp2, sizeof(vino));
          }
        }
        ofs.close();
        ifstream ifs;
        ifs.open("temp.dat", ios::in | ios::binary);
        podaci.clear();
        ifs.seekg(0, ios::beg); 
        ifs.read((char *)&temp, sizeof(vino));
        while (!ifs.eof()) {
          podaci.push_back(temp);
          ifs.read((char *)&temp, sizeof(vino));
          }
        dat.close();
        ifs.close();
        remove("listavina.dat");
        rename("temp.dat", "listavina.dat");
        dat.open("listavina.dat", ios::in | ios::out | ios::binary);
      break;
      }
      case 5: 
        // code block
      podaci.sort(compare);
      dat.seekg(0, ios::beg); 
        for (list<vino>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          vino temp2;
          temp2.sifra = (*i).sifra;
          strcpy(temp2.naziv, (*i).naziv);
          temp2.cijena = (*i).cijena;
          dat.write((char *)&temp2, sizeof(vino));
        }
      break;
      case 6:
        // code block
        int sifra1, sifra2;
        vino temp3, temp4;
        cout << "Upisite sifru prvog vina:" << endl;
        cin >> sifra1;
        cout << "Upisite sifru drugog vina:" << endl;
        cin >> sifra2;
        for (list<vino>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          if((*i).sifra == sifra1) {
          temp3.sifra = (*i).sifra;
          strcpy(temp3.naziv, (*i).naziv);
          temp3.cijena = (*i).cijena;
          }
          else if((*i).sifra == sifra2) {
          temp4.sifra = (*i).sifra;
          strcpy(temp4.naziv, (*i).naziv);
          temp4.cijena = (*i).cijena;
          }
        }
        dat.seekg(0, ios::beg); 
        for (list<vino>::iterator i=podaci.begin(); i!=podaci.end(); i++){
          vino temp2;
          if((*i).sifra == sifra1) {
          (*i).sifra = temp4.sifra;
          strcpy((*i).naziv, temp4.naziv);
          (*i).cijena = temp4.cijena;
          }
          else if((*i).sifra == sifra2) {
          (*i).sifra = temp3.sifra;
          strcpy((*i).naziv, temp3.naziv);
          (*i).cijena = temp3.cijena;
          }
          temp2.sifra = (*i).sifra;
          strcpy(temp2.naziv, (*i).naziv);
          temp2.cijena = (*i).cijena;
          dat.write((char *)&temp2, sizeof(vino));
        }

      break;
      
    }

	} while (izbor != 0);


  return 0;
}


