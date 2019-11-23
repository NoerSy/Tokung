#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

	char Barang[100][100]={"Teh Pucup","Teh Gelas"}; 
	char Harga[100][100]={"10.000","5.000"};
	int Jumlah[100]={50,100};
	
	void stok();
	

int main(){
	char p;
	
	puts("\n     [Tokung]\n\n [1] Stok Barang\n [2] Penjualan\n [3] Untung Rugi\n [4] Keluar\n");
	printf(" Pilih : ");
	p=getch(); fflush(stdin); 

	switch(p){
		case '1':
			system("cls");
			
			stok();

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
	int BarangTerjual;
	
	printf("\n\n");
	for (i=0; Barang[i][0] != '\0'; i++){
      printf("%d. %s \n   Jumlah : %d\n   Harga  : %s\n====================\n", (i+1), Barang[i], Jumlah[i], Harga[i]);
	}
	printf("\n\n");
	
	system("pause");
	system("cls");
	main();
}

