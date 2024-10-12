-- 코드를 입력하세요
SELECT D.DR_NAME, D.DR_ID, D.MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d') as HIRE_YMD
FROM DOCTOR D
WHERE D.MCDP_CD = 'CS' OR D.MCDP_CD = 'GS'
ORDER BY D.HIRE_YMD DESC, D.DR_NAME ASC;