// =============================================================================
// StdUninitFillN_Elem28_CountEax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f150
// Address:   0x0045f150–0x0045f198  (autoassault.exe, image base 0x400000)
// Body:      73 B / 0x49; bare RET; pad CC then next @ 0x0045f1a0
// System:    stl-helpers / POD uninit fill-n (elem 0x1c)
// Generated: 2026-07-23 scaffold as FUN_0045f150; dual A/B seal 2026-07-29 (W35-L)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Write `count` copies of a 28-byte (7-dword) POD template into consecutive
//   slots starting at dest. Null-safe: if dest is NULL, skip stores but still
//   advance by 0x1c (same pattern as Mem_FillDwordN_FromSrc_EaxEcxEdx).
//
// ABI (register — not thiscall/stdcall):
//   EAX = count
//   ECX = template* (const Elem28 / 7 dwords; not advanced)
//   EDX = dest* (write cursor; +0x1c each iteration)
//   bare ret (no stack formals)
//
// Parents: StdVector_InsertN_Pod28 (FUN_0045cd30) @ 0x0045ceae, 0x0045cfb7.
// Sibling: FUN_0046a260 (fill-n, different ABI: count ECX / dest EAX / tmpl EBX).
//
// Ghidra: FUN_0045f150
// Reject: Named_CalleeOf_*anmTrackMast_0045f150
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

// Register ABI cannot be expressed portably; document contract in comment.
// Portable semantic equivalent:
void StdUninitFillN_Elem28_CountEax_Inferred(uint32_t count,
                                             const Elem28* tmpl,
                                             Elem28* dest)
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
    dest = dest + 1; // +0x1c
    count = count - 1;
  } while (count != 0);
}

// Scaffold / Ghidra alias (decompiler formals + phantom count)
extern "C" void FUN_0045f150(const Elem28* tmpl /*ECX*/, Elem28* dest /*EDX*/,
                             uint32_t count /*EAX*/)
{
  StdUninitFillN_Elem28_CountEax_Inferred(count, tmpl, dest);
}
