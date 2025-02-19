/* Write your T-SQL query statement below */
select P.project_id, ROUND(AVG(E.experience_years * 1.0), 2) as average_years
FROM Project as P JOIN Employee as E
ON P.employee_id = E.employee_id 
Group By P.project_id
Order By P.project_id