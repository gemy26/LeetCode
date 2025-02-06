# Write your MySQL query statement below
select S.student_id ,S.student_name , SUB.subject_name, COUNT(E.student_id) attended_exams 
FROM Students S CROSS JOIN Subjects SUB
LEFT JOIN Examinations E ON E.student_id  = S.student_id 
AND SUB.subject_name  = E.subject_name 

GROUP BY S.student_id, S.student_name, SUB.subject_name
ORDER BY S.student_id, S.student_name, SUB.subject_name ASC
