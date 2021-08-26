#include <iostream>
#include <exception>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>

#include "MyException.h"
#include "FileWriting.h"
#include "Person.h"
#include "Test.h"
#include "OverloadingTest.h"
#include "Complex.h"

using namespace std;

//STL
void Vector()
{
	vector<string> strings;

	strings.emplace_back("One");
	strings.emplace_back("Two");
	strings.emplace_back("Three");

	for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it)
	{
		cout << *it << endl;
	}

	vector<string>::iterator it = strings.begin();

	it += 2;

	cout << *it << endl;
}

void VectorAndMemory()
{
	vector<double> numbers(0);

	cout << "Size of vector: " << numbers.size() << endl;

	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; i++)
	{
		if (numbers.capacity() != capacity)
		{
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}
		numbers.push_back(i);
	}

	//Change vector size with resize() and capacity with reserve()
	//Under the hood, a vector just uses an array. The capacity of the vector is the size of that array
	//numbers.clear();
	//numbers.resize(100);
	numbers.reserve(100000);
	cout << numbers[2] << endl;
	cout << "Size of vector: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;
}

void TwoDimensionalVector()
{
	vector<vector<int>> grid(3, vector<int>(4, 7));

	grid[1].push_back(8);

	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t c = 0; c < grid[i].size(); c++)
		{
			cout << grid[i][c] << flush;
		}
		cout << endl;
	}
}

void List()
{
	list<int> numbers{ 1,2,3 };

	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_front(0);

	auto it = numbers.begin();
	++it;
	numbers.insert(it, 100);
	cout << *it << endl;

	auto erase = numbers.begin();
	++erase;
	erase = numbers.erase(erase);
	cout << *erase << endl;

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (*it == 2)
			numbers.insert(it, 1234);


		if (*it == 1)
		{
			it = numbers.erase(it);
			--it;
		}
	}

	cout << endl;
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << endl;
	}
}

void Map()
{
	unordered_map<string, int> ages;
	ages["Mike"] = 40;
	ages["Jennifer"] = 20;
	ages["Vicky"] = 30;

	cout << ages["Jennifer"] << endl;

	ages.insert(pair<string, int>("Peter", 100));
	ages.insert(make_pair("John", 200));

	if (ages.find("Vick") != ages.end())
	{
		cout << "Found Vicky" << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}

	for (unordered_map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}

	cout << endl;

	for (unordered_map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}
}

void CustomObjectMapValue()
{
	unordered_map<int, Person> people;

	people[0] = Person("Mike", 40);
	people[1] = Person("Vicky", 30);
	people[2] = Person("Raj", 20);

	people.insert(make_pair(55, Person("Bob", 45)));
	people.insert(make_pair(55, Person("Sue", 24)));

	for (unordered_map<int, Person>::iterator it = people.begin(); it != people.end(); ++it)
	{
		it->second.Print();
	}
}

void CustomObjectMapKey()
{
	map<Person, int> people;

	people[Person("Mike", 40)] = 40;
	people[Person("Mike", 444)] = 50;
	people[Person("Vicky", 30)] = 30;
	people[Person("Raj", 20)] = 20;

	for (auto it = people.begin(); it != people.end(); ++it)
	{
		cout << it->second << ": " << flush;
		it->first.Print();
		cout << endl;
	}
}

void MultiMap()
{
	unordered_multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(20, "Jennifer"));
	lookup.insert(make_pair(50, "Carly"));
	lookup.insert(make_pair(30, "Carl"));

	for (unordered_multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	for (auto it = lookup.find(20); it != lookup.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	pair<unordered_multimap<int, string>::iterator, unordered_multimap<int, string>::iterator> its = lookup.equal_range(30);


	for (auto it = its.first; it != its.second; ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}
}

void Set()
{
	unordered_set<int> nums;

	nums.insert(50);
	nums.insert(10);
	nums.insert(50);
	nums.insert(30);
	nums.insert(20);

	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		cout << *it << endl;
	}

	unordered_set<int>::iterator itFind = nums.find(50);

	if (itFind != nums.end())
	{
		cout << "Found: " << *itFind << endl;
	}

	if (nums.count(30))
	{
		cout << "Number found" << endl;
	}
}

void StackAndQueue()
{
	//LIFO
	stack<Test> testStack;
	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Carly"));

	cout << endl;

	/* This is invalid code! Object is destroyed
	Test& test1 = testStack.top();
	testStack.pop();
	test1.print(); // Reference refers to destroyed objects
	*/

	while (!testStack.empty())
	{
		Test& test = testStack.top();
		test.print();
		testStack.pop();
	}

	cout << endl;

	//FIFO
	queue<Test> testQueue;
	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Carly"));

	cout << endl;

	/* This is invalid code! Object is destroyed
	Test& test1 = testStack.top();
	testStack.pop();
	test1.print(); // Reference refers to destroyed objects
	*/

	testQueue.back().print();

	while (!testQueue.empty())
	{
		Test& test = testQueue.front();
		test.print();
		testQueue.pop();
	}
}

bool comp(const Test& a, const Test& b)
{
	return a.name < b.name;
}

void SortingShit()
{
	vector<Test> tests;
	tests.emplace_back("Mike", 5);
	tests.emplace_back("Sue", 10);
	tests.emplace_back("Raj", 7);
	tests.emplace_back("Vicky", 3);

	sort(tests.begin(), tests.end(), comp);
	sort(tests.begin(), tests.begin() + 2, comp); // Can do this too

	for (auto& test : tests)
	{
		test.print();
	}
}


//Operator overloading
void OperatorOverloading()
{
	const OverloadingTest test1(10, "Mike");
	test1.print();

	OverloadingTest test2(20, "Bob");

	//Shallow copy
	test2 = test1;
	test2.print();

	OverloadingTest test3;
	//test3 = test2 = test1;

	test3.operator=(test2);
	test3.print();

	cout << endl;
	//Copy initialization
	OverloadingTest test4 = test1;
	test4.print();
}

void LeftBitShift()
{
	OverloadingTest test1(10, "Mike");
	OverloadingTest test2(20, "Bob");
	cout << test1 << test2 << endl;
}

void ComplexNumber()
{
	Complex c1(2, 3);
	Complex c2 = c1;

	Complex c3 = c2;

	cout << c2 << " " << c3 << endl;
}


void OverloadingPlus()
{
	Complex c1(3, 4);
	const Complex c2(2, 3);
	Complex c3 = c1 + c2;

	cout << c1 << endl;

	cout << c3 << endl;

	const Complex c4(4, 2);
	Complex c5 = c4 + 7;

	cout << c5 << endl;
}


//Pointers and Memory
void Manipulate(double* value)
{
	*value = 10.0;
	cout << "Value of double in Manipulate: " << value << endl;
}

void Pointers()
{
	int nVal = 8;
	int* pnVal = &nVal;

	cout << "Int: " << nVal << endl;
	cout << "Pointer to Int address: " << pnVal << endl;
	cout << "Int val via pointer: " << *pnVal << endl;

	cout << endl;

	double dVal = 123.4;

	cout << "1. dVal: " << dVal << endl;
	Manipulate(&dVal);
	cout << "2. dVal: " << dVal << endl;
}

void Arithmetic()
{
	double val1 = static_cast<double>(7) / 2;
	cout << val1 << endl;

	int val2 = static_cast<int>(7.3);
	cout << val2 << endl;
}

void PointerAndArrays()
{
	string texts[] = { "one", "Two", "Three" };

	string* pTexts = texts;

	for (int i = 0; i < sizeof texts / sizeof string; i++)
	{
		cout << pTexts[i] << " " << flush;
	}

	cout << endl;

	for (int i = 0; i < sizeof texts / sizeof string; i++, pTexts++)
	{
		cout << *pTexts << " " << flush;
	}

	cout << endl;

	string* pElement = &texts[0];
	string* pEnd = &texts[2];

	while (true)
	{
		cout << *pElement << " " << flush;

		if (pElement == pEnd)
			break;

		pElement++;
	}
}

void PointerArithmetic()
{
	const int ELEMENTS = 5;

	string texts[ELEMENTS] = { "one", "Two", "Three", "Four", "Five" };
	string* pTexts = texts;

	pTexts += 3;

	cout << *pTexts << endl;

	pTexts -= 2;

	cout << *pTexts << endl;

	cout << endl;

	string* pEnd = &texts[ELEMENTS];
	pTexts = &texts[0];

	while (pTexts != pEnd)
	{
		cout << *pTexts << endl;
		pTexts++;
	}

	cout << endl;

	pTexts = &texts[0];
	const long elements = pEnd - pTexts;

	cout << elements << endl;

	pTexts = &texts[0];
	pTexts += ELEMENTS / 2;

	cout << *pTexts << endl;
}


void CharArrays()
{
	char text[] = "hello";
	const char* name = "Karl";

	cout << name[2] << endl;

	for (size_t i = 0; i < sizeof text; i++)
	{
		cout << i << ": " << text[i] << flush;
	}

	cout << endl;

	int k = 0;
	while (true)
	{
		if (text[k] == 0)
			break;

		cout << text[k] << flush;

		k++;
	}
}

void Reverse()
{
	char text[] = "hello there!";
	const int len = sizeof text - 1;
	char* pStart = text;
	char* pEnd = text + len - 1;

	while (pStart < pEnd)
	{
		const char temp = *pStart;
		*pStart = *pEnd;
		*pEnd = temp;

		pStart++;
		pEnd--;
	}

	cout << text << endl;

	char name[] = "Hello There!";

	const int length = sizeof name - 1;
	for (size_t i = 0, j = length - 1; i < j; i++, j--)
	{
		const char temp = name[i];
		name[i] = name[j];
		name[j] = temp;
	}

	cout << name << endl;
}

void ChangeSomething(double& value)
{
	value = 123.4;
}

void References()
{
	int val1 = 8, & val2 = val1;
	val2 = 10;

	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	double val = 4.321;
	ChangeSomething(val);
	cout << val << endl;
}

//class Animal
//{
//	string name;
//
//public:
//	Animal() { cout << "Animal created" << endl; }
//	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying" << endl; }
//	void SetName(string name) { this->name = std::move(name); }
//	void Speak() const { cout << "My name is: " << this->name << endl; }
//};
//
//void Const()
//{
//	Animal animal;
//	animal.SetName("Freddy");
//	animal.Speak();
//
//	int val = 8;
//	int* pVal = &val; // const int* const pVal = &val; <- to make both const
//
//	cout << *pVal << endl;
//
//	int num = 11;
//	pVal = &num; // int* const pVal = &val; <- make pointer const
//	*pVal = 12; // const int* pVal = &val; <- make int val const
//
//	cout << *pVal << endl;
//}
//
//void CopyConstructors()
//{
//	Animal animal1;
//	animal1.SetName("Freddy");
//
//	Animal animal2 = animal1;
//	animal2.Speak();
//	animal2.SetName("Bob");
//
//	animal1.Speak();
//	animal2.Speak();
//
//	const Animal animal3(animal1);
//	animal3.Speak();
//}


string truncateSentence(string s, const int k) {
	std::size_t start = 0, idx = 0;
	std::string res, delim = " ";

	for (size_t end = 0; (end = s.find(delim, end)) != std::string::npos; ++end, ++idx)
	{
		if (idx == k) break;
		res += idx != (k - 1) ? s.substr(start, end - start) + ' ' : s.substr(start, end - start);
		start = end + 1;
	}

	if (k - idx == 1 && idx != 0)
		res += s.substr(start, k - start);

	return idx == 0 ? s : res;

	//for (int i = 0; i < s.size(); ++i)
	//	if (s[i] == ' ' && --k == 0)
	//		return s.substr(0, i);
	//return s;
}

void Test(int value)
{
	cout << "Hello" << " " << value << endl;
}

void FunctionPointers()
{
	Test(7);

	//The name of the function is a pointer to it so no need to specify reference (&)
	void (*pTest)(int) = Test;

	pTest(7);
}

bool Match(string str)
{
	return str.size() == 3;
}

int CountStrings(vector<string>& texts, bool (*SecondMatch)(string str))
{
	int count = 0;
	for (string& str : texts)
		count += SecondMatch(str) == 1 ? 1 : 0;

	return count;
}

void UsingFunctionPointers()
{
	vector<string> texts;
	texts.emplace_back("one");
	texts.emplace_back("two");
	texts.emplace_back("three");
	texts.emplace_back("two");
	texts.emplace_back("four");
	texts.emplace_back("two");
	texts.emplace_back("three");

	cout << Match("one") << endl;

	cout << count_if(texts.begin(), texts.end(), Match) << endl;

	cout << CountStrings(texts, Match) << endl;
}

class Parent
{
private:
	int one;

protected:
	~Parent() = default;

public:
	Parent() : one(0) {  }

	Parent(const Parent& other) : one(0)
	{
		one = other.one;
		cout << "copy parent" << endl;
	}

	virtual void Print()
	{
		cout << "parent" << endl;
	}
};

class Child final : public Parent
{
private:
	int two;

public:
	virtual ~Child() = default;

	Child() : two(0)
	{
	}

	void Print() override
	{
		cout << "child" << endl;
	}
};

void ObjectSlicingAndPolymorphism()
{
	Child c1;
	Parent& p1 = c1;
	p1.Print();

	Parent p2 = Child();
	p2.Print();
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void delve(TreeNode* root, TreeNode* res) {
	if (!root) return;

	if (root->left) {
		if (!res->left) {
			res->left = new TreeNode(res->val, nullptr, nullptr);
			delve(root->left, res->left);
		}
		else {
			res->left->val += root->left->val;
			delve(root->left, res->left);
		}
	}

	if (root->right) {
		if (!res->right) {
			res->right = new TreeNode(res->val, nullptr, nullptr);
			delve(root->right, res->right);
		}
		else {
			res->right += root->right->val;
			delve(root->right, res->right);
		}
	}
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	TreeNode* res = new TreeNode;
	delve(root1, res);
	delve(root2, res);

	if (!root1)
		return root2;
	if (!root2)
		return root1;

	res->val = root1->val + root2->val;
	return res;

	//TreeNode* mergeTrees(TreeNode * t1, TreeNode * t2) {
	//	TreeNode* newRoot = t1;

	//	if (t1 == NULL) return t2;
	//	if (t2 == NULL) return t1;

	//	newRoot->val += t2->val;

	//	newRoot->left = mergeTrees(t1->left, t2->left);
	//	newRoot->right = mergeTrees(t1->right, t2->right);

	//	return newRoot;
}

class Animal
{
public:
	virtual void Run() = 0;
	virtual void Speak() = 0;
};

class Dog : public Animal
{
public:
	void Speak() override
	{
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog
{
public:
	Labrador()
	{
		cout << "new lab" << endl;
	}
	void Run() override
	{
		cout << "Lab running" << endl;
	}
};

void AnimalTest(Animal& a)
{
	a.Run();
}

void AbstractClassesAndPureVirtualFunctions()
{
	Labrador lab;
	lab.Speak();
	lab.Run();

	Animal* animals[5];
	animals[0] = &lab;
	animals[0]->Speak();

	AnimalTest(lab);
}

struct MatchFunctorBase
{
	virtual bool operator()(string& str) = 0;
	virtual ~MatchFunctorBase() {  }
};

struct MatchFunctor : public MatchFunctorBase
{
	bool operator()(string& str) override
	{
		return str == "lion";
	}
};

void Check(string str, MatchFunctorBase& test)
{
	if (test(str))
		cout << "Text matches" << endl;
	else
		cout << "No match" << endl;
}

void Functors()
{
	MatchFunctor pred;
	string value = "lion";
	Check("lion", pred);
}

template<class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}


template<class T>
class Stack
{
private:
	T* stack;
	int top;
	int size;
public:
	explicit Stack(int sz)
	{
		size = sz;
		top = -1;
		stack = new T[size];
	}

	void Push(T x)
	{
		if (top == size - 1)
			cout << "Stack is full" << endl;
		else
		{
			top++;
			stack[top] = x;
		}
	}

	T Pop()
	{
		T x = 0;
		if (top == -1)
			cout << "stack is Empty" << endl;
		else
		{
			x = stack[top];
			top--;
		}
		return x;
	}
};

void TemplatesAndGenerics()
{
	cout << Max(7, 5) << endl;
	Stack<int> s(10);
	s.Push(23);
	s.Push(33);
	Stack<float> ss(10.5);
}

string removeDuplicates(string s) {
	if (s.length() == 1) return s;

	int len = s.length();
	for (size_t i = 0; i < s.length(); ++i) {
		int cnt = 1;
		char curr = s[i];
		for (size_t j = i + 1; curr == s[j] && j < s.length(); ++j)
			cnt++;

		if (cnt > 1) {
			s.erase(i, cnt);
			i = -1;
		}

		if (s == "" && len % 2 != 0)
			return string(1, char(curr));

		if (s == "" && len % 2 == 0)
			return "";
	}

	return s;
}

vector<int> minOperations(string boxes) {
	vector<int> res(boxes.length());
	for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
		res[i] += ops;
		cnt += boxes[i] == '1' ? 1 : 0;
		ops += cnt;
	}
	for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
		res[i] += ops;
		cnt += boxes[i] == '1' ? 1 : 0;
		ops += cnt;
	}
	return res;
}

int height(TreeNode* root) {
	if (root == nullptr)
		return 0;

	const int left = height(root->left);
	const int right = height(root->right);

	return left > right ? left + 1 : right + 1;
}

void delve(TreeNode* root, int& maxLevel, int level, int& sum) {
	if (root == nullptr) return;

	delve(root->left, maxLevel, ++level, sum);

	if (level == maxLevel)
		sum += root->val;

	delve(root->right, maxLevel, level, sum);
}

int deepestLeavesSum(TreeNode* root) {
	if (root->left == nullptr && root->right == nullptr)
		return root->val;

	int max = height(root), sum = 0;
	delve(root, max, 0, sum);

	return sum;
}

void sumNodes(TreeNode* root, int& sum, int level) {
	if (root == nullptr) return;

	if (level == 2)
		sum += root->val;

	sumNodes(root->left, sum, ++level);

	sumNodes(root->right, sum, level);
}

void delve(TreeNode* root, vector<TreeNode*>& nodes) {
	if (root == nullptr) return;

	if (root->val % 2 == 0)
		nodes.emplace_back(root);

	delve(root->left, nodes);

	delve(root->right, nodes);
}

int sumEvenGrandparent(TreeNode* root) {
	int sum = 0;
	vector<TreeNode*> nodes;
	delve(root, nodes);

	for (auto& i : nodes)
		sumNodes(i, sum, 0);

	return sum;
}

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
	vector<vector<int>> res;
	unordered_set<int> set(groupSizes.size());

	for (size_t i = 0; i < groupSizes.size(); ++i) {

		if (set.count(i) != 0) continue;

		vector<int> vec(groupSizes[i]);
		int cnt = 0;

		for (size_t j = i; cnt < groupSizes[i]; ++j) {
			if (groupSizes[i] == groupSizes[j]) {
				vec[cnt++] = j;
				set.insert(j);
			}
		}

		res.emplace_back(vec);
	}

	return res;
}

int main()
{
	//LeetCode
	//string test = truncateSentence("Hi", 1);
	//cout << test << endl;

	/*TreeNode* res = new TreeNode;
	res->val = 0;

	cout << res->val << endl;*/

	//removeDuplicates("aaaaaaaaa");
	//minOperations("001011");
	/*TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n8 = new TreeNode(8);

	n1->left = n2;
	n2->left = n4;
	n2->right = n5;
	n4->left = n7;
	n1->right = n3;
	n3->right = n6;
	n6->right = n8;

	cout << deepestLeavesSum(n1) << endl;*/

	/*TreeNode* n = new TreeNode(6);

	TreeNode* n1 = new TreeNode(7);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(9);
	TreeNode* n4 = new TreeNode(7);
	TreeNode* n5 = new TreeNode(1);
	TreeNode* n6 = new TreeNode(4);

	TreeNode* n7 = new TreeNode(8);
	TreeNode* n8 = new TreeNode(1);
	TreeNode* n9 = new TreeNode(3);
	TreeNode* n10 = new TreeNode(5);

	n->left = n1;
	n1->left = n2;
	n2->left = n3;
	n1->right = n4;
	n4->left = n5;
	n4->right = n6;

	n->right = n7;
	n7->left = n8;
	n7->right = n9;
	n9->right = n10;


	cout << sumEvenGrandparent(n);*/

	vector<int> res{ 3,3,3,3,3,1,3 };
	groupThePeople(res);


	//STL
	//FileWriting::WriteSomeShit();
	//FileWriting::ReadSomeShit();

	//std::cout << sizeof(Person) << std::endl;

	//FileWriting::BinaryParsingShit();
	//FileWriting::ReadBinaryShit();

	//Vector();
	//VectorAndMemory();
	//TwoDimensionalVector();
	//List();
	//Map();
	//CustomObjectMapValue();
	//CustomObjectMapKey();
	//MultiMap();
	//Set();
	//StackAndQueue();
	//SortingShit();

	//End

	//Operator Overloading

	//OperatorOverloading();
	//LeftBitShift();
	//ComplexNumber();
	//OverloadingPlus();

	//End

	//Pointers and Memory;

	//Pointers();
	//Arithmetic();
	//PointerAndArrays();
	//PointerArithmetic();
	//CharArrays();
	//Reverse();
	//References();
	//Const();
	//CopyConstructors();

	//Passing functions to functions
	//FunctionPointers();
	//UsingFunctionPointers();
	//ObjectSlicingAndPolymorphism();
	//AbstractClassesAndPureVirtualFunctions();
	//Functors();

	TemplatesAndGenerics();
}
