// =============================================================================
// RPC_rpcMsgGuaranteedOrdered_Execute
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2a50
// Address:   0x005a2a50  (autoassault.exe, image base 0x400000)
// System:    network-tnl-rpc
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - TNL RPCEvent Execute / CheckClassType gate only.
 * - True iff param is TNLConnection (RTTI cast from TNL::Object).
 * - Shared by six DATA vtable Execute slots (0x009d7c84 + i*0x30).
 * - Symbol name says GuaranteedOrdered; body is reliability-agnostic.
 * - AutoCore mirror: TNLConnection.RPCMsg*.CheckClassType
 *     => (obj as TNLConnection) != null
 * - Callee: __RTDynamicCast only. No pack/unpack/dispatch of payload.
 *
 * ABI: stdcall, one stack pointer arg, ret 4; bool in EAX as 0/1.
 */

// External CRT / RTTI (addresses in autoassault.exe image):
//   TNL::Object::RTTI_Type_Descriptor     @ 0x00b00ba4  (".?AVObject@TNL@@")
//   TNLConnection::RTTI_Type_Descriptor   @ 0x00af3a48  (".?AVTNLConnection@@")

extern "C" void *__cdecl __RTDynamicCast(
    void *inObj,
    long vfDelta,
    void *srcType,
    void *targetType,
    int isRef);

extern void *TNL_Object_RTTI_Type_Descriptor;       /* 0x00b00ba4 */
extern void *TNLConnection_RTTI_Type_Descriptor;  /* 0x00af3a48 */

bool __stdcall RPC_rpcMsgGuaranteedOrdered_Execute(void *obj /* TNL::Object* */)
{
  void *casted = __RTDynamicCast(
      obj,
      /* VfDelta */ 0,
      &TNL_Object_RTTI_Type_Descriptor,
      &TNLConnection_RTTI_Type_Descriptor,
      /* isRef */ 0);
  return casted != 0;
}
