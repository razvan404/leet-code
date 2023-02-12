/* 
 Please write a DELETE statement and DO NOT write a SELECT statement.
 Write your T-SQL query statement below
 */
DELETE P1
FROM Person P1 INNER JOIN Person P2 ON P2.id < P1.id
WHERE P1.email = P2.email