-- Keep a log of any SQL queries you execute as you solve the mystery.

-- list the description detail on crime committed on 07-28-2020
SELECT description FROM crime_scene_reports WHERE year = "2020" AND month = "07" AND day = "28" AND street = "Chamberlin Street";
-- Description: Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today
-- with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Ouput the transcript from the interviews conducted on July 28,2020 follow the theft
SELECT transcript FROM interviews WHERE year = "2020" AND month = "07" AND day = "28";

-- Ouput people who exit the courthouse parking lot within 10:15 and 10:25 the theft
SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 25 ORDER BY name;

--To output the people on call for less than 1 min from on that day
SELECT DISTINCT name FROM people WHERE phone_number IN (SELECT DISTINCT caller
FROM  phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60) ORDER BY name;

-- To output the account number of all withdrawals made that day at that location
SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month=7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Fifer Street';

-- To output passengers list who left the parking within the theft day from 10:15-10:25
 SELECT DISTINCT name FROM people
 JOIN passengers ON people.passport_number = passengers.passport_number
 WHERE license_plate IN (SELECT DISTINCT people.license_plate FROM people
 JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
 WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 25) ORDER BY name;

-- To list people who have a flight booked on the July 29 and who left the courthouse parking betwen 10:15 -10:30
SELECT DISTINCT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE license_plate IN (SELECT DISTINCT people.license_plate FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 30) AND flight_id IN
(SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29) ORDER BY name;

-- To output people`s name who withdrew money from their bank account that day at atm: Fifer Street
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month=7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Fifer Street') ORDER BY name;

-- To output the call receiver
SELECT DISTINCT name FROM people WHERE phone_number IN (SELECT DISTINCT receiver
FROM  phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60) ORDER BY name;

-- To ouput people who received call from the thief in the  passenger list
SELECT DISTINCT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE people.name IN (SELECT DISTINCT name FROM people WHERE phone_number IN (SELECT DISTINCT receiver
FROM  phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)) ORDER BY name;

-- To output the earliest flights
SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour ASC,minute ASC;

-- To output passport from passenger whose flights in earliest on the July 29th
SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour ASC,minute ASC);

-- Earliest flight people's name on July 29th,
SELECT name FROM people WHERE people.passport_number IN (SELECT passport_number FROM passengers WHERE flight_id
IN (SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour ASC,minute ASC)) ORDER BY name;