/* global $ */
/* global input */

var totalCost = 0;
var shippingCost = 0;


$(document).ready(function(){
    
    $('#qty_item1').on('change', function()
    {
        totalCost += 30 * $("#qty_item1").val();
        $("#totalItem1").html("$" + 30 * $("#qty_item1").val());
    });
    $('#qty_item2').on('change', function()
    {
        totalCost += 20 * $("#qty_item2").val();
        $("#totalItem2").html("$" + 20 * $("#qty_item2").val());
    });
    
    
    $("button").on("click", function(){
        
        
        if($("#qty_item1").val() > 0) 
        {
            console.alert("test");
            totalCost = ($("#qty_item1").val() * 30);//calc total item 1
            $("#totalItem1").html(`($("#qty_item1").val() * 30)`);
            
        }
        if($("#qty_item2").val() > 0) 
        {
            console.alert("test");
            totalCost = ($("#qty_item2").val() * 40);//calc total item 1
            
        }
        
        $("#shippingQuantity").on("click", function()
        {
           if($("#shippingQuantity").val() =="15"){
               shippingCost += 15;
           }else if($("shippingQuantity").val() == "10"){
               shippingCost += 10;
           }else if($("shippingQuantity").val() == "5"){
               shippingCost += 5;
           }
           $("#shippingCost").html("$" + shippingCost);
        });
        
        
        function cost()
        {
            totalCost += shippingCost;
        }
         
        });
    
    
});