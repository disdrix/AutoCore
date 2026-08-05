// =============================================================================
// FUN_0078cf30
// -----------------------------------------------------------------------------
// Stable ID: aa_0078cf30
// Address:   0x0078cf30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078cf30 @ 0x0078cf30
// Stable ID: aa_0078cf30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0078cf30.
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

void __thiscall FUN_0078cf30(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  piVar1 = (int *)(**(code **)(*param_1 + 0x480))(param_2);

  if (piVar1 != (int *)0x0) {

    iVar2 = (**(code **)(*piVar1 + 0x78))();

    param_1[0x24a] = iVar2;

    if ((int *)param_1[0x24c] != (int *)0x0) {

      iVar2 = *(int *)param_1[0x24c];

      uVar3 = (**(code **)(*piVar1 + 0x1dc))();

      (**(code **)(iVar2 + 0x3ac))(uVar3);

      (**(code **)(*(int *)param_1[0x24c] + 0x34c))();

    }

    if ((int *)param_1[0xac] != (int *)0x0) {

      iVar2 = *(int *)param_1[0xac];

      uVar3 = (**(code **)(*param_1 + 0x78))();

      (**(code **)(iVar2 + 0x338))(0x1a,uVar3);

    }

  }

  return;

}
