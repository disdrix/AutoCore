// =============================================================================
// FUN_00751890
// -----------------------------------------------------------------------------
// Stable ID: aa_00751890
// Address:   0x00751890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00751890 @ 0x00751890
// Stable ID: aa_00751890
// Embedded strings (evidence for future rename):
//   - "effFallbackEffect.h"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"
//   - "Failed to compile the fallback effect:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, do×1, while×1.
//  - Notable callees: CONCAT11, D3DXCreateEffect, FUN_00445620, FUN_00460380, FUN_007350c0, FUN_00750260, FUN_00751890, FUN_00989e00.
//  - Strings: "effFallbackEffect.h"; ",0x430

                 ,2,".
//  - Return sites: 4.

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

int FUN_00751890(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  char cVar3;

  char *pcVar4;

  int iVar5;

  int unaff_EDI;

  int *local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [4];

  void *local_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1b78;

  pvStack_c = ExceptionList;

  cVar2 = *(char *)(DAT_00d1f044 + 0x1de);

  local_28 = (int *)0x0;

  ExceptionList = &pvStack_c;

  FUN_007350c0();

  FUN_00460380(local_1c);

  local_4 = 0;

  local_24 = 0;

  local_20 = 0;

  FUN_00445620();

  pcVar4 = PTR_s_string_Phase____Opaque___float4x_00afa2f4;

  do {

    cVar3 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar3 != '\0');

  puVar1 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc);

  iVar5 = D3DXCreateEffect(*DAT_00d1f044,PTR_s_string_Phase____Opaque___float4x_00afa2f4,

                           (int)pcVar4 - (int)(PTR_s_string_Phase____Opaque___float4x_00afa2f4 + 1),

                           local_18,0,CONCAT11(1,-(cVar2 != '\x01') & 5),

                           *(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x140),puVar1,&local_28);

  if ((local_28 == (int *)0x0) && (-1 < iVar5)) {

    FUN_00989e00(&local_24,"effFallbackEffect.h");

    iVar5 = FUN_00750260(unaff_EDI,&local_24);

    if (-1 < iVar5) {

      (**(code **)(*(int *)*puVar1 + 0xe8))

                ((int *)*puVar1,*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x30) + 4));

      (**(code **)(*(int *)*puVar1 + 0x11c))((int *)*puVar1,DAT_00d1f610);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

    if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

    ExceptionList = pvStack_c;

    return iVar5;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",0x430

                 ,2,"Failed to compile the fallback effect:");

  if (local_28 != (int *)0x0) {

    (**(code **)(*local_28 + 8))(local_28);

  }

  local_28 = (int *)0x0;

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  ExceptionList = pvStack_c;

  return -1;

}
