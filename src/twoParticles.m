function twoParticles
%function twoParticles draws planetary motion of three planets in imaginary solar system
  figure(1);
  hold on;
  
  G = 0.000667;
  dt =15;
 
   
  starx = 320;
  stary = 240;
  M_s = 1098900; 
  
  planet1x = 170;
  planet1y = 240;
  ay = 0;
  ax = 0;
  M1 = 0.5974;
  angle_radians = 0;
  dx = 0;
  dy = 0;
  D = 0;
  A = 0;
  vx = 0;
  vy = 2;
  
  
  planet2x = 100;
  planet2y = 100;
  ay2 = 0;
  ax2 = 0;
  M2 = 0.1974;
  angle_radians2 = 0;
  dx2 = 0;
  dy2 = 0;
  D2 = 0;
  A2 = 0;
  vx2 = 0;
  vy2 = 2;
  
  
  planet3x = 250;
  planet3y = 100;
  ay3 = 0;
  ax3 = 0;
  M3 = 1;
  angle_radians3 = 0;
  dx3 = 0;
  dy3 = 0;
  D3 = 0;
  A3 = 0;
  vx3 = 0;
  vy3 = 2;
  
   planet4x = 300;
  planet4y = 100;
  ay4 = 0;
  ax4 = 0;
  M4 = 3;
  angle_radians4 = 0;
  dx4 = 0;
  dy4 = 0;
  D4 = 0;
  A4 = 0;
  vx4 = 0;
  vy4 = 2;
  
  while(1)
   
    scatter3(starx,stary,0,100,"k");
    scatter3(planet1x, planet1y,0,M1*10,"k");
    scatter3(planet2x, planet2y,0,M2*10,"k");
    scatter3(planet3x,planet3y,0,M3*10,"k");
    scatter3(planet4x, planet4y,0,M4*10, "k");
    drawnow;
    view(40,35);
    
    dx = starx   - planet1x;
    dy = stary - planet1y;
    D = sqrt(dx.^2 + dy^2);
    if D == 0
      break;
    endif
    angle_radians = atan2(dy,dx);
    
    A = (G*M_s) / D.^2;
    planet1ax = A*cos(angle_radians);
    planet1ay = A*sin(angle_radians);
    vx+= planet1ax*dt;
    vy+=planet1ay*dt;
    planet1x+=vx*dt;
    planet1y+= vy*dt;
    
    %--------------------------------
    dx2 = starx - planet2x;
    dy2 = stary - planet2y;
    D2 = sqrt(dx2.^2 + dy2^2);
    if D2 == 0
      break;
    endif
    angle_radians2 = atan2(dy2,dx2);
    
    A2 = (G*M_s) / D2.^2;
    ax2= A*cos(angle_radians2);
    ay2 = A*sin(angle_radians2);
    vx2+= ax2*dt;
    vy2+=ay2*dt;
    planet2x+=vx2*dt;
    planet2y+= vy2*dt;
    
    %--------------------------------
    dx3 = starx - planet3x;
    dy3 = stary - planet3y;
    D3 = sqrt(dx3.^2 + dy3^2);
    if D3 == 0
      break;
    endif
    angle_radians3 = atan2(dy3,dx3);
    
    A3 = (G*M_s) / D3.^2;
    ax3 = A*cos(angle_radians3);
    ay3 = A*sin(angle_radians3);
    vx3+= ax3*dt;
    vy3+=ay3*dt;
    planet3x+=vx3*dt;
    planet3y+= vy3*dt;
    %--------------------------------
    
    dx4 = starx - planet4x;
    dy4 = stary - planet4y;
    D4 = sqrt(dx4.^2 + dy4^2);
    if D4 == 0
      break;
    endif
    angle_radians4 = atan2(dy4,dx4);
    
    A4 = (G*M_s) / D4.^2;
    ax4 = A*cos(angle_radians3);
    ay4 = A*sin(angle_radians3);
    vx4+= ax4*dt;
    vy4+=ay4*dt;
    planet4x+=vx4*dt;
    planet4y+= vy4*dt;
    
    
   
  
  endwhile   
endfunction