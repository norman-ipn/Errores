/*Implementado como está en un lenguaje de programación con evaluación impaciente, esta versión tendría la funcionalidad para evitar distancias informáticas en múltiples ocasiones.*/

//i is the start index of str1, j is the start index of str2
function LevenshteinDistance(str1, i, len1, str2, j, len2) {
   var key = [i,len1,j,len2].join(',');
   if(memo[key] != undefined) return memo[key];
   
   if(len1 == 0) return len2;
   if(len2 == 0) return len1;
   var cost = 0;
   if(str1[i] != str2[j]) cost = 1;
   
   var dist = Math.min(
       LevenshteinDistance(str1, i+1,len1-1, str2,j,len2)+1, 
       LevenshteinDistance(str1,i,len1,str2,j+1,len2-1)+1,
       LevenshteinDistance(str1,i+1,len1-1,str2,j+1,len2-1)+cost);
   memo[key] = dist;
   return dist;
}
