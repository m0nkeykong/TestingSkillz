// Authors: Haim Elbaz ~ Roni Polisanov ~ Reut Leib
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

	void  MousePressed(Button &b, int x, int y, bool isLeft){
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

	void  MousePressed(Button &b, int x, int y, bool isLeft){
		_c.SetBackground(Color::Black);
		_c.Hide();
	}

};

// Main function. Creates and sets controls, adds them to panel and runs event engine on panel.
int main() {

	Label labelAlias(20);
	labelAlias.SetValue("New Alias: ");
	Label labelLocation(20);
	labelLocation.SetValue("Distinct Location:");
	Label labelYear(20);
	labelYear.SetValue("Year:");
	Label labelSex(20);
	labelSex.SetValue("Sex:");
	Label labelAdditions(20);
	labelAdditions.SetValue("Additions:");
	Label labelAge(20);
	labelAge.SetValue("Alias Age:");
	
	TextBox textName(20);
	TextBox textLocation(25);
	textLocation.SetValue("Abba show, London");

	Button buttonSubmit(10);
	buttonSubmit.SetValue("Submit");
	CheckList checklistInterests(3, 15, { "Money", "Drugs", "Fame" });
	checklistInterests.SelectIndex(1);
	NumericBox numBoxAge(15, 18, 120);
	numBoxAge.SetValue(23);
	RadioBox radioSex(3, 15, { "Male", "Female", "Yes please" });
	ComboBox comboxYear(20, { "70's", "80's", "90's" });
	comboxYear.SetSelectedIndex(1);

	Messagebox sbmt(30, 10);
	sbmt.SetTitle("Courdenence Occurred");
	sbmt.SetText("Prepare for Time Travel !");

	comboxYear.SetBorder(BorderType::Double);
	labelAlias.SetForeground(Color::Cyan);
	labelLocation.SetForeground(Color::Cyan);
	labelYear.SetForeground(Color::Cyan);
	labelSex.SetForeground(Color::Cyan);
	labelAdditions.SetForeground(Color::Cyan);
	labelAge.SetForeground(Color::Cyan);

	/*buttonSubmit.AddListener(SubmitListener::SubmitListener(sbmt));
	Button bOK(5);
	bOK.SetValue("OK");
	bOK.SetBackground(Color::Green);
	bOK.AddListener(bOKListener::bOKListener(sbmt));
	sbmt.addButton(bOK, 10, 10);*/

	Panel main(27, 55);
	main.addControl(labelAlias, 1, 2);
	main.addControl(labelLocation, 1, 5);
	main.addControl(labelYear, 1, 8);
	main.addControl(labelSex, 1, 11);
	main.addControl(labelAdditions, 1, 15);
	main.addControl(labelAge, 1, 20);
	main.addControl(textName, 25, 2);
	main.addControl(textLocation, 25, 5);
	main.addControl(comboxYear, 25, 8);
	main.addControl(radioSex, 25, 11);
	main.addControl(checklistInterests, 25, 15);
	main.addControl(numBoxAge, 25, 20);
	main.addControl(buttonSubmit, 25, 25);
	main.addControl(sbmt, 5, 5);

	Control::setFocus(textName);
	EventEngine engine;
	engine.run(main);

	return 1;
}


