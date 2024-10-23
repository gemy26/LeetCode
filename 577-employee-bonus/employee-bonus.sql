/* Write your T-SQL query statement below */
select name, bonus from employee  left join bonus on employee.empId = bonus.empId
where Bonus.bonus < 1000 OR Bonus.bonus is null;