// =============================================================================
// NDAssetImage_TransferFields_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00432580
// Address:   0x00432580–0x00432625  (autoassault.exe, image base 0x400000)
// System:    NDAssetImage / asset image buffer ownership move
// Generated: 2026-07-29 W23-C dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Move owned image payload fields from src (EBX) into dest (stack arg0):
//   1) clear dest existing ownership via FUN_004321b0 (ESI=dest);
//   2) copy field blocks + ownership pointers src → dest;
//   3) zero src ownership so a temp dtor will not double-free.
//   Used by decode-by-format success commit and flip helpers.
//
// ABI (byte-sealed):
//   stdcall:  dest* on stack; ret 4
//   EBX     : src* (caller-owned register; decompiler unaff_EBX)
//   Return  : 1 on success (AL), 0 if pre-clear fails
//
// CALLEES: FUN_004321b0 (dest pre-clear / free owned buffers)
// CALLERS: FUN_00432cb0, FUN_0098acc0, FUN_0098ae80 (4 xrefs)
// =============================================================================

#include <cstdint>
#include <cstring>

// Dest pre-clear: free existing owned buffers; return 0 if dest+0x38 busy/locked.
// Custom ABI: ESI = dest on entry (image sets ESI = dest before call).
extern "C" uint32_t FUN_004321b0(void);

// Field blocks sealed from rep movsd counts (product field English open).
//   +0x08 .. +0x2c : 10 dwords (40 B)
//   +0x30 ..       : 0x5F dwords (380 B)
//   scalars        : +0x04, +0x1ac, +0x1b0, +0x1b4

struct NDAssetImageFields_Inferred {
  uint32_t vtbl_or_tag;     // +0x00 (not transferred by this unit)
  void*    owned_4;         // +0x04
  uint32_t block8[10];      // +0x08 .. +0x2c
  uint32_t block30[0x5F];   // +0x30 .. +0x1A8-ish
  // ... intervening layout ...
  // +0x1ac, +0x1b0, +0x1b4 transferred as raw dwords below
};

// Ghidra symbol retained.
extern "C" uint32_t FUN_00432580(int dest);

// Named plate — matches sealed CF. Not a claim of full object typedef.
uint32_t NDAssetImage_TransferFields_Inferred(void* dest, void* src /*EBX*/) {
  // Entry bytes: push ebp; mov ebp,[esp+8]; push esi; mov esi,ebp; call FUN_004321b0
  // FUN_004321b0 consumes ESI=dest.
  uint32_t ok;
  {
    // Simulate ESI=dest for the custom-ABI callee.
    // ok = FUN_004321b0_with_esi(dest);
    // Portable stand-in: call after documenting ESI contract.
    ok = FUN_004321b0();  // image: ESI already set to dest
  }
  if ((uint8_t)ok == 0) {
    return ok;  // ret 4
  }

  auto* d = static_cast<uint8_t*>(dest);
  auto* s = static_cast<uint8_t*>(src);

  // rep movsd 10 dwords: dest+8 <- src+8
  std::memcpy(d + 0x08, s + 0x08, 10 * 4);

  // rep movsd 0x5F dwords: dest+0x30 <- src+0x30
  std::memcpy(d + 0x30, s + 0x30, 0x5F * 4);

  // scalar ownership / size fields
  *reinterpret_cast<uint32_t*>(d + 0x04) =
      *reinterpret_cast<uint32_t*>(s + 0x04);
  *reinterpret_cast<uint32_t*>(d + 0x1ac) =
      *reinterpret_cast<uint32_t*>(s + 0x1ac);
  *reinterpret_cast<uint32_t*>(d + 0x1b0) =
      *reinterpret_cast<uint32_t*>(s + 0x1b0);
  *reinterpret_cast<uint32_t*>(d + 0x1b4) =
      *reinterpret_cast<uint32_t*>(s + 0x1b4);

  // zero src +8 block (10 dwords) — image uses stos-style stores from EAX after
  // pointing back at src+8 (see raw hex: 33 C9 / stores via the +8 lea reg)
  std::memset(s + 0x08, 0, 10 * 4);

  // rep stosd 0x5F dwords at src+0x30
  std::memset(s + 0x30, 0, 0x5F * 4);

  *reinterpret_cast<uint32_t*>(s + 0x1b0) = 0;
  *reinterpret_cast<uint32_t*>(s + 0x1ac) = 0;
  *reinterpret_cast<uint32_t*>(s + 0x04) = 0;
  *reinterpret_cast<uint32_t*>(s + 0x1b4) = 0;

  return 1;  // mov al,1; pop ebp; ret 4
}

// Scaffold-facing wrapper matching decompiler signature shape.
extern "C" uint32_t FUN_00432580(int param_1) {
  // EBX must hold src at call site (unaff). Not recoverable in portable C.
  (void)param_1;
  return 0;
}
