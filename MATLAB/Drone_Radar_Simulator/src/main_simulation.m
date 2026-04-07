clc; clear; close all;
addpath(genpath('src')); % Include all src files

% Load default configuration
config.num_targets = 5;
config.num_chirps = 64;
config.num_frames = 50;
config.max_range = 200;
config.collision_threshold = 40;
config.drone_speed = 0.5;
config.forward_speed = 1.0;
config.noise_level = 0.01;

c = 3e8; fc = 77e9; B = 150e6; T = 1e-3; K = B/T; Fs = 2*B; t = 0:1/Fs:T-1/Fs;

% Initialize drone and obstacles
drone = struct('pos',[0,0]);
obstacles = initializeObstacles(config.num_targets);

% Setup visualization
visualizeSimulation(drone, obstacles, zeros(config.num_chirps,length(t)), config, true);

% Simulation loop
for frame = 1:config.num_frames
    obstacles = updateObstacles(obstacles, config.num_chirps, T, config.max_range);
    beat_matrix = generateBeatMatrix(drone, obstacles, t, c, fc, K, config.noise_level, config.num_chirps);
    RD_mag = computeRangeDoppler(beat_matrix, config.num_chirps, length(t));
    closest_obs = detectClosestObstacle(drone, obstacles);
    drone = avoidCollision(drone, closest_obs, config);
    visualizeSimulation(drone, obstacles, RD_mag, config, false);
    drone.pos(1) = drone.pos(1) + config.forward_speed;
end
