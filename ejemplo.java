import java.io.*;

import java.util.*;

import java.util.regex.*;



class Spelling {



 private final HashMap<string, integer=""> nWords = new HashMap<string, integer="">();



 public Spelling(String file) throws IOException {

  BufferedReader in = new BufferedReader(new FileReader(file));

  Pattern p = Pattern.compile("\\w+");

  for(String temp = ""; temp != null; temp = in.readLine()){

   Matcher m = p.matcher(temp.toLowerCase());

   while(m.find()) nWords.put((temp = m.group()), nWords.containsKey(temp) ? nWords.get(temp) + 1 : 1);

  }

  in.close();

 }



 private final ArrayList<string> edits(String word) {

  ArrayList<string> result = new ArrayList<string>();

  for(int i=0; i < word.length(); ++i) result.add(word.substring(0, i) + word.substring(i+1));

  for(int i=0; i < word.length()-1; ++i) result.add(word.substring(0, i) + word.substring(i+1, i+2) + word.substring(i, i+1) + word.substring(i+2));

  for(int i=0; i < word.length(); ++i) for(char c='a'; c <= 'z'; ++c) result.add(word.substring(0, i) + String.valueOf(c) + word.substring(i+1));

  for(int i=0; i <= word.length(); ++i) for(char c='a'; c <= 'z'; ++c) result.add(word.substring(0, i) + String.valueOf(c) + word.substring(i));

  return result;

 }



 public final String correct(String word) {

  if(nWords.containsKey(word)) return word;

  ArrayList<string> list = edits(word);

  HashMap<integer, string=""> candidates = new HashMap<integer, string="">();

  for(String s : list) if(nWords.containsKey(s)) candidates.put(nWords.get(s),s);

  if(candidates.size() > 0) return candidates.get(Collections.max(candidates.keySet()));

  for(String s : list) for(String w : edits(s)) if(nWords.containsKey(w)) candidates.put(nWords.get(w),w);

  return candidates.size() > 0 ? candidates.get(Collections.max(candidates.keySet())) : word;

 }



 public static void main(String args[]) throws IOException {

  if(args.length > 0) System.out.println((new Spelling("big.txt")).correct(args[0]));

 }



}

</integer,></integer,></string></string></string></string></string,></string,>
