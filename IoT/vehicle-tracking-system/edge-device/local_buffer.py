import sqlite3

conn = sqlite3.connect("gps_data.db", check_same_thread=False)
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS gps_data (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    latitude REAL,
    longitude REAL,
    speed REAL,
    altitude REAL,
    gps_time TEXT,
    address TEXT,
    uploaded INTEGER DEFAULT 0
)
""")

conn.commit()


def insert_data(data):
    cursor.execute("""
    INSERT INTO gps_data (
        latitude,
        longitude,
        speed,
        altitude,
        gps_time,
        address
    )
    VALUES (?, ?, ?, ?, ?, ?)
    """, (
        data['lat'],
        data['lon'],
        data['speed'],
        data['altitude'],
        data['time'],
        data['address']
    ))

    conn.commit()


def get_pending():
    cursor.execute("""
    SELECT * FROM gps_data
    WHERE uploaded = 0
    """)

    return cursor.fetchall()


def mark_uploaded(record_id):
    cursor.execute("""
    UPDATE gps_data
    SET uploaded = 1
    WHERE id = ?
    """, (record_id,))

    conn.commit()
