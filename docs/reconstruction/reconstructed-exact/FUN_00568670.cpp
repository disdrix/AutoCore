// =============================================================================
// FUN_00568670
// -----------------------------------------------------------------------------
// Stable ID: aa_00568670
// Address:   0x00568670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00568670 @ 0x00568670
// Stable ID: aa_00568670
// Embedded strings (evidence for future rename):
//   - "ILLEGAL ENHANCEMENT: %i, CBID %i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_004c3700, FUN_004c9aa0, FUN_00568250, FUN_005685e0, FUN_00568670, FUN_007a4480.
//  - Strings: "ILLEGAL ENHANCEMENT: %i, CBID %i".
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

int FUN_00568670(uint32_t /* width from decompiler */ param_1,int param_2)



{

  short sVar1;

  char cVar2;

  short sVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  short sVar7;

  void *pvStack_1c;

  void *pvStack_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4c5b;

  local_c = ExceptionList;

  if (param_2 == -1) {

    return 0;

  }

  ExceptionList = &local_c;

  pvVar4 = operator_new(0x690);

  local_4 = 0;

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_004c9aa0(1);

  }

  local_4 = 0xffffffff;

  iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))(param_2,0,0);

  if (iVar6 < 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5))(1);

    ExceptionList = pvStack_1c;

    return 0;

  }

  sVar7 = (short)puStack_8;

  if (sVar7 != 0) {

    sVar1 = *(short *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                      0x4ee);

    sVar3 = sVar1 + sVar7;

    if (sVar3 < 1) {

      sVar3 = 1;

    }

    iVar6 = (int)sVar3 - (int)sVar1;

    if (iVar6 != 0) {

      cVar2 = FUN_005685e0(iVar6,&stack0xffffffb0);

      if (cVar2 == '\0') {

        FUN_007a4480(1,"ILLEGAL ENHANCEMENT: %i, CBID %i",(int)sVar7,

                     *(uint32_t /* width from decompiler */ *)

                      (*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x34));

        FUN_004c3700(999999);

      }

      else {

        FUN_00568250(&stack0xffffffb0,iVar5);

      }

    }

  }

  ExceptionList = pvStack_18;

  return iVar5;

}
