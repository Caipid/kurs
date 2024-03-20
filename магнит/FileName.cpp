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
	cout << "Введите количество продуктов:";
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
		cout << "Продукт:" << i + 1 << endl;
		cout << "Наименование продукта" << endl;
		cin >> base[i].name;
		cout << "Количество видов продукта" << endl;
		cin >> base[i].count_vid;
		int current = base[i].count_vid;
		for (int i = 0; i < current; i++) {
			vidi* vid_locale = new vidi[current];
			cout << "Наименование вида товара:";
			cin >> vid_locale[i].name;
			cout << "Введите срок храения(до какого года):";
			cin >> vid_locale[i].data;

		}
	}
	int srok;
	cout << "Введите срок годности(год):";
	cin >> srok;
	for (int i = 0; i < count_p; i++) {
		int current = base[i].count_vid;
		for (int i = 0; i < current; i++) {
			vidi* vid = new vidi[current];
			if (vid[i].data < srok) {
				cout << "истек";

			}
		}

	}
}