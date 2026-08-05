// =============================================================================
// Named_FIRST_TIME_LOAD_0_0095c5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095c5a0
// Address:   0x0095c5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_FIRST_TIME_LOAD_0_0095c5a0 @ 0x0095c5a0
// Stable ID: aa_0095c5a0
// Embedded strings (evidence for future rename):
//   - ");

// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×3, while×3.
//  - Notable callees: fprintf×118, Client_GetMissionCompleteAudioTable, FUN_007b6a20, FUN_0095c5a0, GetFileAttributesA, SetFileAttributesA, fclose, fopen.
//  - Strings: ");

  fprintf(_File,"; ",(uint)(*(char *)(unaff_EBX + 4) != '\0'));

  fprintf(_File,"; ",(uint)(*(char *)(unaff_EBX + 5) != '\0'));

  fprintf(_File,"; ",*(undefined4 *)(unaff_EBX + 0x5c));

  fprintf(_File,".
//  - Return sites: 3.

  if (_File == (FILE *)0x0) {

    return 0;

  }

  fprintf(_File,"
//   - ");

  fprintf(_File,"
//   - ",(uint)(*(char *)(unaff_EBX + 4) != '\0'));

  fprintf(_File,"
//   - ",(uint)(*(char *)(unaff_EBX + 5) != '\0'));

  fprintf(_File,"
//   - ",*(undefined4 *)(unaff_EBX + 0x5c));

  fprintf(_File,"
//   - ",*(undefined4 *)(unaff_EBX + 0x60));

  fprintf(_File,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * String-driven rename evidence: "FIRST_TIME_LOAD=0;
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_FIRST_TIME_LOAD_0_0095c5a0(void)



{

  char cVar1;

  char *in_EAX;

  char *pcVar2;

  DWORD DVar3;

  FILE *_File;

  int iVar4;

  int unaff_EBX;

  int local_118;

  CHAR local_110 [268];

  

  if (in_EAX == (char *)0x0) {

    pcVar2 = *(char **)(unaff_EBX + 0xe8);

    if (pcVar2 == (char *)0x0) {

      return 0;

    }

    iVar4 = -(int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_110 + iVar4)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  else {

    iVar4 = -(int)in_EAX;

    do {

      cVar1 = *in_EAX;

      in_EAX[(int)(local_110 + iVar4)] = cVar1;

      in_EAX = in_EAX + 1;

    } while (cVar1 != '\0');

  }

  DVar3 = GetFileAttributesA(local_110);

  if ((DVar3 != 0xffffffff) && ((DVar3 & 1) != 0)) {

    SetFileAttributesA(local_110,DVar3 & 0xfffffffe);

  }

  _File = fopen(local_110,"w");

  if (_File == (FILE *)0x0) {

    return 0;

  }

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"// Account Options\n");

  fprintf(_File,"USERNAME=%s;\n");

  fprintf(_File,"REMEMBER_USERNAME=%d;\n",(uint)(*(char *)(unaff_EBX + 4) != '\0'));

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"\n");

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"// Graphics Options\n");

  fprintf(_File,"MODE_WINDOWED=%d;\n",(uint)(*(char *)(unaff_EBX + 5) != '\0'));

  fprintf(_File,"DRAW_WINDOW_BORDER=%d;\n");

  fprintf(_File,"RESOLUTIONX=%d;\n",*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5c));

  fprintf(_File,"RESOLUTIONY=%d;\n",*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x60));

  fprintf(_File,"ALLOW_UI_SCALE=%d;\n",(uint)(*(char *)(unaff_EBX + 0x68) != '\0'));

  fprintf(_File,"UI_RESOLUTION_SCALE=%0.2f;\n",(double)*(float *)(unaff_EBX + 100));

  fprintf(_File,"GAMMA=%f;\n",(double)*(float *)(unaff_EBX + 0x6c));

  fprintf(_File,"SHADOW_MODE=%d;\n",DAT_00afa2dc);

  fprintf(_File,"SHADOW_DISTANCE=%f;\n",(double)DAT_00afa2e0);

  fprintf(_File,"LOD_BIAS=%f;\n",(double)DAT_00d1a540);

  fprintf(_File,"LOD_SCALAR=%f;\n",(double)DAT_00afa2ec);

  fprintf(_File,"LOAD_SPEC_GLOW=%d;\n",(uint)(*(char *)(unaff_EBX + 0x12) != '\0'));

  fprintf(_File,"BETTER_SHADOW_CULLING=%d;\n",(uint)(DAT_00aefa54 != '\0'));

  fprintf(_File,"ADVANCED_SHADERS=%d;\n",(uint)(*(char *)(unaff_EBX + 0x14) != '\0'));

  fprintf(_File,"TEXTURE_RESOLUTION=%d;\n",(uint)*(byte *)(unaff_EBX + 0x51));

  fprintf(_File,"MODE_ANTIALIASED=%d;\n");

  fprintf(_File,"TERRAIN_DRAW_DIST=%f;\n",(double)DAT_00b036ac);

  fprintf(_File,"PARTICLE_CULLING=%f;\n",(double)DAT_00af06e0);

  fprintf(_File,"BACKGROUND_LOADING=%d;\n",(uint)(DAT_00d1a8f2 != '\0'));

  fprintf(_File,"FLOATING_POINT_24BIT=%d;\n",(uint)(*(char *)(unaff_EBX + 0x19) != '\0'));

  fprintf(_File,"DRAW_FLAIR=%d;\n",(uint)(*(char *)(unaff_EBX + 0x22) != '\0'));

  FUN_007b6a20();

  fprintf(_File,"AGE_FLUSH_PRELOADER=%d;\n",(uint)(DAT_00d1793d != '\0'));

  fprintf(_File,"FIRST_TIME_LOAD=0;\n");

  fprintf(_File,"USE_FADING=%d;\n",(uint)(DAT_00aef950 != '\0'));

  fprintf(_File,"PHYSX_CARD_PRESENT=%d;\n",(uint)(DAT_00b036d8 != '\0'));

  fprintf(_File,"PHYSX_ENABLED_TMP=%d;\n",(uint)(DAT_00b036d9 != '\0'));

  fprintf(_File,"PHYSX_ALLOW_FLUID_TMP=%d;\n",(uint)(DAT_00af06e8 != '\0'));

  fprintf(_File,"PHYSX_ALLOW_DESTRUCTION_TMP=%d;\n",(uint)(DAT_00af06e9 != '\0'));

  fprintf(_File,"PHYSX_ALLOW_CLOTH_TMP=%d;\n");

  fprintf(_File,"PHYSX_LIQUID_PARTICLE_SCALE=%f;\n",(double)DAT_00aefa88);

  fprintf(_File,"PHYSX_DEBRIS_PARTICLE_SCALE=%f;\n",(double)DAT_00aefb3c);

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"\n");

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"// Audio Options\n");

  fprintf(_File,"USESOUND=%d;\n",(uint)(*(char *)(unaff_EBX + 0x2a) != '\0'));

  fprintf(_File,"USEMUSIC=%d;\n",(uint)(*(char *)(unaff_EBX + 0x2b) != '\0'));

  fprintf(_File,"USE3DBUFFERS=%d;\n");

  fprintf(_File,"SOUND_USE_SOFTWARE=%d;\n",(uint)(*(char *)(unaff_EBX + 0x2c) != '\0'));

  fprintf(_File,"SOUND_PERFORMANCE=%d;\n",(uint)(*(char *)(unaff_EBX + 0x2d) != '\0'));

  fprintf(_File,"SOUND_MUSIC=%d;\n",(int)(*(float *)(unaff_EBX + 0x30) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_MUSIC_ENVIRONMENT=%d;\n",(int)(*(float *)(unaff_EBX + 0x34) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_3DLOCAL=%d;\n",(int)(*(float *)(unaff_EBX + 0x38) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_3D=%d;\n");

  fprintf(_File,"SOUND_COLLISION=%d;\n",(int)(*(float *)(unaff_EBX + 0x40) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_2D=%d;\n",(int)(*(float *)(unaff_EBX + 0x44) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_CAR=%d;\n",(int)(*(float *)(unaff_EBX + 0x48) * DAT_00aaa7ac));

  fprintf(_File,"SOUND_ALL=%d;\n",(int)(*(float *)(unaff_EBX + 0x4c) * DAT_00aaa7ac));

  local_118 = 0x260;

  do {

    iVar4 = Client_GetMissionCompleteAudioTable();

    fprintf(_File,"SOUND_PRIORITY%02d=%d;\n",*(uint32_t /* width from decompiler */ *)(local_118 + iVar4));

    local_118 = local_118 + 4;

  } while (local_118 < 0x284);

  fprintf(_File,"NEVER_PLAY_SOUND_FOR_SUMMONS=%d;\n");

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"\n");

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"// Other Options\n");

  fprintf(_File,"USE_JOYSTICK=%d;\n",(uint)(*(char *)(unaff_EBX + 0x13) != '\0'));

  fprintf(_File,"WORD_FILTER=%d;\n",(uint)(*(char *)(unaff_EBX + 0x29) != '\0'));

  fprintf(_File,"ALL_WINDOWS_MOVEABLE=%d;\n");

  fprintf(_File,"DISTANCE_UNITS=%d;\n",(uint)*(byte *)(unaff_EBX + 0x53));

  fprintf(_File,"TARGET_SELF=%d;\n",(uint)(*(char *)(unaff_EBX + 9) != '\0'));

  fprintf(_File,"COMBAT_CURSOR=%d;\n",(uint)(*(char *)(unaff_EBX + 0x17) != '\0'));

  fprintf(_File,"SCREENSHOT_FORMAT=%d;\n",(uint)*(byte *)(unaff_EBX + 0x54));

  fprintf(_File,"NETWORK_TYPE=%d;\n",(uint)*(byte *)(unaff_EBX + 0x52));

  fprintf(_File,"MOUSE_SENSITIVITY=%0f;\n",(double)*(float *)(unaff_EBX + 0xdc));

  fprintf(_File,"USE_EXTENDED_ZOOM=%d;\n",(uint)(*(char *)(unaff_EBX + 0x70) != '\0'));

  fprintf(_File,"USE_SLOWER_CAMERA=%d;\n",(uint)(*(char *)(unaff_EBX + 0x71) != '\0'));

  fprintf(_File,"INVERT_MOUSE=%d;\n",(uint)(*(char *)(unaff_EBX + 0xf) != '\0'));

  fprintf(_File,"MOUSE_MOVE_IN_TOWN=%d;\n",(uint)(*(char *)(unaff_EBX + 0x25) != '\0'));

  fprintf(_File,"MOUSE_MOVE_IN_VEHICLE=%d;\n");

  fprintf(_File,"USE_VIBRATION=%d;\n",(uint)(*(char *)(unaff_EBX + 0x10) != '\0'));

  fprintf(_File,"CAMERA_SNAP_LOCK=%d;\n",(uint)(*(char *)(unaff_EBX + 0x15) != '\0'));

  fprintf(_File,"CAMERA_SNAPS_BEHIND_PLAYER=%d;\n",(uint)(*(char *)(unaff_EBX + 0x16) != '\0'));

  fprintf(_File,"CAMERA_EASIER_LOOK_UP=%d;\n",(uint)(*(char *)(unaff_EBX + 0x72) != '\0'));

  fprintf(_File,"SET_NEW_MISSION_ACTIVE=%d;\n",(uint)(*(char *)(unaff_EBX + 0x1a) != '\0'));

  fprintf(_File,"HIDE_WAYPOINTS_FOR_KILL=%d;\n");

  fprintf(_File,"AUTO_UPDATE_TARGET=%d;\n",(uint)(*(char *)(unaff_EBX + 0x1c) != '\0'));

  fprintf(_File,"AUTO_TARGET_ATTACKER=%d;\n",(uint)(*(char *)(unaff_EBX + 0x1d) != '\0'));

  fprintf(_File,"MOUSE_DRAGS_TOOLTIPS=%d;\n",(uint)(*(char *)(unaff_EBX + 0x1e) != '\0'));

  fprintf(_File,"PREFER_STRAFE_IN_TOWN=%d;\n",(uint)(*(char *)(unaff_EBX + 0x1f) != '\0'));

  fprintf(_File,"DIALOGUE_FADES_IN=%d;\n",(uint)(*(char *)(unaff_EBX + 0x20) != '\0'));

  fprintf(_File,"CHAT_FILTER=%d;\n");

  fprintf(_File,"CHAT_FILTER_SPECIALIZED=%d;\n",DAT_00af921c);

  fprintf(_File,"SUMMON_AI_STATE=%d;\n",(uint)*(byte *)(unaff_EBX + 0x55));

  fprintf(_File,"SUMMON_DISTANCE_MODE=%d;\n",(uint)*(byte *)(unaff_EBX + 0x56));

  fprintf(_File,"FULL_QUICKBAR_RED=%d;\n",(uint)(*(char *)(unaff_EBX + 0x27) != '\0'));

  fprintf(_File,"SHOW_STUNTS=%d;\n",(uint)(*(char *)(unaff_EBX + 0x28) != '\0'));

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"\n");

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fprintf(_File,"// Cinematic Camera Controls\n");

  fprintf(_File,"CINCAM_VELOCITY_FACTOR_X=%0f;\n",(double)*(float *)(unaff_EBX + 0x80));

  fprintf(_File,"CINCAM_VELOCITY_FACTOR_Y=%0f;\n",(double)*(float *)(unaff_EBX + 0x84));

  fprintf(_File,"CINCAM_VELOCITY_FACTOR_Z=%0f;\n",(double)*(float *)(unaff_EBX + 0x88));

  fprintf(_File,"\n");

  fprintf(_File,"CINCAM_VELOCITY_MAX_X=%0f;\n",(double)*(float *)(unaff_EBX + 0x8c));

  fprintf(_File,"CINCAM_VELOCITY_MAX_Y=%0f;\n",(double)*(float *)(unaff_EBX + 0x90));

  fprintf(_File,"CINCAM_VELOCITY_MAX_Z=%0f;\n",(double)*(float *)(unaff_EBX + 0x94));

  fprintf(_File,"\n");

  fprintf(_File,"CINCAM_ROTATION_FACTOR_X=%0f;\n",(double)*(float *)(unaff_EBX + 0xa4));

  fprintf(_File,"CINCAM_ROTATION_FACTOR_Y=%0f;\n",(double)*(float *)(unaff_EBX + 0xa8));

  fprintf(_File,"CINCAM_ROTATION_FACTOR_Z=%0f;\n",(double)*(float *)(unaff_EBX + 0xac));

  fprintf(_File,"\n");

  fprintf(_File,"CINCAM_ROTATION_MAX_X=%0f;\n",(double)*(float *)(unaff_EBX + 0xb0));

  fprintf(_File,"CINCAM_ROTATION_MAX_Y=%0f;\n",(double)*(float *)(unaff_EBX + 0xb4));

  fprintf(_File,"CINCAM_ROTATION_MAX_Z=%0f;\n",(double)*(float *)(unaff_EBX + 0xb8));

  fprintf(_File,"\n");

  fprintf(_File,"CINCAM_ZOOM_FACTOR=%0f;\n",(double)*(float *)(unaff_EBX + 0xcc));

  fprintf(_File,"CINCAM_ZOOM_MAX_VELOCITY=%0f;\n",(double)*(float *)(unaff_EBX + 0xd0));

  fprintf(_File,"CINCAM_ZOOM_MAX_VALUE=%0f;\n",(double)*(float *)(unaff_EBX + 0xd4));

  fprintf(_File,"CINCAM_ZOOM_MIN_VALUE=%0f;\n",(double)*(float *)(unaff_EBX + 0xd8));

  fprintf(_File,"///////////////////////////////////////////////////////////////////\n");

  fclose(_File);

  return 1;

}
