// =============================================================================
// FUN_0068e8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068e8f0
// Address:   0x0068e8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068e8f0 @ 0x0068e8f0
// Stable ID: aa_0068e8f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0068e8f0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0068e8f0(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

  if ((((puVar1 != (uint32_t /* width from decompiler */ *)0x0) && (*(uint32_t /* width from decompiler */ **)(param_1 + 0x10) != (uint32_t /* width from decompiler */ *)0x0)) &&

      (puVar5 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x10), puVar5 != (uint32_t /* width from decompiler */ *)0x0)) &&

     (puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

    uVar2 = (uint)*(ushort *)(param_1 + 0x1c) * (uint)*(ushort *)(param_1 + 8) * 0x80;

    puVar6 = puVar1;

    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    *param_2 = (int)((uVar2 - *(int *)(param_1 + 0x18)) + (int)puVar1) >> 2;

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

}
