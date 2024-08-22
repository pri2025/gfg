# Write your MySQL query statement below
select w.id
from Weather w inner join Weather ww
on datediff(w.recordDate , ww.recordDate) = 1 and
w.temperature > ww.temperature;