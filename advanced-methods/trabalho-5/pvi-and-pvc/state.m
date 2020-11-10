#S = [v; x]

function Sd = state(Si, Ti, w, m)
  zeta = 0.05;
  Sd = [(f(Ti) / m) - (2 * zeta * w * Si(1, 1)) - ((w * w) * Si(2, 1)); Si(1, 1)];
endfunction

function force = f(t)
  if(t < 0 || t > 1)
    force = 0;
  elseif(t >= 0 && t <= 0.5)
    force = 4 * t;
  elseif(t > 0.5 && t <= 1)
    force = 2 - (4 * (t - 0.5));
  endif
endfunction