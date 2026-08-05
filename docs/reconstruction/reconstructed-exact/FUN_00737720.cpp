// =============================================================================
// FUN_00737720
// -----------------------------------------------------------------------------
// Stable ID: aa_00737720
// Address:   0x00737720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00737720 @ 0x00737720
// Stable ID: aa_00737720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_007471c0×2, FUN_0043f4b0, FUN_00737720.
//  - Return sites: 2.

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



uint32_t /* width from decompiler */ FUN_00737720(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint16_t local_10;

  uint16_t local_e;

  uint8_t local_c;

  uint8_t local_b;

  uint8_t local_a;

  uint8_t local_9;

  uint16_t local_8;

  uint16_t local_6;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  iVar2 = 1;

  param_4 = 1;

  iVar3 = 1;

  if (0 < param_2) {

    piVar1 = (int *)(*(int *)(param_1 + 0xd4) + 4);

    do {

      if ((float)_DAT_00aaa608 < *(float *)(param_3 + iVar3 * 4)) {

        if (0x10 < *(int *)(param_1 + 0xb4) + iVar2 * 2) {

          *param_5 = iVar2;

          return 0;

        }

        if (*piVar1 != 0) {

          FUN_0043f4b0();

          iVar2 = param_4;

        }

        local_e = 0;

        local_b = 0;

        local_a = 0;

        local_3 = 0;

        local_c = 2;

        local_4 = 2;

        *(uint32_t /* width from decompiler */ *)(&DAT_00d0e168 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_3 + iVar3 * 4);

        local_10 = (uint16_t)iVar2;

        local_9 = (uint8_t)iVar2;

        local_6 = 0xc;

        local_2 = 3;

        local_8 = local_10;

        local_1 = local_9;

        FUN_007471c0(&local_10);

        FUN_007471c0(&local_8);

        iVar2 = iVar2 + 1;

        param_4 = iVar2;

      }

      iVar3 = iVar3 + 1;

      piVar1 = piVar1 + 2;

    } while (iVar3 <= param_2);

  }

  *param_5 = iVar2;

  return 1;

}
