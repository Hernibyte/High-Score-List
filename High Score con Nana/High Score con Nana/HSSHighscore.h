#pragma once

#include <string>
#include <iostream>

namespace HS {

	const int listSize = 5;

	struct ScoreEntry {
		std::string name;
		long int score;
	};

	static ScoreEntry list[listSize];
	void initList();
	void insertSort(ScoreEntry entry);
	void forceInsert(ScoreEntry entry, int pos);
	void deleteEntry(int pos);
	void clearAllEntries();
	ScoreEntry returnRankEntry(int pos);
	std::string returnRankName(int pos);
	long int returnRankScore(int pos);




}
