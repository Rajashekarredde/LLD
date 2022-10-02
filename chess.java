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
         
            if( end.getPiece().isWhite() == this.isWhite() )
            {
                 return false;
            }
            
            int x = Math.abs( start.getX() - end.getY() );
            int y = Math.abs( start.getY() - end.getY() );
            int z = x * y;
            
            if( z == 2 &&  !end.getPiece()  )
            {
                  return true;
            }
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
             if( end.getPiece().isWhite() == this.isWhite() )
            {
                 return false;
            }
            
            int x = Math.abs( start.getX() - end.getY() );
            int y = Math.abs( start.getY() - end.getY() );
            int z = x + y;
            
            if( (z == 1 ) &&  !end.getPiece() && (start.getX() < end.getX() && start.getY() < end.getY() ) )
            {
                  return true;
            }  
              
            if( z == 2 && ( end.Piece().isWhite() != this.isWhite() ) )
            {
                  return true;
            }
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
            if( end.getPiece().isWhite() == this.isWhite() )
            {
                 return false;
            }
            
            int x = Math.abs( start.getX() - end.getY() );
            int y = Math.abs( start.getY() - end.getY() );
            
            if( x == y )
            {
                 if( no pieces between start and end position )
                    return true;
            }
            return false;
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
            if( end.getPiece().isWhite() == this.isWhite() )
            {
                 return false;
            }
            
            int x = Math.abs( start.getX() - end.getY() );
            int y = Math.abs( start.getY() - end.getY() );
            int z = x + y;
            
            if( (z == 1 || z == 2) && ( !end.getPiece() || end.Piece().isWhite() != this.isWhite() ) )
            {
                  return true;
            }
      }
}

public class Box
{
    private int x;
    private int y;
    private Piece _currentPiece;
    public Box(int _x, int _y, Piece piece )
    {
       this.setX(_x);
       this.setY(_y);
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

public class player
{  
   private Person person;
   boolean whiteSide = false;
   public Player( Person _person, boolean _whiteSide )
   {
        this.person = _person;
        this.whiteSide = _whiteSide;
   }
}


public class Game
{
   private Player[] players;
   private Board board;
   private Player _currentTurn;
   private GameStatus status;
   
   public void initialize( Player p1, Player p2 )
   {
        players[0] = p1;
        players[1] = p2;
        board.initializeBoard();
   }
   
   if( p1.isWhiteSide() == true )
         _currentTurn = p1;
   else
         _currentTuren = p2;
   
   public boolean PlayerMove( Player player, int startX, int startY, int endX, int endY )
   {
      Box start = board[startX][startY];
      Box end = board[endX][endY];
      Piece sourcePiece = start.getPiece();
      boolean isMove = sourcePiece.canMove( board, start, end );
      
      Piece destPiece = end.getPiece();
      if( isMove && destPiece )
      {
         destPiece.setKilled = true;
      }
      else
         end.setPiece( sourcePiece );
      
      _currentTurn = _currentTurn == p1 ? p2 : p1;
   }
}

