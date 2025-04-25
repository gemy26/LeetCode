# Write your MySQL query statement below
SELECT a.employee_id, a.name, COUNT(b.reports_to) AS reports_count, ROUND(AVG(b.age), 0) AS average_age FROM employees AS a 
    JOIN employees AS b
    ON a.employee_id = b.reports_to
    GROUP BY a.employee_id, b.reports_to
    ORDER BY a.employee_id