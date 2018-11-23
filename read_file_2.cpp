/*
	CHUONG TRINH KIEM TRA THONG TIN VE MEMORY CUA MOT PROCESS DANG HOAT DONG
	NHOM 6 - KSTN-DTVT K59
*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

void display(char data[], string str);

int main()
{
	char data[255];
	int A[20];
	int k = 0;
	int pid;

	string path;
	string f1 = "/proc/";
	string f2 = "/status";
	string f3;
	string str;

	cout << "Nhap vao PID cua process: ";
	cin >> pid;
	// cout << endl;

	f3 = std::to_string(pid); //chuyen pid ve kieu string

	path = f1 + f3 + f2;

	// cout << path << endl;

	ifstream mem_proc;   // dua ve che do read
	mem_proc.open(path); // infile.open("/proc/[pid]/status"); // mo file status

	cout << "=====================================================\n";
	cout << "THONG TIN VE MEMORY CUA PROCESS " << pid << ":" << endl;

	while (!mem_proc.eof()) // kiem tra neu chua ket thuc file
	{
		mem_proc >> data; // doc du lieu vao bien : du lieu doc den dau cach
		if ((str == "VmPeak:") || (str == "VmSize:") || (str == "VmHWM:") || (str == "VmRSS:") || (str == "RssAnon:") || (str == "RssFile:") || (str == "RssShmem:") || (str == "VmData:") || (str == "VmStk:") || (str == "VmExe:") || (str == "VmLib:") || (str == "VmPTE:") || (str == "VmSwap:"))
		{
			// display(data, pr);
			int val = atoi(data);

			A[k++] = val;
			cout << "\t- " << str << "\t" << val << "\tkB" << endl;
		}

		str = data;
	}

	// dong file da mo.
	mem_proc.close(); // dong file

	cout << "=====================================================\n";

	cout << "Bo nho ao ma process dang su dung la: " << A[0] << " kB" << endl;
	cout << "Bo nho trong RAM ma process dang su dung la: " << A[3] << " kB" << endl;
	cout << "Bo nho trong SWAP ma process dang su dung la: " << A[12] << " kB" << endl;

	cout << "=====================================================\n";

	return 0;
}
