﻿// Lab2_2sem_Laskina.cpp: определяет точку входа для консольного приложения.
/*Данные о файле представлены структурой с полями: каталог, имя файла, расширение, дата и время создания, 
атрибуты(только на чтение, скрытый, системный), признак удаления, количество выделенных секторов(размер сектора фиксирован константой).
Поиск по каталогу, названию, дате, признаку удаления.

1. Предусмотреть операции добавления, изменения и удаления элемента контейнера.
2. Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл.
3. Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям.
Реализовать поиск в двух вариантах : линейный поиск и двоичный поиск на отсортированном контейнере.
4. Предусмотреть вывод подмножества выборки на экран и в файл.*/
#include "stdafx.h"
#include "file.h"


int main()
{
	vector<file> vect;
	setlocale(LC_ALL, "Russian");
	char choise;
	do {
		cout << "Меню:\n1.Добавить.\n2.Напечатать\n3.Удалить\n4.Заменить\n5.Поиск\n6.Загрузить из файла\n0.Выход.\n";
		cin >> choise;
		switch (choise) {
		case '1':
			try {
				add_record(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case '2':
			export_vector(vect);
			break;
		case '3':
			try {
				delete_v(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case '4':
			try {
				exchange_v(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case '5':
			export_vector(search(vect));
			break;
		case '6':
			load_file(vect);
			break;
		default:
			if (choise != '0') cout << "\nНеверный ввод, введите число от 0 до 9\n";
		}
	} while (choise != '0');
	return 0;
}

