// =============================================================================
// FUN_006cb320
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb320
// Address:   0x006cb320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cb320 @ 0x006cb320
// Stable ID: aa_006cb320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006cb320×2.
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

void __thiscall FUN_006cb320(int param_1,int param_2,int param_3,int param_4)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  puVar1 = (uint *)(param_1 + 0x10c + param_2 * 4);

  *puVar1 = *puVar1 | *(uint *)(param_1 + 0x10c + param_3 * 4);

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x4d94)) {

    do {

      iVar2 = *(int *)(*(int *)(param_1 + 0x4d90) + 4 + iVar3 * 8);

      if (iVar2 == param_2) {

        FUN_006cb320(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4d90) + iVar3 * 8),iVar2,param_4 + 1);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x4d94));

  }

  return;

}
