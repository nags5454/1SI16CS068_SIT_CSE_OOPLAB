#include <bits/stdc++.h>

// Given the list of processes, their burst times, priority and arrival times, write a program to implement the preemptive priority
// CPU scheduling algorithm. Display the turnaround time and waiting time for each process. Also, calculate the average turnaround time
// and average waiting time.

//**PS : FIND SAMPLE OUTPUT AFFIXED AT THE END OF THIS FILE.

using namespace std;

struct ProcessBlock
{
  public:
    int arrivalTime, burstTime, waitTime, turnAroundTime, priority, remainingTime;

    //scheduled : set to 'true' if 'this' process is already scheduled. Else to 'false'.
    bool scheduled;
};



int curProcessSchedule(struct ProcessBlock processList[], int n, int timeElapsed)
{
    //Utility function to determine the next process to be scheduled.
    //The process with the highest priority among all the processes
    //That have already up until now is selected.

    int minPr = INT_MAX, pos;

    for (int i = 0; i < n; ++i)
    {
        if (!processList[i].scheduled &&
            processList[i].priority < minPr &&
            processList[i].arrivalTime <= timeElapsed)
                minPr = processList[i].priority, pos = i;
    }

    return pos;
}

int findTotalBurstTime(struct ProcessBlock processList[], int n)
{
    //Utility function to find the total burst time of the process list.
    int totalTime = 0;
    for (int i = 0; i < n; ++i)
    {
        totalTime += processList[i].burstTime;
    }

    return totalTime;
}

void updateProcessWaitTimes(struct ProcessBlock processList[], int n, int pos, int timeElapsed)
{
    //Utility function to the update the wait-time of each process after each second.
    //Currently executing process if not considered since it isn't waiting but instead
    //is executing.

    int timeAlloted;
    for (int i = 0; i < n; ++i)
    {
        timeAlloted = processList[i].burstTime - processList[i].remainingTime;
        if (!processList[i].scheduled && pos != i&& timeElapsed >= processList[i].arrivalTime)
            processList[i].waitTime = timeElapsed - processList[i].arrivalTime - timeAlloted + 1;
    }
}

void printGanttChart(struct ProcessBlock processList[], int n, int order[], int totalTime)
{
    //Utility function to print the Gantt Chart of the scheduling that has occured.
    //It also prints the average wait-time and average turn-around-time.
    double avgWaitTime = 0, avgTurnAroundTime = 0;

    cout << endl;
    cout << "Gantt Chart : \n";

    for (int i = 0; i < totalTime; ++i)
        cout << "[" << order[i] << "]";

    cout << endl;
    cout << endl;

    cout << "Process\t\tWait-Time\tTurn-Around-Time\n";

    
    for (int i = 0; i < n; ++i) {
        cout << "P[" << i << "]\t\t" << processList[i].waitTime << "\t\t" << processList[i].turnAroundTime << endl;
        avgWaitTime += processList[i].waitTime, avgTurnAroundTime += processList[i].turnAroundTime;
    }

    cout << endl;

    cout << "\nAverage Turn Around Time : " << avgTurnAroundTime / n;
    cout << "\nAverage Wait Time : " << avgWaitTime / n;
}

void scheduleProcessList(struct ProcessBlock processList[], int n)
{
    //Function to perform the Priorty coupled with
    //SRTF(Shortest Remaining Time First) sheduling task.
    //The process with the highest priority is scheduled first.
    //(0 = highest priority, INT_MAX = least priority)

    //var to hold the index of the process to schedule in each iteration of the loop.
    int pos;
    //var to keep track of the total burst time of the processes.
    int totalTime = findTotalBurstTime(processList, n);
    //var to keep track of the ordering of the processes.
    int order[totalTime];

    for (int timeElapsed = 0; timeElapsed < totalTime; ++timeElapsed)
    {
        pos = curProcessSchedule(processList, n, timeElapsed);

        order[timeElapsed] = pos;
        --processList[pos].remainingTime;

        updateProcessWaitTimes(processList, n, pos, timeElapsed);

        if (processList[pos].remainingTime == 0) {
            processList[pos].scheduled = true;
            processList[pos].turnAroundTime = timeElapsed - processList[pos].arrivalTime + 1;
        }
    }

    printGanttChart(processList, n, order, totalTime);

    cout << endl;
}

void readProcessList(struct ProcessBlock processList[], int n)
{
    //Utility function to read the burst-time, arrival-time and
    //priority of each process in the list sequentially.
    //
    //It also assigns default values to waitTime, remainingTime
    //and scheduled var.

    cout << "Enter details : \n";

    for (int i = 0; i < n; ++i)
    {
        cout << "Process [" << i << "]\n";
        cout << "Arrival Time : ";
        cin >> processList[i].arrivalTime;
        cout << "Burst Time : ";
        cin >> processList[i].burstTime;
        cout << "Priority : ";
        cin >> processList[i].priority;
        cout << endl;

        processList[i].remainingTime = processList[i].burstTime;
        processList[i].waitTime = 0;
        processList[i].scheduled = false;
    }
}

int main()
{
    //var to keep track of number of processes to schedule.
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    struct ProcessBlock processList[n];

    readProcessList(processList, n);

    scheduleProcessList(processList, n);

    return 0;
}

//Sample Output [1]: 
/*
    Enter the number of processes : 2
    Enter details :
    Process [0]
    Arrival Time : 0
    Burst Time : 4
    Priority : 2
    Process [1]
    Arrival Time : 0
    Burst Time : 4
    Priority : 00
    Gantt Chart :
    [1][1][1][1][0][0][0][0]
    Process         Wait-Time       Turn-Around-Time
    P[0]            4               8
    P[1]            0               4
    Average Turn Around Time : 6
    Average Wait Time : 2
*/

//Sample Out [2] : 
/*
    Enter the number of processes : 2
    Enter details :
    Process [0]
    Arrival Time : 0
    Burst Time : 3
    Priority : 2
    Process [1]
    Arrival Time : 1
    Burst Time : 3
    Priority : 0
    Gantt Chart :
    [0][1][1][1][0][0]
    Process         Wait-Time       Turn-Around-Time
    P[0]            3               6
    P[1]            0               3
    Average Turn Around Time : 4.5
    Average Wait Time : 1.5
*/







#include <bits/stdc++.h>

// write a program to implement producer-consumer problem using semaphores.

//**PS : FIND SAMPLE OUTPUT AFFIXED AT THE END OF THIS FILE.

using namespace std;

typedef bool semaphore;

class Message
{
    //Class to hold the shared memory buffer.

  private:
    //semaphore to gain access to buffer.
    semaphore empty;
    //buffer as a shared memory between consumer and producer.
    string buffer;

  public:
    Message()
    {
        //Initially buffer is empty and thus empty = true;
        empty = true;
    }

    string read()
    {
        //Function to read the contents of the shared memory(buffer)
        //and subsequently empty the buffer.
        //This also sets empty = true.

        if (empty)
            return "empty";
        empty = true;
        return buffer;
    }

    void write(string item)
    {
        //Function to write onto the shared memory(buffer)
        //and subsequently set empty = false.

        if (!empty)
            return;
        buffer = item;
        empty = false;
    }
};

class Producer
{
  private:
    //var to keep track of the current message to write onto the
    //shared buffer.
    int i;

    //var to hold the pointer to shared Message object.
    Message *message;

    //vector of strings to write onto the shared buffer.
    vector<string> stringList;

  public:
    Producer(Message &message)
    {
        i = 0;
        this->message = &message;
        stringList.push_back("Humpty dumpty.");
        stringList.push_back("Sat on a wall.");
        stringList.push_back("Humpty had a great fall.");
        stringList.push_back("EOF");
    }

    void runProducer()
    {
        //Function to simulate the Producer functionality.
        cout << "MESSAGE SENT : " << stringList[i] << endl;
        message->write(stringList[i]);
        ++i;
    }
};

class Consumer
{
  private:
    //var to hold pointer to the shared Message object.
    Message *message;

    //var to hold the current message read from the shared buffer.
    string messageRead;

  public:
    Consumer(Message &message)
    {
        this->message = &message;
    }

    void runConsumer()
    {
        //Function to simulate the Consumer functionality.
        messageRead = message->read();
        if (messageRead == "empty")
            return;
        if (messageRead == "EOF")
            exit(0);

        cout << "\tMESSAGE READ : " << messageRead << endl;
    }
};

int main()
{
    Message message = Message();
    Producer producer = Producer(message);
    Consumer consumer = Consumer(message);

    for (int i = 0;; ++i)
    {
        //An infinite loop wherein the calls to producer.runProducer()
        //and consumer.runConsumer() are alternated.
        if (i % 2 == 0)
            producer.runProducer();
        else
            consumer.runConsumer();
    }
    return 0;
}

//Sample Output :
/*
    MESSAGE SENT : Humpty dumpty.
            MESSAGE READ : Humpty dumpty.
    MESSAGE SENT : Sat on a wall.
            MESSAGE READ : Sat on a wall.
    MESSAGE SENT : Humpty had a great fall.
            MESSAGE READ : Humpty had a great fall.
    MESSAGE SENT : EOF
*/












#include <bits/stdc++.h>

// Given the list of processes, their burst times and arrival times, write a program to implement the FCFC(First Come, First Server)
// CPU scheduling algorithm. Display the turnaround time and waiting time for each process. Also, calculate the average turnaround time
// and average waiting time.

//**PS : FIND SAMPLE OUTPUT AFFIXED AT THE END OF THIS FILE.

using namespace std;

struct ProcessBlock
{
  public:
    int arrivalTime, burstTime, waitTime, turnAroundTime;

    //var to keep track of the position at which 'this' process is scheduled.
    int sequence;

    //scheduled : set to 'true' if 'this' process is already scheduled. Else to 'false'.
    //displayed : set to 'false' if 'this' process is alrady displayed. Else to 'false'.
    bool scheduled, displayed;
};

void printUnderScores(int n)
{
    //Utility function to print underscores for Gantt Chart.
    //#underscores = burst-time units.

    for (int i = 0; i < n; ++i)
        cout << " _ ";
}

int findNextSequence(struct ProcessBlock processList[], int n)
{
    //Utility function to find the next process to print
    //Based on the scheduling so achieved.

    //var to keep track of the min arrival time among the non-displayed processes.
    int min = INT_MAX;

    //var to keep track of the non-displayed process with the least arrival-time.
    int pos;

    for (int i = 0; i < n; ++i)
    {
        if (!processList[i].displayed && processList[i].arrivalTime < min)
            min = processList[i].arrivalTime, pos = i;
    }
    processList[pos].displayed = true;
    return pos;
}

void printGanttChart(struct ProcessBlock processList[], int n)
{
    //Function to print the GanttChart of the process scheduling so done.
    //It also prints Average Wait Time and Average Turn Around Time of the processes.

    //var to keep track of next non-scheduled process to schedule.
    int pos;

    double avgWaitTime = 0, avgTurnAroundTime = 0;

    cout << endl;

    cout << "Gantt Chart : \n";
    for (int i = 0; i < n; ++i)
    {
        pos = findNextSequence(processList, n);
        cout << "(" << pos << ")";
        printUnderScores(processList[i].burstTime);
        avgWaitTime += processList[i].waitTime;
        avgTurnAroundTime += processList[i].turnAroundTime;
    }

    cout << endl;
    cout << endl;

    cout << "Process\t\tWait-Time\tTurn-Around-Time\n";

    for (int i = 0; i < n; ++i)
    {
        cout << "P[" << i << "]\t\t" << processList[i].waitTime << "\t\t" << processList[i].turnAroundTime << endl;
    }

    cout << endl;

    cout << "\nAverage Turn Around Time : " << setprecision(2) << avgTurnAroundTime / n;
    cout << "\nAverage Wait Time : " << setprecision(3) << avgWaitTime / n;

    cout << endl;
}

void readProcessList(struct ProcessBlock processList[], int n)
{
    //Utility function to read the burst-time and arrival-time
    //of each process in the list sequentially.
    //
    //It also assigns default values to waitTime, sequence, scheduled
    //and displayed var.

    cout << "Enter details : \n";

    for (int i = 0; i < n; ++i)
    {
        cout << "Process [" << i << "]\n";
        cout << "Arrival Time : ";
        cin >> processList[i].arrivalTime;
        cout << "Burst Time : ";
        cin >> processList[i].burstTime;
        cout << endl;

        processList[i].waitTime = processList[i].sequence = 0;
        processList[i].scheduled = processList[i].displayed = false;
    }
}

int findFirst(struct ProcessBlock processList[], int n)
{
    //Utility function to detemine the next process to schedule based on arrival-time.
    //It checks from the the remaining list of unscheduled processes.

    int min = INT_MAX, pos = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!processList[i].scheduled && processList[i].arrivalTime < min)
            min = processList[i].arrivalTime, pos = i;
    }
    processList[pos].scheduled = true;
    return pos;
}

void scheduleProcessList(struct ProcessBlock processList[], int n)
{
    //Function to perform the FCFS sheduling task.
    //The process with the earliest arrival-time is scheduled first.

    //var to hold the index of the process to schedule in each iteration of the loop.
    int pos;
    //var to keep track of the total time elapsed after each process completion.
    int timeElapsed = 0;

    for (int i = 0; i < n; ++i)
    {
        pos = findFirst(processList, n);
        processList[i].sequence = i;
        processList[i].waitTime = timeElapsed;
        timeElapsed += processList[i].burstTime;
        processList[i].turnAroundTime = timeElapsed - processList[i].arrivalTime;
    }

    printGanttChart(processList, n);
}

int main()
{
    //var to keep track of number of processes to schedule.
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    struct ProcessBlock processList[n];

    readProcessList(processList, n);

    scheduleProcessList(processList, n);

    return 0;
}

//Sample Output :
/*
    Enter the number of processes : 3
    Enter details :
    Process [0]
    Arrival Time : 2
    Burst Time : 4
    Process [1]
    Arrival Time : 0
    Burst Time : 4
    Process [2]
    Arrival Time : 3
    Burst Time : 7
    Gantt Chart :
    (1) _  _  _  _ (0) _  _  _  _ (2) _  _  _  _  _  _  _
    Process     Wait-Time       Turn-Around-Time
    P[0]            0               2
    P[1]            4               8
    P[2]            8               12
    Average Turn Around Time : 7.33
    Average Wait Time : 4
*/
