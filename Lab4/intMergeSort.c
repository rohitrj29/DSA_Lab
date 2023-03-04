void mergeSort(int A[], int st, int en)
{
if (en - st < 1)
return;
int mid = (st + en) / 2; // mid is the floor of (st+en)/2
mergeSort(A, st, mid); // sort the first half
mergeSort(A, mid + 1, en); // sort the second half
merge(A, st, mid, en); // merge the two halves
}
int main(){
    
}