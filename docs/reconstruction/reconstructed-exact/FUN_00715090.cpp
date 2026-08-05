// =============================================================================
// FUN_00715090
// -----------------------------------------------------------------------------
// Stable ID: aa_00715090
// Address:   0x00715090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00715090 @ 0x00715090
// Stable ID: aa_00715090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×2, return×1.
//  - Notable callees: FUN_00715a00×2, FUN_00714480, FUN_00715090, FUN_00715200, FUN_007159e0, FUN_007178b0.
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



void FUN_00715090(uint32_t /* width from decompiler */ *param_1,int param_2,float *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  float10 fVar9;

  uint32_t /* width from decompiler */ uStack_240;

  float fStack_23c;

  float fStack_238;

  float afStack_234 [11];

  float local_208 [65];

  float local_104;

  float afStack_100 [64];

  

  FUN_007178b0(param_1,param_1);

  pfVar4 = local_208;

  iVar6 = 0x40;

  puVar8 = param_1;

  do {

    fVar9 = (float10)FUN_00715a00(*puVar8);

    *pfVar4 = (float)fVar9;

    pfVar4 = pfVar4 + 1;

    puVar8 = puVar8 + 4;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  fVar9 = (float10)FUN_00715a00(param_1[0xff]);

  *pfVar4 = (float)fVar9;

  (*(code *)PTR_memset_00af8a50)(&local_104,0,0x104);

  FUN_00714480(local_208,&local_104,0x80);

  fStack_23c = local_208[0] * DAT_00a11080;

  pfVar4 = local_208 + 1;

  iVar5 = param_2 >> 1;

  fStack_238 = local_104 * _DAT_00a1119c;

  pfVar3 = afStack_234;

  pfVar7 = afStack_100;

  pfVar2 = pfVar3;

  iVar6 = iVar5;

  if (0 < iVar5) {

    do {

      fVar1 = *pfVar4;

      pfVar4 = pfVar4 + 1;

      pfVar3 = pfVar2 + 2;

      iVar6 = iVar6 + -1;

      *pfVar2 = fVar1 * _DAT_00a1119c;

      pfVar2[1] = *pfVar7 * _DAT_00a1119c;

      pfVar2 = pfVar3;

      pfVar7 = pfVar7 + 1;

    } while (iVar6 != 0);

  }

  if (iVar5 * 2 != param_2) {

    *pfVar3 = *pfVar4 * _DAT_00a1119c;

  }

  FUN_00715200(&fStack_23c,param_2,param_4,param_5,&uStack_240);

  fVar9 = (float10)FUN_007159e0(uStack_240);

  *param_3 = (float)(fVar9 * (float10)DAT_00a0f298);

  return;

}
