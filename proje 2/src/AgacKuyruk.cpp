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
** DOSYA ACIKLAMSI........: Her bir elemaninda agac tutan kuyruk sinifi cpp dosyasi
****************************************************************************************************/
#include "AgacKuyruk.hpp"

AgacKuyruk::AgacKuyruk()
{
	on = arka = 0;

	uzunluk = 0;
}
AgacKuyruk::~AgacKuyruk()
{
	temizle();
}
int AgacKuyruk::elemanSayisi()const
{
	return uzunluk;
}
bool AgacKuyruk::bosMu()const
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
void AgacKuyruk::temizle()
{
	while (!bosMu())
	{
		kuyrukCikar();
	}
}
ikiliAramaAgaci* AgacKuyruk::getir(int say)
{
	agacKuyrukDugum* temp = on;
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

void AgacKuyruk::kuyrukEkle(ikiliAramaAgaci* veri)
{
	agacKuyrukDugum* son = new agacKuyrukDugum(veri);
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

void AgacKuyruk::kuyrukCikar()
{
	if (bosMu())
	{
		throw "kuyruk bos";
	}
	if (on != NULL)
	{
		on->veri->~ikiliAramaAgaci();
		agacKuyrukDugum* tmp = on;
		on = on->sonraki;
		delete tmp;
		if (on == NULL)
		{
			arka = 0;
		}
		uzunluk--;
	}
}