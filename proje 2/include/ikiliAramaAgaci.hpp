#ifndef ikiliAramaAgaci_hpp
#define ikiliAramaAgaci_hpp

#include <iostream>
#include "ikiliAramaAgaciDugum.hpp"
#include "intYildizKuyruk.hpp"
using namespace std;


class ikiliAramaAgaci
{
private:
	ikiliAramaAgaciDugum* kok;
	intKuyrukYildizKuyruk* pstordrKuyruk = new intKuyrukYildizKuyruk();
	bool varmi(int aranan, ikiliAramaAgaciDugum* aktif);

public:

	ikiliAramaAgaci();

	bool varmi(int veri);

	void ekle(int eklenecek, intKuyruk* doku);

	void ekle(int veri, ikiliAramaAgaciDugum* aktifDugum, intKuyruk* doku);

	void ekle(int eklenecek);

	void ekle(int veri, ikiliAramaAgaciDugum* aktifDugum);

	int yukseklik(ikiliAramaAgaciDugum* aktifDugum);

	intKuyrukYildizKuyruk* postOrder(ikiliAramaAgaciDugum* aktif);

	void sil(int aranan, ikiliAramaAgaciDugum*& aktif);

	int maxDeger(ikiliAramaAgaciDugum* aktif);

	bool dengeliMi();

	ikiliAramaAgaciDugum* dondur();

	~ikiliAramaAgaci();

	void temizle();

	bool bosMu() const;
	
	bool dugumSil(ikiliAramaAgaciDugum*& dugum);


};






#endif