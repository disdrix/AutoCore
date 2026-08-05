// =============================================================================
// FUN_0079a2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a2c0
// Address:   0x0079a2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a2c0 @ 0x0079a2c0
// Stable ID: aa_0079a2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_0079a2c0.
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



void FUN_0079a2c0(void)



{

  int iVar1;

  float fVar2;

  int in_EAX;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  pfVar3 = (float *)(in_EAX + 0x68);

  iVar5 = 2;

  do {

    *pfVar3 = pfVar3[0xe] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[1] = pfVar3[0xf] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[2] = pfVar3[0x10] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[3] = pfVar3[0x11] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[4] = pfVar3[0x12] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[5] = pfVar3[0x13] / (float)*(int *)(in_EAX + 0x10);

    pfVar3[6] = pfVar3[0x14] / (float)*(int *)(in_EAX + 0x10);

    pfVar3 = pfVar3 + 7;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  iVar5 = 0;

  if (0 < *(int *)(in_EAX + 0x1c)) {

    iVar4 = 0;

    do {

      iVar1 = *(int *)(in_EAX + 0x18);

      fVar2 = (float)*(int *)(iVar1 + 0xc + iVar4);

      if (*(int *)(iVar1 + 0xc + iVar4) < 0) {

        fVar2 = fVar2 + _DAT_00aaa5dc;

      }

      *(float *)(iVar1 + iVar4 + 0x1c) =

           (fVar2 / (float)*(int *)(in_EAX + 0x10)) / *(float *)(in_EAX + 0x30);

      iVar1 = *(int *)(in_EAX + 0x18);

      fVar2 = (float)*(int *)(iVar1 + 0x10 + iVar4);

      iVar6 = iVar1 + iVar4;

      if (*(int *)(iVar1 + 0x10 + iVar4) < 0) {

        fVar2 = fVar2 + _DAT_00aaa5dc;

      }

      iVar5 = iVar5 + 1;

      iVar4 = iVar4 + 0x2c;

      *(float *)(iVar6 + 0x20) =

           (fVar2 / (float)*(int *)(in_EAX + 0x10)) / *(float *)(in_EAX + 0x30);

    } while (iVar5 < *(int *)(in_EAX + 0x1c));

  }

  return;

}
