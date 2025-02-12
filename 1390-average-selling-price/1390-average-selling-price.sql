/* Write your T-SQL query statement below */
select 
p.product_id , 
ISNULL(ROUND(SUM(p.price * u.units * 1.0) / SUM(u.units), 2), 0) as average_price 
from prices as p 
left join 
UnitsSold as u
on u.product_id = p.product_id 
and u.purchase_date between p.start_date AND p.end_date
group by p.product_id