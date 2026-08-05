// =============================================================================
// FUN_009430f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009430f0
// Address:   0x009430f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009430f0 @ 0x009430f0
// Stable ID: aa_009430f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: Client_MaybeShowFirstTimeTip×4, FUN_00941fb0×2, CNDHash_LookupByKey, FUN_004962b0, FUN_004d9f00, FUN_00541a80, FUN_0066e9c0, FUN_00923c50.
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

void FUN_009430f0(void)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  void *pvVar4;

  int unaff_ESI;

  uint key;

  

  FUN_004d9f00();

  *(uint8_t *)(*(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe894) + 0x8c) = 1;

  if ((*(int *)(unaff_ESI + 0xe04) != 0) && (*(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe898) != 0)) {

    FUN_004962b0();

  }

  if (*(int *)(unaff_ESI + 0xf38) != 0) {

    FUN_00923c50();

    piVar1 = *(int **)(unaff_ESI + 0xf38);

    if (piVar1[0x31e] != 0) {

      (**(code **)(*piVar1 + 0x318))();

      (**(code **)(*(int *)piVar1[0x31e] + 0xfc))(0,0x40000000);

    }

    iVar2 = *(int *)(unaff_ESI + 0xf38);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcc4) = 6;

    *(uint8_t *)(iVar2 + 0xa82) = 0;

    (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0x3c4))(1);

    *(uint8_t *)(*(int *)(unaff_ESI + 0xf38) + 0xa84) = 1;

    if (*(char *)(*(int *)(unaff_ESI + 0xe04) + 0xf5) == '\0') {

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00a110d8;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0x530) = DAT_00aaaccc;

    }

    *(uint8_t *)(*(int *)(unaff_ESI + 0xf38) + 0xa83) = *(uint8_t *)(unaff_ESI + 0x9d1);

    *(uint8_t *)(unaff_ESI + 0x31d9) = 0;

  }

  iVar2 = *(int *)(unaff_ESI + 0xe04);

  if (((iVar2 != 0) && (*(char *)(iVar2 + 0x100) != '\0')) && (*(char *)(iVar2 + 0xf5) == '\0')) {

    Client_MaybeShowFirstTimeTip(0x19);

    Client_MaybeShowFirstTimeTip(0x17);

    Client_MaybeShowFirstTimeTip(0x31);

    if ((*(byte *)(*(int *)(unaff_ESI + 0xe98) + 0xd36) & 1) == 0) {

      key = *(uint *)(*(int *)(unaff_ESI + 0xe04) + 0xfc);

      pvVar4 = (void *)FUN_00541a80();

      pvVar4 = CNDHash_LookupByKey(pvVar4,key);

      if ((pvVar4 != (void *)0x0) && (*(int *)((int)pvVar4 + 0x14c) != 0)) {

        Client_MaybeShowFirstTimeTip(0x30);

      }

    }

  }

  FUN_009301b0();

  iVar2 = *(int *)(unaff_ESI + 0xe98);

  if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0xca8) & *(uint *)(iVar2 + 0xcac)) != 0xffffffff)) {

    cVar3 = FUN_0066e9c0();

    if (cVar3 == '\0') {

      FUN_00941fb0(unaff_ESI,3,0);

      FUN_00941fb0(unaff_ESI,1,1);

    }

  }

  if (*(int *)(unaff_ESI + 0x4d0) != 0) {

    *(uint8_t *)(*(int *)(unaff_ESI + 0x4d0) + 4) = 1;

  }

  DAT_00d1ad1c = 0;

  *(uint8_t *)(unaff_ESI + 0xb6) = 0;

  *(uint8_t *)(unaff_ESI + 0xb7) = 1;

  return;

}
