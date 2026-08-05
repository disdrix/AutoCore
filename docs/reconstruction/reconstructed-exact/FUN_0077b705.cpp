// =============================================================================
// FUN_0077b705
// -----------------------------------------------------------------------------
// Stable ID: aa_0077b705
// Address:   0x0077b705  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077b705 @ 0x0077b705
// Stable ID: aa_0077b705
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×13, goto×11, return×2, while×2, do×1.
//  - Notable callees: FUN_00772250×6, FUN_00772910×4, free×4, FUN_007707a0×2, FUN_00778a00×2, FUN_0099edb0×2, FUN_00770250, FUN_00770850.
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

int FUN_0077b705(int param_1)



{

  undefined **ppuVar1;

  void *_Memory;

  void *_Memory_00;

  int iVar2;

  int iVar3;

  undefined **ppuVar4;

  

  _Memory = (void *)FUN_00778a00();

  _Memory_00 = (void *)FUN_00778a00();

  if ((_Memory == (void *)0x0) || (_Memory_00 == (void *)0x0)) {

    FUN_00772250(&stack0x00000018,&stack0x00000008,0);

    if (_Memory != (void *)0x0) {

      FUN_00772250(_Memory,(int)_Memory + 0x10,(int)_Memory + 0x20,0);

      free(_Memory);

    }

    if (_Memory_00 != (void *)0x0) {

      FUN_00772250(_Memory_00,(int)_Memory_00 + 0x10,(int)_Memory_00 + 0x20,0);

      free(_Memory_00);

    }

    return 0xd;

  }

  ppuVar4 = &PTR_s_G0000000000004sCQUtDxaqDUN5_00a23888;

  do {

    iVar2 = FUN_00772910(0x40);

    if ((iVar2 != 0) || (iVar2 = FUN_00772910(0x40), iVar2 != 0)) goto LAB_0077b8a7;

    iVar2 = FUN_0099edb0(&param_1);

    if (iVar2 != 0) goto LAB_0077b859;

    if (param_1 == 0) {

LAB_0077b8d1:

      iVar2 = 5;

      goto LAB_0077b859;

    }

    iVar2 = FUN_0099edb0(&param_1);

    if (iVar2 != 0) goto LAB_0077b859;

    if (param_1 == 0) goto LAB_0077b8d1;

    iVar2 = FUN_00772910(0x40);

    if ((iVar2 != 0) || (iVar2 = FUN_00772910(0x40), iVar2 != 0)) {

LAB_0077b8a7:

      iVar3 = 0;

      goto LAB_0077b8b0;

    }

    FUN_00770250();

    iVar2 = FUN_00770850(1,&stack0x00000008);

    if (iVar2 != 0) goto LAB_0077b8a7;

    iVar2 = FUN_00779c60(&stack0x00000008,_Memory,_Memory_00,&stack0x00000018);

    if (iVar2 != 0) goto LAB_0077b859;

    iVar2 = FUN_007707a0();

    if ((iVar2 != 0) || (iVar2 = FUN_007707a0(), iVar2 != 0)) goto LAB_0077b8d1;

    ppuVar1 = ppuVar4 + 3;

    ppuVar4 = ppuVar4 + 7;

  } while (*ppuVar1 != (undefined *)0x0);

  iVar2 = 0;

  goto LAB_0077b859;

  while (iVar3 = iVar3 + 1, iVar3 < 3) {

LAB_0077b8b0:

    if (iVar2 == (&DAT_00a240d0)[iVar3 * 2]) {

      iVar2 = *(int *)(&UNK_00a240d4 + iVar3 * 8);

      goto LAB_0077b859;

    }

  }

  iVar2 = 1;

LAB_0077b859:

  FUN_00772250(_Memory_00,(int)_Memory_00 + 0x10,(int)_Memory_00 + 0x20,0);

  free(_Memory_00);

  FUN_00772250(_Memory,(int)_Memory + 0x10,(int)_Memory + 0x20,0);

  free(_Memory);

  FUN_00772250(&stack0x00000008,&stack0x00000018,0);

  return iVar2;

}
