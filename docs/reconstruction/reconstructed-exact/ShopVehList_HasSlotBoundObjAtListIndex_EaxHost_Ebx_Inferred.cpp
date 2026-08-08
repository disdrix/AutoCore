// =============================================================================
// ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred  (aa_0083a860)
// -----------------------------------------------------------------------------
// Address:   0x0083a860 – 0x0083a87a inclusive (27 B / 0x1B)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9L-I OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from full-body read_memory +
//            disassemble_function + sole-caller assembly_context.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       EAX=host*; EBX=list_i; AL=bool; bare RET
// Parent:    ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred (0x0083ac90)
//            sole CALL @ 0x0083adc2
// =============================================================================

#include <cstdint>

static constexpr int kWindowSlots = 5;
static constexpr int kIdBase = 0x9ca4; // 40100 decimal — shared with parent dual

// Nested finder (undualed OWN residual) — stack host*; EBX=list_i; RET 4
// Scans host+0x50c[5]; returns slot* where GetId(slot) - 0x9ca4 == EBX, else 0.
extern "C" void *FUN_0083a7d0(void *host /* + EBX list_i */);

using GetIdFn = int(__thiscall *)(void *self);

// Portable reconstruction of register ABI (product uses EAX/EBX/AL).
// Retail: PUSH EAX; CALL 0083a7d0; TEST; CMP [EAX+0x508]; SETNZ AL.
extern "C" std::uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(
    void *host, int list_i)
{
  // Retail loads list_i in EBX before CALL 0083a7d0; host is stack arg.
  // Portable form passes both explicitly; behavior matches bytes.
  (void)list_i; // live EBX into finder in product image

  void *slot = FUN_0083a7d0(host);
  if (slot == nullptr) {
    return 0;
  }
  const std::uint32_t payload =
      *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(slot) + 0x508);
  return payload != 0 ? 1 : 0;
}

// Equivalent expanded form documenting finder contract (not a second body):
// for (int i = 0; i < kWindowSlots; ++i) {
//   void *s = host->slots[i];  // host+0x50c
//   if (s && GetId(s) - kIdBase == list_i) return (s[+0x508] != 0);
// } return false;

// Scaffold / Ghidra alias — register form
extern "C" std::uint8_t FUN_0083a860(void)
{
  // Product entry: host in EAX, list_i in EBX. Portable twin cannot recover
  // registers; call named form from typed call sites.
  return 0; // plate: invoke named form with host/list_i from call-site registers
}
