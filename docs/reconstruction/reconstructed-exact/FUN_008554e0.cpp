// =============================================================================
// FUN_008554e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008554e0
// Address:   0x008554e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008554e0 @ 0x008554e0
// Stable ID: aa_008554e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076f5f0, FUN_007abe70, FUN_008554e0, __RTDynamicCast, fcos, fsin.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008554e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *extraout_EDX;

  float10 fVar2;

  float10 fVar3;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x500),0,

                          &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGCharacter::RTTI_Type_Descriptor,0);

  if ((((*(char *)(param_1 + 0x51c) != '\0') && (iVar1 != 0)) && (*(int *)(iVar1 + 0x48) != 0)) &&

     ((DAT_00d1d864 != '\0' && (*(char *)(param_1 + 0xd3) != '\0')))) {

    local_1c = 0.0;

    local_18 = g_flOne;

    local_14 = 0.0;

    FUN_0076f5f0(&local_c,&local_1c);

    fVar2 = (float10)(DAT_00d1d86c - _DAT_00d1d874) * (float10)_DAT_00aaa9f4 * (float10)DAT_00a0f298

    ;

    fVar3 = (float10)fsin(fVar2);

    local_1c = (float)((float10)local_c * fVar3);

    local_18 = (float)((float10)local_8 * fVar3);

    local_14 = (float)((float10)local_4 * fVar3);

    fVar2 = (float10)fcos(fVar2);

    local_10 = (float)fVar2;

    (**(code **)(*extraout_EDX + 0x20))(&local_1c);

  }

  FUN_007abe70(param_2,param_3);

  return;

}
