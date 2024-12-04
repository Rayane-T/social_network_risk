PBA - Session 1 Problem 2

First Idea :
-> Algorithm which assesses the risk 
-> Sorting the risk 
-> Removing up to a threshold  


Post: Tuple –> <Id, Risk level> 
 

Storage Capacity S, Processing Capacity P, Id -> decimal, Risk must be between in [0,1] 

Heap of Tuple –> <Id, Risk level>, priority on Risk Level

If Risk Level > Threshold then stored
Process (store the posts) -> if saturated then choose the lowest risk post to remove

Abtract data structure : Linked list