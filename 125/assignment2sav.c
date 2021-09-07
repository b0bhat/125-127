/*if (n == 0) return -1;
int mid = n / 2;
int found;
if (A[mid].id == id) found = mid;
else if (A[mid].id < id) {
  found = binary_search_rec(A + mid + 1, n - mid - 1, id);
  if (found != -1) found += mid + 1;
} else found = binary_search_rec(A, mid, id);
return found;
}

int mid = (n)/2;
  for (int i = 0; i < 7; i++) printf("%i ", A[i].id);
  printf("\n I%i", n);
   if (n <= 0) {
       return -1;
   } else if (A[mid].id == id) {
      return mid;
   } else if (A[mid].id > id) {
       return binary_search_rec(A, mid, id);
   } else if (A[mid].id < id) {
       return binary_search_rec(&A[mid], n - mid - 1, id);
   } return 99;
}

int temp = (n/2);
   printf(" S ");
   for (int i = 0; i < 5; i++) printf("%i ",A[i].id);
   printf("\n");
   //printf("NI: %i, %i\n", n, temp);
   if (A[temp].id == id) return temp;
   else if (n != 0) {
     if (A[temp].id < id) binary_search_rec(A, temp, id);
     if (A[temp].id > id) {
       binary_search_rec(&A[temp], temp, id);
     }
   } return -1;
}

person *B = malloc(100);
for (int i = 0; i < temp; i++) {
  B[i].id = A[temp+i].id;
  printf("%i, %i\n", B[i], A[temp+1]);
}
binary_search_rec(B, temp, id);*/
