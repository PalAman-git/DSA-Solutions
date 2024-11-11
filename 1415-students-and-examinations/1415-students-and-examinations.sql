# Write your MySQL query statement below
WITH AllCombinations AS(
    SELECT s.student_id,s.student_name,sub.subject_name
    FROM Students s
    CROSS JOIN Subjects sub
),
AttendanceCount AS(
    SELECT a.student_id,a.subject_name,COUNT(e.student_id) AS attended_exams
    FROM AllCombinations a
    LEFT JOIN Examinations e
    ON a.student_id = e.student_id AND a.subject_name = e.subject_name
    GROUP BY a.student_id,a.subject_name
)
SELECT ac.student_id,s.student_name,ac.subject_name,ac.attended_exams
FROM AttendanceCount ac
JOIN Students s 
ON ac.student_id = s.student_id
ORDER BY ac.student_id,ac.subject_name;