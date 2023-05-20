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
** DOSYA ACIKLAMSI........: Ikili arama agaci sinifi
****************************************************************************************************/
#include "ikiliAramaAgaci.hpp"

bool ikiliAramaAgaci::varmi(int aranan, ikiliAramaAgaciDugum* aktif)
{
	if (aktif->veri < aranan)
	{
		if (aktif->sag)
			return varmi(aranan, aktif->sag);
		else
			return false;
	}
	else if (aktif->veri > aranan)
	{
		if (aktif->sol)
			return varmi(aranan, aktif->sol);
		return false;
	}
	else
	{
		return true;
	}
}

ikiliAramaAgaci::ikiliAramaAgaci()
{
	kok = NULL;
}

bool ikiliAramaAgaci::varmi(int veri)
{
	return varmi(veri, kok);
}

void ikiliAramaAgaci::ekle(int eklenecek, intKuyruk* doku)
{
	if (kok == 0)
		kok = new ikiliAramaAgaciDugum(eklenecek, doku);
	else
		ekle(eklenecek, kok, doku);
}

void ikiliAramaAgaci::ekle(int veri, ikiliAramaAgaciDugum* aktifDugum, intKuyruk* doku)
{
	if (aktifDugum->veri > veri)
	{
		if (aktifDugum->sol)
			ekle(veri, aktifDugum->sol, doku);
		else
			aktifDugum->sol = new ikiliAramaAgaciDugum(veri, doku);
	}
	else if (aktifDugum->veri < veri)
	{
		if (aktifDugum->sag)
			ekle(veri, aktifDugum->sag, doku);
		else
			aktifDugum->sag = new ikiliAramaAgaciDugum(veri, doku);
	}
	else
	{
		if (aktifDugum->sol)
			ekle(veri, aktifDugum->sol, doku);
		else
			aktifDugum->sol = new ikiliAramaAgaciDugum(veri, doku);
	}
}

int ikiliAramaAgaci::yukseklik(ikiliAramaAgaciDugum* aktifDugum)
{
	if (aktifDugum)
	{
		aktifDugum->yukseklik = 1 + max(yukseklik(aktifDugum->sol),
			yukseklik(aktifDugum->sag));
		return aktifDugum->yukseklik;
	}
	return -1;
}


intKuyrukYildizKuyruk* ikiliAramaAgaci::postOrder(ikiliAramaAgaciDugum* aktif)
{
	if (aktif)
	{

		postOrder(aktif->sol);
		postOrder(aktif->sag);

		pstordrKuyruk->kuyrukEkle(aktif->doku);

	}
	return pstordrKuyruk;
}


void ikiliAramaAgaci::sil(int aranan, ikiliAramaAgaciDugum*& aktif)
{
	if (aktif == 0)        return;
	if (aktif->veri > aranan)
		sil(aranan, aktif->sol);
	else if (aktif->veri < aranan)
		sil(aranan, aktif->sag);
	else
	{
		if (aktif->sag && aktif->sol)
		{
			aktif->veri = maxDeger(aktif->sol);
			sil(aktif->veri, aktif->sol);
		}
		else
		{
			ikiliAramaAgaciDugum* silinecek = aktif;
			if (aktif->sol == 0)
				aktif = aktif->sag;
			else if (aktif->sag == 0)
				aktif = aktif->sol;
			else
				aktif = 0;
			delete silinecek;
		}
	}
}

int ikiliAramaAgaci::maxDeger(ikiliAramaAgaciDugum* aktif)
{
	if (aktif->sag)
		return maxDeger(aktif->sag);

	return aktif->veri;
}

bool ikiliAramaAgaci::dengeliMi()
{
	int a = 0;
	a = yukseklik(kok->sag) - yukseklik(kok->sol);
	if (a == 0 || a == 1 || a == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ikiliAramaAgaciDugum* ikiliAramaAgaci::dondur()
{
	return kok;
}

void ikiliAramaAgaci::ekle(int eklenecek)
{
	if (kok == 0)
		kok = new ikiliAramaAgaciDugum(eklenecek);
	else
		ekle(eklenecek, kok);
}

void ikiliAramaAgaci::ekle(int veri, ikiliAramaAgaciDugum* aktifDugum)
{
	if (aktifDugum->veri > veri)
	{
		if (aktifDugum->sol)
			ekle(veri, aktifDugum->sol);
		else
			aktifDugum->sol = new ikiliAramaAgaciDugum(veri);
	}
	else if (aktifDugum->veri < veri)
	{
		if (aktifDugum->sag)
			ekle(veri, aktifDugum->sag);
		else
			aktifDugum->sag = new ikiliAramaAgaciDugum(veri);
	}
	else
	{
		if (aktifDugum->sol)
			ekle(veri, aktifDugum->sol);
		else
			aktifDugum->sol = new ikiliAramaAgaciDugum(veri);
	}
}

ikiliAramaAgaci::~ikiliAramaAgaci()
{
	temizle();
}

void ikiliAramaAgaci::temizle()
{
	while (!bosMu())
	{
		dugumSil(kok);
	}
	pstordrKuyruk->~intKuyrukYildizKuyruk();
}

bool ikiliAramaAgaci::bosMu() const
{
	return kok == NULL;
}

bool ikiliAramaAgaci::dugumSil(ikiliAramaAgaciDugum*& dugum)
{
	ikiliAramaAgaciDugum* silinecek = dugum;
	if (dugum->sag == NULL)
	{
		dugum = dugum->sol;
	}
	else if (dugum->sol == NULL)
	{
		dugum = dugum->sag;
	}
	else
	{
		silinecek = dugum->sol;
		ikiliAramaAgaciDugum* ebeveyn = dugum;
		while (silinecek->sag != NULL)
		{
			ebeveyn = silinecek;
			silinecek = silinecek->sag;
		}
		dugum->veri = silinecek->veri;
		dugum->doku = silinecek->doku;
		if (ebeveyn == dugum)
		{
			dugum->sol = silinecek->sol;

		}
		else
		{
			ebeveyn->sag = silinecek->sol;
		}
	}
	delete silinecek;
	return true;
}