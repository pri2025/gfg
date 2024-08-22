# Write your MySQL query statement below
select w.id
from Weather w inner join Weather ww
on w.recordDate - interval 1 day = ww.recordDate and
w.temperature > ww.temperature;