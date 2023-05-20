#ifndef AgacKuyruk_hpp
#define AgacKuyruk_hpp

#include <iostream>
#include "agacKuyrukDugum.hpp"  
#include "ikiliAramaAgaci.hpp"

using namespace std;

class AgacKuyruk
{
public:
	agacKuyrukDugum* on;
	agacKuyrukDugum* arka;
	int uzunluk;

	AgacKuyruk();

	~AgacKuyruk();

	int elemanSayisi()const;

	bool bosMu()const;

	void temizle();

	ikiliAramaAgaci* getir(int say);


	void kuyrukEkle(ikiliAramaAgaci* veri);


	void kuyrukCikar();


};



















#endif