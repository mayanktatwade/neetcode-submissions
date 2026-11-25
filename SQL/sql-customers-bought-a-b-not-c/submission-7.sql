-- Write your query below
((select c.customer_id, customer_name 
from customers as c
inner join orders on c.customer_id = orders.customer_id
where product_name = 'A'


intersect

select c.customer_id, customer_name 
from customers as c
inner join orders on c.customer_id = orders.customer_id
where product_name = 'B'

)
except

select c.customer_id, customer_name 
from customers as c
inner join orders on c.customer_id = orders.customer_id
where product_name = 'C')
order by customer_name;

