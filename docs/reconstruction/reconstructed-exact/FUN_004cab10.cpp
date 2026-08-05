// =============================================================================
// FUN_004cab10
// -----------------------------------------------------------------------------
// Stable ID: aa_004cab10
// Address:   0x004cab10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cab10 @ 0x004cab10
// Stable ID: aa_004cab10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT31, FUN_004ca910, FUN_004cab10, FUN_005cbcb0.
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

void __thiscall FUN_004cab10(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  

  if (param_2 != 0) {

    FUN_005cbcb0(param_2,param_3,param_4);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3d8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3a0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x110);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x2f0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xf8);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x2ec) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xfc);

    *(bool *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4b4 + param_1) =

         (*(uint *)(param_2 + 0x130) & *(uint *)(param_2 + 0x134)) != 0xffffffff;

    iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

    *(uint32_t /* width from decompiler */ *)(iVar1 + -0x4bc + param_1) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x130);

    *(uint32_t /* width from decompiler */ *)(iVar1 + -0x4b8 + param_1) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x134);

    iVar2 = *(int *)(param_2 + 0x114);

    if (iVar2 < 2) {

      iVar2 = 1;

    }

    *(int *)(param_1 + -0x3b0) = iVar2;

    if (*(char *)(param_2 + 0x126) != '\0') {

      *(uint8_t *)(param_1 + -0x1f5) = 1;

    }

    CVOGWaypoint_InitFromSpawn

              (*(int *)(param_2 + 0x118),*(int *)(param_2 + 0x118) >> 0x1f,

               *(uint32_t /* width from decompiler */ *)(param_2 + 0x11c),*(uint32_t /* width from decompiler */ *)(param_2 + 0x120),1,

               CONCAT31((int3)((uint)iVar1 >> 8),*(uint8_t *)(param_2 + 0x124)));

    FUN_004ca910(param_2 + 0xe0,*(char *)(param_2 + 0xf0) == '\0');

  }

  return;

}
