# Write your MySQL query statement below
select A.machine_id, ROUND(AVG(B.timestamp - A.timestamp), 3) as processing_time from Activity as A
join Activity as B on A.machine_id = B.machine_id
where A.process_id = B.process_id and A.activity_type  = 'start' and B.activity_type  = 'end'
group by A.machine_id 