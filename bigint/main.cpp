#include "bigint.hpp"
#include <iostream>

int main()
{
    const bigint a(49);
    bigint b(22), c, d(1337), e(d), f(0), g(1338), h(1339);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "c + c = " << c + c << std::endl;
    std::cout << "c + a = " << c + a << std::endl;
    std::cout << "f + f = " << f + f << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "(f << 3) = " << ((f << 3)) << std::endl;
    std::cout << "(b << 3) = " << ((b << 3)) << std::endl;
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    // std::cout << "a =" << a << std::endl;
    // std::cout << "d =" << d << std::endl;

    std::cout << "true: " << true << std::endl;
    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    // std::cout << "(g > h) = " << (g > h) << std::endl;
    // std::cout << "(h > g) = " << (h > g) << std::endl;
    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "g = " << g << std::endl;
    std::cout << "h = " << h << std::endl;
    std::cout << "(g < h) = " << (g < h) << std::endl;
    std::cout << "(h < g) = " << (h < g) << std::endl;

    // std::cout << "(d >= a) = " << (d >= a) << std::endl;
    // std::cout << "(d == a) = " << (d == a) << std::endl;
    // std::cout << "(d == e) = " << (d == e) << std::endl;
    // std::cout << "(d != a) = " << (d != a) << std::endl;

    // std::cout << "\n==== EDGE CASES ====\n" << std::endl;

    // // --- Zero: construcao, soma, shift ---
    bigint zero(0);
    std::cout << "zero = " << zero << " (esperado 0)" << std::endl;
    std::cout << "zero + zero = " << (zero + zero) << " (esperado 0)" << std::endl;
    // std::cout << "zero << 5 = " << (zero << 5) << " (esperado 0, sem zero a esquerda)" << std::endl;
    // std::cout << "zero >> 5 = " << (zero >> 5) << " (esperado 0)" << std::endl;

    // // --- Shift por 0 (nao deve mudar nada) ---
    // bigint num(777);
    // std::cout << "num << 0 = " << (num << 0) << " (esperado 777)" << std::endl;
    // std::cout << "num >> 0 = " << (num >> 0) << " (esperado 777)" << std::endl;

    // // --- Shift que corta exatamente todos os digitos ---
    // std::cout << "num >> 3 = " << (num >> 3) << " (esperado 0, num tem 3 digitos)" << std::endl;

    // // --- Shift maior que a quantidade de digitos ---
    // std::cout << "num >> 10 = " << (num >> 10) << " (esperado 0)" << std::endl;

    // --- Carry em cadeia (soma que "estoura" varias casas) ---
    bigint n999(999), n1(1);
    std::cout << "999 + 1 = " << (n999 + n1) << " (esperado 1000)" << std::endl;

    bigint nines(9999999);
    std::cout << "9999999 + 1 = " << (nines + n1) << " (esperado 10000000)" << std::endl;

    // // --- ++ atravessando fronteira de carry ---
    // bigint edge999(999);
    // std::cout << "++edge999 = " << ++edge999 << " (esperado 1000)" << std::endl;

    // // --- Comparacao com quantidade de digitos diferente ---
    // bigint n9(9), n10(10);
    // std::cout << "(9 < 10) = " << (n9 < n10) << " (esperado 1)" << std::endl;
    // std::cout << "(9 > 10) = " << (n9 > n10) << " (esperado 0)" << std::endl;
    // std::cout << "(999 < 1000) = " << (bigint(999) < bigint(1000)) << " (esperado 1)" << std::endl;

    // // --- Igualdade entre copias ---
    // bigint copy1(555);
    // bigint copy2(copy1);
    // std::cout << "(copy1 == copy2) = " << (copy1 == copy2) << " (esperado 1)" << std::endl;

    // // --- Auto-atribuicao (a = a) ---
    // bigint self(123);
    // self = self;
    // std::cout << "self = self -> " << self << " (esperado 123, sem corromper)" << std::endl;

    // // --- Independencia entre copia e original (nao pode ser ponteiro/referencia compartilhada) ---
    // bigint original(10);
    // bigint clone(original);
    // original += bigint(5);
    // std::cout << "original apos += : " << original << " (esperado 15)" << std::endl;
    // std::cout << "clone continua    : " << clone << " (esperado 10, nao deve mudar)" << std::endl;

    // // --- Auto-soma (x += x) ---
    // bigint selfadd(7);
    // selfadd += selfadd;
    // std::cout << "selfadd += selfadd = " << selfadd << " (esperado 14)" << std::endl;

    // // --- Shifts encadeados ---
    // bigint chain(3);
    // std::cout << "(chain << 2) << 1 = " << ((chain << 2) << 1) << " (esperado 3000)" << std::endl;

    // // --- >>= com bigint como argumento (exigido pelo main oficial do subject) ---
    // bigint viaShift(500);
    // viaShift >>= (const bigint)2;
    // std::cout << "viaShift >>= bigint(2) = " << viaShift << " (esperado 5)" << std::endl;

    // // --- Comparacao no limite exato (valores iguais) ---
    // bigint eqA(88), eqB(88);
    // std::cout << "(eqA >= eqB) = " << (eqA >= eqB) << " (esperado 1)" << std::endl;
    // std::cout << "(eqA <= eqB) = " << (eqA <= eqB) << " (esperado 1)" << std::endl;
    // std::cout << "(eqA != eqB) = " << (eqA != eqB) << " (esperado 0)" << std::endl;

    // // --- unsigned wraparound de int negativo no construtor ---
    // bigint fromNeg(-1);
    // std::cout << "bigint(-1) = " << fromNeg << " (esperado 4294967295, wraparound de unsigned int)" << std::endl;

    // // --- Numero grande, perto do limite de unsigned int 32 bits ---
    // bigint maxish(4294967295u);
    // std::cout << "bigint(4294967295) = " << maxish << " (esperado 4294967295)" << std::endl;

    // // --- Post/pre-increment: valor de retorno vs valor final do objeto ---
    // bigint pp(5);
    // bigint returned = pp++;
    // std::cout << "pp++ retornou " << returned << " (esperado 5) e pp agora e " << pp << " (esperado 6)" << std::endl;

    // bigint pre(5);
    // bigint returnedPre = ++pre;
    // std::cout << "++pre retornou " << returnedPre << " (esperado 6) e pre agora e " << pre << " (esperado 6)" << std::endl;
}
