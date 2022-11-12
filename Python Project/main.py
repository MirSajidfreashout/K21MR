from tkinter import *

root = Tk()
root.geometry("400x400")
root.title("Main Menu")
var = StringVar()
head = Label(root, textvariable=var)
var.set("PIZZA DELIVERY SYSTEM\nARE YOU A:")
head.pack()


# function to show label
def label(windowName, LabelText, rowVal, colVal):
    new_label = Label(windowName, text=LabelText)
    new_label.grid(row=rowVal, column=colVal)


# function to bring the customer main menu window
def customer_window():
    newWindow = Toplevel(root)
    newWindow.geometry("400x400")
    newWindow.title("Customer")
    order = Button(newWindow,
                   text="Order Pizza",
                   width=25,
                   command=order_window)
    cancel = Button(newWindow,
                    text="Cancel Order",
                    width=25,
                    command=cancel_window)
    track_order = Button(newWindow,
                         text="Track Order",
                         width=25,
                         command=track_window)
    exit_button = Button(newWindow,
                         text="Exit",
                         width=25,
                         command=newWindow.destroy)
    order.pack()
    cancel.pack()
    track_order.pack()
    exit_button.pack()


# function to bring the vendor main menu window
def vendor_window():
    newWindow = Toplevel(root)
    newWindow.geometry("400x400")
    newWindow.title("Vendor")
    new_pizza_order = Button(newWindow,
                             text="New Pizza Order",
                             width=25,
                             command=go_back)
    cancelled_order = Button(newWindow,
                             text="Cancelled Order",
                             width=25,
                             command=go_back)
    served_order = Button(newWindow,
                          text="Served Order",
                          width=25,
                          command=go_back)
    pending_order = Button(newWindow,
                           text="Pending Order",
                           width=25,
                           command=go_back)
    main_menu = Button(newWindow,
                       text="Go Back to Main Menu",
                       width=25,
                       command=newWindow.destroy)
    new_pizza_order.pack()
    cancelled_order.pack()
    served_order.pack()
    pending_order.pack()
    main_menu.pack()


# function to bring the pizza selection menu window
def order_window():
    orderWindow = Toplevel(root)
    orderWindow.geometry("400x400")
    orderWindow.title("Order Pizza")
    label(orderWindow, "Name", 0, 0)
    name_entry = Entry(orderWindow)
    name_entry.grid(row=0, column=1)
    label(orderWindow, "Address", 1, 0)
    address_entry = Entry(orderWindow)
    address_entry.grid(row=1, column=1)
    label(orderWindow, "Pizza Type", 2, 0)
    type1 = IntVar()
    type2 = IntVar()
    type3 = IntVar()
    Checkbutton(orderWindow, text="Type 1", variable=type1).grid(row=2,
                                                                 column=1)
    Checkbutton(orderWindow, text="Type 2", variable=type2).grid(row=2,
                                                                 column=2)
    Checkbutton(orderWindow, text="Type 3", variable=type3).grid(row=2,
                                                                 column=3)
    label(orderWindow, "Mobile No.", 3, 0)
    mobile_num_entry = Entry(orderWindow)
    mobile_num_entry.grid(row=3, column=1)
    label(orderWindow, "E-Mail", 4, 0)
    email_entry = Entry(orderWindow)
    email_entry.grid(row=4, column=1)
    go_back = Button(orderWindow, text="Go Back",
                     command=orderWindow.destroy).grid(row=5, column=0)
    order = Button(orderWindow, text="Order Now",
                   command=ordered_window_final).grid(row=5, column=1)
    go_back.pack()
    order.pack()


# function to show that the pizza is ordered
def ordered_window_final():
    new = Toplevel(root)
    new.geometry("400x400")
    new.title("Ordered")
    Label(new, text="Ordered").pack(padx=20, pady=20)


# function to show the pizza order cancellation window
def cancel_window():
    cancelWindow = Toplevel(root)
    cancelWindow.geometry("400x400")
    cancelWindow.title("Cancel Order")
    label(cancelWindow, "Name", 0, 0)
    name_entry = Entry(cancelWindow)
    name_entry.grid(row=0, column=1)
    label(cancelWindow, "Order ID", 1, 0)
    order_id_entry = Entry(cancelWindow)
    order_id_entry.grid(row=1, column=1)
    Button(cancelWindow, text="Go Back",
           command=cancelWindow.destroy).grid(row=2, column=0)
    Button(cancelWindow, text="Cancel Order").grid(row=2, column=1)


# function to show the order tracking window
def track_window():
    trackWindow = Toplevel(root)
    trackWindow.geometry("400x400")
    trackWindow.title("Track Order")
    label(trackWindow, "Order ID", 0, 0)
    track_id_entry = Entry(trackWindow)
    track_id_entry.grid(row=0, column=1)
    Button(trackWindow, text="Go Back",
           command=trackWindow.destroy).grid(row=1, column=0)
    Button(trackWindow, text="Track Order").grid(row=1, column=1)


def go_back():
    go_back = Toplevel(root)
    go_back.geometry("400x400")
    go_back.title("Under Construction")
    Label(go_back, text="Under Construction", font=20).pack(padx=50, pady=50)
    Button(go_back, command=go_back.destroy).grid(row=1,column=1)


customer_window_button = Button(root,
                                text="Customer",
                                width=25,
                                command=customer_window)
vendor_window_button = Button(root,
                              text="Vendor",
                              width=25,
                              command=vendor_window)
exit_button = Button(root, text="Quit", command=root.destroy, width=25)

customer_window_button.pack()
vendor_window_button.pack()
exit_button.pack()

root.mainloop()