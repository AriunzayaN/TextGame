CREATE TABLE users(
  username VARCHAR(20) NOT NULL UNIQUE,
  state TEXT NOT NULL,
  PRIMARY KEY(username)
);
