// =============================================================================
// FUN_00477a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00477a60
// Address:   0x00477a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477a60 @ 0x00477a60
// Stable ID: aa_00477a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_00477a60.
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

void FUN_00477a60(void)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar4 = *(uint *)(*(int *)(in_EAX + 0x1c) + 0x14);

  if (*(uint *)(in_EAX + 0x10) < uVar4) {

    uVar4 = *(uint *)(in_EAX + 0x10);

  }

  if (uVar4 != 0) {

    puVar5 = *(uint32_t /* width from decompiler */ **)(*(int *)(in_EAX + 0x1c) + 0x10);

    puVar6 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0xc);

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + uVar4;

    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x10);

    *piVar1 = *piVar1 + uVar4;

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + uVar4;

    *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) - uVar4;

    piVar1 = (int *)(*(int *)(in_EAX + 0x1c) + 0x14);

    *piVar1 = *piVar1 - uVar4;

    iVar2 = *(int *)(in_EAX + 0x1c);

    if (*(int *)(iVar2 + 0x14) == 0) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar2 + 8);

    }

  }

  return;

}
