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
** DOSYA ACIKLAMSI........: Her bir elemanı int* tutan kuyruk sinifi
****************************************************************************************************/
#include "intYildizKuyruk.hpp"


intYildizKuyruk::intYildizKuyruk()
{
	on = arka = 0;
	uzunluk = 0;
}
intYildizKuyruk::~intYildizKuyruk()
{
	temizle();
}
int intYildizKuyruk::elemanSayisi()const
{
	return uzunluk;
}
bool intYildizKuyruk::bosMu()const
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
void intYildizKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}

int* intYildizKuyruk::getir(int say)
{
	intYildizDugum* temp = on;
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

void intYildizKuyruk::kuyrukEkle(int* veri)
{
	intYildizDugum* son = new intYildizDugum(veri);
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

void intYildizKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		intYildizDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}
void intYildizKuyruk::yazdir(int say)
{

	for (int i = 0; i < say; i++)
	{
		cout << getir(i) << " ";
	}
}