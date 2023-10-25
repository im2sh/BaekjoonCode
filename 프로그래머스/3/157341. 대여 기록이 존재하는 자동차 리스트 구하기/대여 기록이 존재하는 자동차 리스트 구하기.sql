-- 코드를 입력하세요
SELECT DISTINCT H.CAR_ID
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
WHERE EXTRACT(MONTH FROM H.START_DATE) = 10 AND CAR_ID IN (
                                                    SELECT CAR_ID
                                                    FROM CAR_RENTAL_COMPANY_CAR C
                                                    WHERE C.CAR_TYPE = '세단')
ORDER BY H.CAR_ID DESC