var faker = require('faker'); 

var randomName = faker.name.findName(); 
var randomEmail = faker.internet.email(); 
var randomCard = faker.helpers.createCard();

var answer = readline();
for(let i = 0 ; i < answer ; i ++)
{
    console.log("INFO FOR CLIENT ID: " +[i] );
    console.log(faker.fake( "PERSONAL: {{name.lastName}}, {{name.firstName}} {{name.suffix}} "));
    console.log(faker.fake( "EMAIL   : {{internet.email}} "))
    console.log(faker.fake( "FINANCE : {{finance.currencyCode}} Amount:{{finance.amount}} :: BITCOIN ADDRESS: {{finance.bitcoinAddress}}"));
}
//console.log(faker.fake("{{name.lastName}}, {{name.firstName}} {{name.suffix}} " +"EMAIL:"+ randomEmail));