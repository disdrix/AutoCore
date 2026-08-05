// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00870070
// -----------------------------------------------------------------------------
// Stable ID: aa_00870070
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00870070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×15, return×12, switch×1.
//  - Notable callees: CONCAT31×7, FUN_00870070.
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

void Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00870070(void)



{

  char cVar1;

  undefined3 uVar3;

  uint32_t /* width from decompiler */ uVar2;

  char unaff_BL;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar1 != '\0') {

    uVar3 = (undefined3)((uint)(unaff_ESI[0x153] + -0x9c45) >> 8);

    switch(unaff_ESI[0x153] + -0x9c45) {

    case 0:

      if (unaff_ESI[0x17b] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x17b] + 0x47c))();

        }

        else {

          uVar2 = CONCAT31(uVar3,(char)unaff_ESI[0x154]);

        }

        (**(code **)(*(int *)unaff_ESI[0x17b] + 0x484))(uVar2,0);

        return;

      }

      break;

    case 1:

      if (unaff_ESI[0x17c] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x17c] + 0x47c))();

          (**(code **)(*(int *)unaff_ESI[0x17c] + 0x488))(0,uVar2);

          return;

        }

        (**(code **)(*(int *)unaff_ESI[0x17c] + 0x488))(0,CONCAT31(uVar3,(char)unaff_ESI[0x154]));

        return;

      }

      break;

    case 2:

      if (unaff_ESI[0x17d] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x17d] + 0x47c))();

        }

        else {

          uVar2 = CONCAT31(uVar3,(char)unaff_ESI[0x154]);

        }

        (**(code **)(*(int *)unaff_ESI[0x17d] + 0x484))(uVar2,0);

        return;

      }

      break;

    case 3:

      if (unaff_ESI[0x17e] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x17e] + 0x47c))();

          (**(code **)(*(int *)unaff_ESI[0x17e] + 0x488))(0,uVar2);

          return;

        }

        (**(code **)(*(int *)unaff_ESI[0x17e] + 0x488))(0,CONCAT31(uVar3,(char)unaff_ESI[0x154]));

        return;

      }

      break;

    case 4:

      if (unaff_ESI[0x17f] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x17f] + 0x47c))();

          (**(code **)(*(int *)unaff_ESI[0x17f] + 0x488))(0,uVar2);

          return;

        }

        (**(code **)(*(int *)unaff_ESI[0x17f] + 0x488))(0,CONCAT31(uVar3,(char)unaff_ESI[0x154]));

        return;

      }

      break;

    case 5:

      if (unaff_ESI[0x180] != 0) {

        if (unaff_BL == '\0') {

          uVar2 = (**(code **)(*(int *)unaff_ESI[0x180] + 0x47c))();

          (**(code **)(*(int *)unaff_ESI[0x180] + 0x488))(0,uVar2);

          return;

        }

        (**(code **)(*(int *)unaff_ESI[0x180] + 0x488))(0,CONCAT31(uVar3,(char)unaff_ESI[0x154]));

        return;

      }

      break;

    default:

      if (unaff_ESI[0x17a] != 0) {

        if (unaff_BL != '\0') {

          (**(code **)(*(int *)unaff_ESI[0x17a] + 0x488))(0,CONCAT31(uVar3,(char)unaff_ESI[0x154]));

          return;

        }

        uVar2 = (**(code **)(*(int *)unaff_ESI[0x17a] + 0x47c))();

        (**(code **)(*(int *)unaff_ESI[0x17a] + 0x488))(0,uVar2);

      }

    }

  }

  return;

}
