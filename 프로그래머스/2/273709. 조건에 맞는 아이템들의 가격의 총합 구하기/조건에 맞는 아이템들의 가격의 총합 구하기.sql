-- 코드를 작성해주세요

SELECT SUM(I.PRICE) as TOTAL_PRICE
FROM ITEM_INFO I
WHERE I.ITEM_ID IN
                    (SELECT ITEM_ID
                    FROM ITEM_INFO II
                    WHERE II.RARITY LIKE '%LEGEND%')