// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00571010×2, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_00809c70.
//  - Strings: "Tried to modify an object that isn\'t in inventory.".
//  - Return sites: 2.

// =============================================================================
// Client_OnInventoryModifyMissingObject
// -----------------------------------------------------------------------------
// Purpose:  Error path when modifying an object that is not present in inventory.
//
// Address:  0x00809c70  (autoassault.exe, image base 0x400000)
// Stable:   aa_00809c70
// System:   inventory-transfer
//
// String evidence: "Tried to modify an object that isn't in inventory."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00809c70.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00809c70 using string evidence: "Tried to modify an object that isn't in inventory."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __fastcall Client_OnInventoryModifyMissingObject(uint32_t /* width from decompiler */ param_1)

{

  int *in_EAX;

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  FUN_007a69d0();

  piVar1 = (int *)FUN_00571010(in_EAX[6],in_EAX[7]);

  if (piVar1 == (int *)0x0) {

    piVar1 = (int *)FUN_00571010(in_EAX[6],in_EAX[7]);

    if (piVar1 == (int *)0x0) {

      uVar5 = 1;

      uVar4 = 0xffffffff;

      uVar2 = FUN_007a6de0("Tried to modify an object that isn\'t in inventory.",0xffffffff);

      FUN_007fdfb0(param_1,uVar2,uVar4,uVar5,piVar1);

      return;

    }

  }

  iVar3 = 5;

  do {

    in_EAX = in_EAX + 1;

    if (*in_EAX != -1) {

      (**(code **)(*piVar1 + 0x58))();

      (**(code **)(*piVar1 + 0x6c))(*in_EAX,1);

    }

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
