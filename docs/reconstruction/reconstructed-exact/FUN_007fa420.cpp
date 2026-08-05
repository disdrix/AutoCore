// =============================================================================
// FUN_007fa420
// -----------------------------------------------------------------------------
// Stable ID: aa_007fa420
// Address:   0x007fa420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fa420 @ 0x007fa420
// Stable ID: aa_007fa420
// Embedded strings (evidence for future rename):
//   - "i_g_2d_cursor_combat_base.dds"
//   - "i_g_2d_cursor_combat_mask.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×8, for×4, return×3.
//  - Notable callees: block×13, FUN_0096efd0×4, CONCAT31×2, FUN_0096be60×2, FUN_0096f3e0×2, FUN_00989e00×2, FUN_007fa420, FUN_0096f0e0.
//  - Strings: "i_g_2d_cursor_combat_base.dds"; "i_g_2d_cursor_combat_mask.dds".
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

/* WARNING: Removing unreachable block (ram,0x007fa5c1) */

/* WARNING: Removing unreachable block (ram,0x007fa5ce) */

/* WARNING: Removing unreachable block (ram,0x007fa6a4) */

/* WARNING: Removing unreachable block (ram,0x007fa5d7) */

/* WARNING: Removing unreachable block (ram,0x007fa5dc) */

/* WARNING: Removing unreachable block (ram,0x007fa5e6) */

/* WARNING: Removing unreachable block (ram,0x007fa672) */

/* WARNING: Removing unreachable block (ram,0x007fa6d6) */

/* WARNING: Removing unreachable block (ram,0x007fa67f) */

/* WARNING: Removing unreachable block (ram,0x007fa6b7) */

/* WARNING: Removing unreachable block (ram,0x007fa684) */

/* WARNING: Removing unreachable block (ram,0x007fa689) */

/* WARNING: Removing unreachable block (ram,0x007fa6e0) */



uint32_t /* width from decompiler */ FUN_007fa420(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b14fa;

  pvStack_c = ExceptionList;

  pvVar3 = *(void **)(param_1 + 0x534);

  if (pvVar3 != (void *)0x0) {

    ExceptionList = &pvStack_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  ExceptionList = &pvStack_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0;

  puVar1 = operator_new(4);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = 0;

  }

  local_4 = 0xffffffff;

  local_14 = 0x20;

  local_10 = 0x20;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x534) = puVar1;

  iVar2 = FUN_0096f0e0(0x15,&local_14,1,1,1,0);

  if (iVar2 < 0) {

    pvVar3 = *(void **)(param_1 + 0x534);

    if (pvVar3 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0;

  }

  if (*(void **)(param_1 + 0x538) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x538));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  if (*(void **)(param_1 + 0x53c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x53c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0;

  pvVar3 = operator_new__(0x1000);

  *(void **)(param_1 + 0x538) = pvVar3;

  pvVar3 = operator_new__(0x1000);

  *(void **)(param_1 + 0x53c) = pvVar3;

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x538);

  for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x53c);

  for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  local_4 = 1;

  FUN_00989e00(&local_14,"i_g_2d_cursor_combat_base.dds");

  iVar2 = FUN_0096f3e0(&local_14,0);

  if ((((-1 < iVar2) && (iRam0000001c == 0x20)) && (iRam00000020 == 0x20)) &&

     (puVar1 = (uint32_t /* width from decompiler */ *)FUN_0096be60(0,0,0,(uRam0000002c & 0x80) != 0),

     puVar1 != (uint32_t /* width from decompiler */ *)0x0)) {

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x538);

    for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar1;

      puVar1 = puVar1 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00989e00(&local_14,"i_g_2d_cursor_combat_mask.dds");

  iVar2 = FUN_0096f3e0(&local_14,0);

  if (((-1 < iVar2) && (iRam0000001c == 0x20)) &&

     ((iRam00000020 == 0x20 &&

      (puVar1 = (uint32_t /* width from decompiler */ *)FUN_0096be60(0,0,0,(uRam0000002c & 0x80) != 0),

      puVar1 != (uint32_t /* width from decompiler */ *)0x0)))) {

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x53c);

    for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar1;

      puVar1 = puVar1 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0096efd0();

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = pvStack_c;

  return 1;

}
