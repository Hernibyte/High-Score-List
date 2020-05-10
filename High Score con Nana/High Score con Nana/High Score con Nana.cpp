#include <iostream>
#include "nana/gui.hpp"
#include "nana/gui/widgets/label.hpp"
#include "nana/gui/widgets/button.hpp"
#include "HSSHighscore.h"
#include <string>

using namespace std;
using namespace HS;
using namespace nana; 

int main()
{
	//fake input
	ScoreEntry user1;
	user1.name = "Nana";
	user1.score = 90;
	ScoreEntry user2;
	user2.name = "Anuel";
	user2.score = 85;
	ScoreEntry user3;
	user3.name = "Pablo";
	user3.score = 87;
	ScoreEntry user4;
	user4.name = "SoyYo";
	user4.score = 91;
	ScoreEntry user5;
	user5.name = "Eljajas";
	user5.score = 120;

	initList();

	insertSort(user1);
	insertSort(user2);
	insertSort(user3);
	insertSort(user4);
	insertSort(user5);

	string score1 = to_string(returnRankScore(0));
	string score2 = to_string(returnRankScore(1));
	string score3 = to_string(returnRankScore(2));
	string score4 = to_string(returnRankScore(3));
	string score5 = to_string(returnRankScore(4));

	//Define a form.
	form fm;
	fm.caption("High Score");

	//Define a label and display a text.

	label posList1{ fm, returnRankName(0) };
	posList1.format(true);

	label pos1Score{ fm, score1 };
	pos1Score.format(true);

	label posList2{ fm, returnRankName(1) };
	posList2.format(true);

	label pos2Score{ fm, score2 };
	pos2Score.format(true);

	label posList3{ fm, returnRankName(2) };
	posList3.format(true);

	label pos3Score{ fm, score3 };
	pos3Score.format(true);

	label posList4{ fm, returnRankName(3) };
	posList4.format(true);

	label pos4Score{ fm, score4 };
	pos4Score.format(true);

	label posList5{ fm, returnRankName(4) };
	posList5.format(true);

	label pos5Score{ fm, score5 };
	pos5Score.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});

	//Layout management
	place plc(fm);
	plc.div("<vertical abc> <vertical std>");
	plc.field("abc") << posList1 << posList2 << posList3 << posList4 << posList5;
	plc.field("std") << pos1Score << pos2Score << pos3Score << pos4Score << pos5Score;
	plc.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}