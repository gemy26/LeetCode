# Write your MySQL query statement below
with minYear AS(
    select product_id , min(year) as year from Sales group by product_id 
)
select Sales.product_id, minYear.year as first_year , quantity , price  from Sales join minYear on Sales.product_id =  minYear.product_id
where  Sales.year = minYear.year

