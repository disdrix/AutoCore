// =============================================================================
// LogicUiEventQueue_InsertOne_GrowPath
// -----------------------------------------------------------------------------
// Stable ID: aa_004068f0
// Address:   0x004068f0 – 0x00406964  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004068f0
// System:    client-logic-ui / event queue
// Generated: 2026-07-29 W22-I dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Capacity overflow / reallocate path for Logic-UI event enqueue
//   (sole caller Client_SendLogicUiPacket @ 0x004059f0).
//   Save element index from insert iterator, grow-insert one 0x138-byte slot
//   via FUN_004076a0, then write the (possibly rebased) slot pointer to *out.
//
// ABI (sealed from bytes):
//   __thiscall RET 0xC
//   ECX = queue*  begin@+4  end@+8  cap@end@+0xC
//   stack0 = void** outSlot
//   stack1 = void*  insertAt
//   stack2 = uint32_t payload (forwarded to insert-N)
//
// STRIDE: 0x138 (312). Twin of CombatFloaterQueue_InsertOne_GrowPath (0x38).
// =============================================================================

void __thiscall LogicUiEventQueue_InsertOne_GrowPath(
    int this_queue,
    int *out_slot,
    int insert_at,
    uint32_t payload)
{
  int index;
  int begin;

  begin = *(int *)(this_queue + 4);
  if (begin != 0) {
    if ((*(int *)(this_queue + 8) - begin) / 0x138 != 0) {
      index = (insert_at - begin) / 0x138;
      goto LAB_00406939;
    }
  }
  index = 0;
LAB_00406939:
  // FUN_004076a0(this_queue, insert_at, count=1, payload) — may realloc
  FUN_004076a0(insert_at, 1, payload);
  *out_slot = *(int *)(this_queue + 4) + index * 0x138;
  return;
}
