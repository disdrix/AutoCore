// =============================================================================
// FUN_005af890
// -----------------------------------------------------------------------------
// Stable ID: aa_005af890
// Address:   0x005af890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005af890 @ 0x005af890
// Stable ID: aa_005af890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_005af890, FUN_00793aa0, FUN_0079cde0, FUN_0079d010.
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

void FUN_005af890(int *param_1,int param_2)



{

  void *pvVar1;

  

  if (*(char *)((int)param_1 + 5) == '\0') {

    (**(code **)(*param_1 + 8))(param_2 + 0x44,4);

  }

  else {

    (**(code **)(*param_1 + 4))();

  }

  if (*(char *)((int)param_1 + 5) == '\0') {

    (**(code **)(*param_1 + 8))(param_2 + 0x40,1);

  }

  else {

    (**(code **)(*param_1 + 4))();

  }

  if (*(char *)((int)param_1 + 5) == '\0') {

    (**(code **)(*param_1 + 8))(param_2 + 0x48,4);

  }

  else {

    (**(code **)(*param_1 + 4))();

  }

  if (*(char *)((int)param_1 + 5) == '\0') {

    (**(code **)(*param_1 + 8))(param_2 + 0x4c,4);

  }

  else {

    (**(code **)(*param_1 + 4))();

  }

  if ((param_1[0x1a3] == 0) || ((uint)param_1[param_1[0x1a3] + 2] < 0x2e)) {

    if (*(char *)((int)param_1 + 5) != '\0') {

      *(uint8_t *)(param_2 + 0x50) = 0;

    }

  }

  else if (*(char *)((int)param_1 + 5) == '\0') {

    (**(code **)(*param_1 + 8))(param_2 + 0x50,1);

  }

  else {

    (**(code **)(*param_1 + 4))();

  }

  if (*(char *)((int)param_1 + 6) != '\0') {

    FUN_0079cde0(param_2);

    return;

  }

  pvVar1 = (void *)FUN_0079d010(0,0);

  FUN_00793aa0(param_2,pvVar1,0x40);

  operator_delete__(pvVar1);

  return;

}
