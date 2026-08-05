// =============================================================================
// FUN_008a27e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a27e0
// Address:   0x008a27e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a27e0 @ 0x008a27e0
// Stable ID: aa_008a27e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008a27e0.
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

void FUN_008a27e0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *unaff_ESI;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puStack_30;

  uint8_t *puStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  int iStack_24;

  uint8_t *puStack_20;

  uint8_t auStack_14 [4];

  uint8_t local_10 [4];

  uint8_t auStack_c [4];

  uint8_t local_8 [8];

  

  if (unaff_ESI != (int *)0x0) {

    puStack_20 = local_10;

    iStack_24 = 0x8a27fa;

    iVar1 = (**(code **)(*unaff_ESI + 0x124))();

    iStack_24 = 0;

    uStack_28 = 1;

    puStack_2c = auStack_c;

    puStack_20 = (uint8_t *)

                 ((float)DAT_00d1e81c * (*(float *)(iVar1 + 4) + DAT_00aaa8dc) * DAT_00aaa678);

    puStack_30 = (uint32_t /* width from decompiler */ *)0x8a2834;

    puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_ESI + 0x120))();

    uStack_28 = *puVar2;

    iStack_24 = (int)(float)puStack_2c;

    puStack_30 = &uStack_28;

    (**(code **)(*unaff_ESI + 0x110))();

    puStack_30 = (uint32_t /* width from decompiler */ *)0xff696969;

    (**(code **)(*unaff_ESI + 0x15c))(0,&puStack_30);

  }

  if (unaff_EDI != (int *)0x0) {

    puStack_20 = local_8;

    iStack_24 = 0x8a288b;

    iVar1 = (**(code **)(*unaff_EDI + 0x124))();

    iStack_24 = 0;

    uStack_28 = 1;

    puStack_2c = auStack_14;

    puStack_20 = (uint8_t *)

                 ((float)DAT_00d1e81c * (*(float *)(iVar1 + 4) + DAT_00aaa8dc) * DAT_00aaa678);

    puStack_30 = (uint32_t /* width from decompiler */ *)0x8a28c5;

    puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EDI + 0x120))();

    uStack_28 = *puVar2;

    iStack_24 = (int)(float)puStack_2c;

    puStack_30 = &uStack_28;

    (**(code **)(*unaff_EDI + 0x110))();

    puStack_30 = (uint32_t /* width from decompiler */ *)0xffa5a5a5;

    (**(code **)(*unaff_EDI + 0x15c))(1,&puStack_30);

  }

  return;

}
