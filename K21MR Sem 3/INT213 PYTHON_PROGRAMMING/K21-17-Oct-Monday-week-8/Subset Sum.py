import Control.Monad
import Data.List
import Data.Function
import Data.Array
import Data.Int
import qualified Data.Set as S

f :: [Int64] -> [Int64]
f = g 0
  where
    g :: Int64 -> [Int64] -> [Int64]
    g _ [] = []
    g acc (x:xs) = (acc+x) `seq` (acc+x):g (acc+x) xs

g :: S.Set Int64 -> Int64 -> Int
g s x = let (l, _) = S.split x s
        in 1 + S.size l

main :: IO ()
main = do
    n <- readLn :: IO Int
    ln <- getLine
    let ls = map (read :: String -> Int64) $ words ln
        ns = S.fromList $ f $ sortBy (flip compare) ls
        su = sum ls
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- readLn :: IO Int64
        if su < s
          then putStrLn "-1"
          else print $ g ns s