// =============================================================================
// FUN_00809260
// -----------------------------------------------------------------------------
// Stable ID: aa_00809260
// Address:   0x00809260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00809260 @ 0x00809260
// Stable ID: aa_00809260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007fd930, FUN_00809260.
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

void __fastcall FUN_00809260(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint *puVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int in_EAX;

  

  iVar4 = *(int *)(in_EAX + 0xe98);

  uVar5 = *(uint *)(param_2 + 0x10);

  puVar1 = (uint *)(iVar4 + 0x728);

  uVar3 = *puVar1;

  *puVar1 = *puVar1 - uVar5;

  piVar2 = (int *)(iVar4 + 0x72c);

  *piVar2 = (*piVar2 - *(int *)(param_2 + 0x14)) - (uint)(uVar3 < uVar5);

  if (*(char *)(param_2 + 0x18) != '\0') {

    *(uint8_t *)(*(int *)(in_EAX + 0xe98) + 0x4fc) = 0;

    FUN_007fd930();

    return;

  }

  return;

}
