from doctest import master
from tkinter import *
import time
root = Tk()
root.geometry("400x400")
root.title("Main Menu")
var=StringVar()
head = Label(root, textvariable=var)
var.set("PIZZA DELIVERY SYSTEM\nARE YOU A:")
head.pack()

def customer_window():
    newWindow = Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Customer")
    order = Button(newWindow, text="Order Pizza", width=25, command=order_window)
    cancel = Button(newWindow, text="Cancel Order", width=25, command=cancel_window)
    track_order = Button(newWindow, text="Track Order", width=25, command=track_window)
    exit_button = Button(newWindow, text="Exit", width=25, command=newWindow.destroy)
    order.pack()
    cancel.pack()
    track_order.pack()
    exit_button.pack()

def vendor_window():
    newWindow = Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Vendor")
    new_pizza_order = Button(newWindow, text="New Pizza Order", width=25, command=newWindow.destroy, pady=10)
    cancelled_order = Button(newWindow, text="Cancelled Order", width=25, command=newWindow.destroy)
    served_order = Button(newWindow, text="Served Order", width=25, command=newWindow.destroy)
    exit_button = Button(newWindow, text="Pending Order", width=25, command=newWindow.destroy)
    new_pizza_order.pack()
    cancelled_order.pack()
    served_order.pack()
    exit_button.pack()

def order_window():
    orderWindow = Toplevel(master)
    orderWindow.geometry("500x500")
    orderWindow.title("Order Pizza")
    
    go_back = Button(orderWindow, text="Go Back", command=orderWindow.destroy).grid(row=0, column=0)
    order = Button(orderWindow, text="Order Now", command=ordered_window_final).grid(row=0, column=1)
    go_back.pack()
    order.pack()

def ordered_window_final():
    ordered_final = Tk()
    ordered_window_final = Toplevel(ordered_final)
    ordered_window_final.geometry("200x200")
    label1 = Label(ordered_final, text="Ordered")
    label1.pack()
    ordered_window_final.destroy()

def cancel_window():
    cancelWindow = Toplevel(master)
    cancelWindow.geometry("500x500")
    cancelWindow.title("Cancel Order")

def track_window():
    trackWindow = Toplevel(master)
    trackWindow.geometry("500x500")
    trackWindow.title("Track Order")

customer_window_button = Button(root, text="Customer", width=25, command=customer_window)
vendor_window_button = Button(root, text="Vendor", width=25, command=vendor_window)
exit_button = Button(root, text="Exit",command=root.destroy, width=25)

customer_window_button.pack()
vendor_window_button.pack()
exit_button.pack()

root.mainloop()