SELECT
ROUND(AVG(ratings.rating), 2)
FROM
ratings
JOIN
movies
ON
ratings.movie_id = movies.id
WHERE
year = 2012
