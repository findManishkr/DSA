`sql`-> 

 * sql is a language to interact with relational databases(RDbMS)

`ex` -> mysql, postgre sql etc


`what sql databases follow`->

* structured data arranged in tables( rows & columns)
* fixed schema -> structure of data (col, types, constrains) must be define be inserting the data init
* supports acid properites ( good for consistency)
* supports join

`atomicit`-> all or nothing ie a transcition must complete full or not execute at all

`consistency` -> a database must remain in valid state before and after a transcition


`isolation` -> multiple transcitions happeing at same time should not affect each other's result

example -> two peoples buying the last ticket

* transcition 1 -> cheks availabilty
* transcitiion 2 -> cheks availabity

isolation insures only 1 transcition gets tickt

withoout isolation double booking happens

`durability`-> 

* once a transcition is commited, data is saved permanently,
  even if 
  - system crashesh
  - power goes of 
  - server restarts


  acide properties ensures `transcition are `safe`, `realiable`, and `consistent``;




 `indexing `-> indexing is a data structure used by databases to speed up search querues , instead of scanning the 
           whole data  , indexing allows the database to directly locate the required data






`joins`


`inner join`->

returns only matching rows from both the tables

 ie gives only the common data 

 `left join`-> returns all rows form the left + matching rows form the right

 `full join`-> returns all rows form both the tables whetehre matched or not

 `cross join`-> returns cartesian product





 `mysql`








`nosql`->

1. supports flexible schema
2. stores data as document


