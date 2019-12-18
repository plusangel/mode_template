//
// Created by angelos on 14/12/2019.
//

#ifndef INC_TEMP_EXP_H
#define INC_TEMP_EXP_H

#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T>
requires std::is_integral<T>::value
T mode(const T *values, size_t length)
 {

  // check if it has zero length
  if (!length)
    return 0;

  if (!values)
    throw std::invalid_argument{"Invalid input array"};

  int count{}, maxOccurrences{};
  int multipleModes{};
  T mode{};

  // check every element unless the mode's occurrences are greater than the
  // remaining list
  for (int k{}; k < length && maxOccurrences <= (length - k); ++k) {

    // reset the count for every individual element
    count = 0;

    // count the number of occurrences
    for (int i{}; i < length; ++i) {
      if (values[k] == values[i])
        count++;
    }

    if (count > maxOccurrences && mode != values[k]) {
      mode = values[k];
      maxOccurrences = count;
      multipleModes = 0;
      /*std::cout << "Count:" << count << " - MaxOccur:" << maxOccurrences
                << " - Mode:" << mode << std::endl;*/
    }

    if (count == maxOccurrences && mode != values[k]) {
      // if the array has multiple modes
      multipleModes = 1;
    }
  }

  if (multipleModes == 1)
    return 0;
  else
    return mode;
}

#endif // INC_TEMP_EXP_H
