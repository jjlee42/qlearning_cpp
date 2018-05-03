// an attempt to recreate the CAMP 2015 RL code in c++
// essentially is a 10-armed bandit

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int selectAction();
int getReward(int);
vector<float> updateQvals(vector<float>,int,int,const float);

int main() { // void avoids having to return 0?

    // init simulation params
    const int NTimesteps = 15; 
    const float alpha = 0.8; // learning rate

    int action;
    int reward;

    vector<int> actions; // action space

    for (int i = 0; i < 10; i++)
        actions.push_back(i); // define list of actions 0-10

    vector<float> qvals(actions.size(), 0); // initialise zeros

    // main loop of RL stuff here
    for(size_t i = 0; i < NTimesteps; ++i) {
        action  = selectAction();
        reward  = getReward(action);
        qvals   = updateQvals(qvals,action,reward,alpha); 
        cout << qvals[action] << endl; // just for debugging

    }
    return 0; 
}

int selectAction() {
    int action = (rand() % 10); // select one of the possible actions
    return action;
}

int getReward(int action) {
    // TODO define some reward table that actually depends on action
    int reward = (rand() % 100); // returns between 0-1.0
    return reward;
}

vector<float> updateQvals(vector<float> qvals, int action,int reward,const float alpha) 
{
    qvals[action] = qvals[action] + alpha*(reward - qvals[action]);
    return qvals;
}
