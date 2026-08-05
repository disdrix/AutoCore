// =============================================================================
// FUN_007449f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007449f0
// Address:   0x007449f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007449f0 @ 0x007449f0
// Stable ID: aa_007449f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00426f60, FUN_0044d960, FUN_0044dc00, FUN_007449f0.
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

uint32_t /* width from decompiler */ FUN_007449f0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  FUN_00426f60();

  piVar4 = (int *)FUN_0044d960();

  iVar1 = *piVar4;

  iVar2 = piVar4[1];

  if (iVar1 != iVar2) {

    iVar3 = *param_2;

    do {

      if (*(int *)(iVar1 + 0x18) == iVar3) {

        return 1;

      }

      FUN_0044dc00();

    } while (iVar1 != iVar2);

  }

  return 0;

}
