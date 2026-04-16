# Write your MySQL query statement below

select DATE_FORMAT(trans_date, '%Y-%m') AS month,country,count(amount) AS trans_count,COUNT(case when state = 'approved' then 1 else null end) AS approved_count,sum(amount)as trans_total_amount,sum(case when state = 'approved' then amount else 0 end) as approved_total_amount
from Transactions
group by month, country  