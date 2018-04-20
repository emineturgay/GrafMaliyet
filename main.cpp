#include <allegro.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<map>
#include<limits.h>
#include<stdio.h>
#include<set>
#include<math.h>
using namespace std;

struct matris
{
	int x;
	int y;
     int adi;

	int uzaklik;
};

struct kenar
{
	int d1;
	int d2;

	int uzaklik;
};

void Baslat();
void Bitir();

int kenar_karsilastir(const void *K1, const void *K2);
void kruskal(struct kenar kenarlar[], int KENAR_SAY, int DUGUM_SAY, struct kenar * sonuc_ekya_kenarlar[]);
struct matris *dugum;
struct kenar kenarlar[190];
int maliyet=0;



int main()
{
	  int i,j,sayi=0;

	int deger=0;

		int kac_tane;


	cout<<"KAC GIRIS YAPACAKSINIZ : "<<endl;


			do
			{
				cin>>kac_tane;
				if(kac_tane>400)
				{
					cout<<"hatali giris tekrar deneyin : "<<endl;
				}



			}while(kac_tane>400);



 int kenar_sayisi=(kac_tane*(kac_tane-1))/2;



	dugum =( struct matris *)malloc(sizeof(struct matris) * kac_tane);





	for (int i = 0; i < kac_tane; i++)
	{
		(dugum + i)->adi =  i;
		cin >> (dugum + i)->x;

		cin >> (dugum + i)->y;

		if(((dugum+i)->x)>20 || (dugum+i)->y>20)
		{
		//	cout<<"20'den Buyuk Deger Giremezsiniz : "<<endl;

	while( ((dugum+i)->x>20 )|| ( (dugum+i)->y>20 ))
	{            cout<<"20'den Buyuk Deger Giremezsiniz : "<<endl;
				cin>>(dugum+i)->x;
				cin>>(dugum+i)->y;
			}
		}






			for(int k=0; k<=i-1; k++)
		{
			if(((dugum+k)->x==(dugum+i)->x) &&((dugum+k)->y==(dugum+i)->y))
			{
				cout<<"Girmis Oldugunuz Deger Mevcut Lutfen Tekrardan (x,y) Veri Girin"<<endl;
			cin >> (dugum + i)->x;

		cin >> (dugum + i)->y;

			}
		}

	}
	cout << endl << "--------------" << endl;

	for (int i = 0; i < kac_tane; i++)

	{
		printf("%c : %d-%d\n", 'A'+(dugum + i)->adi, (dugum + i)->x, (dugum + i)->y);




	}
	int fark=0;
	int sayac = 0;
	for (i = 0; i < kac_tane; i++)
	{
		for (int j = i + 1; j < kac_tane; j++)
		{
			fark=fabs((dugum + j)->x - (dugum + i)->x)+fabs((dugum + j)->y - (dugum + i)->y);

			kenarlar[sayac] = { (dugum + i)->adi, (dugum + j)->adi, fark };
			sayac++;

		}
	}
	cout << "----KOMSULUK MATRISI------" << endl;
	for (i = 0; i < kenar_sayisi; i++)
	{
		printf("%c-%c : %d\n", 'A'+kenarlar[i].d1,'A'+kenarlar[i].d2 , kenarlar[i].uzaklik);
	}


	struct kenar * ekya_kenarlar[kenar_sayisi];



Baslat();

	clear_to_color(screen,makecol(0,0,0));



	while(!key[KEY_ESC])
	{



        for(i=0;i<21;i++)
        {
        	for(j=0;j<21;j++)
        	{

        	rect(screen,35+j*25,35+i*25,60+j*25,60+i*25,makecol(255,255,255));

        	}



        }



        for(i=0; i<21; i++)
        {
        	textprintf_ex(screen,font,40+(i*25),50,makecol(255,255,255),-1,"%d",i);


        }

         for(i=1; i<21; i++)
        {
        	textprintf_ex(screen,font,40,(i*25)+50,makecol(255,255,255),-1,"%d",i);


        }


	 for(i=0; i<kac_tane; i++)
        {
        	textprintf_ex(screen,font,45+(25*(dugum+i)->x),45+(25*(dugum+i)->y),makecol(255,0,0),-1,"%c",'A'+(dugum+i)->adi);


        }




	kruskal(kenarlar, kenar_sayisi, kac_tane, ekya_kenarlar);

       	rest(100000);


	}


	Bitir();
	system("pause");
	return 0;

}
END_OF_MAIN()


void kruskal(struct kenar kenarlar[], int KENAR_SAY, int DUGUM_SAY, struct kenar * sonuc_ekya_kenarlar[])
{
	int ekya_kenarsay = 0;

 //kenarlari kucukten buyuge doru siralaa
	qsort(kenarlar, KENAR_SAY, sizeof(kenar), kenar_karsilastir);
	//ekrana yaz
	cout << "siralanmis kenarlar : " << endl;

	for (int i = 0; i < KENAR_SAY; i++)
	{
		printf("%c-%c : %d\n", 'A'+kenarlar[i].d1, 'A'+kenarlar[i].d2, kenarlar[i].uzaklik);
	}

	printf("\n");




	int * dugum_renkleri = (int*)malloc(DUGUM_SAY * sizeof(int));
	for (int i = 0; i <DUGUM_SAY; i++) {
		dugum_renkleri[i] = i;
	}


	for (int i = 0; i < KENAR_SAY; i++) {

		int cevrim_yok = 1;

		int d1 = kenarlar[i].d1;
		int d2 = kenarlar[i].d2;


		if (dugum_renkleri[d1] == dugum_renkleri[d2]) {
			// iki dugum ayni renkteyse cevrim olmustur
			cevrim_yok = 0;
			printf("eklenmedi. cevrim var: %c - %c\n",  'A'+d1, 'A'+d2);
		}

		if (cevrim_yok) {
			// su anda incelenen (i. indexteki) kenari ekle
			sonuc_ekya_kenarlar[ekya_kenarsay] = &kenarlar[i];




			ekya_kenarsay++;
			printf("kenar eklendi: %c - %c\n", 'A' + d1, 'A' + d2);
			maliyet+=kenarlar[i].uzaklik;



	line(screen, 37+((dugum+d2)->x*(26)),49+((dugum+d1)->y*(26)),  37+((dugum+d2)->x*26), 49+((dugum+d2)->y*(26)),makecol(255,0,0));
  line(screen, 37+((dugum+d1)->x*26), 49+((dugum+d1)->y*26), 37+((dugum+d2)->x*26),49+((dugum+d1)->y*26), makecol(255,0,0));



			int d1_renk = dugum_renkleri[d1];
			int d2_renk = dugum_renkleri[d2];
			for (int j = 0; j < DUGUM_SAY; j++) {
				if (dugum_renkleri[j] == d2_renk) {
					dugum_renkleri[j] = d1_renk;
				}
			}
		}

	}

	free(dugum_renkleri);



textprintf_ex(screen, font, 80,570, makecol(255,0,0),-1,"TOPLAM MALIYET : %d",maliyet);




}



int kenar_karsilastir(const void *K1, const void *K2)

{
	kenar *k1 = (kenar*)K1;
	kenar *k2 = (kenar*)K2;



	return (k1->uzaklik-k2->uzaklik);
}







void Baslat()
{
	int depth,res;
	allegro_init();
	depth=desktop_color_depth();
	if(depth==0)
	depth=32;
	set_color_depth(depth);

	res=set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

if(res !=0)
{
	allegro_message(allegro_error);
	exit(-1);


}
	install_timer();
	install_keyboard();
	install_mouse();
}


void Bitir()
{
	clear_keybuf();

}







