/* Write your T-SQL query statement below */
SELECT A.machine_id, Round(AVG(ABS(A.timestamp - B.timestamp)), 3) AS processing_time
FROM Activity A join Activity B ON A.machine_id = B.machine_id 
where A.process_id = B.process_id and A.activity_type  = 'start' and B.activity_type = 'end' 
Group By A.machine_id;