/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   Olympics.h contains the function prototypes
   for the following classes: Sport, Track 
   (track and field), Tennis, VB (volleyball),
   BST, B_Node, LLL, and L_Node.
   The athletes will be stored in a BST.

   Last updated: Aug 14, 2021
 */

#include <iostream>
#include <cstring>
#include <vector>

//base class: Sport
class Sport {
public:
  Sport();
  ~Sport();
  Sport(const Sport & source);
  void read();
  void display() const;
  bool compare_d(char* d); //compare date
  bool compare_t(char* t); //compare time

  std::ostream & operator << (std::ostream &);
  friend std::istream & operator >> (std::istream &, std::string& s);
  bool operator == (const Sport &);
  bool operator != (const Sport &);
  Sport & operator = (const Sport &);
  Sport & operator += (int); //add medals
private:
  char* date; //represented in 6 digits (mm/dd/yy)
  char* time; //represented in 4 digits (hh/mm)
  std::string skills;
  std::string history;
  int medals;
};

//track and field class
class Track : public Sport {
public:
  Track();
  void read(std::string);
  void display();
  void change_event(int dist);
  
private:
  std::string athlete_name;
  int distance;
};

//tennis class
class Tennis : public Sport {
public:
  Tennis();
  void read(std::string);
  void display();
  void change_type();
private:
  int type; //1 = singles tennis, 2 = doubles tennis
  std::string athlete_name;
};

//volleyball class
class VB : public Sport {
public:
  VB();
  void display();
  void read(std::string);
  void add_players(std::vector<std::string> p);
  void remove_players(std::vector<std::string> to_remove);
private:
  std::string team_name;
  std::vector<std::string> players;
};

// ***************** DATA STRUCTURE CLASSES **************

//each node in the LLL is an L_Node
class L_Node {
public:
  L_Node();
  L_Node(const Sport & source);
  L_Node *& go_next();
  void set_next(L_Node *& n);
  void set_sport(Sport * s);
  Sport *compare_sport();
  
  L_Node & operator = (const L_Node &);
  bool operator == (const L_Node &) const;
  bool operator != (const L_Node&) const;
  
private:
  Sport * sport;
  L_Node * next;
};

//holds the races/events the athlete is competing in
class LLL {
public:
  LLL();
  LLL(const LLL & source);
  ~LLL();

  //wrapper functions:
  void insert(L_Node & to_add);
  void remove(L_Node *& r);
  void display();
  void remove_all();

  L_Node& operator + (L_Node &);
  L_Node& operator = (const L_Node &);
  L_Node& operator [] (int index) const;
private:
  //recursive versions:
  void remove(L_Node *& cur, L_Node *& to_remove);
  void display(L_Node * cur);
  void remove_all(L_Node *& cur);
  void cp(L_Node * cur, L_Node * source);
  void destruct(L_Node *&);
  L_Node * head;
};

//each node in the BST is a B_Node
class B_Node {
public:
  B_Node();
  B_Node *& go_left();
  B_Node *& go_right();
  void set_left(B_Node * node);
  void set_right(B_Node * node);
  std::string & compare_name();
  void change_name(std::string n);
  
  bool operator == (const B_Node &) const;
  bool operator != (const B_Node &) const;
  bool operator < (const char*);
  bool operator <= (const char*);
  bool operator > (const char*);
  bool operator >= (const char*);

private:
  std::string name;
  B_Node * left;
  B_Node * right;
};

//binary search tree class
class BST {
public:
  BST();
  ~BST();

  //wrapper functions:
  void insert(B_Node *& to_add);
  void remove(B_Node *& to_remove); //remove by node
  void remove(std::string); //remove by name
  void display();
  void remove_all();

  B_Node & operator + (const B_Node &);
  B_Node & operator = (const B_Node &);

private:
  //recursive versions:
  void insert(B_Node *& cur, B_Node *& to_add);
  void remove(B_Node *& cur, B_Node *& to_remove);
  void display(B_Node * cur, int d);
  B_Node* destruct(B_Node *& cur);
  //  B_Node* clone(B_Node & source, B_Node & dest);
  void find_smallest(B_Node *, B_Node *&);
  B_Node * root;
};

