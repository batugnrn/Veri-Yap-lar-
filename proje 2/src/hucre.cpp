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
** DOSYA ACIKLAMSI........: Mutasyona ugratma isleminin yaildigi sinif (yariya dusurme islemi)
****************************************************************************************************/
#include "hucre.hpp"

void hucre::DNAdegistir(intKuyruk* k, int say)
{
	int* dinamik;
	dinamik = new int[say];

	for (int i = 0; i < say; i++)
	{
		if (k->getir(i) % 2 == 0)
		{
			dinamik[i] = k->getir(i) / 2;
		}
		else
		{
			dinamik[i] = k->getir(i);
		}
	}
	Radix* r = new Radix(dinamik, say);
	sirali = r->sirala();

	orta = say / 2 + 1;
	ortaKuyruk->kuyrukEkle(sirali[orta]);

	delete[] dinamik;
	delete r;
}

hucre::~hucre()
{
	delete ortaKuyruk;
	delete k2;
}


intKuyruk* hucre::MutasyonluAgac()
{
	int* dinamik;
	dinamik = new int[20];
	for (int i = 0; i < 20; i++)
	{
		dinamik[i] = ortaKuyruk->getir(i);
	}

	Radix* r2 = new Radix(dinamik, 20);
	int* sirali2;
	sirali2 = r2->sirala();

	

	for (int i = 0; i < 20; i++)
	{
		k2->kuyrukEkle(sirali2[i]);
	}
	delete[] dinamik;
	delete r2;
	return k2;
}

