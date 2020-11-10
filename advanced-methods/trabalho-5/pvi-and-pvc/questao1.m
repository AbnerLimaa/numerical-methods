#intervalo = [inicio, fim]
#S = [v; x]

function resultado = questao1(S0, intervalo, delta_t, erro, w, m)
  Sant = zeros(2, 1);
  Snovo = S0;
  ant = 0;
  novo = 1;
  
  while (abs((novo - ant) / novo) >= erro)
    ant = novo;
    Sant = Snovo;
    
    Snovo = S0;
    for Ti = intervalo(1,1) : delta_t : intervalo(1,2)
      Snovo = runge_kutta_4(Snovo, Ti, delta_t, w, m);
    endfor
    
    novo = Snovo(2, 1);
    delta_t /= 2;
  endwhile
  
  resultado = Snovo;
endfunction