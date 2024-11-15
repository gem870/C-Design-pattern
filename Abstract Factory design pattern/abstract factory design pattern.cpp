

#include <iostream>
#include <chrono>
using namespace std;

class IButton {
public:
	virtual void press() = 0;               // <--------------------//
};																	//  
																	// 
class MacButton :public IButton {									// 
public:																//
	void press() {													//
		cout << "::--> You have pressed Mac button." << endl;		//
	}																//
};																	//
																	//- Here are the interface that define
class WinButton :public IButton {									//- pure virtual function of press and 
public:																//- showText.
	void press() {													//
		cout << "::--> You have pressed Windows button." << endl;	//
	}																//
};																	//
																	//
//===============================================================	//
																	//
class ITextBox {													//
public:																//
	virtual void showText() = 0;            // <--------------------//
};

class WinTextBox :public ITextBox {
public:
	void showText() {
		cout << "::--> Showing text from the windows." << endl;
	}
};

class MacTextBox :public ITextBox {
public:
	void showText() {
		cout << "::--> Showing text from the Mac. " << endl;
	}
};

//===============================================================

class IFactory {
public:
	virtual IButton* CreateButton() = 0;
	virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory :public IFactory {      // IFactory is an abstract factory interface with methods CreateButton and CreateTextBox.
public:									 // It allows the creation of button and text box objects without specifying their concrete classes.
	IButton* CreateButton() {
		return new MacButton();
	}

	ITextBox* CreateTextBox() {
		return new MacTextBox();
	}
};

class WinFactory :public IFactory {
public:
	IButton* CreateButton() {
		return new WinButton();
	}

	ITextBox* CreateTextBox() {
		return new WinTextBox();
	}
};
                     
//===============================================================

class GUIAbstractFactory {
public:
	static IFactory* CreateFactory(string osType) { // GUIAbstractFactory provides a static method CreateFactory that returns the appropriate
		if (osType == "windows")					// factory (either MacFactory or WinFactory) based on user input. If the input is "windows", it
			return new WinFactory();				// returns a WinFactory, and if it’s "mac", it returns a MacFactory.
		else if (osType == "mac")
			return new MacFactory();
		return new MacFactory();
	}
};



int main()
{
	auto startTime = chrono::high_resolution_clock::now();
	cout << "\n\n";
	int i = 0;
	while (i <= 119)
	{
		cout << ":";
		i++;
	}
	cout << "\n\n";
	cout << "Enter your machine os" << endl;
	string osType;
	cin >> osType;

	IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

	IButton* button = fact->CreateButton();
	button->press();

	ITextBox* textBox = fact->CreateTextBox();
	textBox->showText();



	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> timeComlexity = endTime - startTime;
	cout << "\n\n:::::::::::::: TIME COMPLEXITY ::::::::::::::" << endl;
	cout << "::::: Run Time: " << timeComlexity.count() << "ms" << endl;
}


