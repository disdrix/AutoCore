// =============================================================================
// StdUninitFillN_Elem28_CountEcx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a260
// Address:   0x0046a260–0x0046a281  (autoassault.exe, image base 0x400000)
// Body:      34 B / 0x22; bare RET; pad CC then next @ 0x0046a290
// System:    stl-helpers / POD uninit fill-n (elem 0x1c)
// Generated: 2026-07-23 scaffold as FUN_0046a260; dual A/B seal 2026-07-29 (W36-M)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Write `count` copies of a 28-byte (7-dword) POD template into consecutive
//   slots starting at dest. Null-safe: if dest is NULL, skip stores but still
//   advance by 0x1c. Uses REP MOVSD for the 7-dword copy.
//
// ABI (register — not thiscall/stdcall):
//   ECX = count
//   EAX = dest* (write cursor; +0x1c each iteration)
//   EBX = template* (const Elem28 / 7 dwords; not advanced)
//   bare ret (no stack formals)
//
// Parents: FUN_00469c80 @ 0x00469cdb; StdVector_InsertN_Elem28_ValueEdx_Inferred
//          (FUN_00469f50) @ 0x0046a093, 0x0046a19e (W34-Q).
// Sibling: StdUninitFillN_Elem28_CountEax_Inferred (0x0045f150) — different ABI
//          (count EAX / dest EDX / tmpl ECX; explicit dword stores).
//
// Ghidra: FUN_0046a260
// Reject: Named_CalleeOf_*assPackManag*_0046a260
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

// Register ABI cannot be expressed portably; document contract in comment.
// Portable semantic equivalent:
void StdUninitFillN_Elem28_CountEcx_Inferred(uint32_t count,
                                             Elem28* dest,
                                             const Elem28* tmpl)
{
  if (count == 0) {
    return;
  }
  do {
    if (dest != nullptr) {
      // retail: MOV ECX,7 / MOV ESI,tmpl / MOV EDI,dest / REP MOVSD
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

// Scaffold / Ghidra alias (decompiler: count ECX; phantoms in_EAX / unaff_EBX)
extern "C" void FUN_0046a260(uint32_t count /*ECX*/,
                             Elem28* dest /*EAX*/,
                             const Elem28* tmpl /*EBX*/)
{
  StdUninitFillN_Elem28_CountEcx_Inferred(count, dest, tmpl);
}
