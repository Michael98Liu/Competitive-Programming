n = int(input())

a = set([x for x in input().split()])

notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
# tone, tone, semitone, tone, tone, tone, semitone
tones = [0, 2, 2, 1, 2, 2, 2, 1]

scale = dict()

for i in range(len(notes)):
    s = set()
    ind = i
    for j in tones:
        ind = (ind + j)%12
        s.add(notes[ind])
    scale[notes[i]] = s

active = set([key for key, s in scale.items()])

for i in a:
    for key, s in scale.items():
        if i in s:
            continue
        else:
            if key in active: active.remove(key)
            #print(active, i)


if len(active) == 0:
    print('none')
else:
    a = sorted(active, key=str.lower)
    for s in a:
        print(s, end = " ")
print()
