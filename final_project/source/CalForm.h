#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"
#include "NumericBox.h"
#include "RadioBox.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "MessageBox.h"

Panel* maincopy = NULL;
vector<wstring>str;
class Submit :public MouseListener {
private:
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		vector<Control*> myvec;
		control.getAllControls(&myvec);
		wstring answer=L"name: " ;
		for (int i = 0; i < 2; i++) {
			TextBox *tmp = static_cast<Button*>(myvec[i]);
			answer += tmp->getText()+L" ";
		}
		NumericBox *tmp = static_cast<NumericBox*>(myvec[2]);
		answer += (L"|age: " + to_wstring(tmp->getValue()) + L"\n") ;
		answer += L"Hobby: ";

		CheckList* temp = static_cast<CheckList*>(myvec[3]);
		vector<string> en = temp->Getallentries();
		vector<size_t> in = temp->GetallIndex();
		for (int i = 0; i < in.size(); i++) {
			answer += temp->s2ws(en[in[i]]);
			if (i != in.size() - 1)
				answer += L", ";
		}
		answer += L"\n";
		answer += L"Gender: ";
		RadioBox *ttmp = static_cast<RadioBox*>(myvec[4]);
		 en = ttmp->Getallentries();
		size_t sein = ttmp->GetSelectedIndex();
		if (sein != -1) 
			answer += (ttmp->s2ws(en[sein]));
		
			answer += L"\nEducation: ";
		
		ComboBox* tempo = static_cast<ComboBox*>(myvec[5]);
		sein = tempo->GetSelectedIndex();
		vector<Control*>child;
		tempo->getAllControls(&child);

		if (sein != -1) {
			Button* bb = static_cast<Button*>(child[sein]);
			answer += bb->getText();
		}

		Messagebox *tt = static_cast<Messagebox*> (myvec[myvec.size()-1]);
		answer += L"\nDo you want to Save?";
		tt->setText(answer);
		myvec[myvec.size() - 1]->setVisibility(true);
	}
};

class messageBoxListener : public MouseListener {
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		control.setVisibility(false);
		Messagebox* tmp = static_cast<Messagebox*>(&control);
		if (tmp->isOK()) {
			vector<Control*> vec;
			maincopy->getAllControls(&vec);

			TextBox *tmp = static_cast<TextBox*>(vec[0]);
			tmp->setText(str[0]);
			tmp->restCursor();
			Control::setFocus(*tmp);
			tmp = static_cast<TextBox*>(vec[1]);
			tmp->setText(str[1]);
			tmp->restCursor();

			CheckList* temp = static_cast<CheckList*>(vec[3]);
			vector <size_t> *out = &temp->GetallIndex();
			out->clear();
			temp->restCursor();

		}
	}
};
messageBoxListener messageb;

// 1->textbox first name (wstring::getText())
// 2->textbox last name  (wstring::getText())
// 3-> numricbox age (size_t::getValue())
// 4-Checklist hobby (vector<size_t> GetallIndex())
// 5->Radiobox gender (size_t::GetSelectedIndex())
// 6->Combobox eduaction (size_t::GetSelectedIndex)

Submit listener;


class Form {

public:
	Form() {}
	~Form() {}
	void start() {
		//the main panel
		Panel main(29, 70);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		maincopy = &main;
		//box exampales
		TextBox str1(10);
		str1.setText(L"first");
		str1.setBorder(BorderType::Single);
		main.AddControl(str1, 5, 7);
		str.push_back(str1.getText());

		TextBox str2(10);
		str2.setText(L"last");
		str2.setBorder(BorderType::Single);
		main.AddControl(str2, 20, 7);
		str.push_back(str2.getText());

		NumericBox age(4, 0, 18);
		age.setBorder(BorderType::Single);
		main.AddControl(age, 5, 14);

		vector<string> hobbies;
		hobbies.push_back("sport");
		hobbies.push_back("movies");
		hobbies.push_back("swiming");
		hobbies.push_back("vidiogames");

		CheckList hobby(10, 2, hobbies);
		hobby.setBorder(BorderType::Single);
		main.AddControl(hobby,50, 14);

		vector<string> genders;
		genders.push_back("male");
		genders.push_back("female");
		genders.push_back("others");

		RadioBox gender(7, 2, genders);
		gender.setBorder(BorderType::Single);
		main.AddControl(gender, 50, 5);

		vector<string> educations;
		educations.push_back("collage");
		educations.push_back("highschool");
		educations.push_back("droped");

		ComboBox education(10, educations);
		education.setBorder(BorderType::Single);
		main.AddControl(education, 25, 14);

		//titles
		Label title(12);
		title.setText(L"   survey");
		title.setBackground(Color::White);
		title.setForeground(Color::Black);
		main.AddControl(title, 27, 1);

		Label name(15);
		name.setText(L"full name");
		name.setBackground(Color::Black);
		name.setForeground(Color::Orange);
		main.AddControl(name, 13, 5);


		Label agetest(15);
		agetest.setText(L"age(0-18)");
		agetest.setBackground(Color::Black);
		agetest.setForeground(Color::Orange);
		main.AddControl(agetest, 5, 12);

		Label educattest(15);
		educattest.setText(L"education");
		educattest.setBackground(Color::Black);
		educattest.setForeground(Color::Orange);
		main.AddControl(educattest, 25, 12);

		Label hobbytest(15);
		hobbytest.setText(L"hobby");
		hobbytest.setBackground(Color::Black);
		hobbytest.setForeground(Color::Orange);
		main.AddControl(hobbytest, 52, 12);

		Label gendertest(15);
		gendertest.setText(L"gender");
		gendertest.setBackground(Color::Black);
		gendertest.setForeground(Color::Orange);
		main.AddControl(gendertest, 50, 3);


		Button click(10);
		click.setText(L" submit!");
		click.setBorder(BorderType::Single);
		click.setBackground(Color::White);
		click.setForeground(Color::Green);
		click.addListener(listener);
		main.AddControl(click, 30, 25);


		Messagebox message(35, 8, L" ");
		message.setVisibility(false);
		message.addlistener(&messageb);
		main.AddControl(message, 5, 10);


		/*End of the Form */

		Control::setFocus(str1);
		EventEngine engine;
		engine.run(main);
	}
};



