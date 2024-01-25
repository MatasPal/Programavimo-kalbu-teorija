-- Importing necessary functions from standard libraries
import Data.Char (digitToInt)
import Data.List (find)
import Text.Printf (printf)

-- Function to calculate factorial of a given integer
--factorial :: Integer -> Integer
--factorial n = product [1..n]
-- Function to calculate factorial of a given integer recursively
factorial :: Integer -> Integer
factorial 0 = 1
factorial 1 = 1
factorial n = n * factorial (n - 1)


-- Function to find the last non-zero digit of the factorial of a given integer
lastNonZeroDigit :: Integer -> Maybe Int
lastNonZeroDigit n = find (/= 0) $ reverse $ map digitToInt $ show $ factorial n

-- Function to format the output in the desired way
formatOutput :: Integer -> Maybe Int -> String
formatOutput n Nothing = printf "%5d -> %s" n "none"
formatOutput n (Just d) = printf "%5d -> %d" n d

-- The main function
main :: IO ()
main = do
  -- Read input from file and convert to list of integers
  input <- readFile "input.txt"
  let ns = map read $ lines input :: [Integer]
  -- Calculate the last non-zero digit of factorial for each integer in the input list
  let results = map (\n -> (n, lastNonZeroDigit n)) ns
  -- Format the output for each integer in the results list and join them into a single string
  let output = unlines $ map (\(n, d) -> formatOutput n d) results
  -- Write the output to a file and print a message indicating completion
  writeFile "output.txt" output
  putStrLn "Done!"
