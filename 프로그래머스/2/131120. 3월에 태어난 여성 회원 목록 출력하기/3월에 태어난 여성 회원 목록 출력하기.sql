-- 코드를 입력하세요 
SELECT M.MEMBER_ID, M.MEMBER_NAME, M.GENDER, DATE_FORMAT(M.DATE_OF_BIRTH, '%Y-%m-%d') as DATE_OF_BIRTH
FROM MEMBER_PROFILE M
WHERE MONTH(DATE_OF_BIRTH) = 3 AND NOT ISNULL(TLNO) AND M.GENDER = 'W'
ORDER BY M.MEMBER_ID;