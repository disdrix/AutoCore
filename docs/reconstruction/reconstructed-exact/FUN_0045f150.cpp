// =============================================================================
// FUN_0045f150 — twin of StdUninitFillN_Elem28_CountEax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f150
// Address:   0x0045f150–0x0045f198  (autoassault.exe, image base 0x400000)
// Body:      73 B / 0x49; bare RET
// System:    stl-helpers / POD uninit fill-n (elem 0x1c)
// Generated: scaffold 2026-07-23; dual A/B seal 2026-07-29 (W35-L)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Canonical name: StdUninitFillN_Elem28_CountEax_Inferred
// See: StdUninitFillN_Elem28_CountEax_Inferred.cpp
//
// ABI: EAX=count, ECX=template*, EDX=dest*; bare RET; leaf
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

extern "C" void FUN_0045f150(const Elem28* tmpl /*ECX*/, Elem28* dest /*EDX*/,
                             uint32_t count /*EAX*/)
{
  if (count == 0) {
    return;
  }
  do {
    if (dest != nullptr) {
      dest->w[0] = tmpl->w[0];
      dest->w[1] = tmpl->w[1];
      dest->w[2] = tmpl->w[2];
      dest->w[3] = tmpl->w[3];
      dest->w[4] = tmpl->w[4];
      dest->w[5] = tmpl->w[5];
      dest->w[6] = tmpl->w[6];
    }
    dest = dest + 1;
    count = count - 1;
  } while (count != 0);
}
