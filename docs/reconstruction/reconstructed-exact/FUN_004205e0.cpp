// =============================================================================
// FUN_004205e0  /  OleDb_WalkActiveBindings_Vtbl10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004205e0
// Address:   0x004205e0 – 0x00420623  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor bind (skill DbLoad plumbing)
// Generated: 2026-07-23 scaffold; dual-refined 2026-07-29 (W16-F)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Convention: no stack args; context in ESI; plain ret
// =============================================================================

// PURPOSE:
//   Walk binding table at ESI[2]: for each entry (stride 8) with active flag
//   at entry+4 != 0, invoke (*( *ESI )->vtbl + 0x10)(iface, ESI[3],
//   entry_dword, table[2]). Return first negative HRESULT, else last hr (0 if
//   none failed).
//
// Sole caller: FUN_0041c000 (OleDb_RebindAccessor) — if this returns < 0 after
// successful CreateAccessor-shaped call, rebind path re-releases the handle.
//
// On standard IAccessor, vtbl+0x10 is CreateAccessor (see aa_004231d0 dual).

// READABILITY:
//  - Control keywords: if×2, do/while×1, return×2
//  - No named callees (indirect vtbl+0x10 only)

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; live re-verify 2026-07-29 ≡ raw.
 * - unaff_ESI is ambient register context (confirmed by entry bytes mov ecx,[esi+8]).
 */

int FUN_004205e0(void)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  uint uVar4;

  uVar1 = *(uint *)(unaff_ESI[2] + 4);
  iVar3 = 0;
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      piVar2 = (int *)unaff_ESI[2];
      if ((*(char *)(*piVar2 + 4 + uVar4 * 8) != '\0') &&
         (iVar3 = (**(code **)(*(int *)*unaff_ESI + 0x10))
                            ((int *)*unaff_ESI, unaff_ESI[3],
                             *(undefined4 *)(*piVar2 + uVar4 * 8), piVar2[2]),
          iVar3 < 0)) {
        return iVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return iVar3;
}
