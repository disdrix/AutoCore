// =============================================================================
// FUN_006e58d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e58d0
// Address:   0x006e58d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e58d0 @ 0x006e58d0
// Stable ID: aa_006e58d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006e58d0.
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

void __fastcall FUN_006e58d0(uint32_t /* width from decompiler */ *param_1)



{

  short sVar1;

  int iVar2;

  

  if ((param_1[2] != 0) && (iVar2 = 0, 0 < (int)param_1[4])) {

    do {

      sVar1 = *(short *)(param_1[3] + iVar2 * 2);

      if (sVar1 != -1) {

        (**(code **)(*(int *)param_1[2] + 8))(sVar1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_1[4]);

  }

  (**(code **)*param_1)(1);

  return;

}
