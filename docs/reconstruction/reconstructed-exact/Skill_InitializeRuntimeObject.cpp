// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_00418820, Skill_InitializeRuntimeObject, Skill_ReevaluateForCurrentRank.
//  - Return sites: 1.

// =============================================================================
// Skill_InitializeRuntimeObject
// -----------------------------------------------------------------------------
// Stable ID: aa_00553710
// Address:   0x00553710  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Skill_InitializeRuntimeObject(...)

   

   Fills skill runtime from template args: id +0x5fc, category +0x5e8, flags +0x614.

   Clears casting. If flags byte+0x615 bit1 set → +0x61c=1 (defer cast-again start).

   

   INFERRED: full parameter list from many ctor args. */



void * __thiscall

Skill_InitializeRuntimeObject

          (void *param_1,uint8_t param_2,uint8_t param_3,uint8_t param_4,uint8_t param_5

          ,uint8_t param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9,

          uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,uint32_t /* width from decompiler */ param_13,

          uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint8_t param_16,uint32_t /* width from decompiler */ param_17,

          uint32_t /* width from decompiler */ param_18,char *param_19,char *param_20,char *param_21,uint32_t /* width from decompiler */ param_22,

          uint32_t /* width from decompiler */ param_23,uint32_t /* width from decompiler */ param_24)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x17c) = param_14;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5e8) = param_17;

  *(uint8_t *)((int)param_1 + 0x5f8) = param_2;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x180) = param_13;

  *(uint8_t *)((int)param_1 + 0x5e7) = param_16;

  *(uint8_t *)((int)param_1 + 0x5fb) = param_5;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5ec) = param_18;

  *(uint8_t *)((int)param_1 + 0x5f4) = param_6;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x610) = param_11;

  *(uint8_t *)((int)param_1 + 0x5f9) = param_3;

  *(uint8_t *)((int)param_1 + 0x5fa) = param_4;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x620) = param_12;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5fc) = param_7;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x60c) = param_10;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x170) = 0;

  *(uint16_t *)((int)param_1 + 0x174) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x178) = 0;

  *(uint16_t *)((int)param_1 + 0x5f6) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x614) = param_8;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x618) = param_9;

  *(uint8_t *)((int)param_1 + 0x61c) = 0;

  *(uint8_t *)((int)param_1 + 0x628) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x62c) = param_15;

  uVar3 = FUN_00418820(param_15);

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x5f0) = uVar3;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x604) = param_23;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x608) = param_24;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x600) = param_22;

  iVar2 = 0x184 - (int)param_19;

  do {

    cVar1 = *param_19;

    param_19[(int)param_1 + iVar2] = cVar1;

    param_19 = param_19 + 1;

  } while (cVar1 != '\0');

  iVar2 = 0x1a5 - (int)param_20;

  do {

    cVar1 = *param_20;

    param_20[(int)param_1 + iVar2] = cVar1;

    param_20 = param_20 + 1;

  } while (cVar1 != '\0');

  if (param_21 == (char *)0x0) {

    *(uint8_t *)((int)param_1 + 0x5a6) = 0;

  }

  else {

    iVar2 = 0x5a6 - (int)param_21;

    do {

      cVar1 = *param_21;

      param_21[(int)param_1 + iVar2] = cVar1;

      param_21 = param_21 + 1;

    } while (cVar1 != '\0');

  }

  Skill_ReevaluateForCurrentRank(param_1);

  if ((*(byte *)((int)param_1 + 0x615) & 2) != 0) {

    *(uint8_t *)((int)param_1 + 0x61c) = 1;

  }

  return param_1;

}
