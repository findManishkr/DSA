 `introduce your self`




good morning sir , my name is manish kumar, and i'm studing mechancial engineering at 
iit bhu , along with my core course work i've completed data structre and algorithm cores, also i 
love to solve dsa problems , alos i'm intersedt in web development i have exprolred mern technologies by making projects.

also i served as core member of health and hygiene club where i helped to organize health awarness initatives and contributed to improving student well being at iit bhu.

that's small introducion of my self.





`tell me about about your research internship at iit bhu`


during my research internship at iit bhu, i worked on a project involving `prediction of wind speed in coastal areas using era 5 data `  era 5 is live website that provides live meterological data,

the goal was to accurately forecast wind speed for jamnagar coastal regiion, which is improtant for disaster
management , renewable energy planning and marine safety.


i started by automating the data aquisition , for this i used the era 5 data set from copernicus climate data store and wrote python script using the cds api library to automatically large volumes of meterological  data for the year 2021 , this step was essentioal because manually downloading dozens of netcdf file was not feasible and;


after collectiong data i converted netcdf data into csv formats
using `xarray` and `pandas` to make them usable for machine learning workflows;


next i performed data cleaning , validation , normalization, and featrue engineering , i added temporal features like month hour and derived important meterological variables


for modelling , i trained 3 models

`random forest`

`xgboost`

`ann artificai neural networks`

among them `random` forest achieved the best performance wih and R^2 of .75. followed by ann , and xgboost


overall it was a great opportunity to get awareness about ml technologies and understant their relevance in today's al focused world





`project 1`



`build and deployed a full stack movie booking web app usng mern tecnolgy`

for devloping this applicaton

i used

`mongodb`-> database to stores users details, moviens, names, seats configuration, booking styss

`express.js`-> back frame work to build apis

def-> express.js is light weight and fast web appliaction 
 framework for node.js to build backend servers, apis etc

 by provinding useful features like 

 `routing`

 `middle ware`


 `request handling`

 `response management `







 `react js` -> ui for users to browse movies and book
   tickets


 `nodes.js` -> server environment


 for example when a user selects a movie

 * react sends a requers ->/api/movies/:id

 * express receives it 
 * node processes it 
 *  mongo db returns movie details



 `implemented authentication with cleark supporing email`
 ` phone  and social log in  with multi profile swithcing`


 `cleark`-> modern authenticaion and user management service that provides, ready to use login , signup, and user profile for web and mobile appliccations


 it handles all the hard parts of authentications and devlopers dont have to implemnt them manually

* log in with email + password

* log in with phone otp
*  log in with google tech

* users can also switch b/w multiple prfiles ( personal vs familiy acouunt)

# for example 

if a user logs in using google, clerk 

* verifies identity 
* creates an user account automatically
* returns a secure tocken 
* allows further access to the app



`developed a seat reservation styse with stripe payments in cluding 10 minutes seat hold and auto re-lease for failed/ cancelled transctions`;

what it means->

* when a user select seats ,
 it locs those seats for 10 minutes,
* no body else can book those seats during that window

* if payment succeeds -> booking confirm
* if payment fails / cancelled -> seat automatically unlocked



suppose user `A` selects seat a1 at 600pm

backend marks seat a1 as blocked time stamp 
* if user a does not pay by 6.10 am your backend script unblocks a1

* user b opening the same show at 6;06 pm cannot see seat aq availbale 

* but at 6:11 pm , the system automatically frees the seat

this requrires designming a state maching ->

### available -> blocked -> booked ###


`stripe `->
 is s secure devloper friendly online plateform that allows appliccatiosn to accept payement using credit cards, upi , net banking , wallets and many other mehtos

 it handls all the complex part of online payments , security , fraud detections , billing receipts


 how it works

 1- frontend creates a payment request

  ex user chooses seats worth 300
  fronted called backend -> backedn creates a stripe chekout seion


 2 stripe handles payment uii

  user enters upi card details 


`one line stripe`-> it si secrue payment gateway that i
integrated into my movie booking app to handle tickets payements , it manages payment processing , veriefies transction, and triggers backedn webhooks that confirm or cancel seating booling 





`desinged an admit dashboard to mange movie and bookings`

admins have a seprate log in interface 

they , cca

* add movies, 
* add theatere show, timing
* chek all bookings 

* edit or delete movies

admin logs in -> goes to dashboard -> clicks add moves-> fills form -> backend stroes in mongodb-> moves appers on user dise




`automaited emalis( confirmatiosn and reminders) using 
inngest background jobs`


it creates automated notifications that run in background without blocking the main serverswh


`about inngest `
it is background job and event processing plateform

it allows you to run tasks like sending mails, processing web hooks , cleaing data , scheduing jobs  all outside your main serves withoud blocking user requests









### project no - 2 ###

` i devloped a full stack ai powered blog portal suing the mern stack with an admin dashboard for blog and commend managment`



`admin`-> i autohorides person who has complete control over website


# mongodb

mongo db stores all the data for the blog plateform

* blog posts
* blog categoreis
* authurs
* user comments
* admin details
* images ( via image kit urls)


beacuse mongodb is flexible , each blog can store dynamic content , tags, author info , timestamps




`express.js`-> Backend api layer 

just like project 1 express.js handles 

`routing`

apis like 
* post/blogs ( create blog)
* get / blogs( liss blog )
* put / blogs/:id( update blog)
* delete/ blogs/:id ( delete blog)

`middle ware`->

* authentication chekcking 

* comment walidation 
* image validation
* error handling 

`resqust and response managment`->

express receives apis request from react and returns json
responsed
















































## project 3 ###


` i built the git version control system in javascript(Node.js) using the file system(fs) module implemnting the core commands like 'init', 'add', 'commit', 'log', and 'status`;



*** 1. Tech used  -> Node.js + file system (fs) module ***


I used Node.js because it provides access to the file system and asynchronous operations 

`using the fs module` i could->

* create folder 
* read / write files
* generate meta data for commits
* store object shapshots


Essentially i built a simplified version of how `git stores`  and `tracks data`;



*** 2. Implemented core git commands ***


`init` -> initialize a repo

what is does :->

Creates a hidden folder .mygit (like .git) inside the project directory.

inside .mygit , it stores

* a folder for commit 
* a folder for staging area 
* A config file


example 

when user types `mygit init`



out