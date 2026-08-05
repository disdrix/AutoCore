// =============================================================================
// FUN_0050b890
// -----------------------------------------------------------------------------
// Stable ID: aa_0050b890
// Address:   0x0050b890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0050b890 @ 0x0050b890
// Stable ID: aa_0050b890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: block×17, FUN_0041b0b0, FUN_0050b890, FUN_0050f3e0.
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x0050ba38) */

/* WARNING: Removing unreachable block (ram,0x0050b95b) */

/* WARNING: Removing unreachable block (ram,0x0050b976) */

/* WARNING: Removing unreachable block (ram,0x0050b980) */

/* WARNING: Removing unreachable block (ram,0x0050b9a1) */

/* WARNING: Removing unreachable block (ram,0x0050b9a8) */

/* WARNING: Removing unreachable block (ram,0x0050b9d2) */

/* WARNING: Removing unreachable block (ram,0x0050b9e3) */

/* WARNING: Removing unreachable block (ram,0x0050b9fb) */

/* WARNING: Removing unreachable block (ram,0x0050b9df) */

/* WARNING: Removing unreachable block (ram,0x0050ba08) */

/* WARNING: Removing unreachable block (ram,0x0050ba1a) */

/* WARNING: Removing unreachable block (ram,0x0050ba21) */

/* WARNING: Removing unreachable block (ram,0x0050ba58) */

/* WARNING: Removing unreachable block (ram,0x0050ba65) */

/* WARNING: Removing unreachable block (ram,0x0050ba27) */

/* WARNING: Removing unreachable block (ram,0x0050ba5c) */



uint __thiscall

FUN_0050b890(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a32b7;

  local_c = ExceptionList;

  local_4 = 0;

  if (((int)param_4 < 4) && (-1 < (int)param_4)) {

    iVar4 = param_4 * 0xc;

    ExceptionList = &local_c;

    piVar2 = (int *)FUN_0050f3e0(&param_4,&param_3);

    iVar1 = *piVar2;

    if (iVar1 != *(int *)(param_1 + iVar4 + 0x84)) {

      iVar4 = 0;

      iVar5 = 0;

      while( true ) {

        if (*(int *)(iVar1 + 0x14) == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 4;

        }

        if (iVar3 <= iVar4) break;

        iVar3 = *(int *)(iVar1 + 0x14);

        local_1c = *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5);

        local_18 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar5);

        local_14 = *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5 + 8);

        local_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5 + 0xc);

        FUN_0041b0b0(&local_1c);

        iVar4 = iVar4 + 1;

        iVar5 = iVar5 + 0x10;

      }

      piVar2 = (int *)0x0;

    }

    ExceptionList = local_c;

    return (uint)piVar2 & 0xffffff00;

  }

  return param_4 & 0xffffff00;

}
