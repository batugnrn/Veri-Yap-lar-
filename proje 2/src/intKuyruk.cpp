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
** DOSYA ACIKLAMSI........: integer veri tutan kuyruk sinifi
****************************************************************************************************/
#include "intKuyruk.hpp"


intKuyruk::intKuyruk()
{
	on = arka = 0;

	uzunluk = 0;
}
intKuyruk::~intKuyruk()
{
	temizle();
}
int intKuyruk::elemanSayisi()const
{
	return uzunluk;
}
bool intKuyruk::bosMu()const
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
void intKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}
int intKuyruk::ilkElemaniGetir() const
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
int intKuyruk::getir(int say)
{
	intKuyrukDugum* temp = on;
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

void intKuyruk::kuyrukEkle(const int veri)
{
	intKuyrukDugum* son = new intKuyrukDugum(veri);
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

void intKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		intKuyrukDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}
