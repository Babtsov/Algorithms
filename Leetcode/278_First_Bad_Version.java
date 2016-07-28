// iterative strategy
public int firstBadVersion(int n) {
    int begin = 1, end = n;
    while (end >= begin) { 
        int middle = (end - begin) / 2 + begin;
        if (isBadVersion(middle)) {
            if (end - begin <= 1) { 
                return middle;
            }
            end = middle;
        }else {
            begin = middle + 1;
        }
    }
    return -1; // optional:  return -1 if no bad version exists
}

// recursive strategy
public int firstBadVersion(int n) {
    return firstBadVersionRecursive(1, n, n);
}

public int firstBadVersionRecursive(int begin, int end, int n) {
    if (end < begin) { // optional:  return -1 if no bad version exists
        return -1;
    }
    int middle = (end - begin) / 2 + begin;
    if (isBadVersion(middle)) {
        if (end - begin <= 1) { 
            return middle;
        }
        return firstBadVersionRecursive(begin, middle, n);
    }else {
        return firstBadVersionRecursive(middle + 1, end, n);
    }
}
