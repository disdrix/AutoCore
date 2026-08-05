// =============================================================================
// FUN_0062aae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062aae0
// Address:   0x0062aae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062aae0 @ 0x0062aae0
// Stable ID: aa_0062aae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00600100×2, FUN_0062a650, FUN_0062aae0.
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

void __thiscall

FUN_0062aae0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  ushort uVar4;

  int local_14;

  int local_10;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  

  piVar1 = (int *)(param_1 + 0x14);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 == 0) {

    iVar2 = *(int *)(param_3 + 0x20);

    iVar3 = *(int *)(param_2 + 0x20);

    uVar4 = *(ushort *)(iVar2 + 0x5c);

    if (*(ushort *)(iVar3 + 0x5c) < *(ushort *)(iVar2 + 0x5c)) {

      uVar4 = *(ushort *)(iVar3 + 0x5c);

    }

    *(uint *)(param_1 + 0x14) = uVar4 + 1;

    local_10 = param_2;

    local_c = param_3;

    local_8 = param_5;

    local_14 = param_1;

    FUN_0062a650(*(uint32_t /* width from decompiler */ *)(param_1 + 8),&local_14);

    if (*(int *)(iVar3 + 100) != 0) {

      FUN_00600100(iVar3,&local_14);

    }

    if (*(int *)(iVar2 + 100) != 0) {

      FUN_00600100(iVar2,&local_14);

    }

  }

  return;

}
