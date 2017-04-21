
/*===============================================================================================================================
	Program		: HartaKarun.c
    Deskripsi	: Permainan Mencari Harta Karun
	Nama		: Eki Fauzi Firdaus & Muhammad Ganjar Imanudin
	Versi		: 1.1.0
    Compiler	: MinGW GCC
===============================================================================================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

main ()
{
  	typedef struct{
    int x;
    int y;}Point;
    Point tebak,ct;
    int harta[26][26],baris,kolom,baris_isi,kolom_isi,baris_ct,kolom_ct,baris_map,kolom_map,mapx,mapy;
    int kesempatan,hadiah,isi,level,n,m,Q;
    char map[26][26],Kondisi='Y';

    //USER INTERFACE
	while(Kondisi=='Y' || Kondisi=='y')
    {
    m=0;
    hadiah=1000;
    printf("===============================================================================\n");
	printf("|                                                                             |\n");
	printf("|                      Selamat Datang Di Game Harta Karun!!!^-^               |\n");
	printf("|                                  Creator :                                  |\n");
  	printf("|                           1. Eki Fauzi Firdaus                              |\n");
  	printf("|                           2. Muhammmad Ganjar Imanudin                      |\n");
  	printf("|                                                                             |\n");
  	printf("|                           Politeknik Negeri Bandung                         |\n");
	printf("===============================================================================\n");
	printf("\n");
	printf("Peraturan Game:\n");
	printf("1.Anda harus menginput dua angka yang menunjuk koordinat harta karun\n");
	printf("2.Angka yang diinput tidak boleh melebihi maksmum ukuran kotak\n");
	printf("\n");
	//User pilih level
	printf("Silakan pilih Level:\n");
	printf("1. Easy (5x5 Kotak)\n");
	printf("2. Medium (10x10 Kotak)\n");
	printf("3. Hard (15x15 Kotak)\n");
	printf("4. 1xjBRET (5x5 Kotak namun kesempatan menebak hanya satu kali)\n");
	printf("5. Custom (Ukuran kotak tergantung User, namun maksimum ukuran kotak 20x20)\n");

	//User pilih level
	printf("Pilihan: ");
	scanf("%d",&level);
	system("cls");

    printf("Peraturan Game:\n");
	printf("1.Anda harus menginput dua angka yang menunjuk koordinat harta karun\n");
	printf("2.Angka yang diinput tidak boleh melebihi maksmum ukuran kotak\n");
	printf("\n");

	switch(level)
	{
    case 1:n=5;Q=10;break;
    case 2:n=10;Q=10;break;
    case 3:n=15;Q=10;break;
    case 4:n=5;Q=1;break;
    case 5:printf("Masukkan N ukuran kotak: ");scanf("%d",&n);Q=10;printf("\n");break;
	}

	//inisialisasi semua map harta dengan nilai nol (False, tidak ada harta karun)
    for (baris=0;baris<n;baris++)
    {
        for (kolom=0;kolom<n;kolom++)
        {
            harta[baris][kolom]=0;
        }
    }

    //isi salahsatu koordinat dengan nilai satu (True, terdapat nilai harta karun)
    srand(time(NULL));
	baris_isi = rand()%n;
	kolom_isi = rand()%n;
    harta[baris_isi][kolom_isi]=1;

    //catat koordinat hartakarun
    for (baris_ct=0;baris_ct<n;baris_ct++)
    {
        for (kolom_ct=0;kolom_ct<n;kolom_ct++)
        {
            if (harta[baris_ct][kolom_ct]==1)
            {
                ct.x=kolom_ct;
                ct.y=baris_ct;

                break;
            }
        }
    }
    //printf("Jawabannya: %d %d\n",ct.x,ct.y);

    //Inisialisasi map yang akan dilihat user
    printf("               Legend:\n");
    printf("BL---U----TL |BL=Barat Laut; U=Utara;   TL=Timur laut\n");
    printf("B----X----T  |B=Barat;       X=Harta;   T=Timur\n");
    printf("BD---S----TG |BD=Barat Daya; S=Selatan; TG=Tenggara\n");
    printf("\n");
    for (baris_map=0;baris_map<n;baris_map++)
    {
        for (kolom_map=0;kolom_map<n;kolom_map++)
        {
            map[baris_map][kolom_map]=176;
            printf("%c ",map[baris_map][kolom_map]);
            if (kolom_map+1==n)
            {
                printf(" %d",kolom_map-baris_map);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        printf("\n");
        if (baris_map+1==n)
        {
            for (isi=0;isi<n;isi++)
            {
                printf ("%d ",isi);
                if(m<n && m<10)
                {
                	printf(" ");
                	m++;
                }
            }
            printf("\n");
        }
    }

  	kesempatan=1;

    //user menebak harta karun
	while (kesempatan<=Q)
	{
      		printf("Masukkan input X: ");
            scanf("%d",&tebak.x);
      		printf("Masukkan Input Y: ");
            scanf("%d",&tebak.y);
            system("cls");

	printf("Peraturan Game:\n");
	printf("1.Anda harus menginput dua angka yang menunjuk koordinat harta karun\n");
	printf("2.Angka yang diinput tidak boleh melebihi maksmum ukuran kotak\n");
	printf("\n");

            //Jika tepat
            if(tebak.x==ct.x && tebak.y==ct.y)
            {
                map[n-(tebak.y+1)][tebak.x]='X';
                printf("               Legend:\n");
                printf("BL---U----TL |BL=Barat Laut; U=Utara;   TL=Timur laut\n");
                printf("B----X----T  |B=Barat;       X=Harta;   T=Timur\n");
                printf("BD---S----TG |BD=Barat Daya; S=Selatan; TG=Tenggara\n");
                printf("\n");
                for (mapy=0;mapy<n;mapy++)
                {
                    for (mapx=0;mapx<n;mapx++)
                    {
                        printf("%c ",map[mapy][mapx]);
                        if (mapx+1==n)
                        {
                            printf(" %d",mapx-mapy);
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                    printf("\n");
                    m=0;
                    if (mapy+1==n)
                    {
                        for (isi=0;isi<n;isi++)
                        {
                            printf ("%d ",isi);
                            if(m<n && m<10)
                			{
                				printf(" ");
                				m++;
                			}
                        }
                        printf("\n");
                    }
                }
                printf("Selamat Anda mendapat Harta Karun Sebanyak %d gold!!\n",hadiah);
                printf("Jangan lupa berbagi rezekimu kepada yang membutuhkan :)\n");
                kesempatan+=10;
                printf("Mau Mencoba lagi(Y/T)? : ");
        		scanf("%s",&Kondisi);
        		system("cls");
            }
            //Jika Salah
            else
            {
                map[n-(tebak.y+1)][tebak.x]=219;
                m=0;
                printf("               Legend:\n");
                printf("BL---U----TL |BL=Barat Laut; U=Utara;   TL=Timur laut\n");
                printf("B----X----T  |B=Barat;       X=Harta;   T=Timur\n");
                printf("BD---S----TG |BD=Barat Daya; S=Selatan; TG=Tenggara\n");
                printf("\n");
                for (mapy=0;mapy<n;mapy++)
                {
                    for (mapx=0;mapx<n;mapx++)
                    {
                        printf("%c ",map[mapy][mapx]);
                        if (mapx+1==n)
                        {
                            printf(" %d",mapx-mapy);
                        }
                        else
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                    printf("\n");
                    if (mapy+1==n)
                    {
                        for (isi=0;isi<n;isi++)
                        {
                            printf ("%d ",isi);
                            if(m<n && m<10)
                			{
                			printf(" ");
                			m++;
                			}
                        }
                        printf("\n");
                    }
                }
                if (kesempatan<Q)
                {
                    //CEK UTARA,TIMUR, SELATAN, BARAT
                    if(tebak.x>ct.x && tebak.y==ct.y)
                    {
                        if (tebak.x-1==ct.x||tebak.x-2==ct.x)
                        {
                            printf("Anda sudah dekat namun terlalu ke Timur :(\n");
                        }
                        else
                        {
                            printf("Anda terlalu ke Timur :(\n");
                        }
                    }
                    else if(tebak.x<ct.x && tebak.y==ct.y)
                    {
                        if (tebak.x+1==ct.x||tebak.x+2==ct.x)
                        {
                            printf("Anda sudah dekat namun terlalu ke Barat :(\n");
                        }
                        else
                        {
                            printf("Anda terlalu ke Barat :(\n");
                        }
                    }
                    else if(tebak.x==ct.x && tebak.y>ct.y)
                    {
                        if (tebak.y-1==ct.y||tebak.y-2==ct.y)
                        {
                            printf("Anda sudah dekat namun terlalu ke Utara :(\n");
                        }
                        else
                        {
                            printf("Anda terlalu ke Utara :(\n");
                        }
                    }
                    else if(tebak.x==ct.x && tebak.y<ct.y)
                    {
                        if (tebak.y+1==ct.y||tebak.y+2==ct.y)
                        {
                            printf("Anda sudah dekat namun terlalu ke Selatan :(\n");
                        }
                        else
                        {
                            printf("Anda terlalu ke Selatan :(\n");
                        }
                    }
                    //CEK TIMUR LAUT,TENGGGARA,BARAT DAYA,BARAT LAUT
                    else if ((tebak.x-1==ct.x && tebak.y-1==ct.y)||((tebak.x-2==ct.x && tebak.y-2==ct.y)))
                    {
                        printf("Anda sudah dekat namun terlau ke Timur Laut :(\n");
                    }
                    else if ((tebak.x-1==ct.x && tebak.y+1==ct.y)||((tebak.x-2==ct.x && tebak.y+2==ct.y)))
                    {
                        printf("Anda sudah dekat namun terlau ke Tenggara :(\n");
                    }
                    else if ((tebak.x+1==ct.x && tebak.y+1==ct.y)||((tebak.x+2==ct.x && tebak.y+2==ct.y)))
                    {
                        printf("Anda sudah dekat namun terlau ke Barat Daya :(\n");
                    }
                    else if ((tebak.x+1==ct.x && tebak.y-1==ct.y)||((tebak.x+2==ct.x && tebak.y-2==ct.y)))
                    {
                        printf("Anda sudah dekat namun terlau ke Barat Laut :(\n");
                    }
                    else
                    {
                        printf("Anda terlalu jauh dari Harta Karun :(\n");
                    }
                    printf("Kesempatan anda tersisa %d kali lagi\n",(Q-kesempatan));
                }
                else
                {
                    printf("Maaf kesempatan anda habis T^T\n");
                    printf("Jawabannya: X=%d dan Y=%d\n",ct.x,ct.y);
                    printf("Mau Mencoba lagi(Y/T)? : ");
        			scanf("%s",&Kondisi);
        			system("cls");
                }
            hadiah=hadiah-(1000*10/100);
            if (hadiah<0)
            {
                hadiah=0;
            }
            kesempatan+=1;
            }
        }
	}
	if(Kondisi=='T' || Kondisi=='t')
	{
		printf("===============================================================================\n");
		printf("|                                                                             |\n");
		printf("|                      	        Terima Kasih ^_^/                             |\n");
		printf("|                                  Creator :                                  |\n");
  		printf("|                           1. Eki Fauzi Firdaus                              |\n");
  		printf("|                           2. Muhammmad Ganjar Imanudin                      |\n");
  		printf("|                                                                             |\n");
  		printf("|                           Politeknik Negeri Bandung                         |\n");
		printf("===============================================================================\n");
		getch();
	}
    return 0;
}

