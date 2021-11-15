#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<conio.h>
using namespace std;

struct Employee
{
	vector<int> id;
	vector<string> name, email, password;
};
struct Storage
{
	vector <string> title, description, sku, vendor, type, added;
	vector <vector <string>> variants;
	vector <double> cost, price;
	vector <int> quantity;
};
struct ActivityLog
{
	vector <string> added, edited, deleted;
	vector <string> description, sku, vendor, type;
	vector <string> newTitle, newDescription, newSKU, newVendor, newType;
	vector <double> cost, price;
	vector <double> newCost, newPrice;
	vector <int> quantity;
	vector <int> newQuantity;
	vector <vector <string >> variants;
	vector <vector <string >> newVariants;
};

void clearError()
{
	cin.clear();
	cin.ignore(100, '\n');
}

void clearScreen()
{
	int getch();

	cout << "Press any key to continue...";
	getch(); //read input by user, but doesn't store it at buffer
	system("cls");
}

void hardcodeEmployeeList()
{
	//check is employee list exist in computer
	//is not exist, system hard code some employee details for illustration

	ifstream checkFileExist("Employee_List.csv", ios::in);
	if (!checkFileExist)
	{
		ofstream hardcodeEmpData("Employee_List.csv", ios::out);
		if (hardcodeEmpData.is_open())
		{
			hardcodeEmpData
				<< "Employee ID" << "," << "Employee Name" << "," << "Employee Email" << "," << "Employee Password" << "\n"
				<< 131008 << "," << "Liaw Yi Kai" << "," << "131008@kdu-online.com" << "," << "Lyk12345" << "\n"
				<< 132601 << "," << "Wan Mohammed Adam" << "," << "132601@kdu-online.com" << "," << "Adam12345" << "\n"
				<< 130836 << "," << "Ng Hang Ee" << "," << "130836@kdu-online.com" << "," << "Anson12345" << "\n";
		}
		else
			cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
		hardcodeEmpData.close();
	}
	checkFileExist.close();
}

void extractEmployeeList(Employee& employeeData)
{
	string dummy, temp;

	ifstream readEmpData("Employee_List.csv", ios::in);
	if (readEmpData.is_open())
	{
		getline(readEmpData, dummy);
		while (getline(readEmpData, temp, '\n'))
		{
			stringstream ss(temp);

			getline(ss, temp, ',');
			employeeData.id.push_back(stoi(temp));

			getline(ss, temp, ',');
			employeeData.name.push_back(temp);

			getline(ss, temp, ',');
			employeeData.email.push_back(temp);

			getline(ss, temp, ',');
			employeeData.password.push_back(temp);
		}
	}
	else
		cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
	readEmpData.close();
}

void updateEmployeeList(Employee empData)
{
	int i;

	ofstream writeEmpData("Employee_List.csv", ios::out, ios::trunc);
	if (writeEmpData.is_open())
	{
		writeEmpData << "Employee ID" << "," << "Employee Name" << "," << "Employee Email" << "," << "Employee Password" << "\n";
		for (i = 0; i < empData.id.size(); i++)
		{
			writeEmpData << empData.id[i] << "," << empData.name[i] << "," << empData.email[i] << "," << empData.password[i] << "\n";
		}
	}
	else
		cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
	writeEmpData.close();
}

void clearEmployeeVector(Employee& employeeData)
{
	employeeData.id.clear();
	employeeData.name.clear();
	employeeData.email.clear();
	employeeData.password.clear();
}

void hardcodeStorageList()
{
	//check is storage list exist in computer
	//is not exist, system hard code some employee details for illustration

	ifstream checkFileExist("Storage_List.csv", ios::in);
	if (!checkFileExist)
	{
		ofstream hardcodeData("Storage_List.csv", ios::out);
		if (hardcodeData.is_open())
		{
			hardcodeData
				<< "Titile,Description, Cost, Selling Price, SKU, Quantity, Vendor, Type, Variants\n";
			hardcodeData
				<< "Doge Exclusive T-Shirt" << ","
				<< "The best T-Shirt ever made in the Universe/ Limited Stock!" << ","
				<< "8.99" << ","
				<< "899" << ","
				<< "DGE123456" << ","
				<< "100" << ","
				<< "Louis Vuitton" << ","
				<< "T-Shirt" << ","
				<< "S Size/M Size/L Size/" << "\n";
			hardcodeData
				<< "Doge Pencil" << ","
				<< "The best quality 2B pencil/ buy now and test it yourself if you don't believe!" << ","
				<< "1.99" << ","
				<< "199" << ","
				<< "DGE13579" << ","
				<< "298" << ","
				<< "" << ","
				<< "Pencil" << ","
				<< "Blue/" << "\0";
		}
		else
			cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
		hardcodeData.close();
	}
	checkFileExist.close();
}

void extractStorageList(Storage& productData)
{
	string dummy, temp;
	vector <string> temp1;

	ifstream readStorageData("Storage_List.csv", ios::in);
	if (readStorageData.is_open())
	{
		int k = 0;
		getline(readStorageData, dummy);
		while (!readStorageData.eof())
		{
			//Title
			getline(readStorageData, temp, ',');
			productData.title.push_back(temp);

			//Description
			getline(readStorageData, temp, ',');
			for (int i = 0; i < temp.length(); i++)
			{
				if (temp[i] == '/')
					temp[i] = ',';
			}
			productData.description.push_back(temp);

			//Cost
			getline(readStorageData, temp, ',');
			productData.cost.push_back(stod(temp));

			//Price
			getline(readStorageData, temp, ',');
			productData.price.push_back(stod(temp));

			//SKU
			getline(readStorageData, temp, ',');
			productData.sku.push_back(temp);

			//Quantity
			getline(readStorageData, temp, ',');
			productData.quantity.push_back(stoi(temp));

			//Vendor
			getline(readStorageData, temp, ',');
			productData.vendor.push_back(temp);

			//Type
			getline(readStorageData, temp, ',');
			productData.type.push_back(temp);

			//Variants		
			getline(readStorageData, temp, '\n');

			if (readStorageData.eof())
				getline(readStorageData, temp, ',');

			stringstream s(temp);
			while (getline(s, temp, '/'))
			{
				temp1.push_back(temp);
			}
			productData.variants.push_back(temp1);
			temp1.clear();

			k++;
		}
	}
	else
		cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
	readStorageData.close();
}

void clearStorageVector(Storage& productData)
{
	productData.title.clear();
	productData.description.clear();
	productData.cost.clear();
	productData.price.clear();
	productData.sku.clear();
	productData.quantity.clear();
	productData.vendor.clear();
	productData.type.clear();
	productData.variants.clear();
}

void printStorageList(Storage productData, int number)
{
	//Output Title & Description
	cout
		<< "[" << productData.title[number] << "]\n\n"
		<< "Description: " << productData.description[number] << "\n";

	//Output Price Section
	cout
		<< "\n\n Price"
		<< "\n" << setfill('-') << setw(37) << "\n"
		<< " Buying Cost  : RM " << fixed << setprecision(2) << productData.cost[number] << "\n\n"
		<< " Selling Price: RM " << fixed << setprecision(2) << productData.price[number]
		<< "\n" << setfill('-') << setw(37) << "\n";

	//Output Inventory Section
	cout
		<< "\n\n Inventory"
		<< "\n" << setfill('-') << setw(37) << "\n"
		<< " Stock Keeping Unit(SKU): " << productData.sku[number] << "\n\n"
		<< " Stock Quantity: " << productData.quantity[number] << "\n\n"
		<< " Product Vendor: " << productData.vendor[number] << "\n\n"
		<< " Product Type  : " << productData.type[number]
		<< "\n" << setfill('-') << setw(37) << "\n";

	//Output Product Variants
	cout
		<< "\n\n Variants"
		<< "\n" << setfill('-') << setw(37) << "\n";
	for (int j = 0; j < productData.variants[number].size(); j++)
	{
		if (productData.variants[number][j] == "-")
		{
			cout << "N/A";
			break;
		}
		else
			cout << " Variant [" << j + 1 << "]: " << productData.variants[number][j] << "\n";
	}
	cout << setfill('-') << setw(37) << "\n";
}

void updateStorageList(Storage prodData)
{
	ofstream writeStorageData("Storage_List.csv", ios::out, ios::trunc);
	if (writeStorageData.is_open())
	{
		writeStorageData
			<< "Titile,Description, Cost, Selling Price, SKU, Quantity, Vendor, Type, Variants\n";

		for (int i = 0; i < prodData.title.size(); i++)
		{
			writeStorageData
				<< prodData.title[i] << ",";

			for (int j = 0; j < prodData.description[i].length(); j++)
			{
				if (prodData.description[i][j] == ',')
					prodData.description[i][j] = '/';
			}
			writeStorageData
				<< prodData.description[i] << ",";

			writeStorageData
				<< prodData.cost[i] << ","
				<< prodData.price[i] << ","
				<< prodData.sku[i] << ","
				<< prodData.quantity[i] << ","
				<< prodData.vendor[i] << ","
				<< prodData.type[i] << ",";

			for (int k = 0; k < prodData.variants[i].size(); k++)
			{
				writeStorageData << prodData.variants[i][k] << "/";
			}
			(i == prodData.title.size() - 1) ? writeStorageData << "\0" : writeStorageData << "\n";
		}
	}
	else
		cerr << "File is not found...Contact 0131008@kdu-online.com for debugging.\n";
	writeStorageData.close();
}

int landingPage()
{
	int option = 0;

	cout << "================================================\n"
		<< " Welcome to T&L Stock Keeping Management System\n"
		<< "================================================\n\n"

		<< " 1 - Register a new account\n"
		<< " 2 - Log in to existing account\n\n"

		<< "Select a number and press enter to continue: ";
	cin >> option;
	clearError();

	while (option != 1 && option != 2)
	{
		cerr << "Select only 1 or 2 and press enter: ";
		cin >> option;
		clearError();
	}

	return option;
}

void registerPage(Employee employeeData)
{
	int empID, length = 0, temp;
	string empLastName, empFirstName, empName, empEmail, empPassword, adminID, adminPassword;
	char confirmRegister;

	cout << "=====================================================================\n"
		<< " T&L Stock Keeping Management System Registraion Page > Admin Log In\n"
		<< "=====================================================================\n\n";

	//Prompt admin to log in before register a new account
	cout << "*Enter -1 to return to main page*\n\n";
	cout << "Enter Admin ID: ";
	getline(cin, adminID);
	while (adminID != "A16899")
	{
		if (adminID == "-1")
			return;
		else
		{
			cerr << "\nError ID. Please enter the correct ID: ";
			getline(cin, adminID);
		}
	}

	//check if admin password is correct
	cout << "Enter Password: ";
	getline(cin, adminPassword);
	while (adminPassword != "Admin12345")
	{
		if (adminPassword == "-1")
			return;
		else
		{
			cout << "\nWrong Password. Please enter the corerct password: ";
			getline(cin, adminPassword);
		}
	}

	if (adminID == "A16899" && adminPassword == "Admin12345")
	{
		system("cls");
		cout << "======================================================\n"
			<< " T&L Stock Keeping Management System Registraion Page\n"
			<< "======================================================\n\n";
	}
		
	//Prompt for user's first name for register new account
	cout << "Enter First Name: ";
	getline(cin, empFirstName);
	while (empFirstName == "")
	{
		cerr << "\nUser must enter his first name! (E.g. John)";
		cout << "\nEnter First Name: ";
		getline(cin, empFirstName);
	}

	//Prompt for user's last name
	cout << "\nEnter Last Name: ";
	getline(cin, empLastName);
	while (empLastName == "")
	{
		cerr << "\nUser must enter his last name! (E.g. Smith)"
			<< "\nEnter Last Name: ";
		getline(cin, empLastName);
	}
	empName = empLastName + " " + empFirstName;

	//Prompt for user's employee id
	cout << "\nEnter Employee ID: ";
	cin >> empID;
	temp = empID;
	while (temp > 0)
	{
		temp /= 10;
		length++;
	}
	clearError();
	while (length != 6)
	{
		length = 0;
		cerr << "\nEmployee ID must be 6 integers!"
			<< "\nEnter Employee ID: ";
		cin >> empID;
		temp = empID;
		while (temp > 0)
		{
			temp /= 10;
			length++;
		}
		clearError();
	}

	//Prompt for user's email
	cout << "\nEnter Employee Email: ";
	getline(cin, empEmail);
	while (empEmail == "")
	{
		cerr << "\nEmployee email cannot be blank!"
			<< "\nEnter Employee Email: ";
		getline(cin, empEmail);
	}

	//Prompt for user's passowrd
	cout << "\nEnter Password: ";
	cin >> empPassword;
	while (!isupper(empPassword[0]))
	{
		cerr << "\nFirst letter of password must be uppercase!"
			<< "\nEnter another passowrd: ";
		cin >> empPassword;
	}

	//Display entered credentials, ask for comfirmation to register account
	cout << "\n\n\nConfirm Register Details\n"
		<< "-------------------------------------"
		<< "\n Employee ID   : " << empID
		<< "\n Employee Name : " << empName
		<< "\n Employee Email: " << empEmail
		<< "\n Password      : " << empPassword
		<< "\n-------------------------------------\n"
		<< "Enter (Y to Confirm / N to Cancel Registration): ";
	cin >> confirmRegister;
	while (toupper(confirmRegister) != 'Y' && toupper(confirmRegister) != 'N')
	{
		cerr << "Enter only Y or N: ";
		cin >> confirmRegister;
		cin.clear();
	}

	//If receive conmfirmation to register account, system store new employee data to excel
	//Else, system return to landing page
	if (toupper(confirmRegister) == 'Y')
	{
		employeeData.id.push_back(empID);
		employeeData.name.push_back(empName);
		employeeData.email.push_back(empEmail);
		employeeData.password.push_back(empPassword);

		updateEmployeeList(employeeData);

		system("cls");
		cout << "Registration Successfull!\n\n";
		clearScreen();
	}
	else
		return;
}

void loginPage(Employee data)
{
	bool checkID = false, checkPW = false;
	int loginID, i, reference;
	string loginPassword;

	cout << "================================================\n"
		<< " T&L Stock Keeping Management System Login Page\n"
		<< "================================================\n\n";

	while (!checkID)
	{
		cout << "Enter Employee ID: ";
		cin >> loginID;
		clearError();
		for (i = 0; i < data.id.size(); i++)
		{
			if (loginID == data.id[i])
			{
				reference = i;
				checkID = true;
				continue;
			}
		}
		if (checkID == false)
			cerr << "Employee ID not found, please try again.\n\n";
	}

	while (!checkPW)
	{
		checkPW = true;
		cout << "Enter Password   : ";
		cin >> loginPassword;
		clearError();
		if (loginPassword != data.password[reference])
		{
			cerr << "\nInvalid Password, please try again.\n";
			checkPW = false;
		}
	}
}

void alertMessage(Storage productData)
{
	for (int i = 0; i < productData.title.size(); i++)
	{
		if (productData.quantity[i] < 10)
		{
			cout << "    -ALERT MESSAGE STOCK RUNNING LOW-\n";
			cout << setfill('=') << setw(45) << "\n"
				<< left << setfill(' ')
				<< setw(31) << "|  Product Title" << "| " << "Quantity  |\n"
				<< right << setfill('-') << setw(45) << "\n";
			break;
		}
	}

	for (int i = 0; i < productData.title.size(); i++)
	{
		if (productData.quantity[i] < 10)
			cout << left << setfill(' ')
				 << "|  " << setw(28) << productData.title[i] << "|    " << setw(7) << productData.quantity[i] << "|\n";
	}

	cout << right << setfill('=') << setw(47) << "\n\n\n";
	clearScreen();
}

int homePage()
{
	int option;

	cout << "===============================================\n"
		<< " T&L Stock Keeping Management System Home Page\n"
		<< "===============================================\n\n";

	cout << " 1 - Add New Products\n"
		<< " 2 - Manage Products\n"
		<< " 3 - Generate Reports\n"
		<< " 4 - Log Out\n\n"
		<< "Select a number and press enter to continue: ";
	cin >> option;
	clearError();

	while (option != 1 && option != 2 && option != 3 && option != 4)
	{
		cerr << "Enter only 1 / 2 / 3 / 4: ";
		cin >> option;
		clearError();
	}
	return option;
}

void activityLog(ActivityLog activityRecord)
{
	if ((activityRecord.added.size() <= 0) && (activityRecord.edited.size() <= 0) && (activityRecord.deleted.size() <= 0))
	{
		cout << "No action has been made during this Login session~\n\n";
		return;
	}

	if (activityRecord.added.size() > 0)
	{
		cout << " Product Added"
			<< "\n" << setfill('-') << setw(37) << "\n";
		for (int i = 0; i < activityRecord.added.size(); i++)
		{
			cout << i + 1 << ". " << activityRecord.added[i] << "\n";
		}
		cout << setfill('-') << setw(39) << "\n\n\n";
	}

	if (activityRecord.deleted.size() > 0)
	{
		cout << " Product Deleted"
			<< "\n" << setfill('-') << setw(37) << "\n";
		for (int i = 0; i < activityRecord.deleted.size(); i++)
		{
			cout << i + 1 << ". " << activityRecord.deleted[i] << "\n";
		}
		cout << setfill('-') << setw(39) << "\n\n\n";
	}

	if (activityRecord.edited.size() > 0)
	{
		cout << " Product Edited"
			<< "\n" << setfill('-') << setw(74) << "\n";

		for (int i = 0; i < activityRecord.edited.size(); i++)
		{
			cout << i + 1 << ". " << activityRecord.edited[i] << "\n";

			if (activityRecord.newTitle[i] != "")
				cout << "Title      : " << activityRecord.edited[i] << " -> " << activityRecord.newTitle[i] << "\n";

			if (activityRecord.description[i] != "")
				cout << "Description: " << activityRecord.description[i] << " -> " << activityRecord.newDescription[i] << "\n";

			if (activityRecord.sku[i] != "")
				cout << "SKU        : " << activityRecord.sku[i] << " -> " << activityRecord.newSKU[i] << "\n";

			if (activityRecord.vendor[i] != "")
				cout << "Vendor     : " << activityRecord.vendor[i] << " -> " << activityRecord.newVendor[i] << "\n";

			if (activityRecord.type[i] != "")
				cout << "Type       : " << activityRecord.type[i] << " -> " << activityRecord.newType[i] << "\n";

			if (activityRecord.cost[i] != 0)
				cout << "Cost       : RM" << activityRecord.cost[i] << " -> RM" << activityRecord.newCost[i] << "\n";

			if (activityRecord.price[i] != 0)
				cout << "Price      : RM" << activityRecord.price[i] << " -> RM" << activityRecord.newPrice[i] << "\n";

			if (activityRecord.quantity[i] != 0)
				cout << "Quantity   : " << activityRecord.quantity[i] << " -> " << activityRecord.newQuantity[i] << "\n";

			if (activityRecord.variants[i][0] != "")
			{
				cout << "Variants   : ";
				for (int j = 0; j < activityRecord.variants[i].size(); j++)
				{
					cout << activityRecord.variants[i][j];
					if (j < activityRecord.variants[i].size() - 1)
						cout << " / ";
					else
						cout << " -> ";
				}
				for (int k = 0; k < activityRecord.newVariants[i].size(); k++)
				{
					cout << activityRecord.newVariants[i][k];
					if (k < activityRecord.newVariants[i].size() - 1)
						cout << " / ";
					else
						cout << "\n\n";
				}
			}
		}
		cout << setfill('-') << setw(74) << "\n\n\n";
	}
}

bool addProduct(Storage productData, ActivityLog &activityRecord)
{
	string title, description, sku, vendor, type, temp;
	vector<string> variant;
	double cost, price;
	int quantity, variantNum;
	int addProduct = 0;
	char update, descriptionBlank, skuBlank, vendorBlank;

	cout << "====================================================\n"
		<< " T&L Stock Keeping Management System > Add Products\n"
		<< "====================================================\n\n";

	//Prompt user to input all required data
	cout << " -Enter Details of the Product-\n";

	//TITLE
	cout << "\n Product Title: ";
	getline(cin, title, '\n');
	//Title cannot be blank
	//Prompt error maessage if title is blank
	while (title == "")
	{
		cerr << " Product Title cannot be blank: ";
		getline(cin, title, '\n');
	}

	//DESCRIPTION
	cout << "\n Description  : ";
	getline(cin, description, '\n');
	//Description can be blank
	//Prompt for confirmation to leave description blank
	while (description == "")
	{
		cout << " Are you sure to leave description blank?\n"
			<< " Enter (Y) for Yes / (N) for No: ";
		cin >> descriptionBlank;
		clearError();
		while (toupper(descriptionBlank) != 'Y' && toupper(descriptionBlank) != 'N')
		{
			cerr << " Enter only (Y) or (N): ";
			cin >> descriptionBlank;
			clearError();
		}

		if (toupper(descriptionBlank) == 'Y')
		{
			description = "";
			break;
		}
		else
		{
			cout << " Enter Desciption: ";
			getline(cin, description, '\n');
		}
	}

	//PRICE SECTION
	cout << "\n\n Price";
	cout << "\n" << setfill('-') << setw(37) << "\n";

	//Buuying Cost
	cout << " Buying Cost  : RM ";
	cin >> cost;
	clearError();
	//Cost must be a number
	//Prompt error message if system receives other data type
	while (!cost)
	{
		cerr << " Buying Cost must be a number: RM ";
		cin >> cost;
		clearError();
	}

	//Selling Price
	cout << "\n Selling Price: RM ";
	cin >> price;
	clearError();
	//Price must be a number
	//Prompt error message if system receives other data type
	while (!price)
	{
		cerr << " Selling Price must be a number: RM ";
		cin >> price;
		clearError();
	}
	cout << setfill('-') << setw(37) << "\n";

	//INVENTORY SECTION
	cout << "\n\n Inventory";
	cout << "\n" << setfill('-') << setw(37) << "\n";

	//Stock Keeping Unit
	cout << " Stock Keeping Unit(SKU): ";
	getline(cin, sku, '\n');
	//SKU can be blank
	//Prompt for confirmation to leave SKU blank
	while (sku == "")
	{
		cout << " Are you sure to leave SKU blank?\n"
			<< " Enter (Y) for Yes / (N) for No: ";
		cin >> skuBlank;
		clearError();
		while (toupper(skuBlank) != 'Y' && toupper(skuBlank) != 'N')
		{
			cerr << " Enter only (Y) or (N): ";
			cin >> skuBlank;
			clearError();
		}

		if (toupper(skuBlank) == 'Y')
		{
			sku = "";
			break;
		}
		else
		{
			cout << " Enter SKU: ";
			getline(cin, sku, '\n');
		}
	}

	//Stock Quantity
	cout << "\n Stock Quantity: ";
	cin >> quantity;
	clearError();
	//Price must be an integer
	//Prompt error message if system receives other data type
	while (!quantity)
	{
		cerr << " Quantity must be an integer: ";
		cin >> quantity;
		clearError();
	}

	//Product Vendor
	cout << "\n Product Vendor: ";
	getline(cin, vendor, '\n');
	while (vendor == "")
	{
		cout << " Are you sure to leave Vendor blank?\n"
			<< " Enter (Y) for Yes / (N) for No: ";
		cin >> vendorBlank;
		clearError();
		while (toupper(vendorBlank) != 'Y' && toupper(vendorBlank) != 'N')
		{
			cerr << " Enter only (Y) or (N): ";
			cin >> vendorBlank;
			clearError();
		}

		if (toupper(vendorBlank) == 'Y')
		{
			vendor = "";
			break;
		}
		else
		{
			cout << " Enter Vendor: ";
			getline(cin, vendor, '\n');
		}
	}

	//Product Type
	cout << "\n Product Type  : ";
	getline(cin, type, '\n');
	//Product Type can be blank
	//Prompt for confirmation to leave Pproduct type blank
	while (type == "")
	{
		cerr << "Product Type cannot be blank: ";
		getline(cin, type, '\n');
	}
	cout << setfill('-') << setw(37) << "\n";


	//Variants
	cout << "\n\n Variants";
	cout << "\n" << setfill('-') << setw(37) << "\n";
	cout << " Number of Variants: ";
	cin >> variantNum;
	clearError();
	while (!variantNum)
	{
		cerr << " Number of Variants must be an integer: ";
		cin >> variantNum;
		clearError();
	}
	cout << "\n";
	for (int i = 0; i < variantNum; i++)
	{
		cout << " Variant [" << i + 1 << "] : ";
		getline(cin, temp, '\n');
		variant.push_back(temp);
	}
	cout << setfill('-') << setw(37) << "\n";

	//Prompt User to Confirm and Save Product
	//Or Cancel and return to home page
	cout << "\nEnter (Y) to Save Product / (N) to Cancel and return to Home Page: ";
	cin >> update;
	clearError();
	while (toupper(update) != 'Y' && toupper(update) != 'N')
	{
		cerr << " Enter only (Y) or (N): ";
		cin >> update;
		clearError();
	}

	if (toupper(update) == 'Y')
	{
		//Update Storage Data to buffer
		productData.title.push_back(title);
		productData.description.push_back(description);
		productData.cost.push_back(cost);
		productData.price.push_back(price);
		productData.sku.push_back(sku);
		productData.vendor.push_back(vendor);
		productData.quantity.push_back(quantity);
		productData.type.push_back(type);
		productData.variants.push_back(variant);

		//Record added activity Log
		activityRecord.added.push_back(title);
		
		//Update Storage Data to database
		updateStorageList(productData);

		system("cls");
		cout << "Product Added Successfully!\n\n";

		cout << "Do you want to add another product or return to home page?\n\n"
			<< " 1 - Add another Product\n"
			<< " 2 - Return to Home Page\n\n"
			<< "Select a number and press enter to continue: ";
		cin >> addProduct;
		clearError();
		while (addProduct != 1 and addProduct != 2)
		{
			cerr << "Enter only 1 or 2: ";
			cin >> addProduct;
			clearError();
		}

		if (addProduct == 1)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool editProduct(Storage& productData, int chooseProduct, ActivityLog &activityRecord)
{
	system("cls");

	int editOption = 0;
	string title, description, sku, vendor, type, temp;
	vector <string> variant;
	vector <string> dummy{""};
	char descriptionBlank, skuBlank, vendorBlank, editOther = 'Y', confirmUpdate;
	double cost = 0, price = 0;
	int quantity = 0, variantNum = 0;

	while (toupper(editOther) == 'Y')
	{
		cout << setfill('=') << setw(85) << "\n"
			<< " T&L Stock Keeping Management System > Manage Products > Edit Product > " << productData.title[chooseProduct] << "\n"
			<< setfill('=') << setw(86) << "\n\n";

		cout
			<< " 1 - Title\n"
			<< " 2 - Description\n"
			<< " 3 - Price (Buying Cost / Selling Price)\n"
			<< " 4 - Inventory (SKU / Quantity / Vendor / Type)\n"
			<< " 5 - Variants\n"
			<< " 6 - Back to Last Page\n\n"
			<< "Select a number and press enter: ";
		cin >> editOption;
		clearError();
		while (editOption < 1 || editOption > 6)
		{
			cerr << "Only enter number between 1 - 6: ";
			cin >> editOption;
			clearError();
		}

		if (editOption == 6)
			return true;

		switch (editOption)
		{
			//Edit Title
		case 1:
			cout << "\n" << setfill('-') << setw(37) << "\n";
			cout << "Enter new Product Title: ";
			getline(cin, title, '\n');
			while (title == "")
			{
				cerr << "Product Title cannot be blank: ";
				getline(cin, title, '\n');
			}
			cout << setfill('-') << setw(37) << "\n";
			break;

			//Edit Desctiption
		case 2:
			cout << "\n" << setfill('-') << setw(37) << "\n";
			cout << "Enter new Product Description: ";
			getline(cin, description, '\n');
			while (description == "")
			{
				cout << "\nAre you sure to leave description blank?\n"
					<< "Enter (Y) for Yes / (N) for No: ";
				cin >> descriptionBlank;
				clearError();
				while (toupper(descriptionBlank) != 'Y' && toupper(descriptionBlank) != 'N')
				{
					cerr << "Enter only (Y) or (N): ";
					cin >> descriptionBlank;
					clearError();
				}

				if (toupper(descriptionBlank) == 'Y')
				{
					description = "";
					break;
				}
				else
				{
					cout << "\nEnter Desciption: ";
					getline(cin, description, '\n');
				}
			}
			cout << setfill('-') << setw(37) << "\n";
			break;

			//Edit Price
		case 3:
			//Buying Cost
			cout << "\n" << setfill('-') << setw(37) << "\n";
			cout << "Enter new Buying Cost: RM ";
			cin >> cost;
			clearError();
			while (!cost)
			{
				cerr << "Buying Cost must be a number: RM ";
				cin >> cost;
				clearError();
			}
			//Selling Price
			cout << "\nEnter new Selling Price: RM ";
			cin >> price;
			clearError();
			while (!price)
			{
				cerr << "Selling Price must be a number: RM ";
				cin >> price;
				clearError();
			}
			cout << setfill('-') << setw(37) << "\n";
			break;

			//Edit Inventory
		case 4:
			cout << "\n" << setfill('-') << setw(37) << "\n";
			cout << "Enter new Stock Keeping Unit(SKU): ";
			getline(cin, sku, '\n');
			while (sku == "")
			{
				cout << "Are you sure to leave SKU blank?\n"
					<< "Enter (Y) for Yes / (N) for No: ";
				cin >> skuBlank;
				clearError();
				while (toupper(skuBlank) != 'Y' && toupper(skuBlank) != 'N')
				{
					cerr << "Enter only (Y) or (N): ";
					cin >> skuBlank;
					clearError();
				}

				if (toupper(skuBlank) == 'Y')
				{
					sku = "";
					break;
				}
				else
				{
					cout << "\nEnter SKU: ";
					getline(cin, sku, '\n');
				}
			}
			cout << "\n" << setfill('-') << setw(37) << "\n";

			//Stock Quantity
			cout << "Enter new Stock Quantity: ";
			cin >> quantity;
			clearError();
			while (!quantity)
			{
				cerr << "Quantity must be an integer: ";
				cin >> quantity;
				clearError();
			}
			cout << "\n" << setfill('-') << setw(37) << "\n";

			//Product Vendor
			cout << "Enter new Product Vendor: ";
			getline(cin, vendor, '\n');
			while (vendor == "")
			{
				cout << "Are you sure to leave Vendor blank?\n"
					<< "Enter (Y) for Yes / (N) for No: ";
				cin >> vendorBlank;
				clearError();
				while (toupper(vendorBlank) != 'Y' && toupper(vendorBlank) != 'N')
				{
					cerr << "Enter only (Y) or (N): ";
					cin >> vendorBlank;
					clearError();
				}

				if (toupper(vendorBlank) == 'Y')
				{
					vendor = "";
					break;
				}
				else
				{
					cout << "Enter Vendor: ";
					getline(cin, vendor, '\n');
				}
			}
			cout << "\n" << setfill('-') << setw(37) << "\n";

			//Product Type
			cout << "Enter new Product Type: ";
			getline(cin, type, '\n');
			while (type == "")
			{
				cerr << "Product Type cannot be blank: ";
				getline(cin, type, '\n');
			}
			cout << "\n" << setfill('-') << setw(37) << "\n";
			break;

			//Edit Variants
		default:
			variant.clear();
			cout << "\n" << setfill('-') << setw(37) << "\n";
			cout << "Enter new Number of Variants: ";
			cin >> variantNum;
			clearError();
			while (!variantNum)
			{
				cerr << "\nNumber of Variants must be an integer: ";
				cin >> variantNum;
				clearError();
			}
			cout << "\n";
			for (int i = 0; i < variantNum; i++)
			{
				cout << "New Variant [" << i + 1 << "] : ";
				getline(cin, temp, '\n');
				variant.push_back(temp);
			}
			cout << setfill('-') << setw(37) << "\n";
			break;
		}

		//Promopt user to see if he wants to edit another data
		cout << "\nDo you want to edit other data?\n"
			<< "Enter (Y) for Yes / (N) for No: ";
		cin >> editOther;
		clearError();
		while (toupper(editOther) != 'Y' && toupper(editOther) != 'N')
		{
			cerr << "Enter only (Y) or (N): ";
			cin >> editOther;
			clearError();
		}

		system("cls");
	}

	if (toupper(editOther) == 'N')
	{
		cout << setfill('=') << setw(85) << "\n"
			<< " Doge SKU System > Manage Products > Edit Product > " << productData.title[chooseProduct] << "\n"
			<< setfill('=') << setw(86) << "\n\n";

		cout << "-Confirm Updated Product Details-\n\n";

		//Output Title & Description
		cout << "Product Title: ";
		(title == "") ? cout << productData.title[chooseProduct] << "\n\n" : cout << title << "\n\n";

		cout << "Description  : ";
		(description == "") ? cout << productData.description[chooseProduct] << "\n" : cout << description << "\n";


		//Output Price Section
		cout
			<< "\n\n Price"
			<< "\n" << setfill('-') << setw(37) << "\n";
		cout << " Buying Cost  : RM ";
		(cost == 0) ? cout << fixed << setprecision(2) << productData.cost[chooseProduct] << "\n\n" : cout << fixed << setprecision(2) << cost << "\n\n";

		cout << " Selling Price: RM ";
		(price == 0) ? cout << fixed << setprecision(2) << productData.price[chooseProduct] : cout << fixed << setprecision(2) << price;
		cout << "\n" << setfill('-') << setw(37) << "\n";


		//Output Inventory Section
		cout
			<< "\n\n Inventory"
			<< "\n" << setfill('-') << setw(37) << "\n";

		cout << " Stock Keeping Unit(SKU): ";
		(sku == "") ? cout << productData.sku[chooseProduct] << "\n\n" : cout << sku << "\n\n";

		cout << " Stock Quantity: ";
		(quantity == 0) ? cout << productData.quantity[chooseProduct] << "\n\n" : cout << quantity << "\n\n";

		cout << " Product Vendor: ";
		(vendor == "") ? cout << productData.vendor[chooseProduct] << "\n\n" : cout << vendor << "\n\n";

		cout << " Product Type  : ";
		(type == "") ? cout << productData.type[chooseProduct] : cout << type;

		cout << "\n" << setfill('-') << setw(37) << "\n";


		//Output Product Variants
		cout
			<< "\n\n Variants"
			<< "\n" << setfill('-') << setw(37) << "\n";

		if (variant.size() == 0)
		{
			for (int j = 0; j < productData.variants[chooseProduct].size(); j++)
			{
				if (productData.variants[chooseProduct][j] == "-")
				{
					cout << "N/A";
					break;
				}
				else
				{
					cout << " Variant [" << j + 1 << "]: " << productData.variants[chooseProduct][j] << "\n";
				}
			}
		}
		else
		{
			for (int j = 0; j < variant.size(); j++)
			{
				if (variant[j] == "-")
				{
					cout << "N/A";
					break;
				}
				else
				{
					cout << " Variant [" << j + 1 << "]: " << variant[j] << "\n";
				}
			}
		}

		cout << setfill('-') << setw(37) << "\n";

		//Prompt user to confirm details and update
		cout << "\nDo you want to save product details or discard changes?\n\n"
			<< " Y - Save Product Details\n"
			<< " N - Discard and back to Manage Product\n\n"
			<< "Enter (Y) or (N): ";
		cin >> confirmUpdate;
		clearError();
		while (toupper(confirmUpdate) != 'Y' && toupper(confirmUpdate) != 'N')
		{
			cerr << "Enter only (Y) or (N): ";
			cin >> confirmUpdate;
			clearError();
		}

		//Update product details
		if (toupper(confirmUpdate) == 'Y')
		{
			//Record edited activity Log
			activityRecord.edited.push_back(productData.title[chooseProduct]);

			//Title
			if (!title.empty())
			{
				productData.title[chooseProduct] = title;
				activityRecord.newTitle.push_back(title);
			}
			else
				activityRecord.newTitle.push_back("");

			//Desciption
			if (!description.empty())
			{
				activityRecord.description.push_back(productData.description[chooseProduct]);
				productData.description[chooseProduct] = description;
				activityRecord.newDescription.push_back(description);
			}
			else
			{
				activityRecord.description.push_back("");
				activityRecord.newDescription.push_back("");
			}
			
			//Cost
			if (cost != 0)
			{
				activityRecord.cost.push_back(productData.cost[chooseProduct]);
				productData.cost[chooseProduct] = cost;
				activityRecord.newCost.push_back(cost);
			}
			else
			{
				activityRecord.cost.push_back(0);
				activityRecord.newCost.push_back(0);
			}
			
			//Price
			if (price != 0)
			{
				activityRecord.price.push_back(productData.price[chooseProduct]);
				productData.price[chooseProduct] = price;
				activityRecord.newPrice.push_back(price);
			}
			else
			{
				activityRecord.price.push_back(0);
				activityRecord.newPrice.push_back(0);
			}
			
			//SKU
			if (!sku.empty())
			{
				activityRecord.sku.push_back(productData.sku[chooseProduct]);
				productData.sku[chooseProduct] = sku;
				activityRecord.newSKU.push_back(sku);
			}
			else
			{
				activityRecord.sku.push_back("");
				activityRecord.newSKU.push_back("");
			}
			
			//Quantity
			if (quantity != 0)
			{
				activityRecord.quantity.push_back(productData.quantity[chooseProduct]);
				productData.quantity[chooseProduct] = quantity;
				activityRecord.newQuantity.push_back(quantity);
			}
			else
			{
				activityRecord.quantity.push_back(0);
				activityRecord.newQuantity.push_back(0);
			}
			
			//Vendor
			if (!vendor.empty())
			{
				activityRecord.vendor.push_back(productData.vendor[chooseProduct]);
				productData.vendor[chooseProduct] = vendor;
				activityRecord.newVendor.push_back(vendor);
			}
			else
			{
				activityRecord.vendor.push_back("");
				activityRecord.newVendor.push_back("");
			}
			
			//Type
			if (!type.empty())
			{
				activityRecord.type.push_back(productData.type[chooseProduct]);
				productData.type[chooseProduct] = type;
				activityRecord.newType.push_back(type);
			}
			else
			{
				activityRecord.type.push_back("");
				activityRecord.newType.push_back("");
			}

			//Variant
			if (!variant.empty())
			{
				activityRecord.variants.push_back(productData.variants[chooseProduct]);
				productData.variants[chooseProduct].clear();
				for (int i = 0; i < variant.size(); i++)
				{
					productData.variants[chooseProduct].push_back(variant[i]);
				}
				activityRecord.newVariants.push_back(variant);
			}
			else
			{
				activityRecord.variants.push_back(dummy);
				activityRecord.newVariants.push_back(dummy);
			}

			updateStorageList(productData);

			//Prompt user when product is updated successfully
			system("cls");
			cout << "Product Details Updated Successfully!\n\n";
			clearScreen();
		}
	}
	return false;
}

bool deleteProduct(Storage& productData, int chooseProduct, ActivityLog &activityRecord)
{
	system("cls");
	string temp;
	char confirmDelete;

	cout << "========================================================================\n"
		<< " T&L Stock Keeping Management System > Manage Products > Delete Product\n"
		<< "========================================================================\n\n";

	temp = productData.title[chooseProduct];

	cout << "Are you sure to delete " << '\"' << temp << '\"' << " ?\n\n"
		<< " Y - Confirm Deletion\n"
		<< " N - Cancel and return to Last Page\n\n"
		<< "Enter (Y) or (N) and press enter: ";
	cin >> confirmDelete;
	clearError();
	while (toupper(confirmDelete) != 'Y' && toupper(confirmDelete) != 'N')
	{
		cerr << "Enter only (Y) or (N): ";
		cin >> confirmDelete;
		clearError();
	}

	if (toupper(confirmDelete) == 'N')
		return true;
	else
	{
		//Record deleted activity Log
		activityRecord.deleted.push_back(productData.title[chooseProduct]);

		productData.title.erase(productData.title.begin() + chooseProduct);
		productData.description.erase(productData.description.begin() + chooseProduct);
		productData.cost.erase(productData.cost.begin() + chooseProduct);
		productData.price.erase(productData.price.begin() + chooseProduct);
		productData.sku.erase(productData.sku.begin() + chooseProduct);
		productData.quantity.erase(productData.quantity.begin() + chooseProduct);
		productData.vendor.erase(productData.vendor.begin() + chooseProduct);
		productData.type.erase(productData.type.begin() + chooseProduct);
		productData.variants.erase(productData.variants.begin() + chooseProduct);

		updateStorageList(productData);
	}
	system("cls");
	cout << "Product " << '\"' << temp << '\"' << " has been deleted successfully!\n\n";
	clearScreen();
	return false;
}

void manageProduct(Storage productData, ActivityLog &activityRecord)
{
	int chooseProduct = 0, manageOption;
	bool loopProductList = true;

	while (chooseProduct != -1)
	{
		cout << "=======================================================\n"
			<< " T&L Stock Keeping Management System > Manage Products\n"
			<< "=======================================================\n\n";

		cout
			<< setfill('=') << setw(72) << "\n"
			<< left << setfill(' ') << "| No.| " << setw(26) << "Title" << "| " << setw(16) << "Type" << "| " << setw(17) << "Vendor" << "|" << "\n"
			<< right << setfill('=') << setw(72) << "\n";

		//List out all product
		for (int i = 0; i < productData.title.size(); i++)
		{
			cout << "| " << i + 1 << "  | "
				<< left << setfill(' ')
				<< setw(26) << productData.title[i] << "| "
				<< setw(16) << productData.type[i] << "| ";

			(productData.vendor[i] == "") ? cout << setw(17) << "N/A" << "|" << "\n" : cout << setw(17) << productData.vendor[i] << "|" << "\n";
		}
		cout << right << setfill('=') << setw(72) << "\n";

		//Receive user input (manage which product)
		cout << "\nEnter respective number of product to manage Or (-1) to return to home page.\n\n"
			<< "Select a number: ";
		cin >> chooseProduct;
		clearError();
		if (chooseProduct == -1)
			return;
		while (chooseProduct < productData.title.size() - (productData.title.size() - 1) || chooseProduct > productData.title.size())
		{
			cerr << "\nOnly enter the number for respective products listed on screen! Or (-1) to back to Home Page.\n"
				<< "Select another number: ";
			cin >> chooseProduct;
			clearError();
		}

		loopProductList = true;
		while (loopProductList)
		{
			//List out all details for the selected product
			system("cls");
			printStorageList(productData, chooseProduct - 1);

			//Ask user if he would like to edit or delete the product
			cout << "\nHow would you like to manage the product?\n\n"
				<< " 1 - Edit\n"
				<< " 2 - Delete\n"
				<< " 3 - Back to Manage Product\n\n"
				<< "Select a number and press enter: ";
			cin >> manageOption;
			clearError();
			while (manageOption != 1 && manageOption != 2 && manageOption != 3)
			{
				cerr << "Please enter only 1 or 2 or 3: ";
				cin >> manageOption;
				clearError();
			}

			switch (manageOption)
			{
				// Edit Product
			case 1:
				loopProductList = editProduct(productData, chooseProduct - 1, activityRecord);
				system("cls");
				break;
				//Delete Product
			case 2:
				loopProductList = deleteProduct(productData, chooseProduct - 1, activityRecord);
				system("cls");
				break;
				//Back to manage product list
			case 3:
				loopProductList = false;
				system("cls");
				break;
			}
		}
	}
}

void generateReport(Storage productData)
{
	double overallCost = 0;
	int getch();

	cout << "=======================================================\n"
		<< " T&L Stock Keeping Management System > Generate Report\n"
		<< "=======================================================\n\n";

	cout
		<< setfill('=') << setw(111) << "\n"
		<< left << setfill(' ') << "| No.| "
		<< setw(28) << "Title" << "| "
		<< setw(17) << "Vendor" << "| "
		<< setw(17) << "Buying Cost" << "| "
		<< setw(15) << "Quantity" << "| "
		<< setw(17) << "Total" << "|" << "\n"
		<< right << setfill('=') << setw(111) << "\n";

	//List out all product
	for (int i = 0; i < productData.title.size(); i++)
	{
		cout << "| " << i + 1 << "  | "
			<< left << setfill(' ')
			<< setw(28) << productData.title[i] << "| ";

		(productData.vendor[i] == "") ? cout << setw(17) << "N/A" << "| " : cout << setw(17) << productData.vendor[i] << "| ";

		cout << "RM  " << setw(13) << productData.cost[i] << "| "
			<< setw(15) << productData.quantity[i] << "| "
			<< "RM  " << setw(13) << fixed << setprecision(2) << productData.cost[i] * productData.quantity[i] << "|";

		cout << "\n";

		overallCost += productData.cost[i] * productData.quantity[i];
	}
	cout << right << setfill('=') << setw(112) << "\n\n";

	cout << right << setfill('-') << setw(39) << "\n";
	cout << " Overall Buying Cost: RM " << overallCost << "" << endl;
	cout << right << setfill('-') << setw(40) << "\n\n\n";

	cout << "Press any key to return to Home Page...";
	getch();
}

void logOut(ActivityLog activityRecord)
{
	activityLog(activityRecord);
	clearScreen();

	cout << "You have successfully Logged Out!\n\n";
	clearScreen();
}

void buildMenu(Employee empData, Storage prodData)
{
	bool returnLandingPG = true, addAnotherProduct = true, returnHomePG = true;
	int landingOption, systemFunction;
	ActivityLog activityRecord;

	while (returnLandingPG)
	{
		//Clear activity log data saved in buffer after user logs out
		activityRecord.added.clear();
		activityRecord.edited.clear();
		activityRecord.deleted.clear();
		activityRecord.newTitle.clear();
		activityRecord.cost.clear();
		activityRecord.newCost.clear();
		activityRecord.description.clear();
		activityRecord.newDescription.clear();
		activityRecord.price.clear();
		activityRecord.newPrice.clear();
		activityRecord.quantity.clear();
		activityRecord.newQuantity.clear();
		activityRecord.sku.clear();
		activityRecord.newSKU.clear();
		activityRecord.type.clear();
		activityRecord.newType.clear();
		activityRecord.vendor.clear();
		activityRecord.newVendor.clear();
		activityRecord.variants.clear();
		activityRecord.newVariants.clear();
		activityRecord.type.clear();
		activityRecord.newType.clear();

		landingOption = landingPage();
		system("cls");

		// Register Page
		if (landingOption == 1)
		{
			registerPage(empData);

			//clear employee data in buffer to avoid error while ectracting employee list
			clearEmployeeVector(empData);
			extractEmployeeList(empData);
			system("cls");
			continue;
		}

		//Login Page
		if (landingOption == 2)
		{
			loginPage(empData);
			system("cls");
		}

		//Alert Message after log in if stocks running low
		alertMessage(prodData);

		//Home Page
		returnHomePG = true;
		while (returnHomePG)
		{
			systemFunction = homePage();
			system("cls");

			switch (systemFunction)
			{
				//Add Product
			case 1:
				addAnotherProduct = true;
				while (addAnotherProduct)
				{
					addAnotherProduct = addProduct(prodData, activityRecord);

					//clear storage data in buffer to avoid error while extracting storage list
					clearStorageVector(prodData);
					extractStorageList(prodData);
					system("cls");
				}

				if (!addAnotherProduct)
					continue;
				break;

				//Manage Product
			case 2:
				manageProduct(prodData, activityRecord);

				//clear storage data in buffer to avoid error while extracting storage list
				clearStorageVector(prodData);
				extractStorageList(prodData);
				system("cls");
				break;

				//Generate Report
			case 3:
				generateReport(prodData);
				system("cls");
				break;

				//Log Out
			default:
				logOut(activityRecord);
				returnLandingPG = true;
				returnHomePG = false;
				break;
			}
		}
	}
}

int main()
{
	Employee employeeData;
	Storage storageData;

	hardcodeEmployeeList();
	extractEmployeeList(employeeData);

	hardcodeStorageList();
	extractStorageList(storageData);

	buildMenu(employeeData, storageData);

	return 0;
}