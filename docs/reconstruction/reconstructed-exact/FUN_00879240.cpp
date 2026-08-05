// =============================================================================
// FUN_00879240
// -----------------------------------------------------------------------------
// Stable ID: aa_00879240
// Address:   0x00879240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00879240 @ 0x00879240
// Stable ID: aa_00879240
// Embedded strings (evidence for future rename):
//   - "Deathmatch"
//   - "Capture \'N Hold"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: __RTDynamicCast×2, FUN_00879240.
//  - Strings: "Deathmatch"; "Capture \'N Hold".
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

void FUN_00879240(void)



{

  int *piVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  undefined *puVar5;

  

  if (*(int **)(in_EAX + 0x594) != (int *)0x0) {

    uVar2 = (**(code **)(**(int **)(in_EAX + 0x594) + 0x448))(&DAT_00a328a0);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x52c) = uVar2;

    puVar5 = &DAT_00a1e460;

    puVar4 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x530);

    do {

      uVar2 = (**(code **)(**(int **)(in_EAX + 0x594) + 0x448))(puVar5);

      *puVar4 = uVar2;

      puVar5 = puVar5 + 0x10;

      puVar4 = puVar4 + 1;

    } while ((int)puVar5 < 0xa1e4d0);

    piVar1 = *(int **)(*(int *)(in_EAX + 0x594) + 0x930);

    if (piVar1 != (int *)0x0) {

      *(uint8_t *)((int)piVar1 + 0x489) = 1;

      piVar3 = (int *)(**(code **)(*piVar1 + 0x170))(0xb);

      piVar1[0x8b] = *piVar3;

      piVar3 = (int *)__RTDynamicCast(piVar1[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                      &CNDUIDialog::RTTI_Type_Descriptor,0);

      if ((piVar3 != (int *)0x0) && ((int *)piVar3[0x12f] == piVar1)) {

        (**(code **)(*piVar3 + 0x1c8))(0);

        (**(code **)(*piVar3 + 0x3c0))(0);

      }

    }

  }

  if (*(int **)(in_EAX + 0x598) != (int *)0x0) {

    uVar2 = (**(code **)(**(int **)(in_EAX + 0x598) + 0x448))(&DAT_00a328a0);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x54c) = uVar2;

    uVar2 = (**(code **)(**(int **)(in_EAX + 0x598) + 0x448))("Deathmatch");

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x550) = uVar2;

    uVar2 = (**(code **)(**(int **)(in_EAX + 0x598) + 0x448))("Capture \'N Hold");

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x554) = uVar2;

    piVar1 = *(int **)(*(int *)(in_EAX + 0x598) + 0x930);

    if (piVar1 != (int *)0x0) {

      *(uint8_t *)((int)piVar1 + 0x489) = 1;

      piVar3 = (int *)(**(code **)(*piVar1 + 0x170))(0xb);

      piVar1[0x8b] = *piVar3;

      piVar3 = (int *)__RTDynamicCast(piVar1[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                      &CNDUIDialog::RTTI_Type_Descriptor,0);

      if ((piVar3 != (int *)0x0) && ((int *)piVar3[0x12f] == piVar1)) {

        (**(code **)(*piVar3 + 0x1c8))(0);

        (**(code **)(*piVar3 + 0x3c0))(0);

      }

    }

  }

  return;

}
