select contest_id, ROUND(COUNT(contest_id) * 1.00 / ( select count(*) from users ) * 100.00 , 2) as percentage 
from register 
group by contest_id
order by percentage desc , contest_id asc