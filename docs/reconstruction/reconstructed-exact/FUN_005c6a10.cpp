// =============================================================================
// FUN_005c6a10
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6a10
// Address:   0x005c6a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c6a10 @ 0x005c6a10
// Stable ID: aa_005c6a10
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_initPostCreateMsg"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31×3, FUN_005c6a10, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initPostCreateMsg".
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

uint32_t /* width from decompiler */ __thiscall FUN_005c6a10(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ unaff_EBX;

  void *pvVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  undefined3 uVar3;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6dde;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CLoadNode::_initPostCreateMsg");

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

  uVar3 = (undefined3)((uint)unaff_EBX >> 8);

  pvVar2 = (void *)CONCAT31(uVar3,*(uint8_t *)((int)puVar1 + 10));

  local_4 = 0;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 200))

            (*puVar1,puVar1[1],CONCAT31(uVar3,*(uint8_t *)(puVar1 + 2)),

             CONCAT31(uVar3,*(uint8_t *)((int)puVar1 + 9)),pvVar2,1);

  if ((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x6c));

  }

  **(uint32_t /* width from decompiler */ **)(param_1 + 0x6c) = 0;

  if (*(void **)(param_1 + 0x6c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x6c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  FUN_0076cef0();

  ExceptionList = pvVar2;

  return 0;

}
