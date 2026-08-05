// =============================================================================
// FUN_0056b0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b0a0
// Address:   0x0056b0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b0a0 @ 0x0056b0a0
// Stable ID: aa_0056b0a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0051b230, FUN_0056b0a0, __RTDynamicCast.
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

int __fastcall FUN_0056b0a0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  uVar2 = FUN_0051b230(0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                       &CVOGWeapon::RTTI_Type_Descriptor,0);

  iVar3 = __RTDynamicCast(uVar2);

  if (iVar3 != 0) {

    *(uint8_t *)(iVar3 + 0xc4) = *(uint8_t *)(param_1 + -0x8c);

    *(uint16_t *)(iVar3 + 0xd4) = *(uint16_t *)(param_1 + -0x7c);

    *(uint8_t *)(iVar3 + 0xcc) = *(uint8_t *)(param_1 + -0x84);

    iVar1 = *(int *)(param_1 + -0x80);

    *(int *)(iVar3 + 0xd0) = iVar1;

    if (iVar1 == 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xd0) = 1;

    }

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xdc) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x74);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xe0) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x70);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xe4) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xe8) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x68);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xec) = *(uint32_t /* width from decompiler */ *)(param_1 + -100);

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xc4 + iVar3) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x8c + param_1);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x124) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x128) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x28);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 300) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x24);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x130) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x20);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x134) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x138) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x18);

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x218))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa8 + param_1));

    return *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

  }

  return 0;

}
