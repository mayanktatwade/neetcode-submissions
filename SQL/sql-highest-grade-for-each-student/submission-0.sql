-- Write your query below
with helper as(
    select *, row_number() over(partition by student_id order by score desc, exam_id) as rnk from exam_results 
)
select student_id, exam_id,score
from helper
where rnk = 1
order by student_id;