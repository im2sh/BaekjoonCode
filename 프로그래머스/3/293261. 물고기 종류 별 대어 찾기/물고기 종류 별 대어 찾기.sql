-- 코드를 작성해주세요
SELECT FI.ID, FNI.FISH_NAME, FI.LENGTH
FROM FISH_INFO FI
JOIN FISH_NAME_INFO FNI ON FI.FISH_TYPE = FNI.FISH_TYPE
WHERE (FNI.FISH_NAME, FI.LENGTH) IN (SELECT FNI.FISH_NAME, MAX(FI.LENGTH) FROM FISH_INFO FI JOIN FISH_NAME_INFO FNI ON FI.FISH_TYPE = FNI.FISH_TYPE GROUP BY FNI.FISH_NAME HAVING MAX(FI.LENGTH))
ORDER BY FI.ID ASC;