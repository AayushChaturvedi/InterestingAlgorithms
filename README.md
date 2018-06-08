# InterestingAlgorithms
This repository contains implementations of a few interesting and famous algorithms.


# Prim's Algorithm
   Prime's Algorithms for finding the Minimum Spanning Tree in an undirected, weighted graphs, edge weights are considered
   distinct and non-negative. The input format is as below : 
    
        First line : < number of nodes in the graphs = n > < number of edges in the graphs = m >
        Next m lines : < source node for edge j, considering 1 based indices > < destination > < edge weight >
   
  The programme is a brute force direct implementation O(n * n), for a faster one, min heaps should be used instead of vector
  (list). 


# Huffman Encoding
   This is the famous Huffman Encoding for losseless data compression. The programme generates binary codes which are prefix
   free (and therefore no clashing possible) and are such that it minimises the Average Encoding Length, defined as ( for a 
   binary Tree T, where the probability of occurence of the ith data string in the given data is pi and depth of the data 
   string in T is di)
    
   ![imageforgithub](https://user-images.githubusercontent.com/23059190/41183893-a48242e2-6b9a-11e8-8935-6097893c4ebe.png)
 
   The input format is as below : 
        
        First line : < The number of strings to be encoded, the strings are numbered 1,2,...n >
        Next n lines : < The frequency of the ith string in the ith line >
        
   The programme is a brute force direct implementation O(n * n), for a faster one, min heaps should be used instead of vector
   (list).
