-- Write your query below
Select name from customers left join orders  on customers.id = orders.customer_id
where customer_id is null;