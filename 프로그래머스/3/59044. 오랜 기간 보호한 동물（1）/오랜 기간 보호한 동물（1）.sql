-- 코드를 입력하세요
SELECT AI.NAME, AI.DATETIME
FROM ANIMAL_INS AI
LEFT JOIN ANIMAL_OUTS AO ON AI.ANIMAL_ID = AO.ANIMAL_ID
WHERE ISNULL(AO.DATETIME)
ORDER BY AI.DATETIME ASC
LIMIT 3;