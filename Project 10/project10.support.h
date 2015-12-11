
/***********************************************************************/ 
/*  Declarations for Project #10                                       */
/***********************************************************************/ 


struct player
{
  unsigned short number;    /* player's jersey number (key) */
  char name[24];            /* player's name                */
  unsigned short games;     /* number of games played       */
  unsigned short goals;     /* number of goals scored       */
  unsigned short assists;   /* number of assists scored     */
  unsigned short points;    /* points (goals + assists)     */
  float points_per_game;    /* points per game played       */
};


struct table
{
  unsigned short capacity;  /* number of elements in table  */
  unsigned short count;     /* number of players in table   */
  struct player* memory;    /* pointer to array of players  */
};


/***********************************************************************/
/*  Function:  view                                                    */
/*                                                                     */
/*  Purpose:  display all information about one player, if the         */
/*  player is present in the table.                                    */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of players                                      */
/*    jersey number of player to be displayed                          */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if player displayed, 0 (false) otherwise                */
/***********************************************************************/

int view( struct table*, unsigned long );


/***********************************************************************/
/*  Function:  search                                                  */
/*                                                                     */
/*  Purpose:  locate and return a pointer to a player, if the          */
/*  player is present in the table.                                    */
/*                                                                     */
/*  Arguments:                                                         */
/*    pointer to table of players                                      */
/*    jersey number of player to be located                            */
/*    pointer to pointer to player                                     */
/*                                                                     */
/*  Return value:                                                      */
/*    1 (true) if player located, 0 (false) otherwise                  */
/***********************************************************************/
 
int search( struct table*, unsigned long, struct player** );

