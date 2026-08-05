// =============================================================================
// Host_ActionList_Push  (was FUN_00507290)
// -----------------------------------------------------------------------------
// Stable ID: aa_00507290
// Address:   0x00507290  (autoassault.exe, image base 0x400000)
// Body:      0x00507290–0x005072c5
// System:    physics / action host list
// Dual A/B:  2026-07-29 W19-O  accept
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seal.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Append a pointer (typically a physics action*) into the host's growable
//   pointer vector at host+0x94 (count +0x98, capacity +0x9c).
//   Grows via FUN_005b3370 when count == (capacity & 0x7fffffff).
//
// SIGNATURE
//   void __thiscall Host_ActionList_Push(void* host, void* itemPtr);
//   // ECX = host; stack = item; RET 4
//
// KEY OFFSETS
//   host+0x94  void** data
//   host+0x98  int    count
//   host+0x9c  uint   capacity (mask 0x7fffffff for compare)
//
// CALLERS (ECX = host at each site — decompiler often shows incomplete)
//   Phys_ActionBase_ctor 0x00636370
//   FUN_00636220
//   FUN_0066e660 (×2 — primary host + secondary host)
//
// NOTE
//   Does not addref. Callers (e.g. Phys_ActionBase_ctor) addref host separately.
// =============================================================================

void __thiscall Host_ActionList_Push(int host, void *itemPtr)
{
  if (*(unsigned int *)(host + 0x98) ==
      (*(unsigned int *)(host + 0x9c) & 0x7fffffff)) {
    FUN_005b3370((int *)(host + 0x94), 4);
  }
  *(void **)(*(int *)(host + 0x94) + *(int *)(host + 0x98) * 4) = itemPtr;
  *(int *)(host + 0x98) = *(int *)(host + 0x98) + 1;
  return;
}
