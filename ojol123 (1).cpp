#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct
{
	string nama_depan,nama_belakang,kota,negara,email,pengemudi,no_hp,alasan;
	string no_kendaraan;
	int id;
}data_driver;
data_driver data[100];
	int pil,n,a=0,temp;
	char namafile1[20],namafile2[20],namafile3[20];
	int banyak_n;
	string fdriver;
	int banyak=100;
	int x=0,c,bantu,array[100];
	string cari;
	bool found;
void mergSambung();
void splitting();
void input();
void search();
void seqsearch();
void binary();
void bubbleno();
void transaksi();
void insert();
void shell();
void quic();
void quicPertama(int first, int last);
void merg();
void mergPertama(int kiri, int kanan);
void mergKedua(int kiri, int tengah, int kanan);
void selection();


int main()
{
	do{
	int pil;
	cout<<"\t Pendaftaran Driver OJOL\n";
	cout<<"1.Input Data\n";
	cout<<"2.Searching\n";
	cout<<"3.Transaksi\n";
	cout<<"4.Exit\n";
	cout<<"Pilih :";cin>>pil;
	system ("cls");
	switch (pil)
	{
		case 1:
			input();
			break; 
		case 2:
			search();
			break;
		case 3:
		 transaksi();
			break; 
		case 4:
			return(0);
			break;
		default:
			cout<<"Tidak ada di dalam menu";
	}
	
}while(1);
}
void input()
{		
		cout<<"Nama File 1 :";cin>>namafile1;
		fdriver=namafile1;
		cout<<"Banyak Data :";cin>>n;
		ofstream open;
		ifstream close;
		close.open(fdriver.c_str());
		if (!close.fail())
		{
	 	close >> banyak_n;
		}
		else
		{
	 	banyak_n = 0;
		}
		close.close();
		
		open.open(fdriver.c_str());
		open<< banyak_n + n;
		open.close();
	 
		ofstream buka;
		buka.open(namafile1, ios::app); 
		for(int i=0;i<n;i++){
		cout<<"Nama Depan      :";cin>>data[i].nama_depan;
		cout<<"Nama Belakang   :";cin>>data[i].nama_belakang;
		cout<<"Nomor Handphone :";cin>>data[i].no_hp;
		cout<<"Kota            :";cin>>data[i].kota;
		cout<<"Negara          :";cin>>data[i].negara;
		cout<<"|Motor|\n";
		cout<<"|Mobil|\n";
		cout<<"Jenis Pengemudi :";cin>>data[i].pengemudi;
		cout<<"Alamat Email    :";cin>>data[i].email;
		cout<<"Nomor Kendaraan :";cin>>data[i].no_kendaraan;
		cout<<"Alasan          :";cin.ignore();getline(cin,data[i].alasan);
		a=a+1;
		data[i].id=a;
		buka<<data[i].nama_depan<<endl;
		buka<<data[i].nama_belakang<<endl;
		buka<<data[i].no_hp<<endl;
		buka<<data[i].kota<<endl;
		buka<<data[i].negara<<endl;
		buka<<data[i].pengemudi<<endl;
		buka<<data[i].email<<endl;
		buka<<data[i].no_kendaraan<<endl;
		buka<<data[i].alasan<<endl;
		buka<<data[i].id<<endl;
		
	}
	buka.close();
}


void search()
{
	
	cout<<"\tMenu Searching\n";
	cout<<"1.Sequen\n";	
	cout<<"2.Binary\n";
	cout<<"Pilih :";cin>>pil;
		switch (pil)
		{
			case 1:
		    seqsearch();
				break;
			case 2:
			binary();
			
			default:
				cout<<"Tidak ada di dalam menu";
				
		}
		
	
}
void seqsearch()
{		
			cout<<"Sequen\n";
			cout << "Nama file : ";cin>>namafile1;
			fdriver= namafile1;
			ifstream open;
			open.open(fdriver.c_str());
			open>>n;
			open.close();
			ifstream output;
			output.open(namafile1);
			cout << "\n";
		cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
	
			for (int i=0; i<n; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
	}
	
		found=false;
		cout<<"CARI BERDASARKA NO KENDARAAN = ";cin>>cari;
		for (int i = 0; i < n; i++)
		{ if (data[i].no_kendaraan == cari)
		{
			array[x]=i;
			x=x+1;
			found = true;
		}
		else
		cout<<"";
			
		}
		if (found)
		{
		
		for (int j = 0; j < x; j++)
		{
			c=array[j];
			bantu=c;
		cout<<setw(10)<<"Nama Depan      :"<<data[bantu].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[bantu].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[bantu].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[bantu].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[bantu].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[bantu].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[bantu].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[bantu].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[bantu].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[bantu].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
		}
		
		}
		else
			cout<<"\nNO KENDARAAN MOTOR TERSEBUT TIDAK DITEMUKAN!";
	output.close();
								
			
	        		
}



void binary()
{
				
				
				cout<<"1.BUBBLE SORT\n";
				cout<<"2.STRAIGHT INSERTION SORT\n";
				cout<<"3.SHELL SORT\n";
				cout<<"4.QUICK SORT\n";
				cout<<"5.MERGE SORT\n";
				cout<<"6.SELECTION SORT\n";
				cout<<"Pilih :";cin>>pil;
				switch (pil)
				{
						case 1:
						bubbleno();
						break;
						case 2:
						insert();
						break;
						case 3:
						shell();
						break;
						case 4:
						quic();
						break;
						case 5:
					    merg();
						break;
						case 6:
		
		
						break;
						
				}
	cout<<"CARI BERDASARKA NO KENDARAAN = ";cin>>cari;
	int k;
	int i = 0;
	int j = n-1; 
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == data[k].no_kendaraan)
	        found = true;
	    else
	    {
	        if(cari < data[k].no_kendaraan)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<<endl;
	if (found)
		{
		cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t|							DATA DRIVER 						|\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
		cout<<setw(10)<<"Nama Depan      :"<<data[k].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[k].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[k].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[k].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[k].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[k].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[k].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[k].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[k].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[k].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
		
		}
		else
			cout<<"\nNO KENDARAAN MOTOR TERSEBUT TIDAK DITEMUKAN!";
		
		
}
void bubbleno()
{
	cout << "Bubble Sort\n";
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil) : ";cin>>namafile2;
	fdriver=namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver = namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();

	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
	
			for (int i=0; i<n; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
	}
	
	data_driver temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (data[j].no_kendaraan>data[j+1].no_kendaraan)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
			
		}
		
	}
	for (int i=0; i<n; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl; 
		
		}
		simpan.close();
		output.close();
		cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t|							DATA DRIVER 						|\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
		
		for (int i = 0; i < n; i++)
		{
			
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[i].id;cout<<endl;
		cout<<setw(12)<<"\t===============================================================" <<endl;
	
		}
}
void insert()
{
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil Sort) : ";cin>>namafile2;
	fdriver = namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver =namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();

	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t|							DATA DRIVER 						|\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
		
	for (int i=0; i<n; i++)
	{

		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
		
	}
	
	data_driver temp;
	int j;
	for(int i=1; i<n; i++) {
      temp = data[i];
      j = i - 1;
      while((temp.no_kendaraan < data[j].no_kendaraan) & (j >= 0))
      {
         data[j+1] = data[j];
         j = j - 1;
         data[j+1] = temp;
      }
   }
		for (int i=0; i<n; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl; 
		
		}
		simpan.close();
		output.close();
		cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t|							DATA DRIVER 						|\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
	for (int i=0; i<n; i++)
	{
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
		
	}
		
		
}
void shell()
{
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil) : ";cin>>namafile2;
	fdriver=namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver = namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();

	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
		cout <<setw(12)<<"\n\t===============================================================" <<endl;
		cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
		cout <<setw(12)<<"\t===============================================================" <<endl;
	
			for (int i=0; i<n; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
	}
		data_driver tampung;
		for (int i = n/2; i > 0; i/=2)
		{
			for ( int j = i; j < n; j++)
			{ 
				for ( int k = j-i; k >=0 && data[k].no_kendaraan > data[k+i].no_kendaraan; k-=i)
				{
					tampung=data[k];
					data[k]=data[k+i];
					data[k+i]=tampung;
					
				}
				
			}
			
		}
		for (int i=0; i<n; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl;
		}
		simpan.close();
		output.close();
		
			cout <<setw(12)<<"\n\t===============================================================" <<endl;
			cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
			cout <<setw(12)<<"\t===============================================================" <<endl;
		
		for (int i = 0; i < n; i++)
		{
			
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[i].id;cout<<endl;
		cout<<setw(12)<<"\t===============================================================" <<endl;
	
		}
}
void quic(){
	cout << "\nQuick Sort\n";
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil Sort) : ";cin>>namafile2;
	fdriver = namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver = namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();
	
	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
		
	for (int i=0; i<n; i++)
	{

		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
		
	}
	
	data_driver temp;
	int first = 0;
	int last = n - 1;
	quicPertama(first, last);

		for (int i=0; i<banyak; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl;
		}
		simpan.close();
		output.close();			
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
	for (int i=0; i<n; i++)
	{
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[i].id;cout<<endl;
		cout<<setw(12)<<"\t===============================================================" <<endl;
	
		
	}
}

void quicPertama(int first, int last){
	data_driver temp;
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = data[(first + last) / 2].no_kendaraan;

   	do {
      	while(data[low].no_kendaraan < list_separator)
         	low++;
      	while(data[high].no_kendaraan > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = data[low];
         	data[low++] = data[high];
         	data[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quicPertama(first, high);
   	if(low < last) quicPertama(low, last);
}


void merg(){
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil Sort) : ";cin>>namafile2;
	fdriver = namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver = namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();

	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
	for (int i=0; i<n; i++)
	{

		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
	
	
		
	}
	
	data_driver temp;
	
	mergPertama(0, n-1);

		for (int i=0; i<n; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl;
		}
		simpan.close();
		output.close();

		
		cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
	for (int i=0; i<n; i++)
	{
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[i].id;cout<<endl;
		cout<<setw(12)<<"\t===============================================================" <<endl;
	
	}
}

void mergPertama(int kiri, int kanan){
	if (kiri < kanan) 
    { 
        int tengah = kiri+(kanan-kiri)/2;  
        mergPertama(kiri, tengah); 
        mergPertama(tengah+1, kanan); 
        mergKedua(kiri, tengah, kanan); 
    } 
}

void mergKedua(int kiri, int tengah, int kanan){
	int i, j, k; 
    int n1 = tengah - kiri + 1; 
    int n2 =  kanan - tengah; 
  	
    data_driver KIRI[n1], KANAN[n2]; 
  	
    for (i = 0; i < n1; i++) 
        KIRI[i] = data[kiri + i]; 
    for (j = 0; j < n2; j++) 
        KANAN[j] = data[tengah + 1+ j]; 

    i = 0;
    j = 0;
    k = kiri;
    while (i < n1 && j < n2) 
    { 
        if (KIRI[i].no_kendaraan <= KANAN[j].no_kendaraan) 
        { 
            data[k] = KIRI[i]; 
            i++; 
        } 
        else
        { 
            data[k] = KANAN[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        data[k] = KIRI[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        data[k] = KANAN[j]; 
        j++; 
        k++; 
    }
}
void transaksi()
{
	cout<<"\tTransaksi\n";
	cout<<"1.Splitting\n";
	cout<<"2.Merge Sambung\n";
	cout<<"Pilih :";cin>>pil;
	switch (pil)
	{
		case 1:{
			cout<<"Splitting\n";
			splitting();
			break;}
		case 2:{
			cout<<"Merge Sambung";
			mergSambung();
			break;}
		default:
			cout<<"Tidak ada Di Menu";
	}
	
}
void selection(){
	cout << "Nama file : ";cin>>namafile1;
	cout << "Nama file (Hasil Sort) : ";cin>>namafile2;
	fdriver = namafile1;
	ifstream open;
	open.open(fdriver.c_str());
	open>>n;
	open.close();

	fdriver = namafile2;
	ofstream close;
	close.open(fdriver.c_str());
	close<<n;
	close.close();

	ifstream output;
	output.open(namafile1);
	
	ofstream simpan;
	simpan.open(namafile2);
	
	cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
		
	for (int i=0; i<n; i++)
	{

		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			     :"<<data[i].id;cout<<endl;
		cout <<setw(12)<<"\t===============================================================" <<endl;
	}
	
	data_driver temp;
	
	for(int current=0; current<banyak; current++)  
	{
      for(int j=current+1; j<banyak; j++)  
	{
         if(data[current].no_kendaraan > data[j].no_kendaraan) 
         {
            temp = data[current];
            data[current] = data[j];
            data[j] = temp;
         }
     }
   }
		for (int i=0; i<n; i++)
		{
		simpan<<data[i].nama_depan<<endl;
		simpan<<data[i].nama_belakang<<endl;
		simpan<<data[i].no_hp<<endl;
		simpan<<data[i].kota<<endl;
		simpan<<data[i].negara<<endl;
		simpan<<data[i].pengemudi<<endl;
		simpan<<data[i].email<<endl;
		simpan<<data[i].no_kendaraan<<endl;
		simpan<<data[i].alasan<<endl;
		simpan<<data[i].id<<endl;
		}
		simpan.close();
		output.close();

		
		cout << "\n";
	cout <<setw(12)<<"\n\t===============================================================" <<endl;
	cout <<setw(12)<<"\t| 						DATA DRIVER								 |\n";
	cout <<setw(12)<<"\t===============================================================" <<endl;
		
	for (int i=0; i<n; i++)
	{
		
		cout<<setw(10)<<"Nama Depan      :"<<data[i].nama_depan;cout<<endl;
		cout<<setw(10)<<"Nama Belakang   :"<<data[i].nama_belakang;cout<<endl;
		cout<<setw(10)<<"Nomor Handphone :"<<data[i].no_hp;cout<<endl;
		cout<<setw(10)<<"Kota            :"<<data[i].kota;cout<<endl;
		cout<<setw(10)<<"Negara          :"<<data[i].negara;cout<<endl;
		cout<<setw(10)<<"Jenis Pengemudi :"<<data[i].pengemudi;cout<<endl;
		cout<<setw(10)<<"Alamat Email    :"<<data[i].email;cout<<endl;
		cout<<setw(10)<<"Nomor Kendaraan :"<<data[i].no_kendaraan;cout<<endl;
		cout<<setw(10)<<"Alasan          :"<<data[i].alasan;cout<<endl;
		cout<<setw(10)<<"ID			   :"<<data[i].id;cout<<endl;
		cout<<setw(12)<<"\t===============================================================" <<endl;
		
	}
}
void splitting()
{
	string namafile1,namafile2,namafile3;
	ifstream output;
	ofstream input;
	cout<< "File displiting : "; cin>> namafile1;
	cout<< "File splitting 1: "; cin>> namafile2;
	cout<< "File splitting 2: ";cin>>namafile3;
	fdriver=namafile1;
	output.open(fdriver.c_str());
	output >> n;
	cout << n <<endl;

	//output.open(namafile1.c_str());
	for (int i=0; i<n; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
	}
	output.close();
	
	int satu, dua;
	
	satu = 0;
	dua = 0;

	
	for (int i = 0; i < n; ++i)
	{
		if (data[i].id < 5)
		{
			input.open(namafile2.c_str(), ios::app);
			input<<data[i].nama_depan<<endl;
			input<<data[i].nama_belakang<<endl;
			input<<data[i].no_hp<<endl;
			input<<data[i].kota<<endl;
			input<<data[i].negara<<endl;
			input<<data[i].pengemudi<<endl;
			input<<data[i].email<<endl;
			input<<data[i].no_kendaraan<<endl;
			input<<data[i].alasan<<endl;
			input<<data[i].id<<endl;
			input.close();
			satu++;
		}
		else
		{
			input.open(namafile3.c_str(), ios::app);
			input<<data[i].nama_depan<<endl;
			input<<data[i].nama_belakang<<endl;
			input<<data[i].no_hp<<endl;
			input<<data[i].kota<<endl;
			input<<data[i].negara<<endl;
			input<<data[i].pengemudi<<endl;
			input<<data[i].email<<endl;
			input<<data[i].no_kendaraan<<endl;
			input<<data[i].alasan<<endl;
			input<<data[i].id<<endl;
			input.close();
			dua++;
		}
	}
	fdriver=namafile2;
	input.open(fdriver.c_str(),ios::app);
	input << satu;
	input.close();
	fdriver=namafile3;
	input.open(fdriver.c_str(),ios::app);
	input << dua;
	input.close();
}
void mergSambung(){
	int j = 0;
	string namafile1, namafile2, namafile3;
	ifstream output;
	ofstream input;

	cout<< "File 1 : "; cin>> namafile1;
	cout<< "File 2  : "; cin>> namafile2;
	fdriver = namafile1;
	output.open(fdriver.c_str());
	output >> n;
	output.close();

	output.open(namafile1.c_str());
	for (int i=0; i<n; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		
		j++;
	}
	output.close();

	fdriver = namafile2;
	output.open(fdriver.c_str());
	output >> n;
	output.close();
	
	int batas = j+n;
	output.open(namafile2.c_str());
	for (int i=j; i<batas; i++)
	{
		output>>data[i].nama_depan;
		output>>data[i].nama_belakang;
		output>>data[i].no_hp;
		output>>data[i].kota;
		output>>data[i].negara;
		output>>data[i].pengemudi;
		output>>data[i].email;
		output>>data[i].no_kendaraan;
		output>>data[i].alasan;
		output>>data[i].id;
		j++;
	}
	output.close();

	cout<< "File hasil   : "; cin>> namafile3;
	input.open(namafile3.c_str());
	
	for (int i=0; i<j; i++)
	{
		input<<data[i].nama_depan;
		input<<data[i].nama_belakang;
		input<<data[i].no_hp;
		input<<data[i].kota;
		input<<data[i].negara;
		input<<data[i].pengemudi;
		input<<data[i].email;
		input<<data[i].no_kendaraan;
		input<<data[i].alasan;
		input<<data[i].id;
	}
	input.close();

	fdriver = namafile3;
	input.open(fdriver.c_str(),ios::app);
	input << j;
	input.close();
}



