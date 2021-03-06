#ifndef GAMELOGIC_H
#define GAMELOGIC_H

/******************************
* Klasse f�r die Spiele-Logik
* Autor: Sven Gebhard
* Start: 4.3.17
*/

#include<efi.h>
#include<efilib.h>

#include"Shapes.h"

#define BALL_MOVE_SPEED_X 10
#define BALL_MOVE_SPEED_Y 10

/////////////
// Collider werden dazu verwendet, um zu pr�fen ob sich der Ball an der Decke oder 
// dem Boden des Spielfelds befindet oder um zu pr�fen ob ein Spieler den Ball
// durchgelassen hat
//
struct Bound topCollider, bottomCollider, leftCollider, rightCollider;

/////////////
// Aktuell erzielte Scores der beiden Spieler
UINTN p1_score, p2_score;

//////////////////
// -- setupGame --
// Setup-Methode des Spiels
//
void setupGame(struct Shape *background);

///////////////////////
// -- setupColliders --
// Methode die die Werte der Collider setzt
//
void setupCollider(struct Shape *background);

//////////////////////
// -- manageBallCol --
// Methode die die Kollision des Balls abf�ngt und dessen Bewegungsvektor neu setzt
//
void manageBallCol(struct Shape *ball, struct Shape *background, struct Shape *pad_1, struct Shape *pad_2, struct Vector *ballMovVec);

////////////////////////
// -- managePaddleCol --
// Methode die die Kollision des Balls mit einem Paddle abf�ngt und dessen Bewegungs-
// vektor neu setzt
// @param xdir: -1 = left
//		  ydir:  1 = right
//
BOOLEAN managePaddleCol(struct Shape *pad, struct Shape *ball, struct Vector *ballMovVec, UINTN xdir);

//////////////////
// -- resetBall --
// Methode setzt den Ball auf die Anfangsposition zur�ck
//
void resetBall(struct Shape background, struct Shape *ball, struct Vector *moveVec);

#endif