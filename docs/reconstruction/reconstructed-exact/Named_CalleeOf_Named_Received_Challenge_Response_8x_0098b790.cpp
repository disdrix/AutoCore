// =============================================================================
// Named_CalleeOf_Named_Received_Challenge_Response_8x_0098b790
// -----------------------------------------------------------------------------
// Stable ID: aa_0098b790
// Callee of Named_Received_Challenge_Response_8x (+3 other named callers)
// Address:   0x0098b790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Received_Challenge_Response_8x: callee helper. Evidence string: "Timer: %s Elapsed: %g ms". Supports parent flow (not a free-standing entry point). Named_Received_Challenge_Response_8x (+3 other named callers).
// Embedded strings (evidence):
//   - "Timer: %s Elapsed: %g ms"
//   - "secretSubKeyGen"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00783610×2, FUN_00424d60, FUN_0077a180, FUN_0077dcb0, FUN_0077f960, FUN_0077fb80, FUN_007834d0, FUN_00783aa0.
//  - Strings: "Timer: %s Elapsed: %g ms"; "secretSubKeyGen".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Received_Challenge_Response_8x (+3 other named callers)
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

void Named_CalleeOf_Named_Received_Challenge_Response_8x_0098b790(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_EBX;

  float10 fVar2;

  longlong lVar3;

  longlong lVar4;

  uint32_t /* width from decompiler */ local_138;

  uint8_t local_134 [32];

  uint8_t local_114 [276];

  

  if ((*(int *)(unaff_EBX + 0x10) == *(int *)(param_1 + 0x10)) &&

     (*(char *)(param_1 + 0x14) != '\0')) {

    local_138 = 0x800;

    lVar3 = FUN_00783610();

    FUN_0077a180(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc),&DAT_00d0d6a0,

                 &local_138);

    lVar4 = FUN_00783610();

    fVar2 = (float10)FUN_007834d0(lVar4 - lVar3);

    FUN_00783aa0("Timer: %s Elapsed: %g ms","secretSubKeyGen",(double)fVar2);

    FUN_0077dcb0(local_114);

    FUN_0077fb80(local_114,&DAT_00d0d6a0,local_138);

    FUN_0077f960(local_114,local_134);

    puVar1 = operator_new(0x18);

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar1[1] = 0;

      puVar1[2] = 0;

      *puVar1 = &PTR_LAB_009d7b00;

      puVar1[4] = 0x20;

      puVar1[3] = local_134;

      *(uint8_t *)(puVar1 + 5) = 0;

    }

    FUN_00424d60();

    *param_2 = puVar1;

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar1[2] = puVar1[2] + 1;

      return;

    }

  }

  else {

    *param_2 = 0;

  }

  return;

}
