-- https://programmers.co.kr/learn/courses/30/lessons/59046

SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME LIKE 'Lucy' OR 
      NAME LIKE 'Ella' OR 
      NAME LIKE 'Pickle' OR
      NAME LIKE 'Rogan' OR
      NAME LIKE 'Sabrina' OR
      NAME LIKE 'Mitty'
ORDER BY ANIMAL_ID