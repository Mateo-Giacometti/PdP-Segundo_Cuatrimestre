#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct bucket {
    int val;
    struct bucket *next;
};

struct list {
    struct bucket *head;;
    struct bucket *last;
};

typedef struct bucket* Bucket;
typedef struct list* List;



Bucket newBucket(int val) {
    Bucket ptr = (Bucket)malloc( sizeof( struct bucket ) );
    if ( NULL == ptr ) return NULL;

    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}

void print( List list ) {
    Bucket current = list->head;

    printf( "< " );
    while( current != NULL ) {
        printf( "%d ",current->val );
        current = current->next;
    }
    printf( ">\n" );

    return;
}

List append( List list, int val ) {
    printf("--:%d ",val);
    Bucket ptr = newBucket( val );
    
    if( NULL == list->head ) {
        list->head = ptr;
    } else { 
        list->last->next = ptr;
    }

    list->last = ptr;
    return list;
}

List add( List list, int val ) {
    printf("%d:-- ",val);
    Bucket ptr = newBucket( val );
    
    if( NULL == list->head )  {
        list->last = ptr;
    } else {
        ptr->next = list->head;
    }
    
    list->head = ptr;
    return list;
}

int main(void) {
    struct list list;
    print( &list );

    for(int i = 5; i<10; i++)
        append( &list, i );

    print( &list );

    for(int i = 4; i>0; i--)
        add( &list, i );

    print( &list );

    for(int i = 1; i<10; i += 4) {
        printf("\n");
        Bucket ptr = search( &list, i, NULL );
        if (NULL != ptr) {
            printf("Search [val = %d] passed: ",ptr->val);
        }

        print( &list );

        if ( delete( &list, i ) == 0) {
            printf("delete [val = %d]  passed: ",i);
        }

        print( &list );
    }

    return 0;
}