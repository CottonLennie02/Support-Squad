#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

//Data structure to store information about the members in a support group
struct Member{
  string name;
  string illness;
  string contact;
  string location;
};

//Data structure to store all the members in a support group
vector<Member> members;

//Function to add new members
void addMember(string name, string illness, string contact, string location){
  Member newMember = {name, illness, contact, location};
  members.push_back(newMember);
}

//Function to remove members
void removeMember(string name){
  for(int i = 0; i < members.size(); i++){
    if(members[i].name == name){
      members.erase(members.begin() + i);
      break;
    }
  }
}

//Function to find members by location
vector<Member> findMembersByLocation(string location){
  vector<Member> foundMembers;
  for(int i = 0; i < members.size(); i++){
    if(members[i].location == location){
      foundMembers.push_back(members[i]);
    }
  }
  return foundMembers;
}

//Function to find members by illness
vector<Member> findMembersByIllness(string illness){
  vector<Member> foundMembers;
  for(int i = 0; i < members.size(); i++){
    if(members[i].illness == illness){
      foundMembers.push_back(members[i]);
    }
  }
  return foundMembers;
}

//Function to list all members
void listMembers(){
  for(int i = 0; i < members.size(); i++){
    cout << members[i].name << ": " << members[i].illness <<
    " " << members[i].contact << " " << members[i].location << endl;
  }
}

//Function to organize meetings
void organizeMeeting(string location){
  //Find all members in the specified location
  vector<Member> foundMembers = findMembersByLocation(location);
  //Randomly shuffle the members
  random_shuffle(foundMembers.begin(), foundMembers.end());
  //Display the members
  for(int i = 0; i < foundMembers.size(); i++){
    cout << foundMembers[i].name << endl;
  }
}

int main(){
  //Add some dummy members
  addMember("John Doe", "Diabetes", "jdoe@example.com", "New York");
  addMember("Jane Doe", "Rheumatoid Arthritis", "jane.doe@example.com", "San Francisco");
  addMember("Jill Smith", "Depression", "jill.smith@example.com", "New York");
  addMember("Jack Jones", "Cancer", "jack.jones@example.com", "San Francisco");
  //List all members
  listMembers();
  //Find members with diabetes
  vector<Member> diabeticMembers = findMembersByIllness("Diabetes");
  //Organize a meeting in San Francisco
  organizeMeeting("San Francisco");
  return 0;
}