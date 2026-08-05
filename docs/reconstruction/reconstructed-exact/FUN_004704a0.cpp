// =============================================================================
// FUN_004704a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004704a0
// Address:   0x004704a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004704a0 @ 0x004704a0
// Stable ID: aa_004704a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, for×3, return×2.
//  - Notable callees: FUN_004704a0, FUN_004766e0, FUN_00476cc0, malloc.
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

void FUN_004704a0(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  int unaff_EBX;

  

  if ((unaff_EBX != 0) && (param_1 != 0)) {

    FUN_004766e0();

    if (*(code **)(unaff_EBX + 0x248) == (code *)0x0) {

      puVar1 = malloc(0x300);

    }

    else {

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(unaff_EBX + 0x248))();

    }

    if ((puVar1 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(unaff_EBX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x114) = puVar1;

    for (iVar2 = 0xc0; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    }

    puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x114);

    for (uVar3 = (uint)(param_3 * 3) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar1 = *param_2;

      param_2 = param_2 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar3 = param_3 * 3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)param_2;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x114);

    *(short *)(unaff_EBX + 0x118) = (short)param_3;

    *(byte *)(param_1 + 0xb9) = *(byte *)(param_1 + 0xb9) | 0x10;

    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 8;

    *(short *)(param_1 + 0x14) = (short)param_3;

  }

  return;

}
