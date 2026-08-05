// =============================================================================
// FUN_00753060
// -----------------------------------------------------------------------------
// Stable ID: aa_00753060
// Address:   0x00753060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753060 @ 0x00753060
// Stable ID: aa_00753060
// Embedded strings (evidence for future rename):
//   - "Diffuse"
//   - "Ambient"
//   - "Emissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: strstr×3, FUN_00752a30, FUN_00753060.
//  - Strings: "Diffuse"; "Ambient"; "Emissive".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00753060(int param_1)



{

  int in_EAX;

  char *pcVar1;

  float *pfVar2;

  float *unaff_EDI;

  float fVar3;

  char *local_28;

  

  if (param_1 < 0) {

    *unaff_EDI = DAT_00afdf30;

    unaff_EDI[1] = DAT_00afdf34;

    unaff_EDI[2] = DAT_00afdf38;

    unaff_EDI[3] = DAT_00afdf3c;

    return 0xffffffff;

  }

  pfVar2 = (float *)((uint)*(ushort *)(*(int *)(*(int *)(in_EAX + 8) + 0x10) + 4 + param_1 * 8) +

                    *(int *)(in_EAX + 0xc));

  *unaff_EDI = *pfVar2;

  unaff_EDI[1] = pfVar2[1];

  unaff_EDI[2] = pfVar2[2];

  unaff_EDI[3] = pfVar2[3];

  FUN_00752a30(in_EAX,param_1);

  if (local_28 != (char *)0x0) {

    pcVar1 = strstr(local_28,"Diffuse");

    if (((pcVar1 == (char *)0x0) && (pcVar1 = strstr(local_28,"Ambient"), pcVar1 == (char *)0x0)) &&

       (pcVar1 = strstr(local_28,"Emissive"), pcVar1 == (char *)0x0)) {

      return 0;

    }

    fVar3 = g_flOne / DAT_00afa2f8;

    *unaff_EDI = *unaff_EDI * fVar3;

    unaff_EDI[1] = unaff_EDI[1] * fVar3;

    unaff_EDI[2] = unaff_EDI[2] * fVar3;

  }

  return 0;

}
