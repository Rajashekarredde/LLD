Entities

-> box
-> player
-> pieces
-> board
-> game

public abstract class piece
{
   private boolean killed = false;
   private boolean white = false;
  
   public piece( boolean _white )
   {
      this.setWhite(_white);
   }

   public boolean isWhite( )
   {
     return this.white == true;
   }
   
   public setWhite( boolean _white )
   {
      this.white = _white;
   }
    
   public boolean isKilled()
   {
       return this.killed == true;
   }
   
   public setKilled( boolean _killed )
   {
      this.killed = _killed;
   }
   
   public abstract class boolean canMove(Board board, Box start, Box end );
}

public class knight extends piece
{
      public knight( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}

public class rook extends piece
{
      public rook( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}

public class queen extends piece
{
      public queen( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}

public class pawn extends piece
{
      public pawn( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}


public class bishop extends piece
{
      public bishop( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}

public class king extends piece
{
      public king( boolean _white )
      {
          super(_white);
      }
      
      public class boolean canMove(Board board, Box start, Box end )
      {
      
      }
}

public class Box
{
    private int x;
    private int y;
    private Piece _currentPiece;
    public Box(int _x, int _y, Piece piece )
    {
       this.x = _x;
       this.y = _y;
       this.setPiece(piece);
    }
}

public class Board
{ 
    Box [][]boxes;
    public Board()
    {
        this.initializeBoard();
    }
    
    public void initializeBoard()
    {
        boxes[0][0] = new Box( 0, 0, new Rook(true) );
        boxes[0][1] = new Box( 0, 1, new Knight(true) );
      
        boxes[2][0] = new Box( 2, 0, nullptr) );
    }
}

