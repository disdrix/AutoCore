// =============================================================================
// Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_00513920
// -----------------------------------------------------------------------------
// Stable ID: aa_00513920
// Callee of Drive_CollisionListener_DoVehicleCollision
// Address:   0x00513920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_CollisionListener_DoVehicleCollision: vehicle collision helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00513920.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_CollisionListener_DoVehicleCollision
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_00513920(int *param_1,byte *param_2)



{

  byte *pbVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  uVar3 = g_abTfidInvalid_9CDF88._12_4_;

  uVar5 = g_abTfidInvalid_9CDF88._8_4_;

  uVar4 = g_abTfidInvalid_9CDF88._4_4_;

  uVar6 = g_abTfidInvalid_9CDF88._0_4_;

  iVar2 = (**(code **)(*param_1 + 0x214))();

  if (iVar2 != 0) {

    iVar2 = (**(code **)(*param_1 + 0x214))();

    pbVar1 = (byte *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);

    uVar6 = *(uint32_t /* width from decompiler */ *)pbVar1;

    uVar4 = *(uint32_t /* width from decompiler */ *)(pbVar1 + 4);

    uVar5 = *(uint32_t /* width from decompiler */ *)(pbVar1 + 8);

    uVar3 = *(uint32_t /* width from decompiler */ *)(pbVar1 + 0xc);

    iVar2 = (**(code **)(*param_1 + 0x214))();

    if (((*(uint *)(iVar2 + 0x228) & *(uint *)(iVar2 + 0x22c)) != 0xffffffff) ||

       ((char)*(uint32_t /* width from decompiler */ *)(iVar2 + 0x230) != '\0')) {

      iVar2 = (**(code **)(*param_1 + 0x214))();

      uVar6 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x228);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x22c);

      uVar5 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x230);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x234);

    }

  }

  *(uint32_t /* width from decompiler */ *)param_2 = uVar6;

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = uVar4;

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar5;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = uVar3;

  return;

}
