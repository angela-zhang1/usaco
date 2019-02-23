"""
ID: angela.11
LANG: PYTHON3
TASK: gift1
"""

#this is... also kind of a mess
#opening the files
giftIn = open('gift1.in', 'r')
giftOut = open('gift1.out', 'w')
gifts = giftIn.readlines() #turns the file into a list
giftIn.close()
numPeople = gifts[0].strip() #the number of gift givers
count = 0 #variable to keep track of how far we are in the list
finalMoney = {}

while (count < int(numPeople)):
    finalMoney[gifts[count+1].strip()] = 0 #creating a dictionary to store the money people have
    count= count+1
finalCount = 0
for finalCount in range (0, count):
    gift1 = gifts[count+2].strip().split() #turns amount of money of first person into a list
    if ((int)(gift1[1]) != 0):
        finalMoney[gifts[count+1].strip()] = finalMoney[gifts[count+1].strip()] + int(gift1[0]) % int(gift1[1]) - int(gift1[0]) #adds leftover money to the person's account
        for x in range(count+3, count+3+int(gift1[1])):
            finalMoney[gifts[x].strip()] = finalMoney[gifts[x].strip()] + int(gift1[0])//int(gift1[1]) #adds money to recipients of first person's money
    else:
        pass
    count = count + 2 + int(gift1[1])
for t in range(0, finalCount+1):
    giftOut.write(gifts[t+1].strip() + ' ' + str(finalMoney[gifts[t+1].strip()]) + '\n')
giftOut.close()
