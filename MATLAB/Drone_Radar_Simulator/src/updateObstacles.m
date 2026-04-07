function obstacles = updateObstacles(obstacles, num_chirps, T, max_range)
% Updates obstacle positions each frame
for i=1:length(obstacles)
    obstacles(i).X = obstacles(i).X + obstacles(i).Vx*num_chirps*T;
    obstacles(i).Y = obstacles(i).Y + obstacles(i).Vy*num_chirps*T;
    % Keep obstacles within environment bounds
    obstacles(i).X = max(min(obstacles(i).X, max_range), 0);
    obstacles(i).Y = max(min(obstacles(i).Y, 10), -10);
end
end
