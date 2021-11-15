//#include<iostream>
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<vector>
//#include<iomanip>
//#include<conio.h>
//using namespace std;
//
//struct Employee
//{
//	vector<int> id;
//	vector<string> name, email, password;
//};
//struct Storage
//{
//	vector <string> title, description, sku, vendor, type, added;
//	vector <vector <string>> variants;
//	vector <double> cost, price;
//	vector <int> quantity;
//};
//
//void activityLog(int printLog, Storage productData)
//{
//	//activityLog(0, productData, true, title);
//	//activityLog(1, productData, false, "dummy");
//
//	cout << productData.added[0] << "\n";
//	cout << productData.added.size() << "\n";
//
//	if (printLog == 1)
//	{
//		cout << productData.added.size();
//		if (productData.added.size() > 0)
//		{
//			cout << "Added Product\n";
//			for (int i = 0; i < productData.added.size(); i++)
//				cout << productData.added[i] << "\n";
//		}
//	}
//}
//
//int main ()
//{
//	Storage prodData; 
//
//	prodData.added.push_back("Doge Shoes");
//	prodData.added.push_back("Doge Bag");
//	prodData.added.push_back("Doge Pen");
//
//	activityLog(1, prodData);
//
//	cout << prodData.added.size();
//	return 0;
//}