// =============================================================================
// FUN_0096f660  /  Material_ReleaseAndNullField0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f660
// Address:   0x0096f660 – 0x0096f681  (34 B; autoassault.exe base 0x400000)
// System:    gfx / material resource
// Generated: 2026-07-29 W26-M (refined from 2026-07-23 scaffold)
// Exactness: Decompiler CF; fixed-width types (no bare undefined4).
// =============================================================================

#include <cstdint>

void __fastcall FUN_0096f660(int* param_1)
{
  int* piVar1;
  int iVar2;
  int* piVar3;

  iVar2 = *param_1;
  if (iVar2 != 0) {
    piVar3 = *reinterpret_cast<int**>(iVar2 + 0x18);
    if (piVar3 != nullptr) {
      piVar1 = piVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code**)(*piVar3 + 8))();
      }
    }
    *reinterpret_cast<uint32_t*>(iVar2 + 0x18) = 0;
  }
  return;
}
