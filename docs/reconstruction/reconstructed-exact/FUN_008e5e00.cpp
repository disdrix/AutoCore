// =============================================================================
// FUN_008e5e00  (Ghidra twin of Client_UI_CraftHost_RefreshMaterialList_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5e00
// Address:   0x008e5e00–0x008e6386  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      R10-015 2026-08-05 — accept-with-gaps
//
// Canonical clean (meaningful name):
//   docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp
//
// This twin keeps the Ghidra symbol as the entry name for searchability.
// Behavior-preserving notes live in the named clean + annotated raw.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// =============================================================================

// PURPOSE: Refresh craft host list widget (host+0x754) from cargo + locker +
// equip inventory sources; restore selection; rebind via FUN_008e5ce0 if TFID
// selection changes. Host arrives in EDI; plain RET; no stack args.
//
// Embedded strings:
//   "[M]"  DAT_00a3af60  (equip prefix)
//   "[L]"  DAT_00a3af64  (locker prefix)
//   "%s %s" DAT_00a34304
//
// See named clean for annotated control flow and dual-sealed ABI.

void FUN_008e5e00(void);

// Implementation: see Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp
// (EDI-host modeled as explicit host* parameter in the named clean).
