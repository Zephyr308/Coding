function beat_matrix = generateBeatMatrix(drone, obstacles, t, c, fc, K, noise_level, num_chirps)
% Generates FMCW radar beat signals from obstacles
N = length(t);
beat_matrix = zeros(num_chirps, N);
for k=1:num_chirps
    t_chirp = t + (k-1)*1e-3;
    beat_sum = zeros(size(t));
    for i=1:length(obstacles)
        R = sqrt((obstacles(i).X - drone.pos(1))^2 + (obstacles(i).Y - drone.pos(2))^2);
        fd = 2*((obstacles(i).Vx^2 + obstacles(i).Vy^2)^0.5)*fc/c;
        rx = cos(2*pi*(fc + fd)*(t_chirp - 2*R/c) + pi*K*(t_chirp - 2*R/c).^2);
        tx = cos(2*pi*fc*t_chirp + pi*K*t_chirp.^2);
        beat_sum = beat_sum + tx.*rx;
    end
    beat_sum = beat_sum + noise_level*randn(size(beat_sum));
    beat_matrix(k,:) = beat_sum;
end
end
