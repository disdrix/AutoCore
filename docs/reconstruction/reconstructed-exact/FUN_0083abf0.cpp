// =============================================================================
// FUN_0083abf0  (twin of ShopVehList_BindSlotFromListIndexIfMismatch_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0083abf0
// Address:   0x0083abf0 – 0x0083ac89 inclusive (154 B / 0x9A)
// Dual:      WQ9L-J 2026-08-05 — accept-with-gaps
// Note:      Ghidra-style twin. Product: ECX=slot, EDX=list_i, stack host, RET 4.
//            Named clean is authoritative for porting.
//            Decompiler's FUN_0083ab90(host) understates ECX/EAX/stack ABI.
// =============================================================================

#include <cstdint>

extern "C" char FUN_00427d20(uint32_t index, void **out_entity /* + EDI container */);
extern "C" void FUN_0083ab90(void *slot_obj /* ECX */, void *host /* stack */,
                             int entity_id /* EAX */);

// Modeled with explicit formals; retail: ECX, EDX, stack host, RET 4.
extern "C" void FUN_0083abf0(int param_1_slot, int param_2_list_i, int *param_3_host)
{
  int iVar1;
  int iVar2 = reinterpret_cast<int>(param_3_host);
  int *piVar3;
  char cVar4;
  int iVar5;

  if (!((-1 < param_2_list_i) &&
        (*(int *)(reinterpret_cast<int>(param_3_host) + 0x508) != 0) &&
        (-1 < param_1_slot) &&
        (param_1_slot < 5 &&
         (iVar1 = *(int *)(reinterpret_cast<int>(param_3_host) + 0x50c +
                           param_1_slot * 4),
          iVar1 != 0)) &&
        (*(int *)(*(int *)(reinterpret_cast<int>(param_3_host) + 0x508) + 0x50) !=
         0))) {
    return;
  }

  // param_3 reused as out-entity local (decompiler)
  param_3_host = nullptr;
  cVar4 = FUN_00427d20(static_cast<uint32_t>(param_2_list_i),
                       reinterpret_cast<void **>(&param_3_host));
  piVar3 = param_3_host;
  if (cVar4 == '\0' || param_3_host == nullptr) {
    return;
  }

  iVar5 = (**(int(__thiscall ***)(int *))(*param_3_host + 0x1d4))(param_3_host);
  if (iVar5 == 0) {
    return;
  }

  if (*(int *)(iVar1 + 0x508) != 0) {
    int bound = *(int *)(iVar1 + 0x50c);
    iVar5 = (**(int(__thiscall ***)(int *))(*piVar3 + 0x1d4))(piVar3);
    if (bound == iVar5) {
      return;
    }
  }

  (**(int(__thiscall ***)(int *))(*piVar3 + 0x1d4))(piVar3);
  FUN_0083ab90(reinterpret_cast<void *>(iVar1), reinterpret_cast<void *>(iVar2),
               /* EAX from vcall */ 0);
  (void)iVar2;
}
