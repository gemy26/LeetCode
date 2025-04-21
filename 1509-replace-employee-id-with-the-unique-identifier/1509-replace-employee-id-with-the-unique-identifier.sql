# Write your MySQL query statement below
select e.name, eu.unique_id from Employees as e left join EmployeeUNI as eu on e.id = eu.id 