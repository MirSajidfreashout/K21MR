import mysql.connector as connector

conn=connector.connect(user="root", password = "root")
c = conn.cursor()

c.execute("create database if not exist bachelorpizza;")
c.execute("use bachelorpizza;")

with open("new.txt") as f:
    c.execute(f.read())
conn.commit()