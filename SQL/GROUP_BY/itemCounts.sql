SELECT ITEM_NAME, ITEM_TYPE, COUNT(*) AS ITEM_COUNT
FROM AVAILABLEITEMS
GROUP BY ITEM_NAME, ITEM_TYPE
ORDER BY ITEM_TYPE, ITEM_NAME;