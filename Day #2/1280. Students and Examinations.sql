SELECT s.student_id , s.student_name, s.subject_name , count(e.student_id) as attended_exams
from (SELECT * FROM Students join Subjects on 1) s left outer join Examinations e
on s.student_id = e.student_id AND s.subject_name = e.subject_name
group by s.student_id , s.subject_name
order by s.student_id , s.subject_name