// =============================================================================
// Object_HasFlag8SelfOrLinked  (FUN_005134e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005134e0
// Address:   0x005134e0  (autoassault.exe, image base 0x400000)
// System:    targeting / object-flags
// Generated: 2026-07-29 W17-E dual (from raw + live decompile/read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Link-aware predicate — true if object has flag mask 0x08 at +0x184,
// or (when +0xac parent link exists) if related/parent also carries the same
// logical flag. Callers use true as reject/exclude/remove gate.

// Signature (bytes): ECX = object; no stack args; bool in AL; ret (c3).

bool __fastcall Object_HasFlag8SelfOrLinked(int obj)
{
  int iVar1;
  bool bVar2;

  if (*(int **)(obj + 0xac) == (int *)0x0) {
    return (*(unsigned int *)(obj + 0x184) & 8) != 0;
  }
  iVar1 = (**(int (**)())(**(int **)(obj + 0xac) + 0x19c))();
  bVar2 = (*(unsigned char *)(obj + 0x184) & 8) != 0;
  if (iVar1 != 0) {
    return bVar2 ||
           (*(unsigned char *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x188 + iVar1) & 8) != 0;
  }
  return bVar2 || (*(unsigned char *)(*(int *)(obj + 0xac) + 0x184) & 8) != 0;
}
