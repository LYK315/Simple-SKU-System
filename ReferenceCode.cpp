////FOP Assignment January 2021 - Online Hospital System
////Liaw Yi Kai - 0131008
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <ctime>
//#include <fstream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//
//struct Hospital
//{
//	string institution, doctor1, doctor2;
//};
//struct Patient
//{
//	string name, birth, address;
//	int id = 0, apptDay = 0, apptMonth = 0, apptYear = 0, n_apptDay = 0, n_apptMonth = 0, n_apptYear = 0;
//
//	string labelVitC, labelVitB, nlabelVitC = "blank", nlabelVitB = "blank";
//	int amtVitC = 0, amtVitB = 0, namtVitC = 0, namtVitB = 0;
//};
//
//void clrError()
//{
//	cin.clear();
//	cin.ignore(100, '\n');
//}
//
//void clrScreen()
//{
//	//getch() learned form: https://www.geeksforgeeks.org/difference-getchar-getch-getc-getche/
//	int getch();
//
//	cout << "Press any key for Main Menu...";
//	getch(); //read input by user, but doesn't save it at buffer
//	system("cls");
//}
//
///*-------------------------------------------------------------------------------------------------------------------------------*/
//
////fucntion created to determine updated / non-updated values to avoid error while writing to file or outputing
//void defineUpdatedValue(Patient patientInfo[], int pat_id)
//{
//	if (patientInfo[pat_id].namtVitC == 0)
//		patientInfo[pat_id].namtVitC = patientInfo[pat_id].amtVitC;
//
//	if (patientInfo[pat_id].namtVitB == 0)
//		patientInfo[pat_id].namtVitB = patientInfo[pat_id].amtVitB;
//
//	if (patientInfo[pat_id].nlabelVitC == "blank")
//		patientInfo[pat_id].nlabelVitC = patientInfo[pat_id].labelVitC;
//
//	if (patientInfo[pat_id].nlabelVitB == "blank")
//		patientInfo[pat_id].nlabelVitB = patientInfo[pat_id].labelVitB;
//
//	if (patientInfo[pat_id].n_apptDay == 0)
//	{
//		patientInfo[pat_id].n_apptDay = patientInfo[pat_id].apptDay;
//		patientInfo[pat_id].n_apptMonth = patientInfo[pat_id].apptMonth;
//		patientInfo[pat_id].n_apptYear = patientInfo[pat_id].apptYear;
//	}
//}
//
//void checkDate(Patient patientCheck[], int id, bool& d, bool& m, bool& y)
//{
//	int dd = patientCheck[id].n_apptDay;
//	int mm = patientCheck[id].n_apptMonth;
//	int yy = patientCheck[id].n_apptYear;
//
//	if (yy >= 2021 && yy <= 9999)
//		y = true;
//
//	if (dd >= 1 && mm >= 1 && mm <= 12)
//	{
//		m = true;
//		if (mm == 2)
//		{
//			//check for leap year
//			if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
//			{
//				if (dd <= 29)
//					d = true;
//			}
//			else if (dd <= 28)
//				d = true;
//		}
//
//		if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
//		{
//			if (dd <= 30)
//				d = true;
//		}
//		else
//			if (mm != 2)
//			{
//				if (dd <= 31)
//					d = true;
//			}
//	}
//	//date error check adapted from: https://www.geeksforgeeks.org/program-check-date-valid-not/
//}
//
///*-------------------------------------------------------------------------------------------------------------------------------*/
//
////Hard Coded patient list
//void createFile()
//{
//	//if file already exist in particular pc, do not create this file to insert these infos
//	ifstream filecheck("patient.txt", ios::in);
//	if (!filecheck)
//	{
//		ofstream filewrite("patient.txt", ios::out);
//		if (filewrite.is_open())
//		{
//			filewrite << 1 << "\n" << "Liaw Yi Kai" << "\n" << "15/03/2001" << "\n" << 11 << "\t" << 5 << "\t" << 2021 << "\n" << 2 << "\t" << "1 Tablet per day, Morning, after meal" << "\n" << 1 << "\t" << "1 Tablet per day, before sleep" << "\n" << "5, Jalan Zapin 9E, Bandar Bukit Baja, 41050 Klang, Selangor" << "\n\n"
//				<< 2 << "\n" << "Kok Yong Wei" << "\n" << "16/03/2001" << "\n" << 12 << "\t" << 5 << "\t" << 2021 << "\n" << 3 << "\t" << "2 Tablets per day, Morning & Night, after meal" << "\n" << 1 << "\t" << "1 Tablet per day, before sleep" << "\n" << "8, Jalan Kontraktor U1/14, Seksyen u1, 40150 Shah Slam, Selangor" << "\n\n"
//				<< 3 << "\n" << "Teh Houng Wei" << "\n" << "24/03/2001" << "\n" << 16 << "\t" << 5 << "\t" << 2021 << "\n" << 5 << "\t" << "2 Tablets per day, Morning & Night, after meal" << "\n" << 1 << "\t" << "1 Tablet per day, before sleep" << "\n" << "6, Jalan Bunga 8A, Bandar Botanic, 41200 Klang, Selangor" << "\n\n"
//				<< 4 << "\n" << "Chai Wen Feng" << "\n" << "29/03/2001" << "\n" << 21 << "\t" << 5 << "\t" << 2021 << "\n" << 1 << "\t" << "1 Tablet per day, Morning, after meal" << "\n" << 2 << "\t" << "2 Tablets per day, after lunch, before sleep" << "\n" << "7, Jalan SS 25/22, Taman Mayang, 47301 Petaling Jaya, Selangor" << "\n\n"
//				<< 5 << "\n" << "Lim Theng Yuen" << "\n" << "14/09/2001" << "\n" << 15 << "\t" << 5 << "\t" << 2021 << "\n" << 1 << "\t" << "1 Tablet per day, Morning, after meal" << "\n" << 2 << "\t" << "1 Tablet per day, before sleep" << "\n" << "12, Jalan Emas 8A, Bandar Bukit Tinggi, 41200 Klang, Selangor";
//		}
//		else
//			cerr << "Cannot create file...Contact 0131008@kdu-online.com for debugging.";
//
//		filewrite.close();
//	}
//	filecheck.close();
//}
//
////calculate total number of patients in file
//int sizeFile() 
//{
//	int id, apptDay, apptMonth, apptYear;
//	string name, birth, address;
//
//	int amtVitC, amtVitB;
//	string labelVitC, labelVitB;
//
//	int counter = 0;
//
//	ifstream fileread("patient.txt", ios::in);
//	if (fileread.is_open())
//	{
//		while (!fileread.eof())
//		{
//			fileread >> id;
//			fileread.ignore();
//			getline(fileread, name);
//			fileread >> birth >> apptDay >> apptMonth >> apptYear >> amtVitC;
//			fileread.ignore();
//			getline(fileread, labelVitC);
//			fileread >> amtVitB;
//			fileread.ignore();
//			getline(fileread, labelVitB);
//			fileread.ignore();
//			getline(fileread, address);
//
//			counter++;
//		}
//	}
//	else
//		cerr << "File is not found.. Contact 0131008@kdu-online.com for debugging.\n";
//	fileread.close();
//
//	return counter;
//}
//
////extract patient infos from file to buffer
//void extractFile(Patient readPatient[]) 
//{
//	ifstream fileread("patient.txt", ios::in);
//	if (fileread.is_open())
//	{
//		int i = 0;
//		while (!fileread.eof())
//		{
//			fileread >> readPatient[i].id;
//			fileread.ignore();
//			getline(fileread, readPatient[i].name);
//			fileread >> readPatient[i].birth >> readPatient[i].apptDay >> readPatient[i].apptMonth >> readPatient[i].apptYear >> readPatient[i].amtVitC;
//			fileread.ignore();
//			getline(fileread, readPatient[i].labelVitC);
//			fileread >> readPatient[i].amtVitB;
//			fileread.ignore();
//			getline(fileread, readPatient[i].labelVitB);
//			getline(fileread, readPatient[i].address);
//
//			i++;
//		}
//	}
//	else
//		cerr << "File is not found.. Contact 0131008@kdu-online.com for debugging.\n";
//	fileread.close();
//}
//
//void writeFile(int size, Patient writePatient[], int patId) //write updated datas to file
//{
//	int i;
//
//	ofstream filewrite("patient.txt", ios::out, ios::trunc);
//	if (filewrite.is_open())
//	{
//		for (i = 0; i < size; i++)
//		{
//			defineUpdatedValue(writePatient, i);
//			filewrite << writePatient[i].id << "\n"
//				<< writePatient[i].name << "\n"
//				<< writePatient[i].birth << "\n"
//				<< writePatient[i].n_apptDay << "\t" << writePatient[i].n_apptMonth << "\t" << writePatient[i].n_apptYear << "\n"
//				<< writePatient[i].namtVitC << "\t" << writePatient[i].nlabelVitC << "\n"
//				<< writePatient[i].namtVitB << "\t" << writePatient[i].nlabelVitB << "\n";
//
//			//while writing the last line of data, to avoid reading extra lines while calculating total patient numbers, no new line is needed
//			(i < size - 1) ? filewrite << writePatient[i].address << "\n\n" : filewrite << writePatient[i].address;
//		}
//	}
//	else
//		cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
//	filewrite.close();
//}
//
///*-------------------------------------------------------------------------------------------------------------------------------*/
//
//void receptionistUI(tm* localtm, Patient patientInfo[], Hospital hospitalInfo[], int& pat_id, int& hos_id, string& drName)
//{
//	bool flagError = true;
//
//	cout << "======================\n"
//		<< "Receptionist Interface\n"
//		<< "======================" << endl;
//
//	//display system time
//	cout << "Date: " << localtm->tm_mday << "/" << 1 + localtm->tm_mon << "/" << 1900 + localtm->tm_year << endl;
//	cout << "Time: " << localtm->tm_hour << ":" << localtm->tm_min << ":" << localtm->tm_sec << '\n' << endl;
//
//	//take registration number (with error checking)
//	do
//	{
//		if (flagError)
//			cout << "Enter Patient ID: ";
//		else
//		{
//			cerr << "ID does not exists. Enter another ID: ";
//			flagError = true;
//		}
//		cin >> pat_id;
//		clrError();
//		flagError = false;
//	} while (pat_id > sizeFile() || !pat_id);
//
//	//define appointment hospital; Patient with odd id = Columbia; Patient with even id = Sunway
//	(pat_id % 2 != 0) ? hos_id = 0 : hos_id = 1;
//
//	//reset patient id for array to capture accurate value
//	pat_id--;
//
//	//define available doctor for the appointment date; Odd day = doctor 1; Even day = doctor 2
//	(patientInfo[pat_id].apptDay % 2 != 0) ? drName = hospitalInfo[hos_id].doctor1 : drName = hospitalInfo[hos_id].doctor2;
//
//	//output patient particulars
//	cout << "\nPatient ID      : " << patientInfo[pat_id].id << "\n\n"
//		<< "Patient Name    : " << patientInfo[pat_id].name << "\n\n"
//		<< "Birth Date      : " << patientInfo[pat_id].birth << "\n\n"
//		<< "Hospital        : " << hospitalInfo[hos_id].institution << "\n\n"
//		<< "Patient Address : " << patientInfo[pat_id].address << "\n\n"
//		<< "Appointment Date: " << setfill('0') << setw(2) << patientInfo[pat_id].apptDay << "/" << setw(2) << patientInfo[pat_id].apptMonth << "/" << patientInfo[pat_id].apptYear << "  "
//		<< "[Doctor " << drName << " is available for the appointment date]\n\n"
//		<< " Patient Prescription & Labels\n"
//		<< "------------------------------------------------------------------\n"
//		<< " " << patientInfo[pat_id].amtVitC << " x Vitamin C" << " - " << patientInfo[pat_id].labelVitC << "\n"
//		<< " " << patientInfo[pat_id].amtVitB << " x Vitamin B" << " - " << patientInfo[pat_id].labelVitB << "\n"
//		<< "------------------------------------------------------------------\n\n"
//		<< endl;
//}
//
//void doctorUI(Patient patientInfo[], Hospital hospitalInfo[], int pat_id, int hos_id, string drName)
//{
//	char modifyChoice, modifyOpt, dummy, confirm = 'X';
//	bool flag = true, errorCheck = true;
//
//	cout << "================\n"
//		<< "Doctor Interface\n"
//		<< "================\n" << endl;
//
//	if (pat_id == -1)
//	{
//		cerr << "Improper Operation. Please Call in a Patient First.\n\n" << endl;
//		return;
//	}
//	else
//		cout << "Patient ID  : " << patientInfo[pat_id].id << "\t\t\t" << "Doctor  : " << drName << "\n"
//		<< "Patient Name: " << patientInfo[pat_id].name << "\t" << "Hospital: " << hospitalInfo[hos_id].institution << "\n"
//		<< endl;
//
//	//output patient previous prescription
//	cout << " Previous Precription\n"
//		<< "----------------------\n"
//		<< " " << patientInfo[pat_id].amtVitC << " x Bottle Vitamin C\n"
//		<< " " << patientInfo[pat_id].amtVitB << " x Bottle Vitamin B\n"
//		<< "----------------------\n" << endl;
//
//	//ask if want to modify or remain the prescription
//	cout << "Doctor " << drName << ", do you wish to modify the prescription?\n"
//		<< "Enter (Y for Yes / Else for No): ";
//	cin >> modifyChoice;
//	clrError();
//
//	//modify precsription (with error checking)
//	if (toupper(modifyChoice) == 'Y')
//	{
//		cout << "\nC - Modify Vitamin C\nB - Modify Vitamin B\nE - Stop Modifying" << endl;
//		do
//		{
//			if (errorCheck)
//				cout << "\nSelect Option (C / B / E): ";
//			else
//			{
//				cerr << "Error. Enter Only (C / B / E): ";
//				errorCheck = true;
//			}
//			cin >> modifyOpt;
//			clrError();
//
//			switch (toupper(modifyOpt))
//			{
//			case 'C':
//				cout << "Enter an integer to modify the bottle amount of Vitamin C: ";
//				cin >> patientInfo[pat_id].namtVitC;
//				while (!patientInfo[pat_id].namtVitC)
//				{
//					clrError();
//					cerr << "Error. Plase enter only integer: ";
//					cin >> patientInfo[pat_id].namtVitC;
//				}
//				break;
//			case 'B':
//				cout << "Enter an integer to modify the bottle amount of Vitamin B: ";
//				cin >> patientInfo[pat_id].namtVitB;
//				while (!patientInfo[pat_id].namtVitB)
//				{
//					clrError();
//					cerr << "Error. Plase enter only integer: ";
//					cin >> patientInfo[pat_id].namtVitB;
//				}
//				break;
//			case 'E':
//				defineUpdatedValue(patientInfo, pat_id);
//				cout << "\n\nPlease Confirm Updated Data\n";
//				cout << "---------------------------------\n"
//					<< "Vitamin C - " << patientInfo[pat_id].amtVitC << " Bottle => " << patientInfo[pat_id].namtVitC << " Bottle\n"
//					<< "Vitamin B - " << patientInfo[pat_id].amtVitB << " Bottle => " << patientInfo[pat_id].namtVitB << " Bottle\n"
//					<< "---------------------------------\n"
//					<< "Confirm Update? (Y for Yes / Else for No): ";
//				cin >> confirm;
//				clrError();
//				break;
//			default:
//				errorCheck = false;
//				continue;
//			}
//		} while (toupper(confirm) != 'Y');
//
//		//output updated prescription
//		cout << "\n\nPrecription Successfully Updated\n"
//			<< "----------------------\n"
//			<< "Vitamin C - " << patientInfo[pat_id].namtVitC << " Bottle\n"
//			<< "Vitamin B - " << patientInfo[pat_id].namtVitB << " Bottle\n"
//			<< "----------------------\n" << endl;
//	}
//	else
//		cout << "\n\nPrecsription is Not Updated.\n" << endl;
//
//	cout << "==================== Update New Appointment Date ====================" << endl;
//
//	bool day, month, year;
//
//	//take new appointment date
//	do
//	{
//		day = month = year = false;
//		cout << "\nEnter a New Appointment Date (eg.15/3/2001): ";
//		cin >> patientInfo[pat_id].n_apptDay >> dummy >> patientInfo[pat_id].n_apptMonth >> dummy >> patientInfo[pat_id].n_apptYear;
//		clrError();
//
//		checkDate(patientInfo, pat_id, day, month, year);
//
//		while (day == false || month == false || year == false)
//		{
//			day = month = year = false;
//			cerr << "Invalid Date. Enter another One: ";
//			cin >> patientInfo[pat_id].n_apptDay >> dummy >> patientInfo[pat_id].n_apptMonth >> dummy >> patientInfo[pat_id].n_apptYear;
//			clrError();
//			checkDate(patientInfo, pat_id, day, month, year);
//		}
//
//		cout << "Confirm Update? (Y for Yes / Else for No): ";
//		cin >> confirm;
//		clrError();
//	} while (toupper(confirm) != 'Y');
//
//	cout << "\n\nSuccessfully Updated.\n"
//		<< "New Appointment Date: " << patientInfo[pat_id].n_apptDay << "/" << patientInfo[pat_id].n_apptMonth << "/" << patientInfo[pat_id].n_apptYear << "\n\n" << endl;
//}
//
//void pharmacistUI(Patient patientInfo[], int pat_id)
//{
//	char labelChange, changeOpt, confirm = 'X';
//	bool errorFlag = true;
//
//	cout << "====================\n"
//		<< "Pharmacist Interface\n"
//		<< "====================\n" << endl;
//
//	//check if user follow SOP
//	if (pat_id == -1)
//	{
//		cerr << "Improper Operation. Please Call in a Patient First.\n\n" << endl;
//		return;
//	}
//	else
//		cout << "Patient ID  : " << patientInfo[pat_id].id << "\n" << "Patient Name: " << patientInfo[pat_id].name << "\n" << endl;
//
//	//output patient previous prescription list & labels
//	cout << " Previous Prescription Labels\n"
//		<< "------------------------------------------------------------------\n"
//		<< " " << patientInfo[pat_id].amtVitC << " x Bottle Vitamin C - " << patientInfo[pat_id].labelVitC << "\n"
//		<< " " << patientInfo[pat_id].amtVitB << " x Bottle Vitamin B - " << patientInfo[pat_id].labelVitB << "\n"
//		<< "------------------------------------------------------------------\n" << endl;
//
//	cout << "Do you wish to update either one of the labels?\n"
//		<< "Enter (Y for Yes / Else for No): ";
//	cin >> labelChange;
//	clrError();
//
//	//modify specific prescription labels (with error checking)
//	if (toupper(labelChange) == 'Y')
//	{
//		cout << "\nC - Modify Vitamin C's Label\nB - Modify Vitamin B's Label\nE - Stop Modifying" << endl;
//		do
//		{
//			if (errorFlag)
//				cout << "\nSelect Option (C / B / E): ";
//			else
//			{
//				cerr << "Error. Enter Only (C / B / E): ";
//				errorFlag = true;
//			}
//			cin >> changeOpt;
//			clrError();
//
//			switch (toupper(changeOpt))
//			{
//			case 'C':
//				cout << "Enter new Vitamin C's Label: ";
//				getline(cin, patientInfo[pat_id].nlabelVitC);
//				break;
//			case 'B':
//				cout << "Enter new Vitamin B's Label: ";
//				getline(cin, patientInfo[pat_id].nlabelVitB);
//				break;
//			case 'E':
//				defineUpdatedValue(patientInfo, pat_id);
//				cout << "\n\nPlease Confirm Updated Data\n";
//				cout << "------------------------------------------------------------------\n"
//					<< "Vitamin C - " << patientInfo[pat_id].labelVitC << "\n"
//					<< "         => " << patientInfo[pat_id].nlabelVitC << "\n\n"
//					<< "Vitamin B - " << patientInfo[pat_id].labelVitB << "\n"
//					<< "         => " << patientInfo[pat_id].nlabelVitB << "\n"
//					<< "------------------------------------------------------------------\n"
//					<< "Confirm Update? (Y for Yes / Else for No): ";
//				cin >> confirm;
//				clrError();
//				break;
//			default:
//				errorFlag = false;
//				continue;
//			}
//		} while (toupper(confirm) != 'Y');
//
//
//		//output updated prescription labels
//		cout << "\n\nPrescription Label Successfully Updated\n"
//			<< "------------------------------------------------------------------\n"
//			<< " " << patientInfo[pat_id].namtVitC << " x Bottle Vitamin C - " << patientInfo[pat_id].nlabelVitC << "\n"
//			<< " " << patientInfo[pat_id].namtVitB << " x Bottle Vitamin B - " << patientInfo[pat_id].nlabelVitB << "\n"
//			<< "------------------------------------------------------------------\n\n" << endl;
//	}
//	else
//		cout << "\nPrescription's Label is not Updated.\n\n" << endl;
//}
//
///*-------------------------------------------------------------------------------------------------------------------------------*/
//
//void invoice(tm* localtime, double priceVC, double priceVB, Patient patientList[], int patId)
//{
//	defineUpdatedValue(patientList, patId);
//
//	cout << setfill('-') << setw(80) << "\n"
//		<< setfill(' ') << setw(45) << "Invoice\n"
//		<< setfill('-') << setw(80) << "\n"
//		<< setfill('=') << setw(80) << "\n"
//		<< left << setfill(' ') << setw(6) << "| QTY" << setw(33) << "| Medicine Name" << setw(21) << "| Unit Price(RM)" << setw(18) << "| Amount(RM)" << "|\n"
//		<< right << setfill('=') << setw(80) << "\n"
//		<< "|  " << left << setfill(' ') << setw(3) << patientList[patId].namtVitC << setw(33) << "| Vitamin C" << "|" << right << setw(19) << fixed << setprecision(2) << priceVC << " | " << setw(15) << priceVC * patientList[patId].namtVitC << " |\n"
//		<< "|  " << left << setw(3) << patientList[patId].namtVitB << setw(33) << "| Vitamin B" << "|" << right << setw(19) << priceVB << " | " << setw(15) << priceVB * patientList[patId].namtVitB << " |\n"
//		<< setfill('=') << setw(80) << "\n"
//		<< left << setfill(' ') << setw(30) << "|" << setw(30) << "TOTAL AMOUNT" << "| RM" << right << setw(13) << priceVC * patientList[patId].namtVitC + priceVB * patientList[patId].namtVitB << " |\n"
//		<< setfill('=') << setw(81) << "\n\n"
//		<< localtime->tm_mday << "/" << 1 + localtime->tm_mon << "/" << 1900 + localtime->tm_year << "  "
//		<< localtime->tm_hour << ":" << localtime->tm_min << ":" << localtime->tm_sec << "\n\n"
//		<< endl;
//}
//
//void receipt(tm* localtime, Patient patientList[], Hospital hospitalList[], int patId, int hosId, string dr, double priceVC, double priceVB)
//{
//	defineUpdatedValue(patientList, patId);
//
//	cout << setfill('-') << setw(80) << "\n"
//		<< setfill(' ') << setw(45) << "Receipt\n"
//		<< setfill('-') << setw(80) << "\n"
//		<< "Patient ID  : " << left << setfill(' ') << setw(30) << patientList[patId].id << "Dcotor Incharge      : " << dr << "\n"
//		<< "Patient Name: " << setw(30) << patientList[patId].name << "Next Appointment Date: " << right << setfill('0') << setw(2) << patientList[patId].n_apptDay << "/" << setw(2) << patientList[patId].n_apptMonth << "/" << patientList[patId].n_apptYear << "\n"
//		<< "\nPatient Address: " << patientList[patId].address << "\n\n"
//		<< setfill('=') << setw(80) << "\n"
//		<< left << setfill(' ') << setw(6) << "| QTY" << setw(33) << "| Medicine Name" << setw(21) << "| Unit Price(RM)" << setw(18) << "| Amount(RM)" << "|\n"
//		<< right << setfill('=') << setw(80) << "\n"
//		<< left << setfill(' ') << "|  " << setw(3) << patientList[patId].namtVitC << setw(33) << "| Vitamin C" << "|" << right << setw(19) << fixed << setprecision(2) << priceVC << " | " << setw(15) << priceVC * patientList[patId].namtVitC << " |\n"
//		<< "|  " << left << setw(3) << patientList[patId].namtVitB << setw(33) << "| Vitamin B" << "|" << right << setw(19) << priceVB << " | " << setw(15) << priceVB * patientList[patId].namtVitB << " |\n"
//		<< setfill('=') << setw(80) << "\n"
//		<< left << setfill(' ') << setw(30) << "|" << setw(30) << "TOTAL AMOUNT" << "| RM" << right << setw(13) << priceVC * patientList[patId].namtVitC + priceVB * patientList[patId].namtVitB << " |\n"
//		<< setfill('=') << setw(81) << "\n\n"
//		<< setfill(' ') << setw(53) << "-IMPORTANT MEDICINE USAGE-\n"
//		<< setfill('-') << setw(80) << "\n"
//		<< "   Vitamin C - " << left << setfill(' ') << setw(63) << patientList[patId].nlabelVitC << " \n"
//		<< "   Vitamin B - " << setw(63) << patientList[patId].nlabelVitB << " \n"
//		<< right << setfill('-') << setw(81) << "\n\n"
//		<< localtime->tm_mday << "/" << 1 + localtime->tm_mon << "/" << 1900 + localtime->tm_year << "  "
//		<< localtime->tm_hour << ":" << localtime->tm_min << ":" << localtime->tm_sec << '\n'
//		<< hospitalList[hosId].institution << "\n"
//		<< "Online Hospital System v.01" << "\n"
//		<< endl;
//}
//
//void payment(tm* localtm, Patient patientInfo[], Hospital hospitalInfo[], int pat_id, int hos_id, string drName)
//{
//	int payMethod, getch();
//	double priceVitC = 6.50;
//	double priceVitB = 8.00;
//
//	cout << "=================\n"
//		<< "Payment Interface\n"
//		<< "=================\n" << endl;
//
//	cout << "1 - Online Banking Transaction\n"
//		<< "2 - Cash On Delivery\n"
//		<< "\nSelect Payment Method: ";
//	cin >> payMethod;
//	clrError();
//
//	while (payMethod != 1 && payMethod != 2)
//	{
//		cerr << "Enter only 1 or 2: ";
//		cin >> payMethod;
//		clrError();
//	}
//
//	cout << "\n\n";
//
//	if (payMethod == 1)
//	{
//		invoice(localtm, priceVitC, priceVitB, patientInfo, pat_id);
//		cout << "Press any key to proceed with the Payment...\n";
//		getch();
//		cout << "Payment Successfull. Enclosed here with the receipt.\n\n";
//		receipt(localtm, patientInfo, hospitalInfo, pat_id, hos_id, drName, priceVitC, priceVitB);
//	}
//	else
//	{
//		cout << "Transaction Successfull. Enclosed here with the Receipt.\n\n";
//		receipt(localtm, patientInfo, hospitalInfo, pat_id, hos_id, drName, priceVitC, priceVitB);
//	}
//}
//
///*-------------------------------------------------------------------------------------------------------------------------------*/
//
//bool buildMenu(bool flagCont, tm* lctime, Patient patientFile[], Hospital hospitalFile[], int& patID, int& hosID, string& doctorName)
//{
//	char user;
//	bool falgError = true;
//
//	cout << "====================================================\n"
//		<< "Online Hospital System v.01 by Liaw Yi Kai - 0131008\n"
//		<< "====================================================\n" << endl;
//
//	cout << "R - Receptionist \nD - Doctor \nP - Pharmacist\nE - Save Data and Exit Program\n\n"
//		<< "Select Position (R / D / P / E): ";
//	cin >> user;
//
//	user = toupper(user);
//	while (user != 'R' && user != 'D' && user != 'P' && user != 'E')
//	{
//		clrError();
//		cerr << "Enter Only (R / D / P / E): ";
//		cin >> user;
//		user = toupper(user);
//	}
//
//	system("cls");
//
//	switch (user)
//	{
//	case 'R':
//		receptionistUI(lctime, patientFile, hospitalFile, patID, hosID, doctorName);
//		clrScreen();
//		break;
//	case 'D':
//		doctorUI(patientFile, hospitalFile, patID, hosID, doctorName);
//		clrScreen();
//		break;
//	case 'P':
//		pharmacistUI(patientFile, patID);
//		if (patID == -1)
//		{
//			clrScreen();
//			break;
//		}
//		system("pause");
//		system("cls");
//		payment(lctime, patientFile, hospitalFile, patID, hosID, doctorName);
//		clrScreen();
//		break;
//	case'E':
//		(patID == -1) ? cout << "No Data is Updated. Program Exiting..." : cout << "Data Succesfully Updated. Program Exiting...";
//		cout << "\n\n";
//		flagCont = false;
//		break;
//	}
//	return flagCont;
//}
//
//int main()
//{
//	//declare and use system local time, learned & adapted from: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
//	time_t now = time(0);
//	tm* ltm = localtime(&now);
//
//	createFile(); //create a patient.txt file in pc's hard disk
//
//	/*Dynamic array learned from: https://www.dummies.com/programming/cpp/using-a-dynamic-array-with-a-structure/ */
//	int sizeP = sizeFile();
//	Patient* listpatient = new Patient[sizeP];
//
//	//extract data from file into buffer
//	extractFile(listpatient);
//
//	//assign hospital & doctor informations
//	Hospital listhospital[2]
//		= { {"Columbia Asia Hospital", "Chua", "Shermaine Ho"},
//			{"Sunway Medical Centre", "Bernard Lee", "Ooi"} };
//
//	bool flagCont = true;
//
//	//variables are declared and passed from main() to avoid error while passing values through switch statement under buildMenu();
//	int patientID = -1, hospitalID = -1;
//	string doctor;
//
//	//loop for main menu
//	while (flagCont)
//		flagCont = buildMenu(flagCont, ltm, listpatient, listhospital, patientID, hospitalID, doctor);
//
//	//modify file data everytime before program exits
//	writeFile(sizeP, listpatient, patientID);
//
//	//free up memory used by listpatient to avoid memory leak
//	delete[] listpatient;
//
//	return 0;
//}
//
//
//
////pass parameter by reference learned from: https://www.learncpp.com/cpp-tutorial/passing-arguments-by-reference/
//
////setw(), setfill() learned from: https://www.geeksforgeeks.org/stdsetbase-stdsetw-stdsetfill-in-cpp/
//
////use of file learned and adapted from: https://www.cplusplus.com/doc/tutorial/files/ and 
////										https://www.youtube.com/watch?v=lU9y_bwjNjs&t=1732s and 
////										https://www.youtube.com/watch?v=xNJLe3m03Y4&t=2742s