SELECT 
    T.user_id, 
    ROUND(
    CAST(COUNT(CASE WHEN T.action = 'confirmed' THEN 1 END) AS DECIMAL) / 
    CAST(COUNT(*) AS DECIMAL) , 2)
    AS confirmation_rate
FROM (
    SELECT s.user_id AS user_id, c.action AS action 
    FROM Confirmations c 
    RIGHT JOIN Signups s ON s.user_id = c.user_id
) T
GROUP BY T.user_id;
