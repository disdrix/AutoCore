// =============================================================================
// FUN_0048eba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048eba0
// Address:   0x0048eba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048eba0 @ 0x0048eba0
// Stable ID: aa_0048eba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0048eba0, FUN_00756790.
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

void __fastcall FUN_0048eba0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int local_4;

  

  local_4 = param_1;

  iVar2 = FUN_00756790(1);

  puVar1 = DAT_00d1f044;

  if (((iVar2 != 0) && (DAT_00b04db8 != 0)) && (*(int *)(DAT_00b04db8 + 0x14) != 0)) {

    (**(code **)(*(int *)*DAT_00d1f044 + 0x88))

              ((int *)*DAT_00d1f044,*(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00b04db8 + 0x14) + 0x14),0,

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xdc) + 0x14),0,2);

    return;

  }

  iVar2 = 0;

  local_4 = 0;

  (**(code **)(*(int *)*DAT_00d1f044 + 0x48))((int *)*DAT_00d1f044,0,0,0,&local_4);

  if (iVar2 != 0) {

    piVar3 = (int *)0x0;

    (**(code **)(*(int *)*puVar1 + 0x88))

              ((int *)*puVar1,iVar2,0,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xdc) + 0x14),0,2);

    (**(code **)(*piVar3 + 8))(piVar3);

  }

  return;

}
