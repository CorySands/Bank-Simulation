# Terminal Bank Simulation

## Preface 

This is a project that I created in my Programming Data Structures course at Rasmussen University. Accordingly, many specifications were centered around the project description. 

 

## Overview 

Terminal Bank Simulation is a C++ project that processes a timed simulation of a bank with a procedural progress report. Once the program is launched, it will begin at 10:00 AM (bank opening) and continue until the time reaches 1:00 PM (bank closes). The following sections each represent a concept of the program: 

- Handling simulation time
- Simulation actors
- Handling customers  
- Displaying data

## Handling Simulation Time 

As stated in the overview, the bank simulation begins at 10:00 AM and finishes at 1:00 PM. Time in the simulation is processed at a minute to second scale. So, every second that the program is running, a minute will be represented in the simulation. This is done to allow the user to see how the simulation acts over time while providing a more streamlined time frame. Therefore, the simulation will run for a total of three minutes. 

For every minute in simulation there are changes to the actors and data. This includes actions like processing customers, moving customers, and transacting with customers. Constructing the program with this in mind allows data changes to be seen periodically. 

 

## Simulation Actors 

To understand how the program works, it is first important to understand what actors are present. These actors are the customers, tellers, and simulation manager. 

 

## Customers 

Customers are what make up most of the important data in the simulation. A new customer enters the bank at random and is stored in an initial queue. The queue represents every customer that is waiting to be processed. Ideally, customers are moved out of this queue as quickly as possible since the waiting queue feeds into the three teller lines. Therefore, if the queue starts to accumulate customers, it means that the tellers and teller lines are all full. 

When a customer is moved to a teller line, they will have to wait a certain number of in-simulation minutes to be serviced. The time that the customer must wait is determined by the transaction time applied to customers on instantiation. For example, if a customer is given a transaction time of 5, it means that the customer and teller will interact for 5 simulation minutes or 5 real-time seconds. Since each customer is placed into a line with other customers, the total time that they wait will be determined by the transaction time set for the customers ahead of them. 

Finally, when the customer’s transaction is complete, they will be removed from the line and will be stored as a processed customer in a queue. This is done so that the simulation manager can access customer averages and relevant data once the simulation is complete. 

 

## Tellers 

The role of a teller is simple and for the specifications of the project acts primarily as a means of organization. When the simulation begins, three tellers will be created. However, only one teller will be used at the beginning. As the program progresses and more customers are added, the line of the first teller will fill up. Once a teller is responsible for four customers, their line is considered full and will require another teller to be added to help manage the influx. Therefore, when each teller is active and addressing their maximum of four customers, additional customers will be placed in a general storage used to represent the waiting area of the bank.



## Simulation Manager

The simulation manager acts as the main controller in the simulation. It will remove and add tellers as the customer count increases and decreases. The simulation manager is also responsible for increasing the simulation time, displaying updated information every second, and moving customers. And finally, when the simulation is finished, the manager is responsible for calculating data averages and displaying them in the terminal.



## Summary

The terminal bank simulation program functions by adding customers at random and processing their data with tellers and a simulation manager. The tellers act to store groups of customers and interact with them. Customers are moved around by the simulation manager and will ultimately be stored in a vector of processed customers. When the simulation is complete, the simulation manager will calculate the average values and relevant data of customers and display the data to the user.

