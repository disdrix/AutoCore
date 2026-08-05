// =============================================================================
// FUN_00780980
// -----------------------------------------------------------------------------
// Stable ID: aa_00780980
// Address:   0x00780980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780980 @ 0x00780980
// Stable ID: aa_00780980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, return×1.
//  - Notable callees: FUN_00780980.
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

void __thiscall FUN_00780980(int param_1,char param_2)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  

  if ((*(int *)(param_1 + 0x208) == 0) && (param_2 != '\0')) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x210) = 0;

    pvVar2 = operator_new__(0x1000);

    *(void **)(param_1 + 0x208) = pvVar2;

    pvVar2 = operator_new__(0xe000);

    *(void **)(param_1 + 0x220) = pvVar2;

    iVar4 = 0;

    iVar3 = 0;

    do {

      *(uint32_t /* width from decompiler */ *)(iVar3 + *(int *)(param_1 + 0x220)) = 0;

      *(int *)(*(int *)(param_1 + 0x220) + 0x30 + iVar3) = iVar4;

      iVar1 = *(int *)(param_1 + 0x220);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + iVar3) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc + iVar3) = 0;

      iVar3 = iVar3 + 0x38;

      iVar4 = iVar4 + 1;

    } while (iVar3 < 0xe000);

    pvVar2 = operator_new__(0x1000);

    *(void **)(param_1 + 0x224) = pvVar2;

    iVar3 = 0;

    do {

      *(uint32_t /* width from decompiler */ *)(iVar3 + *(int *)(param_1 + 0x224)) = 0;

      iVar3 = iVar3 + 4;

    } while (iVar3 < 0x1000);

  }

  return;

}
