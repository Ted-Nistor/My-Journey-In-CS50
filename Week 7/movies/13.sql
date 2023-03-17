SELECT DISTINCT people.name FROM people
JOIN stars AS s1 ON people.id = s1.person_id
JOIN stars AS s2 ON s1.movie_id = s2.movie_id AND s2.person_id <> s1.person_id
JOIN movies ON s1.movie_id = movies.id
JOIN people AS p1 ON s2.person_id = p1.id
WHERE p1.name = 'Kevin Bacon' AND movies.title IN (
  SELECT movies.title FROM movies
  JOIN stars ON movies.id = stars.movie_id
  JOIN people ON stars.person_id = people.id
  WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
)
ORDER BY people.name;
