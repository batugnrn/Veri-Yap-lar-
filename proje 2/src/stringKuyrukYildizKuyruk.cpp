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
** DOSYA ACIKLAMSI........: Her bir elemanında string içeren kuyruk tutan kuyruk sinifi 
****************************************************************************************************/
#include "stringKuyrukYildizKuyruk.hpp"

stringKuyrukYildizKuyruk::stringKuyrukYildizKuyruk()
{
	on = arka = 0;
	uzunluk = 0;
}

stringKuyrukYildizKuyruk::~stringKuyrukYildizKuyruk()
{
	temizle();
}

int stringKuyrukYildizKuyruk::elemanSayisi()const
{
	return uzunluk;
}

bool stringKuyrukYildizKuyruk::bosMu()const
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

void stringKuyrukYildizKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}

stringKuyruk* stringKuyrukYildizKuyruk::ilkElemaniGetir() const
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	else
	{
		return on->veri;
	}
}

stringKuyruk* stringKuyrukYildizKuyruk::getir(int say)
{
	stringKuyrukYildizDugum* temp = on;
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


void stringKuyrukYildizKuyruk::kuyrukEkle(stringKuyruk* veri)
{
	stringKuyrukYildizDugum* son = new stringKuyrukYildizDugum(veri);
	if (uzunluk == 0)
	{
		on = arka = son;
		uzunluk++;
	}
	else
	{
		stringKuyrukYildizDugum* temp = on;
		while (temp->sonraki != NULL)
		{
			temp = temp->sonraki;
		}
		temp->sonraki = son;

		arka->sonraki = son;
		arka = son;
		uzunluk++;

	}

}

void stringKuyrukYildizKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		on->veri->~stringKuyruk();
		stringKuyrukYildizDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}


