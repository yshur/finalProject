#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"

class Choice_button :public MouseListener {
private:
public:
	/*
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		int num1 = 0, num2 = 0, ans = 0;
		vector<Control*> controls;
		control.getAllControls(&controls);
		TextBox* mynum1 = static_cast<TextBox*>(controls[2]);
		TextBox* mynum2 = static_cast<TextBox*>(controls[4]);
		num1 = stoi(mynum1->getText());
		num2 = stoi(mynum2->getText());


		(get the answer)
		ans = num1 + num2;
		Label* tempo = static_cast<Label*> (controls[1]);
		tempo->setText(to_wstring(ans));
	}
*/

};

//Choice_button listener;

class ChoiceForm {

public:
	ChoiceForm() {}
	~ChoiceForm() {}
	void start() {
		Panel main(20, 30);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		/* Caclculater Form
		* 2 - TextBox 2-Label 1-button
		*/

		//main.AddControl(title, 8, 1);


		/*End of Cal Form */

		/*
		//	main.AddControl(cal, 2, 2);
		Control::setFocus(num1);
		EventEngine engine;
		engine.run(main);
		*/
	}
};
