-- 코드를 입력하세요
SELECT AI.DATETIME
FROM ANIMAL_INS AI
WHERE AI.DATETIME = (SELECT MIN(DATETIME) FROM ANIMAL_INS);