import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class Solution {

	public static int longestIncreasingSubsequence(int arr[]) {
		//Your code goes here
		int n = arr.length;
		List<Integer> list = new ArrayList<Integer>();
		list.add(arr[0]);

		for(int i = 1; i < n; i++)
		{
			if(list.get(list.size()-1) < arr[i])
			{
				list.add(arr[i]);
			}
			else
			{
				int ind = Collections.binarySearch(list, arr[i]);
				//returns the index if it is present
				//else returns -ind-1, where ind is the location where the element would be if it is present
				if(ind < 0)
				{
					ind = -ind-1;
				}

				list.set(ind, arr[i]);
			}
		}

		return list.size();

	}

}

//VERY IMPORTANT
//In this code, we are not generating the LIS in the list, we just keep track of the length of the LIS.
//The list is NOT the LIS of the given array.
//This method cannot be used for printing the LIS