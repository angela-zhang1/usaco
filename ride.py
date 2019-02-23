"""
ID: angela.11
LANG: PYTHON3
TASK: ride
"""

#my first USACO problem, which is actually not a mess

rideIn = open('ride.txt', 'r')
rideOut = open('ride1.txt', 'w')

cows = rideIn.readlines()
comet = list(cows[0].strip())
group = list(cows[1])
totalComet = 1
totalGroup = 1
for item in comet:
    totalComet*=(ord(item)-64)
for item in group:
    totalGroup*=(ord(item)-64)
    
if totalComet%47 == totalGroup%47:
    rideOut.write("GO\n")
else:
    rideOut.write("STAY\n")
rideIn.close()
rideOut.close()
