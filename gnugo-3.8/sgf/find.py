import os
s = 'sgftreeAddComment'
for f in os.listdir('.'):
    if '.c' in f or '.h' in f:
        try:
            ff = open(f)
            if s in ff.read(): 
                print(f)
        except  :
            pass
