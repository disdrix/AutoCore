// =============================================================================
// FUN_006f8e00
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8e00
// Address:   0x006f8e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8e00 @ 0x006f8e00
// Stable ID: aa_006f8e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_006f8640, FUN_006f88a0, FUN_006f8c00, FUN_006f8e00.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall

FUN_006f8e00(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint16_t param_4,ushort param_5,

            float param_6)



{

  int iVar1;

  char *pcVar2;

  ushort *puVar3;

  uint8_t local_61;

  uint32_t /* width from decompiler */ local_60;

  ushort *local_5c;

  ushort local_58;

  ushort uStack_56;

  uint16_t local_54;

  uint8_t local_50 [52];

  float local_1c;

  

  local_5c = &DAT_00a0eff0;

  local_60 = param_1;

  do {

    if ((*local_5c & param_5) == 0) {

      local_58 = (ushort)param_3;

      local_54 = param_4;

      uStack_56 = param_3._2_2_ ^ *local_5c | param_3._2_2_ & 0xff0f;

      iVar1 = *(int *)(param_2 + 0x54) + -1;

      if (-1 < iVar1) {

        puVar3 = (ushort *)(param_2 + 0x22 + iVar1 * 6);

        do {

          if ((puVar3[-1] == (ushort)param_3) && (*puVar3 == uStack_56)) goto LAB_006f8ed2;

          iVar1 = iVar1 + -1;

          puVar3 = puVar3 + -3;

        } while (-1 < iVar1);

      }

      FUN_006f8640(local_50,&local_58);

      pcVar2 = (char *)FUN_006f8c00(&local_61,local_50);

      if ((*pcVar2 != '\0') &&

         (param_6 - _DAT_00a0f000 < local_1c != (param_6 - _DAT_00a0f000 == local_1c))) {

        FUN_006f88a0(param_2,local_50,&local_58);

      }

    }

LAB_006f8ed2:

    local_5c = local_5c + 1;

    if (0xa0effd < (int)local_5c) {

      return;

    }

  } while( true );

}
