function drone = avoidCollision(drone, closest_obs, config)
% Simple lateral collision avoidance
if closest_obs.distance < config.collision_threshold
    if closest_obs.Y - drone.pos(2) > 0
        drone.pos(2) = drone.pos(2) - config.drone_speed;
    else
        drone.pos(2) = drone.pos(2) + config.drone_speed;
    end
    drone.pos(2) = max(min(drone.pos(2), 10), -10); % clamp lateral position
end
end
