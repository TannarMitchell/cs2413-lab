#include "student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement
	int value = nums[0];
	int count = 1;
	for(int i = 1; i < numsSize; i++){
		if(count == 0){
			value = nums[i];
		}
		if(nums[i] == value){
			count++;
		}	
		else{
			count--;
		}


	}
	return value;

}
