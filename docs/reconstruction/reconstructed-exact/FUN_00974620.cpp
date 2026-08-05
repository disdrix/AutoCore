// =============================================================================
// FUN_00974620
// -----------------------------------------------------------------------------
// Stable ID: aa_00974620
// Address:   0x00974620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974620 @ 0x00974620
// Stable ID: aa_00974620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, for×1, if×1, while×1.
//  - Notable callees: FUN_007833a0×2, FUN_00974470, FUN_00974620.
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

uint32_t /* width from decompiler */ FUN_00974620(uint *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  

  iVar3 = FUN_007833a0();

  uVar5 = *param_1;

  do {

    uVar1 = uVar5 + 50000;

    for (; uVar5 < uVar1; uVar5 = uVar5 + 1) {

      cVar2 = FUN_00974470(param_2,param_3);

      if (cVar2 != '\0') {

        *param_1 = uVar5;

        return 1;

      }

    }

    iVar4 = FUN_007833a0();

  } while ((uint)(iVar4 - iVar3) < 0x1f);

  *param_1 = uVar5;

  return 0;

}
