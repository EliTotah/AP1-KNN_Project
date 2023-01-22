
# project1---Ofir-and-Eli
> The project in advanced programming.

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Data](#data)
* [implemantation](#implemantation)
* [Usage](#usage)
* [Project Status](#project-status)


## General Information
- This project is eli and ofir shared project as part of an advanced programming course.
- The project illustrates the [KNN algorithm](https://medium.com/swlh/k-nearest-neighbor-ca2593d7a3c4)
- This project designed to classify different types of objects according to the reception of the input vector and the classification of the type by calculating the distance of K nearest neighbors and determining according to the type of most of them.

![image](https://user-images.githubusercontent.com/118715083/209792303-14ada464-df17-4de1-a617-4a0c5110e097.png)
![image](https://user-images.githubusercontent.com/118715083/209792410-cd47a439-4393-4692-aad1-7921903de4ad.png)

-This program works in a configuration of TCP conversation of a server against a client
-In addition, the project supports the running of several clients at the same time as well as multiple trheads.

## Technologies Used
- The Euclidean distance and the Manhattan distance is a special case of the Minkowski distance. the only diifarent is the change in P value during the calculation.  Therefore during the calculation of the above two distances (Euclidean distance and the Manhattan distance) we will call the function which calculates the Minkowski distance.  
- Two vector have to be in the same length in order to calculates the distance between them. 
- The algorithm makes use of the KNN concept and calculates the distance between the input vector and the data using the matrica chosen by the user and according to the appropriate formulas.
- The K neighbors should be at most the length of the data in addition the K received by the user should be real positive
-TCP communication between server and client

## Data
The calculate of the [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance) - ![Screenshot_20221123_101742](https://user-images.githubusercontent.com/118715083/203510546-bc36f231-0b07-4b3f-89e5-b12ca9ab8faa.png)
![Euclidean_distance_2d](https://user-images.githubusercontent.com/118715083/203536338-8bd7e5e9-48a5-4ef5-bae2-c49ca261d734.svg)


The calculate of the [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance) - ![Screenshot_20221123_100306](https://user-images.githubusercontent.com/118715083/203513971-89d3b242-5d3d-44a4-9fa0-5ddd11cdd237.png)

The calculate of the [Manhattan distance](https://en.wikipedia.org/wiki/Taxicab_geometry) - ![Screenshot_20221123_115455](https://user-images.githubusercontent.com/118715083/203517631-3a4bcc08-8ed8-41c1-b193-b494f6257dff.png)
![Manhattan_distance](https://user-images.githubusercontent.com/118715083/203536363-93432c2a-f0b6-45d2-8f6a-9f21b7eb6863.svg)


The calculate of the [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance) - ![Screenshot_20221123_115706](https://user-images.githubusercontent.com/118715083/203518048-e34ef8f9-a3c1-403c-9069-4c41c3c990f6.png)

The calculate of the [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance) - ![Screenshot_20221123_115919](https://user-images.githubusercontent.com/118715083/203518497-db9a36bc-8691-4a64-a2ef-2ada194f5330.png)

## implemantation

We designed the code so the client and the server will be separated, it means the client doesn't know what the server is about to send - all it does is sending messages and receiving messages. Our Server supports unlimited-size messages and unlimited amount of columns in a csv file.

We changed the classifier to work when facing an ambiguous decision. The classifier chooses the closest type which has the most votes.

We used the Command design pattern in order to handle commands in the server. The base Command class is an abstract class, it has access to client data and IO, and each command subclass implements the execution differently. The commands are stored in a vector which is also used as a menu, and they are invoked using an index given by the client.
- We implemented the program by dividing it into a number of different files according to the main purpose of each file where the division is:
1. Distance.cpp + Distance.h : 
These files are responsible for calculating the distance between the vectors using the familiar formulas I mentioned above when we noticed that the Euclidean distance and the Manhattan distance are a special case of the Minikowski distance, so the calculation of these two distances was carried out using the Minikowski distance functionץ
2. Validation.cpp + Validation.h:
These files are responsible for checking the correctness of the input when for each test we have performed appropriate treatment so that the user understands what his error is and corrects it as necessary.
Some of the checked errors-
- No vectors larger than 300 numbers were entered
- The length of the two vectors is equal, otherwise the distance between them cannot be calculated
- Checking that all characters entered are numbers or other valid characters from ("-", "+", ".", " ")
and more
-In addition to this, adjustments were made to the correctness check according to the line of arguments from the user that includes the insertion of K neighbors, routing to the data file according to which we will perform the classification of the type of the object and selection of the appropriate matrix according to which we will perform the distance calculation:
- K entered by the user must be correct, that is, really positive and within the range of the selected data.
- The vector entered by the user must be of a length corresponding to the number of characteristics of the object tagged in the data, in order to enable the calculation of the distance between the vector received from the user and the selected data.
3. KNN.cpp + KNN.h:
These files generalize the operation of the KNN algorithm by creating a distance vector containing the distance between the vector entered by the user and the other vectors created from the data entered by the user
- The implementation first generates vectors from the received data and calculates their distance from the vector entered by the user. Each such distance enters the vector as a pair along with the string containing the type of that object from the data in order to save the type corresponding to each calculated distance. Then that vector is sorted of pairs in order to finally select the K nearest neighbors according to the sorting of the distances from the input vector and to classify the type of the user's vector according to the type of most of the K nearest neighbors.
4. client.cpp - this file is responsible for the client's actions vis-a-vis the server when the client is responsible for receiving from the user a running line that includes the vector he wishes to check, the type of distance with which the user wishes to perform the calculation, and the K number.
In addition, The client will receive in the launch line a port number where the server is listening and in addition the IP address of the server.
The customer is responsible for some of the correctness checks of the information entered by the user, including-
- Checking that the characters entered into the vector are legal characters of numbers and logical mathematical signs only.
- Furthermore, the customer verifies that the user has indeed entered a valid distance hammer for testing.
- Positive K number as required
5. server.cpp - this file summarizes the actions of the server in front of the client when the server will receive as an argument the routing to the data on which it will perform the analysis, and a port number on which it must listen. The server will receive as a message from the client the line of arguments that the user entered and with the help of the KNN algorithm, will perform an analysis of the vector entered by the user against the data that it will check and finally deliver to the client the type that best suits the user's requests.
- The server is responsible for checking that the vector entered by the user will be the same size as the vectors in the data that the server was asked to check.
- In addition to this, when calling the KNN algorithm at the server, additional normality checks are performed as we detailed in the KNN file that was already built earlier.
In addition The server uses multithreading for two reasons:
•	Handling multiple clients simultaneously.
•	Handling time-consuming commands on a different thread so the client will be able to send more messages while waiting.
![image](https://user-images.githubusercontent.com/118715083/209791721-75a66328-e9ad-4524-91d2-978acc09b88a.png)
6.  CLI.cpp- The CLI department of the server creates a specific client for the server and the same department manipulates the running course of the menu by creating a vector of commands according to the options defined in the menu
7.  CLIClient.cpp - The CLI class of the client creates a specific client at the client and the same class manipulates the running course of the menu on the client side by creating a vector of commands adapted to the client according to the options defined in the menu.
 the **Command design pattern** in order to handle commands in the server:
The UML sketch-
![image](https://user-images.githubusercontent.com/118715083/213931425-7044c2db-52c8-4c74-bfe3-8bc570732127.png)

## Compile using this commends:
It should be noted that in order to run the program correctly, two terminal windows must be opened, one for the client and one for the server,
An example of a run will be detailed below when we specify the run commands to be executed in the server window and the run commands in the client window.

in order to compile the program we use in make file so this is the commend bellow to run:
```bash
# Compile the program on Linux:
make
```
```bash
# Run the program on Linux in the server terminal:
./server.out file port
```

```bash
# Run the program on Linux in the client terminal:
./client.out ip port
```

```bash
# An example of a run command line in the server:
./server.out  8080
```
```bash
# An example of a run command line in the client:
./client.out 127.0.0.1 8080 
Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file
2. algorithm setting
3. classify data
4. display results
5. download results
8. exit
```
## Usage
The KNN algorithm can compete with the most accurate models because it makes highly accurate predictions. Therefore, you can use the KNN algorithm for applications that require high accuracy but that do not require a human-readable model.

The quality of the predictions depends on the distance measure. Therefore, the KNN algorithm is suitable for applications for which sufficient domain knowledge is available. This knowledge supports the selection of an appropriate measure.

The KNN algorithm is a type of lazy learning, where the computation for the generation of the predictions is deferred until classification. Although this method increases the costs of computation compared to other algorithms, KNN is still the better choice for applications where predictions are not requested frequently but where accuracy is important.

## Project Status
Project is: _in progress_

## Contact
Created by [_@Ofirroth_](https://github.com/Ofirroth)  [_@EliTotah_](https://github.com/EliTotah) - feel free to contact me!

<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
