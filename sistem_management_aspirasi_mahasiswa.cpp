#include <iostream>
#include <string>

using namespace std;

struct Aspirasi
{
	string nama;
	string deskripsi;
};

struct Node
{
	string data;
	Node* next;
	Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

int menu2();
void loginMahasiswa();
void inputAspirasi();
void editAspirasi();
Aspirasi kampus();
Aspirasi kurikulum();
Aspirasi sarpras();
void tambahDepan(const string& data);
void tambahBelakang(const string& data);
void tambahTengah(const string& data, int position);
void hapusDepan();
void hapusTengah(int position);
void hapusBelakang();
void printKampus();
void printKurikulum();
void printSarpras();
void tampilanEdit();
void hapusSemua();
bool isEmpty();
void printAspirasi();

Aspirasi aspirasi;

int main()
{
	
	int data;
	int pilihanMenu;
	
	do{
		
		cout<<"Selamat Datang Di Aplikasi Aspirasi Mahasiswa"<<endl;
		cout<<endl;
		cout<<"1. Login Mahasiswa"<<endl;
		cout<<"2. Keluar Aplikasi"<<endl;
		cout<<endl;
		cout<<"Masukkan Pilihan : ";
		cin>>pilihanMenu;
		cout<<endl;
		
		switch (pilihanMenu) 
		{
			case 1:
				loginMahasiswa();				
				break;
				
			case 2:
				cout<<"Selesai!"<<endl;
				break;
				
			default:
				cout<<"Maaf Pilihan Tidak Sesuai!!"<<endl;
				break;
				
		}
		
		
	}while(pilihanMenu !=3);
	
	
}

int menu2()
{
	int pilihan;
	do{
		
	
	cout<<"--------------------------------------------"<<endl;
	cout<<"Selamatdatang di Aplikasi Aspirasi Mahasiswa"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"1. Masukkan Aspirasi"<<endl;
	cout<<"2. Edit Aaspirasi"<<endl;
	cout<<"3. Tampilkan Aspirasi"<<endl;
	cout<<"4. Keluar"<<endl;
	
		
		cout<<"Masukan pilihan : ";
		cin>>pilihan;
		switch(pilihan){
			case 1:
				inputAspirasi();
				break;
			case 2:
				editAspirasi();
				break;
			case 3:
				printAspirasi();
				break;
			default :
				cout<<"Pilihan Anda tidak Sesuai!, Masukkan Pilihan dengan benar"<<endl;
				
		}
		
	}while(pilihan !=4);
	
	
}

void inputAspirasi()
{
	int pilihan; 
	
	do{
		
	cout<<"--------------------------"<<endl;
	cout<<"Pilih Tujuan Aspirasi Mu!!"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"1. Kampus "<<endl;
	cout<<"2. Kurikulum "<<endl;
	cout<<"3. Sarpras "<<endl;
	cout<<"4. Kembali "<<endl;	
		
		cout<<"Masukan pilihan : ";
		cin>>pilihan;
		switch(pilihan){
			case 1:
				aspirasi = kampus();
				cout<<"aspirasi berhasil di tambahkan "<<endl;
				
				break;
			case 2:
				aspirasi = kurikulum();
				cout<<"aspirasi berhasil di tambahkan "<<endl;
				break;
			case 3:
				aspirasi = sarpras();
				cout<<"aspirasi berhasil di tambahkan "<<endl;
				break;
			case 4:
				menu2();
				break;
			default :
				cout<<"Pilihan Anda tidak Sesuai!, Masukkan Pilihan dengan benar"<<endl;
				
		}
		
	}while(pilihan !=4);
	
}

Aspirasi kampus()
{
	
	Aspirasi aspirasiBaru;
	
	cout<<"Nama : ";
	getline(cin,aspirasiBaru.nama);
	cout<<endl;
	cout<<"deskripsi : ";
	getline(cin,aspirasiBaru.deskripsi);
	
	return aspirasiBaru;
	
}

Aspirasi kurikulum()
{
	Aspirasi aspirasiBaru;
	
	cout<<"Nama : ";
	getline(cin,aspirasiBaru.nama);
	cout<<endl;
	cout<<"deskripsi : ";
	getline(cin,aspirasiBaru.deskripsi);
	
	return aspirasiBaru;
	
}

Aspirasi sarpras()
{
	Aspirasi aspirasiBaru;
	
	cout<<"Nama : ";
	getline(cin,aspirasiBaru.nama);
	cout<<endl;
	cout<<"deskripsi : ";
	getline(cin,aspirasiBaru.deskripsi);
	
	return aspirasiBaru;
	
	
}

void loginMahasiswa()
{
	string username,password;
	
	bek:
	cout<<"Masukkan Nama Kampus : ";
	cin>>username;
	cout<<endl;
	cout<<"Maukkan NIM : ";
	cin>>password;
	
	if(username == "AMIKOM" || username == "amikom" && password == "5178"){
		cout<<"Login sukses "<<endl;
		system("cls");
		menu2();
	}else {
		cout<<"Login gagal, Masukan  username dan password dengan bener !!"<<endl;
		goto bek;
	}
	
}


void editAspirasi()
{
int pilihanMenu;
    string data;
    int position;
    char ulang;
    
    yo:

    do {
        cout << "-------------------------------------" << endl;
        cout << "----Edit dan Tambahkan Aspirasimu----" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Menambahkan Aspirasi dari Depan" << endl;
        cout << "2. Menambahkan Aspirasi dari Belakang" << endl;
        cout << "3. Menyisipkan Aspirasi dari Tengah" << endl;
        cout << "4. Menghapus Aspirasi dari Depan" << endl;
        cout << "5. Menghapus Aspirasi dari Belakang" << endl;
        cout << "6. Menghapus Aspirasi dari Tengah" << endl;
        cout << "7. Menghapus Semua Data Aspirasi" << endl;
        cout << "8. Menampilkan Aspirasi" << endl;
        cout << "9. Kembali ke Menu" << endl;
        cout << "-------------------------------------" << endl;

        cout << "Masukkan pilihan anda: ";
        cin >> pilihanMenu;
        cout << endl;

        switch (pilihanMenu) {
            case 1:
                cout << "Masukkan Aspirasi: ";
                cin.ignore();
                getline(cin, data);
                tambahDepan(data);
                break;

            case 2:
                cout << "Masukkan Aspirasi: ";
                cin.ignore();
                getline(cin, data);
                tambahBelakang(data);
                break;

            case 3:
                cout << "Masukkan Aspirasi: ";
                cin.ignore();
                getline(cin, data);
                cout << "Masukkan Posisi: ";
                cin >> position;
                tambahTengah(data, position);
                break;

            case 4:
                hapusDepan();
                break;

            case 5:
                hapusBelakang();
                break;

            case 6:
                cout << "Masukkan Posisi: ";
                cin >> position;
                hapusTengah(position);
                break;

            case 7:
                hapusSemua();
                break;

            case 8:
                printAspirasi();
                break;

            case 9:
                cout << "Selesai!" << endl;
                break;

            default:
                cout << "Pilihan tidak sesuai!" << endl;
                break;
        }

        cout << endl;
        cout << "Kembali ke menu? (y/n): ";
        cin >> ulang;
        cout << endl;
    } while (ulang == 'y' || ulang == 'Y');

    goto yo;
}

void printKampus()
{
	
}

void printKurikulum()
{
	
}

void printSarpras()
{
	
}

bool isEmpty() {
    return head == NULL;
}

void tambahDepan(const string& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void tambahBelakang(const string& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void tambahTengah(const string& data, int position) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        int count = 1;

        while (count < position && current != NULL) {
            current = current->next;
            count++;
        }

        if (current != NULL) {
            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != NULL) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }

            current->next = newNode;
        } else {
            cout << "Posisi yang dimasukkan melebihi jumlah aspirasi saat ini" << endl;
        }
    }
}

void hapusDepan() {
    if (!isEmpty()) {
        Node* del = head;
        cout << del->data << " telah dihapus dari depan" << endl;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete del;
    } else {
        cout << "Tidak ada data dalam linked list" << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        Node* del = tail;
        cout << del->data << " telah dihapus dari belakang" << endl;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete del;
    } else {
        cout << "Tidak ada data dalam linked list" << endl;
    }
}

void hapusTengah(int position) {
    if (!isEmpty()) {
        if (position == 1) {
            hapusDepan();
        } else {
            Node* current = head;
            int count = 1;

            while (count < position && current != NULL) {
                current = current->next;
                count++;
            }

            if (current != NULL) {
                Node* del = current;
                cout << del->data << " telah dihapus dari tengah" << endl;

                if (current == head) {
                    head = current->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete del;
            } else {
                cout << "Posisi yang dimasukkan melebihi jumlah node saat ini" << endl;
            }
        }
    } else {
        cout << "Tidak ada data dalam linked list" << endl;
    }
}

void hapusSemua() {
    while (head != NULL) {
        Node* del = head;
        head = head->next;
        cout << del->data << " dihapus" << endl;
        delete del;
    }
    tail = NULL;
}

void printAspirasi() {
    if (!isEmpty()) {
        Node* current = head;
        int nodeNumber = 1;
        cout << "Aspirasi:" << endl;
        cout<<endl;

        while (current != NULL) {
            cout << nodeNumber << ". " << current->data << endl;
            current = current->next;
            nodeNumber++;
        }
    } else {
        cout << "Tidak ada data dalam linked list" << endl;
    }
}

