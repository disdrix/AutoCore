// =============================================================================
// FUN_008ebfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ebfe0
// Address:   0x008ebfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ebfe0 @ 0x008ebfe0
// Stable ID: aa_008ebfe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008ebfe0.
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

void FUN_008ebfe0(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *unaff_ESI;

  int iStack_58;

  uint8_t *puStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint8_t *puStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint8_t *puStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint8_t auStack_28 [4];

  uint8_t auStack_24 [4];

  uint8_t local_20 [32];

  

  if ((unaff_ESI != (int *)0x0) && (*(int *)(in_EAX + 0x568) != 0)) {

    uStack_34 = 0;

    uStack_38 = 1;

    puStack_3c = local_20;

    uStack_40 = 0x8ec00f;

    iVar1 = (**(code **)(**(int **)(in_EAX + 0x568) + 0x120))();

    uStack_40 = 0;

    uStack_44 = 1;

    puStack_48 = auStack_24;

    uStack_4c = 0x8ec024;

    iVar2 = (**(code **)(*unaff_ESI + 0x120))();

    iVar1 = *(int *)(iVar1 + 4);

    iVar2 = *(int *)(iVar2 + 4);

    uStack_4c = 0;

    uStack_50 = 1;

    puStack_54 = auStack_28;

    iStack_58 = 0x8ec041;

    piVar3 = (int *)(**(code **)(**(int **)(in_EAX + 0x568) + 0x120))();

    iStack_58 = 0;

    piVar4 = (int *)(**(code **)(*unaff_ESI + 0x120))(&stack0xffffffd4,1);

    iStack_58 = *piVar4 + *piVar3;

    puStack_54 = (uint8_t *)(iVar1 + iVar2);

    (**(code **)(*unaff_ESI + 0x110))(&iStack_58);

  }

  return;

}
