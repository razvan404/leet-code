/* Write your T-SQL query statement below */
SELECT email [Email]
FROM Person
GROUP BY email
HAVING COUNT(*) > 1