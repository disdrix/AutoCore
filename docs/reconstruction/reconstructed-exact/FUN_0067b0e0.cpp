// =============================================================================
// FUN_0067b0e0 — netAddress_CopyAssign (scaffold)
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b0e0
// Address:   0x0067b0e0  (autoassault.exe, image base 0x400000)
// System:    network-nazgul-netAddress
// Generated: 2026-07-29 W25-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: POD copy of 16-byte Address (4 dwords) thiscall dest + stack src; ret 4.
// Stable ID: aa_0067b0e0
// Named twin: reconstructed-exact/netAddress_CopyAssign.cpp
// Dual: reviews/A_aa_0067b0e0_netAddress_CopyAssign.md + B_*

/*
 * Behavioral notes:
 * - Live decompile + read_memory 2026-07-29: body 0x0067b0e0–0x0067b102 (34 B).
 * - Epilogue C2 04 00 (ret 4). No callees. No branches.
 * - Cluster: 0067b070 ctor / this copy / 0067b110 dtor / 0067b120 assign.
 */

#include <cstdint>

void __thiscall FUN_0067b0e0(uint32_t *param_1 /* dest this */, uint32_t *param_2 /* src */)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}
