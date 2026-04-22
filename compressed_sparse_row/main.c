#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dense matrix dimensions
#define N 4

// CSR structure
typedef struct {
    double *data;
    int *col_idx;
    int *row_ptr;
    int nnz;      // number of non-zeros
    int nrows;
} CSRMatrix;

// Build CSR from the dense matrix
CSRMatrix build_csr(double A[N][N], int n) {
    CSRMatrix csr;
    csr.nnz = 0;
    csr.nrows = n;

    // First pass: count non-zeros
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (A[i][j] != 0)
                csr.nnz += 1;

    // Allocate
    csr.data    = (double *)malloc(csr.nnz * sizeof(double));
    csr.row_ptr = (int *)malloc((n + 1) * sizeof(int));
    csr.col_idx = (int *)malloc(csr.nnz * sizeof(int));

    // Second pass: fill data, col_idx, row_ptr
    int k = 0;
    for(int i = 0; i < n; i++) {
        csr.row_ptr[i] = k;
        for(int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                csr.data[k] = A[i][j] ;
                csr.col_idx[k] = j;
                k += 1;
            }
        }
    }

    csr.row_ptr[n] = k; // sentinel: total non-zeros

    return csr;
}

// Dense vector multiplication
void dense_matvec(double A[N][N], double *x, double *result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 0.0;
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * x[j];
        }
    }
}

// CSR matrix-vector multiplication
void csr_matvec(CSRMatrix *csr, double *x, double *result) {
    for(int i = 0; i < csr->nrows; i++) {
        result[i] = 0.0;

        // Only iterate over non-zeros in row i
        for(int k = csr->row_ptr[i]; k < csr->row_ptr[i+1]; k++) {
            result[i] += csr->data[k] * x[csr->col_idx[k]];
        }
    }
}

void print_vector(double *v, int n, const char *label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++)
        printf("%.1f%s", v[i], i < n - 1 ? ", " : "");
    printf("]\n");
}

void print_csr(CSRMatrix *csr) {
    printf("\nCSR Representation:\n");

    printf("data    = [");
    for (int i = 0; i < csr->nnz; i++)
        printf("%.0f%s", csr->data[i], i < csr->nnz - 1 ? ", " : "");
    printf("]\n");

    printf("col_idx = [");
    for (int i = 0; i < csr->nnz; i++)
        printf("%d%s", csr->col_idx[i], i < csr->nnz - 1 ? ", " : "");
    printf("]\n");

    printf("row_ptr = [");
    for (int i = 0; i <= csr->nrows; i++)
        printf("%d%s", csr->row_ptr[i], i < csr->nrows ? ", " : "");
    printf("]\n\n");
}

void free_csr(CSRMatrix *csr) {
    free(csr->data);
    free(csr->col_idx);
    free(csr->row_ptr);
}


int main() {
    double A[N][N] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 4},
        {0, 2, 0, 0},
    };

    double x[N]            = {1, 2, 3, 4};
    double dense_result[N] = {0};
    double csr_result[N]   = {0};

    // Dense multiplication
    dense_matvec(A, x, dense_result, N);
    print_vector(dense_result, N, "Dense result");

    // Build CSR and multiply
    CSRMatrix csr = build_csr(A, N);
    print_csr(&csr);
    csr_matvec(&csr, x, csr_result);
    print_vector(csr_result, N, "CSR result  ");

    // Verify
    int match = 1;
    for (int i = 0; i < N; i++)
        if (dense_result[i] != csr_result[i]) {
            match = 0;
            break;
        }
    printf("\nMatch: %s\n", match ? "true" : "false");

    free_csr(&csr);
    return 0;
}

// CSR format
// CSR compresses the matrix into 3 arrays storing only the non-zero values:
// data — the non-zero values themselves
// col_idx — which column each value is in
// row_ptr — where each row starts in the data array
// data    = [3, 1, 4, 2]        # non-zero values left-to-right, top-to-bottom
// col_idx = [2, 0, 3, 1]        # which column each value lives in
// row_ptr = [0, 1, 1, 3, 4]     # row_ptr always has n_rows + 1 elements. To find all non-zero values in row i, you slice data[row_ptr[i] : row_ptr[i+1]]. The rule is simple: after scanning each row, append the current length of data to row_ptr.
