#include <iostream>
#include <locale>
#include <string>

using namespace std;

struct product {
	char name[100];
	int count_vid;

};
struct vidi {
	char name[100];
	int data;
};

int	products() {
	int products;
	cout << "������� ���������� ���������:";
	cin >> products;
	if (products < 1) {
		return 1;
	}
	return products;
}


int main() {
	setlocale(LC_ALL, "ru");
	int count_p = products();
	product* base = new product[count_p];
	for (int i = 0; i < count_p; i++) {
		cout << "�������:" << i + 1 << endl;
		cout << "������������ ��������" << endl;
		cin >> base[i].name;
		cout << "���������� ����� ��������" << endl;
		cin >> base[i].count_vid;
		int current = base[i].count_vid;
		for (int i = 0; i < current; i++) {
			vidi* vid_locale = new vidi[current];
			cout << "������������ ���� ������:";
			cin >> vid_locale[i].name;
			cout << "������� ���� �������(�� ������ ����):";
			cin >> vid_locale[i].data;

		}
	}
	int srok;
	cout << "������� ���� ��������(���):";
	cin >> srok;
	for (int i = 0; i < count_p; i++) {
		int current = base[i].count_vid;
		for (int i = 0; i < current; i++) {
			vidi* vid = new vidi[current];
			if (vid[i].data < srok) {
				cout << "�����";

			}
		}

	}
}