-- 코드를 입력하세요
SELECT MP.MEMBER_ID, MP.MEMBER_NAME, MP.GENDER, DATE_FORMAT(MP.DATE_OF_BIRTH, "%Y-%m-%d") as DATE_OF_BIRTH
FROM MEMBER_PROFILE MP
WHERE MONTH(MP.DATE_OF_BIRTH) = '3' AND NOT ISNULL(MP.TLNO) AND MP.GENDER = 'W'
ORDER BY MP.MEMBER_ID ASC;