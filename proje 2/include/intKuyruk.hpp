#ifndef intKuyruk_hpp
#define intKuyruk_hpp

#include <iostream>
#include "intKuyrukDugum.hpp"
using namespace std;





class intKuyruk
{
public:
	intKuyrukDugum* on;
	intKuyrukDugum* arka;
	int uzunluk;

	intKuyruk();

	~intKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	int ilkElemaniGetir() const;

	int getir(int say);

	void kuyrukEkle(const int veri);

	void kuyrukCikar();

};






#endif