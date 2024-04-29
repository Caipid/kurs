#include <iostream>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

class product {
public:
	string name;
	int count_vid;
};

class vidi {
public:
	string name;
	int data;
};

int	products() {
	int products;
	cout << "������� ���������� ���������:";
	cin >> products;
	return products;
}
void Diskout(ofstream& fout, product base_product,int i) {
	fout << "�������:";
	fout << i + 1 << endl;
	fout << "�������� ��������:";
	fout << base_product.name << endl;
	fout << "���������� �����:";
	fout << base_product.count_vid << endl;
}
void Diskout1(ofstream& fout, vidi** base_vidov, int i, int j) {
	fout << "������� ����� ������:" << endl;
	fout << "(����������� ����� ������,����� ���� ������):";
	fout << "N";
	fout << i+1;
	fout << " ";
	fout << j+1 <<  endl;
	fout << "�������� ������:" << endl;
	fout << base_vidov[i][j].name << "  ";
	fout << "���� �������� ������:" << endl;
	fout << base_vidov[i][j].data << endl;
}

void Diskin(ifstream& fin, vidi**& base_vidov, product* base_product, int count_p) {
	string str[1000];
	int g[1000];
	for (int i = 0; i < count_p; i++) {
		fin >> str[0];
		fin >> g[0];
		fin >> str[1];
		fin >> str[2];
		fin >> str[3];
		fin >> g[1];
		int current = base_product[i].count_vid;
		for (int j = 0; j < current; j++) {
			fin >> str[4];
			fin >> str[5];
			fin >> str[6];
			fin >> g[2];
			fin >> str[7];
			fin >> g[3];
			fin >> str[8];
			fin >> base_vidov[i][j].name;
			fin >> str[9];
			fin >> base_vidov[i][j].data;
		}
	}
}

void takebase(product* base_product, vidi** base_vidov, int count_p) {
	for (int i = 0; i < count_p; i++)
		base_vidov[i] = new vidi[7];
	for (int i = 0; i < count_p; i++) {
		cout << "�������:" << i + 1 << endl;
		cout << "������������ ��������" << endl;
		cin >> base_product[i].name;
		cout << "���������� ����� ��������" << endl;
		cin >> base_product[i].count_vid;
		int current = base_product[i].count_vid;
		for (int j = 0; j < current; j++) {
			vidi* vid_locale = new vidi[current];
			cout << "������������ ���� ������:";
			cin >> vid_locale[j].name;
			cout << "������� ���� �������(�� ������ ����):";
			cin >> vid_locale[j].data;
			base_vidov[i][j] = vid_locale[j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	int count_p = products();
	product* base_product = new product[count_p];
	vidi** base_vidov = new vidi* [count_p];
	ofstream base("Base.txt");	
	int key = -1;
	while (key != 0) {
		cout << "������� ����� ������� ����:";
		cin >> key;
		switch (key) 
		{
		case 1:{
			takebase(base_product, base_vidov, count_p);
			break;
		}
		case 2: {
			int srok;
			cout << "������� ���� ��������(���):";
			cin >> srok;
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
					if (base_vidov[i][j].data == srok) {
						cout << base_product[i].name << " " << base_vidov[i][j].name;
						cout << " ������� ����� " << i + 1 << j + 1;
						cout << " - �������� � " << srok << " ����." << endl;
					}
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				Diskout(base, base_product[i],i);
				for (int j = 0; j < current; j++) {
					Diskout1(base, base_vidov, i, j);
				}
			}
			cout << "�������� �������� � ����" << endl;
			base.close();
			break;
		}
		case 4: {
			vidi** base_vidov = new vidi * [count_p];
			ifstream base("Base.txt");
			cout << "���������� �������� �� �����:" << endl;
			for (int i = 0; i < count_p; i++) {
				base_vidov[i] = new vidi[7];
			}
			Diskin(base, base_vidov, base_product, count_p);
			base.close();
			break;
		}
		case 5: {
			cout << "�������� �����������:" << endl;
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
					cout << base_product[i].name << " " << base_vidov[i][j].name;
					cout << " ������� ����� " << i + 1 << j + 1;
					cout << " - ������" << endl;
				}
				delete[] base_vidov[i];
			}
			delete[] base_vidov;
			cout << "�������� ���������" << endl;
			break;
		}
		case 6: {
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
						cout << base_product[i].name << " " << base_vidov[i][j].name;
						cout << " ������� ����� " << i + 1 << j + 1 << endl;
						cout << base_vidov[i][j].data;
				}
			}
			break;
		}
		case 0: {
			cout << "                                   �������, ��� ��������������� ����� ���������." << endl;
			cout << "                                   �������� ��� ���!" << endl;
			cout << "                                                        � NVLCORP ";
			break;
		}
		default:
			cout << "������������ ������� ����";
			break;
		}
	}

}
