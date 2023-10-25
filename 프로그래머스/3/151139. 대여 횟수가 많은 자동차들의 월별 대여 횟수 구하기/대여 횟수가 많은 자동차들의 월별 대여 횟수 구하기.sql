-- 코드를 입력하세요

SELECT EXTRACT(MONTH FROM C.START_DATE) as MONTH, C.CAR_ID, COUNT(C.CAR_ID) as RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY C
WHERE EXTRACT(MONTH FROM C.START_DATE) BETWEEN 8 AND 10 AND C.CAR_ID IN (SELECT C.CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY C
                    WHERE TO_CHAR(C.START_DATE, 'YYYY-MM') = '2022-08' OR TO_CHAR(C.START_DATE, 'YYYY-MM') = '2022-09' OR TO_CHAR(C.START_DATE, 'YYYY-MM') = '2022-10'
                    GROUP BY C.CAR_ID
                    HAVING COUNT(C.CAR_ID) >= 5)
GROUP BY EXTRACT(MONTH FROM C.START_DATE), C.CAR_ID
HAVING COUNT(CAR_ID) > 0
ORDER BY MONTH ASC, CAR_ID DESC;


