// =============================================================================
// Named_CalleeOf_Named_ecc_sys_0077a730
// -----------------------------------------------------------------------------
// Stable ID: aa_0077a730
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x0077a730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper. Evidence string: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n". Supports parent flow (not a free-standing entry point). Named_ecc_sys (+1 other named callers).
// Embedded strings (evidence):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "key != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×14, return×5, goto×4, do×1, while×1.
//  - Notable callees: FUN_00770210×4, FUN_00772910×3, free×3, FUN_00770120×2, FUN_00772250×2, FUN_00770250, FUN_007707d0, FUN_00771cb0.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "key != NULL"; "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_CalleeOf_Named_ecc_sys_0077a730(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  int iVar2;

  void *_Memory;

  void *_Memory_00;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint8_t auStack_10 [16];

  

  if (unaff_EDI == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "key != NULL",0x329,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\pk\\ecc\\ecc.c"

           );

    raise(0x16);

  }

  if (((param_1 < 0) || (0x1f < param_1)) || ((&DAT_00d19030)[param_1 * 10] == 0)) {

    return 0xc;

  }

  iVar4 = 0;

  if (0x14 < in_EAX) {

    iVar2 = 0x14;

    puVar3 = &DAT_00a23878;

    do {

      if (iVar2 == 0) break;

      iVar2 = puVar3[7];

      puVar3 = puVar3 + 7;

      iVar4 = iVar4 + 1;

    } while (iVar2 < in_EAX);

  }

  iVar2 = (&DAT_00a23878)[iVar4 * 7];

  if ((0x42 < iVar2) || (iVar2 == 0)) {

    return 3;

  }

  unaff_EDI[1] = iVar4;

  _Memory = malloc(0x42);

  if (_Memory == (void *)0x0) {

    return 0xd;

  }

  iVar4 = (**(code **)(&DAT_00d19044 + param_1 * 0x28))(_Memory,iVar2,param_2);

  if (iVar4 != iVar2) {

    free(_Memory);

    return 9;

  }

  puVar3 = unaff_EDI + 0xe;

  puVar1 = unaff_EDI + 2;

  iVar4 = FUN_00771cb0(puVar1,unaff_EDI + 6,unaff_EDI + 10,puVar3,auStack_10,0);

  if (iVar4 != 0) {

    iVar4 = FUN_00770120();

    goto LAB_0077a9a5;

  }

  _Memory_00 = (void *)FUN_00778a00();

  if (_Memory_00 == (void *)0x0) {

    FUN_00772250(puVar1,unaff_EDI + 6,unaff_EDI + 10,puVar3,auStack_10,0);

    iVar4 = 0xd;

    goto LAB_0077a983;

  }

  iVar4 = FUN_00772910(0x40);

  if (((iVar4 == 0) && (iVar4 = FUN_00772910(0x40), iVar4 == 0)) &&

     (iVar4 = FUN_00772910(0x40), iVar4 == 0)) {

    FUN_00770250();

    iVar4 = FUN_00774cc0();

    if (iVar4 != 0) goto LAB_0077a976;

    iVar4 = FUN_00779c60(puVar3,_Memory_00,puVar1,auStack_10);

    if (iVar4 == 0) {

      *unaff_EDI = 0;

      iVar4 = FUN_00770210();

      if ((((iVar4 != 0) || (iVar4 = FUN_00770210(), iVar4 != 0)) ||

          (iVar4 = FUN_00770210(), iVar4 != 0)) || (iVar4 = FUN_00770210(), iVar4 != 0))

      goto LAB_0077a976;

      iVar4 = 0;

    }

  }

  else {

LAB_0077a976:

    iVar4 = FUN_00770120();

  }

LAB_0077a983:

  if (_Memory_00 != (void *)0x0) {

    FUN_00772250(_Memory_00,(int)_Memory_00 + 0x10,(int)_Memory_00 + 0x20,0);

    free(_Memory_00);

  }

LAB_0077a9a5:

  FUN_007707d0();

  free(_Memory);

  return iVar4;

}
