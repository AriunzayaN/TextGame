CREATE TABLE games(
  gamename VARCHAR(20) NOT NULL UNIQUE,
  state TEXT NOT NULL,
  PRIMARY KEY(gamename)
);
