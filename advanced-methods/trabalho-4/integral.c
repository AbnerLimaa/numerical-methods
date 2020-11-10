//#EQUIPE 10
//#GABRIEL FRANÇA LOUREIRO  //#MATRÍCULA: 388835
//#ABNER DE LIMA ARAÚJO    //#MATRÍCULA: 398067
//#MN2 2019
#include <stdio.h>
#include <math.h>
#include <tgmath.h>
#include <stdlib.h>

double fun (double x){
    //SUJEITO A ALTERAÇÃO NA ARGUIÇÃO

    //return (double)cos(x);
    //return (double)(1.0/pow(x, 2.0/3.0));
    return (double)sin(x);
    //return
}
//FUNÇÃO DE ALTERAÇÃO DE VARIÁVEL GAUSS-LEGENDRE
double funcao(double x, double a, double b){
    return (((a + b)/2) + (x * ((a - b)/2)));
}

//FUNÇÃO DE ALTERAÇÃO DE VARIÁVEL GAUSS-CHEBYSCHEV
double funcaoGC(int k, int n){
    return cos(((k - (1.0/2))* M_PI)/n);
}

//FUNÇÃO DE ALTERAÇÃO DE VARIÁVEL EXPONENCIAL SIMPLES
double funcaoExponencial(double a, double b, double alfa){
    return (double)(((a+b)/2.0) + (((b - a)/2.0) * tanh(alfa)));
}

//FUNÇÃO DE ALTERAÇÃO DE VARIÁVEL EXPONENCIAL DUPLA
double funcaoExponencialDupla(double a, double b, double alfa){
    return (double)(((a+b)/2.0) + (((b - a)/2.0) * tanh((M_PI/2.0) * sinh(alfa))));
}

double alpha_u(double alfa){
    return (double)((M_PI/2) * sinh(alfa));
}

double alpha_d(double a, double b, double alfa){
    return (double)(((M_PI * (b - a))/4.0) * (cosh(alfa)/pow(cosh(alpha_u(alfa)),2.0)));
}

double delta_x (double a, double b, int particoes){
    return (double)fabs((b-a)/particoes);
}

double integral_gauss(double a, double b, double tol,
                  const double *w, const double *x, double grau) {
    double x_inicial, x_final, integral_aux, sum, integral = 0, erro, deltaX;
    int particoes = 1;
    int n = 0;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            x_final = x_inicial + deltaX;
            sum = 0;
            for (int i = 0; i < grau; i++) {
                sum += (w[i] * (fun(funcao(x[i], x_inicial, x_final))));
            }
            integral += ((x_final - x_inicial) / 2) * sum;
        }

        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);

    //
    return integral;
}

double Newton_Cotes_1_fechada(double a, double b, double tol){
    double x_inicial, integral = 0, x_final, integral_aux, h;
    int n = 0;
    double erro;
    double deltaX;
    int particoes = 1;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 2;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            x_final = x_inicial + deltaX;
            integral += (h * (fun(x_inicial) + fun(x_final)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);

    //
    return integral;
}

double Newton_Cotes_1_aberta(double a, double b, double tol) {
    double x_inicial, integral = 0, x_final, integral_aux, xm_1, xm_2, h;
    int n = 0;
    double erro;
    double deltaX;
    int particoes = 1;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 3;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            integral += ((3 * h) / 2) * (fun(xm_1) + fun(xm_2));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);

    //
    return integral;
}

double NewtonCotes_2_fechada (double a, double b, double tol){
    double x_inicial, integral = 0, x_final, integral_aux, xm, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 2;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            x_final = x_inicial + deltaX;
            xm = x_inicial + h;
            integral += (h / 3) * ((fun(x_inicial)) + 4 * (fun(xm)) + (fun(x_final)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    return integral;
}

double NewtonCotes_3_fechada (double a, double b, double tol){
    double x_inicial, integral = 0, x_final, integral_aux, xm_1, xm_2, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 3;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            x_final = x_inicial + deltaX;
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            integral += ((3 * h) / 8) *
                    ((fun(x_inicial)) + 3 * (fun(xm_1)) + 3 * (fun(xm_2)) + (fun(x_final)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    //
    return integral;
}

double NewtonCotes_4_fechada (double a, double b, double tol){
    double x_inicial, integral = 0, x_final, integral_aux, xm_1, xm_2, xm_3, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 4;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            x_final = x_inicial + deltaX;
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            xm_3 = xm_2 + h;
            integral += ((2 * h) / 45) *
                    (7 * (fun(x_inicial)) + 32 * (fun(xm_1)) + 12 * (fun(xm_2)) +
                        32 * (fun(xm_3)) + 7 * (fun(x_final)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    //
    return integral;
}

double NewtonCotes_2_aberta (double a, double b, double tol){
    double x_inicial, integral = 0, integral_aux, xm_1, xm_2, xm_3, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 4;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            xm_3 = xm_2 + h;
            integral += ((4 * h) / 3) * (2 * (fun(xm_1)) - (fun(xm_2)) + 2 * (fun(xm_3)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    //
    return integral;
}

double NewtonCotes_3_aberta (double a, double b, double tol){
    double x_inicial, integral = 0, integral_aux, xm_1, xm_2, xm_3, xm_4, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 5;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            xm_3 = xm_2 + h;
            xm_4 = xm_3 + h;
            integral += ((5 * h) / 24) * (11 * (fun(xm_1)) + (fun(xm_2)) + (fun(xm_3)) +
                                        11 * (fun(xm_4)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    //
    return integral;
}

double NewtonCotes_4_aberta (double a, double b, double tol){
    double x_inicial, integral = 0, integral_aux, xm_1, xm_2, xm_3, xm_4, xm_5, h;
    int particoes = 1;
    int n = 0;
    double erro;
    double deltaX;
    do {
        integral_aux = integral;
        integral = 0;
        deltaX = delta_x(a, b, particoes);
        h = deltaX / 6;
        for (n = 0; n < particoes; n++) {
            x_inicial = a + (n * deltaX);
            xm_1 = x_inicial + h;
            xm_2 = xm_1 + h;
            xm_3 = xm_2 + h;
            xm_4 = xm_3 + h;
            xm_5 = xm_4 + h;
            integral += ((6 * h) / 20) *
                    (11 * (fun(xm_1)) - (14 * fun(xm_2)) + (26 * fun(xm_3)) -
                        (14 * fun(xm_4)) + (11 * fun(xm_5)));
        }
        particoes *= 2;
        erro = (double)fabs((integral - integral_aux) / integral);

    } while (erro > tol);
    
    //
    return integral;
}

double GaussLegendre2(double a, double b, double tol){
    double integral, w[2], x[2], grau;
    w[0] = 1;
    w[1] = 1;
    x[0] = - 0.57735;
    x[1] = 0.57735;
    grau = 2;
    integral = integral_gauss(a, b, tol, w, x, grau);
    return integral;
}

double GaussLegendre3(double a, double b, double tol){
    double integral=0;
    double w[3], x[3], grau;
    w[0] = 0.88888;
    w[1] = 0.55555;
    w[2] = 0.55555;
    x[0] = 0;
    x[1] = -0.77459;
    x[2] = 0.774596;
    grau = 3;
    integral = integral_gauss(a, b, tol, w, x, grau);
    return integral;
}

double GaussLegendre4(double a, double b, double tol){
    double integral=0;
    double w[4], x[4], grau;
    w[0] = 0.65214;
    w[1] = 0.65214;
    w[2] = 0.34785;
    w[3] = 0.34785;
    x[0] = -0.3399;
    x[1] = 0.33998;
    x[2] = -0.8611;
    x[3] = 0.86113;
    grau = 4;
    integral = integral_gauss(a, b, tol, w, x, grau);
    return integral;
}

double GaussLegendre5(double a, double b, double tol){
    double integral=0;
    double w[5], x[5], grau;
    w[0] = 0.56888;
    w[1] = 0.47862;
    w[2] = 0.47862;
    w[3] = 0.23692;
    w[4] = 0.23692;
    x[0] = 0;
    x[1] = -0.53846;
    x[2] = 0.53846;
    x[3] = -0.90617;
    x[4] = 0.90617;
    grau = 5;
    integral = integral_gauss(a, b, tol, w, x, grau);
    return integral;
}

double GaussHermite2(){
    double integral = 0, w[2], x[2];

    w[0] = 0.88622;
    w[1] = 0.88622;
    x[0] = -0.70710;
    x[1] = 0.70710;
    for (int i = 0; i < 2; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussHermite3(){
    double integral = 0, w[3], x[3];

    w[0] = 0.29540;
    w[1] = 1.18163;
    w[2] = 0.29540;
    x[0] = -1.22474;
    x[1] = 0;
    x[2] = 1.22474;
    for (int i = 0; i < 3; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussHermite4(){
    double integral = 0, w[2], x[2];

    w[0] = 0.08131;
    w[1] = 0.80491;
    w[2] = 0.80491;
    w[3] = 0.08131;
    x[0] = -1.65068;
    x[1] = -0.52464;
    x[2] = 0.524647;
    x[3] = 1.650680;
    for (int i = 0; i < 5; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussLaguerre2(){
    double integral = 0, w[2], x[2];

    w[0] = 0.85355;
    w[1] = 0.14644;
    x[0] = 0.58578;
    x[1] = 3.41421;
    for (int i = 0; i < 2; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussLaguerre3(){
    double integral = 0, w[3], x[3];

    w[0] = 0.71109;
    w[1] = 0.27851;
    w[2] = 0.01038;
    x[0] = 0.41577;
    x[1] = 2.29428;
    x[2] = 6.28994;
    for (int i = 0; i < 3; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussLaguerre4(){
    double integral = 0, w[4], x[4];

    w[0] = 0.60315;
    w[1] = 0.35741;
    w[2] = 0.03888;
    w[3] = 0.000539295;
    x[0] = 0.32254;
    x[1] = 1.74576;
    x[2] = 4.53662;
    x[3] = 9.39507;
    for (int i = 0; i < 4; i++){
        integral += w[i] * (fun(x[i]));
    }
    return integral;
}

double GaussChebyshev(int n){
    double integral = 0, w = M_PI/n;

    for (int i = 1; i <= n; i++){
        integral += w * (fun(funcaoGC(i,n)));
    }
    return integral;
}

double g_ExpSimples(double a, double b, double alfa){
    double expSimples = funcaoExponencial(a, b, alfa);
    double fun1 = fun(expSimples);
    return (double) (fun1 * ((b - a) / pow(cosh(alfa), 2.0)));
}

double g_ExpDupla(double a, double b, double alfa){
    return fun(funcaoExponencialDupla(a, b, alfa)) * alpha_d(a, b, alfa);
}

double resultadoIntegral (int metodo, int degree, double a, double b, double tol){
    //NEWTON COTES FECHADO
    if (metodo == 1){
        if(degree == 1){
            return Newton_Cotes_1_fechada (a, b, tol);
        }
        if(degree == 2){
            return NewtonCotes_2_fechada (a, b, tol);
        }
        if(degree == 3){
            return NewtonCotes_3_fechada (a, b, tol);
        }
        if(degree == 4){
            return NewtonCotes_4_fechada (a, b, tol);
        }
    }

    //NEWTON COTES ABERTO
    if (metodo == 2){
        if(degree == 1){
            return Newton_Cotes_1_aberta (a, b, tol);
        }
        if(degree == 2){
            return NewtonCotes_2_aberta (a, b, tol);
        }
        if(degree == 3){
            return NewtonCotes_3_aberta (a, b, tol);
        }
        if(degree == 4){
            return NewtonCotes_4_aberta (a, b, tol);
        }
    }

    int valid_gl = 0;
    //GAUSS LEGENDRE
    if (metodo == 3){
        while(valid_gl != 1){
            if(degree == 1){
                printf("Grau inválido. Para a integral com Gauss-Legendre, o grau deve ser no mínimo 2 e no máximo 5. ");
            }
            if(degree == 2){
                valid_gl = 1;
                return GaussLegendre2(a, b, tol);
            }
            if(degree == 3){
                valid_gl = 1;
                return GaussLegendre3(a, b, tol);
            }
            if(degree == 4){
                valid_gl = 1;
                return GaussLegendre4(a, b, tol);
            }
            if(degree == 5){
                valid_gl = 1;
                return GaussLegendre5(a, b, tol);
            }
        }
    }

    int valid_gh = 0;
    //GAUSS-HERMITE
    if (metodo == 4){
        while(valid_gh != 1){
            if(degree == 1){
                printf("Grau inválido. Para a integral com Gauss-Hermite, o grau deve ser no mínimo 2 e no máximo 4. ");
            }
            if(degree == 2){
                valid_gh = 1;
                return GaussHermite2();
            }
            if(degree == 3){
                valid_gh = 1;
                return GaussHermite3();
            }
            if(degree == 4){
                valid_gh = 1;
                return GaussHermite4();
            }
        }
    }

    int valid_glg = 0;
    //GAUSS-LAGUERRE
    if (metodo == 5){
        while(valid_glg != 1){
            if(degree == 1){
                printf("Grau inválido. Para a integral com Gauss-Laguerre, o grau deve ser no mínimo 2 e no máximo 4. ");
            }
            if(degree == 2){
                valid_glg = 1;
                return GaussLaguerre2();
            }
            if(degree == 3){
                valid_glg = 1;
                return GaussLaguerre3();
            }
            if(degree == 4){
                valid_glg = 1;
                return GaussLaguerre4();
            }
        }
    }
}

void main(int argc, char **argv){

    int metodo;
    int degree;
    int a, b;
    int valid = 0;
    double alfa = 0;
    double tol = 0;
    int n;
    double gap[6];

    gap[0] = 0; 
    gap[1] = M_PI/8;
    gap[2] = M_PI/4;
    gap[3] = (3*M_PI)/2;
    gap[4] = M_PI/2; 
    gap[5] = M_PI;

     printf("\n################################################\n# Integrais - EQUIPE 10 #\n################################################\n");
    //Escolha de limites
    while (valid != 1){
        printf("\nEscolha o limite inferior(0 a 5):\n");
        scanf("%d", &a);

        printf("\nEscolha o limite superior(0 a 5):\n");
        scanf("%d", &b);
        
        if (b >= a){
            if(a >= 0 && b >= 0 && a<=5 && b<=5){
                valid = 1;
            }
            else {
                printf("\nIntervalo inválido! Digite um intervalo conforme as regras entre parênteses.\n");
            }
        }
        else {
            printf("\nIntervalo inválido! 'Limite superior' deve ser maior que 'Limite inferior'.\n");
        }
    }

    //Escolha a tolância
    printf("\nEntre com a tolancia:\n>>> ");
    scanf("%lf", &tol);

    //Escolha do método
    printf("\n--------Métodos:---------\n");
    printf("1- Newton-Cotes [Fechado] \n2- Newton-Cotes [Aberto] \n3- Gauss-Legendre \n4- Gauss-Hermite\n5- Gauss-Laguerre\n6- Gauss-Chebyschev\n7- Exponencial Simples\n8- Exponencial Dupla\n>>> ");
    scanf("%d", &metodo);
    
    if(metodo == 6) {

        printf("\n--------Numero de pontos de Chebyschev:---------\n>>> ");
        scanf("%d", &n);
        printf("\n--------Resultado:---------\n");
        printf("O valor da integral é: %lf\n\n",GaussChebyshev (n));

    } else if(metodo == 7){

        printf("\n--------Alfa:---------\n>>> ");
        scanf("%lf", &alfa); 
        printf("\n--------Resultado:---------\n");
        printf("O valor da integral é: %lf\n\n", funcaoExponencial(gap[a], gap[b], alfa));

    } else if(metodo == 8) {

        printf("\n--------Alfa:---------\n>>> ");
        scanf("%lf", &alfa); 
        printf("\n--------Resultado:---------\n");
        printf("O valor da integral é: %lf\n\n", funcaoExponencialDupla(gap[a], gap[b], alfa));

    } else {
        
        printf("\n--------Grau:---------\n");
        printf("ATENÇÃO! 1 a 4 para Newton-Cotes, 2 a 4 para Gauss-Hermite/Gauss-Laguerre e 2 a 5 para Gauss-Legendre.\n>>> ");
        scanf("%d", &degree);

        printf("\n--------Resultado:---------\n");
        printf("O valor da integral é: %lf\n\n", resultadoIntegral(metodo, degree, gap[a], gap[b], tol));

    } 
}