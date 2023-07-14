/* Write your T-SQL query statement below */
SELECT request_at[Day],
    CAST(AVG(CASE WHEN status <> 'completed' THEN 1.0 ELSE 0.0 END) AS DECIMAL(10, 2))[Cancellation Rate]
FROM Trips INNER JOIN Users U ON client_id = U.users_id INNER JOIN Users D ON driver_id = D.users_id
WHERE U.banned = 'No' AND D.banned = 'No' AND DATEDIFF(day, request_at, '2013-10-01') <= 0
    AND DATEDIFF(day, request_at, '2013-10-03') >= 0
GROUP BY request_at