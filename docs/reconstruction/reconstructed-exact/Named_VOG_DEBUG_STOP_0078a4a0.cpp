// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×11, while×2, for×2, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00423f40×2, FUN_004294f0×2, FUN_00789ad0×2, LeaveCriticalSection×2, __RTDynamicCast×2, FUN_0078a4a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0078a4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078a4a0
// Address:   0x0078a4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_0078a4a0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *local_10;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  if (param_2 != *(int *)(param_1 + 0x568)) {

    if (param_2 < 0) {

      param_2 = 0;

    }

    *(int *)(param_1 + 0x568) = param_2;

    iVar1 = -param_2;

    local_8 = 0;

    local_4 = param_1;

    FUN_004294f0();

    iVar2 = FUN_00423f40(&local_10);

    while (iVar2 == 0) {

      FUN_00789ad0(param_1,*local_10,local_10[1],iVar1);

      if ((((-1 < *(int *)(param_1 + 0x9a0)) && (*(int *)(param_1 + 0x2b0) != 0)) &&

          (local_c = __RTDynamicCast(*(int *)(param_1 + 0x2b0),0,&CNDUIWindow::RTTI_Type_Descriptor,

                                     &CNDUIDialog::RTTI_Type_Descriptor,0), local_c != 0)) &&

         (iVar2 = *(int *)(local_c + 0x4c0), iVar2 != 0)) {

        iVar3 = 0;

        if (*(char *)(iVar2 + 0x1d) != '\0') {

          FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        *(uint8_t *)(iVar2 + 0x1d) = 1;

        while( true ) {

          iVar2 = *(int *)(local_c + 0x4c0);

          if (*(char *)(iVar2 + 0x1d) == '\0') {

            FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          if (iVar3 == 0) {

            iVar3 = *(int *)(iVar2 + 0x14);

          }

          else {

            iVar3 = *(int *)(iVar3 + 0x14);

          }

          if (iVar3 == 0) {

            iVar2 = 0;

          }

          else {

            iVar2 = *(int *)(iVar3 + 8);

          }

          if (iVar2 == 0) break;

          iVar2 = __RTDynamicCast(iVar2,0,&CNDUIWindow::RTTI_Type_Descriptor,

                                  &CNDUICtrlListBox::RTTI_Type_Descriptor,0);

          if (((iVar2 != 0) && (*(int *)(iVar2 + 0x9a0) == *(int *)(param_1 + 0x9a0))) &&

             (iVar2 != param_1)) {

            *(int *)(iVar2 + 0x568) = param_2;

            FUN_004294f0();

            FUN_00789ad0(iVar2,*local_10,local_10[1],iVar1);

            if (*(char *)(iVar2 + 0x534) != '\0') {

              *(uint8_t *)(iVar2 + 0x534) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x510));

            }

            *(uint8_t *)(iVar2 + 0x566) = 0;

            param_1 = local_4;

          }

        }

        *(uint8_t *)(*(int *)(local_c + 0x4c0) + 0x1d) = 0;

      }

      iVar1 = iVar1 + 1;

      iVar2 = FUN_00423f40(&local_10);

    }

    if (*(char *)(param_1 + 0x534) != '\0') {

      *(uint8_t *)(param_1 + 0x534) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

    }

  }

  return;

}
