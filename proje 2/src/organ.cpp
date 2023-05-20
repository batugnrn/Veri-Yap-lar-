/*****************************************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** VERİ YAPILARI DERSİ
** 2022-2023 GÜZ DÖNEMİ
**
**
** ÖDEV ..................: 2. ÖDEV
** ÖĞRENCİ ADI............: BAHRİ BATUHAN GÜNEREN
** ÖĞRENCİ NUMARASI.......: G201210059
** MAİL ..................: bahri.guneren@ogr.sakarya.edu.tr
** DERSİN ALINDIĞI GRUP...: 2.ÖĞRETİM C GRUBU
**
**
** DOSYA ACIKLAMSI........: Her 20 satırda bir organ oluşturuldugu sinif
****************************************************************************************************/
#include "organ.hpp"

organ::~organ()
{
	delete organKuyrugu;
	delete mutasyonluOrganKuyrugu;
	delete agacKuyrugu;
	

}
stringKuyruk* organ::organOlustur(intKuyrukYildizKuyruk* dokularKuyruk)
{															
	int a = dokularKuyruk->elemanSayisi() / 20;
	for (int i = 0; i < a; i++)
	{
		ikiliAramaAgaci* agac = new ikiliAramaAgaci();
		for (int j = 20*i; j < 20*(i+1); j++)           // for dongusu  0-20,  20-40,  40-60,....  diye gidiyor |  aslinda bu yuzden ilk basta biraz bekliyoruz  :D
		{	
			int bb = dokularKuyruk->getir(j)->elemanSayisi() / 2;
			agac->ekle(dokularKuyruk->getir(j)->getir(bb), dokularKuyruk->getir(j));			
		}
		agacKuyrugu->kuyrukEkle(agac);      // her 20' de bir olusan agaclari tutan kuyruga eklme islemi

		if (agac->dengeliMi())
		{
			organKuyrugu->kuyrukEkle(" ");
		}
		else
		{
			organKuyrugu->kuyrukEkle("#");
		}
	}
	system("cls");
	cout << setw(35) << "Organizma" << endl;
	return organKuyrugu;
}

stringKuyruk* organ::mutasyon(intKuyrukYildizKuyruk* dokularKuyruk)
{
	int say = 0;
	int b = 0;
	int a = dokularKuyruk->elemanSayisi() / 20;
	for (int i = 0; i < a; i++)
	{
		b = agacKuyrugu->getir(i)->dondur()->veri % 50;
		if (b == 0)
		{
			hucre* h = new hucre();
			for (int j = 0; j < 20; j++)
			{
				intKuyruk* temp = new intKuyruk();
				
				say = agacKuyrugu->getir(i)->postOrder(agacKuyrugu->getir(i)->dondur())->getir(j)->elemanSayisi();  //post order gelen ilk kurugun eleman sayisini bula
				for (int l = 0; l < say; l++)
				{
					temp->kuyrukEkle(agacKuyrugu->getir(i)->postOrder(agacKuyrugu->getir(i)->dondur())->getir(j)->getir(l));   // post order gelen ilk kuyrugu gecici kuyuga atama 
				}
				h->DNAdegistir(temp, say);      // post order gelen ilk kuyrugu DNA'sini yariya indirme 
			}

			ikiliAramaAgaci* tempAgac = new ikiliAramaAgaci();
			for (int g = 0; g < 20; g++)
			{
				tempAgac->ekle(h->MutasyonluAgac()->getir(g));       // mutasyona ugramıs agacı yeniden olusturma
			}
			if (tempAgac->dengeliMi())
			{
				mutasyonluOrganKuyrugu->kuyrukEkle(" ");
			}
			else
			{
				mutasyonluOrganKuyrugu->kuyrukEkle("#");
			}

			delete tempAgac;
			delete h;

		}
		else
		{
			if (agacKuyrugu->getir(i)->dengeliMi())
			{
				mutasyonluOrganKuyrugu->kuyrukEkle(" ");
			}
			else
			{
				mutasyonluOrganKuyrugu->kuyrukEkle("#");
			}
		}
	}
	return mutasyonluOrganKuyrugu;


}
