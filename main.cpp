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

void functioning(string login);

string convertToString(char* a) 
{ 
    string s(a); 
    return s; 
} 

void direc_list(string login){
	cout<<"\t\t\t Directory Section\n";
	cout<<"Press 1 to show grayscale red channel videos\nPress 2 to show red channel videos other channels value to 0\nPress 3 to show blue channel videos other channels value to 0\nPress 4 to show green channel videos other channels value to 0\nPress b to back to record section\nPress q to quit\n";
	char key;
	cin>>key;
	switch(key){
		case '1':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./recorded/") ){
	        		int i=1;
	        		cout<<"\t\t\tRecorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
	                        	string info = convertToString(entry->d_name);
	                        	if(info.find(login)!= std::string::npos){
	                        		cout <<entry->d_name << "\t";
	                        	}
	                        }
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list(login);
		}
		case '2':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./redrecord") ){
	        		cout<<"\t\t\tRecorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
	                        	string info = convertToString(entry->d_name);
	                        	if(info.find(login)!= std::string::npos){
	                        		cout <<entry->d_name << "\t";
	                        	}
	                        }
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
        	direc_list(login);
		}
		case '3':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./bluerecord/") ){
	        		cout<<"\t\t\tRecorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
	                        	string info = convertToString(entry->d_name);
	                        	if(info.find(login)!= std::string::npos){
	                        		cout <<entry->d_name << "\t";
	                        	}
	                        }
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list(login);
		}
		case '4':{
			DIR *pDIR;
	        struct dirent *entry;
	        if( pDIR=opendir("./greenrecord/") ){
	        		cout<<"\t\t\tRecorded Files"<<endl;
	                while(entry = readdir(pDIR)){
	                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
	                        	string info = convertToString(entry->d_name);
	                        	if(info.find(login)!= std::string::npos){
	                        		cout <<entry->d_name << "\t";
	                        	}
	                        }
	                }
	                cout<<"\n\n";
	                closedir(pDIR);
	        }
	        direc_list(login);
		}
		case 'b':{
			functioning(login);
		}
		case 'q':{
			exit(1);
		}
		default:{
			functioning(login);
		}
	}
}

void functioning(string login){
	cout<<"\t\t\t Record Section\n";
	cout<<"Press 1 to record video\nPress 2 to show list of recorded videos\nPress 3 to record only red channel video other channels value to 0\nPress 4 to record only blue channel video other channels value to 0\nPress 5 to record only green channels video other channel value to 0\nPress q to quit\n";
	char key;
	cin>>key;
	switch(key){
		case '1':{
			record(login);
			functioning(login);
		}
		case '2':{
			direc_list(login);
			functioning(login);
		}
		case '3':{
			recordred(login);
			functioning(login);
		}
		case '4':{
			recordblue(login);
			functioning(login);
		}
		case '5':{
			recordgreen(login);
			functioning(login);
		}
		case 'q':{
			exit(1);
		}
		default:{
			functioning(login);
		}
	}
}

void call(){
	string login = Register_login();
	if(login!="zzzzzzzzzzzzzzzzzzzzzzzzz"){
		functioning(login);
	}
	else{
		call();
	}
}

int main(){
	cout<<"\t\t\twelcome to the app\t\t\t"<<endl;
	call();
}