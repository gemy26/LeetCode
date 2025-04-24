# Write your MySQL query statement below
WITH first_sale AS(SELECT product_id, MIN(year) first_year FROM sales GROUP BY product_id)

SELECT sales.product_id, first_year, quantity, price FROM sales join first_sale
ON first_sale.product_id = sales.product_id and first_sale.first_year = sales.year