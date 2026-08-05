// =============================================================================
// FourCCFnPtrMap_TryInsert_DAT_00d21958
// -----------------------------------------------------------------------------
// Stable ID: aa_00444850
// Address:   0x00444850  (autoassault.exe, image base 0x400000)
// System:    Palantir FourCC → function-pointer map
// Wave:      W35-H dual seal 2026-07-29
// Exactness: Bytes + caller sites; decompiler void prototype is incomplete.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Thin wrapper — insert (or find) {FourCC, handler*} into global
//          map DAT_00d21958 via FUN_00458510; discard out-pair.
// ABI: EAX=tag, ECX=handler*, bare RET, no stack formals.
// Callers: FUN_00754680 registers 'EFCT' and 'MRPH' during device start.
//

#include <cstdint>

struct MapOutPair { void* it; uint8_t inserted; uint8_t pad[3]; };

// Global tree-map object (MSVC-style head); layout unowned
extern uint8_t DAT_00d21958[];

// in_EAX = map*, EBX = &{uint32 key, void* value}, stack out pair*
MapOutPair* FUN_00458510(MapOutPair* out /*stack*/,
                         /*eax*/ void* map,
                         /*ebx*/ const void* key_value);

// Register formals — not stack
void FourCCFnPtrMap_TryInsert_DAT_00d21958(
    /*eax*/ uint32_t tag,
    /*ecx*/ void* handler)
{
  struct {
    uint32_t tag;
    void* handler;
  } key{tag, handler};
  MapOutPair out{};
  // image: MOV EAX, &DAT_00d21958; LEA EBX, &key; CALL FUN_00458510
  (void)FUN_00458510(&out, &DAT_00d21958, &key);
  // out discarded
}
