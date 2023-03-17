import sqlite3

# create a connection to a new or existing database
conn = sqlite3.connect('example.db')

# create a cursor object
cursor = conn.cursor()

# check if the table already exists
cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='students'")
if cursor.fetchone() is not None:
    print("Table already exists.")
else:
    # create the table if it doesn't exist
    cursor.execute('''CREATE TABLE students (
                       id INTEGER PRIMARY KEY,
                       name TEXT,
                       age INTEGER
                    )''')
    print("Table created successfully.")



# insert data into the table
cursor.execute("INSERT INTO students (name, age) VALUES (?, ?)", ('John', 20))

# retrieve data from the table
cursor.execute("SELECT title, release_yearFROM students FROM movies")
rows = cursor.fetchall()
for row in rows:
    print(row)