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

int dosya::satirSayisi()
	{
		ifstream fileread;
		fileread.open("veriler.txt", ios::in);
		while (!fileread.eof())
		{
			getline(fileread, okunan);
			satirSayac++;
		}
		fileread.close();
		return satirSayac;
		
	}

int dosya::satirElemanSayisi(int sira)
	{

		ifstream fileread;
		fileread.open("veriler.txt", ios::in);
		while (!fileread.eof())
		{

			do
			{
				satirElemanSayac = 0;
				getline(fileread, okunan);
				istringstream ss(okunan);
				while (ss >> str)
				{
					while ((pos = str.rfind(" ")) != string::npos)
					{
						str.erase(pos, 1);
					}
					sayi = stoi(str);
					satirElemanSayac++;
				}

				satirSayac1++;

			} while (!(sira == satirSayac1));

			fileread.close();
			satirSayac1 = 0;
			return satirElemanSayac;
		}

	}

int dosya::tekElemanGetir(int satir, int sayacc)
	{

		ifstream fileread;
		fileread.open("veriler.txt", ios::in);
		int fonkSatirKontrol = 1;
		while (getline(fileread, okunan))
		{

			istringstream ss(okunan);
		
			int listEkleSayac = 1;
			int listSatirKontrolSayac = 1;
			if (satir == fonkSatirKontrol)
			{
				int sira = 0;
				sira = this->satirElemanSayisi(satir);
				for (int i = 0; i < sira; i++)
				{
					int deger;
					if (sayacc == listEkleSayac)
					{

						ss >> deger;
						fileread.close();
						return deger;
					}
					else
					{
						ss >> deger;
						listEkleSayac++;
					}

				
				}
			}
			else
			{
				int sira = 0;
				sira = this->satirElemanSayisi(fonkSatirKontrol);
				for (int i = 0; i < sira; i++)
				{
					int deger;
					ss >> deger;
				}
				fonkSatirKontrol++;
				listSatirKontrolSayac++;
			}



		}

	}