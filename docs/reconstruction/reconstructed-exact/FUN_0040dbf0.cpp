// =============================================================================
// FUN_0040dbf0 / StdVector_InsertOne_RebindIt_Thiscall_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dbf0
// Address:   0x0040dbf0  (autoassault.exe, image base 0x400000)
// System:    util / container (std::vector dword)
// Generated: 2026-07-29 W16-G dual seal (from raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// =============================================================================
//
// PURPOSE:
//   Insert exactly one 4-byte element into an MSVC-style vector, then rebind an
//   out-iterator so it remains valid after a possible reallocation of begin.
//
// ABI (sealed from bytes C2 0C 00 + parent CVOGReaction_FailMissionNotify):
//   ECX        = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   stack arg0 = T** outIt
//   stack arg1 = T*  insert position
//   stack arg2 = const T* value
//   return     = void (*outIt written); ret 0x0C
//
// CALLEE:
//   FUN_004073a0 = StdVector_InsertN_Dword_Inferred (count forced to 1)
//
// TWIN:
//   aa_00466da0 StdVector_InsertOne_RebindIt_Inferred (custom EDI/EBX, FUN_00456960)
//
// READABILITY:
//   - Index saved before insert-N (load-bearing under realloc).
//   - Empty vector forces index 0.
//   - Ghidra raw elides `this` on the call site; bytes push pos/1/value and
//     set ECX = vector before the call.

// Forward decl (insert-N engine; dual-owned elsewhere)
void __thiscall FUN_004073a0(int vec, int pos, int count, unsigned int /*const T**/ value);

void __thiscall FUN_0040dbf0(int param_1, int *param_2, int param_3, unsigned int param_4)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(int *)(param_1 + 8) - iVar1 >> 2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - iVar1 >> 2;
  }
  // Bytes: push param_4; push 1; push param_3; mov ecx,param_1; call FUN_004073a0
  FUN_004073a0(param_1, param_3, 1, param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 4;
  return; // ret 0x0C
}
