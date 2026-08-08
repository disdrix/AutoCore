// =============================================================================
// FUN_00914c60  (clean twin of Client_SetModeLatch493_ParkDriveOnClear_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00914c60
// Address:   0x00914c60  (autoassault.exe, image base 0x400000)
// Body:      0x00914c60–0x00914ce5 inclusive (134 B / 0x86)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; R11-037 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B R11-037: accept-with-gaps.
// =============================================================================

// PURPOSE:
//   Client virtual thiscall: set/clear mode latch +0x493.
//   Clear path parks drive (StopHb+ZeroLong) + UI cleanup; both paths may
//   sync DAT_00d1b9a8 host; always zero f32 +0x538 then FUN_007902a0.

/*
 * Behavioral notes:
 * - CF ≡ live Ghidra decompile 2026-08-05 + disassemble_function + read_memory.
 * - +0x538 store is XORPS/MOVSS f32 zero (decompiler shows dword write).
 * - No direct callers; vtable DATA xref @ 0x00a2f468 only.
 * - Runtime / differential: OPEN.
 */

#include <cstdint>

extern int* DAT_00d1b9a8;

void FUN_007fb990(void);
void FUN_00914c20(void);   // Client_Vehicle_StopHbAndZeroLongitudinal_Inferred (EAX host)
void __thiscall FUN_007902a0(int param_1, char param_2);

void __thiscall FUN_00914c60(int param_1, std::uint32_t param_2)
{
  char cVar1;
  std::uint32_t uVar2;

  if ((char)param_2 == '\0') {
    if (*(char *)(param_1 + 0x493) == '\0') goto LAB_00914cce;
    FUN_007fb990();
    FUN_00914c20();
    if (DAT_00d1b9a8 == (int *)0x0) goto LAB_00914cce;
    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();
    if (cVar1 == '\0') goto LAB_00914cce;
    uVar2 = 0;
  }
  else {
    if ((*(char *)(param_1 + 0x493) != '\0') || (DAT_00d1b9a8 == (int *)0x0)) goto LAB_00914cce;
    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();
    if (cVar1 != '\0') goto LAB_00914cce;
    uVar2 = 1;
  }
  (**(code **)(*DAT_00d1b9a8 + 4))(uVar2);
LAB_00914cce:
  // retail: XORPS xmm0,xmm0 ; MOVSS [param_1+0x538], xmm0
  *(float *)(param_1 + 0x538) = 0.0f;
  FUN_007902a0(param_1, (char)param_2);
  return;
}
