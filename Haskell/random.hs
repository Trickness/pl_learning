module Main where
import  System.Random
import Data.Text.Encoding

main::IO()
main = do

    putStrLn "您好"
    gen <- newStdGen
    print $ mod （fst (random gen :: (Int,StdGen))） 150
