// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_00925580
// -----------------------------------------------------------------------------
// Stable ID: aa_00925580
// Callee of Client_Input_PollBoundActions
// Address:   0x00925580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: Client_SendSectorPacket, FUN_00925580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_00925580(void)



{

  char cVar1;

  uint *unaff_ESI;

  uint32_t /* width from decompiler */ auStack_30 [2];

  uint uStack_28;

  uint uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  float fStack_8;

  

  if ((((DAT_00d1b4b0 == '\0') && (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0)) &&

      ((*(uint *)(DAT_00d1b6d8 + 0xcd8) & *(uint *)(DAT_00d1b6d8 + 0xcdc)) == 0xffffffff)) &&

     ((*unaff_ESI & unaff_ESI[1]) != 0xffffffff)) {

    cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                        0x194))();

    if (cVar1 == '\0') {

      cVar1 = (**(code **)(*DAT_00d1b958 + 0x3d8))();

      if (cVar1 == '\0') {

        cVar1 = (**(code **)(*DAT_00d1b95c + 0x3d8))();

        if (cVar1 == '\0') {

          uStack_28 = *unaff_ESI;

          uStack_24 = unaff_ESI[1];

          uStack_18 = 0;

          uStack_1c = 0;

          uStack_20 = 0;

          uStack_c = 0;

          uStack_10 = 0;

          uStack_14 = 0;

          fStack_8 = g_flMsToSeconds_Inferred;

          auStack_30[0] = 0x2055;

          Client_SendSectorPacket(&DAT_00d1a840,0x30,auStack_30);

        }

      }

    }

  }

  return;

}
