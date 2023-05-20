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
** DOSYA ACIKLAMSI........: Her bir elemanında string karakter tutan kuyruk sinifi
****************************************************************************************************/
#include "stringKuyruk.hpp"
stringKuyruk::stringKuyruk()
{
	on = arka = 0;

	uzunluk = 0;
}
stringKuyruk::~stringKuyruk()
{
	temizle();
}
int stringKuyruk::elemanSayisi()const
{
	return uzunluk;
}
bool stringKuyruk::bosMu()const
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
void stringKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}
string stringKuyruk::ilkElemaniGetir() const
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
string stringKuyruk::getir(int say)
{
	stringDugum* temp = on;
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

void stringKuyruk::kuyrukEkle(const string veri)
{
	stringDugum* son = new stringDugum(veri);
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

void stringKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		stringDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}
