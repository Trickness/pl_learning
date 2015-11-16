main = do
        print [1,2..10]
        print [1,3..10]
        print ['a','b'..'z']
        print ['a','b'..'Z']

        print (take 10 (cycle "LOL "))
        print (take 20 (repeat 'H'))

        print [x*2 | x<-[1..10]]
