# import mysql.connector

# mydb = mysql.connector.connect(
#   host="localhost",
#   user="root",
#   password="root",
#   database = "mydatabase"
# )

# mycursor = mydb.cursor()

# # mycursor.execute("CREATE DATABASE mydatabase")

# # mycursor.execute("SHOW DATABASES")

# # mycursor.execute("CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))")

# sql = "INSERT INTO customers (name, address) VALUES (%s, %s)"
# # val = ("John", "Highway 21")
# val1 = ("Ayan", "Highway 34")
# mycursor.execute(sql, val1)

# mydb.commit()

# mycursor.execute("SELECT * FROM customers")

# myresult = mycursor.fetchall()

# for x in myresult:
#     print(x)

# # print(mydb)
