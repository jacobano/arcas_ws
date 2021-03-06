/*!
 * \file
 * \brief Main class to implement standar communication for ros
 *  Control the arm simulated in gazebo.
 */
#ifndef ROSCOMMUNICATION_H
#define ROSCOMMUNICATION_H
#include <ros/ros.h>
#include <arcas_msgs/QuadStateEstimationWithCovarianceStamped.h>
#include <arcas_msgs/QuadControlReferencesStamped.h>


/*!
 * \brief Framerate for this node.
 */
#define SEND_RATE 100.0


/*!
 * \brief Take off altitude (used also to minimum commanded altitude
 */
#define TAKE_OFF_Z 0.3

/*!
 * \brief Maximum altitude, commands above this altitude will be truncated.
 */
#define CATEC_MAX_Z 3.0

/*!
 * \brief Maximmum velocity for the uav.
 */
#define MAXIMUM_VELOCITY 2.0

using namespace arcas_msgs;

/*!
 * \brief Class to communicate with ROS.
 */
class RosCommunication
{
public:
   RosCommunication(ros::NodeHandle *n,int uavId);

   /*!
    * \brief Get control message from ROS.
    * \return Quad control references message
    */
   QuadControlReferencesStamped getQuadControlReferences();

   /*!
    * \brief to set quad sate estimation that have to be sent
    * \param Quad State Estimation message.
    */
   void setQuadStateEstimation(QuadStateEstimationWithCovarianceStamped q_state);

private:

   /*!
    * \brief quad Control references callback to receive control data from ros nodes.
    * \param Quad Control References Stamped
    */
   void quadControlRefCallback(const QuadControlReferencesStamped::ConstPtr& odom);

   /*!
    * \brief Send loop, to maintaing fixed step.
    * \param TimerEvent data from ROS.
    */
   void sendLoop(const ros::TimerEvent& te);

   /*!
    * \brief To publish quad state estimation message
    */
   ros::Publisher quad_state_pub_;

   /*!
    * \brief To receive control commands from other ros nodes.
    */
   ros::Subscriber quad_control_references_sub_;

   /*!
    * \brief Timer to run a fixed step
    */
   ros::Timer send_loop_timer_;

   /*!
    * \brief Quad State Estimation message to send
    */
   arcas_msgs::QuadStateEstimationWithCovarianceStamped quad_state_to_send_;

   /*!
     *\brief we do not have to send state if seq do not incremented.
     */
   uint32_t _last_seq;

   /*!
    * \brief Hold last quad control references message.
    */
   arcas_msgs::QuadControlReferencesStamped last_quad_control_references_;

};

#endif // ROSCOMMUNICATION_H
