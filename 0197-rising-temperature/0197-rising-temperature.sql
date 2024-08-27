# Write your MySQL query statement below
select w.id
from Weather w inner join Weather ww
on subdate(w.recordDate ,1) =  ww.recordDate and
w.temperature > ww.temperature;