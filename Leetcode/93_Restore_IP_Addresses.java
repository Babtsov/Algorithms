public List<String> restoreIpAddresses(String s) {
    ArrayList<String> ips = new ArrayList<>();
    backtrack(ips, new ArrayList<>(), s, 4);
    return ips;
}

public void backtrack(List<String> ips, ArrayList<Integer> address, String s, int parts) {
    if (parts == 0) {
        if (!s.isEmpty()) {
            return;
        }
        StringBuilder sBuilder = new StringBuilder();
        sBuilder.append(address.get(0));
        for (int i = 1; i < address.size(); i++) {
            sBuilder.append("." + address.get(i));
        }
        ips.add(sBuilder.toString());
        return;
    }
    for (int i = 1; i <= 3 && i <= s.length(); i++) {
        int val = Integer.parseInt(s.substring(0, i));
        if (val > 255) {
            return;
        }
        address.add(val);
        backtrack(ips, address, s.substring(i), parts - 1);
        address.remove(address.size() - 1);
        if (s.charAt(0) == '0') {
            break;
        }
    }
}
