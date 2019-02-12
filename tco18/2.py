class WordAndPhraseDiv1:
    def findNumberOfPhrases(self, w):
        count = 0
        consec = 1
        ret = 1

        for i in range(1, len(w)):
            if w[i] == '_' and i != len(w) - 1:
                if w[i+1] == '_':
                    consec += 1
                elif ord(w[i+1]) > 57 or ord(w[i+1]) < 48:
                    count += 1

            else:
                if consec != 1:
                    ret *= consec
                    consec = 1

        print(pow(2, count) * ret % (pow(10, 9) + 7) )
        return pow(2, count) * ret % (pow(10, 9) + 7)


w = WordAndPhraseDiv1()
w.findNumberOfPhrases("____")

print(ord('0'), ord('9'))
