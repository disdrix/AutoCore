// =============================================================================
// FUN_005819e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005819e0
// Address:   0x005819e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005819e0 @ 0x005819e0
// Stable ID: aa_005819e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00581940, FUN_005819e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005819e0(int param_1,int *param_2,int param_3)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint unaff_ESI;

  int unaff_retaddr;

  

  iVar3 = param_3;

  if (param_2 == (int *)0x0) {

    return 0;

  }

  if (0x14 < param_3) {

    (**(code **)(*param_2 + 0x14))(&param_3,4);

    if (unaff_retaddr != 0) {

      pvVar4 = operator_new__(unaff_retaddr + 1);

      *(void **)(param_1 + 0x18) = pvVar4;

      (**(code **)(*param_2 + 0x14))(pvVar4,unaff_retaddr);

      *(uint8_t *)(unaff_retaddr + *(int *)(param_1 + 0x18)) = 0;

      FUN_00581940();

    }

    if (0x2f < iVar3) {

      (**(code **)(*param_2 + 0x14))(&stack0xfffffffc,1);

      iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

      puVar1 = (uint *)(iVar2 + 0x180 + param_1);

      *puVar1 = *puVar1 ^ ((unaff_ESI & 0xff) << 0x12 ^ *(uint *)(iVar2 + 0x180 + param_1)) &

                          0x40000;

    }

    if (0x3d < iVar3) {

      (**(code **)(*param_2 + 0x14))(&stack0xfffffffc,4);

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x118 + param_1) = unaff_EBX;

    }

  }

  return 1;

}
