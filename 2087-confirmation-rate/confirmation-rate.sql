SELECT 
    s.user_id, 
    ROUND(
    CAST(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) AS FLOAT) / 
    CAST(COUNT(*) AS FLOAT) , 2)
    AS confirmation_rate

    FROM Confirmations c 
    RIGHT JOIN Signups s ON s.user_id = c.user_id

GROUP BY s.user_id;
