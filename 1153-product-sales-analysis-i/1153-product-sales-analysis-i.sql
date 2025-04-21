# Write your MySQL query statement below
select product_name, year, price from sales as s join product as p on s.product_id = p.product_id