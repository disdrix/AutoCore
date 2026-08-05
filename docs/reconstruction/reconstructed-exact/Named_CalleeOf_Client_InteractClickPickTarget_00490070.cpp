// =============================================================================
// Named_CalleeOf_Client_InteractClickPickTarget_00490070
// -----------------------------------------------------------------------------
// Stable ID: aa_00490070
// Callee of Client_InteractClickPickTarget
// Address:   0x00490070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_InteractClickPickTarget: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: if×36, goto×6, return×2, while×2, do×1, switch×1.
//  - Notable callees: FUN_004bae00×2, CONCAT31, FUN_0040b1b0, FUN_00490070, FUN_00524520, FUN_005245d0, FUN_0075c340, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_InteractClickPickTarget
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

int * __thiscall Named_CalleeOf_Client_InteractClickPickTarget_00490070(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  bool bVar1;

  byte bVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  byte local_75;

  float local_74;

  uint local_6c;

  int *local_68;

  float local_64;

  uint32_t /* width from decompiler */ local_60;

  int local_5c;

  uint8_t auStack_58 [4];

  uint8_t local_54 [12];

  uint8_t local_48 [12];

  float fStack_3c;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  if ((*(int *)(param_1 + 0xc0) == 0) || (*(int *)(param_1 + 0xbc) == 0)) {

    return (int *)0x0;

  }

  local_2 = 0xff;

  local_3 = 0xff;

  local_4 = 0xff;

  local_1 = 0xff;

  FUN_0075c340(param_2,local_54,local_48);

  local_64 = DAT_00aaa630;

  local_74 = DAT_00aaa630;

  local_68 = (int *)0x0;

  local_6c = local_6c & 0xffffff00;

  local_75 = 0;

  bVar1 = false;

  local_5c = 2;

  do {

    local_60 = 0;

    piVar4 = (int *)FUN_004bae00(local_6c,&local_60);

    bVar2 = local_75;

    while (piVar4 != (int *)0x0) {

      local_75 = 0;

      if (((((uint)piVar4[0x5f] >> 6 & 1) == 0) ||

          (iVar5 = (**(code **)(*piVar4 + 0x1cc))(), *(int *)(iVar5 + 8) == 0)) ||

         (*(char *)(iVar5 + 0xe) == '\0')) goto switchD_004901c9_caseD_1e;

      fStack_3c = DAT_00aaa630;

      cVar3 = (**(code **)(**(int **)(iVar5 + 8) + 0x78))(5,auStack_58);

      if (cVar3 == '\0') goto switchD_004901c9_caseD_1e;

      uVar6 = (uint)*(short *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x3f2);

      if ((uVar6 >> 0xe & 1) != 0) {

        local_74 = fStack_3c;

        local_75 = 0x50;

      }

      if (((uVar6 >> 7 & 1) != 0) && (local_74 = fStack_3c, local_75 < 0x47)) {

        local_75 = 0x46;

      }

      switch(*(uint32_t /* width from decompiler */ *)(piVar4[0x2a] + 0x38)) {

      case 1:

      case 3:

        if (((*(int *)(param_1 + 0xb8) != 0) &&

            (piVar7 = *(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0), piVar7 != (int *)0x0)) &&

           (iVar5 = (**(code **)(*piVar7 + 0x1dc))(), iVar5 != 0)) {

          piVar7 = piVar4;

          (**(code **)(**(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0) + 0x1dc))(piVar4);

          iVar5 = FUN_00524520(piVar7);

          if (iVar5 == 0) {

            piVar7 = piVar4;

            (**(code **)(**(int **)(*(int *)(param_1 + 0xb8) + 0xe8a0) + 0x1dc))(piVar4);

            iVar5 = FUN_005245d0(piVar7);

            if (iVar5 == 0) goto LAB_00490248;

          }

          bVar1 = true;

          if (local_75 < 0x3d) {

            local_75 = 0x3c;

          }

        }

LAB_00490248:

        if ((piVar4[10] & piVar4[0xb]) != 0xffffffff) {

          bVar1 = true;

        }

        if ((piVar4[0xc] & piVar4[0xd]) != 0xffffffff) {

          bVar1 = true;

        }

        if ((piVar4[0xe] & piVar4[0xf]) != 0xffffffff) {

          bVar1 = true;

        }

        if ((((*(ushort *)(*(int *)(piVar4[0x2a] + 0x3c) + 0x3f2) & 0x2000) != 0) || (bVar1)) &&

           (local_74 = fStack_3c, local_75 < 0x15)) {

          local_75 = 0x14;

        }

        break;

      case 10:

      case 0xc:

      case 0x10:

      case 0x1c:

        piVar7 = (int *)piVar4[0x2b];

        local_74 = fStack_3c;

        if (piVar7 == (int *)0x0) {

          if (local_75 < 0x47) {

            local_75 = 0x46;

          }

        }

        else {

          piVar4 = piVar7;

          if (local_75 < 0x5b) {

            local_75 = 0x5a;

          }

        }

        break;

      case 0xe:

        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {

          iVar5 = (**(code **)(*piVar4 + 0x210))(0);

          if (iVar5 != 0) {

            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

          }

          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;

        }

        local_74 = fStack_3c;

        if (local_75 < 0x5b) {

          local_75 = 0x5a;

        }

        break;

      case 0x12:

        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {

          iVar5 = (**(code **)(*piVar4 + 0x210))(0);

          if (iVar5 != 0) {

            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

          }

          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;

        }

        iVar5 = __RTDynamicCast(piVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGCreature::RTTI_Type_Descriptor,0);

        cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x198))();

        if (cVar3 == '\0') {

          cVar3 = FUN_0040b1b0();

          local_74 = fStack_3c;

          if (cVar3 == '\0') goto LAB_00490468;

          if (local_75 < 0x33) {

            local_75 = 0x32;

          }

        }

        else {

          local_74 = fStack_3c;

          if (local_75 < 0x3d) {

            local_75 = 0x3c;

          }

        }

        break;

      case 0x14:

        if ((param_4 == '\0') && (*(int *)(param_1 + 0xb8) != 0)) {

          iVar5 = (**(code **)(*piVar4 + 0x210))(0);

          if (iVar5 != 0) {

            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

          }

          if (iVar5 == *(int *)(*(int *)(param_1 + 0xb8) + 0xe8a0)) break;

        }

      default:

        local_74 = fStack_3c;

        if (local_75 < 0x29) {

          local_75 = 0x28;

        }

        break;

      case 0x16:

LAB_00490468:

        local_74 = fStack_3c;

        if (local_75 < 0x65) {

          local_75 = 100;

        }

        break;

      case 0x1e:

      case 0x36:

      case 0x38:

        goto switchD_004901c9_caseD_1e;

      }

      if (local_75 == bVar2) {

        if (local_74 < local_64) {

          local_64 = local_74;

          local_75 = bVar2;

LAB_00490477:

          bVar2 = local_75;

          local_68 = piVar4;

        }

      }

      else if (bVar2 < local_75) goto LAB_00490477;

switchD_004901c9_caseD_1e:

      local_75 = bVar2;

      piVar4 = (int *)FUN_004bae00(local_6c,&local_60);

      bVar2 = local_75;

    }

    local_5c = local_5c + -1;

    local_6c = CONCAT31(local_6c._1_3_,(char)local_6c == '\0');

    local_75 = bVar2;

    if (local_5c == 0) {

      return local_68;

    }

  } while( true );

}
