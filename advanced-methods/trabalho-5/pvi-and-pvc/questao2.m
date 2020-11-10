function [matriz resul] = questao2(T, P, N, inicio, fim)
  resul = zeros(N+1, 1);
  resul(2:N, 1) -= P/T;
  Dr = (fim - inicio) / N;
  
  matriz = construirMatriz(N-1, Dr, inicio);
  
  resul = resolverSistema(matriz, resul);
endfunction

function matriz = construirMatriz(tam, Dr, inicio)
  matriz = eye(tam+2, tam+2);
  r = inicio;
  
  for i = 2:tam+1
    r += Dr;
    
    matriz(i, i-1) = (1/(Dr*Dr)) - (1/(2*r*Dr));
    
    matriz(i, i) = -(2/(Dr*Dr));
    
    matriz(i, i+1) = (1/(Dr*Dr)) + (1/(2*r*Dr));
  endfor
endfunction

function vetor = resolverSistema(matriz, vetor)
  sub = 0;
  
  for i = 1:columns(matriz)-1
    vetor(i, 1) /= matriz(i, i);
    matriz(i, :) /= matriz(i, i);
    
    sub = -matriz(i+1, i);
    matriz(i+1, :) += sub * matriz(i, :);
    vetor(i+1, 1) += sub * vetor(i, 1);
  endfor
  
  for i = columns(matriz):-1:2
      sub = -matriz(i-1, i);
      matriz(i-1, :) += sub * matriz(i, :);
      vetor(i-1, 1) += sub * vetor(i, 1);
  endfor
endfunction