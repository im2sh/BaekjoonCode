-- 코드를 입력하세요
# SELECT *
# FROM ONLINE_SALE OS
# GROUP BY YEAR(OS.SALES_DATE), MONTH(OS.SALES_DATE)

SELECT YEAR(OS.SALES_DATE) AS YEAR, MONTH(OS.SALES_DATE) AS MONTH, UI.GENDER, COUNT(DISTINCT UI.USER_ID) AS USERS
FROM USER_INFO UI
JOIN ONLINE_SALE OS ON UI.USER_ID = OS.USER_ID
WHERE NOT ISNULL(UI.GENDER)
GROUP BY YEAR(OS.SALES_DATE), MONTH(OS.SALES_DATE), UI.GENDER
ORDER BY YEAR ASC, MONTH ASC, GENDER ASC;