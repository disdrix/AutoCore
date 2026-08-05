// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Sending_Chal_00784000
// -----------------------------------------------------------------------------
// Stable ID: aa_00784000
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response
// Address:   0x00784000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, for×2, while×1.
//  - Notable callees: FUN_00784000.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Sending_Chal_00784000(int param_1,uint param_2,ushort *param_3)



{

  uint *in_EAX;

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  uVar2 = *in_EAX;

  uVar1 = in_EAX[1];

  if (uVar2 < uVar1) {

    uVar1 = uVar1 - uVar2;

  }

  else if (((char)in_EAX[4] == '\0') && (uVar2 == uVar1)) {

    uVar1 = 0;

  }

  else {

    uVar1 = uVar1 + (in_EAX[3] - uVar2);

  }

  if (uVar1 < param_2) {

    return 0;

  }

  *param_3 = 0;

  uVar2 = *in_EAX;

  uVar1 = in_EAX[1];

  if (uVar2 < uVar1) {

    uVar4 = uVar1 - uVar2;

  }

  else {

    uVar4 = in_EAX[3] - uVar2;

    if (((char)in_EAX[4] == '\0') && (uVar2 == uVar1)) {

      uVar4 = 0;

    }

  }

  uVar3 = param_2;

  if (uVar4 < param_2) {

    if (uVar2 < uVar1) {

      uVar3 = uVar1 - uVar2;

    }

    else {

      uVar3 = in_EAX[3] - uVar2;

      if (((char)in_EAX[4] == '\0') && (uVar2 == uVar1)) {

        uVar3 = 0;

      }

    }

  }

  while ((uVar3 != 0 && (*param_3 < param_2))) {

    puVar5 = (uint32_t /* width from decompiler */ *)(in_EAX[5] + *in_EAX);

    puVar7 = (uint32_t /* width from decompiler */ *)((uint)*param_3 + param_1);

    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar7 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    *param_3 = *param_3 + (short)uVar3;

    *in_EAX = *in_EAX + uVar3;

    uVar2 = in_EAX[3];

    if (uVar2 <= *in_EAX) {

      *in_EAX = 0;

    }

    uVar1 = *in_EAX;

    uVar4 = in_EAX[1];

    if (uVar1 == uVar4) {

      *(uint8_t *)(in_EAX + 4) = 0;

    }

    if (uVar1 < uVar4) {

      uVar6 = uVar4 - uVar1;

    }

    else {

      uVar6 = uVar2 - uVar1;

      if (((char)in_EAX[4] == '\0') && (uVar1 == uVar4)) {

        uVar6 = 0;

      }

    }

    uVar3 = param_2 - *param_3;

    if (uVar6 < uVar3) {

      if (uVar1 < uVar4) {

        uVar3 = uVar4 - uVar1;

      }

      else {

        uVar3 = uVar2 - uVar1;

        if (((char)in_EAX[4] == '\0') && (uVar1 == uVar4)) {

          uVar3 = 0;

        }

      }

    }

  }

  return 1;

}
