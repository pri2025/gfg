# Write your MySQL query statement below
select e.name
from Employee e join Employee emp 
on e.id = emp.managerId 
group by emp.managerId  having count(emp.managerId) >= 5