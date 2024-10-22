/* Write your PL/SQL query statement below */
select unique_id, name from EmployeeUNI eu  right join Employees e on e.id = eu.id;