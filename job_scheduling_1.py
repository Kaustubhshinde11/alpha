def job_sequencing():
    n=int(input("Enter the total number of jobs"))
    job=[]
    deadline=[]
    profit=[]
    for i in range(n):
        job.append(input("Enter the name of the job"))
        deadline.append(int(input("Enter the deadline of the job")))
        profit.append(int(input("Enter the profit of the job")))

    max_deadline=max(deadline)
    schedule=[None]*max_deadline

    sorted_jobs=sorted(zip(job,deadline,profit),key=lambda x:x[2], reverse=True)
    print(sorted_jobs)

    total_profit=0

    for j in sorted_jobs:
        current_deadline=j[1]
        slot=current_deadline-1
        while slot>=0:
            if schedule[slot] is None:
                schedule[slot]=j[0]
                total_profit+=j[2]
                break
            slot-=1

    return schedule,total_profit

schedule,profit=job_sequencing()
print(schedule)
print(profit)
