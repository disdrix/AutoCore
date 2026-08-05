// =============================================================================
// FUN_00931be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00931be0
// Address:   0x00931be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931be0 @ 0x00931be0
// Stable ID: aa_00931be0
// Embedded strings (evidence for future rename):
//   - "Invalid crafting object."
//   - "Object not found on COList."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, Client_SendSectorPacket, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_00931be0.
//  - Strings: "Invalid crafting object."; "Object not found on COList.".
//  - Return sites: 3.

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

void FUN_00931be0(void)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ local_10;

  byte local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  FUN_007a69d0();

  uVar1 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + (uint)(byte)DAT_00d1d914 * 8);

  uVar2 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + (uint)(byte)DAT_00d1d914 * 8);

  if ((uVar1 & uVar2) == 0xffffffff) {

    pcVar5 = "Invalid crafting object.";

  }

  else {

    iVar4 = CVOGReaction_ResolveObjectTarget(1,uVar1,uVar2);

    if (iVar4 != 0) {

      local_10 = 0x2051;

      local_c = (byte)DAT_00d1d914;

      local_8 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

      local_4 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

      Client_SendSectorPacket(&DAT_00d1a840,0x10,&local_10);

      return;

    }

    pcVar5 = "Object not found on COList.";

  }

  uVar8 = 0;

  uVar6 = 0xffffffff;

  uVar7 = 1;

  uVar3 = FUN_007a6de0(pcVar5,0xffffffff);

  FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar6,uVar7,uVar8);

  return;

}
