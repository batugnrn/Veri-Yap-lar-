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
#include "ekran.hpp"

void ekran::cizgiCizdir(int adet)
	{
		for (int i = 0; i < adet; i++)
		{
			cout << "----------  ";
		}
		cout << endl;
	}

void ekran::yoneticiYaz(yoneticiListe* list, int sira)
	{
		int sayac2 = 0;
		int sayac = 8;
		int dugumSayi = 0;
		dugumSayi = list->yoneticiDugumSayGetir();
	
		int b = 0;
		int a = 1;
		int c = 0;
		for (int i = 0; i < sira + 1; i++)
		{
			b = i % 8;
			if (b == 0)
			{
				sayac2++;
			}
		}
		for (int i = 0; i < sayac2; i++)
		{
			a = 1;
			if (sayac2 == 1)
			{
				a = a * i * 8;
			}
			else
			{
				a = a * i * 8;
			}
		}
		c = sayac * sayac2;
		if (c >= dugumSayi)
		{
			if (c == dugumSayi)
			{

				c = dugumSayi;
				cout << "<---" << setw((10 * 8) + (2 * 7) - 4) << "son" << endl;
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->dugumGetir(i) << "  ";
				}
				cout << endl;
				cizgiCizdir(8);
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->dugumGetir(i)->on << "  ";
				}
				cout << endl;
				cizgiCizdir(8);
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->yoneticiOrt(i) << "  ";
				}
				cout << endl;
				cizgiCizdir(8);
				for (int i = a; i < c; i++)
				{
					cout  << setw(10) << list->dugumGetir(i)->arka << "  ";
				}
				cout << endl;
				cizgiCizdir(8);
				cout << endl;
			}
			else
			{
				int d = dugumSayi % 8;
				c = dugumSayi;
				cout << "<---" << setw((10 * d) + (2 * d - 1) - 5) << "son" << endl;
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->dugumGetir(i) << "  ";
				}
				cout << endl;
				cizgiCizdir(d);
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->dugumGetir(i)->on << "  ";
				}
				cout << endl;
				cizgiCizdir(d);
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->yoneticiOrt(i) << "  ";
				}
				cout << endl;
				cizgiCizdir(d);
				for (int i = a; i < c; i++)
				{
					cout << setw(10) << list->dugumGetir(i)->arka <<"  ";
				}
				cout << endl;
				cizgiCizdir(d);
				cout << endl;
			}

		}
		else
		{
			if (a == 0)
			{
				cout << "ilk" << setw((10 * 8) + (2 * 7) - 3) << "--->" << endl;
			}
			else
			{
				cout << "<---" << setw((10 * 8) + (2 * 7) - 4) << "--->" << endl;
			}


			for (int i = a; i < c; i++)
			{
				cout << setw(10) << list->dugumGetir(i) << "  ";
			}
			cout << endl;
			cizgiCizdir(sayac);
			for (int i = a; i < c; i++)
			{

				cout << setw(10) << list->dugumGetir(i)->on <<"  ";
			}
			cout << endl;
			cizgiCizdir(sayac);
			for (int i = a; i < c; i++)
			{

				cout << setw(10) << list->yoneticiOrt(i) << "  ";
				
			}
			cout << endl;
			cizgiCizdir(sayac);
			for (int i = a; i < c; i++)
			{
				cout <<setw(10) << list->dugumGetir(i)->arka << "  ";
			}
			cout << endl;
			cizgiCizdir(sayac);
			cout << endl;
		}


	}

void ekran::satirYaz(int sira, yoneticiListe* list)
	{
		yoneticiDugum* yazilacakDugum;
		yazilacakDugum = list->dugumGetir(sira);
		int dugumSirasi = 0;
		dugumSirasi = list->yoneticiHangiDugum(yazilacakDugum);
		if (sira == dugumSirasi)
		{
			
			list->dugumGetir(dugumSirasi)->veri->satirListeYazdir(sira);
			
		}



	}

void ekran::silincekSatirOkuYazdir(int sira, yoneticiListe* list, int hangisi)
	{
		yoneticiDugum* yazilacakDugum;
		yazilacakDugum = list->dugumGetir(sira);
		int dugumSirasi = 0;
		dugumSirasi = list->yoneticiHangiDugum(yazilacakDugum);
		if (sira == dugumSirasi)
		{
			
			list->dugumGetir(dugumSirasi)->veri->satirListeSilmeYazdir(sira, hangisi);

		}
	}
