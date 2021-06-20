def knapsack(p, w, W):

    pbyw = []
    for i in range(len(p)):
        pbyw.append(p[i]/w[i])
    
    #Sort based on profit by weight ratio
    zipped = sorted(zip(pbyw, p, w), reverse=True)

    pbyw, p, w = zip(*zipped)     # Unzipping values
    profit = 0
    count = 0
    
    for i in range(len(p)):
        if(W > 0 and w[i] <= W):    # Checking weight exceeds or not!
            profit += p[i]
            W -= w[i]
            count += 1 #Variable for checking all elements included or not
        else:
            break
    if(W > 0 and count < len(p)):   # Adding partial amount of profit
        profit += p[i]*(W/w[i])
    print("{:.2f}".format(float(profit)))



n = int(input())
profit = []
weight = []
W = int(input("Enter bag capacity: "))
for i in range(n):
    profit.append(int(input()))
for i in range(n):
    weight.append(int(input()))
knapsack(profit, weight, W)
