// =============================================================================
// FUN_0072afd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072afd0
// Address:   0x0072afd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072afd0 @ 0x0072afd0
// Stable ID: aa_0072afd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: for×4, if×2, return×1.
//  - Notable callees: FUN_0072afd0.
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

void FUN_0072afd0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  

  if (*(int *)(in_EAX + 0x10) != 0) {

    puVar1 = operator_new__(*(int *)(in_EAX + 0x10) * 0xc);

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0x14) = puVar1;

    for (uVar2 = (uint)(*(int *)(in_EAX + 0x10) * 0xc) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar1 = *param_1;

      param_1 = param_1 + 1;

      puVar1 = puVar1 + 1;

    }

    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

      *(uint8_t *)puVar1 = *(uint8_t *)param_1;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  if (*(int *)(in_EAX + 0xc) != 0) {

    puVar1 = operator_new__(*(int *)(in_EAX + 0xc) * 6);

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0x18) = puVar1;

    uVar2 = *(int *)(in_EAX + 0xc) * 6;

    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar1 = *param_2;

      param_2 = param_2 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)param_2;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  return;

}
