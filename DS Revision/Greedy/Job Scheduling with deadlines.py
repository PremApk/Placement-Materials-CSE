

deadline = []
profit = []
# Input for deadline and jobs
n = int(input())
for i in range(n):
    a = list(map(int, input().split()))
    deadline.append(a[0])
    profit.append(a[1])

# To find out the size of gantt_chart
max_deadline = max(deadline)

gantt_chart = [0] * max_deadline

# Sort the list based on profit
zipped = sorted(zip(profit, deadline), reverse=True)

profit, deadline = zip(*zipped)

total_profit = 0
for i in range(n):
    j = deadline[i] - 1
    # To check the previous positions before deadline as we can complete a job in anytime before the deadline
    while j >= 0:
        if gantt_chart[j] == 0:
            total_profit += profit[i]
            gantt_chart[j] = profit[i]
            break
        j -= 1
print(gantt_chart, total_profit)