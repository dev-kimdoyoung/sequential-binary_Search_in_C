#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "boolean.h"
#include "searchmethod.h"
#define MAXSIZE 10

int main() {
    // MAXSIZE 크기의 int형 배열 선언
    int data[MAXSIZE] = {13, 22, 30, 41, 56, 68, 70, 80, 90, 100};

    // size는 배열의 capacity
    const int size = sizeof(data) / sizeof(int);

    // 순차 검색 test
    int result = sequentialSearch(data, size, 100);
    if(result != EOF) {
        printf("순차 검색 결과 : %d\n", result);
    }
    else {
        printf("찾는 데이터가 존재하지 않습니다.\n");
    }

    // index table 선언
    Index_Table table;

    // index table을 이용한 순차 검색 test
    result = index_sequentialSearch(table, data, size, 60);
    if(result != EOF) {
        printf("inde_table 검색 결과 : %d\n", result);
    }
    else {
        printf("찾는 데이터가 존재하지 않습니다.\n");
    }

    // 이진 검색 test
    result = binarySearch(data, 0, size, 68);
    if(result != EOF) {
        printf("inde_table 검색 결과 : %d\n", result);
    }
    else {
        printf("찾는 데이터가 존재하지 않습니다.\n");
    }

    return 0;
}

// 순차 검색
int sequentialSearch(const int data[], const int size, const int key) {
    // 배열의 끝까지 순차 검색
    for(int i = 0; i < size; i++) {
        // 만약 data를 찾으면
        if(data[i] == key) {
            return data[i];
        }
    }
    // 검색 실패(-1) return
    return EOF;
}

// 색인 순차 검색
int index_sequentialSearch(Index_Table idx_table, const int data[], const int size, const int key) {
    // 테이블 설정
    int table_size = sizeof(idx_table.table) / sizeof(int);

    for(int i = 0; i < table_size; i++) {
        idx_table.table[i] = data[2 * i + 1];
    }

    for(int i = 0; i < table_size; i++) {
        // 만약 key 값이 index_table[i] 보다 작으면 data table에서 찾는 범위를 축소
        if(idx_table.table[i] > key) {
            // data table에서 해당 key의 데이터 존재하면
            if(data[2*i] == key) {
                return data[2*i];
            }
        }
        // key 값이 index table에 존재하면
        else if(idx_table.table[i] == key) {
            // 해당 값 return
            return idx_table.table[i];
        }
    }
    // 검색 실패(-1) return
    return EOF;
}

// 이진 탐색
int binarySearch(const int data[], int start, int end, const int key) {

    // 배열에서 중간에 위치한 index 저장
    int mid_index = (start + end) / 2;
    // 찾는 데이터가 없으면
    if(data[start] == key) {
        return data[start];
    }
    // 찾는 데이터가 없으면
    if(start == mid_index) {
        return EOF;
    }
    // key가 중간 index의 값보다 크면
    else if(key > data[mid_index]) {
        binarySearch(data, mid_index, end, key);
    }
    // key가 중간 index의 값보다 작으면
    else if(key < data[mid_index]) {
        binarySearch(data, start, mid_index, key);
    }
    // key가 중간 index의 값이 key와 일치하면
    else if(key == data[mid_index]){
        return data[mid_index];
    }
}