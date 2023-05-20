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
** DOSYA ACIKLAMSI........: Radix siralamanın yapildigi sinif
****************************************************************************************************/
#include "Radix.hpp"
Radix::Radix(int* sayilar, int adet)
{
	this->sayiAdedi = adet;

	this->sayilar = new int[sayiAdedi];

	for (int i = 0; i < sayiAdedi; i++)
		this->sayilar[i] = sayilar[i];

	kuyruklar = new intKuyruk * [10];
	for (int i = 0; i < 10; i++)
	{
		kuyruklar[i] = new intKuyruk();
	}
}
Radix::~Radix()
{
	delete[] sayilar;
	for (int i = 0; i < 10; i++)
	{
		delete kuyruklar[i];
	}
	delete[] kuyruklar;


}

int* Radix::sirala()
{

	for (int i = 0; i < sayiAdedi; i++)
	{
		int sonBasamak = sayilar[i] % 10;

		kuyruklar[sonBasamak]->kuyrukEkle(sayilar[i]);

	}
	int maxBasamakSayisi = maxBasamakSayisiGetir();


	int basamakCarpani = 10;

	for (int i = 1; i < maxBasamakSayisi; i++)
	{
		int uzunluklar[10];

		kuyrukUzunluklariGetir(uzunluklar);

		for (int j = 0; j < 10; j++)
		{
			int es = uzunluklar[j];

			while (es)
			{
				int siradakiSayi = kuyruklar[j]->ilkElemaniGetir();

				kuyruklar[j]->kuyrukCikar();
				int basamak = (siradakiSayi / basamakCarpani) % 10;
				kuyruklar[basamak]->kuyrukEkle(siradakiSayi);
				es--;
			}
		}
		basamakCarpani *= 10;
	}
	int diziIndex = 0;
	for (int i = 0; i < 10; i++)
	{
		while (!kuyruklar[i]->bosMu())
		{
			sayilar[diziIndex] = kuyruklar[i]->ilkElemaniGetir();
			kuyruklar[i]->kuyrukCikar();
			diziIndex++;
		}
	}

	return sayilar;
}

int Radix::maxBasamakSayisiGetir()
{
	int maxBasamakSayisi = basamakSayisiGetir(sayilar[0]);

	for (int i = 1; i < sayiAdedi; i++)
	{
		int siradakiBasamakSayisi = basamakSayisiGetir(sayilar[i]);
		if (maxBasamakSayisi < siradakiBasamakSayisi)
			maxBasamakSayisi = siradakiBasamakSayisi;
	}
	return maxBasamakSayisi;
}
int Radix::basamakSayisiGetir(int sayi)
{
	int basamakSayisi = 0;
	while (sayi)
	{
		sayi = sayi / 10;
		basamakSayisi++;
	}
	return basamakSayisi;

}
void Radix::kuyrukUzunluklariGetir(int* uzunluklar)
{
	for (int i = 0; i < 10; i++)
	{
		uzunluklar[i] = kuyruklar[i]->elemanSayisi();
	}
}