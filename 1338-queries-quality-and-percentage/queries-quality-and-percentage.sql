-- # Write your MySQL query statement below
SELECT query_name, ROUND(
    AVG(
    CAST(rating AS DECIMAL) / position
    ), 2
) AS quality,
    ROUND(
        COUNT(IF(rating < 3, 1, null)) / COUNT(query_name) * 100.00
        , 2) as poor_query_percentage
    from Queries
    group by
    query_name
