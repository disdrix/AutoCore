// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: strstr×3, FUN_0096a230, vog_LogMessage.
//  - Strings: "Diffuse"; "Ambient"; "Emissive"; ",0xbe,

                 3,".
//  - Return sites: 3.

// =============================================================================
// Named_effGlobalEffect_0096a230
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a230
// Address:   0x0096a230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effGlobalEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_effGlobalEffect_0096a230(void)



{

  int *piVar1;

  int iVar2;

  char *pcVar3;

  int unaff_EBX;

  float *unaff_ESI;

  float fVar4;

  char *pcStack_28;

  

  if (*(int *)(*(int *)(unaff_EBX + 4) + 0xc) == 0) {

    iVar2 = -0x7789f794;

  }

  else {

    piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 0xc);

    iVar2 = (**(code **)(*piVar1 + 0x54))(piVar1);

  }

  if (-1 < (int)-(uint)(iVar2 != 0)) {

    if (*(int *)(*(int *)(unaff_EBX + 4) + 0xc) != 0) {

      piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 0xc);

      (**(code **)(*piVar1 + 0x10))(piVar1);

    }

    if (pcStack_28 != (char *)0x0) {

      pcVar3 = strstr(pcStack_28,"Diffuse");

      if (((pcVar3 == (char *)0x0) && (pcVar3 = strstr(pcStack_28,"Ambient"), pcVar3 == (char *)0x0)

          ) && (pcVar3 = strstr(pcStack_28,"Emissive"), pcVar3 == (char *)0x0)) {

        return 0;

      }

      fVar4 = g_flOne / DAT_00afa2f8;

      *unaff_ESI = *unaff_ESI * fVar4;

      unaff_ESI[1] = unaff_ESI[1] * fVar4;

      unaff_ESI[2] = unaff_ESI[2] * fVar4;

    }

    return 0;

  }

  *unaff_ESI = DAT_00afdf30;

  unaff_ESI[1] = DAT_00afdf34;

  unaff_ESI[2] = DAT_00afdf38;

  unaff_ESI[3] = DAT_00afdf3c;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effGlobalEffect.cpp",0xbe,

                 3,"Invalid Param Handle");

  return 0xffffffff;

}
