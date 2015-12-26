maxisum' :: (Ord a) => [a] -> a
maxisum' []     = error "Empty list"
maxisum' [x]    = x
maxisum' (x:xs) = max x (maxisum' xs)
