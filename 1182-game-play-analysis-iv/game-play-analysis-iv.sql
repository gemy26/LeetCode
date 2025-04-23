WITH cnt AS (
    SELECT COUNT(DISTINCT player_id) AS players 
    FROM activity
),
first_login AS (
    SELECT player_id, MIN(event_date) AS first_event_date 
    FROM activity 
    GROUP BY player_id
)
SELECT 
    CASE 
        WHEN COUNT(A.player_id) = 0 THEN 0
        ELSE ROUND(COUNT(A.player_id) / cnt.players, 2)
    END AS fraction
FROM activity A
JOIN first_login F
  ON A.player_id = F.player_id 
 AND DATEDIFF(A.event_date, F.first_event_date) = 1
JOIN cnt;
