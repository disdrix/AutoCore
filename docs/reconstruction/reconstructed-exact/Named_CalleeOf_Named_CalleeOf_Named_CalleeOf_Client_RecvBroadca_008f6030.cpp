// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_008f6030
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6030
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
// Address:   0x008f6030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast: packet/network helper. Evidence string: "[1. General] %s: ". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "[1. General] %s: "
//   - "You told %s: "
//   - "[5. Looking For Convoy] %s: "
//   - "[4. Trade] %s: "
//   - "[6. Faction] %s: "
//   - "[2. French] %s: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×15, switch×1.
//  - Notable callees: FUN_008f6030.
//  - Strings: "%s broadcasts: "; "%s tells you: "; "%s tells the convoy: "; "%s tells the clan: ".
//  - Return sites: 15.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_008f6030(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  switch(in_EAX) {

  case 1:

    return "%s broadcasts: ";

  case 2:

    return "%s tells you: ";

  case 3:

    return "%s tells the convoy: ";

  case 4:

    return "%s tells the clan: ";

  case 5:

    return "[1. General] %s: ";

  case 6:

  case 10:

  case 0x18:

    return "%s: ";

  case 7:

    return "You told %s: ";

  case 8:

    return "[5. Looking For Convoy] %s: ";

  case 9:

    return "[4. Trade] %s: ";

  case 0xb:

    return "%s tells the new users clan: ";

  case 0xc:

    return "%s says ";

  case 0xd:

    return "[6. Faction] %s: ";

  case 0xe:

    return "[2. French] %s: ";

  case 0xf:

    return "[3. German] %s: ";

  default:

    return "%s";

  }

}
