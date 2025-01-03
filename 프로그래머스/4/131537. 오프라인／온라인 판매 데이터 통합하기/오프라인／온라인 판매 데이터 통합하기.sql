# -- 코드를 입력하세요
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE OS
WHERE OS.SALES_DATE LIKE '2022-03%'
UNION ALL
SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
FROM OFFLINE_SALE OFS
WHERE OFS.SALES_DATE LIKE '2022-03%'
ORDER BY SALES_DATE ASC, PRODUCT_ID ASC, USER_ID ASC