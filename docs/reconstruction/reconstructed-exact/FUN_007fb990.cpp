// =============================================================================
// FUN_007fb990  (clean twin of Client_UI_Host1144_QueryAndFade_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb990
// Address:   0x007fb990 – 0x007fb9d3 inclusive (68 B / 0x44)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Generated: 2026-08-05 R12-007 dual re-verify (live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: OPEN (no Launcher).
// Named plate: Client_UI_Host1144_QueryAndFade_Inferred.cpp
// =============================================================================

// PURPOSE: ESI-host leaf — query/state gates then fade dialog at host+0x1144
//           with (0, 0.1f). See named plate for install/caller evidence.

void FUN_007fb990(void)
{
  char cVar1;
  int iVar2;
  int unaff_ESI; // ESI = client UI host

  if (*(int *)(unaff_ESI + 0x1144) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xe8))();
      if (iVar2 != -1) {
        (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xfc))(0, 0x3dcccccd);
      }
    }
  }
  return;
}
