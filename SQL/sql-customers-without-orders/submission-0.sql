select c.name from customers c where id not in (select customer_id from orders)
