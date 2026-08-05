// =============================================================================
// Named_Set_ornament_unhappy_type_CBID_COID
// -----------------------------------------------------------------------------
// Stable ID: aa_004fe620
// Address:   0x004fe620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Set_ornament_unhappy_type_CBID_COID @ 0x004fe620
// Stable ID: aa_004fe620
// Embedded strings (evidence for future rename):
//   - "Set ornament of unhappy type: CBID:%d COID:%I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_004fe380×2, FUN_004fbb50, FUN_004fdcb0, Named_Set_ornament_unhappy_type_CBID_COID, FUN_00512670, FUN_007a4480, FUN_00989270.
//  - Strings: "Set ornament of unhappy type: CBID:%d COID:%I64d".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Set ornament of unhappy type: CBID:%d COID:%I64d"
 * Domain alias of FUN_004fe620 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Set_ornament_unhappy_type_CBID_COID(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,char param_4)



{

  int iVar1;

  float fVar2;

  int iVar3;

  int *piVar4;

  

  FUN_00512670();

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x26c);

  }

  iVar3 = *(int *)(param_1 + 0x26c);

  if (iVar3 != 0) {

    if (param_4 == '\0') {

      FUN_004fbb50(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

    }

    iVar3 = *(int *)(param_1 + 0x26c);

    if (iVar3 != 0) {

      iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

    }

    FUN_004fe380(iVar3,0);

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x26c) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0x26c)) + 0x158))(0);

  }

  *(int *)(param_1 + 0x26c) = param_2;

  if (param_2 != 0) {

    iVar3 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2);

    if ((*(int *)(iVar3 + 0x38) != 6) || (*(short *)(*(int *)(iVar3 + 0x3c) + 0x3f4) != 10)) {

      iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

      iVar3 = iVar1 + param_2;

      FUN_007a4480(1,"Set ornament of unhappy type: CBID:%d COID:%I64d",

                   *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xac) + 0x34),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_2));

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x158))

              (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

    iVar3 = *(int *)(param_1 + 0x26c);

    if (iVar3 != 0) {

      iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

    }

    FUN_004fdcb0(iVar3);

    iVar3 = *(int *)(param_1 + 0x26c);

    if (iVar3 != 0) {

      iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

    }

    FUN_004fe380(iVar3,1);

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x218))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));

  }

  if ((((*(int *)(param_1 + 0x48) != 0) &&

       (iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 100), iVar3 != 0)) &&

      (0 < *(int *)(iVar3 + 0x10))) && (iVar3 != 0)) {

    piVar4 = (int *)FUN_00989270(100);

    fVar2 = g_flOne;

    if ((piVar4 != (int *)0x0) && (*(int *)(param_1 + 0x26c) != 0)) {

      iVar3 = *piVar4;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3bc) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c0) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c4) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

      iVar3 = *piVar4;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3cc) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d0) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3d4) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

      *(float *)(param_1 + 0x3d8) = fVar2;

    }

  }

  return;

}
