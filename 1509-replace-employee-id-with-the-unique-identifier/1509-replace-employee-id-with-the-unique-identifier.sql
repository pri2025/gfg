# Write your MySQL query statement below
select e.name,emp.unique_id
from Employees e left join EmployeeUNI emp on e.id = emp.id;