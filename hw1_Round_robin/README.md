# Round-robin
## Explanation
Round-robin (RR) is a common scheduling algorithm for CPU scheduling. Each process uses the CPU for a period of time. The length of this time is called time quantum.

We setup a “ready queue” for the processes waiting to use the CPU. When the CPU is not used, we choose the first process in the ready queue to use the CPU.

The process has following information: <br>
<b>process_id</b>, <b>arrival_time</b>, and <b>require_time</b>. 
    
    arrival_time is the time that process enters into the system
    process_id is from small to large according to the arrival_time 
    require_time is the time that process requires to use CPU

If the process runs out of the time quantum and doesn’t finish, the process will return to the ready queue and wait for the next time using the CPU. 

If the process completes before the time quantum runs out, we select the first process in the ready queue to use the CPU. 

If two or more processes enter the ready queue at the same time, the process with the smaller <b>process_id</b> enters the ready queue earlier.

    There is only one CPU in the system.


## Example
Suppose that the time quantum is 3.

|process_id|arrival_time|require_time|
|:--------:|:----------:|:----------:|
|0         |0           |5           |
|1         |2           |2           |

* At time 0, process 0 arrives and no one is using the CPU, so process 0 uses the CPU directly.

* At time 2, process 1 arrives. Since process 0 is using the CPU and doesn’t run out of the time quantum, process 1 enters the ready queue and waits.

* At time 3, process 0 runs out of the time quantum, so it returns to the ready queue. The first process in the ready queue is process 1, so it’s process 1’s turn to use the CPU.

* At time 5, process 1 finishes using the CPU. The first process in the ready queue is process 0, so it’s process 0’s turn to use the CPU.

* At time 7, process 0 finishes using the CPU.

In this example , the ending sequence of the processes is process 1→ process 0.

## Task
* Given n processes with their process_ids, arrival_times and require_times, please using RR scheduling with time quantum = 3, output the finishing order of the processes. 

* The larger the process_id the process is, the later it arrives to the system.

* Time Limit: 3 sec

# I/O

## Input
Start with an integer n, followed by n lines. Each line has three integers, process_id, arrival_time and require_time.

    (n<100, arrival_time<999, require_time<300)

## Output
process_ids, ordered by finishing time, separated by commas. You need to output '\n' in the end of line.

## Example

|Input|Output|
|:---:|:----:|
|3<br>0 0 5<br>1 0 2<br>2 1 3|1,2,0 |
|2<br>0 0 4<br>1 4 3|0,1|

# STL is not allowed
* <stack> <queue> <list> <vector> are not allowed

* main.cpp & function.h 會給你們,不能更改
因此不會有<stack><queue>被宣告
