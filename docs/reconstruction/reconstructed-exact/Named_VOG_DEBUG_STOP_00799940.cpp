// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CoCreateInstance, FUN_00799940, FUN_007a4480, _CxxThrowException.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00799940
// -----------------------------------------------------------------------------
// Stable ID: aa_00799940
// Address:   0x00799940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __fastcall Named_VOG_DEBUG_STOP_00799940(uint32_t /* width from decompiler */ *param_1)



{

  LPVOID *ppv;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *local_4;

  

  ppv = (LPVOID *)(param_1 + 1);

  *param_1 = &PTR_FUN_00a98338;

  param_1[3] = 0;

  param_1[4] = 0;

  *ppv = (LPVOID)0x0;

  param_1[2] = 0;

  local_4 = param_1;

  puVar1 = (uint32_t /* width from decompiler */ *)

           CoCreateInstance((IID *)&DAT_00a0f0e0,(LPUNKNOWN)0x0,1,(IID *)&DAT_00a0f0f0,ppv);

  if (-1 < (int)puVar1) {

    (**(code **)(*(int *)*ppv + 0xfc))(*ppv,0);

    return param_1;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  local_4 = puVar1;

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(&local_4,(ThrowInfo *)&DAT_00acc430);

}
