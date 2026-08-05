// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: for×4, return×1.
//  - Notable callees: Client_ActionMap_Init, Client_InitActionDisplayNames, Client_InitDefaultKeybinds.
//  - Return sites: 1.

// =============================================================================
// Client_ActionMap_Init
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9110
// Address:   0x007f9110  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (ActionMap construction)
// Generated: 2026-07-23 from raw capture
// Refined:   2026-07-23 human-refine — clear zero-fill regions + callee chain;
//            pActionMap rename (decomp unaff_ESI). CF ≡ raw.
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  ActionMap ctor/init. Install vtable, zero slot tables, then fill
//           display names and default DIK keybinds. Slot stride 0x34.
//
// Convention: ActionMap object pointer arrives in ESI (decomp unaff_ESI → pActionMap).
//             Callees Client_InitActionDisplayNames / Client_InitDefaultKeybinds
//             consume the same object via EAX / EDI (register-passing artifact).
//
// Callers:  FUN_009495c0 (client bootstrap; exact parent name open)
// Callees:  Client_InitActionDisplayNames  0x007f7570  aa_007f7570
//           Client_InitDefaultKeybinds     0x007f8720  aa_007f8720
//
// Related:
//   docs/reconstruction/systems/input-drive-control.md
//   docs/reconstruction/reconstructed-exact/Client_InitDefaultKeybinds.cpp
//   docs/reconstruction/reconstructed-exact/Client_InitActionDisplayNames.cpp
//   docs/reconstruction/reviews/A_aa_007f8720_Client_InitDefaultKeybinds.md
// =============================================================================

/*
 * Behavioral notes:
 * - Four dword memset-style loops clear disjoint table regions on the ActionMap.
 * - Display names then keybinds fill the zeroed slots (overwrite only name/key fields).
 * - Final store clears byte at +0x5 (init-complete / dirty flag — meaning tentative).
 *
 * Zero-fill regions (from base pActionMap):
 *   [+0x06,  +0x06 + 0x41*4)   first table block
 *   [+0x10a, +0x10a + 0x4e*4)  second block
 *   [+0x242, +0x242 + 0x618*4) main action-slot mass
 *   [+0x1aa2,+0x1aa2+ 0x104*4) tail block
 *
 * Readability pass:
 * - undefinedN → fixed-width; unaff_ESI → pActionMap.
 * - Control flow and call order preserved from authoritative raw.
 */

// Vtable for ActionMap class (Ghidra PTR_LAB)
extern void *PTR_LAB_00a84e08;
void Client_InitActionDisplayNames(void);
void Client_InitDefaultKeybinds(void);

void Client_ActionMap_Init(void)
{
  int iVar1;
  uint32_t /* width from decompiler */ *pActionMap; /* decomp unaff_ESI */
  uint32_t /* width from decompiler */ *puVar2;

  // ---------------------------------------------------------------------------
  // SECTION 1: Install ActionMap vtable
  // ---------------------------------------------------------------------------
  *pActionMap = (uint32_t /* width from decompiler */)&PTR_LAB_00a84e08;

  // ---------------------------------------------------------------------------
  // SECTION 2: Zero-fill table region A starting at +0x06 (0x41 dwords)
  // ---------------------------------------------------------------------------
  puVar2 = (uint32_t /* width from decompiler */ *)((int)pActionMap + 6);
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }

  // ---------------------------------------------------------------------------
  // SECTION 3: Zero-fill table region B starting at +0x10a (0x4e dwords)
  // ---------------------------------------------------------------------------
  puVar2 = (uint32_t /* width from decompiler */ *)((int)pActionMap + 0x10a);
  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }

  // ---------------------------------------------------------------------------
  // SECTION 4: Zero-fill main slot mass at +0x242 (0x618 dwords)
  // ---------------------------------------------------------------------------
  puVar2 = (uint32_t /* width from decompiler */ *)((int)pActionMap + 0x242);
  for (iVar1 = 0x618; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }

  // ---------------------------------------------------------------------------
  // SECTION 5: Zero-fill tail region at +0x1aa2 (0x104 dwords)
  // ---------------------------------------------------------------------------
  puVar2 = (uint32_t /* width from decompiler */ *)((int)pActionMap + 0x1aa2);
  for (iVar1 = 0x104; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }

  // ---------------------------------------------------------------------------
  // SECTION 6: Populate display names then default DIK keybinds
  // ---------------------------------------------------------------------------
  Client_InitActionDisplayNames();
  Client_InitDefaultKeybinds();

  // ---------------------------------------------------------------------------
  // SECTION 7: Clear status byte at +0x5
  // ---------------------------------------------------------------------------
  *(uint8_t *)((int)pActionMap + 5) = 0;
  return;
}
