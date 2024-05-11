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

void Diskout_visual_file(ofstream& fout, product base_product, int i) {
	fout << "Продукт:";
	fout << i + 1 << endl;
	fout << "Название продукта:";
	fout << base_product.name << endl;
	fout << "Количество видов:";
	fout << base_product.count_vid << endl;
}
void Diskout1_visual_file(ofstream& fout, vidi** base_vidov, int i, int j) {
	fout << "Кодовый номер товара";
	fout << "(Инвентарный номер товара,Номер вида товара):";
	fout << "N";
	fout << i + 1;
	fout << j + 1 << endl;
	fout << "Название товара: ";
	fout << base_vidov[i][j].name << endl;
	fout << "Срок годности товара: ";
	fout << base_vidov[i][j].data << endl;
}
void Diskout_work_file(ofstream& fout, vidi** base_vidov, int i, int j) {
	fout << i + 1 << j + 1 << endl;
	fout << base_vidov[i][j].name << endl;
	fout << base_vidov[i][j].data << endl;
}
void Diskout1_work_file(ofstream& fout, product base_product, int i){
	fout << i + 1 << endl;
	fout << base_product.name << endl;
	fout << base_product.count_vid << endl;
}

static product Diskin(ifstream& fin, product* base_product, int i){
	int kodenumber;
	fin >> kodenumber;
	fin >> base_product[i].name;
	fin >> base_product[i].count_vid;
	return base_product[i];
}
static vidi Diskin2(ifstream& fin, vidi** base_vidov, int i, int j) {
	int kodenumber;
	fin >> kodenumber;
	fin >> base_vidov[i][j].name;
	fin >> base_vidov[i][j].data;
	return base_vidov[i][j];
}

void takebase(product* base_product, vidi** base_vidov, int count_p) {
	for (int i = 0; i < count_p; i++)
		base_vidov[i] = new vidi[7];
	for (int i = 0; i < count_p; i++) {
		cout << "Продукт:" << i + 1 << endl;
		cout << "Наименование продукта" << endl;
		cin >> base_product[i].name;
		cout << "Количество видов продукта" << endl;
		cin >> base_product[i].count_vid;
		int current = base_product[i].count_vid;
		for (int j = 0; j < current; j++) {
			vidi* vid_locale = new vidi[current];
			cout << "Наименование вида товара:";
			cin >> vid_locale[j].name;
			cout << "Введите срок храения(до какого года):";
			cin >> vid_locale[j].data;
			base_vidov[i][j] = vid_locale[j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	int products;
	cout << "Введите количество продуктов:";
	cin >> products;
	int count_p = products;
	product* base_product = new product[count_p];
	vidi** base_vidov = new vidi* [count_p];
	ofstream base("Base.txt");
	ofstream base_work("Bas.txt");
	int key = -1;
	cout << "         Cправочная информация:" << endl;
	cout << "Ключ - 0: Завершение программы" << endl;
	cout << "Ключ - 1: Заполнение базы данных срока хранения товаров" << endl;
	cout << "Ключ - 2: Вывод товаров срок хранения которых истекает в заданном году" << endl;
	cout << "Ключ - 3: Запись значений в файл" << endl;
	cout << "Ключ - 4: Получение значений из файла" << endl;
	cout << "Ключ - 5: Изменение значений товара" << endl;
	cout << "Ключ - 6: Вывод базы данных товаров" << endl;
	cout << "Ключ - 7: Удаление записей продуктов" << endl;
	while (key != 0) {
		cout << "Введите новый кодовый ключ:";
		cin >> key;
		switch (key) 
		{
		case 1:{
			takebase(base_product, base_vidov, count_p);
			break;
		}
		case 2: {
			int srok;
			cout << "Введите срок годности(год):";
			cin >> srok;
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
					if (base_vidov[i][j].data == srok) {
						cout << base_product[i].name << " " << base_vidov[i][j].name;
						cout << " Кодовый номер " << i + 1 << j + 1;
						cout << " - истекает в " << srok << " году." << endl;
					}
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				Diskout_visual_file(base, base_product[i],i);
				Diskout1_work_file(base_work, base_product[i], i);
				for (int j = 0; j < current; j++) {
					Diskout1_visual_file(base, base_vidov, i, j);
					Diskout_work_file(base_work, base_vidov, i, j);
					cout << base_product[i].name << base_vidov[i][j].name << "Срок хранения: " << base_vidov[i][j].data << " - Записан в файл";
				}
			}
			cout << "Значения записаны в файл" << endl;
			base.close();
			break;
		}
		case 4: {
			/*product* base_product = new product[count_p];
			vidi** base_vidov = new vidi * [count_p];*/
			ifstream Bas("Bas.txt");
			cout << "Полученные значения из файла:" << endl;
			for (int i = 0; i < count_p; i++) {
				base_vidov[i] = new vidi[7];
			}
			for (int i = 0; i < count_p; i++) {
				base_product[i] = Diskin(Bas, base_product, i);
				int current = base_product[i].count_vid;
				cout << base_product[i].name << endl;
				cout << "Видов: " << base_product[i].count_vid << endl;
				for (int j = 0; j < current; j++) {
					base_vidov[i][j] = Diskin2(Bas, base_vidov, i, j);
					cout << "N " << i + 1 << j + 1 << " ";
					cout << base_vidov[i][j].name << " ";
					cout << base_vidov[i][j].data << endl;
						}
				}
			Bas.close();
			break;
		}

		case 5: {
			int kodenumber;
			int key_number;
			string change_string;
			int change_int;
			cout << "Введите кодовый номер элемента который хотите изменить:";
			cin >> kodenumber;
			int i = (kodenumber / 10) - 1;
			int j = (kodenumber % 10) - 1;
			cout << "Какую информацию вы хотите изменить?" << endl;
			cout << "Введите 1 - если хотите изменить имя товара" << endl;
			cout << "Введите 2 - если хотите изменить имя вида товара" << endl;
			cout << "Введите 3 - если хотите изменить срок хранения" << endl;
			cin >> key_number;
			while (key_number != 0) {
				switch (key_number) {
					case 1: {
						cout << "Введите новое имя товара:";
						getline(cin,change_string);
						base_product[i].name = change_string;
						key_number = 0;
						break;
					}
					case 2: {
						cout << "Введите новое имя вида товара:";
						getline(cin, change_string);
						base_vidov[i][j].name = change_string;
						key_number = 0;
						break;
					}
					case 3: {
						cout << "Введите новый срок хранения товара:";
						cin >> change_int;
						base_vidov[i][j].data = change_int;
						key_number = 0;
						break;
					}
					default:
						cout << "Неправильный кодовый ключ!" << endl;
						cout << "Введите кодовый ключ еще раз:";
						cin >> key_number;
						break;
				}
			}
			break;
		}
		case 6: {
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
					cout << base_product[i].name << " " << base_vidov[i][j].name;
					cout << " Кодовый номер " << i + 1 << j + 1 << " ";
					cout << "Срок хранения " << base_vidov[i][j].data << endl;
				}
			}
			break;
		}


		case 7: {
			cout << "Удаление выполняется:" << endl;
			for (int i = 0; i < count_p; i++) {
				int current = base_product[i].count_vid;
				for (int j = 0; j < current; j++) {
					cout << base_product[i].name << " " << base_vidov[i][j].name;
					cout << " Кодовый номер " << i + 1 << j + 1;
					cout << " - удален" << endl;
					base_vidov[i][j].data = 0;
					base_vidov[i][j].name = "";
				}
				//delete[] base_vidov[i]
				base_product[i].count_vid = 0;
				base_product[i].name = "";
			}
			//delete[] base_product;
			//delete[] base_vidov;
			cout << "Удаление завершено" << endl;
			break;
		}

		case 0: {
			cout << "                                   Спасибо, что воспользовались нашей програмой." << endl;
			cout << "                                   Хорошего вам дня!" << endl;
			cout << "                                                         Автор программы: Уланов Максим Валерьевич ";
			break;
		}
		default:
			cout << "Неправильный кодовый ключ!";
			cout << "Введите кодовый ключ еще раз:";
			cin >> key;
			break;
		}
	}

}
