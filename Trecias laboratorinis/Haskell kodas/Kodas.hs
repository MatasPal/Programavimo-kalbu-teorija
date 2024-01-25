import Data.Char (ord, chr)
import Data.List (group, sort)

type Square = (Int, Int)

parseSquare :: String -> Square
parseSquare [x,y] = (ord x - ord 'a' + 1, ord y - ord '0')

validMoves :: Square -> [Square]
validMoves (x, y) = filter isValid [(x+2, y+1), (x+2, y-1), (x-2, y+1), (x-2, y-1),
                                     (x+1, y+2), (x+1, y-2), (x-1, y+2), (x-1, y-2)]
    where isValid (x', y') = x' `elem` [1..8] && y' `elem` [1..8]

knightMoves :: Square -> Square -> Int
knightMoves start end = head $ head $ dropWhile null $ iterate (concatMap validMoves) [[start]] >>= return . (`intersect` [end])
    where intersect xs ys = [x | x <- xs, x `elem` ys]

toSquare :: Square -> String
toSquare (x, y) = [chr (x + ord 'a' - 1), chr (y + ord '0')]

main :: IO ()
main = interact (unlines . map (formatLine . processLine) . lines)

processLine :: String -> (Square, Square)
processLine line = (parseSquare a, parseSquare b)
    where [a, b] = words line

formatLine :: (Square, Square) -> String
formatLine (a, b) = "To get from " ++ toSquare a ++ " to " ++ toSquare b ++ " takes " ++ show (knightMoves a b) ++ " knight moves."
