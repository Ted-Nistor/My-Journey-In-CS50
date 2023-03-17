-- Keep a log of any SQL queries you execute as you solve the mystery.
-- SELECT * FROM crime_scene_reports
--      WHERE day = 28 AND month = 7 AND year = 2021
--      AND street = "Humphrey Street";

-- SELECT * FROM interviews WHERE day = 28 AND month = 7 AND year = 2021 AND transcript LIKE "%bakery%";

-- SELECT * FROM bakery_security_logs
--      WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND activity = "exit" AND minute BETWEEN 15 AND 25;

-- SELECT * from atm_transactions
--      WHERE atm_location = "Leggett Street"
--      AND day = 28 AND month = 7 AND year = 2021 AND transaction_type = "withdraw";

--  SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- SELECT p.name
--  FROM phone_calls pc
--  JOIN people p ON pc.caller = p.phone_number
--  JOIN bakery_security_logs bsl ON p.license_plate = bsl.license_plate
--      WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28
--      AND bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28
--      AND bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25
--      AND pc.duration < 60;


-- SELECT id FROM airports WHERE city = "Fiftyville";

-- SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 AND year = 2021 ORDER BY hour,minute ASC LIMIT 1;
-- SELECT city FROM airports WHERE id = 4;

-- SELECT * FROM flights WHERE day = 29 AND origin_airport_id = 8 AND destination_airport_ID = 4;

-- SELECT p.name, p.phone_number, p.passport_number, p.license_plate, b.account_number
--FROM people p
--JOIN bank_accounts b ON p.id = b.person_id
--JOIN atm_transactions a ON b.account_number = a.account_number
--JOIN passengers ps ON p.passport_number = ps.passport_number
--JOIN phone_calls pc ON p.phone_number = pc.caller
--JOIN bakery_security_logs bs ON p.license_plate = bs.license_plate
--WHERE a.day = 28 AND a.month = 7 AND a.year = 2021 AND a.transaction_type = "withdraw"
--AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021 AND pc.duration < 60
--AND ps.flight_id = 36
--AND bs.day = 28 AND bs.month = 7 AND bs.year = 2021 AND bs.hour = 10 AND bs.minute BETWEEN 15 AND 25 AND bs.activity = "exit";

-- SELECT phone_number FROM people WHERE name = "Bruce";

-- SELECT * FROM phone_calls WHERE caller = "(367) 555-5533" AND day = 28
-- AND month = 7 AND year = 2021 AND duration < 60;

-- SELECT name FROM people WHERE phone_number = "(375) 555-8161";




