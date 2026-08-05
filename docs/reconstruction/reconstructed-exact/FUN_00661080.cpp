// =============================================================================
// FUN_00661080
// -----------------------------------------------------------------------------
// Stable ID: aa_00661080
// Address:   0x00661080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00661080 @ 0x00661080
// Stable ID: aa_00661080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005b3370, FUN_00660f80, FUN_00661080.
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

uint32_t /* width from decompiler */ __fastcall FUN_00661080(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(int *)(param_1 + 0x10) == 0) {

    puVar1 = operator_new(0x18);

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar1 = 0;

      puVar1[1] = 0;

      puVar1[2] = 0x80000000;

      puVar1[3] = 0;

      puVar1[4] = 0;

      puVar1[5] = 0x80000000;

      puVar4 = puVar1;

    }

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x60,8);

    *(uint16_t *)(iVar2 + 4) = 0x60;

    uVar3 = FUN_00660f80(puVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar3;

    if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {

      FUN_005b3370(unaff_ESI,4);

    }

    *(uint32_t /* width from decompiler */ *)(*unaff_ESI + unaff_ESI[1] * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    unaff_ESI[1] = unaff_ESI[1] + 1;

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

}
