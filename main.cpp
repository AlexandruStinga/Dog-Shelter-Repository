//
// Created by Alex on 3/19/2021.
//
#include "ui/ui.h"
#include "tests/tests.h"
#include "../repository/HTMLAdoptionRepo.h"
#include "../repository/CSVAdoptionRepo.h"
#include "ui/mainwindow.h"
#include "ui/GUI.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	all_tests();

	while (true)
	{
		int option;
		cout<<"1.UI"<<endl<<"2.GUI"<<endl<<"Option: ";
		cin>>option;
//		AdoptionRepo* adopt_repo;
		if (option == 1)
		{
			AdoptionRepo* adopt_repo;
			while (true)
			{
				int option;
				cout<<"Choose the repository: "<<endl<<"1.HTML"<<endl<<"2.CSV"<<endl<<"Option: ";
				cin>>option;
				if (option == 1)
				{
					adopt_repo = new HTMLAdoptionRepo("../adoptions.txt");
					break;
				}
				else if (option == 2)
				{
					adopt_repo = new CSVAdoptionRepo("../adoptions.txt");
					break;
				}
				else cout << "Invalid option\n\n";
			}

			Repository *repo = new fileRepo("../dogs.txt");
			Service s(*repo);
			user_service us(*repo,*adopt_repo);
			ui u(s,us);
			u.mainUI();

			delete adopt_repo;
			delete repo;
			return 0;
		}
		else if (option == 2)
		{
			QApplication a(argc, argv);
			AdoptionRepo* adopt_repo;
			adopt_repo = new HTMLAdoptionRepo("../adoptions.txt");
			Repository *repo = new fileRepo("../dogs.txt");
			Service s(*repo);
			user_service us(*repo,*adopt_repo);
			CommandManager commandManager;
			GUI w(commandManager,s,us);
			w.show();
			int ret = a.exec();

			delete adopt_repo;
			delete repo;

			return ret;
		}
		else cout << "Invalid option\n\n";
	}
}
