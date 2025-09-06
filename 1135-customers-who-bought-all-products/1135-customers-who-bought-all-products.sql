SELECT Customer.customer_id FROM Customer 
Group By Customer.customer_id 
HAVING COUNT(DISTINCT Customer.product_key ) = 
(SELECT COUNT(DISTINCT product_key) FROM product)