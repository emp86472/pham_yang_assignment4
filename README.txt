Ethan Pham 811467634 emp86472@uga.edu
Kevin Yang

getNumSingleParent()
    if (left !null)
       i += left.getNumSingleParent()
    if (right !null)
       i += right.getNumSingleParent()
    if (has one child)
       i++
    return i;

T(N) = 2T(N/2) + 1
a=2 b=2 k=0 p=0
case 1 if logab > k then O(n^logab) or O(N)

getNumLeafNodes() is implemented the same way as getNumSingleParent
also O(N)

getSumOfSubtrees()
    node temp;
    while (temp !null)
          if (data == value)
             return leftdata + rightdata
          if (data < value)
             temp go right
          if (data > value)
             temp go left
T(N) = T(N/2)
O(logn)
