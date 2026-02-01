#include "dfs.h"
#include <stdio.h>

int main() {
    cdfs_put("input.txt", "/dfs/input.txt");
    cdfs_get("/dfs/input.txt", "output.txt");

    printf("DFS test completed\n");
    return 0;
}
