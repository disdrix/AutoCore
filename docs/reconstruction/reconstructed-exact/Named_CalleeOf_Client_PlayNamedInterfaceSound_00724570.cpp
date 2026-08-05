// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_00724570
// -----------------------------------------------------------------------------
// Stable ID: aa_00724570
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x00724570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007227e0, FUN_007239b0, FUN_00724570.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */ __fastcall

Named_CalleeOf_Client_PlayNamedInterfaceSound_00724570(uint32_t /* width from decompiler */ *param_1,uint8_t param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint8_t param_5,uint8_t param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  int unaff_EDI;

  float10 extraout_ST0;

  float fVar3;

  

  if (*(char *)(unaff_ESI + 600) != '\0') {

    *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x36) = param_6;

    *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x34) = 0;

    iVar2 = *(int *)(unaff_ESI + 0x31c + unaff_EDI * 4);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40) = param_3;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = param_4;

    *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x35) = param_5;

    iVar2 = *(int *)(unaff_ESI + 0x31c + unaff_EDI * 4);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x150) = *param_1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x154) = param_1[1];

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x158) = param_1[2];

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x15c) = param_1[3];

    *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x37) = param_2;

    *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x39) = param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x1b8) = param_7;

    if (*(char *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x36) != '\0') {

      iVar2 = FUN_007227e0(0);

      fVar3 = g_flOne;

      if ((float)extraout_ST0 <= g_flOne) {

        fVar3 = (float)extraout_ST0;

      }

      *(float *)(iVar2 + 0x1a4) = fVar3;

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x180) = param_8;

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x184) = param_9;

    cVar1 = FUN_007239b0(unaff_ESI);

    if (cVar1 != '\0') {

      *(uint32_t /* width from decompiler */ *)

       (*(int *)(unaff_ESI + 0x70 + *(int *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x30) * 4

                ) + 0x10c) = 1;

      *(uint32_t /* width from decompiler */ *)

       (*(int *)(unaff_ESI + 0x70 + *(int *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x30) * 4

                ) + 0x110) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3dc);

      *(uint8_t *)(*(int *)(unaff_ESI + 0x31c + unaff_EDI * 4) + 0x3a) = 1;

    }

  }

  return 0;

}
