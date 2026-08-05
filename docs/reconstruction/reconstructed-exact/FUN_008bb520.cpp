// =============================================================================
// FUN_008bb520
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb520
// Address:   0x008bb520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bb520 @ 0x008bb520
// Stable ID: aa_008bb520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CNDHash_LookupByKey, CVOGReaction_RandomUnitScalar, FUN_00541a80, FUN_008bb520, block.
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

/* WARNING: Removing unreachable block (ram,0x008bb5d6) */



void FUN_008bb520(void)



{

  void *pvVar1;

  int iVar2;

  uint uVar3;

  int *unaff_EDI;

  uint key;

  

  if (unaff_EDI[0x15e] != 0) {

    (**(code **)(*(int *)unaff_EDI[0x15e] + 0x1d8))(*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,1,1);

  }

  if (unaff_EDI[0x15f] != 0) {

    (**(code **)(*(int *)unaff_EDI[0x15f] + 0x1d8))(*(int *)(DAT_00d1b644 + 0xe50c) + 0x10c,1,1);

  }

  uVar3 = (uint)*(byte *)(DAT_00d1b644 + 0x7c);

  key = *(uint *)(DAT_00d1b644 + 0xfc);

  pvVar1 = (void *)FUN_00541a80();

  pvVar1 = CNDHash_LookupByKey(pvVar1,key);

  if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 0x10) != 0)) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar3 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2) & 0x80000007;

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  }

  if (unaff_EDI[0x160] != 0) {

    (**(code **)(*(int *)unaff_EDI[0x160] + 0x1d8))

              (*(int *)(DAT_00d1b644 + 0xe50c) + 0x8dc + uVar3 * 0x8d0,1,1);

  }

  if (unaff_EDI[0x161] != 0) {

    (**(code **)(*(int *)unaff_EDI[0x161] + 0x1d8))

              (*(int *)(DAT_00d1b644 + 0xe50c) + 0x9dc + uVar3 * 0x8d0,1,1);

  }

                    /* WARNING: Could not recover jumptable at 0x008bb64e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x34c))();

  return;

}
