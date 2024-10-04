#include <Arduboy2.h>
Arduboy2 arduboy;

#define GAME_TITLE  0
#define GAME_OVER  1
#define GAME_SELECT  2
#define GAME_PONG  3
#define GAME_TENNIS  4
#define GAME_FOOTBALL  5
#define GAME_HOCKEY  6
#define GAME_BASKETBALL  7

int gameState = GAME_TITLE;

//gameselectionscreen
int gameSelected = 0;
int columnOfGames = 0;

//title
float textX = 63;
float textY = 33;

int textRightSpeed = 1;
int textDownSpeed = 1;

//score
int playerOneScore = 0;
int playerTwoScore = 0;

//pong
int hollowBallX = 63;
int hollowBallY = 33;
int hollowBallSize = 2;
int hollowBallRightSpeed = 1;
int hollowBallDownSpeed = 1;

int racketWidth = 3;
int racketHeight = 8;

int playerOneRacketX = 0;
int playerOneRacketY = 0;

int playerTwoRacketX = 127 - racketWidth;
int playerTwoRacketY = 0;

//tennis
float tennisBallX = 63;
float tennisBallY = 33;

int tennisBallSize = 4;
int tennisBallRightSpeed = 1;
int tennisBallDownSpeed = 1;

int racquetWidth = 2;
int racquetHeight = 13;

int playerRacquetX = 0;
int playerRacquetY = 0;

int computerRacquetX = 127 - racquetWidth;
int computerRacquetY = 0;


const uint8_t PROGMEM logo[] = {
    64, 25,
    0x00, 0xe0, 0x18, 0x04, 0x06, 0x02, 0x01, 0xc1, 0xa1, 0xe1, 0x01, 0x01, 0x02, 0x06, 0x0c, 0xfe, 0x02, 0x03, 0x01, 0x01, 0x03, 0x02, 0x06, 0x0c, 0x1c, 0x76, 0xc1, 0x01, 0x01, 0x03, 0x0e, 0x3c, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0xf0, 0x1e, 0x03, 0x01, 0x01, 0x03, 0x0e, 0xfc, 0x06, 0x02, 0x02, 0x03, 0x01, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0xc2, 0xe2, 0xfc, 0xf0, 0xe0, 0x80, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0x98, 0x08, 0x0c, 0x06, 0x03, 0x00, 0xf8, 0xfc, 0x7c, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc7, 0xc7, 0x87, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x17, 0xe7, 0x87, 0x03, 0x01, 
    0x01, 0x1f, 0x70, 0xc0, 0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x03, 0x0c, 0x18, 0x30, 0x60, 0x40, 0xc1, 0xc3, 0xc2, 0xc3, 0xc1, 0xc0, 0xe0, 0xf8, 0xfe, 0x61, 0x40, 0x40, 0x40, 0xc0, 0xfe, 0xff, 0xfe, 0xfc, 0xf0, 0x70, 0x20, 0x60, 0xc0, 0xc0, 0xc0, 0xf0, 0xfe, 0xf9, 0xe0, 0x60, 0x20, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xfe, 0x7f, 0x7f, 0x3f, 0x1c, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };

static void titlescreen()
{
  Sprites::drawOverwrite(33, 12, logo, 0);

  arduboy.setCursor(22, 55);
  arduboy.print("Press A to play");

  if (arduboy.justPressed(A_BUTTON)) 
  {
    gameState += 2;
  }    
}

static gameover()
{
  if(textRightSpeed == 1) 
  {
    textX += 0.5;
  }
  if(textRightSpeed == -1) 
  {
    textX -= 0.5;
  }
   
  if(textDownSpeed == 1) 
  {
    textY += 0.5;
  }  
  if(textDownSpeed == -1) 
  {
    textY -= 0.5;
  }
      
  if(textY == 0) 
  {
    textDownSpeed = 1;
  }  
  if (textY + 7 == 63) //9/5 - special value for bouncing 
  {
    textDownSpeed = -1;
  }

  if (textX == 0) 
  {
    textRightSpeed = 1;
  } 
  if (textX + 27 == 127) 
  {
    textRightSpeed = -1;
  }

  arduboy.setCursor(textX, textY);
  arduboy.print("Loser");
}

static gamewin()
{
  arduboy.setCursor(random (45, 57), random(28, 36));
  arduboy.print("Winner");
}

static playeronewon()
{
  arduboy.setCursor(41, 33);
  arduboy.print("Player 1 Wins");
}

static playertwowon()
{
  arduboy.setCursor(41, 33);
  arduboy.print("Player 2 Wins");
}

static void gameselectionscreen()
{
  arduboy.setCursor(21,0);
  arduboy.print("Select The Game");
  //first column
  arduboy.setCursor(0,16);
  arduboy.print("  Pong"); 
  arduboy.setCursor(0,32);
  arduboy.print("  Tennis");
  arduboy.setCursor(0,48);
  arduboy.print("  Football");
  //second column
  arduboy.setCursor(50,16);
  arduboy.print("  Basketball");
  arduboy.setCursor(74,32);
  arduboy.print("  Kicker");
  arduboy.setCursor(74,48);
  arduboy.print("  Hockey");

  if (gameState == 2) 
  {
    arduboy.setCursor(0,100);
  }

  if (arduboy.justPressed(DOWN_BUTTON))
  {
    gameSelected++;

    if (gameSelected > 3)
    {
      gameSelected = 3; 
    }
  }
  else if (arduboy.justPressed(UP_BUTTON) && gameSelected != 0)
  {
    gameSelected--;

    if (gameSelected < 1)
    {
      gameSelected = 1; 
    }
  }
  else if (arduboy.justPressed(RIGHT_BUTTON))
  {
    columnOfGames = 1;

    if (columnOfGames > 1)
    {
      columnOfGames = 1;
    }
  }
  else if (arduboy.justPressed(LEFT_BUTTON))
  {
    columnOfGames = 0;

    if (columnOfGames < 0)
    {
      columnOfGames = 0;
    }
  }

  if (gameSelected == 1 && columnOfGames == 0)
  {
    arduboy.setCursor(0,16);

    if (arduboy.justPressed(A_BUTTON))
    {
      gameState = 3;
    }
  }

  if (gameSelected == 2 && columnOfGames == 0)
  {
    arduboy.setCursor(0,32);

    if (arduboy.justPressed(A_BUTTON))
    {
      gameState = 6;
    }
  }

  if (gameSelected == 3 && columnOfGames == 0)
  {
    arduboy.setCursor(0,48);

    if(arduboy.justPressed(A_BUTTON))
    {
      gameState = 8;
    }
  }

  if (gameSelected == 1 && columnOfGames == 1)
  {
    arduboy.setCursor(50,16);

    if(arduboy.justPressed(A_BUTTON))
    {
      gameState = 10;
    }
  }

  if (gameSelected == 2 && columnOfGames == 1)
  {
    arduboy.setCursor(74,32);

    if(arduboy.justPressed(A_BUTTON))
    {
      gameState = 12;
    }
  }

  if (gameSelected == 3 && columnOfGames == 1)
  {
    arduboy.setCursor(74,48);

    if(arduboy.justPressed(A_BUTTON))
    {
      gameState = 15;
    }
  }

  arduboy.print(">");
}

static void pongtitle()
{
  Sprites::drawOverwrite(33, 8, logo, 0);

  arduboy.setCursor(22, 48);
  arduboy.print("  1 player"); 
  arduboy.setCursor(22, 56);
  arduboy.print("  2 players");

  if (arduboy.justPressed(DOWN_BUTTON))
  {
    gameSelected++;

    if (gameSelected > 2)
    {
      gameSelected = 2; 
    }
  }
  else if (arduboy.justPressed(UP_BUTTON) && gameSelected != 0)
  {
    gameSelected--;

    if (gameSelected < 1)
    {
      gameSelected = 1; 
    }
  }

  if (gameSelected == 1)
  {
    arduboy.setCursor(16, 48);

    if (arduboy.justPressed(A_BUTTON))
    {
      gameState = 4;
    }
  }

  if (gameSelected == 2)
  {
    arduboy.setCursor(16, 56);

    if (arduboy.justPressed(A_BUTTON))
    {
      gameState = 5;
    }
  }

  arduboy.print(">");
}

// static void pong1player()
// {
//   arduboy.setCursor(20, 0); //score
//   arduboy.print(playerOneScore);

//   arduboy.setCursor(101, 0);
//   arduboy.print(playerTwoScore);
  
//   arduboy.fillRect(hollowBallX, hollowBallY, hollowBallSize, hollowBallSize, WHITE); //draw the hollow ball
//   arduboy.fillRect(playerOneRacketX, playerOneRacketY, racketWidth, racketHeight, WHITE); //draw the player one racket
//   arduboy.fillRect(playerTwoRacketX, playerTwoRacketY, racketWidth, racketHeight, WHITE); //draw the player two racket

//   //Hollow Ball Rules
//   if(hollowBallRightSpeed == 1) 
//   {
//     hollowBallX += 1;
//   }
//   if(hollowBallRightSpeed == -1) 
//   {
//     hollowBallX -= 1;
//   }
   
//   if(hollowBallDownSpeed == 1) 
//   {
//     hollowBallY += 1;
//   }  
//   if(hollowBallDownSpeed == -1) 
//   {
//     hollowBallY -= 1;
//   }
      
//   if(hollowBallY == 0) 
//   {
//     hollowBallDownSpeed = 1;
//   }  
//   if (hollowBallY + 9/5 == 63) //9/5 - special value for bouncing 
//   {
//     hollowBallDownSpeed = -1;
//   }
  
//   if(hollowBallX == playerOneRacketX + racketWidth && playerOneRacketY < hollowBallY + hollowBallSize && playerOneRacketY + racketHeight > hollowBallY) 
//   {
//     hollowBallRightSpeed = 1;
//   }
   
//   if(hollowBallX + hollowBallSize == playerTwoRacketX && playerTwoRacketY < hollowBallY + hollowBallSize && playerTwoRacketY + racketHeight > hollowBallY) 
//   {
//     hollowBallRightSpeed = -1;
//   }

//   if(hollowBallX < -10) 
//   {
//     hollowBallX = 64;
//     playerTwoScore += 1;
//   }
//   if(hollowBallX > 130) 
//   {
//     hollowBallX = 64;
//     playerOneScore += 1;
//   }

//   //racket rules
//   if (arduboy.pressed(UP_BUTTON) && playerOneRacketY > 0) 
//   {
//     playerOneRacketY -= 1;
//   }
//   if (arduboy.pressed(DOWN_BUTTON) && playerOneRacketY + racketHeight < 63) 
//   {
//     playerOneRacketY += 1;
//   }

//   //AI
//   if(hollowBallY != random(0,15) && hollowBallY != random(0,15) && hollowBallY != random(0,15) && hollowBallY != random(22,37) && hollowBallY != random(22,37) && hollowBallY != random(22,37) && hollowBallY != random(50,65) && hollowBallY != random(50,165) && hollowBallY != random(50,65))
//   {
//     if(hollowBallY < playerTwoRacketY) 
//     {
//       playerTwoRacketY -= 1;
//     }
//   }
//   else
//   {
//     playerTwoRacketY += 2;
//   }
 
//   if(hollowBallY + hollowBallSize > playerTwoRacketY + racketHeight) 
//   {
//     playerTwoRacketY += 1;
//   }

//   //result 
//   if (playerOneScore == 11)
//   {
//     gameState = 18;
//   }
//   else if (playerTwoScore == 11)
//   {
//     gameState = 17;
//   }
// }

static void pong2players()
{
  arduboy.setCursor(20, 0); //score
  arduboy.print(playerOneScore);

  arduboy.setCursor(101, 0);
  arduboy.print(playerTwoScore);
  
  arduboy.fillRect(hollowBallX, hollowBallY, hollowBallSize, hollowBallSize, WHITE); //draw the hollow ball
  arduboy.fillRect(playerOneRacketX, playerOneRacketY, racketWidth, racketHeight, WHITE); //draw the player one racket
  arduboy.fillRect(playerTwoRacketX, playerTwoRacketY, racketWidth, racketHeight, WHITE); //draw the player two racket

  //Hollow Ball Rules
  if(hollowBallRightSpeed == 1) 
  {
    hollowBallX += 1;
  }
  if(hollowBallRightSpeed == -1) 
  {
    hollowBallX -= 1;
  }
   
  if(hollowBallDownSpeed == 1) 
  {
    hollowBallY += 1;
  }  
  if(hollowBallDownSpeed == -1) 
  {
    hollowBallY -= 1;
  }
      
  if(hollowBallY == 0) 
  {
    hollowBallDownSpeed = 1;
  }  
  if (hollowBallY + 9/5 == 63) //9/5 - special value for bouncing 
  {
    hollowBallDownSpeed = -1;
  }
  
  if(hollowBallX == playerOneRacketX + racketWidth && playerOneRacketY < hollowBallY + hollowBallSize && playerOneRacketY + racketHeight > hollowBallY) 
  {
    hollowBallRightSpeed = 1;
  }
   
  if(hollowBallX + hollowBallSize == playerTwoRacketX && playerTwoRacketY < hollowBallY + hollowBallSize && playerTwoRacketY + racketHeight > hollowBallY) 
  {
    hollowBallRightSpeed = -1;
  }

  if(hollowBallX < -10) 
  {
    hollowBallX = 64;
    playerTwoScore += 1;
  }
  if(hollowBallX > 130) 
  {
    hollowBallX = 64;
    playerOneScore += 1;
  }

  //racket rules
  if (arduboy.pressed(UP_BUTTON) && playerOneRacketY > 0) 
  {
    playerOneRacketY -= 1;
  }
  if (arduboy.pressed(DOWN_BUTTON) && playerOneRacketY + racketHeight < 63) 
  {
    playerOneRacketY += 1;
  }

  //second player
  if (arduboy.pressed(B_BUTTON) && playerTwoRacketY > 0) 
  {
    playerTwoRacketY -= 1;
  }
  else if (arduboy.pressed(A_BUTTON) && playerTwoRacketY + racketHeight < 63) 
  {
    playerTwoRacketY += 1;
  }

  if (playerOneScore == 11)
  {
    gameState = 19;
  }
  else if (playerTwoScore == 11)
  {
    gameState = 20;
  }
}

static void resetpong() 
{
  hollowBallX = 62;
  playerOneScore = 0;
  playerTwoScore = 0;
}

static void tennistitle()
{
  Sprites::drawOverwrite(33, 8, logo, 0);
  arduboy.setCursor(22, 55);
  arduboy.print("Press A to play");

  if (arduboy.justPressed(A_BUTTON)) 
  {
    gameState = 6;
  }    
}



static void tennis()
{
  arduboy.setCursor(20, 0); //score
  arduboy.print(playerOneScore);

  arduboy.setCursor(101, 0);
  arduboy.print(playerTwoScore);
  
  arduboy.fillRect(tennisBallX, tennisBallY, tennisBallSize, tennisBallSize, WHITE); //draw the hollow ball
  arduboy.fillRect(playerRacquetX, playerRacquetY, racquetWidth, racquetHeight, WHITE); //draw the player one racket
  arduboy.fillRect(computerRacquetX, computerRacquetY, racquetWidth, racquetHeight, WHITE); //draw the player two racket

  //Tennis Ball Rules
  if(tennisBallRightSpeed == 1) 
  {
    tennisBallX += 1;
  }
  if(hollowBallRightSpeed == -1) 
  {
    hollowBallX -= 1;
  }
   
  if(hollowBallDownSpeed == 1) 
  {
    hollowBallY += 1;
  }  
  if(hollowBallDownSpeed == -1) 
  {
    hollowBallY -= 1;
  }
      
  if(hollowBallY == 0) 
  {
    hollowBallDownSpeed = 1;
  }  
  if (hollowBallY + 9/5 == 63) //9/5 - special value for bouncing 
  {
    hollowBallDownSpeed = -1;
  }

  if(hollowBallX == playerOneRacketX + racketWidth && playerOneRacketY < hollowBallY + hollowBallSize && playerOneRacketY + racketHeight > hollowBallY) 
  {
    hollowBallRightSpeed = 1;
  }
   
  if(hollowBallX + hollowBallSize == playerTwoRacketX && playerTwoRacketY < hollowBallY + hollowBallSize && playerTwoRacketY + racketHeight > hollowBallY) 
  {
    hollowBallRightSpeed = -1;
  }

  if(hollowBallX < -10) 
  {
    hollowBallX = 64;
    playerTwoScore += 1;
  }
  if(hollowBallX > 130) 
  {
    hollowBallX = 64;
    playerOneScore += 1;
  }
}

void football()
{
  arduboy.print("11");
}

static void gameloop()
{

}

void setup() 
{
  arduboy.begin();

   arduboy.initRandomSeed();
   arduboy.setFrameRate(60);

   arduboy.clear();
}

void loop() 
{
  if (!arduboy.nextFrame()) 
  {
    return;
  }
  
  arduboy.clear();
  arduboy.pollButtons();

  switch(gameState)
  {
    case GAME_TITLE:
      titlescreen();
      arduboy.print(gameState);
      break;

    case 2:
    gameselectionscreen();
    // arduboy.setCursor(120, 55);
    // arduboy.print(gameState);
    break; 

    case 3:
    pongtitle();
    break;

    case 4:
    pong1player();
    break;

    case 5:
    pong2players();
    break;

    case 6:    
    break;

    case 7:    
    break;

    case 8:    
    break;

    case 9:
    break;

    case 10:
    pong2players();
    break;

    case 11:
    pong2players();
    break;

    case 12:
    pong2players();
    break;

    case 13:
    pong2players();
    break;

    case 14:
    pong2players();
    break;

    case 15:
    pong2players();
    break;

    case 16:
    pong2players();
    break;

    case 17:
    gameover();

    if (arduboy.justPressed(A_BUTTON)) 
    {
      resetpong();
      gameState = GAME_TITLE;
    }
    break;

    case 18:
    gamewin();

    if (arduboy.justPressed(A_BUTTON)) 
    {
      resetpong();
      gameState = GAME_TITLE;
    }
    break;

    case 19:
    playeronewon();

    if (arduboy.justPressed(A_BUTTON)) 
    {
      resetpong();
      gameState = GAME_TITLE;
    }
    break;

    case 20:
    playertwowon();

    if (arduboy.justPressed(A_BUTTON)) 
    {
      resetpong();
      gameState = GAME_TITLE;
    }
    break;

    case 21:
    pong2players();
    break;

    case 22:
    pong2players();
    break;



  }

  arduboy.display();
}