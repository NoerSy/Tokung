#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//Deklarasi
	char Barang[100][100]; 
	int Harga[3][100];
	int Jumlah[100];
	int rekod;
	int s=0;
	
//Variabel Waktu
   time_t rawtime;
   struct tm * timeinfo;
   
/*
Harga[0] = Harga asli barang
Harga[1] = Harga mark-up
Harga[2] = Harga Jual

Jumlah[0] = Jumlah barang

rekod = Jumlah jenis barang yang tersimpan
*/	


	void stok();
		void StokBaru();
		void EditStok();
		void HapusStok();
	void Penjualan();
		void Log(int in, char nam[100][100], int jum[100], int Laba);
		void LogL();
		void MaxMin();
		void GrafT();
	void Statistik();
	void save();
	void load();

int main(){
	char p;
	s=0;
	load();
	system("cls");
	puts(" \n\t\t\t\t  [Tokung]\n\n");
	puts(" \t\t\t============================");
	puts(" \t\t\t|                          |");
	puts(" \t\t\t|     [1] Manajemen Stok   |"); 
	puts(" \t\t\t|     [2] Menjual          |");
	puts(" \t\t\t|     [3] Statistik        |");
	puts(" \t\t\t|                          |");
	puts(" \t\t\t|     [0] Keluar           |");
	puts(" \t\t\t|                          |");
	puts(" \t\t\t============================\n");
	printf("               Pilih : "); fflush(stdin); 
	p=getchar(); 

	switch(p){
		case '1':
			system("cls");
			stok();
			break;
		case '2':
			system("cls");
			Penjualan();
		    break;
		case '3':
			system("cls");
			Statistik();
		    break;
		case '0':
			system("cls");
			save();
			exit(EXIT_SUCCESS);
		    break;
		default:
			system("cls");
			puts("\n\n\nInput salah.");
			system("pause");
			system("cls");
			main();
			break;
	}
	exit(EXIT_FAILURE);
	return 0;
}

void stok(){
	int i=0;
	char p;

	system("cls");
	printf("\n");
	puts(" \t\t      ========== [Stok] =========");
	puts(" \t\t                                ");
	for (i=0; Barang[i][0] != '\0'; i++){
		if(Jumlah[i] <= 0)
			continue;
        printf(" \t\t        [%s] x%d\n", Barang[i], Jumlah[i]);
	}
	puts(" \t\t                                ");
	puts(" \t\t      ===========================");
	printf("\n");
	puts(" \t\t\t    [Manajemen Stok]\n");
	puts(" \t\t\t=======================");
	puts(" \t\t\t|                     |");
	puts(" \t\t\t|    [1] Stok Baru    |");
	puts(" \t\t\t|    [2] Edit Stok    |"); 
	puts(" \t\t\t|    [3] Hapus        |");
	puts(" \t\t\t|    [4] Tampilkan    |");
	puts(" \t\t\t|                     |"); 
	puts(" \t\t\t|    [0] Exit         |");
	puts(" \t\t\t|                     |");
	puts(" \t\t\t=======================");
	fflush(stdin);
	printf("               Pilih : "); p=getchar(); 
	
	switch(p){
	case '1':
		StokBaru();
		break;
	case '2':
		system("cls");	
		EditStok();
		break;
	case '3':
		system("cls");
		puts("\n");
		HapusStok();
		break;
	case '4':
		system("cls");
			for (i=0; Barang[i][0] != '\0'; i++){
			printf("\n [%s][%d]\n ==============\n   Jumlah : %d\n   Harga Barang  : Rp %d\n   Harga Mark-Up : Rp %d\n   Harga Jual    : Rp %d\n", Barang[i], i, Jumlah[i], Harga[0][i], Harga[1][i], Harga[2][i]);
		}
		puts("\n");
		system("pause");
		system("cls");
		stok();
		break;
	case '0':
		system("cls");
		save();
		main();
		break;
	default:
			system("cls");
			puts("\n\n\nInput salah.");
			system("pause");
			system("cls");
			stok();
			break;
	}
}

void Penjualan(){
	int i=0, j=0, h=0;
	char p;
	char NamaBarang[100], temp3[100][100];
	int JumlahBarang, temp=0, temp2[100], laba = 0, temp5[50];

	R:
		system("cls");
	P:
	puts("\n\n\t\t [Pejualan Barang] ");
	for (i = 0; 1; i++){
		fflush(stdin);
		printf("\n\t      -------------------------");
		printf("\n\t      |*Input 0 untuk kembali.|");
		printf("\n\t      -------------------------");
		printf("\n\n\t      Nama Barang : ");  
		gets(NamaBarang); 
		
		if(NamaBarang[0] == '0')
			main();
		
			for(j=0; 1; j++){
				if (!strcmp(Barang[j], NamaBarang)){
		   	   	   	printf("\n\t      -------------------------");
					printf("\n\n\t      Jumlah Barang : "); scanf("%d", &JumlahBarang);
					if(JumlahBarang == 0)
						goto R;
					
					Jumlah[j] -= JumlahBarang;
						if(Jumlah[j] - JumlahBarang <= 0){
							puts("\n Stok tidak cukup\n");
							printf(" Stok Yang Kurang : %d\n", (Jumlah[j] - JumlahBarang + 1)*(-1));
							getch();
							goto P;
						}
					temp += Harga[2][j]*JumlahBarang;
					laba += Harga[1][j]*JumlahBarang;
					temp2[i] = JumlahBarang ;
					strcpy(temp3[i], NamaBarang);
					//printf("%d %s", temp2[i], temp3[i]);
					temp5[i] = Harga[2][j];
					j=0;
					break;
				}else if(j==100){
					puts("\n Barang tidak ada.");
					system("pause");
					system("cls");
					Penjualan();
				}
			}
			
			fflush(stdin);
			printf("\n 'Enter' untuk barang lain; 'y' Selesai "); p = getchar(); 
			if( p == 'y' || p == 'Y'){
			        break;
			}
		h++;
	}
	
	
	printf("\n ");
	system("cls");
		
	int n=0, l=0;
	int Bil[50];
	int BilS[50];
	char lineB[100][100];
	
			for(j=0; temp5[j] != 0; j++){
				for(i=0; 1; i++){
					if(!strcmp(temp3[i], temp3[j])){
						Bil[i] += temp2[j];
						BilS[i] += temp5[j];
						strcpy(lineB[i], temp3[j]);
						break;
					}else if(i == 50){
						Bil[n] = temp2[j];
						BilS[n] = temp5[j];
						strcpy(lineB[n], temp3[j]);
						n++;
						break;
					}
				}
			}
			
	printf("\n No.    Harga   ||    Nama    ||  Jumalah  ");
	for(j = 0; j < 50; j++){
		if(lineB[j][0] != '\0'){
			printf("\n %d.    Rp %d       %s       %dx ", j+1, BilS[j], lineB[j], Bil[j]);
			l++;
		}else if(n == 1){
			break;
		}
	}
		puts("\n ===================");
		printf("  [Rp %d]   Total \n\n", temp);
	
	 Log(temp, lineB, Bil, laba);
		
system("pause");
system("cls");
save();
main();
}

void Statistik(){
	//int maks = 0, max, mins=0, min;
	system("cls");		

	MaxMin();
	
	LogL();
	
	GrafT();
	load();
	printf("\n\n\n");
	system("pause");
	system("cls");
	main();
}

void Hari(char lineTime[3][50][50], int Bil[100]){
	int j, n=0;
	char line[3][50][50];
	int BilF[100];
	puts("\t\t  =====[Laba Penjualan Per Hari]==== ");
	for(j=1; j < 50; j++){
		//printf("\t\t  |[%s %s %s] ", lineTime[0][j], lineTime[1][j], lineTime[2][j]);
		//printf(">Rp %d \n", Bil[j]);
		if(lineTime[0][j][0]!= '\0'){
			strcpy(line[0][n], lineTime[0][j]);
			strcpy(line[1][n], lineTime[1][j]);
			strcpy(line[2][n], lineTime[2][j]);
			BilF[n] = Bil[j];
			n++;
		}
	}
	for(j=0; line[0][j][0] != '\0'; j++){
		printf("\t\t  |[%s %s %s] ", line[0][j], line[1][j], line[2][j]);
		printf(">Rp %d \n", BilF[j]);
	}	
}

void Bulan(char lineTime[2][50][50], int Bil[100]){
	int j;
	puts("\n\t\t  =====[Laba Penjualan Per Bulan]==== ");
	for(j=1; lineTime[0][j][0] !='\0'; j++){
		printf("\t\t  |[%s %s] ", lineTime[0][j], lineTime[1][j]);

		/*for(i=0; i < Bil[j]/500; i++){
			printf("*");
		}*/
		printf(">Rp %d \n", Bil[j]);
		
		if(lineTime[0][j+1][0] == '\0'){
			j++;
			continue;
		}
	}
}

void Tahun(char lineTime[50][50], int Bil[100]){
	int j;
	puts("\n\t\t  =====[Laba Penjualan Per Tahun]==== ");
	for(j=1; lineTime[j][0] !='\0'; j++){
		printf("\t\t  |[%s] ", lineTime[j]);
		/*
		for(i=0; i < Bil[j]/1000; i++){
			printf("*");
		}*/
		printf(">Rp %d \n", Bil[j]);
		
		if(lineTime[j+1][0] == '\0'){
			j++;
			continue;
		}
	}
}

void GrafT(){
	char line[100];
	char line2[100][100]; //Hari
	
	char line4[100][100]; //Bulan
	char line5[100][100]; //Tahun
	
	char lineH[3][50][50];
	char lineB[2][50][50];
	char lineT[50][50];
	
	int LabaR[100];
	
	int Bil[50];//Hari
	int Bil2[50];//Bulan
	int Bil3[50];//Tahun
	
	int i=0, j=0, h=1, s=1, r=0, n=0;
	FILE* in = fopen("data/Penjualan.txt", "r");

	while(fgets(line, sizeof(line), in)){
		if(line[0] == '#'){
			strncpy(line2[h], line+9, 2); 
			line2[h][3] = '\0';	
			
			strncpy(line4[h], line+5, 3); 
			line4[h][4] = '\0';	

			strncpy(line5[h], line+21, 4); 
			line5[h][5] = '\0';				
			
			for(j=0; 1; j++){
				if(!strcmp(line2[j], line2[h])){
					s = h;
				}else if(line2[j][0] != '\0'){
					if(s==h){
						s = r+1;
						break;
					}else if(h == 0){
						break;
					}else{
						s++;
						r=s;
						break;
					}
				}
			}
			
			h++;
		}
		for(i=0; 1; i++){
			if(line[i] == '#' && line[i-1] == '2'){
				for(j=0; line[j] != '\0'; j++){
					line[j] = line[j+10];
				}
				LabaR[s] += atoi(line);
			}else if(line[i] == '\n'){
				break;
			}
		}
	}
	fclose(in);	

	for(j=1; LabaR[j] != 0; j++){ //Hari
		for(i=1; 1; i++){
			if(!strcmp(line2[j], line2[i])){
				strcpy(lineH[0][i], line2[j]);
				strcpy(lineH[1][i], line4[j]);
				strcpy(lineH[2][i], line5[j]);
				Bil[i] += LabaR[j];
				
				break;
			}else if(i == 50){
				strcpy(lineH[0][n], line2[j]);
				strcpy(lineH[1][n], line4[j]);
				strcpy(lineH[2][n], line5[j]);
				Bil[n] = LabaR[j];
				n++;
				break;
			}
		}
	}
	
	for(j=1; LabaR[j] != 0; j++){ //Bulan
		for(i=1; 1; i++){
			if(!strcmp(line4[j], line4[i])){
				strcpy(lineB[0][i], line4[j]);
				strcpy(lineB[1][i], line5[j]);
				Bil2[i] += LabaR[j];
				break;
			}else if(i == 50){
				strcpy(lineB[0][n], line4[j]);
				strcpy(lineB[1][n], line5[j]);
				Bil2[n] = LabaR[j];
				n++;
				break;
			}
		}
	}
	
	for(j=1; LabaR[j] != 0; j++){ //Tahun
		for(i=1; 1; i++){
			if(!strcmp(line5[j], line5[i])){
				strcpy(lineT[i], line5[j]);
				Bil3[i] += LabaR[j];
				break;
			}else if(i == 50){
				strcpy(lineT[n], line5[j]);
				Bil3[n] = LabaR[j];
				n++;
				break;
			}
		}
	}
	
	Hari(lineH,Bil);
	Bulan(lineB, Bil2);
	Tahun(lineT,Bil2);


}      	

void MaxMin(){
	char line[100];
	char line2[100][100];
	char line3[100][100];
	
	char lineB[100][100];
	int Bil[100];
	int Bil2[100];
	
	int i=0, j=0, n=0, s = 0, r=0, f = 0, k, max, min, maks=0, mins=0;
	FILE* in = fopen("data/Penjualan.txt", "r");
	
	while(fgets(line, sizeof(line), in)){
		if(line[1] == '+'){
			for(j=0; line[j] != '\n'; j++){ //Menghitung Panjangn String
				if(line[j+1] == '*')
					s = 1;
				if(j>=2 && s == 0){
	   			 	 n++;
				}
				if(line[j-1] == '*'){
					k = j;
					r=1;
				}
				if(r == 1){
					f++;
				}
			}
			strncpy(line2[i], line+2, n); //Mengcopy string ke line2(Menampung dan duplikat)
			line2[i][n] = '\0'; // Menambah akhir untuk sring.
			//puts(line2[i]);
			
			strncpy(lineB[i], line+k, f); 
			lineB[i][f] = '\0'; 
			//puts(lineB[i]);
			Bil[i] = atoi(lineB[i]);
			
			s=0;
			f=0;
			r=0;
			n=0;
			i++;
		}
	}
	
	n=0;
	for(j=0; line2[j][0] != '\0'; j++){
		for(i=0; 1; i++){
			if(strcmp(line2[j], line3[i]) == 0){
				strcpy(line3[i], line2[j]);
				//puts(line3[i]);
				Bil2[i] += Bil[j];
				break;
			}else if(i == 50){
				strcpy(line3[n], line2[j]);
				//puts(line3[n]);
				Bil2[n] = Bil[j];
				n++;
				break;
			}
		}
		
	}
	fclose(in);
	
	for(j=0; j < 50; j++){
		if(line3[j][0] != '\0'){
			if(maks < Bil2[j]){
				maks = Bil2[j];
				max = j;
			}
		}
	}
	mins = maks;
	for(j=0; j < 50; j++){
		if(line3[j][0] != '\0'){
			if(Bil2[j] < mins){
				mins = Bil2[j];
				min = j;
				//printf("%d\n", Bil2[j]);
			}
		}
	}
		//printf("%d\n", min);
	printf("\n\t\t  === [Grafik Banyak Penjualan] === \n\n");
	for(j=0; j<50; j++){
		if(line3[j][0] != '\0'){	
			printf("\t\t  |");
			for(i=0; i < Bil2[j]; i++){
				printf("*");
			}
			printf(">%s \n", line3[j]);
		}
	}
	
	puts("\n\t\t  =======[Paling Banyak]============== ");
	printf("\t\t  | (%s) Terjual : %d Barang  ", line3[max], maks);

	puts("\n\n\t\t  =======[Paling Dikit]=============== ");
	printf("\t\t  | (%s) Terjual : %d Barang  ", line3[min], mins);	

}

void Log(int Total, char nam[100][100], int jum[100], int Laba){
	int j=0, n=0;
	char line[100][100];
	int Bil[100];
	
   time ( &rawtime );
   timeinfo = localtime ( &rawtime );	
	
	char fname[20] = "data/Penjualan.txt";	
	FILE* out;
	
			for(j=0; j < 100; j++){
					if(jum[j] != 0){
						strcpy(line[n], nam[j]);
						Bil[n] = jum[j];
						n++;
					}
			}
			//strcat(line[i+1], "\0");
			
 	  	        out = fopen (fname, "a") ;
			  
				fprintf(out, "#%s", asctime(timeinfo));	 
				fprintf(out, "---------------------\n");	
				for(j=0; j < 10; j++){
					if(line[j][0] != '\0'){
						fprintf(out, " +%s *%d\n", line[j], Bil[j]);
					}else if(n == 1){
						break;
					}
				}
				fprintf(out, "====================\n");
				fprintf(out, "Total : 1#%d\n", Total);
				fprintf(out, "Laba  : 2#%d\n", Laba);		

				fclose(out);
}

void LogL(){
	char line[50];	
	int n, i, j, t = 0, l =0, s, r=0;
	FILE* in;
	
	in = fopen("data/Penjualan.txt", "r");
	
	while(fgets(line, sizeof(line), in)){
		for(i=0; line[i] != '\0'; i++){
			if(line[i] == '#' && line[i-1] == '1'){
				for(j=0; line[j] != '\0'; j++){
					line[j] = line[j+10];
				}
				n = atoi(line);
				t += n;
				r++;
			}else if(line[i] == '#' && line[i-1] == '2'){
				for(j=0; line[j] != '\0'; j++){
					line[j] = line[j+10];
				}
				s = atoi(line);
				l += s;
			}else if(line[i] == '\n'){
				break;
			}
		}
	}
	puts("\n\n\t\t  =======[Total]====================== ");
	printf("\t\t  | Total Transaksi   : %dx   \n", r);
	printf("\t\t  | Total Penjualan   : Rp %d \n", t);
	printf("\t\t  | Total Laba Bersih : Rp %d \n\n", l);
	
}

void save(){

	int i, n=0;
	char fname[20] = "data/";
	char fname1[20];
	char fname2[20] = "data/";
	FILE *out;  
	
	for(i=0; Barang[i][0] != '\0'; i++){
		n++;
	}
	
	for(i = 0; i < n; i++){ //Nama
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Barang_");
			strcat(fname, fname1);
			strcat(fname, ".txt");
			
		out = fopen (fname, "w"); 
		
		fprintf(out, "%s", Barang[i]);
		
		//Mengati kembali ke awal
			strcpy(fname, fname2);
			
		fclose(out);
		}
		
	for(i = 0; i < n; i++){ //Jumlah
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Jumlah_");
			strcat(fname, fname1);
			strcat(fname, ".bin");
			
		out = fopen (fname, "wb"); 
		
		fwrite(&Jumlah[i], sizeof (Jumlah[i]), 2, out);
				
		//Mengati kembali ke awal
			strcpy(fname, fname2);
			
		fclose(out);
		}

	for(i = 0; i < n; i++){ //Harga
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Harga_");
			strcat(fname, fname1);
			strcat(fname, ".bin");
			
		out = fopen (fname, "wb"); 
		
		fwrite(&Harga[0][i], sizeof(int), 3, out);
		fwrite(&Harga[1][i], sizeof(int), 3, out);		
		fwrite(&Harga[2][i], sizeof(int), 3, out);
				
		//Mengati kembali ke awal
			strcpy(fname, fname2);
			
		fclose(out);
	}
		
	FILE *Record = fopen("data/record.bin", "wb");
		fwrite(&s, sizeof(int), 1,Record);
		fwrite(&rekod, sizeof(int), 1,Record); 
		fclose(Record);
}

void load(){

	int i=0, n=0;
	char fname[20] = "data/";
	char fname1[20];
	char fname2[20] = "data/";
	
	FILE *Record = fopen("data/record.bin", "rb");
		fread(&s, sizeof(int), 2,Record);
		fread(&rekod, sizeof(int), 2,Record); 
	 fclose(Record);

	 n = s;
	 	 	
	FILE *in;  	
	for(i = 0; i < n; i++){ // Nama
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Barang_");
			strcat(fname, fname1);
			strcat(fname, ".txt");
		in = fopen (fname, "r"); 
			
			fgets(Barang[i], 100, in);
		
		//Mengati kembali ke awal
			strcpy(fname, fname2);
		fclose(in);
		}	
	
	for(i = 0; i < n; i++){ //Jumlah
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Jumlah_");
			strcat(fname, fname1);
			strcat(fname, ".bin");
			
		    in = fopen (fname, "r"); 
			
			fread(&Jumlah[i],sizeof(int),2,in);	
		
		//Mengati kembali ke awal
  	        strcpy(fname, fname2);
		fclose(in);
		}	
		
	for(i = 0; i < n; i++){ //Harga
		//Nama dinamic file
			sprintf(fname1, "%d", i);
			strcat(fname, "Harga_");
			strcat(fname, fname1);
			strcat(fname, ".bin");
			
		    in = fopen (fname, "r"); 
			
			fread(&Harga[0][i],sizeof(int), 3,in);
			fread(&Harga[1][i],sizeof(int), 3,in);
			fread(&Harga[2][i],sizeof(int), 3,in);
					
		//Mengati kembali ke awal
  	        strcpy(fname, fname2);
		fclose(in);
		}
}

void StokBaru(){
	int i=0,j;
	char NamaBarang[100];
	int HargaBarang=0, JumlahBarang=0, HargaMarkUp=0;
		system("cls");
		puts("\n\t\t  [Stok Baru] \n");
		for(i=0; 1; i++){
			if(Barang[i][0]=='\0'){ 	   fflush(stdin);
				printf("\t ------------------------\n");
				printf("\t |*input 0 untuk kembali|\n");
				printf("\t ------------------------\n\n");
				printf("\t ------------------\n");
				printf("\t Nama Barang :  "); gets(NamaBarang);
			
			if(NamaBarang[0] == '0')
				stok();
			
				for(j=0; 1; j++){
					if(strcmp(Barang[j], NamaBarang) == 0){
						puts("\t Barang sudah ada. \n\n\t");
						getch();
						StokBaru();
					}else if(j==100){
						break;
					}
				 }
				 s += 1;
				
				 fflush(stdin);
				x:
				 puts("\n\t  *Harga asli produk.");
  	  	  	     printf("\t -------------------\n");
				 printf("\t Harga Barang : Rp "); scanf("%d", &HargaBarang); 
				if(HargaBarang > 0){
				 }else if(HargaBarang == 0){
					StokBaru();
				 }else{
				 	 puts("\n\t Tolong masukan input.\n"); 
				 	goto x;
				 }
				 
				u:
				puts("\n\t  *Keuntngan yang ingin diambil");
				printf("\t ---------------------\n");
				printf("\t Harga Mark-Up : Rp "); scanf("%d", &HargaMarkUp); 
				if(HargaMarkUp > 0){
				 }else if(HargaMarkUp == 0){
					 goto x;
				 }else{
				 	 puts("\n\t Tolong masukan input.\n"); 
				 	 goto u;
				 }

				y:
  	  	  	     printf("\t -------------------\n");
				 printf("\t Jumlah Barang : "); scanf("%d", &JumlahBarang); 
				if(JumlahBarang > 0){
				 }else if(JumlahBarang == 0){
					 goto u;
				 }else{
				 	 puts("\n\t Tolong masukan input.\n"); 
				 	 goto y;
				 }

				strcpy(Barang[i], NamaBarang);
				Harga[0][i] = HargaBarang;
				Harga[1][i] = HargaMarkUp;
				Harga[2][i] = HargaMarkUp + HargaBarang;
				Jumlah[i] = JumlahBarang;
				
				puts("\n\t  Produk Berhasil Ditambahkan. \n\n");
				system("pause");
				system("cls"); 
				stok(); 
			}
		}
}

void EditStok(){
	int i=0, d=0, costd;
	char p;
	int HargaBarang=0, JumlahBarang=0;
	
		printf("\n\t\t -----------------------\n");
			for (i=0; Barang[i][0] != '\0'; i++){
          	  printf("\t\t    %d. [%s]\n", i+1, Barang[i]);
          	 
		}
		printf("\t\t -----------------------\n");
		
		puts("\n\t\t       [Edit Stok] \n\n");
        puts("\t\t-------------------------");
		puts("\t\t|*input 0 untuk kembali.|");
        puts("\t\t-------------------------\n");
		printf("\t    Pilih : "); fscanf(stdin,"%d", &d);
		system("cls");
		
		if(d == 0)
			stok();
		
		d--;
		costd = d;
			if(Barang[d][0] == '\0'){
					system("cls");
					puts("\n Barang Tidak ada.");
					getch();
					system("cls");
					EditStok();	
			}
		
			while(1){     
			d = costd;  
			//printf("%d %d\n", Jumlah[d], d);                                                                                                                                                
			printf("\n\t   %s              \n", Barang[d]); 
			printf("\t ====================\n");
			printf("\t Jumlah       :  %d  \n", Jumlah[d]);
			printf("\t Harga Asli   : Rp %d\n", Harga[0][d]);
			printf("\t Harga Mak-Up : Rp %d\n", Harga[1][d]);
			printf("\t Harga Jual   : Rp %d\n", Harga[2][d]);
			fflush(stdin);
			puts("\n [1] Tambah\n [2] Kurang\n [3] Ganti Harga Barang\n [4] Ganti Harga Mark-Up\n\n [0] Kembali");
				printf(" Pilih : "); scanf("%s", &p); 
				//printf("%d %d\n", Jumlah[d], d);
				switch(p){
				case '1':
					d = costd; 
					printf("\n Jumlah ditambah : ");
					scanf("%d", &JumlahBarang); 
					Jumlah[d] += JumlahBarang;
					//printf("%d %d\n", Jumlah[d], d); 
					system("cls");
					//goto Edit;
					break;
				case '2':
					d = costd; 
					printf("\n Jumlah dikurangi : ");
					scanf("%d", &JumlahBarang); 
					Jumlah[d] -= JumlahBarang;
					system("cls");
					//goto Edit;
					break;
				case '3':
					d = costd;
					printf("\n Harga Barang Baru : Rp ");
					scanf("%d", &HargaBarang);
					Harga[0][d] = HargaBarang;
					Harga[2][d] = Harga[0][d] + Harga[d][i];
					system("cls");
					//goto Edit;
					break;
				case '4':
					d = costd; 
					printf("\n Harga Mark-Up Baru : Rp ");
					scanf("%d", &HargaBarang); 
					Harga[1][d] = HargaBarang;
					Harga[2][d] = Harga[0][d] + Harga[1][d];
					system("cls");
					//goto Edit;
					break;
				default:
					system("cls");
					EditStok();
					break;
				}
			}
}

void HapusStok(){
	fflush(stdin);
	int i=0, Pilih;
	char p, kosong[1];
	 
	 kosong[0] = '\0';
	
	puts(" \t\t      ========== [Stok] =========");
	puts(" \t\t                                ");
	for (i=0; Barang[i][0] != '\0'; i++){
        printf("\t\t            %d. [%s]\n", i+1, Barang[i]);
		}
	puts(" \t\t                                ");
	puts(" \t\t      ===========================");	
	
		printf("\n  [Hapus Stok] \n\n *input 0 untuk kembali. \n\n Pilih : ");
		scanf("%d", &Pilih); 
		system("cls");
		
		if(Pilih == 0)
			stok();
		
		i = Pilih - 1;
		
			if(Harga[i] == '\0'){
					system("cls");
					puts(" Barang Tidak ada.");
					getch();
					system("cls");
					EditStok();	
			}
				fflush(stdin);
				printf("\n  [ %s]\n ==============\n  Jumlah : %d\n  Harga Jual : Rp %d\n\n", Barang[i], Jumlah[i], Harga[2][i]);
				printf("  Hapus? y/n : "); p = getchar(); 
				s --;
				if(p=='y' || p=='Y'){
					strcpy(Barang[i], kosong);
					Harga[0][i] = 0;
					Harga[1][i] = 0;
					Harga[2][i] = 0;
					Jumlah[i] = 0;

					i = 0;
					while(1){
							if(Barang[i+1][0] == '\0' && Barang[i+2][0] == '\0'){
								break;
							}
						    if(Barang[i][0] == '\0'){
 							   strcpy(Barang[i], Barang[i+1]);
 							   Jumlah[i] = Jumlah[i+1];
 							   Harga[0][i] = Harga[0][i+1];
 							   Harga[1][i] = Harga[1][i+1];
 							   Harga[2][i] = Harga[2][i+1];
			 					
			 					i++;
								 		   
						       strcpy(Barang[i], kosong);
							   Harga[0][i] = 0;
							   Harga[1][i] = 0;
							   Harga[2][i] = 0;
							   Jumlah[i] = 0;
						   }else{
							   i++;
						   }
					}					   
					system("cls");
					HapusStok();
		}
		fflush(stdin);
}
