// =============================================================================
// AnmTrackEvents_UnserializeOneEvent_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Unserialize one anmTrackEvents event entry:
//           read FOURCC/key from stoChunkReader (EDI), look up NestedHash0x10
//           factory bag (static once-get DAT_00d1fcc0), invoke node factory,
//           store object, then call object vtbl[+4] with EDI for body fill.
//
// Address:  0x0044fe10  (autoassault.exe, image base 0x400000)
// Body:     0x0044fe10–0x0044fe65 (86 B / 0x56)
// Stable:   aa_0044fe10
// System:   anmTrackEvents / NestedHash factory dispatch
// Ghidra:   FUN_0044fe10
//
// Caller:   FUN_00987750 (anmTrackEvents.cpp unserialize event loop) @ 0x00987987
// Family:   uses NestedHash0x10_StaticOnceGet_d1fcc0_Inferred (W35-E);
//           NestedHash lookup FUN_0046c1b0; key read FUN_0076a900.
//
// Exactness: CF mirrors raw + read_memory; names structural _Inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W36-G seal).
// =============================================================================

/* AnmTrackEvents_UnserializeOneEvent_Inferred

   Parameters:
     out_event — stack out-param; receives factory object pointer or null.
     EDI       — stoChunkReader* (register formal; not stack).

   Returns:
     On hit:  result of object->vtbl[+4] thiscall (EDI pushed as stack arg).
     On miss: 0xffffffff.
*/

extern uint32_t FUN_0076a900(void); /* ESI = chunk reader */
extern void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void); /* FUN_0044fee0 */
/* NestedHash lookup: ESI = bag, ECX = &key, EAX = &node_out (fastcall-ish) */
extern void __fastcall FUN_0046c1b0(uint32_t *key /* ECX */);

uint32_t AnmTrackEvents_UnserializeOneEvent_Inferred(void **out_event)
{
  uint32_t key;
  void *bag;
  void *node;
  void *obj;
  uint32_t status;

  /* ESI ← EDI (chunk reader) before key read — see raw byte notes */
  key = FUN_0076a900();

  bag = NestedHash0x10_StaticOnceGet_d1fcc0_Inferred();
  /* ESI = bag for lookup; node written through out pointer */
  node = 0;
  FUN_0046c1b0(&key);

  bag = NestedHash0x10_StaticOnceGet_d1fcc0_Inferred();
  if (node == *(void **)((unsigned char *)bag + 8)) {
    obj = 0; /* NestedHash sentinel → miss */
  } else {
    /* thiscall factory at node vtbl slot +0xC */
    obj = (*(void *(__thiscall **)(void *))(*(uint32_t *)node + 0xC))(node);
  }

  *out_event = obj;
  if (obj != 0) {
    /* thiscall obj->vtbl[+4]; EDI pushed as stack arg (bytes: 57 FF 52 04) */
    status = (*(uint32_t(__thiscall **)(void *))(*(uint32_t *)obj + 4))(obj);
    return status;
  }
  return 0xffffffffu;
}
