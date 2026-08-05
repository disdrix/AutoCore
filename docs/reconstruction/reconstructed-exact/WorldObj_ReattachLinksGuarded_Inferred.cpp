// =============================================================================
// WorldObj_ReattachLinksGuarded_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00560f30
// Address:   0x00560f30  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00560f30
// Body:      0x00560f30–0x00560f60 (48 B); ret 4
// System:    world-object / phys rebind
// Dual:      2026-07-29 W27-O
// =============================================================================
//
// ABI: __thiscall  ECX = Manager*; stack = WorldObj*; void; ret 4
//
// CF:
//   1. prev = *(uint8*)(manager + 0x12c); *(manager + 0x12c) = 1
//   2. FUN_0055e760(obj)   // attach/register onto manager
//   3. FUN_0055fa40(obj)   // WorldObj_BindLinks_Inferred
//   4. *(manager + 0x12c) = prev
//
// Caller: FUN_005d4440 when new HBAI mode code == 7 (PUSH obj; MOV ECX,mgr).
// Not enroll (no counters/refcount). Not RebindActivate (no 0055fbf0 unbind).

void __thiscall WorldObj_ReattachLinksGuarded_Inferred(int manager, uint32_t obj)
{
  uint8_t prevFlag;

  prevFlag = *(uint8_t *)(manager + 300);
  *(uint8_t *)(manager + 300) = 1;
  FUN_0055e760(obj);
  FUN_0055fa40(obj);
  *(uint8_t *)(manager + 300) = prevFlag;
  return;
}
