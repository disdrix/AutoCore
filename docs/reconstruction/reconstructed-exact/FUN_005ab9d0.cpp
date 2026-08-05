// =============================================================================
// FUN_005ab9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ab9d0
// Address:   0x005ab9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ab9d0 @ 0x005ab9d0
// Stable ID: aa_005ab9d0
// Embedded strings (evidence for future rename):
//   - "name"
//   - "index"
//   - "description"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00798bb0×2, FUN_005aaf20, FUN_005ab9d0, FUN_00799460, SysFreeString.
//  - Strings: "name"; "index"; "description".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void FUN_005ab9d0(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_ESI;

  BSTR unaff_EDI;

  uint8_t *puVar3;

  uint local_1014 [510];

  uint8_t auStack_81c [8];

  uint16_t uStack_814;

  void *pvStack_1c;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a650b;

  pvStack_c = ExceptionList;

  uStack_10 = 0x5ab9ef;

  puVar3 = (uint8_t *)0x0;

  local_1014[0] = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x68))(param_1);

  uStack_814 = 0;

  local_1014[0] = local_1014[0] & 0xffff0000;

  iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&stack0xffffefe0);

  if ((iVar2 == 0) && (local_1014 != (uint *)0x0)) {

    cVar1 = FUN_00798bb0(local_1014,L"name",auStack_81c);

    if (cVar1 == '\0') {

      (**(code **)(local_1014[0] + 8))(local_1014);

    }

    else {

      cVar1 = FUN_00799460(local_1014,L"index",&stack0xffffefe0,10);

      if (cVar1 == '\0') {

        unaff_ESI = 0xffffffff;

      }

      cVar1 = FUN_00798bb0(local_1014,L"description",&stack0xffffefe4);

      if (cVar1 != '\0') {

        puVar3 = &stack0xffffefe4;

      }

      (**(code **)(local_1014[0] + 8))(local_1014);

      FUN_005aaf20(auStack_81c,&stack0xffffefdc,unaff_ESI,puVar3);

    }

  }

  SysFreeString(unaff_EDI);

  ExceptionList = pvStack_1c;

  return;

}
