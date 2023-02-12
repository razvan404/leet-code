/* Write your T-SQL query statement below */
SELECT D.name [Department], E.name [Employee], E.salary [Salary]
FROM Employee E INNER JOIN Department D ON E.departmentId = D.id
WHERE E.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = D.id
)