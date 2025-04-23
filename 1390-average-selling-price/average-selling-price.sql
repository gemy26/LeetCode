select p.product_id, 
    IFNULL(ROUND(SUM(units * price) / SUM(units), 2), 0) as  average_price 
    FROM Prices as p LEFT JOIN UnitsSold as u
    ON  u.product_id = p.product_id
    and u.purchase_date between p.start_date AND p.end_date
    group by p.product_id
   