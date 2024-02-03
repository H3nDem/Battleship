from random import randint

from tkinter import*
fen1=Tk()

def init_board(): # Create grid
    global a, b
    a = randint(0,9)
    b = randint(0,9)
    print("Ship position :", a, ",", b)
    for i in range(10):
        for j in range(10):
            canvas.create_rectangle(i*50,j*50,(i+1)*50,(j+1)*50,fill='blue')
    canvas.update()


def start_game(): # game function
    init_board()
    tries = 5
    
    while(tries != 0):
        x = int(input("x : "))
        y = int(input("y : "))
        
        if (x == a and y == b): # Ship has been hit
            canvas.create_rectangle(a*50,b*50,(a+1)*50,(b+1)*50,fill='red')
            print("Hit ! You win, GG!")
            break
        elif (a-1 <= x <= a+1 and b+1 >= y >= b-1): # Ship neighboring tile has been hit
            canvas.create_rectangle(x*50,y*50,(x+1)*50,(y+1)*50,fill='orange')
            print("Pretty close...")
        else:
            canvas.create_rectangle(x*50,y*50,(x+1)*50,(y+1)*50,fill='green')
            print("Miss")
            
        canvas.update()
        tries -= 1
        
    if (tries == 0):
        print("You lost, better luck next time")


button = Button(fen1, text="Quit", command=fen1.destroy)
button.pack(side=LEFT)
button = Button(fen1, text="Play", command=start_game)
button.pack(side=LEFT)
canvas = Canvas(fen1, bg="white", width=500, height=500)
canvas.pack()
fen1.mainloop()



