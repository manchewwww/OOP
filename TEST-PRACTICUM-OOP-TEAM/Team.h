#pragma once
#include "Person.h"
#include "Group.h"
class Team : public Group{
private:
	Person* teamLeader;
	Person** workers;
	unsigned sizeOfTeamLeader;
	unsigned capacityOfTeamLeader;

	void copyFrom(const Team& other);
	void free();
public:
	Team();
	Team(Person* teamLeader, Person** workers, unsigned sizeOfTeamLeader, const Person* persons, const unsigned size);
	Team(const Team& other);
	Team& operator=(const Team& other);
	~Team();

	void operator()(const Person& lhs, const Person& rhs);


	bool operator<=(const Team& other) const;
	bool operator>=(const Team& other) const;
	bool operator<(const Team& other) const;
	bool operator>(const Team& other) const;

private:
	void setTeamLeader(const Person* teamLeader);
	void setWorkers(const Person** workers);
	void resize();
};
