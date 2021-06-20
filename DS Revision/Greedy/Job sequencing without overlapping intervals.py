n = int(input())
start_time = []
end_time = []
for i in range(n):
    a = list(map(int,input().split()))
    start_time.append(a[0])
    end_time.append(a[1])

zipped = sorted(zip(end_time, start_time))

end_time, start_time = zip(*zipped)

ans = [(start_time[0], end_time[0])]

temp = 0
i = 1
while i<len(start_time):
    if end_time[temp] <= start_time[i]:
        ans.append((start_time[i], end_time[i]))
        temp = i
    i += 1
print(ans)
