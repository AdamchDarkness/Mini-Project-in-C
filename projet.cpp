#include<stdio.h>
#include<windows.h>
#include<conio.h>

//Fonction Position
void gotoxy(short x, short y)                                                      
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Fonction Couleur
void Color (int couleurDuTexte,int couleurDeFond)
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
///////////////////////////////////////////////////////////////////////////////////
//fichier pour film
struct tf
{
	int id;
	char nom[30];
	char rea[30];
	float prix;
}fi;
FILE*film;
//fichier pour utilisateur
struct tu
{
	int id;
	char nom[40];
	char prenom[40];
	char mail[50];
	int code;
}mm;
FILE*membres;
//fichier pour gerant
struct tg
{
	int id;
	char nom[30];
	char prenom[30];
	int code;
}ge;
FILE*gerant;
//fichier pour film Acheter par un utilisateur
struct ta
{
	char nom[40];
	int code;
	int idfilm;
}fa;
FILE*filmA;
//fichier pour film noter
struct tn
{
	int idfilm;
	char nom[30];
	int note;
}fn;
FILE*filmN;

struct tc
{
	char nom[40];
}fc;
FILE*filmc;
////////////////////////////////////////////////////////////////////////////
//COde pour la barre ou ecrire
barre(int x,int y)
{
	int i;
	gotoxy(x,y);printf("%c",218);
	for(i=y;i<=20;i++)
	{
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(x,y+1);printf("%c",179);gotoxy(x+17,y+1);printf("%c",179);
	gotoxy(x,y+2);printf("%c",192);
	for(i=y;i<=20;i++)
	{
		printf("%c",196);
	}
	printf("%c",217);
}
////////////////////////////////////////////////////////////////////
//pour tracer des lignes
void hor(int x,int y,int z)	
	{
		int i;
		gotoxy(x,y);
		for (i=1;i<=z;i++)
		{
			printf("%c",196);
		}
	}
void ver(int y,int x,int z)
	{
		int i;
		for(i=z;i<=x;i++)
		{
		gotoxy(y,i);
		printf("%c",179);
		}
	}
///////////////////////////////////////////////
int code,T,G,M,c,s,v;
int id;
//saisie film
saisief()
{
	id=0;
	film=fopen("film.dat","r");
	fread(&fi,sizeof(fi),1,film);
	while(!feof(film))
	{
		id++;
		fread(&fi,sizeof(fi),1,film);
	}fclose(film);
	film=fopen("film.dat","a");
	do
	{
		system("cls");
		fi.id=id;
		printf("%d",fi.id);
		gotoxy(20,6);printf("1 - Saisir nom du film");
		gotoxy(48,6);scanf("%s",&fi.nom);
		gotoxy(20,8);printf("2 - Saisir realisateur du film");
		gotoxy(55,8);scanf("%s",&fi.rea);
		gotoxy(20,10);printf("3 - Saisir prix du film ");
		gotoxy(44,10);scanf("%f",&fi.prix);
		gotoxy(20,14);printf("Taper 1 pour enregistrer les donnes ou 0 pour annuler");scanf("%d",&v);
		if(v==1)
		{
			fwrite(&fi,sizeof(fi),1,film);
			gotoxy(20,16);printf("Les donnees ont ete enregistrees");
		}
		id=id+1;
		gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);
	}
	while(s!=0);
	fclose(film);	
}
//consultation film
consulf()
{
	do
	{
		system("cls");
		film=fopen("film.dat","r");
		gotoxy(38,2);Color(12,0);printf("Consultation de film");
		gotoxy(20,4);Color(15,0);printf("Saisir id du film a consulter");
		gotoxy(56,4);scanf("%d",&id);
		T=0;
		film=fopen("film.dat","r");
		fread(&fi,sizeof(fi),1,film);	
		while(!feof(film) && T==0)
		{
			if(id==fi.id)
			{
				T=1; 	
			}
			else
			{
				fread(&fi,sizeof(fi),1,film);	
			}	
		}
		if(T==0)
		{
			gotoxy(20,6);printf("N existe pas");
			fclose(film);
		}
		else
		{
			gotoxy(20,6);printf("Nom du film : %s",fi.nom);
			gotoxy(20,8);printf("Realisateur du film : %s",fi.rea);
			gotoxy(20,10);printf("Prix du film : %f",fi.prix);
			fclose(film);
		}
	 	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);
	}
	while(s!=0);
}
//consultation client
consulc()
{
	do
 	{
 		system("cls");
 		membres=fopen("membres.dat","r");
		gotoxy(38,2);Color(12,0);printf("Consultation de client");
		gotoxy(20,4);Color(15,0);printf("Saisir id du client a consulter");
		gotoxy(56,4);scanf("%d",&id);
 		T=0;
 		membres=fopen("membres.dat","r");
 		fread(&mm,sizeof(mm),1,membres);	
 		while(!feof(membres) && T==0)
 		{
 			if(id==mm.id)
			{
				T=1; 	
			}
			else
			{
				fread(&mm,sizeof(mm),1,membres);
			}	
		}
		if(T==0)
		{
			gotoxy(20,6);printf("N existe pas");
			fclose(membres);
		}
		else
		{
			gotoxy(20,6);printf("Nom du client : %s",mm.nom);
			gotoxy(20,8);printf("Prenom du client : %s",mm.prenom);
			gotoxy(20,10);printf("Code du client : %s",mm.code);
			fclose(membres);
		}
	 	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);
	}
	while(s!=0);
}
//liste film
lfilm()
{
	int i;
	do{
	system("cls");
	gotoxy(40,2);printf("Liste de film");
	film=fopen("film.dat","r");
	gotoxy(8,4);printf("%c",218);
	gotoxy(8,5);printf("%c",179);
	gotoxy(8,6);printf("%c",195);
	hor(9,4,56);printf("%c",191);
	gotoxy(10,5);printf("Id");
	gotoxy(30,5);printf("Nom");
	gotoxy(50,5);printf("Prix");
	fread(&fi,sizeof(fi),1,film);
	i=7;
	while(!feof(film))
	{
		gotoxy(9,6);printf("%c",180);
		hor(9,6,56);printf("%c",191);
		gotoxy(10,i);printf("%d",fi.id);
		gotoxy(30,i);printf("%s",fi.nom);
		gotoxy(50,i);printf("%.2f",fi.prix);
		i++;
		fread(&fi,sizeof(fi),1,film);
	}
	ver(8,i-1,6);
	ver(65,i-1,5);
	gotoxy(8,i);printf("%c",192);hor(9,i,56);printf("%c",217);
	gotoxy(15,i+3);printf("Tapez 1 pour commander un film non present sur la liste ou 0 pour retour au menu ");scanf("%d",&s);
	if(s==1)
	{
		filmc=fopen("filmc","a");
		do
		{
			system("cls");
			gotoxy(15,5);
			printf("Tapez le nom du film ");scanf("%s",fc.nom);
			fwrite(&fc,sizeof(fc),1,filmc);
			gotoxy(15,10);
			printf("Tapez 1 pour commander un film non present sur la liste ou 0 pour retour au menu ");
			scanf("%d",&T);
		}while(T!=0);fclose(filmc);
	}
	}
	while(s!=0);
	fclose(film);
}
//liste film commanfer
lfc()
{
		int i;
	system("cls");
	gotoxy(40,2);printf("Liste de film commander ");
	filmc=fopen("filmc","r");
	gotoxy(8,4);printf("%c",218);
	gotoxy(8,5);printf("%c",179);
	gotoxy(8,6);printf("%c",195);
	hor(9,4,56);printf("%c",191);
	gotoxy(10,5);printf("Nom film");
	fread(&fc,sizeof(fc),1,filmc);
	i=7;
	while(!feof(filmc))
	{
		gotoxy(9,6);printf("%c",180);
		hor(9,6,56);printf("%c",191);
		gotoxy(10,i);printf("%s",fc.nom);
		i++;
		fread(&fc,sizeof(fc),1,filmc);
	}
	ver(8,i-1,6);
	ver(65,i-1,5);
	gotoxy(8,i);printf("%c",192);hor(9,i,56);printf("%c",217);
	getch();fclose(filmc);	
}
//liste clinet
lclient()
{
	int i;
	system("cls");
	gotoxy(40,2);printf("Liste de film");
	membres=fopen("membres.dat","r");
	gotoxy(8,4);printf("%c",218);
	gotoxy(8,5);printf("%c",179);
	gotoxy(8,6);printf("%c",195);
	hor(9,4,56);printf("%c",191);
	gotoxy(10,5);printf("Id");
	gotoxy(30,5);printf("Nom");
	gotoxy(50,5);printf("Code");
	fread(&mm,sizeof(mm),1,membres);
	i=7;
	while(!feof(membres))
	{
		gotoxy(9,6);printf("%c",180);
		hor(9,6,56);printf("%c",191);
		gotoxy(10,i);printf("%s",mm.id);
		gotoxy(30,i);printf("%s",mm.nom);
		gotoxy(50,i);printf("%s",mm.code);
		i++;
		fread(&mm,sizeof(mm),1,membres);
	}
	ver(8,i-1,6);
	ver(65,i-1,5);
	gotoxy(8,i);printf("%c",192);hor(9,i,56);printf("%c",217);
	getch();fclose(membres);
}
//client par id film
cpif()
{
	int i;
	do
	{
		system("cls");
		filmA=fopen("filmA.dat","r"); 
		gotoxy(38,2);Color(12,0);printf("Client par id film");
		gotoxy(20,4);Color(15,0);printf("Saisir id du film");
		gotoxy(56,4);scanf("%d",&id);
		gotoxy(10,6);printf("id film");
		gotoxy(30,6);printf("Nom");
		gotoxy(50,6);printf("Code");
		T=0;
		i=8;
		fread(&fa,sizeof(fa),1,filmA);
		while(!feof(filmA) && T==0)
		{
			if(id==fa.idfilm)
			{
				T=1;
			}
			else
			{
				fread(&fa,sizeof(fa),1,filmA);
			}	
		}
		if(T==0)
		{
			gotoxy(25,i);printf("Nexiste pas");
		}
		else
		{
			gotoxy(10,i);printf("%d",fa.idfilm);
			gotoxy(30,i);printf("%s",fa.nom);
			gotoxy(50,i);printf("%s",fa.code);
		}
	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);	fclose(filmA);
	}
	while(s!=0);
}
//note par id film 
npif()
{
	int i;
	do
	{
		system("cls");
		filmN=fopen("filmN.dat","r"); 
		gotoxy(38,2);Color(12,0);printf("Client par id film");
		gotoxy(20,4);Color(15,0);printf("Saisir id du film");
		gotoxy(56,4);scanf("%d",&id);
		gotoxy(10,6);printf("id film");
		gotoxy(30,6);printf("Nom");
		gotoxy(50,6);printf("Note");
		T=0;
		i=8;
		fread(&fn,sizeof(fn),1,filmN);
		while(!feof(filmA) && T==0)
		{
			if(id==fn.idfilm)
			{
				T=1;
			}
			else
			{
				fread(&fn,sizeof(fn),1,filmN);
			}	
		}
		if(T==0)
		{
			gotoxy(25,i);printf("Nexiste pas");
		}
		else
		{
			gotoxy(10,i);printf("%d",fn.idfilm);
			gotoxy(30,i);printf("%s",fn.nom);
			gotoxy(50,i);printf("%d",fn.note);
		}
	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);	fclose(filmN);
	}
	while(s!=0);
}	
//formulaire gerant
formg()
{
	id=0;
	gerant=fopen("gerant.dat","r");
	fread(&ge,sizeof(ge),1,gerant);
	while(!feof(gerant))
	{
		id++;
		fread(&ge,sizeof(ge),1,gerant);
	}fclose(gerant);
	gerant=fopen("gerant.dat","a");
	do
	{
		system("cls");
		ge.id=id;
		printf("%d",fi.id);
		gotoxy(20,6);printf("1 - Saisir nom");
		gotoxy(48,6);scanf("%s",&ge.nom);
		gotoxy(20,8);printf("2 - Saisir prenom");
		gotoxy(55,8);scanf("%s",&ge.prenom);
		gotoxy(20,10);printf("3 - Saisir code du gerant ");
		gotoxy(44,10);scanf("%d",&ge.code);
		gotoxy(20,14);printf("Taper 1 pour enregistrer les donnes ou 0 pour annuler");scanf("%d",&v);
		if(v==1)
		{
			fwrite(&ge,sizeof(ge),1,gerant);
			gotoxy(20,16);printf("Les donnees ont ete enregistrees");
		}
		id=id+1;
		gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);
	}
	while(s!=0);
	fclose(gerant);
}
//menu admin
menuad()
{
	do
	{
		system("cls");
		gotoxy(35,2);printf("Menu Admin");
		gotoxy(15,4);printf("1-Saise film");
		gotoxy(15,6);printf("2-Consultaion film");
		gotoxy(15,8);printf("3-Consultaion client");
		gotoxy(15,10);printf("4-Liste film");
		gotoxy(15,12);printf("5-Liste client");
		gotoxy(15,14);printf("6-Client par id film");
		gotoxy(15,16);printf("7-Notation par id film");
		gotoxy(15,18);printf("8-Ajouter gerant");
		gotoxy(15,20);printf("9-Liste de film commander");
		gotoxy(15,22);printf("10-Deconnection");
		gotoxy(20,24);printf("Choix ");scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				saisief();
				break;
			}
			case 2:
			{
				consulf();
				break;
			}
			case 3:
			{
				consulc();
				break;
			}
			case 4:
			{
				lfilm();
				break;
			}
			case 5:
			{
				lclient();
				break;
			}
			case 6:
			{
				cpif();
				break;
			}
			case 7:
			{
				npif();
				break;
			}
			case 8:
			{
				formg();
				break;
			}
			case 9:
			{
				lfc();
				break;
			}
		}
	}
	while(c!=10);
}
//Formulaire d'inscription
form()
{
	id=0;
	membres=fopen("membres.dat","r");
	fread(&mm,sizeof(mm),1,membres);
	while(!feof(membres))
	{
		id++;
		fread(&mm,sizeof(mm),1,membres);
	}fclose(membres);
	system("cls");
	membres=fopen("membres.dat","a");
	mm.id=id+1;
	gotoxy(9,3);printf("Votre id : %d",mm.id);
	gotoxy(9,5);printf("Nom");
	gotoxy(28,5);scanf("%s",&mm.nom);
	gotoxy(9,8);printf("Prenom");
	gotoxy(28,8);scanf("%s",&mm.prenom);
	gotoxy(9,11);printf("Mail");
	gotoxy(28,11);scanf("%s",&mm.mail);
	gotoxy(9,13);printf("Code");
	gotoxy(28,13);scanf("%d",&mm.code);
	gotoxy(9,15);printf("Confirmation code");
	gotoxy(28,15);scanf("%d",&code);
	T=0;
	if(code==mm.code)
	{
		T=1;
	}
	else
	{
		T=0;
	}
	if(T==0)
	{
		printf("Les codes ne corespondent pas");
	}
	else
	{
		fwrite(&mm,sizeof(mm),1,membres);
		printf("Votre compte a ete cree");
	
	}	fclose(membres);
}
//menu gerant
menuge()
{
		do
	{
		system("cls");
		gotoxy(35,2);printf("Menu Gerant");
		gotoxy(15,4);printf("1-Saise film");
		gotoxy(15,6);printf("2-Consultaion film");
		gotoxy(15,8);printf("3-Consultaion client");
		gotoxy(15,10);printf("4-Liste film");
		gotoxy(15,12);printf("5-Liste client");
		gotoxy(15,14);printf("6-Client par id film");
		gotoxy(15,16);printf("7-Notation par id film");
		gotoxy(15,18);printf("8-Liste de film commander");
		gotoxy(15,20);printf("9-Deconnection");
		gotoxy(20,22);printf("Choix ");scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				saisief();
				break;
			}
			case 2:
			{
				consulf();
				break;
			}
			case 3:
			{
				consulc();
				break;
			}
			case 4:
			{
				lfilm();
				break;
			}
			case 5:
			{
				lclient();
				break;
			}
			case 6:
			{
				cpif();
				break;
			}
			case 7:
			{
				npif();
				break;
			}
		}
	}
	while(c!=8);
}
//achat film
af()
{
	 do
	{
		system("cls");
		filmA=fopen("filmA.dat","w");
		gotoxy(38,2);Color(12,0);printf("Achat de film");
		gotoxy(20,4);Color(15,0);printf("1 - Saisir id du film a acheter");
		gotoxy(43,4);scanf("%d",&fa.idfilm);
		gotoxy(20,6);printf("2 - Saisir votre code");
		gotoxy(48,6);scanf("%d",&fa.code);
		gotoxy(20,8);printf("2 - Saisir votre nom");
		gotoxy(48,8);scanf("%s",&fa.nom);
		membres=fopen("membres.dat","r");
		T=0;
		fread(&mm,sizeof(mm),1,membres);
		while(!feof(membres) && T==0)
		{
			if(fa.code==mm.code)
			{
				T=1;
			}
			else
			{
				fread(&mm,sizeof(mm),1,membres);
			}
		}
		if(T=0)
		{
			gotoxy(20,16);printf("Ce code n'existe pas");
		}
		else
		{
			fwrite(&fa,sizeof(fa),1,filmA);
			gotoxy(20,16);printf("Merci d'avoir acheter ce film");
		}
	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);
	}
	while(s!=0);
	fclose(filmA);
}
//film par code
fpc()
{
	int i;
	do
		{
			system("cls");
			filmA=fopen("filmA.dat","r");
			gotoxy(38,2);Color(12,0);printf("film par code");
			gotoxy(20,4);Color(15,0);printf("Saisir votre code");
			gotoxy(56,4);scanf("%d",&id);
			gotoxy(10,6);printf("code");
			gotoxy(30,6);printf("id film");
			gotoxy(50,6);printf("nom film");
			T=0;
			i=8;
			fread(&fa,sizeof(fa),1,filmA);
			while(!feof(filmA) && T==0)
			{
				if(id==fa.code)
				{
					T=1;
				}
				else
				{
					fread(&fa,sizeof(fa),1,filmA);
				}	
			}
			if(T==0)
			{
				gotoxy(25,i);printf("Nexiste pas");
			}
			else
			{
				gotoxy(10,i);printf("%d",fa.code);
				gotoxy(30,i);printf("%d",fa.idfilm);
				film=fopen("film.dat","r");
				T=0;
				fread(&fi,sizeof(fi),1,film);
				while(!feof(film) && T==0)
				{
					if(id==fi.id)
					{
						T=1;
					}
					else
					{
						fread(&fi,sizeof(fi),1,film);
					}	
				}
				if(T==0)
				{
					gotoxy(50,i);printf("Film non trouver");
				}	
				else
				{
					gotoxy(50,i);printf("%s",fi.nom);
				}
			}
		gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);	
	}
	while(s!=0);
}
//noter un film
nf()
{
	do
	{
		system("cls");
		filmN=fopen("filmN.dat","a");
		gotoxy(38,2);Color(12,0);printf("Notation Film");
		gotoxy(20,4);Color(15,0);printf("Saisir l'id du film a noter");
		gotoxy(56,4);scanf("%d",&fn.idfilm);
		film=fopen("film.dat","r");
		T=0;
		fread(&fi,sizeof(fi),1,film);
		while(!feof(film) && T==0)
		{
			if(fn.idfilm==fi.id)
			{
				T=1;
			}
			else
			{
				fread(&fi,sizeof(fi),1,film);
			}	
		}
		if(T==0)
		{
			gotoxy(20,6);printf("Film non trouver");
		}	
		else
		{
			gotoxy(20,6);printf("Ecrire nom du film");
			gotoxy(50,6);scanf("%s",fn.nom);
			gotoxy(20,8);printf("Ecrire votre note sur 10");
			gotoxy(50,8);scanf("%d",fn.note);
			fwrite(&fn,sizeof(fn),1,filmN);	
		}
	gotoxy(20,18);printf("Tapez 1 pour autre saisie sinon 0 pour retour au menu  ");scanf("%d",&s);	
	}
	while(s!=0);
	
}
//menu client
menucl()
{
	system("cls");
	do
	{
		gotoxy(40,2);printf("client");
		gotoxy(20,4);printf("1-Acheter un film");
		gotoxy(20,6);printf("2-Liste de film");
		gotoxy(20,8);printf("3-Film par code"); 
		gotoxy(20,10);printf("4-Noter un film");
		gotoxy(20,12);printf("5-Quitter");
		gotoxy(30,14);printf("Choix");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				af();
				break;
			}
			case 2:
			{
				lfilm();
				break;
			}
			case 3:
			{
				fpc();
				break;
			}
			case 4:
			{
				nf();
				break;
			}
		}
	}
	while(c!=5);
	
}
//connection
menu()
{
	system("cls");
	gotoxy(9,6);printf("Tapez votre code");barre(27,5);
	gotoxy(28,6);scanf("%d",&code);
	T=0;
	G=0;
	M=0;
	if(code==545)
	{
		menuad();
	}
	else if(code==0)
	{
		form();
	}
	else
	{
		gerant=fopen("gerant.dat","r");
		fread(&ge,sizeof(ge),1,gerant);
		while((!feof(gerant)) && (T==0))
		{
			if(code==ge.code)
			{
				T=1;
			}
			else
			{
				fread(&ge,sizeof(ge),1,gerant);
			}
		}
		fclose(gerant);
		membres=fopen("membres.dat","r");
		fread(&mm,sizeof(mm),1,membres);
		while((!feof(membres)) && (M==0))
		{
			if(code==mm.code)
			{
				M=1;
			}
			else
			{
				fread(&mm,sizeof(mm),1,membres);
			}
		}
		fclose(membres);
		if (T==1)
		{
			menuge();
		}
		else if(M==1)
		{
			menucl();
		}	
	}
}
main()
{
	menu();
}
