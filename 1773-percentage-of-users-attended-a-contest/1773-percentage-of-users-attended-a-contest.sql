WITH TotalUsers AS (
    SELECT COUNT(*) * 1.0 AS total_users FROM Users
),
UserRegistrations AS (
    SELECT contest_id, user_id 
    FROM Register 
    GROUP BY contest_id, user_id
),
ContestParticipation AS (
    SELECT contest_id, COUNT(user_id) AS registered_users
    FROM UserRegistrations
    GROUP BY contest_id
)
SELECT 
    CP.contest_id, 
    ROUND((CP.registered_users * 100.0) / TU.total_users, 2) AS percentage
FROM ContestParticipation CP
CROSS JOIN TotalUsers TU
ORDER BY percentage DESC, CP.contest_id ASC;
