// =============================================================================
// FUN_0082fa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fa60
// Address:   0x0082fa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082fa60 @ 0x0082fa60
// Stable ID: aa_0082fa60
// Embedded strings (evidence for future rename):
//   - "Invite To Clan"
//   - "i_m_int_2d_btn_generic.xml"
//   - "Kick From Clan"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004c22a0×2, FUN_0082f7d0×2, FUN_0082fa60.
//  - Strings: "Invite To Clan"; "i_m_int_2d_btn_generic.xml"; "Kick From Clan".
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

void FUN_0082fa60(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EBX;

  

  if (((*(int *)(in_EAX + 0x6b4) < 1) || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) &&

     (DAT_00d1da30 != 0)) {

    iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    iVar1 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + DAT_00d1b6d8),

                         *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + DAT_00d1b6d8));

    iVar2 = *(int *)(*(int *)(in_EAX + 4) + 4);

    iVar2 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + in_EAX),

                         *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + in_EAX));

    if (iVar1 != 0) {

      if (iVar2 == 0) {

        if (1 < *(int *)(iVar1 + 0x24)) {

          uVar3 = FUN_0082f7d0("Invite To Clan","i_m_int_2d_btn_generic.xml",0,0x11173);

          *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x548) = uVar3;

          return;

        }

      }

      else if (*(int *)(iVar2 + 0x24) < *(int *)(iVar1 + 0x24)) {

        uVar3 = FUN_0082f7d0("Kick From Clan","i_m_int_2d_btn_generic.xml",0,0x11174);

        *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x54c) = uVar3;

      }

    }

  }

  return;

}
