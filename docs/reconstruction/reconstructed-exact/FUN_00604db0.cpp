// =============================================================================
// FUN_00604db0  (scaffold — prefer CVOGHBBase_SetPartnerLink)
// -----------------------------------------------------------------------------
// Stable ID: aa_00604db0
// Address:   0x00604db0  (autoassault.exe, image base 0x400000)
// System:    object / combat-target / HB
// Generated: 2026-07-23 scaffold; 2026-07-29 W20-S plate refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: leaf body sealed via read_memory (W20-S).
// Dual: accept — A/B_aa_00604db0_CVOGHBBase_SetPartnerLink
// =============================================================================

// PURPOSE: CVOGHBBase partner link setter at +0x24 with same-owner skip gate.
// ABI: __thiscall, RET 4.

/*
 * Behavioral notes:
 * - if (partner==0 || partner[+0x18] != this[+0x18]) this[+0x24] = partner;
 * - Sole caller Object_SetSelectedTarget (two sites, both directions).
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __thiscall FUN_00604db0(int param_1, int param_2)
{
  if ((param_2 == 0) || (*(int *)(param_2 + 0x18) != *(int *)(param_1 + 0x18))) {
    *(int *)(param_1 + 0x24) = param_2;
  }
  return;
}
