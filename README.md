# Spring 2020 CS124 Team Project Report: A COVID-19 Wiki

# • Listing of team members and workload or contributions to the project

## Brian Yu - General design, organization and writingparts of the code

## Kenneth Lai - Research, writing parts of the code

## Vincent Li - Documentation, writing parts of thecode

## Zhexian Liu - Debugging, structuring, and writingparts of the code


##• Purpose

The purpose of this assignment is to address an issue related to COVID-19 and implement a solution to it using the various data structures and algorithms we learned from CS 124. Since it is also our first group project in the class, it will also help us develop our collaboration and leadership skills. For our issue, we chose the lack of reliable information out there on COVID-19. As you can see in the figure to the right, according to a study published by Reuters, 38% of false claims regarding COVID-19 are straight up, completely fabricated. Social media is a huge propagator for this type of information, such as misleading videos, "gurus" pushing fake remedies, and comments from the president telling people to inject disinfectants. Because of this, we wanted to create a wiki that would help educate the public and turn them in the right direction. Specifically, this wiki will be targeted towards bay area users since the data we gathered on testing centers are from around here. On the expected impact of our project, we are not expecting the people who stubbornly refuse to wash their hands, or who go to work and meet clients without wearing a mask, to instantly change after reading our wiki. Instead, we are hoping people who wish to become more informed can find an easy place to learn with condensed information.

![Alt Text]()

##• Planning and organization

Q: What input does the program need from the user? Why?

A: We will need the following inputs from the user:
Choice of operation to be performed
Type in the keyword for searching algorithm
 
Q: If any complex objects were used, how did you decide what objects needed to be defined and used? 

A: We defined several complex objects, and we decide to use a complex object when we are having a piece of information that contains multiple parts. For example, the test location contains address, name, and city, therefore we implemented it as a class.
 
Q: What functions are included and how did you decide which operations go into functions? 

A: The implementations of each function are explained in detail below.
 
Q: What is the program flow? How did you decide on the program flow? 

A: A flowchart has been drawn below.
 
Q: How do you decide that your program is complete?

A: We decided the program was near completion when we started to run out of time. Even though we would've liked to implement more features such as a word suggestion function, we decided it was more important to perfect our existing code than tack on more potentially flawed features.

We began planning our project by brainstorming project ideas that seem feasible on a google doc, these included financial planning services for the people that recently lost their jobs, a shopping list program that helps people keep track of what to buy, and this wiki that provides credible information about COVID-19. After some discussion, we ultimately narrowed it down to this wiki because we thought that it would better demonstrate what we have learned in this class, utilizing the various data structures and algorithms we have worked on in the past, and has a better purpose that is more relevant to the situation we face right now.

To give a better demonstration of our knowledge, we decided to have different features of our wiki utilize different data structures we have learned. Our original brainstorm was to have seven different options, but as time went on and some of our features took too long to implement, we narrowed it down to five features at the end. In order to use these features, the user only needs to input integers to signify which action they would like to take. In the search symptoms function, they need to type in a keyword.
Our organization and planning of the five different features, as well as how specific we want each step to be is demonstrated by the graph below.

