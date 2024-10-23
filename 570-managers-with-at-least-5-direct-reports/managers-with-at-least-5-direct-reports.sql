/* Write your T-SQL query statement below */
select E.manager_name as name from(
    select  m.name as manager_name , count(m.name) as emp_count
    from employee m join employee e on m.id = e.managerid
    group by e.managerid, m.name
    having count(*) >= 5
) 
E
-- where E.emp_count >= 5;

    

