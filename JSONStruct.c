struct Person 
{
  int contact_person_id;
  char *first_name,*last_name;
  char *email;
};

struct Contact
{
  int contact_id;
  char *contact_name;
  char *street,*area,*city;
  struct Person *contact_persons[10];
}*contactlist;


  
