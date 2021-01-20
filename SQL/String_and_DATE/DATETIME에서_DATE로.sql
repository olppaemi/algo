-- DATE_FORMAT(DATE, 형식)
-- 형식에는 %Y(4자리 연도), %y(2자리 연도), %m(월), %d(일), %H(24시간), %h(12시간), %i, %s가 있습니다.

SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m%-%d') AS 날짜
FROM ANIMAL_INS
ORDER BY ANIMAL_ID