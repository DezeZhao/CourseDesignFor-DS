#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;
class Person
{
private:
    int id;
    QString name;
    QString region;
    QString primarySchool;
    QString middleSchool;
    QString highSchool;
    QString workPlace;
    bool hobbies[10];

public:
    Person();
    ~Person();
    void setId(int id);
    int getId();
    void setName(QString name);
    QString getName();
    void setRegion(QString region);
    QString getRegion();
    void setPrimarySchool(QString primarySchool);
    QString getPrimarySchool();
    void setMiddleSchool(QString middleSchool);
    QString getMiddleSchool();
    void setHighSchool(QString highSchool);
    QString getHighSchool();
    void setWorkPlace(QString workPlace);
    QString getWorkPlace();
    void setHobbies(bool *hobbies);
    bool *getHobbies();
};

#endif // PERSON_H
