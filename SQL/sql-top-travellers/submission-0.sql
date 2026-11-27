-- Write your query below
WITH helper as(
    select user_id, sum(distance) as travelled_distance
    from rides
    group by user_id
)
select name, 
case when travelled_distance is null then 0
else travelled_distance end as
travelled_distance
from users left join helper on users.id = helper.user_id
order by travelled_distance DESC, name;