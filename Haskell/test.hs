simpleRecursion :: (Integral a) => a -> a
simpleRecursion 0 = 1   -- Edge condition
simpleRecursion x = x * (simpleRecursion (x - 1))

main = do
    inp <- getLine
    let x = read inp :: Int
    print $ simpleRecursion x
