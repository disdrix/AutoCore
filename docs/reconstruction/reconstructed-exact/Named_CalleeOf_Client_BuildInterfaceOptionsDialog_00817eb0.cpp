// =============================================================================
// Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00817eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00817eb0
// Callee of Client_BuildInterfaceOptionsDialog
// Address:   0x00817eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_BuildInterfaceOptionsDialog: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0078f890, FUN_00817eb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_BuildInterfaceOptionsDialog
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Client_BuildInterfaceOptionsDialog_00817eb0(void)



{

  float fVar1;

  void *pvVar2;

  int iVar3;

  int *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8119;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  unaff_EDI[0x14f] = 0;

  if ((char)unaff_EDI[0x2d9] != '\0') {

    if (unaff_EDI[0x152] == 0) {

      pvVar2 = operator_new(0x954);

      local_4 = 0;

      if (pvVar2 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = FUN_0078f890();

      }

      local_4 = 0xffffffff;

      unaff_EDI[0x152] = iVar3;

      (**(code **)(*unaff_EDI + 0xa8))(iVar3);

      (**(code **)(*(int *)unaff_EDI[0x152] + 0x28))(unaff_EDI + 0x2d9);

      (**(code **)(*(int *)unaff_EDI[0x152] + 0x43c))();

      (**(code **)(*(int *)unaff_EDI[0x152] + 0x74))(40000);

      (**(code **)(*(int *)unaff_EDI[0x152] + 0x468))(1);

    }

    (**(code **)(*(int *)unaff_EDI[0x152] + 0xd4))(1);

    (**(code **)(*(int *)unaff_EDI[0x152] + 0x460))(0x3f800000);

    if (unaff_EDI[0x150] < unaff_EDI[0x145]) {

      iVar3 = unaff_EDI[0x145] - unaff_EDI[0x150];

      fVar1 = (float)iVar3;

      if (iVar3 < 0) {

        fVar1 = fVar1 + _DAT_00aaa5dc;

      }

      (**(code **)(*(int *)unaff_EDI[0x152] + 0x460))(g_flOne / fVar1);

    }

    else {

      (**(code **)(*(int *)unaff_EDI[0x152] + 0xd4))(0);

    }

    (**(code **)(*(int *)unaff_EDI[0x152] + 0x454))(0,0);

  }

  ExceptionList = local_c;

  return;

}
