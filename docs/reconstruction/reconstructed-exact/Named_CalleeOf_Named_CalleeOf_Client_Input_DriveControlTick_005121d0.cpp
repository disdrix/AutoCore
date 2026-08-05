// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_005121d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005121d0
// Callee of Named_CalleeOf_Client_Input_DriveControlTick
// Address:   0x005121d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Legacy alias path only. Prefer IsPlayerTargetingLinkAndDestroy / FUN_005121d0.cpp.
// Dual-sealed 2026-07-29 (W16-O): HB purge predicate (RTTI CVOGHBPlayerTargetingLink + vtbl+0x18).
// Sole xref: Object_SetSelectedTarget @ 0x0051733b (not a direct drive-tick leaf).
// Readability: control flow preserved from Ghidra decompile; ABI ret 0xC (3 formals).

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005121d0, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_DriveControlTick
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_005121d0(int *param_1)



{

  int iVar1;

  

  iVar1 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                          &CVOGHBPlayerTargetingLink::RTTI_Type_Descriptor,0);

  if (iVar1 != 0) {

    (**(code **)(*param_1 + 0x18))(1,0);

    return 1;

  }

  return 0;

}
