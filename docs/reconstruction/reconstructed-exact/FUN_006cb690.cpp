// =============================================================================
// FUN_006cb690
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb690
// Address:   0x006cb690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cb690 @ 0x006cb690
// Stable ID: aa_006cb690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_006cb690.
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

void __fastcall FUN_006cb690(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  *param_1 = &PTR_FUN_00a0d914;

  piVar4 = param_1 + 3;

  iVar3 = 8;

  do {

    iVar2 = 8;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)*piVar4;

      if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) &&

         (*(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1,

         *(short *)((int)puVar1 + 6) == 0)) {

        (**(code **)*puVar1)(1);

      }

      piVar4 = piVar4 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  if (-1 < (int)param_1[0x1369]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1367],(param_1[0x1369] & 0x7fffffff) * 0x1c,0x12);

  }

  if (-1 < (int)param_1[0x1366]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1364],param_1[0x1366] << 3,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
