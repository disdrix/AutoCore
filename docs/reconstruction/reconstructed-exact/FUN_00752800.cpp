// =============================================================================
// FUN_00752800
// -----------------------------------------------------------------------------
// Stable ID: aa_00752800
// Address:   0x00752800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752800 @ 0x00752800
// Stable ID: aa_00752800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×1.
//  - Notable callees: FUN_00752800.
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

void __thiscall FUN_00752800(uint param_1,int param_2)



{

  ushort uVar1;

  int iVar2;

  int *piVar3;

  int in_EAX;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  iVar2 = *(int *)(in_EAX + 8);

  uVar1 = *(ushort *)(*(int *)(iVar2 + 0x10) + 4 + param_2 * 8);

  if (param_1 == 4) {

    *(uint32_t /* width from decompiler */ *)((uint)uVar1 + *(int *)(in_EAX + 0xc)) = *unaff_EBX;

  }

  else if (param_1 == 0xc) {

    puVar5 = (uint32_t /* width from decompiler */ *)((uint)uVar1 + *(int *)(in_EAX + 0xc));

    *puVar5 = *unaff_EBX;

    puVar5[1] = unaff_EBX[1];

    puVar5[2] = unaff_EBX[2];

  }

  else if (param_1 == 0x10) {

    puVar5 = (uint32_t /* width from decompiler */ *)((uint)uVar1 + *(int *)(in_EAX + 0xc));

    *puVar5 = *unaff_EBX;

    puVar5[1] = unaff_EBX[1];

    puVar5[2] = unaff_EBX[2];

    puVar5[3] = unaff_EBX[3];

  }

  else {

    puVar5 = (uint32_t /* width from decompiler */ *)((uint)uVar1 + *(int *)(in_EAX + 0xc));

    for (uVar4 = param_1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar5 = *unaff_EBX;

      unaff_EBX = unaff_EBX + 1;

      puVar5 = puVar5 + 1;

    }

    for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {

      *(uint8_t *)puVar5 = *(uint8_t *)unaff_EBX;

      unaff_EBX = (uint32_t /* width from decompiler */ *)((int)unaff_EBX + 1);

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

  }

  if (DAT_00afe038 == *(int *)(in_EAX + 0xc)) {

    piVar3 = *(int **)(iVar2 + 0xc);

    (**(code **)(*piVar3 + 0x50))

              (piVar3,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(in_EAX + 8) + 0x10) + param_2 * 8));

  }

  return;

}
