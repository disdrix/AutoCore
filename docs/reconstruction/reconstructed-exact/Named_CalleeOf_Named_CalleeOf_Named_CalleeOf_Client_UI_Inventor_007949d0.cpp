// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UI_Inventor_007949d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007949d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryItemClickDispa
// Address:   0x007949d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryItemClickDispa: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×14, while×3, do×2, return×2, goto×1.
//  - Notable callees: FUN_00755890×2, CONCAT22, FUN_00755a50, FUN_007944a0, FUN_007949d0, wcslen.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryItemClickDispa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_UI_Inventor_007949d0(void)



{

  wchar_t wVar1;

  int iVar2;

  char cVar3;

  ushort uVar4;

  int iVar5;

  size_t sVar6;

  int *piVar7;

  int *unaff_EBX;

  int *piVar8;

  wchar_t *_Str;

  int iVar9;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint uStack_28;

  int iStack_24;

  int *piStack_20;

  int iStack_18;

  uint8_t auStack_10 [16];

  

  unaff_EBX[0x47] = -1;

  cVar3 = (**(code **)(*unaff_EBX + 0x1ec))();

  if ((((cVar3 == '\0') || (*(char *)((int)unaff_EBX + 0xba) == '\0')) && (unaff_EBX[0xa4] != 0)) &&

     ((char)unaff_EBX[0x122] != '\0')) {

    if ((unaff_EBX[0x83] != 0) && (unaff_EBX[0xa3] == 0)) {

      iVar5 = (**(code **)(*unaff_EBX + 0x210))();

      unaff_EBX[0xa3] = iVar5;

    }

    iVar5 = unaff_EBX[0xa3];

    if (((iVar5 != 0) && (*(int *)(iVar5 + 0x84) != 0)) &&

       (*(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x84) >> 7 != 0)) {

      iVar5 = unaff_EBX[0x46];

      uStack_28 = (uint)(uint3)uStack_28;

      unaff_EBX[0x47] = 0;

      (**(code **)(*unaff_EBX + 0x140))(auStack_10,1);

      FUN_007944a0();

      iVar2 = unaff_EBX[0xa3];

      piStack_20 = *(int **)(iVar2 + 0x84);

      if (piStack_20 != *(int **)(iVar2 + 0x88)) {

        piVar8 = piStack_20 + 10;

        do {

          if ((char)((uint)unaff_EDI >> 0x18) != '\0') {

            return;

          }

          if ((*piVar8 != 0) && (_Str = (wchar_t *)(piVar8 + -6), piVar8[-2] != 0)) {

            if (7 < (uint)piVar8[-1]) {

              _Str = *(wchar_t **)_Str;

            }

            sVar6 = wcslen(_Str);

            if (iVar5 != 0) {

              if ((int)sVar6 < iVar5) {

                piVar7 = (int *)FUN_00755a50(auStack_10);

                uStack_28 = uStack_28 - *piVar7;

                iStack_24 = iVar5 - sVar6;

                goto LAB_00794be3;

              }

              iVar9 = 0;

              if (0 < iVar5) {

                do {

                  wVar1 = _Str[iVar9];

                  if (((ushort)*(wchar_t *)(*(int *)*piVar8 + 0x88) <= (ushort)wVar1) &&

                     ((ushort)wVar1 <= (ushort)*(wchar_t *)(*(int *)*piVar8 + 0x8a))) {

                    iVar5 = FUN_00755890(wVar1);

                    uStack_28 = uStack_28 - *(int *)(iVar5 + 0x18);

                  }

                  iVar9 = iVar9 + 1;

                } while (iVar9 < iStack_24);

              }

              iStack_24 = 0;

            }

            iVar5 = *piStack_20 + uStack_28;

            wVar1 = *_Str;

            while (wVar1 != L'\0') {

              uVar4 = (ushort)(byte)*_Str;

              if ((*(ushort *)(*(int *)unaff_EBX[0xa4] + 0x88) <= uVar4) &&

                 (uVar4 <= *(ushort *)(*(int *)unaff_EBX[0xa4] + 0x8a))) {

                iVar9 = FUN_00755890(CONCAT22((short)((uint)_Str >> 0x10),uVar4));

                iVar5 = iVar5 + *(int *)(iVar9 + 0x18);

                if (iStack_18 <= iVar5) {

                  unaff_EDI = 0x1000000;

                  break;

                }

              }

              if (-1 < iVar5) {

                unaff_EBX[0x47] = unaff_EBX[0x47] + 1;

              }

              _Str = _Str + 1;

              wVar1 = *_Str;

            }

          }

LAB_00794be3:

          piVar8 = piVar8 + 0x20;

          piStack_20 = piStack_20 + 0x20;

          iVar5 = iStack_24;

        } while (piStack_20 != *(int **)(iVar2 + 0x88));

      }

    }

  }

  return;

}
