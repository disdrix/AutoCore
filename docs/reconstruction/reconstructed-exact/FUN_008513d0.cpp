// =============================================================================
// FUN_008513d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008513d0
// Address:   0x008513d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008513d0 @ 0x008513d0
// Stable ID: aa_008513d0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, goto×2.
//  - Notable callees: FUN_00758460, FUN_007a4480, FUN_0084f610, FUN_0084fe60, FUN_008513d0, FUN_008572f0.
//  - Strings: "VOG_DEBUG_STOP".
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

void FUN_008513d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  float fVar4;

  undefined *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int local_10;

  int local_c;

  

  if (param_3 < '\0') {

    return;

  }

  FUN_0084f610(&local_10);

  FUN_0084fe60();

  if ((param_3 == 'd') || (param_3 == 'e')) {

    param_3 = '\x01';

  }

  else if ('\x13' < param_3) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar3 = local_10 - *(int *)(in_EAX + 0x538) / 2;

  iVar2 = local_c - *(int *)(in_EAX + 0x53c) / 2;

  if (iVar3 < 0) {

    iVar3 = 0;

  }

  if (iVar2 < 0) {

    iVar2 = 0;

  }

  cVar1 = FUN_008572f0(param_3,&local_10);

  if (cVar1 == '\0') {

    puVar5 = *(undefined **)(in_EAX + 0x5b0 + param_3 * 4);

    fVar4 = (float)(*(int *)(in_EAX + 0x53c) + iVar2);

    if (puVar5 != (undefined *)0x0) {

      piVar7 = (int *)0x0;

      uVar6 = 0;

      goto LAB_008514e7;

    }

  }

  else {

    puVar5 = *(undefined **)(in_EAX + 0x5ac);

    fVar4 = (float)(*(int *)(in_EAX + 0x53c) + iVar2);

    if (puVar5 != (undefined *)0x0) {

      piVar7 = &local_10;

      uVar6 = 1;

      goto LAB_008514e7;

    }

  }

  piVar7 = (int *)0x0;

  uVar6 = 0;

  puVar5 = &DAT_00d1ec78;

LAB_008514e7:

  FUN_00758460((float)iVar3,(float)iVar2,(float)(*(int *)(in_EAX + 0x538) + iVar3),fVar4,puVar5,0,

               param_1,uVar6,piVar7,0,&DAT_00d1ecac);

  return;

}
