// =============================================================================
// CVOGSpawnPoint_ActivateFromStream_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00565950
// Address:   0x00565950 – 0x00566485  (2870 B / 0xB36)  autoassault.exe @ 0x400000
// System:    client spawn-point stream unpack + activation
// Wave:      W30-H OWN-ONLY dual (2026-07-29)
// Exactness: Named alias of CF-faithful body in FUN_00565950.cpp (scaffold twin).
//            Do not "modernize" the large SEH/stream body — port field-for-field.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Unpack a versioned spawn-point activation blob from a stream reader into a
//   CVOGSpawnPoint MI subobject, apply optional world float4 offset, clamp a bad
//   activation range to 75.0f, optionally spawn linked entities, and register
//   race/slot map entries (StdMap_InsertAlways_Val12_IntKey ×2 per active slot).
//
// ABI (bytes sealed)
//   thiscall; ECX = spawn-point subobject (negative field offsets vs ECX).
//   Stack cleaned by ret 0x10 (16 B). Decompiler formals:
//     stream* (null → return 0), version (int), float* worldOffset.
//   Fourth stack dword implied by ret size (role unsealed / unused in decomp).
//   Returns 0 if stream null, else 1.
//
// ENTRY PATH
//   MI this-adjustor thunk 0x00567CBE: sub ecx,[ecx-4]; jmp 0x00565950
//   (sole direct CODE xref — vtable slot).
//
// PRODUCT STRINGS
//   "******BAD SPAWN POINT ACTIVATION RANGE: %d %f"
//   "Spawn:%I64d"
//
// CONSTANTS
//   _DAT_009d2eb8 @ 0x009d2eb8 = 75.0f  (default activation range)
//
// NESTED SEALS
//   FUN_00567860 StdMap_InsertAlways_Val12_IntKey (W29-M)
//   FUN_0040b330 GetOrInsert by int key
//   Object_GetRootRaceId
//
// FULL BODY
//   Identical control flow to Ghidra live decompile 2026-07-29 ≡ raw 2026-07-23.
//   Authoritative line-by-line transcription:
//     docs/reconstruction/reconstructed-exact/FUN_00565950.cpp
// =============================================================================

// Named entry symbol for ports / cross-refs. Implementation body is the twin.
// MSVC-style thiscall; match FUN_00565950.

#include <cstdint>

extern "C" uint32_t __thiscall FUN_00565950(void* self, void* stream, void* version,
                                            float* world_offset4);

uint32_t __thiscall CVOGSpawnPoint_ActivateFromStream_Inferred(void* self, void* stream,
                                                               void* version,
                                                               float* world_offset4)
{
  return FUN_00565950(self, stream, version, world_offset4);
}
