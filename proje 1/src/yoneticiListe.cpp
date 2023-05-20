/*****************************************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** VERİ YAPILARI DERSİ
** 2022-2023 GÜZ DÖNEMİ
**
**
** ÖDEV ..................: 1. ÖDEV
** ÖĞRENCİ ADI............: BAHRİ BATUHAN GÜNEREN
** ÖĞRENCİ NUMARASI.......: G201210059
** DERSİN ALINDIĞI GRUP...: 2.ÖĞRETİM C GRUBU
****************************************************************************************************/
#include "yoneticiListe.hpp"

yoneticiListe::yoneticiListe()
	{
		ilk = 0;
	}

yoneticiListe::~yoneticiListe()
	{
		yoneticiDugum* temp = ilk;
		while (temp != 0)
		{
			yoneticiDugum* silinecek = temp;
			temp = temp->arka;
			delete silinecek;
		}
	}

void yoneticiListe::yoneticiEkle(satirListe* veri)
	{
		yoneticiDugum* yeniDugum = new yoneticiDugum(veri);
		if (ilk == 0)
		{
			ilk = yeniDugum;
		}
		else
		{
			yoneticiDugum* temp = ilk;

			while (temp->arka != 0)
			{
				temp = temp->arka;
			}
			temp->arka = yeniDugum;
			yeniDugum->on = temp;
		}
	}

void yoneticiListe::yoneticiEkle(satirListe* veri, int sira)
	{
		if (ilk == 0 && sira == 0)
		{
			ilk = new yoneticiDugum(veri);
			return;     
		}

		yoneticiDugum* eklenecekDugum = dugumGetir(sira);
		if (eklenecekDugum == 0)  return;

		yoneticiDugum* yeni = new yoneticiDugum(veri);

		yoneticiDugum* on = eklenecekDugum->on;

		eklenecekDugum->on = yeni;
		yeni->arka = eklenecekDugum;
		yeni->on = on;

		if (on)
		{
			on->arka = yeni;
		}
		else
		{
			ilk = yeni;
		}
	}

yoneticiDugum* yoneticiListe::dugumGetir(int sira)
	{
		yoneticiDugum* temp = ilk;
		int sayac = 0;



		while (temp != 0)
		{
			if (sayac == sira)
			{
				return temp;
			}

			temp = temp->arka;
			sayac++;
		}
		return 0;
	}

void yoneticiListe::yoneticiCikar()
	{
		if (ilk == 0) return;
		if (ilk->arka == 0)
		{
			delete ilk;
			ilk = 0;
			return;
		}

		yoneticiDugum* temp = ilk;
		while (temp->arka->arka != 0)
		{
			temp = temp->arka;
		}
		delete temp->arka;
		temp->arka = 0;
	}

void yoneticiListe::yoneticiCikar(int sira)
	{
		yoneticiDugum* sil = dugumGetir(sira);
		if (sil == 0) return;

		yoneticiDugum* on = sil->on;
		yoneticiDugum* arka = sil->arka;
		delete sil;

		if (arka)
		{
			arka->on = on;
		}
		if (on)
		{
			on->arka = arka;
		}
		else
		{
			ilk = arka;
		}
		
	}

int yoneticiListe::yoneticiDugumSayGetir()
	{
		yoneticiDugum* temp = ilk;
		int sayac = 0;

		while (temp != 0)
		{

			temp = temp->arka;
			sayac++;
		}

		return sayac;
	}

int yoneticiListe::yoneticiHangiDugum(yoneticiDugum* dugum)
	{
		yoneticiDugum* temp = ilk;
		int sayac = 0;
		while (temp != 0)
		{
			if (temp == dugum)
			{
				return sayac;
			}
			temp = temp->arka;
			sayac++;
		}
	}

double yoneticiListe::yoneticiOrt(int sira)
	{
		yoneticiDugum* temp;
		temp = dugumGetir(sira);

		double ortalama = 0, d2;

		ortalama = temp->veri->ortalamaHesapla();
		
		return ortalama;
	}

    