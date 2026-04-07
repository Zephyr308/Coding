function obstacles = initializeObstacles(N)
% Initializes N obstacles with random positions and velocities
for i=1:N
    obstacles(i).X = randi([20,100]);
    obstacles(i).Y = rand()*10 - 5;
    obstacles(i).Vx = rand()*0.2 - 0.1;
    obstacles(i).Vy = rand()*0.2 - 0.1;
end
end
