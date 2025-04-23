WITH first_order AS(
    SELECT customer_id, MIN(order_date) AS order_date FROM Delivery
    GROUP BY customer_id
)

SELECT ROUND(AVG(Delivery.customer_pref_delivery_date = first_order.order_date) * 100.00, 2) AS immediate_percentage 
FROM Delivery  JOIN first_order ON
first_order.customer_id = Delivery.customer_id and first_order.order_date = delivery.order_date

