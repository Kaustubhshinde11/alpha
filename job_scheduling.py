def job_schedule():

    n = int(input("Enter the number of jobs"))
    
    jobs = []
    deadline = []
    profit = []

    for i in range(n):
        jobs.append(int(input("Enter the job: ")))
        deadline.append(int(input("Enter the deadline: ")))
        profit.append(int(input("Enter the profit: ")))

    schedule = [None]*max(deadline)


    sorts = sorted(zip(jobs, deadline, profit), key = lambda x:x[2], reverse = True)

    profit = 0
    
    for j in sorts:

        

        curr_deadline = j[1]
        slots = curr_deadline-1

        while slots >= 0:
            if schedule[slots] == None:
                schedule[slots] = j[0]
                profit += j[2]
            slots -= 1

    return  schedule, profit

sch, profit = job_schedule()

print(sch)
print(profit)
                


    
