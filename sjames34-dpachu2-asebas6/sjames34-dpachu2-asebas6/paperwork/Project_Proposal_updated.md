CS 225 Data Structures

Project Proposal (dpachu2-asebas6-sjames34)

1. **Leading Question:** We are looking at the Bitcoin Alpha trust weighted signed network data set and looking to implement a general search tool to be able to parse through all the members who were rated, who rated them, their rating, and when it happened. We are looking to rank the members based on their trustworthiness, which is a combination of their rating and how many ratings they have. A side question/idea is that we can use a search algorithm in order to recommend a user with a high rating with other users that have higher ratings as well.
2. **Dataset Acquisition:** We are acquiring our dataset from the Stanford Large Network Dataset Collection, where our dataset (soc-sign-bitcoin-alpha) is listed under Social networks. The dataset can be downloaded directly from the site, where it is downloaded as a csv file. The Bitcoin Alpha trust weighted signed network is a dataset containing a list of ratings, separated by the source and the target of the rating. The data is separated into Source, Target, Rating, and Time. Time in our case isn&#39;t too necessary, but we are looking to sort the data with the Target as the parent node and the Source as the children. The key or edge weight of each child node would be the rating itself. One difference we will implement is that we will scale the rating differently in order to work better with our algorithms. In the case of error we wouldn&#39;t be able to correct them, so we would simply discard the data.
3. **Algorithms:** We will first be implementing a Breadth First Search Traversal on the data set. We would store the data in a tree where each level contains the ratings for the user corresponding to that level. A breadth first search would allow us to gain insightful data on individual users. Along with that, it would also be able to tell us if two separate nodes are connected in terms of the data, or if we are looking at two unconnected nodes/reviewees. The first algorithm we will implement is making a graphical output of the graph. We will use the force-directed graph drawing algorithm in order to visually show users along with their average rating. The nodes will represent that specific user&#39;s average rating, where the size of the node is determined by the number of ratings that user has received and the color, from shades of red to green, will represent the average rating for that user. Additionally, we will implement Dijkstra&#39;s Algorithm in order to create a method to help users find trustworthy people to trade with. The idea is that Dijstra&#39;s algorithm will return the shortest path from one vertex to another, and in the context of our dataset, this means that it will give us a connection between two users with the lowest weight(or best possible rating). This is useful for users as they can find trustworthy people to trade with through their mutuals.
4. **Timeline:Graph**

- Data acquisition (04/09/2021)
- Data processing (04/16/2021)
- Graphic output of graph(force-directed graph drawing) (04/23/2021)
- Dijkstra&#39;s Algorithm(04/30/2021)
- BFS (05/07/2021)
- Final Project Deliverables (05/11/2021)