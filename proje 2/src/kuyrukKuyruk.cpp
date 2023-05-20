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
** DOSYA ACIKLAMSI........: Her bir elemanında intYildizKuyruk sinifindan eleman tutan kuyruk sinifi
****************************************************************************************************/
#include "kuyrukKuyruk.hpp"

kuyrukKuyruk::kuyrukKuyruk()
{
	on = arka = 0;

	uzunluk = 0;
}

kuyrukKuyruk::~kuyrukKuyruk()
{
	temizle();
}

int kuyrukKuyruk::elemanSayisi()const
{
	return uzunluk;
}

bool kuyrukKuyruk::bosMu()const
{
	if (uzunluk == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void kuyrukKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}

intYildizKuyruk* kuyrukKuyruk::getir(int say)
{
	kuyrukYildizDugum* temp = on;
	int sayac = 0;
	if (say == 0)
	{
		return temp->veri;
	}
	else
	{
		while (temp != 0)
		{

			if (say == sayac)
			{
				return temp->veri;
			}
			sayac++;
			temp = temp->sonraki;
		}
	}
}

void kuyrukKuyruk::kuyrukEkle(intYildizKuyruk* veri)
{
	kuyrukYildizDugum* son = new kuyrukYildizDugum(veri);
	if (bosMu())
	{
		on = arka = son;
	}
	else
	{
		arka->sonraki = son;
		arka = son;
	}
	uzunluk++;
}

void kuyrukKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		kuyrukYildizDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}
