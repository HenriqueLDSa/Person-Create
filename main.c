#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
 
// Variable Date containing a day, month and year
typedef struct 
{
    int day;
    int month;
    int year;
} Date;
 
// Variable Person containing a name, birthdate, gender and annual income
typedef struct 
{
    char name[30];
    Date birthdate;
    char gender;
    double annualIncome;
} Person;
 
Person populatePerson(Person person);
bool validateDate(int day, int month, int year);
bool validateGender(char gender);
bool validateIncome(float annualIncome);
 
int main()
{
    Person person1;
    Person person2;
    Person person3;
 
    printf("\n-------------------\nPERSON 1\n-------------------\n");
    person1 = populatePerson(person1);
 
    printf("\n-------------------\nPERSON 2\n-------------------\n");
    person2 = populatePerson(person2);
 
    printf("\n-------------------\nPERSON 3\n-------------------\n");
    person3 = populatePerson(person3);
 
    printf("\n\nName: %s.", person1.name);
    printf("\nBirthdate: %d/%d/%d.", person1.birthdate.month, person1.birthdate.day, person1.birthdate.year);
    printf("\nGender: %c.", person1.gender);
    printf("\nAnnual Income: $%.2lf.", person1.annualIncome);
 
    printf("\n\nName: %s.", person2.name);
    printf("\nBirthdate: %d/%d/%d.", person2.birthdate.month, person2.birthdate.day, person2.birthdate.year);
    printf("\nGender: %c.", person2.gender);
    printf("\nAnnual Income: $%.2lf.", person2.annualIncome);
 
    printf("\n\nName: %s.", person3.name);
    printf("\nBirthdate: %d/%d/%d.", person3.birthdate.month, person3.birthdate.day, person3.birthdate.year);
    printf("\nGender: %c.", person3.gender);
    printf("\nAnnual Income: $%.2lf.", person3.annualIncome);
    
    return 0;
}
 
// Function to populate a variable Person
Person populatePerson(Person person)
{
    bool isDateValid = false;
    bool isGenderValid = false;
    bool isIncomeValid = false;
 
    // gets the name of the person
    printf("Name: ");
    scanf(" %[^\n]s", person.name);
 
    // gets person's birthdate 
    printf("Birthdate (MM/DD/YYYY format): ");
    while (isDateValid == false) //iterates through loop while input is invalid
    {
        scanf("%d/%d/%d", &person.birthdate.month, &person.birthdate.day, &person.birthdate.year);
        isDateValid = validateDate(person.birthdate.day, person.birthdate.month, person.birthdate.year);
 
        if (isDateValid == false)
            printf("\nINVALID DATE, TRY AGAIN!\n\n");
    }
 
    // gets person's gender
    printf("Gender (M, F or O): ");
    while (isGenderValid == false) //iterates through loop while input is invalid
    {
        scanf(" %c", &person.gender);
        person.gender = toupper(person.gender);
        isGenderValid = validateGender(person.gender);
 
        if (isGenderValid == false)
            printf("\nINVALID GENDER, TRY AGAIN!\n\n");
    }
 
    // gets person's annual income
    printf("Annual Income (between 0 and 1 million dollars): ");
    while (isIncomeValid == false) //iterates through loop while input is invalid
    {
        scanf("%lf", &person.annualIncome);
        isIncomeValid = validateIncome(person.annualIncome);
 
        if (isIncomeValid == false)
            printf("\nINVALID INCOME, TRY AGAIN!\n\n");
    }
 
    return person;
}
 
// Validates the date based on leap year rules, number of months and amount of days per month
bool validateDate(int day, int month, int year)
{   
    //checks year
    if(year>=1900 && year<=9999)
    {
        //check month
        if(month>=1 && month<=12)
        {
            //check days
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                return true;
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                return true;
            else if((day>=1 && day<=28) && (month==2))
                return true;
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0))) //checks leap year
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
 
// Validates if gender is M, F or O
bool validateGender(char gender)
{
    if (gender == 'M' || gender == 'F' || gender == 'O')
        return true;
    else   
        return false;
}
 
// Validates if annualIncome is between 0 and 1 million
bool validateIncome(float annualIncome)
{
    if(annualIncome >= 0 && annualIncome <= 1000000)
        return true;
    else
        return false;
}
