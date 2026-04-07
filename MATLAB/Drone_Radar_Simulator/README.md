# 2D Autonomous Drone Radar Simulator

A MATLAB-based simulation of a **2D autonomous drone** using **FMCW radar** for **obstacle detection and avoidance**. This project demonstrates real-time radar signal processing, drone navigation, and dynamic visualization.

---

## **Features**

- FMCW radar simulation generating **Range-Doppler maps**.
- Multiple moving obstacles with random velocities.
- **Collision avoidance** with smooth lateral adjustments.
- **Dual visualization**:
  - 2D environment map showing drone and obstacles.
  - Range-Doppler radar map.
- **Modular and professional code structure**:
  - Easily extendable and configurable.
- Realistic noise modeling for radar signal simulation.
- Configurable parameters for quick experimentation.

---

## **Installation**

1. Clone the repository:
```bash
git clone https://github.com/your-username/DroneRadarSimulator.git
```
2. Open MATLAB and navigate to the ```src``` folder.
3. Add all subfolders to MATLAB path:
```matlab
addpath(genpath('path_to_repository/DroneRadarSimulator'));
```
---
## **Usage**

Run the main simulation script:
```matlab
main_simulation
```
Optional: Modify configuration parameters in ```main_simulation.m``` or ```load config.mat```.
---
## **Configuration Parameters**
- ```num_targets```: Number of obstacles in the environment.
- ```num_chirps```: Number of radar chirps per frame.
- ```num_frames```: Number of frames in the simulation.
- ```max_range```: Maximum radar detection range (meters).
- ```collision_threshold```: Distance threshold for collision avoidance (meters).
- ```drone_speed```: Lateral speed of drone for collision avoidance.
- ```forward_speed```: Forward speed of the drone.
- ```noise_level```: Standard deviation of radar signal noise.

---
## **Visualization**
1. **2D Environment Map**: Red circle = Drone, Black crosses = Obstacles. Shows forward (X-axis) and lateral (Y-axis) positions.
2. **Range-Doppler Map**: 2D FFT of radar beat signals showing object range vs. relative velocity.

---

## **Future Improvements**
- **Path prediction** for smoother trajectory planning.
- **Kalman filter** for obstacle tracking.
- 3D extension including altitude navigation.
- Interactive controls to manually adjust drone path.
- Export Range-Doppler data for offline analysis.

## License
MIT License


