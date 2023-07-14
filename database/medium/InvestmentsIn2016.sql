/* Write your T-SQL query statement below */
SELECT ROUND(SUM(I1.tiv_2016), 2) AS tiv_2016
FROM Insurance I1
WHERE EXISTS (
    SELECT I2.pid
    FROM Insurance I2
    WHERE I1.pid != I2.pid
        AND I1.tiv_2015 = I2.tiv_2015
) AND NOT EXISTS (
    SELECT I2.pid
    FROM Insurance I2
    WHERE I1.pid != I2.pid
        AND I1.lat = I2.lat
        AND I1.lon = I2.lon
);