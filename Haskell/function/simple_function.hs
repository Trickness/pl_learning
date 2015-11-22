func1 x y z = x + y + z

func2 :: (Integral a) => a -> String
func2 7 = "Luck"
func2 a = "Unlucky"

myComp :: (Ord a) => a -> a -> Ordering
a  `myComp` b
    | a > b     = GT
    | a == b    = EQ
    | a < b     = LT

bmiTell :: (RealFloat a) => a -> a -> String
bmiTell weight height
    | bmi <= 18.5   = "Underweight"
    | bmi <= 25.0   = "Normal"
    | bmi <= 30.0   = "fat"
    | otherwise     = "..."
    where bmi = weight / height ^ 2 
