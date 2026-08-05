// =============================================================================
// FUN_004c6730
// -----------------------------------------------------------------------------
// Stable ID: aa_004c6730
// Address:   0x004c6730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c6730 @ 0x004c6730
// Stable ID: aa_004c6730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×31, goto×8, return×2.
//  - Notable callees: GetTickCount×14, FUN_004c4e80×2, FUN_004c6730.
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

void __thiscall FUN_004c6730(int param_1,uint param_2)



{

  byte *pbVar1;

  int iVar2;

  DWORD DVar3;

  uint *puVar4;

  

  if ((param_2 & 0x125e) == 0) {

    if ((param_2 & 0x100000) == 0) goto LAB_004c6a61;

  }

  else if ((param_2 & 0x100000) == 0) {

    if ((param_2 & 2) != 0) {

      if ((*(byte *)(param_1 + -0x1e8) & 2) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1e4) < 0x1771) goto LAB_004c67b4;

        *(uint *)(param_1 + -0x1e8) = *(uint *)(param_1 + -0x1e8) & 0xfffffffd;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      puVar4 = (uint *)(iVar2 + -0x448 + param_1);

      *puVar4 = *puVar4 | 2;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1c4) = *(int *)(param_1 + -0x1c4) + 1;

      *(DWORD *)(param_1 + -0x1e4) = DVar3;

    }

LAB_004c67b4:

    if ((param_2 & 4) != 0) {

      if ((*(byte *)(param_1 + -0x1e8) & 4) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1e0) < 0x1771) goto LAB_004c680b;

        *(uint *)(param_1 + -0x1e8) = *(uint *)(param_1 + -0x1e8) & 0xfffffffb;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      puVar4 = (uint *)(iVar2 + -0x448 + param_1);

      *puVar4 = *puVar4 | 4;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1c0) = *(int *)(param_1 + -0x1c0) + 1;

      *(DWORD *)(param_1 + -0x1e0) = DVar3;

    }

LAB_004c680b:

    if ((param_2 & 8) != 0) {

      if ((*(byte *)(param_1 + -0x1e8) & 8) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1dc) < 0x1771) goto LAB_004c6862;

        *(uint *)(param_1 + -0x1e8) = *(uint *)(param_1 + -0x1e8) & 0xfffffff7;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      puVar4 = (uint *)(iVar2 + -0x448 + param_1);

      *puVar4 = *puVar4 | 8;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1bc) = *(int *)(param_1 + -0x1bc) + 1;

      *(DWORD *)(param_1 + -0x1dc) = DVar3;

    }

LAB_004c6862:

    if ((param_2 & 0x10) != 0) {

      if ((*(byte *)(param_1 + -0x1e8) & 0x10) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1d8) < 0x1771) goto LAB_004c68b9;

        *(uint *)(param_1 + -0x1e8) = *(uint *)(param_1 + -0x1e8) & 0xffffffef;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      puVar4 = (uint *)(iVar2 + -0x448 + param_1);

      *puVar4 = *puVar4 | 0x10;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1b8) = *(int *)(param_1 + -0x1b8) + 1;

      *(DWORD *)(param_1 + -0x1d8) = DVar3;

    }

LAB_004c68b9:

    if ((param_2 & 0x40) != 0) {

      if ((*(byte *)(param_1 + -0x1e8) & 0x40) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1d4) < 0x1771) goto LAB_004c6910;

        *(uint *)(param_1 + -0x1e8) = *(uint *)(param_1 + -0x1e8) & 0xffffffbf;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      puVar4 = (uint *)(iVar2 + -0x448 + param_1);

      *puVar4 = *puVar4 | 0x40;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1b4) = *(int *)(param_1 + -0x1b4) + 1;

      *(DWORD *)(param_1 + -0x1d4) = DVar3;

    }

LAB_004c6910:

    if ((param_2 & 0x200) != 0) {

      if ((*(byte *)(param_1 + -0x1e7) & 2) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1d0) < 0x1771) goto LAB_004c6968;

        *(byte *)(param_1 + -0x1e7) = *(byte *)(param_1 + -0x1e7) & 0xfd;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      pbVar1 = (byte *)(iVar2 + param_1 + -0x447);

      *pbVar1 = *pbVar1 | 2;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1b0) = *(int *)(param_1 + -0x1b0) + 1;

      *(DWORD *)(param_1 + -0x1d0) = DVar3;

    }

LAB_004c6968:

    if ((param_2 & 0x1000) != 0) {

      if ((*(byte *)(param_1 + -0x1e7) & 0x10) == 0) {

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      else {

        DVar3 = GetTickCount();

        if (DVar3 - *(int *)(param_1 + -0x1cc) < 0x1771) goto LAB_004c69c0;

        *(byte *)(param_1 + -0x1e7) = *(byte *)(param_1 + -0x1e7) & 0xef;

        iVar2 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      }

      pbVar1 = (byte *)(iVar2 + param_1 + -0x447);

      *pbVar1 = *pbVar1 | 0x10;

      DVar3 = GetTickCount();

      *(int *)(param_1 + -0x1ac) = *(int *)(param_1 + -0x1ac) + 1;

      *(DWORD *)(param_1 + -0x1cc) = DVar3;

    }

LAB_004c69c0:

    *(bool *)(param_1 + -0x1eb) =

         0 < *(int *)(param_1 + -0x1c4) + *(int *)(param_1 + -0x1c0) + *(int *)(param_1 + -0x1bc) +

             *(int *)(param_1 + -0x1b8) + *(int *)(param_1 + -0x1b4) + *(int *)(param_1 + -0x1b0) +

             *(int *)(param_1 + -0x1ac);

    FUN_004c4e80();

    return;

  }

  if ((param_2 & 2) != 0) {

    *(int *)(param_1 + -0x1a4) = *(int *)(param_1 + -0x1a4) + 1;

  }

  if ((param_2 & 4) != 0) {

    *(int *)(param_1 + -0x1a0) = *(int *)(param_1 + -0x1a0) + 1;

  }

  if ((param_2 & 8) != 0) {

    *(int *)(param_1 + -0x19c) = *(int *)(param_1 + -0x19c) + 1;

  }

  if ((param_2 & 0x10) != 0) {

    *(int *)(param_1 + -0x198) = *(int *)(param_1 + -0x198) + 1;

  }

  if ((param_2 & 0x40) != 0) {

    *(int *)(param_1 + -0x194) = *(int *)(param_1 + -0x194) + 1;

  }

  if ((param_2 & 0x200) != 0) {

    *(int *)(param_1 + -400) = *(int *)(param_1 + -400) + 1;

  }

  if ((param_2 & 0x1000) != 0) {

    *(int *)(param_1 + -0x18c) = *(int *)(param_1 + -0x18c) + 1;

  }

LAB_004c6a61:

  puVar4 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x448);

  *puVar4 = *puVar4 | param_2 & 0xffefffff;

  FUN_004c4e80();

  return;

}
