// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00571260
// -----------------------------------------------------------------------------
// Stable ID: aa_00571260
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x00571260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, while×3, return×2, do×2.
//  - Notable callees: FUN_00413be0×2, FUN_004294f0, FUN_00571260, FUN_00573040, LeaveCriticalSection.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00571260(int param_1,int param_2,byte param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int local_8;

  int local_4;

  

  iVar1 = param_2;

  if ((param_2 == 0) || (*(int *)(param_1 + 0x14) <= (int)(uint)param_3)) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 0x1c);

  iVar4 = iVar2 * (uint)param_3;

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x18)) {

    do {

      iVar5 = iVar4;

      if (iVar4 < iVar2 + iVar4) {

        do {

          iVar2 = *(int *)(param_1 + 0xc) * iVar3 + iVar5;

          if ((*(uint *)(*(int *)(param_1 + 0x28) + iVar2 * 8) &

              *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar2 * 8)) != 0xffffffff) {

            param_3 = '\0';

            param_2 = 0;

            FUN_004294f0();

            iVar2 = FUN_00413be0(&param_2,&local_8);

            while (iVar2 == 0) {

              iVar2 = *(int *)(param_1 + 0xc) * iVar3 + iVar5;

              if ((local_8 == *(int *)(*(int *)(param_1 + 0x28) + iVar2 * 8)) &&

                 (local_4 == *(int *)(*(int *)(param_1 + 0x28) + 4 + iVar2 * 8))) {

                param_3 = '\x01';

                break;

              }

              iVar2 = FUN_00413be0(&param_2,&local_8);

            }

            if (*(char *)(iVar1 + 0x28) != '\0') {

              *(uint8_t *)(iVar1 + 0x28) = 0;

              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));

            }

            if (param_3 == '\0') {

              iVar2 = *(int *)(param_1 + 0xc) * iVar3 + iVar5;

              FUN_00573040(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x28) + iVar2 * 8),

                           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x28) + 4 + iVar2 * 8));

            }

          }

          iVar2 = *(int *)(param_1 + 0x1c);

          iVar5 = iVar5 + 1;

        } while (iVar5 < iVar2 + iVar4);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x18));

  }

  return iVar1;

}
