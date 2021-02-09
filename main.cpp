#include <bits/stdc++.h>
#include "login.cpp"
#include "record.cpp"
#include "recordred.cpp"
#include "recordblue.cpp"
#include "recordgreen.cpp"
#include <filesystem>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include <dirent.h>

using namespace std;

void functioning();

void direc_list(){
	cout<<"Press 1 to show grayscale red channel videos\nPress 2 to show red channel videos other channels value to 0\nPress 3 to show blue channel videos other channels value to 0\nPress 4 to show green channel videos other channels value to 0\nPress b to back to record section\nPress q to quit\n";
	char key;
	cin>>key;
	switch(key){
		case '1':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./recorded/") ){
	        		int i=1;
	        		cout<<"Recorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
	                        cout <<entry->d_name << "\t";
	                    	i++;
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list();
		}
		case '2':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./redrecord") ){
	        		int i=1;
	        		cout<<"Recorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
	                        cout << entry->d_name << "\t";
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
        	direc_list();
		}
		case '3':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./bluerecord/") ){
	        		int i=1;
	        		cout<<"Recorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
	                        cout << entry->d_name << "\t";
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list();
		}
		case '4':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./greenrecord/") ){
	        		int i=1;
	        		cout<<"Recorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
	                        cout << entry->d_name << "\t";
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list();
		}
		case 'b':{
			functioning();
		}
		case 'q':{
			exit(1);
		}
		default:{
			functioning();
		}
	}
}

void functioning(){
	cout<<"Press 1 to record video\nPress 2 to show list of recorded videos\nPress 3 to record only red channel video other channels value to 0\nPress 4 to record only blue channel video other channels value to 0\nPress 5 to record only green channels video other channel value to 0\nPress q to quit\n";
	char key;
	cin>>key;
	switch(key){
		case '1':{
			record();
			functioning();
		}
		case '2':{
			direc_list();
			functioning();
		}
		case '3':{
			recordred();
			functioning();
		}
		case '4':{
			recordblue();
			functioning();
		}
		case '5':{
			recordgreen();
			functioning();
		}
		case 'q':{
			exit(1);
		}
		default:{
			functioning();
		}
	}
}

int main(){
	cout<<"\t\t\twelcome to the app\t\t\t"<<endl;
	int login = Register_login();
	if(login==1){
		functioning();
	}
}