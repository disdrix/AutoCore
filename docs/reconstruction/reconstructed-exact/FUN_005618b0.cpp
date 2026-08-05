// =============================================================================
// FUN_005618b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005618b0
// Address:   0x005618b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005618b0 @ 0x005618b0
// Stable ID: aa_005618b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00561450, FUN_005618b0.
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

void __fastcall FUN_005618b0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar3 = 0;

  uStack_4 = param_1;

  if (0 < *(int *)(param_1 + 0xf4)) {

    do {

      iVar1 = *(int *)(*(int *)(param_1 + 0xf0) + iVar3 * 4);

      if (*(int *)(iVar1 + 0x44) != 0) {

        FUN_00561450((int)&uStack_4 + 3,iVar1);

      }

      puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xf0) + iVar3 * 4);

      *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

      if (*(short *)((int)puVar2 + 6) == 0) {

        (**(code **)*puVar2)(1);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0xf4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  return;

}
