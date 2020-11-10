#S = [v; x]

function Si1 = runge_kutta_4(Si, Ti, Dt, w, m)
  Si1 = Si + (Dt * integral4(Si, Ti, Dt, w, m));
endfunction

function integral = integral4(Si, Ti, Dt, w, m)
  k1 = state(Si, Ti, w, m);
  k2 = state(Si + (k1 * (Dt / 2)), Ti + (Dt / 2), w, m);
  k3 = state(Si + (k2 * (Dt / 2)), Ti + (Dt / 2), w, m);
  k4 = state(Si + (k3 * Dt), Ti + Dt, w, m);
  
  integral = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
endfunction