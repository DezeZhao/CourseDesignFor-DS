#include "person.h"
Person::Person() {}
int Person::getId()
{
    return id;
}
void Person::setId(int id)
{
    this->id = id;
}
QString Person::getName()
{
    return name;
}
void Person::setName(QString name)
{
    this->name = name;
}
QString Person::getRegion()
{
    return region;
}
void Person::setRegion(QString region)
{
    this->region = region;
}
QString Person::getHighSchool()
{
    return highSchool;
}
void Person::setHighSchool(QString highSchool)
{
    this->highSchool = highSchool;
}
void Person::setMiddleSchool(QString middleSchool)
{
    this->middleSchool = middleSchool;
}
QString Person::getMiddleSchool()
{
    return middleSchool;
}
QString Person::getPrimarySchool()
{
    return primarySchool;
}
void Person::setPrimarySchool(QString primarySchool)
{
    this->primarySchool = primarySchool;
}
QString Person::getWorkPlace()
{
    return workPlace;
}
void Person::setWorkPlace(QString workPlace)
{
    this->workPlace = workPlace;
}
void Person::setHobbies(bool *hobbies)
{
    for (int i = 0; i < 10; i++) {
        this->hobbies[i] = hobbies[i];
    }
}

bool *Person::getHobbies()
{
    return hobbies;
}
Person::~Person() {}
