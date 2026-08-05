// =============================================================================
// FUN_005b06d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b06d0
// Address:   0x005b06d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b06d0 @ 0x005b06d0
// Stable ID: aa_005b06d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b0560, FUN_005b06d0, FUN_005b0c10.
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

void FUN_005b06d0(int *param_1)



{

  int *piVar1;

  void *pvVar2;

  int unaff_ESI;

  void *pvVar3;

  int iStack_1c;

  uint32_t /* width from decompiler */ *puStack_18;

  void *local_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a66ef;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005b0560();

  puStack_18 = (uint32_t /* width from decompiler */ *)0x0;

  (**(code **)(*param_1 + 0x14))(&puStack_18,4);

  iStack_4 = 0;

  if (0 < unaff_ESI) {

    do {

      pvVar2 = operator_new(100);

      pvVar3 = (void *)0x0;

      if (pvVar2 != (void *)0x0) {

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x58) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x5c) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x60) = 0;

        pvVar3 = pvVar2;

      }

      piVar1 = (int *)((int)pvVar3 + 0x44);

      pvStack_c = (void *)0xffffffff;

      (**(code **)(*param_1 + 0x14))(piVar1,4);

      (**(code **)(*param_1 + 0x14))((int)pvVar3 + 0x40,1);

      (**(code **)(*param_1 + 0x14))((uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x48),4);

      (**(code **)(*param_1 + 0x14))((int)pvVar3 + 0x4c,4);

      if (unaff_ESI < 0x2e) {

        *(uint8_t *)((int)pvVar3 + 0x50) = 0;

      }

      else {

        (**(code **)(*param_1 + 0x14))((int)pvVar3 + 0x50,1);

      }

      (**(code **)(*param_1 + 0x14))(pvVar3,0x40);

      FUN_005b0c10(*piVar1,pvVar3,0);

      if (*(int *)(iStack_1c + 0x38) <= *piVar1) {

        *(int *)(iStack_1c + 0x38) = *piVar1 + 1;

      }

      iStack_4 = iStack_4 + 1;

      *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x48) = *puStack_18;

    } while (iStack_4 < unaff_ESI);

  }

  ExceptionList = local_14;

  return;

}
