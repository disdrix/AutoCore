// =============================================================================
// FUN_00513c10  (machine twin of Item_ValidateTinkerKitUse_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513c10
// Address:   0x00513c10  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-036 — leave-FUN twin; prefer named clean source.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named form: Item_ValidateTinkerKitUse_Inferred.cpp
// Prior scaffold: Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513c10
//   (retired — name was parent-string seed only).
//
// ABI: __thiscall ECX=item; stack character*, kit*; RET 8; EAX status 0..4.
//

extern char FUN_00513bc0(int *item_this, int kit);
extern int  FUN_00521eb0(void);

char __thiscall FUN_00513c10(int *param_1, int param_2, int param_3)
{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;

  if (param_3 == 0) {
    return '\x03';
  }
  if ((short *)(param_3 + 0xb0) != (short *)0x0) {
    cVar1 = FUN_00513bc0(param_1, param_3);
    if (cVar1 != '\0') {
      if (((unsigned)param_1[0x5f] >> 0x13 & 1) != 0) {
        return '\0';
      }
      sVar3 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4b4);
      sVar2 = (**(int (**)())(*param_1 + 0x8c))();
      if (sVar3 <= sVar2) {
        return '\0';
      }
      if (param_2 == 0) {
        return '\x03';
      }
      sVar3 = (**(int (**)())(*param_1 + 0x8c))();
      // ECX = param_2 (character) for FUN_00521eb0
      iVar4 = FUN_00521eb0();
      if ((iVar4 < sVar3 + 1) && (*(int *)(param_2 + 0x6b4) < 1)) {
        return '\x01';
      }
      return (sVar3 + 1 <= (int)*(short *)(param_3 + 0xb0)) * '\x02' + '\x02';
    }
  }
  return '\x03';
}
