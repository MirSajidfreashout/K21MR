from tkinter import *
root = Tk()
root.geometry("400x400")
root.title("Main Menu")
var=StringVar()
head = Label(root, textvariable=var)
var.set("PIZZA DELIVERY SYSTEM\nARE YOU A:")
head.pack()


# function to bring the customer main menu window
def customer_window():
    newWindow = Toplevel(root)
    newWindow.geometry("400x400")
    newWindow.title("Customer")
    order = Button(newWindow, text="Order Pizza", width=25, command=order_window)
    cancel = Button(newWindow, text="Cancel Order", width=25, command=cancel_window)
    track_order = Button(newWindow, text="Track Order", width=25, command=track_window)
    exit_button = Button(newWindow, text="Exit", width=25, command=newWindow.destroy)
    order.pack()
    cancel.pack()
    track_order.pack()
    exit_button.pack()

# function to bring the vendor main menu window
def vendor_window():
    newWindow = Toplevel(root)
    newWindow.geometry("400x400")
    newWindow.title("Vendor")
    new_pizza_order = Button(newWindow, text="New Pizza Order", width=25, command=go_back)
    cancelled_order = Button(newWindow, text="Cancelled Order", width=25, command=go_back)
    served_order = Button(newWindow, text="Served Order", width=25, command=go_back)
    pending_order = Button(newWindow, text="Pending Order", width=25, command=go_back)
    new_pizza_order.pack()
    cancelled_order.pack()
    served_order.pack()
    pending_order.pack()

# function to bring the pizza selection menu window
def order_window():
    orderWindow = Toplevel(root)
    orderWindow.geometry("400x400")
    orderWindow.title("Order Pizza")
    name_label = Label(orderWindow, text="Name")
    name_label.grid(row=0, column=0)
    name_entry = Entry(orderWindow)
    name_entry.grid(row=0, column=1)
    address_label = Label(orderWindow, text="Address")
    address_label.grid(row=1, column=0)
    address_entry = Entry(orderWindow)
    address_entry.grid(row=1, column=1)
    type_label = Label(orderWindow, text="Pizza Type")
    type_label.grid(row=2, column=0)
    type1 = IntVar()
    type2 = IntVar()
    type3 = IntVar()
    Checkbutton(orderWindow, text="Type 1", variable=type1).grid(row=2, column=1)
    Checkbutton(orderWindow, text="Type 2", variable=type2).grid(row=2, column=2)
    Checkbutton(orderWindow, text="Type 3", variable=type3).grid(row=2, column=3)
    mobile_num_label = Label(orderWindow, text="Mobil No.")
    mobile_num_label.grid(row=3, column=0)
    mobile_num_entry = Entry(orderWindow)
    mobile_num_entry.grid(row=3, column=1)
    email_label = Label(orderWindow, text="E-Mail")
    email_label.grid(row=4, column=0)
    email_entry = Entry(orderWindow)
    email_entry.grid(row=4, column=1)
    go_back = Button(orderWindow, text="Go Back", command=orderWindow.destroy).grid(row=5, column=0)
    order = Button(orderWindow, text="Order Now", command=ordered_window_final).grid(row=5, column=1)
    go_back.pack()
    order.pack()

# function to show that the pizza is ordered
def ordered_window_final():
    new = Toplevel(root)
    new.geometry("400x400")
    new.title("Ordered")
    Label(new, text="Ordered", font=(17)).pack(padx=20, pady=20)

# function to show the pizza order cancellation window
def cancel_window():
    cancelWindow = Toplevel(root)
    cancelWindow.geometry("400x400")
    cancelWindow.title("Cancel Order")
    name_label = Label(cancelWindow, text="Name")
    name_label.grid(row=0, column=0)
    name_entry = Entry(cancelWindow)
    name_entry.grid(row=0, column=1)
    order_id_label = Label(cancelWindow, text="Order ID")
    order_id_label.grid(row=1, column=0)
    order_id_entry = Entry(cancelWindow)
    order_id_entry.grid(row=1, column=1)
    Button(cancelWindow, text="Go Back", command=cancelWindow.destroy).grid(row=2, column=0)
    Button(cancelWindow, text="Cancel Order").grid(row=2, column=1)

# function to show the order tracking window
def track_window():
    trackWindow = Toplevel(root)
    trackWindow.geometry("400x400")
    trackWindow.title("Track Order")
    track_id_label = Label(trackWindow, text="Order ID")
    track_id_label.grid(row=0, column=0)
    track_id_entry = Entry(trackWindow)
    track_id_entry.grid(row=0, column=1)

def go_back():
    go_back = Toplevel(root)
    go_back.geometry("400x400")
    go_back.title("Under Construction")
    Label(go_back, text="Under Construction", font=20).pack(padx=50, pady=50)

customer_window_button = Button(root, text="Customer", width=25, command=customer_window)
vendor_window_button = Button(root, text="Vendor", width=25, command=vendor_window)
exit_button = Button(root, text="Exit",command=root.destroy, width=25)

customer_window_button.pack()
vendor_window_button.pack()
exit_button.pack()

root.mainloop()