/*
Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
*/

overLapped interval is
 start = max(a.start, b.start)
    end = min(a.end, b.end) 
