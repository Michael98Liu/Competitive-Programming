n = int(input())
boats = [0]*n

for i in range(n):
    a = int(input())
    boats[i] = a


bridge_down = 1
latest = boats[0] + 1800
waiting = 1
time = 0
time_drop = 0

for i in range(1,n):
    if bridge_down:
        if boats[i] - latest < 120:
            # do not raise the bridge
            waiting += 1
        else:
            bridge_down = 0
            time_raise = latest - 60
            time_past = time_raise + 60 + 20*waiting
    else:
        # bridge is raised up
        if boats[i] - time_past < 120:
            time_drop = boats[i] + 20 + 60
        else:
            time += time_drop - time_raise
            bridge_down = 1
            waiting = 1

    print(bridge_down, time)

if bridge_down:
    time += 120 + 20 * waiting
else:
    time += time_drop - time_raise

print(time)
