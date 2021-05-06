#include "vector.h"
void init_vector(vector* v)
{
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;
}
vector* init_vector_ptr()
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->size = 0;
    v->capacity = 0;
    v->arr = NULL;
    return v;
}
void pushback(vector* v, int ele)
{
    if (v == NULL) {
        printf("v is NULL in pushback. Initialise v using init_vector_ptr first!\n");
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
void delete_vector(vector *v)
{
    free(v->arr);
    v->capacity = 0;
    v->size = 0;
}
void delete_vector_ptr(vector** v)
{
    free((*v)->arr);
    free(*v);
    *v = NULL;
}
void popback(vector* v)
{
    if (v->size == 0) {
        printf("Underflow error! Cannot popback from an empty vector!\n");
        assert(0);
    }
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







