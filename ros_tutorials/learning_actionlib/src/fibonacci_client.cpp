#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <learning_actionlib/FibonacciAction.h>

void done_cb (const actionlib::SimpleClientGoalState &state,
              const learning_actionlib::FibonacciResultConstPtr &result) {
}

void active_cb () {
}

void feedback_cb (const learning_actionlib::FibonacciFeedbackConstPtr &feedback) {
        for (int i = 0; i < feedback->sequence.size(); i++) {
                std::cout << feedback->sequence.at(i) << " ";
        }
        std::cout << std::endl;
}

int main (int argc, char **argv)
{
        ros::init(argc, argv, "test_fibonacci");

        // create the action client
        // true causes the client to spin its own thread
        actionlib::SimpleActionClient<learning_actionlib::FibonacciAction> ac("fibonacci", true);

        ROS_INFO("Waiting for action server to start.");
        // wait for the action server to start
        ac.waitForServer(); //will wait for infinite time

        ROS_INFO("Action server started, sending goal.");
        // send a goal to the action
        learning_actionlib::FibonacciGoal goal;
        goal.order = 20;
        ac.sendGoal(goal, done_cb, active_cb, feedback_cb);

        //wait for the action to return
        bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

        if (finished_before_timeout)
        {
                actionlib::SimpleClientGoalState state = ac.getState();
                ROS_INFO("Action finished: %s",state.toString().c_str());
        }
        else
                ROS_INFO("Action did not finish before the time out.");
        
        //exit
        return 0;
}