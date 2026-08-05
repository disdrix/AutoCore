// =============================================================================
// FUN_00753160
// -----------------------------------------------------------------------------
// Stable ID: aa_00753160
// Address:   0x00753160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753160 @ 0x00753160
// Stable ID: aa_00753160
// Embedded strings (evidence for future rename):
//   - "Diffuse"
//   - "Ambient"
//   - "Emissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×1.
//  - Notable callees: strstr×3, FUN_00752a30, FUN_00753160.
//  - Strings: "Diffuse"; "Ambient"; "Emissive".
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

uint32_t /* width from decompiler */ FUN_00753160(int param_1,float param_2,float param_3,float param_4,float param_5)



{

  int iVar1;

  int *piVar2;

  char *pcVar3;

  float *pfVar4;

  int unaff_EDI;

  char *local_28;

  

  if (param_1 < 0) {

    return 0xffffffff;

  }

  FUN_00752a30(unaff_EDI,param_1);

  if (local_28 != (char *)0x0) {

    pcVar3 = strstr(local_28,"Diffuse");

    if (pcVar3 == (char *)0x0) {

      pcVar3 = strstr(local_28,"Ambient");

      if (pcVar3 == (char *)0x0) {

        pcVar3 = strstr(local_28,"Emissive");

        if (pcVar3 == (char *)0x0) goto LAB_007531f1;

      }

    }

    param_2 = DAT_00afa2f8 * param_2;

    param_3 = DAT_00afa2f8 * param_3;

    param_4 = DAT_00afa2f8 * param_4;

  }

LAB_007531f1:

  iVar1 = *(int *)(unaff_EDI + 8);

  pfVar4 = (float *)((uint)*(ushort *)(*(int *)(iVar1 + 0x10) + 4 + param_1 * 8) +

                    *(int *)(unaff_EDI + 0xc));

  *pfVar4 = param_2;

  pfVar4[1] = param_3;

  pfVar4[2] = param_4;

  pfVar4[3] = param_5;

  if (DAT_00afe038 == *(int *)(unaff_EDI + 0xc)) {

    piVar2 = *(int **)(iVar1 + 0xc);

    (**(code **)(*piVar2 + 0x50))

              (piVar2,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_EDI + 8) + 0x10) + param_1 * 8),

               &param_2,0xffffffff);

  }

  return 0;

}
