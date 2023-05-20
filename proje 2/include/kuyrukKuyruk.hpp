#ifndef kuyrukKuyruk_hpp
#define kuyrukKuyruk_hpp


#include <iostream>
#include "kuyrukYildizDugum.hpp"
using namespace std;


class kuyrukKuyruk
{
public:
	kuyrukYildizDugum* on;
	kuyrukYildizDugum* arka;
	int uzunluk;

	kuyrukKuyruk();

	~kuyrukKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	intYildizKuyruk* getir(int say);

	void kuyrukEkle(intYildizKuyruk* veri);

	void kuyrukCikar();


};




#endif