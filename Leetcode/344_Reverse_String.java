public String reverseString(String s) {
   char[] reversed = new char[s.length()];
   for (int i = 0, n = s.length(); i < n; i++) {
       reversed[i] = s.charAt(n - 1 - i);
   }
   return new String(reversed);
}
