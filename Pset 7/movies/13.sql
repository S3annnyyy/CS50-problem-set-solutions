/*  In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
    Your query should output a table with a single column for the name of each person.
    There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
    Kevin Bacon himself should not be included in the resulting list. */

/* find movies that Kevin Bacon starred in and then find the people that starred in the same movie*/

SELECT DISTINCT(name)
FROM people
WHERE name IS NOT "Kevin Bacon" AND id IN(
    /* finding person id of cast including Kevin Bacon (TO BE FILTERED ABOVE) */
    SELECT person_id
    FROM stars
    WHERE movie_id IN(
        /* finding all the id of movies Kevin bacon starred in */
        SELECT movies.id                              
        FROM movies
        JOIN stars
        ON stars.movie_id = movies.id
        JOIN people
        ON people.id = stars.person_id
        WHERE name = "Kevin Bacon" AND birth = 1958))
ORDER BY name
