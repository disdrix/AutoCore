// =============================================================================
// FUN_0071c4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c4d0
// Address:   0x0071c4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071c4d0 @ 0x0071c4d0
// Stable ID: aa_0071c4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×2.
//  - Notable callees: CONCAT31, FUN_0071b010, FUN_0071c4d0.
//  - Return sites: 3.

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

uint FUN_0071c4d0(uint32_t /* width from decompiler */ *param_1,ushort *param_2)



{

  ushort uVar1;

  uint in_EAX;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  uVar2 = in_EAX;

  if (2 < *(uint *)(in_EAX + 0x14)) {

    uVar1 = (ushort)(*(byte **)(in_EAX + 0x10))[1] * 0x100 + (ushort)**(byte **)(in_EAX + 0x10);

    *param_2 = uVar1;

    uVar2 = (uint)uVar1;

    if (uVar2 <= *(uint *)(in_EAX + 0x14)) {

      puVar3 = operator_new__(uVar2 - 2);

      *param_1 = puVar3;

      uVar1 = *param_2;

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x10) + 2);

      for (uVar2 = uVar1 - 2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar3 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar2 = uVar1 - 2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar4;

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + (uint)*param_2;

      uVar1 = *param_2;

      *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) - (uint)uVar1;

      *param_2 = *param_2 - 2;

      if (*(int *)(in_EAX + 4) == 0) {

        return CONCAT31((uint3)(byte)(uVar1 >> 8),1);

      }

      uVar2 = FUN_0071b010();

      return uVar2;

    }

  }

  return uVar2 & 0xffffff00;

}
