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
#include "satirListe.hpp"

satirListe::satirListe()
	{
		ilk = 0;
	}

satirListe::~satirListe()
	{
		satirDugum* temp = ilk;
		while (temp != 0)
		{
			satirDugum* sil = temp;
			temp = temp->arka;
			delete sil;
		}

	}

void satirListe::satirListeCikar()
	{
		if (ilk == 0) return;
		if (ilk->arka == 0)
		{
			delete ilk;
			ilk = 0;
			return;
		}
		satirDugum* temp = ilk;
		while (temp->arka->arka != 0)
		{
			temp = temp->arka;
		}
		delete temp->arka;
		temp->arka = 0;
	}

void satirListe::satirListeCikar(int sira)
	{
		satirDugum* sil = satirDugumGetir(sira);
		if (sil == 0) return;

		satirDugum* on = sil->on;
		satirDugum* arka = sil->arka;
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

satirDugum* satirListe::satirDugumGetir(int sira)
	{
		satirDugum* temp = ilk;
		int sayac = 0;
		if (sira==0)
		{
			return temp;

		}

		while (temp != 0)
		{
			if (sayac+1 == sira)
			{
				return temp;
			}

			temp = temp->arka;
			sayac++;
		}
		return 0;
	}

void satirListe::satirListeEkle(int sayi)
	{
		satirDugum* yeni = new satirDugum(sayi);
		if (ilk == 0)
		{
			ilk = yeni;
		}
		else
		{
			satirDugum* temp = ilk;

			while (temp->arka != 0)
			{
				temp = temp->arka;
			}
			temp->arka = yeni;
			yeni->on = temp;
		}

	}

void satirListe::satirListeYazdir(int sira)
	{
		satirDugum* temp = ilk;
		int a = 0;
		
		a = sira % 8;
		cout << endl;
		cout << setw(12 * a) << "" << "^^^^^^^^^^" << endl;
		while (temp != 0)
		{
						
			cout << setw(12 * a) <<" " << temp << endl;
			cout << setw(12 * a) << "" << "----------" << endl;
			cout << setw(12 * a) << "" << "|" << setw(5) << temp->veri <<setw(4)<< "|" << endl;

			cout << setw(12 * a) << "" << "----------" << endl;
			cout << setw(12 * a) << "" <<"|" << temp->arka <<"|" << endl;
			cout << setw(12 * a) << "" << "----------" << endl;
			cout << endl;
			temp = temp->arka;
		}

	}

void satirListe::satirListeSilmeYazdir(int sira, int hangisi)
	{
		satirDugum* temp = ilk;

		int sayac = 1;
		int a = 0;

		a = sira % 8;
		cout << endl;
		cout << setw(12 * a) << "" << "^^^^^^^^^^" << endl;
		if (hangisi==0)
		{
			sayac = 0;
		}
		
		while (temp != 0)
		{
			
			
			
			cout << setw(12 * a) << " " << temp << " " << endl;
			cout << setw(12 * a) << "" << "----------" << endl;
			cout << setw(12 * a) << "" << "|" << setw(5) << temp->veri << setw(4) << "|";

			if (sayac == hangisi)
			{
				cout << "   <----" << endl;
			}
			else
			{
				cout << endl;
			}
			cout << setw(12 * a) << "" << "----------" << endl;
			cout << setw(12 * a) << "" <<"|" << temp->arka <<"|" << endl;
			cout << setw(12 * a) << "" << "----------" << endl;
			cout << endl;
			temp = temp->arka;
			sayac++;
		}
	}

int satirListe::satirDugumSayGetir()
	{
		satirDugum* temp = ilk;
		int sayac = 0;

		while (temp != 0)
		{
			temp = temp->arka;
			sayac++;
		}

		return sayac;
	}

double satirListe::ortalamaHesapla()
	{
		satirDugum* temp = ilk;
		double toplam = 0;
		double ortalama = 0;
		int satirDugumSayi = 0;
		satirDugumSayi = satirDugumSayGetir();
		while (temp != 0)
		{
			toplam = toplam + temp->veri;
			temp = temp->arka;
		}
		ortalama = toplam / satirDugumSayi;
		return ortalama;
	}