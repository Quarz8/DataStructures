// FILE: bag1.cxx
// CLASS IMPLEMENTED: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "bag1.h"
using namespace std;

// From what I gathered, this namespace serves as another level of privacy.
// For the purposes of lab 3, it isn't NEEDED, but I've left it in.
// I suppose if you wanted to re-write the bag class elsewhere in the project, and keep
// the same class name, you could do so by not using  namespace main_savitch_3 (?)
// That's my amateur take on it.
namespace main_savitch_3 
{
    const bag::size_type bag::CAPACITY; // Declaring CAPACITY from bag1.h again? Seems unneeded?
    
    bag::size_type bag::erase(const value_type& target)
    {
	size_type index = 0; // index of value_type data[]
	size_type many_removed = 0; // number of targets removed

	while (index < used) // while index is less than used
	{
	    if (data[index] == target) // if item found at the index is equal to the target
	    {
		--used; // decrement used by 1 (Note: used-1 == final index 'used' in data). Decreases size by 1.
		data[index] = data[used]; // set value at index (a target) to the last used element in data. (Effectively deletes target by copying last item to its location)
        // Note that data[used] is now duplicated in the array, but is no longer considered in the bag as the used value has been decreased to exclude it.
		++many_removed; // increase many_removed by 1
	    }
	    else
		++index; // increase index by 1 to compare next element to target
	}

	return many_removed; // returns how many targets were removed
    }

    bool bag::erase_one(const value_type& target)
    {
	size_type index; // The location of target in the data array    

	// First, set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1. If target is not
	// in the array, then index will be set equal to used.
	index = 0; 
	while ((index < used) && (data[index] != target))
	    ++index;

	if (index == used)
	    return false; // target isn't in the bag, so no work to do.

	// When execution reaches here, target is in the bag at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];    
	return true;
    }

    void bag::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
        assert(size( ) < CAPACITY); // Assert that the bag is not already full

        data[used] = entry; // inserts entry into bag at data[used] 
	++used; // increment used by 1
    }

    void bag::operator +=(const bag& addend)
    // Library facilities used: algorithm, cassert
    {
    // Assert that the sum of contents of the 2 bags do not go over capacity
	assert(size( ) + addend.size( ) <= CAPACITY); 
	
    // Copy elements from addend.data through addend.used to this->data+used (ie the end of used item slots in this)
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used; // Increase value of this->used by the value of addend.used to represent the combination's size
    }

    bag::size_type bag::count(const value_type& target) const // member variables cannot be changed inside this function
    {
        size_type answer; // how many targets are in the bag?
        size_type i; // index of data[]

        answer = 0;
        for (i = 0; i < used; ++i) // for each item in the bag
            if (target == data[i]) // if target is equal to the item at index i
                ++answer; // increase answer by 1
        return answer; // return number of targets in bag
    }

    bag operator +(const bag& b1, const bag& b2)
    // Library facilities used: cassert
    {
        bag answer; // bag that will contain union of b1 and b2

        assert(b1.size( ) + b2.size( ) <= bag::CAPACITY); // Assert that sum of each bag's size fits within CAPACITY

        // Use overloaded += to assign b1 and b2 to answer
        answer += b1; 
        answer += b2;
        return answer; //return bag containing union of b1 and b2
    }
}