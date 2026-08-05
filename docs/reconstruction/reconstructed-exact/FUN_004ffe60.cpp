// =============================================================================
// FUN_004ffe60
// -----------------------------------------------------------------------------
// Stable ID: aa_004ffe60
// Address:   0x004ffe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ffe60 @ 0x004ffe60
// Stable ID: aa_004ffe60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×23, return×12, do×1, while×1.
//  - Notable callees: FUN_00407140, FUN_004a2670, FUN_004ffe60, FUN_00564260, FUN_00570f50.
//  - Return sites: 12.

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

void __fastcall FUN_004ffe60(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  uint8_t auStack_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a2df4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(undefined ***)(param_1 + -0x670) = &PTR_Vehicle_TryActivatePhysics_009cd77c;

  *(undefined ***)(param_1 + -0x630) = &PTR_FUN_009cd740;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) = &PTR_LAB_009cd47c;

  iVar3 = *(int *)(*(int *)(param_1 + -0x66c) + 4);

  *(int *)(iVar3 + -0x670 + param_1) = iVar3 + -0x66c;

  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1) = 0;

  local_4 = 6;

  if (*(void **)(param_1 + -0x4cc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x4cc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x4cc) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x3ec) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x3ec))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x3ec) = 0;

  (**(code **)(*(int *)(param_1 + -0x630) + 4))();

  iVar3 = *(int *)(param_1 + -0x2b8);

  if (iVar3 != 0) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(iVar3 + 4);

    if (puVar1 != *(uint32_t /* width from decompiler */ **)(iVar3 + 8)) {

      if (*(uint32_t /* width from decompiler */ **)*puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)*puVar1)(1);

      }

      *(uint32_t /* width from decompiler */ *)*puVar1 = 0;

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)*puVar1);

    }

    iVar3 = *(int *)(param_1 + -0x2b8);

    if (*(void **)(iVar3 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(iVar3 + 4));

    }

    *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    pvVar2 = *(void **)(param_1 + -0x2b8);

    if (pvVar2 != (void *)0x0) {

      if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)pvVar2 + 4));

      }

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x2b8) = 0;

  }

  if (*(int *)(param_1 + -0x3f0) != 0) {

    FUN_00564260((int *)(param_1 + -0x670));

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3f0) = 0;

  }

  if (*(int *)(param_1 + -0x3fc) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x3fc) + 0x278) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3fc) = 0;

  }

  if (*(int *)(param_1 + -0x3f8) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x3f8) + 0x274) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3f8) = 0;

  }

  (**(code **)(*(int *)(param_1 + -0x670) + 4))();

  if (*(int *)(param_1 + -0x3c0) != 0) {

    FUN_00570f50();

    if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x3c0) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x3c0))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x3c0) = 0;

  }

  piVar4 = (int *)(param_1 + -0x324);

  iVar3 = 8;

  do {

    if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);

    }

    *piVar4 = 0;

    piVar4 = piVar4 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  pvVar2 = *(void **)(param_1 + -0x334);

  if (pvVar2 != (void *)0x0) {

    FUN_004a2670();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x334) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x2c0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x2c0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c0) = 0;

  if (*(void **)(param_1 + -0x410) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + -0x410));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x410) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x578) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x578))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x578) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x418) = 0;

  if (*(void **)(param_1 + -0x68) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x68));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x60) = 0;

  if (*(void **)(param_1 + -0x78) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x78));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x70) = 0;

  if (*(void **)(param_1 + -0x88) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x88));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x80) = 0;

  if (*(void **)(param_1 + -0x2dc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x2dc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d4) = 0;

  if (*(void **)(param_1 + -0x340) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x340));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x340) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x33c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x338) = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_00407140(auStack_10,**(uint32_t /* width from decompiler */ **)(param_1 + -0x3b4),*(uint32_t /* width from decompiler */ **)(param_1 + -0x3b4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + -0x3b4));

}
