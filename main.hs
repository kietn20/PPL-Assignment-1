quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x : xs) =
  let smallerSorted = quicksort [a | a <- xs, a <= x]
      biggerSorted = quicksort [a | a <- xs, a > x]
   in smallerSorted ++ [x] ++ biggerSorted

-- helper function to get the first half of a list
firstHalf :: [a] -> [a]
firstHalf xs = take (length xs `div` 2) xs

-- helper function to get the second half of a list
secondHalf :: [a] -> [a]
secondHalf xs = drop (length xs `div` 2) xs

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x : xs) (y : ys)
  | (x <= y) = x : (merge xs (y : ys)) -- if x is less than or equal to y, then x is the first element of the merged list
  | otherwise = y : (merge (x : xs) ys) -- if y is less than x, then y is the first element of the merged list

mergesort :: (Ord a) => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort (firstHalf xs)) (mergesort (secondHalf xs))