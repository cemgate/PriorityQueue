#include "List.h"
#include<fstream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

List::List()
{
	first = NULL;
}

void List::add_msg(string name, string content)
{
	message *nowa = new message;
	nowa->name = name;
	nowa->content = content;
	if (first == NULL)
	{
		first = nowa;
	}

	else
	{
		message* temp = first;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = nowa;
			nowa = 0;
	}	
}

List List::flood(Msg n)
{
	List list;
	
        srand(unsigned(time(0)));
		vector<int> arr;

		for (int j = 1; j <= n.n; ++j)

		{
			arr.push_back(j);
		}

		random_shuffle(arr.begin(), arr.end());

	    for (int h=0; h<n.n; h++)
		{
			string tmp, tmp2, tmp3;
			tmp2 = to_string(arr[h]);
			tmp3 = "W" + tmp2 + ".txt";
			ifstream MyReadFile(tmp3);
			getline(MyReadFile, tmp);
			list.add_msg(tmp2, tmp);
			MyReadFile.close();
		}
		return list;
}

List List::sort(const List& l, Msg n)
{
	List tmp;
	int k = 0;
	while (k <= n.n)
	{
		for (auto range = l.first; range != NULL; range = range->next)
		{
			string find = to_string(k + 1);
			if (range->name == find)
			{
				tmp.add_msg(find, range->content);
				k++;
				if (k == n.n)
				{
					goto stop;
				}
			}
		}
	}
    stop:
    return tmp;  
}  

void List::display(const List& l)
{
	
	for (auto range = l.first; range != NULL; range = range->next)
	{
		cout << range->content;
	}
}

int randomfunc(int j)
{
	return rand() % j;
}

void menu()
{
	List list;
	Msg f;
	List bad;
	List good;
    cout << "Witamy w programie do dzieleniea i skladania wiadomosci" << endl;
	cout << "Dostepne opcje" << endl;
	while (1)
	{
		cout << "1.Wpisanie wiadomosci" << endl;
		cout << "2.Podzielenie wiadomosci" << endl;
		cout << "3.Wyswietlenie nieuporzadkowanej wiadomosci" << endl;
		cout << "4.Wyswietlenie uporzadkowanej wiadomosci" << endl;
		cout << "5.Koniec dzialania programu" << endl;
		cout << "Wybierz opcje ktora Cie interesuje:";
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			f.getMsg();
			cout << endl;
			break;
		}

		case 2:
		{
			f.divideMsg();
			bad = list.flood(f);
			good = list.sort(bad, f);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "Nieuporzadkowana wiadomosc ->";
			list.display(bad);
			cout << endl;
			cout << endl;
			break;
		}
		case 4:
		{
			cout << endl;
			cout << "Uporzadkowana wiadomosc ->";
			list.display(good);
			cout << endl;
			cout << endl;
			break;
		}

		case 5:
		{
			cout << "Zegnamy";
			exit(0);
			break;
		}

		default:
			break;
		}
	}
	
}

