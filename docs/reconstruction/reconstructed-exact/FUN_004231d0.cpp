// =============================================================================
// FUN_004231d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004231d0
// Address:   0x004231d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004231d0 @ 0x004231d0
// Stable ID: aa_004231d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041d7b0, FUN_004231d0, FUN_004232c0, FUN_00437cd0.
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

int __fastcall

FUN_004231d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *unaff_retaddr;

  

  uVar1 = param_5;

  FUN_00437cd0();

  iVar2 = (**(code **)*param_2)(param_2,&DAT_00a860ac);

  if (iVar2 < 0) {

    FUN_0041d7b0();

    return iVar2;

  }

  FUN_004232c0();

  iVar2 = *param_3 + -8 + param_3[1] * 8;

  *(uint8_t *)(iVar2 + 4) = 1;

  (**(code **)(*unaff_retaddr + 0x10))(unaff_retaddr,2,1,&stack0xffffffc0,uVar1,iVar2,0);

                    /* WARNING: Subroutine does not return */

  operator_delete(&param_5);

}
