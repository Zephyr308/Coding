## **Enhanced simulation_overview.md**


# Simulation Overview

This simulation models a **2D drone navigating an environment** using **FMCW radar**. It demonstrates the full radar signal processing chain in MATLAB, integrated with drone navigation and collision avoidance logic.

---

## **Core Components**

### 1. Drone

- Moves forward along the X-axis.
- Performs lateral adjustments (Y-axis) to avoid obstacles.
- Position stored as `[X, Y]`.
- Movement controlled by `forward_speed` and `drone_speed`.

### 2. Obstacles

- Randomly initialized positions and velocities.
- Updated each frame.
- Bounded within the simulation environment.
- Multiple obstacles allow for realistic dynamic scenarios.

### 3. FMCW Radar Simulation

- Generates **beat signals** for each obstacle.
- Includes realistic noise modeling.
- Computes **Range-Doppler map** via 2D FFT.
- Doppler estimation uses relative velocity magnitude of obstacles.

### 4. Collision Detection & Avoidance

- Detects the closest obstacle to the drone.
- If distance < `collision_threshold`, the drone moves laterally away.
- Ensures smooth navigation and avoids collisions.

### 5. Visualization

- **Environment Map**: shows positions of drone and obstacles in 2D.
- **Range-Doppler Map**: shows object range vs. relative velocity.
- Updated in real-time each frame.

---

## **Modular Design**

Each function has a single responsibility:

| Function | Purpose |
|----------|---------|
| `initializeObstacles.m` | Randomly initializes obstacles |
| `updateObstacles.m` | Updates positions each frame |
| `generateBeatMatrix.m` | Generates FMCW radar beat signals |
| `computeRangeDoppler.m` | Computes 2D FFT to produce Range-Doppler map |
| `detectClosestObstacle.m` | Finds closest obstacle to drone |
| `avoidCollision.m` | Moves drone laterally to avoid collisions |
| `visualizeSimulation.m` | Updates all visualizations |

---

## **Simulation Parameters**

- Radar: FMCW, carrier frequency 77 GHz, bandwidth 150 MHz, chirp duration 1 ms.
- Drone: Forward speed configurable, lateral movement for avoidance.
- Obstacles: Random initial positions and velocities, bounded environment.
- Noise: Gaussian noise simulating radar signal imperfections.

---

## **Extensibility**

This modular setup allows:

- Adding more advanced **trajectory planning**.
- Implementing **obstacle prediction**.
- Exporting simulation data for analysis.
- Extending to **3D simulations** including altitude control.
