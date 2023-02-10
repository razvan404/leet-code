/* Write your T-SQL query statement below */
SELECT DISTINCT L1.num [ConsecutiveNums]
FROM Logs L1, Logs L2, Logs L3
WHERE L1.num = L2.num AND L1.num = L3.num
    AND L2.id = L1.id + 1 AND L3.id = L1.id + 2