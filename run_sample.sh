# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 22:41:50 on Tue, May 24, 2022
#
# Description: run sample script

#!/bin/bash

set -euo pipefail

WORK_PATH=$(cd $(dirname $0) && pwd) && cd $WORK_PATH

rm -rf log && mkdir -p log/sample

nohup $WORK_PATH/output/sample/ring_queue > log/sample/ring_queue.log 2>&1 &
nohup $WORK_PATH/output/sample/ds_stack > log/sample/ds_stack.log 2>&1 &
nohup $WORK_PATH/output/sample/sequence_list > log/sample/sequence_list.log 2>&1 &
nohup $WORK_PATH/output/sample/single_list > log/sample/single_list.log 2>&1 &
nohup $WORK_PATH/output/sample/hash_map_list > log/sample/hash_map_list.log 2>&1 &
nohup $WORK_PATH/output/sample/skip_list > log/sample/skip_list.log 2>&1 &
nohup $WORK_PATH/output/sample/binary_tree_array > log/sample/binary_tree_array.log 2>&1 &
nohup $WORK_PATH/output/sample/binary_tree_list > log/sample/binary_tree_list.log 2>&1 &
nohup $WORK_PATH/output/sample/AVL_tree > log/sample/AVL_tree.log 2>&1 &
nohup $WORK_PATH/output/sample/red_black_tree > log/sample/red_black_tree.log 2>&1 &
nohup $WORK_PATH/output/sample/binary_heap > log/sample/binary_heap.log 2>&1 &
nohup $WORK_PATH/output/sample/graph_adjacency_matrix > log/sample/graph_adjacency_matrix.log 2>&1 &
