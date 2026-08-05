// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_00784340
// -----------------------------------------------------------------------------
// Stable ID: aa_00784340
// Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
// Address:   0x00784340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Sending_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, goto×1.
//  - Notable callees: FUN_00784230×2, FUN_00784340.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
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

uint __fastcall

Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_00784340(uint32_t /* width from decompiler */ param_1,uint *param_2,uint32_t /* width from decompiler */ param_3,uint param_4,char param_5)



{

  uint uVar1;

  uint in_EAX;

  uint uVar2;

  uint uVar3;

  

  uVar3 = param_4 & 0xffff;

  if (0x10000 < uVar3) {

    return in_EAX & 0xffffff00;

  }

  if (param_5 == '\0') {

    if (uVar3 <= param_2[3]) {

      if ((char)param_2[4] == '\0') {

        uVar1 = param_2[1];

        uVar2 = *param_2;

        if (uVar1 < uVar2) {

          uVar2 = uVar2 - uVar1;

        }

        else {

          uVar2 = (uVar2 - uVar1) + param_2[3];

        }

      }

      else {

        uVar2 = 0;

      }

      if (uVar2 < uVar3) {

        return uVar2 & 0xffffff00;

      }

LAB_007843c9:

      uVar3 = FUN_00784230(param_3,param_4);

      return uVar3;

    }

  }

  else if (uVar3 + 2 <= param_2[3]) {

    if ((char)param_2[4] == '\0') {

      uVar1 = param_2[1];

      uVar2 = *param_2;

      if (uVar1 < uVar2) {

        in_EAX = uVar2 - uVar1;

      }

      else {

        in_EAX = (uVar2 - uVar1) + param_2[3];

      }

    }

    else {

      in_EAX = 0;

    }

    if (uVar3 + 2 <= in_EAX) {

      in_EAX = FUN_00784230(&param_4,2);

      if ((char)in_EAX != '\0') goto LAB_007843c9;

    }

  }

  return in_EAX & 0xffffff00;

}
