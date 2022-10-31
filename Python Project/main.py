from doctest import master
from tkinter import *
root = Tk()
root.geometry("400x400")
root.title("Customer Menu")

def order_pizza_window():
    newWindow = Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Order Pizza")
    exit_button = Button(newWindow, text="exit", width=25, command=newWindow.destroy)
    exit_button.pack()

def cancel_order_window():
    newWindow = Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Order Pizza")
    exit_button = Button(newWindow, text="exit", width=25, command=newWindow.destroy)
    exit_button.pack()

def track_order_window():
    newWindow = Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Track Order")
    exit_button = Button(newWindow, text="exit", width=25, command=newWindow.destroy)
    exit_button.pack()

button_order = Button(root, text="Order Pizza", width=25, command=order_pizza_window)
button_cancel = Button(root, text="Cancel Order", width=25, command=cancel_order_window)
button_track = Button(root, text="Track Order", width=25, command=track_order_window)

button_order.pack()
button_cancel.pack()
button_track.pack()

root.mainloop()