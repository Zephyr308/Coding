function closest_obs = detectClosestObstacle(drone, obstacles)
% Returns the obstacle closest to the drone
distances = arrayfun(@(t) sqrt((t.X - drone.pos(1))^2 + (t.Y - drone.pos(2))^2), obstacles);
[min_dist, idx] = min(distances);
closest_obs = obstacles(idx);
closest_obs.distance = min_dist;
end
