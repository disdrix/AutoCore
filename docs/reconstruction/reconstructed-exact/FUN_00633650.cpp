// =============================================================================
// FUN_00633650
// -----------------------------------------------------------------------------
// Stable ID: aa_00633650
// Address:   0x00633650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633650 @ 0x00633650
// Stable ID: aa_00633650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Object_ResolveFromTFID×2, CONCAT31, CVOGHBBase_RescheduleAfterFire, FUN_004d7e30, FUN_00633650.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall FUN_00633650(CVOGHBBase *param_1,uint32_t /* width from decompiler */ *param_2)



{

  void *pvVar1;

  void *pvVar2;

  uint *pOutNextDelayMs;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0x633674;

  pvVar1 = Object_ResolveFromTFID((TFID_16 *)&param_1[1].nPeriodMs);

  local_14 = 0x633695;

  pvVar2 = Object_ResolveFromTFID((TFID_16 *)&param_1[1].pOwnerObject);

  if ((pvVar1 != (void *)0x0) && (pvVar2 != (void *)0x0)) {

    local_20 = DAT_009e35a0;

    local_1c = DAT_009e35a4;

    local_18 = DAT_009e35a8;

    local_14 = DAT_009e35ac;

    FUN_004d7e30(CONCAT31((int3)((uint)&local_20 >> 8),*(uint8_t *)&param_1[1].pVTable),

                 param_1[1].nRefOrFlags,pvVar1,pvVar2,1,0,0);

    local_14 = 0x6336f8;

    CVOGHBBase_RescheduleAfterFire(param_1,pOutNextDelayMs);

    return param_2;

  }

  *param_2 = DAT_00af4ea0;

  return param_2;

}
