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

//listener for the 'SUBMITION' button
struct SubmitListener : public MouseListener {
private:
	Control & _c;
public:
	SubmitListener(Control &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft) {
		_c.SetBackground(Color::Blue);
		_c.Show();
	}
};

//listener for the 'YES' button
struct yesBtnListener : public MouseListener {
private:
	Control & _c;
public:
	yesBtnListener(Control &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft){
		_c.SetBackground(Color::Black);
		_c.Hide();
	}
};

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
	
	TextBox textboxName(20);
	TextBox texboxtLocation(25);
	texboxtLocation.SetValue("Abba show, London");

	Button buttonSubmit(6);
	buttonSubmit.SetValue("Travel");
	CheckList checklistInterests(3, 15, { "Money", "Drugs", "Fame" });
	checklistInterests.SelectIndex(1);
	NumericBox numBoxAge(15, 18, 120);
	numBoxAge.SetValue(27);
	RadioBox radioSex(3, 15, { "Male", "Female", "Yes please" });
	ComboBox comboxYear(20, { "70's", "80's", "90's" });
	comboxYear.SetSelectedIndex(1);

	Messagebox sbmt(30, 7);
	sbmt.SetTitle("Courdenence Occurred");
	sbmt.SetText("Prepare for Time Travel!");

	comboxYear.SetBorder(BorderType::Double);
	labelAlias.SetForeground(Color::Cyan);
	labelLocation.SetForeground(Color::Cyan);
	labelYear.SetForeground(Color::Cyan);
	labelSex.SetForeground(Color::Cyan);
	labelAdditions.SetForeground(Color::Cyan);
	labelAge.SetForeground(Color::Cyan);

	SubmitListener submitListener = SubmitListener::SubmitListener(sbmt);
	buttonSubmit.AddListener(submitListener);
	Button buttonYes(6);
	buttonYes.SetValue("Launch");
	buttonYes.SetBackground(Color::Blue);
	yesBtnListener buttonYesListener = yesBtnListener::yesBtnListener(sbmt);
	buttonYes.AddListener(buttonYesListener);
	sbmt.addButton(buttonYes, 28, 9);

	Panel mainPanel(27, 55);
	mainPanel.addControl(labelAlias, 1, 2);
	mainPanel.addControl(labelLocation, 1, 5);
	mainPanel.addControl(labelYear, 1, 8);
	mainPanel.addControl(labelSex, 1, 11);
	mainPanel.addControl(labelAdditions, 1, 15);
	mainPanel.addControl(labelAge, 1, 20);
	mainPanel.addControl(textboxName, 25, 2);
	mainPanel.addControl(texboxtLocation, 25, 5);
	mainPanel.addControl(comboxYear, 25, 8);
	mainPanel.addControl(radioSex, 25, 11);
	mainPanel.addControl(checklistInterests, 25, 15);
	mainPanel.addControl(numBoxAge, 25, 20);
	mainPanel.addControl(buttonSubmit, 25, 25);
	mainPanel.addControl(sbmt, 17, 5);

	Control::setFocus(textboxName);
	EventEngine engine;
	engine.run(mainPanel);

	return 1;
}


