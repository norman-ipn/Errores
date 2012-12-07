/*Una implementación directa, como pseudocódigo para una función LevenshteinDistance que toma dos cadenas, s y t , y devuelve la distancia Levenshtein entre ellos:*/

int LevenshteinDistance ( string s, cadena t)
 { 
  int longitud = len_s (s), len_t longitud = (t), costo = 0

  si (s [0]! = t [0]) luego costo = 1

  si (len_s == 0) entonces devolver len_t
   elseif (len_t == 0) entonces devolver len_s
   else return mínimo (LevenshteinDistance (s [1 .. len_s-1], t) + 1,
                                          LevenshteinDistance (s, t [1 .. len_t-1]) + 1,
                                          LevenshteinDistance (s [1 .. len_s-1], t [1 .. len_t-1]) + costo)
}

