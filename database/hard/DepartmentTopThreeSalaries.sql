/* Write your T-SQL query statement below */
SELECT D.name [Department], E.name [Employee], E.salary [Salary]
FROM Employee E INNER JOIN Department D ON E.departmentId = D.id
WHERE E.salary IN (
    SELECT DISTINCT TOP 3 salary
    FROM Employee
    WHERE departmentId = D.id
    ORDER BY salary DESC
)