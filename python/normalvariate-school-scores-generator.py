import random

full_score = int(input ("Input Full Score : "));
standard_score = int(input ("Input Standard Score : "));
sigma = float(input ("Input Default Sigma : "));

if (standard_score == 0):
    standard_score = full_score * random.uniform(0.6,0.9);

if (sigma == 0):
    sigma = random.uniform(3,15);

while True:
    NV = int(random.normalvariate (standard_score,sigma));
    if (NV > full_score):
        continue
    print ("%d"%NV);
    if(str(input("continue?(Y/N)")).lower() == "n"):
        break;

