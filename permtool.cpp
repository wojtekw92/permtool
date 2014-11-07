#include <iostream>
#include <string>
using namespace std;
void showHelp()
{
	cout << "\t Help Page:" << endl
		<< "-b convert char permission to int permission" << endl
		<< "-d convert int permission to char permission" << endl
		<< "SAMPLE" << endl
		<< "premtool -b rwxrwxrwx     ==> 777" << endl
		<< "premtool -b drwxrwxrwx    ==> 777" << endl
		<< "premtool -d 777           ==> rwxrwxrwx" << endl;
}
int main(int argc, char *argv[])
{
	int a=0;
	int b=0;
	int c=0;
	int i=0;
	if(argc<=2){
		showHelp();
		return 0;
	}
	string comm=argv[1];
	string pom=argv[2];
	if(comm=="-b")
	{
		if(pom.length()<9) return 0;
		if(pom.length()==10) pom=pom.substr(1);
		for(;i<9;i++)
		{
			if(pom[i]=='r')
			{
				if(i<3)a+=4;
				else if(i<6)b+=4;
				else c+=4;
			}
			if(pom[i]=='w')
			{
				if(i<3)a+=2;
				else if(i<6)b+=2;
				else c+=2;
			}
			if(pom[i]=='x')
			{
				if(i<3)a+=1;
				else if(i<6)b+=1;
				else c+=1;
			}
		}
		cout << a << b << c;
	}
	else if(comm=="-d")
	{
		a=stoi(pom);
		pom="";
		for(i=0;i<3;i++)
		{
			b=a%10;
			a=a/10;
			switch(b)
			{
				case 0: pom="---"+pom;
				break;
				case 1: pom="--x"+pom;
				break;
				case 2: pom="-w-"+pom;
				break;
				case 3: pom="-wx"+pom;
				break;
				case 4: pom="r--"+pom;
				break;
				case 5: pom="r-x"+pom;
				break;
				case 6: pom="rw-"+pom;
				break;
				case 7: pom="rwx"+pom;
				break;
			}
		}
		cout << pom;
	}
	else showHelp();
	return 0;
}

