-- 코드를 작성해주세요
SELECT SUM(II.PRICE) AS TOTAL_PRICE
FROM ITEM_INFO II
WHERE II.RARITY = 'LEGEND';