// =============================================================================
// FUN_00804ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00804ca0
// Address:   0x00804ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804ca0 @ 0x00804ca0
// Stable ID: aa_00804ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: for×4, if×3, return×2.
//  - Notable callees: FUN_00804ca0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00804ca0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar1 = *(int *)(param_2 + 0x70);

  if (iVar1 != 0) {

    if (*(int *)(iVar1 + 0x4c) != 0) {

      **(uint32_t /* width from decompiler */ **)(iVar1 + 0x4c) = 1;

      uVar2 = *(int *)(iVar1 + 0x48) * *(int *)(iVar1 + 0x44);

      puVar5 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x4c);

      puVar4 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x60);

      for (uVar3 = uVar2 >> 2; puVar5 = puVar5 + 1, uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

      }

      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      }

    }

    return *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c);

  }

  if (*(int *)(param_2 + 0x4c) != 0) {

    **(uint32_t /* width from decompiler */ **)(param_2 + 0x4c) = 1;

    uVar2 = *(int *)(param_2 + 0x48) * *(int *)(param_2 + 0x44);

    puVar5 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x4c);

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x60);

    for (uVar3 = uVar2 >> 2; puVar5 = puVar5 + 1, uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

    }

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

  }

  return *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c);

}
