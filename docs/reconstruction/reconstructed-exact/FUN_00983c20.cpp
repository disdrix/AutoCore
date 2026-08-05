// =============================================================================
// FUN_00983c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00983c20
// Address:   0x00983c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983c20 @ 0x00983c20
// Stable ID: aa_00983c20
// Embedded strings (evidence for future rename):
//   - "Force opening %s from disk from pack file."
//   - "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"
//   - "opening %s FAILED! (result=%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_0076c0b0, FUN_00983680, FUN_00983b60, FUN_00983c20.
//  - Strings: "Force opening %s from disk from pack file."; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"; "opening %s FAILED! (result=%d)".
//  - Return sites: 4.

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

int * FUN_00983c20(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  int iVar5;

  undefined *puVar6;

  int *piVar7;

  int *piVar8;

  int local_8;

  int *local_4;

  

  piVar7 = param_2;

  piVar8 = (int *)0x0;

  local_8 = 0;

  local_4 = (int *)0x0;

  piVar2 = (int *)FUN_00983680(&local_8,&local_4,1);

  if (piVar2 == (int *)0x0) {

    return (int *)0x0;

  }

  if (local_4 == (int *)0x0) {

    puVar6 = (undefined *)*piVar7;

    if ((undefined *)*piVar7 == (undefined *)0x0) {

      puVar6 = PTR_DAT_00afa2bc;

    }

    uVar3 = FUN_0076cec0(&param_2,"Force opening %s from disk from pack file.",puVar6);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0xcb,1,uVar3);

    pvVar4 = operator_new(0x18);

    iVar1 = local_8;

    if (pvVar4 != (void *)0x0) {

      piVar8 = (int *)FUN_0076c0b0(local_8);

    }

    iVar5 = (**(code **)(*piVar2 + 0x14))(piVar8[1],iVar1);

    (**(code **)*piVar2)(1);

    if (-1 < iVar5) {

      piVar8[3] = iVar1;

      (**(code **)(*piVar8 + 8))();

      return piVar8;

    }

    puVar6 = (undefined *)*local_4;

    if ((undefined *)*local_4 == (undefined *)0x0) {

      puVar6 = PTR_DAT_00afa2bc;

    }

    uVar3 = FUN_0076cec0(&local_4,"opening %s FAILED! (result=%d)",puVar6,iVar5);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0xd7,1,uVar3);

    return (int *)0x0;

  }

  piVar7 = (int *)FUN_00983b60(0,local_4);

  return piVar7;

}
