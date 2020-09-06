#!/bin/bash
for((i=13000;i<13100;i=i+10));do
	./server $i&
done;