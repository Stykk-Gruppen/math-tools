
#Set primtall for kroppen vi jobber med
p = 13

#Sett inn polynom
def polynomial(x):
  return (x**7 + x + 1)


def main():
  isReducible = False
  i = 0
  while(i< p):
    if polynomial(i) % p == 0:
      isReducible = True
      print(i)
    i = i + 1

  if isReducible:
    print('Polynom er redusibelt')
  else:
    print('Polynom er IKKE redusibelt')



if __name__ == "__main__":
  main()
