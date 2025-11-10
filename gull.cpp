#include<iostream>
#include<string>
using namespace std;
class employee {
private:
	string Name;
	int Id;
	int Salary;
	//static and const members
	static int count;
	static const string company_name;
public:
	//constructor initializer list
	employee(string n, int i, int s) :Name(n), Id(i), Salary(s) {
		count++;
	}
	//copy constructor
	employee(const employee& e) {
		Name = e.Name;
		Id = e.Id;
		Salary = e.Salary;
		count++;
	}
	//const function to display information of employees
	void display()const {
		cout << " Company :" << company_name << endl;
		cout << " Name :" <<Name << endl;
		cout << " Employee ID :" <<Id << endl;
		cout << " Salary :" << Salary<< endl;
		cout << "                                    " << endl;
	}
	//function to update employee salary
	void update_salary(int Salary) {
		this->Salary = Salary;
	}
	//static function to sow total employees
	static void show_count() {
		cout << "Total Employees :" << count << endl;
	}
	//returning of object
	employee get_copy() {
		return *this;
	}
	~employee() {  //destructor
		count--;
	}
};
//static members initialization
int employee::count = 0;
const string employee::company_name = "Tech Solutions";
void show_employee(employee e) {
	cout << "Employee passed to function" << endl;
	e.display();
}
int main() {
	employee* e1 = new employee("Ahmed", 103, 55000);  //dynamic allocation
	e1->display();
	employee e2("Fatima", 105, 60000);
	e2.display();
	//return object to function
	employee e3 = e2.get_copy();
	cout << "Copy returned of e2 :" << endl;
	e3.display();
	//copy constructor implementation
	employee e4 = e2;
	cout << " Original is e2" << endl;
	e2.display();
	cout << "Copy of e4" << endl;
	e4.display();
	cout << " Modifying Employee Salary to 80000" << endl;
	e2.update_salary(80000);
	cout << "After Modification :" << endl;
	e2.display();
	cout << "e4 remains unchanged :" << endl;
	e4.display();
	//shallow and deep copy
	cout << "          Deep and shallow copy         " << endl;
	string name1 = " Ali";
	string name2 = name1;
	name1 = " Changed";
	cout << "Name 1 :" << name1 << endl;
	cout << "Name 2  which is unchanged:" << name2 << endl;
	cout << endl;
	employee::show_count();
	// deleting dynamically created object
	delete e1;
	employee::show_count();
	return 0;
}
