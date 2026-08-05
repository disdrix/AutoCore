// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_00861200, FUN_00941b20.
//  - Strings: "This equipment cannot be changed at this time.".
//  - Return sites: 2.

// =============================================================================
// Inv_This_equipment_cannot_be_changed_at_this_time
// -----------------------------------------------------------------------------
// Stable ID: aa_00861200
// Address:   0x00861200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "This equipment cannot be changed at this time."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Inv_This_equipment_cannot_be_changed_at_this_time(int *param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if ((param_1 != (int *)0x0) && (*(int *)(in_EAX + 0x56c) != 0)) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x56c) + 4);

    uVar4 = 1;

    uVar1 = (**(code **)(*param_1 + 0x3ac))(uVar3,1);

    uVar2 = FUN_00941b20(uVar1,uVar3,uVar4);

    return uVar2;

  }

  FUN_007a69d0();

  uVar5 = 0;

  uVar4 = 1;

  uVar1 = 0xffffffff;

  uVar3 = FUN_007a6de0("This equipment cannot be changed at this time.",0xffffffff);

  uVar2 = FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar1,uVar4,uVar5);

  return uVar2 & 0xffffff00;

}
