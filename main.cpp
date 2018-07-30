#include <iostream>
#include "Control.h"
#include "Graphics.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include "CheckList.h"
#include "Button.h"
#include "NumericBox.h"
#include "RadioBox.h"
#include "TextBox.h"
#include "ComboBox.h"
#include "MessageBox.h"

using namespace std;

// Listeners for the buttons used.
struct SubmitListener : public MouseListener
{
private:
	Control & _c;

public:

	SubmitListener(Control &c) : _c(c) { }

	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.SetBackground(Color::Green);
		_c.Show();
	}

};

struct bOKListener : public MouseListener
{
private:
	Control & _c;

public:

	bOKListener(Control &c) : _c(c) { }

	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.SetBackground(Color::Black);
		_c.Hide();

	}

};

// Main function. Creates and sets controls, adds them to panel and runs event engine on panel.
void main() {

	Label lName(20);
	lName.SetValue("Name: ");

	Label lAddress(20);
	lAddress.SetValue("Address:");
	Label lCountry(20);
	lCountry.SetValue("Counrty:");
	Label lSex(20);
	lSex.SetValue("Sex:");
	Label lInterests(20);
	lInterests.SetValue("Interests:");
	Label lAge(20);
	lAge.SetValue("Age:");
	TextBox tName(20);
	TextBox tAddress(25);
	tAddress.SetValue("221B Baker Street, London");
	Button bSubmit(10);
	bSubmit.SetValue("Submit");
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	NumericBox nAge(15, 18, 120);
	nAge.SetValue(23);
	RadioBox rSex(2, 15, { "Male", "Female" });
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.SetSelectedIndex(1);
	Messagebox results(30, 10);
	results.SetTitle("SUBMIT");
	results.SetText("Thank you! Goodbye.");




	cCountry.SetBorder(BorderType::Double);
	lName.SetForeground(Color::Blue);
	lAddress.SetForeground(Color::Orange);
	lCountry.SetForeground(Color::Green);
	lSex.SetForeground(Color::Purple);
	lInterests.SetForeground(Color::Cyan);
	lAge.SetForeground(Color::Red);

	/*bSubmit.AddListener(SubmitListener::SubmitListener(results));
	Button bOK(5);
	bOK.SetValue("OK");
	bOK.SetBackground(Color::Green);
	bOK.AddListener(bOKListener::bOKListener(results));
	results.addButton(bOK, 10, 10);*/



	Panel main(27, 55);
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 20);
	main.addControl(bSubmit, 25, 25);
	main.addControl(results, 5, 5);



	Control::setFocus(tName);
	EventEngine engine;
	engine.run(main);

}


