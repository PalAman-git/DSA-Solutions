# Write your MySQL query statement below
WITH managerCount AS (
    SELECT managerId,COUNT(managerId) AS m_count
    FROM Employee
    GROUP BY managerId
)
SELECT e.name
FROM Employee e
LEFT JOIN managerCount m
ON e.id = m.managerId
WHERE m.m_count >= 5;