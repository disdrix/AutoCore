// =============================================================================
// Mission_Invalid_Position_request_prefixes_sent_GetP
// -----------------------------------------------------------------------------
// Stable ID: aa_005c98f0
// Address:   0x005c98f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Mission_Invalid_Position_request_prefixes_sent_GetP @ 0x005c98f0
// Stable ID: aa_005c98f0
// Embedded strings (evidence for future rename):
//   - "*****************************Invalid Position request(%d, # of prefixes = %d) sent to GetP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT22×2, FUN_004ccf30, Mission_Invalid_Position_request_prefixes_sent_GetP, FUN_007a4480, request.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "*****************************Invalid Position request(%d, # of prefixes = %d) sent to GetP"
 * Domain alias of FUN_005c98f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Mission_Invalid_Position_request_prefixes_sent_GetP(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint16_t extraout_var;

  

  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))

                    ();

  if (uVar2 <= param_2) {

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60)

            )();

    FUN_007a4480(0xffffffff,

                 "*****************************Invalid Position request(%d, # of prefixes = %d) sent to GetPrefix"

                 ,param_2,uVar4);

    return CONCAT22(extraout_var,0xffff);

  }

  iVar1 = *(int *)(*(int *)(param_1 + -0x44) + 4);

  if ((iVar1 != 0) &&

     (iVar3 = *(int *)(*(int *)(param_1 + -0x44) + 8) - iVar1, param_2 < (uint)(iVar3 >> 2))) {

    return CONCAT22((short)(iVar3 >> 0x12),*(uint16_t *)(iVar1 + param_2 * 4));

  }

                    /* WARNING: Subroutine does not return */

  FUN_004ccf30();

}
