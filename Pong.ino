static void pong1player()
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

  //AI
  if(hollowBallY != random(0,15) && hollowBallY != random(0,15) && hollowBallY != random(0,15) && hollowBallY != random(22,37) && hollowBallY != random(22,37) && hollowBallY != random(22,37) && hollowBallY != random(50,65) && hollowBallY != random(50,165) && hollowBallY != random(50,65))
  {
    if(hollowBallY < playerTwoRacketY) 
    {
      playerTwoRacketY -= 1;
    }
  }
  else
  {
    playerTwoRacketY += 2;
  }
 
  if(hollowBallY + hollowBallSize > playerTwoRacketY + racketHeight) 
  {
    playerTwoRacketY += 1;
  }

  //result 
  if (playerOneScore == 11)
  {
    gameState = 18;
  }
  else if (playerTwoScore == 11)
  {
    gameState = 17;
  }
}