// =============================================================================
// FUN_0046a260 — twin of StdUninitFillN_Elem28_CountEcx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a260
// Address:   0x0046a260–0x0046a281  (autoassault.exe, image base 0x400000)
// Body:      34 B / 0x22; bare RET
// System:    stl-helpers / POD uninit fill-n (elem 0x1c)
// Generated: scaffold 2026-07-23; dual A/B seal 2026-07-29 (W36-M)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Canonical name: StdUninitFillN_Elem28_CountEcx_Inferred
// See: StdUninitFillN_Elem28_CountEcx_Inferred.cpp
//
// ABI: ECX=count, EAX=dest*, EBX=template*; bare RET; leaf
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

extern "C" void FUN_0046a260(uint32_t count /*ECX*/,
                             Elem28* dest /*EAX*/,
                             const Elem28* tmpl /*EBX*/)
{
  for (; count != 0; count = count - 1) {
    if (dest != nullptr) {
      // retail: ECX=7, ESI=tmpl, EDI=dest, REP MOVSD
      const uint32_t* src = tmpl->w;
      uint32_t* dst = dest->w;
      for (int i = 7; i != 0; i = i - 1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
      }
    }
    dest = dest + 1; // +0x1c
  }
}
