// =============================================================================
// Named_CalleeOf_Named_SpeexCodec_00702970
// -----------------------------------------------------------------------------
// Stable ID: aa_00702970
// Callee of Named_SpeexCodec
// Address:   0x00702970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SpeexCodec: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00703190×2, FUN_00702970, FUN_007031b0, realloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SpeexCodec
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

void Named_CalleeOf_Named_SpeexCodec_00702970(int *param_1,int param_2,size_t param_3)



{

  void *pvVar1;

  int iVar2;

  

  if (param_1[6] < (int)param_3) {

    FUN_007031b0(s__Packet_if_larger_than_allocated_00af58df + 1,param_3);

    if (param_1[4] == 0) {

      FUN_00703190(s_Do_not_own_input_buffer__truncat_00af593c);

      param_3 = param_1[6];

    }

    else {

      pvVar1 = realloc((void *)*param_1,param_3);

      if (pvVar1 == (void *)0x0) {

        param_3 = param_1[6];

        FUN_00703190(s_Could_not_resize_input_buffer__t_00af590c);

      }

      else {

        param_1[6] = param_3;

        *param_1 = (int)pvVar1;

      }

    }

  }

  iVar2 = 0;

  if (0 < (int)param_3) {

    do {

      *(uint8_t *)(iVar2 + *param_1) = *(uint8_t *)(iVar2 + param_2);

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_3);

  }

  param_1[1] = param_3 * 8;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[5] = 0;

  return;

}
