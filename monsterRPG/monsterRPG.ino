
int NPCs[10][5]; //NPCs are the Monsters in the dungeon and there stats. NPCs can be found at random.
int PC[5]; //Player Charater stats
int level = 1; //PC starting level
int gold = 0; //starting player gold

//Areas are names of rooms in the dungeon
String Areas[10] = {"Library","Entrance","Walk Way", "Stand", "Pizza Place","Six","Seven","8","9","10"};

//Names of the Monsters in the dungeon
String Monsters[10] = {"Cyborg",
                    "Cat Man",
                    "Dog Face",
                    "Bat Dude",
                    "Laptop Thing",
                    "The Black Phantom",
                    "Green Meanie",
                    "Pod Face",
                    "Glenda",
                    "Some Bad Thing" };
                    
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("This is a Turn-Based RPG (sorta)");
Serial.println("Monster RPG");
Serial.print("Generating NPCs");
randomSeed(analogRead(0) + analogRead(1));
createNPCS();
Serial.print("Generating PC stats");
generatePC();

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0; i<10; i++) {
  
    Serial.print("Monster : ");
    Serial.print(i+1);
    Serial.print(" ");
    Serial.println(Monsters[i]);
    Serial.print("Hit Points: ");
    Serial.println(NPCs[i][0]);
    Serial.print("Ability Dice: ");
    Serial.println(NPCs[i][1]);
    Serial.print("Danger Dice: ");
    Serial.println(NPCs[i][2]);
    Serial.print("Threat Dice: ");
    Serial.println(NPCs[i][3]);
    Serial.print("Bonus Dice: ");
    Serial.println(NPCs[i][4]);
    Serial.println();
}

for (int i=0; i<10; i++) {
  Serial.println(Areas[i]);
}
Serial.println();
Serial.println("Your Stats: ");
Serial.print("Hit Points: ");
Serial.println(PC[0]);
Serial.print("Ability Dice: ");
Serial.println(PC[1]);
Serial.print("Danger Dice: ");
Serial.println(PC[2]);
Serial.print("Threat Dice: ");
Serial.println(PC[3]);
Serial.print("Bonus Dice: ");
Serial.println(PC[4]);
Serial.print("Level: ");
Serial.println(level);
Serial.print("Gold: ");
Serial.println(gold);

while(1) {}
}

void createNPCS() {
  for (int i=0; i<10; i++) {
    for (int y=0; y<5; y++) {
      NPCs[i][y] = random(1, 13);
      Serial.print("..");
      
    }
  }
  Serial.println();
  
}

void generatePC() {
  for (int y = 0; y<5; y++) {
    PC[y] = random(1,13);
    Serial.print(".....");
  }
  Serial.println();
  Serial.println();
}

