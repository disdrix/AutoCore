// =============================================================================
// FUN_0066d490
// -----------------------------------------------------------------------------
// Stable ID: aa_0066d490
// Address:   0x0066d490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066d490 @ 0x0066d490
// Stable ID: aa_0066d490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_0066d490.
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

void __thiscall FUN_0066d490(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x20);

  if ((int)(param_2[2] & 0x7fffffffU) < iVar1) {

    iVar2 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar2 <= iVar1) {

      iVar2 = iVar1;

    }

    FUN_005b3300(param_2,iVar2,4);

  }

  param_2[1] = iVar1;

  if ((int)(param_2[5] & 0x7fffffffU) < iVar1) {

    iVar2 = (param_2[5] & 0x7fffffffU) * 2;

    if (iVar2 <= iVar1) {

      iVar2 = iVar1;

    }

    FUN_005b3300(param_2 + 3,iVar2,4);

  }

  iVar2 = 0;

  param_2[4] = iVar1;

  if (0 < iVar1) {

    do {

      *(uint32_t /* width from decompiler */ *)(*param_2 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + iVar2 * 8);

      *(uint32_t /* width from decompiler */ *)(param_2[3] + iVar2 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 4 + iVar2 * 8);

      iVar2 = iVar2 + 1;

    } while (iVar2 < iVar1);

  }

  return;

}
