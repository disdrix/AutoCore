// =============================================================================
// Named_CalleeOf_Client_QuickBar_ActivateSlot_005710c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005710c0
// Callee of Client_QuickBar_ActivateSlot
// Address:   0x005710c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_005710c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_QuickBar_ActivateSlot
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

int * __thiscall Named_CalleeOf_Client_QuickBar_ActivateSlot_005710c0(int param_1,int param_2,char param_3,ushort param_4)



{

  ushort uVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar3 = FUN_004022a0(&local_4,&local_8);

  piVar2 = local_8;

  do {

    if (iVar3 != 0) {

      if (*(char *)(param_1 + 0x54) != '\0') {

        *(uint8_t *)(param_1 + 0x54) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

      }

      return (int *)0x0;

    }

    local_8 = piVar2;

    if ((piVar2 != (int *)0x0) && (iVar3 = piVar2[0x2a], *(int *)(iVar3 + 0x34) == param_2)) {

      if (param_3 != '\0') {

LAB_00571192:

        if (*(char *)(param_1 + 0x54) != '\0') {

          *(uint8_t *)(param_1 + 0x54) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

        }

        return piVar2;

      }

      if (((uint)piVar2[0x5f] >> 0x13 & 1) == 0) {

        if (*(int *)(iVar3 + 0x38) == 4) {

          uVar4 = 999999;

        }

        else {

          uVar1 = *(ushort *)(*(int *)(iVar3 + 0x3c) + 0x4ba);

          uVar4 = (uint)uVar1;

          if (uVar1 == 0) {

            uVar4 = 200;

          }

        }

        iVar3 = (**(code **)(*piVar2 + 0x25c))();

        if ((int)(iVar3 + (uint)param_4) <= (int)(uVar4 & 0xffff)) goto LAB_00571192;

      }

    }

    iVar3 = FUN_004022a0(&local_4,&local_8);

    piVar2 = local_8;

  } while( true );

}
