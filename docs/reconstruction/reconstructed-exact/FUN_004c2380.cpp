// =============================================================================
// FUN_004c2380
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2380
// Address:   0x004c2380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2380 @ 0x004c2380
// Stable ID: aa_004c2380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004c22a0×2, FUN_004c2380.
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

uint32_t /* width from decompiler */ __thiscall

FUN_004c2380(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            ,int param_6,char param_7)



{

  int iVar1;

  int iVar2;

  

  iVar1 = FUN_004c22a0(param_2,param_3);

  iVar2 = FUN_004c22a0(param_4,param_5);

  if ((iVar1 != 0) && (iVar2 != 0)) {

    if ((((0 < param_6) && ((param_6 < 3 && (*(int *)(iVar2 + 0x24) < 3)))) || (param_7 != '\0')) &&

       ((1 < *(int *)(iVar1 + 0x24) || (param_7 != '\0')))) {

      *(int *)(iVar2 + 0x24) = param_6;

      if (param_6 == 3) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8) = param_4;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1dc) = param_5;

      }

      return 1;

    }

  }

  return 0;

}
