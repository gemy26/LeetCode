/* Write your T-SQL query statement below */
SELECT R.contest_id, 
ROUND((COUNT(DISTINCT R.user_id)*100.00 / (SELECT COUNT(user_id) FROM USERS)), 2) as percentage
FROM Register as R 
Group By R.contest_id
Order By percentage DESC, R.contest_id ASC