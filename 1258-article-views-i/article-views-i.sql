-- Write your PostgreSQL query statement below
select distinct author_id AS id from views where author_id = viewer_id order by author_id asc;