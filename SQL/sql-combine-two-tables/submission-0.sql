-- Write your query below
select first_name, last_name, city, state
from person as p left join address as a on p.person_id = a.person_id;