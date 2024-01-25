import Data.Char (digitToInt)

-- Function to replace a digit in a number with another digit
replaceDigit :: Int -> Int -> Int -> Int
replaceDigit x y n = read $ map (\c -> if c == intToDigit x then intToDigit y else c) $ show n

-- Function to compute the actual value of a contract
actualValue :: Int -> Int -> Int
actualValue d n = read $ map (\c -> if c == intToDigit d then '0' else c) $ show n

-- Function to read test cases and compute the actual values
readAndCompute :: IO ()
readAndCompute = do
    line <- getLine
    let (d, n) = map read $ words line
    if d == 0 && n == 0
        then return ()
        else do
            let originalValue = read $ show n
                digits = map digitToInt $ show originalValue
                actualValues = map (actualValue d) [replaceDigit d i originalValue | i <- [1..9], i /= d]
                result = maximum actualValues
            print result
            readAndCompute

-- Main function to start the program
main :: IO ()
main = readAndCompute
