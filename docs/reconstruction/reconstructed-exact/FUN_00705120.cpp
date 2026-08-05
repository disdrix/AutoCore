// =============================================================================
// FUN_00705120
// -----------------------------------------------------------------------------
// Stable ID: aa_00705120
// Address:   0x00705120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00705120 @ 0x00705120
// Stable ID: aa_00705120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×1.
//  - Notable callees: FUN_0070e350×4, FUN_0070e5a0×2, FUN_0070ed00×2, FUN_007039f0, FUN_00705120, FUN_0070e720.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00705120(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int unaff_ESI;

  int iVar7;

  float local_10;

  float local_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0;

  if (param_2 == 0) {

    FUN_0070e350(0x3f7d70a4,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18));

  }

  else {

    local_8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c) = 1;

  }

  iVar4 = *(int *)(unaff_ESI + 0x18);

  iVar2 = iVar4 * 4;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 1;

  iVar5 = param_3 + 4 + (-param_3 & 3U) + iVar2;

  iVar6 = iVar5 + 4 + (-iVar5 & 3U) + iVar2;

  iVar2 = iVar6 + 4 + (-iVar6 & 3U) + iVar2;

  iVar7 = iVar5 + iVar4 * -4 + -4;

  iVar5 = iVar6 + iVar4 * -4 + -4;

  iVar6 = iVar2 + iVar4 * -4 + -4;

  if (*(int *)(unaff_ESI + 0x24) != 0) {

    iVar3 = *(int *)(*(int *)(unaff_ESI + 0x68) + *(int *)(unaff_ESI + 0x6c) * 4);

    if (iVar3 == 0) {

      local_c = 0.7;

      local_10 = 0.7;

    }

    else {

      local_10 = *(float *)(iVar3 + 0x30);

      local_c = *(float *)(iVar3 + 0x34);

    }

    FUN_0070e350(local_10,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),iVar7,iVar4);

    FUN_0070e350(local_c,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),iVar5,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18));

    FUN_0070e350(local_10 - local_c,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),iVar6,

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18));

  }

  if ((param_2 == 0) && (iVar4 = 0, 0 < *(int *)(unaff_ESI + 0xc))) {

    do {

      iVar3 = iVar4 * 4;

      iVar1 = iVar4 * 4;

      iVar4 = iVar4 + 1;

      *(float *)(*(int *)(unaff_ESI + 0x48) + iVar1) =

           *(float *)(*(int *)(unaff_ESI + 0x48) + iVar3) * (float)_DAT_00a0f1c8;

    } while (iVar4 < *(int *)(unaff_ESI + 0xc));

  }

  iVar4 = 0;

  if (0 < *(int *)(unaff_ESI + 0xc)) {

    do {

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x34) + iVar4 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x48) + iVar4 * 4);

      iVar4 = iVar4 + 1;

    } while (iVar4 < *(int *)(unaff_ESI + 0xc));

  }

  if (*(int *)(unaff_ESI + 0x24) == 0) {

    iVar5 = 0;

    if (0 < *(int *)(unaff_ESI + 0x18)) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x5c) + (*(int *)(unaff_ESI + 0x18) + iVar5) * 4) = 0;

        iVar5 = iVar5 + 1;

      } while (iVar5 < *(int *)(unaff_ESI + 0x18));

    }

    FUN_0070e720(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5c));

  }

  else {

    FUN_0070e5a0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),iVar5,iVar7,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),*(int *)(unaff_ESI + 0x18),

                 *(int *)(unaff_ESI + 0x5c) + *(int *)(unaff_ESI + 0x18) * 4);

    FUN_0070e5a0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),iVar6,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5c));

  }

  FUN_0070ed00(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x2c),&DAT_00af6448,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38),

               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),0x40,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40),iVar2);

  FUN_0070ed00(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34),&DAT_00af6548,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c),

               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),0x40,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44),iVar2);

  FUN_007039f0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c) = local_8;

  }

  return;

}
