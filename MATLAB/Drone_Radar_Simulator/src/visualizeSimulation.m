function visualizeSimulation(drone, obstacles, RD_mag, config, init_flag)
% Updates 2D environment map and Range-Doppler map
persistent env_plot obs_plot RD_img
if init_flag
    % Initial plot setup
    subplot(1,2,1); % Environment
    env_plot = plot(drone.pos(2), drone.pos(1),'ro','MarkerSize',10,'LineWidth',2); hold on;
    obs_plot = gobjects(config.num_targets,1);
    for i=1:config.num_targets
        obs_plot(i) = plot(obstacles(i).Y, obstacles(i).X,'kx','MarkerSize',8,'LineWidth',2);
    end
    xlabel('Lateral Y (m)'); ylabel('Forward X (m)'); title('Drone Environment Map');
    legend('Drone','Obstacles'); grid on; hold off;
    
    subplot(1,2,2); % Range-Doppler
    RD_img = imagesc(linspace(0,config.max_range,size(RD_mag,2)), linspace(-50,50,size(RD_mag,1)), RD_mag);
    xlabel('Range (m)'); ylabel('Velocity (m/s)'); title('Range-Doppler Map');
    colorbar; set(gca,'YDir','normal');
else
    set(env_plot,'XData',drone.pos(2),'YData',drone.pos(1));
    for i=1:config.num_targets
        set(obs_plot(i),'XData',obstacles(i).Y,'YData',obstacles(i).X);
    end
    set(RD_img,'CData',RD_mag);
    drawnow;
end
end
