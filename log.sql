-- Keep a log of any SQL queries you execute as you solve the mystery.

-- list the description detail on crime committed on 07-28-2020
SELECT description FROM crime_scene_reports WHERE year = "2020" AND month = "07" AND day = "28" AND street = "Chamberlin Street";
-- Description: Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today
-- with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Ouput the transcript from the interviews conducted on July 28,2020 follow the theft
SELECT transcript FROM interviews WHERE year = "2020" AND month = "07" AND day = "28";

-- Ouput people who exit the courthouse parking lot within 10:15 and 10:25 the theft
SELECT name ,passport_number,phone_number FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 25 ORDER BY name;

name      | passport_number | phone_number
Amber     | 7526138472 | (301) 555-4174
Danielle  | 8496433585 | (389) 555-5198
Elizabeth | 7049073643 | (829) 555-5269
Ernest    | 5773159633 | (367) 555-5533
Evelyn    | 8294398571 | (499) 555-9472
Patrick   | 2963008352 | (725) 555-4692
Roger     | 1695452385 | (130) 555-0289
Russell   | 3592750733 | (770) 555-1861

--To output the people on call for less than 1 min who exit the courthouse parking lot within 10:15 and 10:25 the theft on that day
SELECT name ,passport_number,phone_number FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 25 AND people.license_plate IN
(SELECT people.license_plate FROM people WHERE phone_number IN (SELECT DISTINCT caller
FROM  phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60))ORDER BY name;

name    | passport_number | phone_number
Ernest  | 5773159633      | (367) 555-5533
Evelyn  | 8294398571      | (499) 555-9472
Roger   | 1695452385      | (130) 555-0289
Russell | 3592750733      | (770) 555-1861


-- To list people who have a flight booked on the July 29 and who left the courthouse parking betwen 10:15 -10:30
SELECT DISTINCT people.name ,people.passport_number,people.phone_number FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE license_plate IN (SELECT DISTINCT people.license_plate FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE activity = 'exit' AND month = '7' AND day = '28' AND hour = '10' AND minute BETWEEN 15 AND 30) AND flight_id IN
(SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29) ORDER BY name;

name     | passport_number | phone_number
Danielle | 8496433585      | (389) 555-5198
Ernest   | 5773159633      | (367) 555-5533
Evelyn   | 8294398571      | (499) 555-9472
Roger    | 1695452385      | (130) 555-0289
Russell  | 3592750733      | (770) 555-1861

-- To output people`s name who withdrew money from their bank account that day at atm: Fifer Street
SELECT people.name ,people.passport_number,people.phone_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month=7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Fifer Street') ORDER BY name;

name      | passport_number | phone_number
Bobby     | 9878712108      | (826) 555-1652
Danielle  | 8496433585      | (389) 555-5198
Elizabeth | 7049073643      | (829) 555-5269
Ernest    | 5773159633      | (367) 555-5533*
Madison   | 1988161715      | (286) 555-6063
Roy       | 4408372428      | (122) 555-4581
Russell   | 3592750733      | (770) 555-1861*
Victoria  | 9586786673      | (338) 555-6650

-- to Output the destination on July 29 by Ernest(passport number:5773159633), since Russell is excluded as having several destination
SELECT flights.destination_airport_id, flights.origin_airport_id, flights.hour, flights.day, flights.month, flights.year FROM flights
JOIN passengers ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
WHERE people.passport_number = 5773159633 AND flights.month = 7 AND flights.day = 29;

destination_airport_id | origin_airport_id | hour | day | month | year
                     4 |                 8 |    8 |  29 |     7 | 2020

-- Output the destination
SELECT * FROM airports WHERE id = 4;
   id | abbreviation | full_name        | city
    4 | LHR          | Heathrow Airport | London


-- To ouput people who received call from Ernest (367-555-5533) in the  phone_calls table
SELECT * FROM  phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration <= 60 AND caller ="(367) 555-5533";

id  | caller         | receiver       | year | month  | day | duration
233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7      | 28  | 45

-- To output the user(receiver) whose  phone number:(375) 555-8161 ; the Accomplice
SELECT * FROM people WHERE phone_number = '(375) 555-8161';
id     | name     | phone_number   | passport_number | license_plate
864400 | Berthold | (375) 555-8161 |                 | 4V16VO0



