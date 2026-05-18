from sqlalchemy import Column, Integer, Float, String
from sqlalchemy.orm import declarative_base

Base = declarative_base()

class VehicleData(Base):

    __tablename__ = "vehicle_data"

    id = Column(Integer, primary_key=True)
    device_id = Column(String)
    latitude = Column(Float)
    longitude = Column(Float)
    speed = Column(Float)
    altitude = Column(Float)
    gps_time = Column(String)
    address = Column(String)
