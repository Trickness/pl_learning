main = do
        let a = [1,2,3,4]
        print (a !! 0)
        print (head a)
        let b = [1,2,4,4]
        print (a > b)
        let a = [2,1,1,1]
        print (a > b)
        print (tail a)        
        print (init a)
