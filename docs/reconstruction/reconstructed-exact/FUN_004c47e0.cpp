// =============================================================================
// FUN_004c47e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c47e0
// Address:   0x004c47e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c47e0 @ 0x004c47e0
// Stable ID: aa_004c47e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004c47e0, FUN_005d4c20.
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

void __fastcall FUN_004c47e0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  if (((*(int *)(param_1 + -0x4f8) == 0) && (iVar3 = *(int *)(param_1 + -0x2b0), iVar3 != 0)) &&

     (*(int *)(iVar3 + 8) != 0)) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x144))();

    puVar1 = (uint32_t /* width from decompiler */ *)

             (*(int *)(*(int *)(*(int *)(param_1 + -0x2b0) + 4) + 4) + 0x84 +

             *(int *)(param_1 + -0x2b0));

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x47c + param_1);

    *puVar2 = *puVar1;

    puVar2[1] = puVar1[1];

    puVar2[2] = puVar1[2];

    puVar2[3] = puVar1[3];

    return;

  }

  FUN_005d4c20();

  return;

}
