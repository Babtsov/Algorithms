public String stringifySpacedNumber(ArrayList<String> parts) {
    if (parts == null || parts.size() == 0) {
        throw new IllegalArgumentException();
    }
    StringBuilder sBuilder = new StringBuilder();
    sBuilder.append(parts.get(0));
    for (int i = 1; i < parts.size(); i++) {
        sBuilder.append(" " + parts.get(i));
    }
    return sBuilder.toString();
}

public String upToThousantToWords(int num) {
    if (num < 1 || num > 999) {
        throw new IllegalArgumentException();
    }
    String[] ones = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    String[] teen = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    String[] tens = { "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    ArrayList<String> parts = new ArrayList<>();
    if (num / 100 > 0) parts.add(ones[num / 100 - 1] + " Hundred");
    num = num % 100;
    if (num / 10 == 1) {
        parts.add(teen[num % 10]);
        return stringifySpacedNumber(parts);
    }
    if (num / 10 > 1)  parts.add(tens[num / 10 - 1]);
    num = num % 10;
    if (num > 0) parts.add(ones[num % 10 - 1]);
    return stringifySpacedNumber(parts) ;
}

public String numberToWords(int num) {
    ArrayList<String> parts = new ArrayList<>();
    String[] units = { "", " Thousand", " Million", " Billion" };
    for (int i = units.length - 1, val = num; i >= 0; i--) {
        int divider = (int) Math.pow(1000,i);
        if (val / divider > 0) parts.add(upToThousantToWords(val / divider) + units[i]);
        val = val % divider;
    }
    return (parts.size() != 0)? stringifySpacedNumber(parts) : "Zero";
}
