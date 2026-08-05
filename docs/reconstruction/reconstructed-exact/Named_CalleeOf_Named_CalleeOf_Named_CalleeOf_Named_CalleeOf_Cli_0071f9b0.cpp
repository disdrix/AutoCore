// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0071f9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f9b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn
// Address:   0x0071f9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0071f9b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn
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

void __fastcall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0071f9b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint unaff_EDI;

  

  fVar1 = g_flOne;

  unaff_ESI[0x60] = DAT_00a110d8;

  uVar2 = DAT_00a27c24;

  unaff_ESI[6] = param_1;

  unaff_ESI[5] = param_4;

  unaff_ESI[0x61] = uVar2;

  *unaff_ESI = &PTR_FUN_00aa952c;

  unaff_ESI[7] = unaff_EDI;

  unaff_ESI[8] = param_2;

  unaff_ESI[9] = 0;

  unaff_ESI[10] = 0;

  unaff_ESI[0xb] = param_5;

  *(uint8_t *)(unaff_ESI + 0xd) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x37) = 0;

  *(uint8_t *)(unaff_ESI + 0xe) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x3a) = 0;

  unaff_ESI[0x53] = 0;

  unaff_ESI[0x62] = 0;

  unaff_ESI[99] = fVar1;

  unaff_ESI[100] = fVar1;

  unaff_ESI[0x65] = 0;

  unaff_ESI[0x66] = 0;

  unaff_ESI[0x67] = 0;

  unaff_ESI[0x68] = 0;

  unaff_ESI[0x69] = 0;

  unaff_ESI[0x6a] = 0;

  unaff_ESI[0x6b] = 0;

  unaff_ESI[0x70] = 0;

  *(uint8_t *)(unaff_ESI + 0x71) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x1c5) = 0;

  unaff_ESI[0x72] = 0;

  pvVar3 = operator_new__(unaff_EDI * 4);

  unaff_ESI[4] = pvVar3;

  if (pvVar3 != (void *)0x0) {

    uVar4 = 0;

    if (unaff_EDI != 0) {

      do {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[4] + uVar4 * 4) = *(uint32_t /* width from decompiler */ *)(param_3 + uVar4 * 4);

        uVar4 = uVar4 + 1;

      } while (uVar4 < unaff_EDI);

    }

    if (param_4 != 0) {

      unaff_ESI[0x53] = 2;

      return;

    }

  }

  return;

}
