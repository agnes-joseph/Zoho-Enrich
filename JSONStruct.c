struct Contact
{
  int contact_id;
  char contact_name[10];
  char street[25],area[10],city[10];
  struct Person *contact_persons[10];
};

struct Person 
{
  int contact_person_id;
  char first_name[10],last_name[10];
  char email[20];
};
  