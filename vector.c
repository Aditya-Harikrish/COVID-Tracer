#include "vector.h"
vector* init_vector()
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->size = 0;
    v->capacity = 0;
    v->arr = NULL;
    printf("ptr = %p\n", v);
    return v;
}
void pushback(vector* v, int ele)
{
    if (v == NULL) {
        printf("v is NULL in pushback\n");
        assert(0);
    }
    if (v->arr == NULL) {
        if (v->size != 0) assert(0);
        v->arr = (int*)malloc(sizeof(int) * 2);
        assert(v->arr != 0);

        v->size = 0;
        v->capacity = 2;
    }
    if (v->size == v->capacity - 1) {
        v->arr = (int*)realloc(v->arr, 2 * (v->capacity) * sizeof(int));

        if (v->arr == NULL) {
            printf("Failed to allocate memory\n");
            assert(0);
        }
        v->capacity = v->capacity * 2;
        // printf("Capacity = %zu\n", v->capacity);
    }
    v->arr[v->size] = ele;
    ++(v->size);
}
void print_vector(vector* v)
{
    for (int i = 0; i < v->size; ++i) {
        printf("%d ", v->arr[i]);
    }
    printf("\n");
}
void delete_vector(vector** v)
{
    free((*v)->arr);
    free(*v);
    *v = NULL;
}
void popback(vector* v)
{
    --(v->size);
    if (v->size == 0) {
        free(v->arr);
        v->arr = NULL;
        v->capacity = 0;
        return;
    }
    if (v->size * 2 <= v->capacity) {
        v->capacity = v->size;
        v->arr = (int*)realloc(v->arr, v->size * sizeof(int));
    }
}







