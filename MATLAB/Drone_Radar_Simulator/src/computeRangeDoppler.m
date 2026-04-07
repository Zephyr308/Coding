function RD_mag = computeRangeDoppler(beat_matrix, num_chirps, N)
% Computes 2D FFT to create Range-Doppler map
RD_map = fft2(beat_matrix, num_chirps, N);
RD_map = fftshift(RD_map,1);
RD_mag = abs(RD_map);
end
