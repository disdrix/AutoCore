// =============================================================================
// FUN_00871150  (alias of UiHost_RefreshTrackedNodeWidgets_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00871150
// Address:   0x00871150 – 0x008715f8  (autoassault.exe, base 0x400000)
// Dual:      W21-S 2026-07-29
// Prefer:    UiHost_RefreshTrackedNodeWidgets_Inferred.cpp
// =============================================================================

// Forward to named reconstruction. Full body lives in the named unit file.
// This file retains the scaffold symbol for xref continuity.

void UiHost_RefreshTrackedNodeWidgets_Inferred(void* host /*EAX*/, int* node /*stack*/);

// Retail ABI: host in EAX, node on stack, ret 4.
void FUN_00871150(int* node)
{
  // Callers: mov eax, host; push node; call FUN_00871150
  UiHost_RefreshTrackedNodeWidgets_Inferred(/*EAX host*/ nullptr, node);
}

/*
 * Sealed facts (see named unit + dual reviews):
 * - Body 0x00871150–0x008715f8 (1192 B), ret 4
 * - Gate: vtbl+0x3d8 visible; null node
 * - FUN_007fd970 after CL = *(u8*)(node+0x1c) - 0x0f
 * - Widget bank host+0x5e8/5ec/5f0/5f4/5f8/5fc/600
 * - Node id pair +8/+0xc; ushort +0x14; short +0x1c
 * - Selection rebind via DAT_00d1b6d8 +0x164/+0x168
 */
