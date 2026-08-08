// =============================================================================
// FUN_00518e30  (scaffold twin → see Object_CreateOrRecreateSkillHash_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00518e30
// Address:   0x00518e30  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-J dual seal
// Exactness: Behavior-preserving; clean named twin is authoritative for ports.
// =============================================================================

void *__cdecl operator_new(unsigned int size);
void __thiscall FUN_004cbdc0(void *hash, unsigned char log2);
void *__thiscall FUN_0051dd60(void *hashMem, unsigned char log2);

void __thiscall FUN_00518e30(int param_1, unsigned char param_2)
{
  void *pvVar1;
  void *uVar2;

  // SEH LAB_009a3627 omitted

  if (*(int *)(param_1 + 0x70) != 0) {
    FUN_004cbdc0(*(void **)(param_1 + 0x70), param_2);
    return; // ret 4
  }

  pvVar1 = operator_new(0x34);
  if (pvVar1 != 0) {
    uVar2 = FUN_0051dd60(pvVar1, param_2);
    *(void **)(param_1 + 0x70) = uVar2;
    return; // ret 4
  }

  *(int *)(param_1 + 0x70) = 0;
  return; // ret 4
}
