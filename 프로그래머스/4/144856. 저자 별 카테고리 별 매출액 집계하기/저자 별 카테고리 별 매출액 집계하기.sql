-- 코드를 입력하세요
SELECT A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM(SALES * B.PRICE) AS TOTAL_SALES
FROM BOOK B
JOIN BOOK_SALES BS ON B.BOOK_ID = BS.BOOK_ID
JOIN AUTHOR A ON B.AUTHOR_ID = A.AUTHOR_ID
WHERE BS.SALES_DATE LIKE '2022-01%'
GROUP BY B.AUTHOR_ID, B.CATEGORY
ORDER BY A.AUTHOR_ID ASC, B.CATEGORY DESC;