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
** DOSYA ACIKLAMSI........: Her bir elemaninda integer veriye sahip kuyruk tutan kuyruk sinifi
****************************************************************************************************/
#include "intKuyrukYildizKuyruk.hpp"

intKuyrukYildizKuyruk::intKuyrukYildizKuyruk()
{
	on = arka = 0;

	uzunluk = 0;
}

intKuyrukYildizKuyruk::~intKuyrukYildizKuyruk()
{
	temizle();
}

int intKuyrukYildizKuyruk::elemanSayisi()const
{
	return uzunluk;
}

bool intKuyrukYildizKuyruk::bosMu()const
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

void intKuyrukYildizKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
		
	}
}


intKuyruk* intKuyrukYildizKuyruk::getir(int say)
{
	intKuyrukYildizDugum* temp = on;
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

void intKuyrukYildizKuyruk::kuyrukEkle(intKuyruk* veri)
{
	intKuyrukYildizDugum* son = new intKuyrukYildizDugum(veri);
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

void intKuyrukYildizKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		
		on->veri->~intKuyruk();
		intKuyrukYildizDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}