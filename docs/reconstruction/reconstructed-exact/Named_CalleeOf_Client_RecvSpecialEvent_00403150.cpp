// =============================================================================
// Named_CalleeOf_Client_RecvSpecialEvent_00403150
// -----------------------------------------------------------------------------
// Stable ID: aa_00403150
// Callee of Client_RecvSpecialEvent
// Address:   0x00403150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvSpecialEvent: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT31×2, FUN_00403150, FUN_004069f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvSpecialEvent
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

void Named_CalleeOf_Client_RecvSpecialEvent_00403150(uint *param_1)



{

  uint *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  puVar1 = param_1;

  puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(in_EAX + 4) + 4);

  param_1 = (uint *)CONCAT31(param_1._1_3_,1);

  if (*(char *)((int)puVar2 + 0x29) == '\0') {

    do {

      if (((int)puVar2[5] < (int)puVar1[1]) ||

         (((int)puVar2[5] <= (int)puVar1[1] && ((uint)puVar2[4] <= *puVar1)))) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar2[2];

        param_1 = (uint *)((uint)param_1._1_3_ << 8);

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

        param_1 = (uint *)CONCAT31(param_1._1_3_,1);

      }

    } while (*(char *)((int)puVar2 + 0x29) == '\0');

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004069f0(&param_1,param_1,puVar1);

  *unaff_ESI = *puVar2;

  *(uint8_t *)(unaff_ESI + 1) = 1;

  return;

}
