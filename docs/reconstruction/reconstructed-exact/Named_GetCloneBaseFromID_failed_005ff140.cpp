// =============================================================================
// Named_GetCloneBaseFromID_failed_005ff140
// -----------------------------------------------------------------------------
// Stable ID: aa_005ff140
// Address:   0x005ff140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_GetCloneBaseFromID_failed_005ff140 @ 0x005ff140
// Stable ID: aa_005ff140
// Embedded strings (evidence for future rename):
//   - "GetCloneBaseFromID failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00404d70, FUN_004ce940, FUN_004f1e20, FUN_00508b10, FUN_005ca680, Named_GetCloneBaseFromID_failed_005ff140, FUN_007a4480.
//  - Strings: "GetCloneBaseFromID failed %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "GetCloneBaseFromID failed %d"
 * Domain alias of FUN_005ff140 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_GetCloneBaseFromID_failed_005ff140(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  FUN_005ca680(param_2,param_3);

  FUN_004ce940();

  iVar1 = FUN_00404d70(param_2);

  if (iVar1 == 0) {

    FUN_007a4480(0,"GetCloneBaseFromID failed %d",param_2);

  }

  else {

    if (*(int *)(iVar1 + 0x3c) == 0) {

      FUN_004f1e20(1,1);

    }

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x3c) + 0x4c0);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00508b10(*puVar2);

      if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar2)(param_1 + -0xe0,param_2,1);

        return 1;

      }

    }

  }

  return 0;

}
