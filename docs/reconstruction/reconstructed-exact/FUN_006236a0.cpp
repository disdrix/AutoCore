// =============================================================================
// FUN_006236a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006236a0
// Address:   0x006236a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006236a0 @ 0x006236a0
// Stable ID: aa_006236a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004d7e30, FUN_006236a0, Object_ResolveFromTFID, __RTDynamicCast.
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

int __thiscall FUN_006236a0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  float fVar1;

  void *pvVar2;

  int iVar3;

  TFID_16 local_10;

  

  iVar3 = *(int *)(param_1 + 0x6c0);

  local_10.dwCoidLo = *(uint *)(iVar3 + 0x108);

  local_10.dwCoidHi = *(uint *)(iVar3 + 0x10c);

  local_10._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x110);

  local_10._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x114);

  pvVar2 = Object_ResolveFromTFID(&local_10);

  if (pvVar2 != (void *)0x0) {

    fVar1 = *(float *)(param_1 + 0x104);

    iVar3 = __RTDynamicCast(pvVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGCreature::RTTI_Type_Descriptor,0);

    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x250), iVar3 != 0)) {

      pvVar2 = (void *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

    }

    FUN_004d7e30(0,-(int)((float)param_4 * fVar1),*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),pvVar2,1,0,0,

                 DAT_009e3048,DAT_009e304c,DAT_009e3050,DAT_009e3054,0);

    return param_4;

  }

  return param_4;

}
