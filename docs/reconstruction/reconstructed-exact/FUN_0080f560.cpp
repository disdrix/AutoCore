// =============================================================================
// FUN_0080f560
// -----------------------------------------------------------------------------
// Stable ID: aa_0080f560
// Address:   0x0080f560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080f560 @ 0x0080f560
// Stable ID: aa_0080f560
// Embedded strings (evidence for future rename):
//   - "Friend not found!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: __RTDynamicCast×2, FUN_00573c70, FUN_007a69d0, FUN_007a6de0, FUN_0080f560, FUN_008f8200.
//  - Strings: "Friend not found!".
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

void FUN_0080f560(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EDI;

  

  FUN_007a69d0();

  if (*(char *)(unaff_EDI + 4) == '\0') {

    uVar4 = FUN_007a6de0("Friend not found!",0xffffffff);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar4,0);

    }

  }

  else {

    iVar1 = *(int *)(in_EAX + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    FUN_00573c70(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1),

                 *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

    if (*(int *)(in_EAX + 0x1038) != 0) {

      piVar3 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,

                                      &CDlgTabsSocial::RTTI_Type_Descriptor,0);

      (**(code **)(*piVar3 + 0x448))();

    }

    if (*(int *)(in_EAX + 0x108c) != 0) {

      piVar3 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x108c),0,&CVOGDialog::RTTI_Type_Descriptor,

                                      &CDlgFriendsDetails::RTTI_Type_Descriptor,0);

                    /* WARNING: Could not recover jumptable at 0x0080f5f2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar3 + 0x448))();

      return;

    }

  }

  return;

}
