# CSCE_240_final

### Rules:
Starting Condition: The simulation will start with the grid full of soil objects each with the [maximum amout] of fertility and a 10 contigouous corn objects
1. If two crop objects share a border, one object has a free space adjacent, both are at least 60 days old, and the fertility of the free soil is above [value] then a new corn object of age 0 will be spawned
2. Each day the fertility value of a soil object with a corn object will decrease by [amount] 
3. Each day the fertility value of a soil object without a corn object will increase [amount] up to the max fertility value
4. Each day there is a [% chance] of a tornado being spawned
5. A tornado can destroy up to 10% of crops, if there are less than 10 crops a tornado can kill up to all of the crops
6. When a corn object is 200 days old it is harvested and its space becomes free
7. If fertility in a tile goes below 0 or equals 0 with a corn object in it the corn crop is killed and removed from the tile.
8. The fertility value of a soil object with a corn object below 60 days old will drop a random number less than the base drop in fertility (to simulate watering young plants) 
9. If the randomly generated move for any planting is illegal (out of bounds) then no move is made.
10. The fertility value of a soil object is not affected by a tornado

Stopping Conditon: 50 crops are harvested or 1000 days have passed, or all the corn has died
