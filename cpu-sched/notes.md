# Insights after running scheduler.py

3 -s 100
0: 2
1: 5
2: 8

Turnaround = (2 + 7 + 15) / 3 = 8 --correct
Response = (2 + 5 + 8) / 3 = 5.33 --wrong

Turnaround (0: 2, 1: 5+2=7, 2: 7+8=15)
Response (0: 0, 1: 0+2=2, 2: 2+5=7)
Avg Response = (0 + 2 + 7) = 9/3 = 3
- First run - Arrival (assume all arives at T0)

Comparing RR to FIFO, response time is much less
0: 0, 1: 1, 2: 2
BUT turnaround is like an illusion (worse if not the same)
0: 4, 1: 11, 2: 15

SJF and FIFO for this set of jobs essentially has the same times because the order each job arrived is their order in increasing runtime

New jobs (0: 10, 1: 1, 2: 8)

FIFO:::
Turnaround => 0: 10, 1: 10+1 = 11, 2: 8+11 = 19
Response => 0: 0, 1: 10, 2: 11
Waiting => 0: 0, 1: 10, 2: 11
Averages::: 
T => (19+11+10)/3 = 40/3 = 10.33
R => (0+10+11)/3 = 21/3 = 7
W => 7

SJF:::
Turnaround => 1: 1, 2: 1+8 = 9, 0: 9+10 = 19
Response => 1: 0, 2: 1, 0: 9 (pretty fast, no convoy)
Waiting => same as response (completed jobs first)

T => (1+9+19) = 29/3 = 9.66
R => (0+1+9) = 10/3 = 3.33
W => same as response

Comparing SJF and FIFO, all values had a significant decrease in SJF as convoy effect was avoided

RR::: (1s time slices)
(0,1=done,2, 0,2,0,2,0,2
0,2,0,2,0,2,0,2=done,0,0)
Turnaround (0: 19, 1: 2, 2: 17)
Runtime (0: 0, 1: 1, 2: 2) ILLUSION OF FASTTTT
Waiting (0: 9, 1: 1, 2: 9) 
Averages:::
T => (19+2+17)/3 = 38/3 = 12.67
R => (0+1+2)/3 = 1 (Very Low but cmon man)
W => (9+1+9)/3 = 19/3 = 6.33

It feels a lot more responsive because of its fairness. But its almost an illusion because jobs 1 (1->2)and 2 (2->17) turnaround gets sacrificed for the sake of job 3 starting earlier

Loading and finishing takes longer for more jobs, which arguably matters a lot more than the feeling of being serviced earlier. Even overall wait times are longer ToT

In the case of SJFs, if jobs become shorter despite having the same total completion time, values get better (lower response, lower turnaround, lower waits)
probably bc the convoy effect also gets reduced

In a very simplified manner, it seems like turnaround and response is inversely proportional. By setting the quantum slice in RR higher, the turnaround (and wait) is greatly reduced, in exchange for a higher response time. BUT its still hard to obtain the low turnaround of SJF due to the cost of context switching!!