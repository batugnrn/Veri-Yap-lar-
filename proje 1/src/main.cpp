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
#include "dosya.hpp"
#include "satirListe.hpp"
#include "yoneticiListe.hpp"
#include "yoneticiDugum.hpp"
#include "ekran.hpp"
#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	dosya d1;
	int satirSayisi = 0;
	int satirElemanSayisi = 0;
	satirSayisi = d1.satirSayisi() + 1;
	int sayi = 0;
	yoneticiListe* yonetici = new yoneticiListe();





	for (int i = 1; i < satirSayisi; i++)
	{

		satirListe* list = new satirListe();


		satirElemanSayisi = d1.satirElemanSayisi(i);
		for (int j = 0; j < satirElemanSayisi; j++)
		{
			sayi = d1.tekElemanGetir(i, j + 1);
			list->satirListeEkle(sayi);

		}
		double ort1 = 0;
		double ort = 0;
		ort = list->ortalamaHesapla();


		int yoneticiDugumSayisi = 0;
		yoneticiDugumSayisi = yonetici->yoneticiDugumSayGetir();

		int yoneticiDugumSayac = 0;
		if (yoneticiDugumSayisi == 0)
		{
			yonetici->yoneticiEkle(list);
		}
		else
		{
			for (int i = 0; i < yoneticiDugumSayisi; i++)
			{
				ort1 = yonetici->dugumGetir(i)->veri->ortalamaHesapla();
				yoneticiDugumSayac = i;
				if (ort1 > ort)
				{
					yonetici->yoneticiEkle(list, i);
					break;
				}

			}
			if (ort > ort1)
			{
				yonetici->yoneticiEkle(list);
			}
		}
	}











	ekran e;
	int sira = 0;
	while (true)
	{
		system("cls");
		int dugumSayi = 0;
		dugumSayi = yonetici->yoneticiDugumSayGetir();

		e.yoneticiYaz(yonetici, sira);


		e.satirYaz(sira, yonetici);





		char ch;
		cin >> ch;

		if (ch == 'z')
		{
			if (sira == 0)
			{
				cout << "" << endl;
			}
			else
			{
				sira--;
			}
		}
		else if (ch == 'c')
		{
			if (sira + 1 == dugumSayi)
			{
				cout << "" << endl;
			}
			else
			{
				sira++;
			}
		}
		else if (ch == 'a')
		{
			if (sira == 0)
			{
				cout << "" << endl;
			}
			else
			{
				int tur = 0;
				tur = yonetici->yoneticiDugumSayGetir() / 8;
				int bolum = 0;
				bolum = sira / 8;
				for (int i = 0; i < tur + 1; i++)
				{
					if (bolum == i)
					{
						int degisecekSira = 0;
						degisecekSira = 0 + 8 * i;
						if (sira == degisecekSira)
						{
							sira = sira - 8;
						}
						else
						{
							sira = degisecekSira;
						}
					}
				}

			}
		}
		else if (ch == 'd')
		{
			if (sira + 1 == dugumSayi)
			{
				cout << "" << endl;
			}
			else
			{
				int tur = 0;
				tur = yonetici->yoneticiDugumSayGetir() / 8;
				int bolum = 0;
				bolum = sira / 8;
				for (int i = 0; i < tur; i++)
				{
					if (bolum == i)
					{
						int degisecekSira = 0;
						degisecekSira = 0 + 8 * (i + 1);
						sira = degisecekSira;
					}
				}
			}
		}
		else if (ch == 'p')
		{
			yonetici->dugumGetir(sira)->veri->~satirListe();
			yonetici->yoneticiCikar(sira);
			
			sira = 0;
		}
		else if (ch == 'k')     
		{
			system("cls");
			e.yoneticiYaz(yonetici, sira);
			int randomSira = 0;
			if (yonetici->dugumGetir(sira)->veri->satirDugumSayGetir()==1)
			{
				randomSira = 1;
			}
			else
			{
				
				randomSira = rand() % yonetici->dugumGetir(sira)->veri->satirDugumSayGetir();
			}
			
			e.silincekSatirOkuYazdir(sira, yonetici, randomSira);
			while (true)
			{
				char ch1;
				cin >> ch1;
				if (ch1 == 'k')
				{


					yonetici->dugumGetir(sira)->veri->satirListeCikar(randomSira);

					int satirElemanSayisi = 0;
					satirElemanSayisi = yonetici->dugumGetir(sira)->veri->satirDugumSayGetir();

					if (satirElemanSayisi == 0)
					{
						yonetici->yoneticiCikar(sira);
						if (sira != 0)
						{
							sira--;
						}
						
					}
					else
					{
						double yOrt = 0;
						yOrt = yonetici->dugumGetir(sira)->veri->ortalamaHesapla();


						for (int i = 0; i < yonetici->yoneticiDugumSayGetir(); i++)
						{
							if (yonetici->yoneticiOrt(i) > yOrt)
							{
								yoneticiDugum* temp;
								temp = yonetici->dugumGetir(sira);

								yonetici->yoneticiEkle(yonetici->dugumGetir(sira)->veri, i);

								yonetici->yoneticiCikar(yonetici->yoneticiHangiDugum(temp));

								break;
							}

						}
						break;
					}
					

				}
				break;
			}
		}
		else if (ch == 'e')
		{
			exit(1);
		}
	}
}

