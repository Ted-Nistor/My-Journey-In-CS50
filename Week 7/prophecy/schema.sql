CREATE TABLE IF NOT EXISTS new_students(
    id INTEGER,
    student_name TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS houses(
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS relationships(
    ID integer,
    student_name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);