#ifndef ikiliAramaAgaciDugum_hpp
#define ikiliAramaAgaciDugum_hpp

#include <iostream>
#include "intKuyrukYildizKuyruk.hpp"
#include "intKuyruk.hpp"
using namespace std;




class ikiliAramaAgaciDugum
{
public:
	ikiliAramaAgaciDugum* sol;
	ikiliAramaAgaciDugum* sag;

	int veri;
	intKuyruk* doku;
	int yukseklik = 0;

	ikiliAramaAgaciDugum(int veri, intKuyruk* doku);
	ikiliAramaAgaciDugum(int veri);


};
















#endif