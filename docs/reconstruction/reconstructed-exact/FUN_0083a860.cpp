// =============================================================================
// FUN_0083a860  — twin of ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a860
// Address:   0x0083a860 – 0x0083a87a inclusive (27 B / 0x1B)
// Wave:      WQ9L-I OWN-ONLY dual 2026-08-05
// Note:      Named implementation is the authority. Product ABI is register
//            (EAX=host*, EBX=list_i, AL=bool). This twin documents the Ghidra
//            symbol and delegates the portable two-arg form.
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(
    void *host, int list_i);

// Byte-faithful register contract (for documentation / call-graph):
//   PUSH EAX              ; host
//   CALL FUN_0083a7d0     ; EBX = list_i live; RET 4; EAX = slot* or 0
//   TEST EAX,EAX / JZ miss
//   CMP [EAX+0x508], 0 / SETNZ AL / RET
// miss: XOR AL,AL / RET
//
// Portable entry used by typed reconstruction (pass host + list_i explicitly).
extern "C" std::uint8_t FUN_0083a860_portable(void *host, int list_i)
{
  return ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(host, list_i);
}

// Ghidra symbol stub — register ABI not expressible as C formals alone.
extern "C" std::uint8_t FUN_0083a860(void)
{
  return FUN_0083a860_portable(/*host from EAX*/ nullptr, /*list_i from EBX*/ 0);
}
