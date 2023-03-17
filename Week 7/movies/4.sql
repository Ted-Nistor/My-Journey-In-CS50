SELECT COUNT(movies.title) FROM movies
JOIN ratings on movies.id = ratings.movie_id
WHERE ratings.rating = 10.0;