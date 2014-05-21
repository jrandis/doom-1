/* Emacs style mode select   -*- C++ -*- 
 *-----------------------------------------------------------------------------
 *
 * $Id: p_pspr.h,v 1.2 1999/10/12 13:00:57 cphipps Exp $
 *
 *  LxDoom, a Doom port for Linux/Unix
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *   and Colin Phipps
 *  
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  Sprite animation.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_PSPR__
#define __P_PSPR__

/* Basic data types.
 * Needs fixed point, and BAM angles. */

#include "m_fixed.h"
#include "tables.h"

/* Needs to include the precompiled sprite animation tables.
 *
 * Header generated by multigen utility.
 * This includes all the data for thing animation,
 * i.e. the Thing Atrributes table and the Frame Sequence table.
 */

#include "info.h"

struct player_s;
struct mobj_s;

#ifdef __GNUG__
#pragma interface
#endif

/*
 * Frame flags:
 * handles maximum brightness (torches, muzzle flare, light sources)
 */

#define FF_FULLBRIGHT   0x8000  /* flag in thing->frame */
#define FF_FRAMEMASK    0x7fff

/*
 * Overlay psprites are scaled shapes
 * drawn directly on the view screen,
 * coordinates are given for a 320*200 view screen.
 */

typedef enum
{
  ps_weapon,
  ps_flash,
  NUMPSPRITES
} psprnum_t;

typedef struct pspdef_s
{
  state_t *state;       /* a NULL state means not active */
  int     tics;
  fixed_t sx;
  fixed_t sy;
} pspdef_t;

extern int weapon_preferences[2][NUMWEAPONS+1];      /* killough 5/2/98 */
int P_WeaponPreferred(int w1, int w2);

weapontype_t P_SwitchWeapon(struct player_s *player);
boolean P_CheckAmmo(struct player_s *player);
void P_SetupPsprites(struct player_s *curplayer);
void P_MovePsprites(struct player_s *curplayer);
void P_DropWeapon(struct player_s *player);

void A_WeaponReady(struct player_s *player, pspdef_t *psp);
void A_ReFire(struct player_s *player, pspdef_t *psp);
void A_CheckReload(struct player_s *player, pspdef_t *psp);
void A_Lower(struct player_s *player, pspdef_t *psp);
void A_Raise(struct player_s *player, pspdef_t *psp);
void A_GunFlash(struct player_s *player, pspdef_t *psp);
void A_Punch(struct player_s *player, pspdef_t *psp);
void A_Saw(struct player_s *player, pspdef_t *psp);
void A_FireMissile(struct player_s *player, pspdef_t *psp);
void A_FireBFG(struct player_s *player, pspdef_t *psp);
void A_FirePlasma(struct player_s *player, pspdef_t *psp);
void A_FirePistol(struct player_s *player, pspdef_t *psp);
void A_FireShotgun(struct player_s *player, pspdef_t *psp);
void A_FireShotgun2(struct player_s *player, pspdef_t *psp);
void A_FireCGun(struct player_s *player, pspdef_t *psp);
void A_Light0(struct player_s *player, pspdef_t *psp);
void A_Light1 (struct player_s *player, pspdef_t *psp);
void A_Light2 (struct player_s *player, pspdef_t *psp);
void A_BFGSpray(struct mobj_s *mo);
void A_BFGsound(struct player_s *player, pspdef_t *psp);

#endif

/*----------------------------------------------------------------------------
 *
 * $Log: p_pspr.h,v $
 * Revision 1.2  1999/10/12 13:00:57  cphipps
 * Changed header to GPL, converted C++ comments to C
 *
 * Revision 1.1  1998/09/13 16:49:50  cphipps
 * Initial revision
 *
 * Revision 1.5  1998/05/03  22:54:44  killough
 * beautification, add external decls formerly in p_local.h
 *
 * Revision 1.4  1998/02/15  02:48:15  phares
 * User-defined keys
 *
 * Revision 1.3  1998/02/09  03:06:18  killough
 * Add player weapon preference options
 *
 * Revision 1.2  1998/01/26  19:27:25  phares
 * First rev with no ^Ms
 *
 * Revision 1.1.1.1  1998/01/19  14:03:09  rand
 * Lee's Jan 19 sources
 *
 *----------------------------------------------------------------------------*/
