from doctest import master
import tkinter as tk
root = tk.Tk()
root.geometry("400x400")
root.title("Main Menu")
var=tk.StringVar()
head = tk.Label(root, textvariable=var)
var.set("PIZZA DELIVERY SYSTEM\nARE YOU A:")
head.pack()

def customer_window():
    newWindow = tk.Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Customer")

    order = tk.Button(newWindow, text="Order Pizza", width=25, command=newWindow.destroy)
    cancel = tk.Button(newWindow, text="Cancel Order", width=25, command=newWindow.destroy)
    track_order = tk.Button(newWindow, text="Track Order", width=25, command=newWindow.destroy)
    exit_button = tk.Button(newWindow, text="Exit", width=25, command=newWindow.destroy)
    order.pack()
    cancel.pack()
    track_order.pack()
    exit_button.pack()

def vendor_window():
    newWindow = tk.Toplevel(master)
    newWindow.geometry("500x500")
    newWindow.title("Vendor")
    new_pizza_order = tk.Button(newWindow, text="New Pizza Order", width=25, command=newWindow.destroy, pady=10)
    cancelled_order = tk.Button(newWindow, text="Cancelled Order", width=25, command=newWindow.destroy)
    served_order = tk.Button(newWindow, text="Served Order", width=25, command=newWindow.destroy)
    exit_button = tk.Button(newWindow, text="Pending Order", width=25, command=newWindow.destroy)
    new_pizza_order.pack()
    cancelled_order.pack()
    served_order.pack()
    exit_button.pack()


customer_window_button = tk.Button(root, text="Customer", width=25, command=customer_window)
vendor_window_button = tk.Button(root, text="Vendor", width=25, command=vendor_window)
exit_button = tk.Button(root, text="Exit",command=root.destroy, width=25)

customer_window_button.pack()
vendor_window_button.pack()
exit_button.pack()

root.mainloop()