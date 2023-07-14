/* Write your T-SQL query statement below */
SELECT W2.id [Id]
FROM Weather W1, Weather W2
WHERE DATEDIFF(day, W1.recordDate, W2.recordDate) = 1
    AND W2.temperature > W1.temperature