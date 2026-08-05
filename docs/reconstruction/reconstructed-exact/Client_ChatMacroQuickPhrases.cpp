// READABILITY (auto CF):
//  - Body size: ~581 non-empty decompiler lines.
//  - Control keywords: if×74, do×50, while×50, for×1, return×1.
//  - Notable callees: FUN_007a6de0×24, FUN_0082ad00×12, FUN_0082ad70×12, FUN_007a69d0, FUN_008b96d0.
//  - Strings: "ClDn?"; "Attack!"; "Ready!"; "I need repair!".
//  - Return sites: 1.

// =============================================================================
// Client_ChatMacroQuickPhrases
// -----------------------------------------------------------------------------
// Purpose:  Client chat macro / quick-phrase UI strings including combat calls ('I need cooldown!', 'I need power!', 'I need repair!', 'Attack!', 'Ready!') and convoy/search phrases.
//
// Address:  0x008b96d0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008b96d0
// System:   skills-abilities
//
// Evidence strings (from raw decompile):
//   - "I need cooldown!"
//   - "I need power!"
//   - "I need repair!"
//   - "Attack!"
//   - "Ready!"
//   - "Looking for Convoy!"
//   - "/cheer"
//
// Notable callees:
//   - FUN_007a69d0 / FUN_007a6de0
//   - FUN_0082ad00 / FUN_0082ad70
//   - operator_new__ / operator_delete__
//
// Notes:    Skill-adjacent via cooldown callout; social/combat UI.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void Client_ChatMacroQuickPhrases(int param_1)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  

  puVar5 = &DAT_00d177c8;

  puVar4 = &DAT_00d17788;

  do {

    if ((void *)*puVar4 != (void *)0x0) {

      operator_delete__((void *)*puVar4);

    }

    *puVar4 = 0;

    iVar6 = 5;

    do {

      if ((void *)*puVar5 != (void *)0x0) {

        operator_delete__((void *)*puVar5);

      }

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

    puVar4 = puVar4 + 1;

  } while ((int)puVar4 < 0xd177c4);

  FUN_007a69d0();

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f40,0xffffffff);

  if (*(int *)(param_1 + 0x568) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d17788 != (void *)0x0) {

    operator_delete__(DAT_00d17788);

  }

  DAT_00d17788 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17788 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f38,0xffffffff);

  if (*(int *)(param_1 + 0x56c) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d1778c != (void *)0x0) {

    operator_delete__(DAT_00d1778c);

  }

  DAT_00d1778c = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d1778c = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f30,0xffffffff);

  if (*(int *)(param_1 + 0x570) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d17790 != (void *)0x0) {

    operator_delete__(DAT_00d17790);

  }

  DAT_00d17790 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17790 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f2c,0xffffffff);

  if (*(int *)(param_1 + 0x574) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d17794 != (void *)0x0) {

    operator_delete__(DAT_00d17794);

  }

  DAT_00d17794 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17794 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f24,0xffffffff);

  if (*(int *)(param_1 + 0x578) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d17798 != (void *)0x0) {

    operator_delete__(DAT_00d17798);

  }

  DAT_00d17798 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17798 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("ClDn?",0xffffffff);

  if (*(int *)(param_1 + 0x57c) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d1779c != (void *)0x0) {

    operator_delete__(DAT_00d1779c);

  }

  DAT_00d1779c = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d1779c = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f14,0xffffffff);

  if (*(int *)(param_1 + 0x580) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177a0 != (void *)0x0) {

    operator_delete__(DAT_00d177a0);

  }

  DAT_00d177a0 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177a0 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f10,0xffffffff);

  if (*(int *)(param_1 + 0x584) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177a4 != (void *)0x0) {

    operator_delete__(DAT_00d177a4);

  }

  DAT_00d177a4 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177a4 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f0c,0xffffffff);

  if (*(int *)(param_1 + 0x588) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177a8 != (void *)0x0) {

    operator_delete__(DAT_00d177a8);

  }

  DAT_00d177a8 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177a8 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f04,0xffffffff);

  if (*(int *)(param_1 + 0x58c) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177ac != (void *)0x0) {

    operator_delete__(DAT_00d177ac);

  }

  DAT_00d177ac = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177ac = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46efc,0xffffffff);

  if (*(int *)(param_1 + 0x590) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177b0 != (void *)0x0) {

    operator_delete__(DAT_00d177b0);

  }

  DAT_00d177b0 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177b0 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46ef4,0xffffffff);

  if (*(int *)(param_1 + 0x594) != 0) {

    FUN_0082ad00();

  }

  if (DAT_00d177b4 != (void *)0x0) {

    operator_delete__(DAT_00d177b4);

  }

  DAT_00d177b4 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177b4 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("Attack!",0xffffffff);

  if (*(int *)(param_1 + 0x568) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d177c8 != (void *)0x0) {

    operator_delete__(DAT_00d177c8);

  }

  DAT_00d177c8 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177c8 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f38,0xffffffff);

  if (*(int *)(param_1 + 0x56c) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d177dc != (void *)0x0) {

    operator_delete__(DAT_00d177dc);

  }

  DAT_00d177dc = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177dc = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("Ready!",0xffffffff);

  if (*(int *)(param_1 + 0x570) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d177f0 != (void *)0x0) {

    operator_delete__(DAT_00d177f0);

  }

  DAT_00d177f0 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d177f0 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("I need repair!",0xffffffff);

  if (*(int *)(param_1 + 0x574) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17804 != (void *)0x0) {

    operator_delete__(DAT_00d17804);

  }

  DAT_00d17804 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17804 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("I need power!",0xffffffff);

  if (*(int *)(param_1 + 0x578) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17818 != (void *)0x0) {

    operator_delete__(DAT_00d17818);

  }

  DAT_00d17818 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17818 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("I need cooldown!",0xffffffff);

  if (*(int *)(param_1 + 0x57c) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d1782c != (void *)0x0) {

    operator_delete__(DAT_00d1782c);

  }

  DAT_00d1782c = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d1782c = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f14,0xffffffff);

  if (*(int *)(param_1 + 0x580) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17840 != (void *)0x0) {

    operator_delete__(DAT_00d17840);

  }

  DAT_00d17840 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17840 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46f10,0xffffffff);

  if (*(int *)(param_1 + 0x584) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17854 != (void *)0x0) {

    operator_delete__(DAT_00d17854);

  }

  DAT_00d17854 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17854 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("Looking for Convoy!",0xffffffff);

  if (*(int *)(param_1 + 0x588) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17868 != (void *)0x0) {

    operator_delete__(DAT_00d17868);

  }

  DAT_00d17868 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17868 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0("/cheer",0xffffffff);

  if (*(int *)(param_1 + 0x58c) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d1787c != (void *)0x0) {

    operator_delete__(DAT_00d1787c);

  }

  DAT_00d1787c = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d1787c = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46e8c,0xffffffff);

  if (*(int *)(param_1 + 0x590) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d17890 != (void *)0x0) {

    operator_delete__(DAT_00d17890);

  }

  DAT_00d17890 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d17890 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  pcVar2 = (char *)FUN_007a6de0(&DAT_00a46e84,0xffffffff);

  if (*(int *)(param_1 + 0x594) != 0) {

    FUN_0082ad70();

  }

  if (DAT_00d178a4 != (void *)0x0) {

    operator_delete__(DAT_00d178a4);

  }

  DAT_00d178a4 = (char *)0x0;

  if (pcVar2 != (char *)0x0) {

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(pcVar2 + 1))));

    DAT_00d178a4 = pcVar3;

    do {

      cVar1 = *pcVar2;

      *pcVar3 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
