#ifndef intKuyrukYildizKuyruk_hpp
#define intKuyrukYildizKuyruk_hpp

#include <iostream>
#include "intKuyrukYildizDugum.hpp"
using namespace std;



class intKuyrukYildizKuyruk
{
public:
	intKuyrukYildizDugum* on;
	intKuyrukYildizDugum* arka;
	int uzunluk;

	intKuyrukYildizKuyruk();

	~intKuyrukYildizKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	intKuyruk* getir(int say);

	void kuyrukEkle(intKuyruk* veri);

	void kuyrukCikar();
};






#endif