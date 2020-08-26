/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 15 March 2020                                                 */
/*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cctype>
#include "inord_list.h"


using namespace std;
int CountLine = 0;
int CountCharacter = 0;
unsigned int CountWord = 0;


int main(int argc, char **argv)
{
	Inorder_List List;
	if(argc==3)
	{
		// Text file
		ifstream textfile(argv[1]);
		// Command file
		ifstream CommandFile(argv[2]);
		if(! textfile.is_open())
		{
			cout<<"File not found"<<endl;
			return 0;

		}
		else
		{
			if(! CommandFile.is_open())
			{
				cout<<"File not found"<<endl;
				return 0;
			}
			else
			{
			char character;
			string Lines;
			string buffer;
			string Word;
			string Word2;
			string Word3;
	/*------------------ Lines counts ---------------*/
			while (!textfile.eof( ))
			{
				getline(textfile,Lines);
				istringstream ss(Lines);
				while(ss >> Word)
				{
					for(unsigned int g=0 ; g<Word.length(); g++)
					{
						if((Word[g]=='.')||(Word[g]==','))
						{
							Word[g]=' ';
						}
					}
					istringstream sss(Word);
					while(sss >> Word2)
					{
						for(unsigned int gg=0 ; gg<Word2.length(); gg++)
						{

							Word2[gg]=tolower(Word2[gg]);

						}
						List.insert(Word2,CountLine);
						CountWord++;
					}
				}
				CountLine++;
			}
			textfile.close();
	/*----------------------------------------------*/
	/*-------------- Characters counts -------------*/
			ifstream textfile(argv[1]);
			while (textfile>> noskipws >> character)
			{
				 CountCharacter++;
			}
//			cout << CountWord<<" Word\n";
//			cout << CountLine<<" Line\n";
//			cout << CountCharacter<<" Character\n";
	// This doesn't check spaces use std::noskipws for that
	/*----------------------------------------------*/
			}
		}
	int counter3=0;
	unsigned int counter2=0;
	string commandword[1000];
	int commandline[1000];
	string CommandLine;
	string Command;
	string temp;
	 while (!CommandFile.eof( ))
	 {
		  getline(CommandFile,CommandLine);
		  istringstream LastSpace(CommandLine);
		  while(LastSpace>>Command)
		 {
			 commandword[counter3]=Command;
			 commandline[counter3]=counter2;
			 counter3++;
		 }
			 counter2++;
	 }

/*	 for(unsigned int x=0 ;x <100;x++)
	 {
		 cout <<" commandword "<<x<<" :"<<commandword[x]<<" in Line: "<<commandline[x]<<endl;
	 }*/
for(int m=0 ;m<counter3;m++)
{
	         temp=commandword[m];
		 	 if(temp=="wordCount")
		 	 {
		 		 int flag0=0;
		 		 int e=1;
		 		 e=m;
		 		 while((commandline[e+1]==commandline[m])&&(commandword[e+1]!="")&&(e!=99))
		 		 {
		 			flag0=1;
		 			e++;
		 		 }
		 		 if(flag0!=1)
		 		 {
			 		 cout << CountWord<<" words"<<endl;
		 		 }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments"<<endl;
		 		 }
		 		m=e;
		 	 }
		 	 else if(temp=="distWords")
		 	 {
		 		 int flag4=0;
		 		 int p=1;
		 		 p=m;
		 		 while((commandline[p+1]==commandline[m])&&(commandword[p+1]!="")&&(p!=99))
		 		 {
		 			flag4=1;
		 			p++;
		 		 }

		 		 if(flag4!=1)
		 		 {
		 		 unsigned int distWords= 0;
		 		 ListLineType line;
		 		 ListElemType element;
		 		 ListElemType ElementTmp;
		 		 bool result;
		 		 result=List.first(element,line);
		 		 while(result==true)
		 		 {
		 			 ElementTmp=element;
		 			 result=List.next(element,line);
		 			 if(ElementTmp!=element)
		 			 {
		 				 distWords++;
		 			 }

		 		 }
		 		 distWords++;
		 		 cout << distWords<<" distinct words"<<endl;
		 		 }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments"<<endl;
		 		 }
		 		m=p;

		 	 }
		 	else if(temp=="charCount")
		 	 {
		 		 int flag9=0;
		 		 int U=1;
		 		 U=m;
		 		 while((commandline[U+1]==commandline[m])&&(commandword[U+1]!="")&&(U!=99))
		 		 {
		 			flag9=1;
		 			U++;
		 		 }
		 		 if(flag9!=1)
		 		 {
		 		 cout << CountCharacter<<" characters"<<endl;
		 		 }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments"<<endl;
		 		 }
		 		m=U;
		 	 }

		 	else if(temp=="frequentWord")
		 	 {
		 		 int flag8=0;
		 		 int E=1;
		 		 E=m;
		 		 while((commandline[E+1]==commandline[m])&&(commandword[E+1]!="")&&(E!=99))
		 		 {
		 			flag8=1;
		 			E++;
		 		 }
		 		 if(flag8!=1)
		 		 {
		 		 int repeated=0;
		 		 int repeatedCounter[CountWord];
		 		 ListElemType Words[CountWord];
		 		 ListLineType line;
		 		 ListElemType element;
		 		 ListElemType ElementTmp;
		 		 ListElemType temp45;
		 		 ListElemType Mostword;
		 		 int MostwordCount;
		 		 bool result3;
		 		 result3=List.first(element,line);
		 		 for(unsigned int b=0 ;(result3==true);b++)
		 		 {
			 		 if(result3==true)
			 		 {
			 			 Words[b]=element;
			 			 result3=List.next(element,line);
			 		 }
		 		 }
		 		 for(unsigned int t=0 ;t < CountWord;t++)
		 		 {
		 			 bool result;
		 			 result=List.first(element,line);
		 			 while(result==true)
		 			 {
		 					 if(element==Words[t])
		 					 {
		 						 MostwordCount++;
		 						 repeatedCounter[t]=MostwordCount;
		 					 }
		 					 result=List.next(element,line);

		 			 }
		 			MostwordCount=0;
		 		 }
		 		 repeated=0;
		 		 for(unsigned int q=0 ;q < CountWord;q++)
		 		 {

		 			if((repeatedCounter[q] > repeated)&&(Words[q] !="a")&&(Words[q] !="an")&&(Words[q] !="the")&&(Words[q] !="in")&&(Words[q] !="on")&&(Words[q] !="of")&&(Words[q] !="and")&&(Words[q] !="is")&&(Words[q] !="are"))
		 			{
		 				repeated=repeatedCounter[q];
		 				Mostword=Words[q];
		 			}
		 		 }
		 		 cout<<"Most frequent word is: "<<Mostword;
		 		 for(unsigned int qq=0 ;qq < CountWord;qq++)
		 		 {
		 			temp45=Mostword;
		 			while((repeatedCounter[qq] == repeated)&&(Words[qq] !="a")&&(Words[qq] !="an")&&(Words[qq] !="the")&&(Words[qq] !="in")&&(Words[qq] !="on")&&(Words[qq] !="of")&&(Words[qq] !="and")&&(Words[qq] !="is")&&(Words[qq] !="are"))
		 			{
		 				if(Words[qq]==temp45)
		 				{
		 					qq++;
		 				}
		 				else
		 				{
						cout<<" "<<Words[qq];
						temp45=Words[qq];
						qq++;
		 				}
		 			}
		 		 }
		 		 cout<<endl;
		 		 }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments"<<endl;
		 		 }
		 		m=E;

		 	 }

		 	else if(temp=="countWord")
		  {
		 		 int flag7=0;
		 		 int I=1;
		 		 I=m;
		 		 while((commandline[I+1]==commandline[m])&&(commandword[I+1]!="")&&(I!=99))
		 		 {
		 			flag7=1;
		 			I++;

		 		 }
		 	//	 cout<<commandword[I]<<"   >"<<endl;
		 	 if((flag7==1)&&(I==m+1))
		 	 {
				 for(unsigned int cC=0 ;cC <commandword[m+1].length();cC++)
				 {
					 commandword[m+1][cC]=tolower(commandword[m+1][cC]);
				 }

		 				int repeatedCounter[CountWord];
		 				ListElemType Words[CountWord];
		 				ListLineType line;
		 				ListElemType element;
		 				ListElemType ElementTmp;
		 				int MostwordCount2;
		 				bool result3;
		 				result3=List.first(element,line);
		 				for(unsigned int b=0 ;(result3==true);b++)
		 				{
		 					if(result3==true)
		 					{
		 							Words[b]=element;
		 							result3=List.next(element,line);
		 					}
		 				}
		 				for(unsigned int t=0 ;t < CountWord;t++)
		 				{
		 					bool result;
		 					result=List.first(element,line);
		 					while(result==true)
		 					{
		 						if(element==Words[t])
		 						{
		 							MostwordCount2++;
		 							repeatedCounter[t]=MostwordCount2;
		 						}
		 						result=List.next(element,line);

		 					}
		 					MostwordCount2=0;
		 				}
		 				int flage10=0;
		 				for(unsigned int q=0 ;q < CountWord;q++)
		 				{
		 					if(Words[q]==commandword[m+1])
		 					{
		 						flage10=1;
		 						cout<<commandword[m+1]<<" is repeated "<<repeatedCounter[q]<<" times"<<endl;
		 						break;
		 					}
		 				}
		 				if(flage10==0)
		 				{
		 					cout<<commandword[m+1]<<" is repeated 0 times"<<endl;
		 				}
		 	 }
	 		 else
	 		 {
	 			cout <<"Incorrect number of arguments"<<endl;
	 		 }
		 	 m=I;
		 	 }


		 	else if(temp=="starting")
		 	{
			  int flag6=0;
			  int v=1;
			  v=m;
			  while((commandline[v+1]==commandline[m])&&(commandword[v+1]!="")&&(v!=99))
			  {
				  flag6=1;
				  v++;
			  }
			  if((flag6==1)&&(v==m+1))
			  {
					 for(unsigned int cC=0 ;cC <commandword[m+1].length();cC++)
					 {
						 commandword[m+1][cC]=tolower(commandword[m+1][cC]);
					 }

				  int repeatedCounter2[CountWord];
				  string st;
				  string stTmp[CountWord];
				  string stTmp2[CountWord];
				  string stringTemp;
				  string temp;
				  st=commandword[m+1];
				  ListLineType line;
				  ListElemType element;
				  ListElemType ElementTmp;
				  unsigned int g=0;
				  bool result;
				  result=List.first(element,line);
				  while(result==true)
				  {
					  ElementTmp=element;
					  if((ElementTmp.compare(0, st.length(), st)) == 0)
					  {
						  stTmp[g]=ElementTmp;
						  g++;
					  }

					  result=List.next(element,line);

				  }

				  for(unsigned int k=0 ; k<g ; k++)
				  {
					  int RepeatedStringTemp=0;
					  int j=0;
			//		  cout<<stTmp2[k]<<"   >"<<RepeatedStringTemp<<endl;
					  stringTemp=stTmp[k];
					  for(unsigned int l=0 ; l<g ; l++)
					  {
						  if(stTmp[l]==stringTemp)
						  {
							  if(RepeatedStringTemp!=1)
							  {
								  stTmp[j]==stringTemp;
								  j++;

							  }
							  RepeatedStringTemp++;

						  }
						  repeatedCounter2[k]=RepeatedStringTemp;
					  }

				  }
				  int flage15=0;
				  for(unsigned int b=0 ; b<g ; b++)
				  {
					  unsigned int j;
					  for(j=0 ; j<b ;j++)
					  {
						  if(stTmp[b]==stTmp[j])
						  {
							  break;
						  }
					  }
					  if(b==j)
					  {
						  flage15=1;
					  cout<<stTmp[b]<<": "<<repeatedCounter2[b]<<"\t";
					  }
				  }
				  if(flage15==0)
				  {
					  cout<<"Word not found";
				  }
			  }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments";
		 		 }
			  m=v;
			  cout<<endl;
		 	}

		 	else if(temp=="containing")
		 	{
			  int flag5=0;
			  int L=1;
			  L=m;
			  while((commandline[L+1]==commandline[m])&&(commandword[L+1]!="")&&(L!=99))
			  {
				  flag5=1;
				  L++;
			  }
			  if((flag5==1)&&(L==m+1))
			  {
					 for(unsigned int cC=0 ;cC <commandword[m+1].length();cC++)
					 {
						 commandword[m+1][cC]=tolower(commandword[m+1][cC]);
					 }


				  int repeatedCounter2[CountWord];
				  string st;
				  string stTmp[CountWord];
				  string stTmp2[CountWord];
				  string stringTemp;
				  string temp;
				  st=commandword[m+1];
				  ListLineType line;
				  ListElemType element;
				  ListElemType ElementTmp;
				  unsigned int g=0;
				  bool result;
				  result=List.first(element,line);
				  while(result==true)
				  {
					  ElementTmp=element;
					  if (ElementTmp.find(st) != std::string::npos)
					  {
						  stTmp[g]=ElementTmp;
						  g++;
					  }

					  result=List.next(element,line);

				  }

				  for(unsigned int k=0 ; k<g ; k++)
				  {
					  int RepeatedStringTemp=0;
					  int j=0;
			//		  cout<<stTmp2[k]<<"   >"<<RepeatedStringTemp<<endl;
					  stringTemp=stTmp[k];
					  for(unsigned int l=0 ; l<g ; l++)
					  {
						  if(stTmp[l]==stringTemp)
						  {
							  if(RepeatedStringTemp!=1)
							  {
								  stTmp[j]==stringTemp;
								  j++;

							  }
							  RepeatedStringTemp++;

						  }
						  repeatedCounter2[k]=RepeatedStringTemp;
					  }

				  }
				  int flag13=0;
				  for(unsigned int b=0 ; b<g ; b++)
				  {
					  unsigned int j;
					  for(j=0 ; j<b ;j++)
					  {
						  if(stTmp[b]==stTmp[j])
						  {
							  break;
						  }
					  }
					  if(b==j)
					  {
						  flag13=1;
						  cout<<stTmp[b]<<": "<<repeatedCounter2[b]<<"\t";
					  }
				  }
				  if(flag13==0)
				  {
					  cout<<"Word not found";
				  }

			  	  }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments";
		 		 }
			  m=L;
			  cout<<endl;
			  }

		 	else if(temp=="search")
		 	{
			  int flag5=0;
			  int w=1;
			  w=m;
			  while((commandline[w+1]==commandline[m])&&(commandword[w+1]!="")&&(w!=99))
			  {
				  flag5=1;
				  w++;
			  }
			  if((flag5==1)&&(w==m+1))
			  {

					 for(unsigned int cC=0 ;cC <commandword[m+1].length();cC++)
					 {
						 commandword[m+1][cC]=tolower(commandword[m+1][cC]);
					 }


				  int repeatedCounter2[CountWord];
				  string st;
				  string stTmp[CountWord];
				  ListLineType lineTmpCounter[CountWord];
				  string stTmp2[CountWord];
				  string stringTemp;
				  string temp;
				  st=commandword[m+1];
				  ListLineType line;
				  ListLineType lineTmp;
				  ListElemType element;
				  ListElemType ElementTmp;
				  unsigned int g=0;
				  bool result;
				  result=List.first(element,line);
				  while(result==true)
				  {
					  lineTmp=line+1;
					  ElementTmp=element;
					  if (ElementTmp.find(st) != std::string::npos)
					  {
						  stTmp[g]=ElementTmp;
						  lineTmpCounter[g]=lineTmp;
						  g++;
					  }

					  result=List.next(element,line);

				  }

				  for(unsigned int k=0 ; k<g ; k++)
				  {
					  int RepeatedStringTemp=0;
					  int j=0;
					  stringTemp=stTmp[k];
					  for(unsigned int l=0 ; l<g ; l++)
					  {
						  if(stTmp[l]==stringTemp)
						  {
							  if(RepeatedStringTemp!=1)
							  {
								  stTmp[j]==stringTemp;
								  j++;

							  }
							  RepeatedStringTemp++;
						  }
						  repeatedCounter2[k]=RepeatedStringTemp;
					  }
				  }
				  int flag14=0;
				  for(unsigned int b=0 ; b<g ; b++)
				  {
					  unsigned int j;
					  for(j=0 ; j<b ;j++)
					  {
						  if(stTmp[b]==stTmp[j])
						  {
							  break;
						  }
					  }
					  if(b==j)
					  {
						  int ModifiedCounter[1000];
						  flag14=1;
						  cout<<stTmp[b]<<":\tlines ";
						  for(int pp=0 ;pp<repeatedCounter2[b];pp++)
						  {
							  ModifiedCounter[pp]=lineTmpCounter[b+pp];
						  }
						  int temp122;
							for(int gg=0;gg<repeatedCounter2[b];gg++)
							{
								for(int jh=gg+1;jh<repeatedCounter2[b];jh++)
								{
									if(ModifiedCounter[gg]>ModifiedCounter[jh])
									{
										temp122=ModifiedCounter[gg];
										ModifiedCounter[gg]=ModifiedCounter[jh];
										ModifiedCounter[jh]=temp122;
									}
								}
							}

						  for(int hh=0 ;hh<repeatedCounter2[b];)
						  {
							  int ff;
							  ff=hh;
							  cout<<ModifiedCounter[ff]<<" ";
							  while(ModifiedCounter[ff]==ModifiedCounter[hh])
							  {
								  hh++;
							  }
						  }
						  cout<<endl;
					  }

				  }
				  if(flag14==0)
				  {
					  cout<<"Word not found"<<endl;
				  }
			  }
		 		 else
		 		 {
		 			cout <<"Incorrect number of arguments"<<endl;
		 		 }
			  m=w;
		 	}

		 	else
		 	{
		 		 int ee=1;
		 		 ee=m;
		 		 while((commandline[ee+1]==commandline[m])&&(commandword[ee+1]!="")&&(ee!=99))
		 		 {
		 			 ee++;
		 		 }
		 		m=ee;
		 		cout<<"Undefined command"<<endl;
		 	}
		}
	}
	else
	{
		cout <<"Incorrect number of arguments"<<endl;
	}
	return 0;
}
