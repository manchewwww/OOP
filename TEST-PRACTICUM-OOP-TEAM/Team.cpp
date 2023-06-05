#include "Team.h"
#include <iostream>
#pragma warning(disable:4996)

void Team::copyFrom(const Team& other)
{
    this->sizeOfTeamLeader = other.sizeOfTeamLeader;
    this->capacityOfTeamLeader = other.capacityOfTeamLeader;
    setTeamLeader(other.teamLeader);
    setWorkers(other.workers);
}

void Team::free()
{
    delete[] teamLeader;
    delete[] workers;
    teamLeader = nullptr;
    sizeOfTeamLeader = 0;
    capacityOfTeamLeader = 0;
}

Team::Team() : Group(), teamLeader(nullptr), workers(nullptr), sizeOfTeamLeader(0), capacityOfTeamLeader(8) {
}

Team::Team(Person* teamLeader, Person** workers, unsigned sizeOfTeamLeader, const Person* persons, const unsigned size) : Group(persons, size)
{
    this->sizeOfTeamLeader = sizeOfTeamLeader;
    capacityOfTeamLeader = 2 * sizeOfTeamLeader;
    setTeamLeader(teamLeader);
    setWorkers(workers);
}

Team::Team(const Team& other) : Group(other)
{
    copyFrom(other);
}

Team& Team::operator=(const Team& other) 
{
    if (this != &other) {
        Group::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Team::~Team()
{
    free();
}

void Team::operator()(const Person& lhs, const Person& rhs)
{
    for (size_t i = 0; i < sizeOfTeamLeader; i++) {
        if (teamLeader[i] == lhs) {
            for (size_t k = 0; k < sizeOfTeamLeader; k++) {
                for (size_t j = 0; j < 8 /*sizeOfWorkers*/; j++)
                {
                    if (workers[k][j] == rhs) {
                        std::swap(workers[k][j], workers[k][8/*sizeOfWorkers for index k*/]);
                        // sizeOfWorkers for index k--;
                        workers[i][8/*size of workers for index i*/] = rhs;
                    }
                }
            }
            break;
        }
    }
    if (sizeOfTeamLeader == capacityOfTeamLeader) {
        resize();
    }
    teamLeader[sizeOfTeamLeader++] = lhs;
}

bool Team::operator<=(const Team& other) const
{
    return !(*this > other);
}

bool Team::operator>=(const Team& other) const 
{
    return !(*this < other);
}

bool Team::operator<(const Team& other) const 
{
    return sizeOfTeamLeader < other.sizeOfTeamLeader;
}

bool Team::operator>(const Team& other) const
{
    return sizeOfTeamLeader > other.sizeOfTeamLeader;
}

void Team::setTeamLeader(const Person* teamLeader)
{
    this->teamLeader = new Person[capacityOfTeamLeader];
    for (size_t i = 0; i < sizeOfTeamLeader; i++) {
        this->teamLeader[i] = teamLeader[i];
    }
}

void Team::setWorkers(const Person** workers)
{
    Person** newPer = new Person*[capacityOfTeamLeader];
    for (size_t i = 0; i < sizeOfTeamLeader; i++)
    {
        newPer[i] = workers[i];
    }
    
}

void Team::resize()
{
    Person* newPer = new Person[capacityOfTeamLeader *= 2];
    for (size_t i = 0; i < sizeOfTeamLeader; i++) {
        newPer[i] = teamLeader[i];
    }
    delete[] teamLeader;
    teamLeader = newPer;
}

