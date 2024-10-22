/* Write your T-SQL query statement below */
select product_name, year, price from sales s join product p on p.product_id = s.product_id;