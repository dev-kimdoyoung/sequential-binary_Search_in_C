#ifndef SEARCHMETHOD_H
#define SEARCHMETHOD_H

// 인덱스 테이블의 크기 지정
#define TABLE_SIZE  5

typedef struct Index_Table{
    int table[TABLE_SIZE];
    
}Index_Table;

/*
 *  function Prototype
 *  ※ 검색 기법의 return 값은 검색 결과값
 */
// 순차 검색
int sequentialSearch(const int data[], const int size, const int key);

// 색인 순차 검색
int index_sequentialSearch(Index_Table table, const int data[], const int size, const int key);

// 이진 탐색
int binarySearch(const int data[], int start, int end, const int key);

#endif