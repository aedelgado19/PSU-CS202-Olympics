/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   Olympics.h contains the function prototypes 
   for the following classes: Sport, Track
   (track and field), Tennis, VB (volleyball),
   BST, B_Node, LLL, and L_Node.
   The athletes will be stored in a BST.  
   
   Last updated: Aug 6, 2021
 */

#include "Olympics.h"

//SPORT CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//initialization list
Sport::Sport() : skills(""), history(""), medals(0){
  date = new char[7];
  time = new char[5];
}

//destructor
Sport::~Sport(){
  delete [] date;
  delete [] time;
  time = nullptr;
  date = nullptr;
}

//copy constructor
Sport::Sport(const Sport & source){
  date = new char[strlen(source.date) + 1];
  strcpy(date, source.date);
  time = new char[strlen(source.time) + 1];
  strcpy(time, source.time);
}

//fill in data
void Sport::read(){
  char d[7];
  char t[5];
  std::string s;
  std::string h;
  int m;
  
  std::cout << "What time does this event occur? " << std::endl;
  std::cout << "Enter the time in hhmm format " << std::endl;
  std::cout << "Ex: 4:30 would be 0430" << std::endl;
  std::cout << "> ";
  std::cin.get(t, 5);
  std::cin.get();
  std::cout << "What is the date of this event? " << std::endl;
  std::cout << "Enter the date in mmddyy format. " << std::endl;
  std::cout << "Ex: May 4, 2021 would be 050421" << std::endl;
  std::cout << "> ";
  std::cin.get(d, 7);
  std::cin.get();
  std::cout << "What kind of skills would this type of sport require?" << std::endl;
  std::cout << "> ";
  std::getline(std::cin, s);
  std::cout << "What is their history of competing at the olympics?" << std::endl;
  std::cout << "> ";
  std::getline(std::cin, h);
  std::cout << "How many medals have they won?" << std::endl;
  std::cout << "> ";
  std::cin >> m;
  std::cin.get();

  strcpy(date, d);
  strcpy(time, t);
  skills = s;
  history = h;
  medals = m;
}

//display data
void Sport::display() const{
  std::cout << "DATE: " << date[0] << date[1] << "/" << date[2] << date[3] << "/" << date[4] << date[5] << std::endl;
  std::cout << "TIME: " << time[0] << time[1] << ":" << time[2] << time[3] << std::endl;
  std::cout << "SKILLS: " << skills << std::endl;
  std::cout << "HISTORY: " << history << std::endl;
  std::cout << "MEDALS: " << medals << std::endl;
}

//compare the date
bool Sport::compare_d(char* d){
  if(strcmp(d, date) == 0){
    return true;
  }
  return false;
}

//compare the time
bool Sport::compare_t(char* t){
  if(strcmp(t, time) == 0){
    return true;
  }
  return false;
}

//overload <<
std::ostream & Sport::operator << (std::ostream & o){
  o << this->skills << std::endl;
  o << this->history << std::endl;
  return o;
}

//overload >>
std::istream & operator >> (std::istream & i, std::string &s){
  return i;
}

//overload ==
bool Sport::operator == (const Sport & sport){
  return (strcmp(date, sport.date) == 0) &&
    (strcmp(time, sport.time) == 0) && (skills == sport.skills)
    && (history == sport.history) && (medals == sport.medals);
}

//overload !=
bool Sport::operator != (const Sport & sport){
 return (strcmp(date, sport.date) != 0) &&
    (strcmp(time, sport.time) != 0) && (skills != sport.skills)
    && (history != sport.history) && (medals != sport.medals);
}

//overload =
Sport & Sport::operator = (const Sport & s){
  if(this->date) delete [] date;
  if(this->time) delete [] time;
  strcpy(this->date, s.date);
  strcpy(this->time, s.time);
  this->skills = s.skills;
  this->history = s.history;
  this->medals = s.medals;
  return *this;
}

//overload +=
Sport & Sport::operator += (int i){
  medals += i;
  return *this;
}

//TRACK AND FIELD CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//initialization list
Track::Track() : athlete_name(""), distance(0){

}

//read in info
void Track::read(std::string n){
  int meters = 0;
  
  std::cout << "How many meters is the event they are competing in?" << std::endl;
  std::cin >> meters;
  std::cin.get();

  athlete_name = n;
  distance = meters;
  Sport::read();
}

//print out athlete data
void Track::display(){
  std::cout << "Athlete: " << athlete_name << std::endl;
  std::cout << "Distance: " << distance << " meters " << std::endl;
  Sport::display();
}

//change which event they are competing in
void Track::change_event(int dist){
  distance = dist;
}

//TENNIS CLASS -------------------------------------------

//constructor
Tennis::Tennis() : type(0), athlete_name(""){
  
}

//read in data
void Tennis::read(std::string name){
  std::string n;
  int t = 0;
  
  std::cout << "Which type of match are they competing in?" << std::endl;
  std::cout << "1 - singles" << std::endl;
  std::cout << "2 - doubles" << std::endl;
  std::cout << "> ";
  std::cin >> t;
  std::cin.ignore(1000, '\n');

  type = t;
  athlete_name = n;
  Sport::read();
}

//display data
void Tennis::display(){
  std::cout << "MATCH TYPE: ";
  if(type == 1) std::cout << "singles tennis " << std::endl;
  else std::cout << "doubles tennis " << std::endl;
  std::cout << "ATHLETE NAME: " << athlete_name << std::endl;
  Sport::display();
}

//change from either singles to doubles or vice versa
void Tennis::change_type(){
  if(type == 1){
    std::cout << "Changing singles reservation to doubles. "<< std::endl;
    type = 2;
  }
  else {
    std::cout << "Changing doubles reservation to singles." << std::endl;
    type = 1;
  }
}

//VOLLEYBALL CLASS -----------------------------------------
VB::VB(){

}

//display data
void VB::display(){
  std::cout << "Players: " << std::endl;
  for(std::vector<std::string>::iterator i = players.begin(); i!=players.end(); ++i){
    std::cout << (*i) << std::endl;
  }
  Sport::display();
}

//read data
void VB::read(std::string n){
  int a = 0;
  std::string name;
  
  std::cout << "Enter the amount of players on the team " << std::endl;
  std::cout << "> ";
  std::cin >> a;
  std::cin.ignore(1000, '\n');
  std::cout << "Enter in each player's name (1 at a time, separated by a newline)" << std::endl;
  for(int i = 0; i < a; i++){
    std::cout << "> ";
    std::getline(std::cin, name);
    players.push_back(name);
  }
  team_name = n;
  Sport::read();
}

//add players to vector
void VB::add_players(std::vector<std::string> p){
  for(std::vector<std::string>::iterator i = p.begin(); i!=p.end(); ++i){
    players.push_back(*i);
  }
}

//remove players from vector
void VB::remove_players(std::vector<std::string> to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = players.begin(); i!=players.end(); ++i){
      if((*i) == (*j)){
	players.erase(i);
	break;
      }
    }  
  }
}

//DATA STRUCTURES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//B_Node class ---------------------------
B_Node::B_Node(){
  right = nullptr;
  left = nullptr;
}

//return left node
B_Node *& B_Node::go_left(){
  return left;
}

//return right node
B_Node *& B_Node::go_right(){
  return right;
}

//set the left node
void B_Node::set_left(B_Node * node){
  left = node;
}

//set the right node
void B_Node::set_right(B_Node * node){
  right = node;
}

std::string & B_Node::compare_name(){
  return name;
}

void B_Node::change_name(std::string n){
  name = n;
}

// BST CLASS ---------------------------

BST::BST(){
  root = nullptr;
}

//destructor
BST::~BST(){
  destruct(root);
  root = nullptr;
}

//recursive deletion of the whole tree (called by destructor)
B_Node* BST::destruct(B_Node *& cur){
  if(cur){
    destruct(cur->go_left());
    destruct(cur->go_right());
    delete cur;
    cur = nullptr;
    return cur;
  }
  return nullptr;
}

//wrapper remove
void BST::remove(std::string name){
  remove(root);
}

//insert node wrapper
void BST::insert(B_Node *& to_add){
  insert(root, to_add);
}

//recursive insert
void BST::insert(B_Node *& cur, B_Node *& to_add){
  if(!root){
    root = to_add;
    to_add->set_right(nullptr);
    to_add->set_left(nullptr);
    return;
  }

  //check left
  if(cur->compare_name() > to_add->compare_name()){
    if(!cur->go_left()){
      cur->set_left(to_add);
      return;
    }
    insert(cur->go_left(), to_add);
  }

  //check right
  if(cur->compare_name() < to_add->compare_name()){
    if(!cur->go_right()){
      cur->set_right(to_add);
      return;
    }
    insert(cur->go_right(), to_add);
  }
}

//wrapper to remove node
void BST::remove(B_Node *& to_remove){
  remove(root, to_remove);
}

//recursive remove
void BST::remove(B_Node *& cur, B_Node *& to_remove){
  if(!cur) return;

  //left
  if(cur->compare_name() > to_remove->compare_name()){
    remove(cur->go_left(), to_remove);
  }

  //right
  if(cur->compare_name() < to_remove->compare_name()){
    remove(cur->go_right(), to_remove);
  }

  if(cur->compare_name() == to_remove->compare_name()){

    //case 1: no children
    if(!cur->go_left() && !cur->go_right()){
      delete cur;
    }

    //case 2: left is null
    if(!cur->go_left() && cur->go_right()){
      B_Node * hold = cur->go_right();
      delete cur;
      cur = hold;
      return;
    }

    //case 3: right is null
    if(cur->go_left() && !cur->go_right()){
      B_Node * hold = cur->go_left();
      delete cur;
      cur = hold;
      return;
    }

    //case 4: has 2 children
    if(cur->go_right() && cur->go_left()){
      B_Node * ios = cur;
      find_smallest(cur->go_right(), ios);
      cur->change_name(ios->compare_name());
      //delete ios
      remove(cur->go_right(), to_remove);
    }
  }
}

//helps find ios (called on the right child, traverses left)
void BST::find_smallest(B_Node * cur, B_Node *& to_return){
  if(cur && cur->go_left()){
    find_smallest(cur->go_left(), to_return);
  }
  if(!cur->go_left()){
    to_return = cur;
    return;
  }
}

//wrapper display
void BST::display(){
  display(root, 0);
}

//recursive display
//credits: used the same display algorithm as I did in 163
void BST::display(B_Node * cur, int d){
  if(!cur) return;
  display(cur->go_right(), d + 1);

  //spacing
  for(int i = 0; i < d; ++i){
    std::cout << "    ";
  }
  std::cout << cur->compare_name() << std::endl;

  display(cur->go_left(), d + 1);
}

//remove all
void BST::remove_all(){
  destruct(root);
}

// L_Node Class ------------------------------------------

//constructor
L_Node::L_Node() : next(nullptr), sport(nullptr){
  
}

//go next
L_Node *& L_Node::go_next(){
  return next;
}

//set next
void L_Node::set_next(L_Node *& n){
  next = n;
}

//set sport
void L_Node::set_sport(Sport * s){
  sport = s;
}

//used for comparing sports
Sport * L_Node::compare_sport(){
  return sport;
}

//overload == operator
bool L_Node::operator == (const L_Node & l) const {
  return (next == l.next);
}

//overload != operator
bool L_Node::operator != (const L_Node & l) const{
  return (next != l.next);
}

// LLL class ----------------------------------------------
//constructor
LLL::LLL() : head(nullptr){

}

//copy constructor
LLL::LLL(const LLL & source){
  cp(head, source.head);
}

//recursive copy
void LLL::cp(L_Node * cur, L_Node * source){
  if(!source->go_next()) { //last node
    cur = new L_Node(*source);
  } else {
    cur = new L_Node(*source);
    cp(cur->go_next(), source->go_next());
  }
}

//destructor
LLL::~LLL(){
  destruct(head);
}

//recursive destruct
void LLL::destruct(L_Node *& cur){
  if(!cur) return;
  L_Node * temp = cur->go_next();
  delete cur;
  destruct(temp);
}

//insert
void LLL::insert(L_Node & to_add){
  if(!head){
    head = &to_add;
  } else {
    to_add.set_next(head);
    head = &to_add;
  }
}

//wrapper remove
void LLL::remove(L_Node *& r){
  if(!head) return;
  remove(head, r);
}

//recursive remove
void LLL::remove(L_Node *& cur, L_Node *& r){
  if(!cur) return;
  if(cur->go_next() == r){
    cur->set_next(cur->go_next()->go_next());
    delete cur->go_next();
    return;
  }
  remove(cur->go_next(), r);
}

//wrapper display
void LLL::display(){
  display(head);
}

//recursive display
void LLL::display(L_Node * cur){
  if(!cur) return;
  std::cout << cur->compare_sport() << std::endl;
  display(cur->go_next());
}

//wrapper remove all
void LLL::remove_all(){
  destruct(head);
}

//overload + operator
L_Node& LLL::operator + (L_Node & to_add){
  if(!head){
    head = &to_add;
  } else {
    to_add.set_next(head);
    head = &to_add;
  }
  return to_add;
}

//overload [] operator
L_Node & LLL::operator [] (int index) const {
  L_Node * current = head;
  for(int i = 0; i < index; i++){
    current = current->go_next();
  }
  return *current;
}

