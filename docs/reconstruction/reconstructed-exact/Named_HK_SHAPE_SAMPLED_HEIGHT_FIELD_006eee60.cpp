// =============================================================================
// Named_HK_SHAPE_SAMPLED_HEIGHT_FIELD_006eee60
// -----------------------------------------------------------------------------
// Stable ID: aa_006eee60
// Address:   0x006eee60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_HK_SHAPE_SAMPLED_HEIGHT_FIELD_006eee60 @ 0x006eee60
// Stable ID: aa_006eee60
// Embedded strings (evidence for future rename):
//   - "unknown"
//   - "HK_SHAPE_CONVEX"
//   - "HK_SHAPE_COLLECTION"
//   - "HK_SHAPE_BV_TREE"
//   - "HK_SHAPE_SPHERE"
//   - "HK_SHAPE_TRIANGLE"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: return×32, switch×1.
//  - Notable callees: FUN_006eee60.
//  - Strings: "unknown"; "HK_SHAPE_CONVEX"; "HK_SHAPE_COLLECTION"; "HK_SHAPE_BV_TREE".
//  - Return sites: 32.

/*
 * Behavioral notes:
 * String-driven rename evidence: "HK_SHAPE_SAMPLED_HEIGHT_FIELD"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char * Named_HK_SHAPE_SAMPLED_HEIGHT_FIELD_006eee60(uint32_t /* width from decompiler */ param_1)



{

  switch(param_1) {

  default:

    return "unknown";

  case 1:

    return "HK_SHAPE_CONVEX";

  case 2:

    return "HK_SHAPE_COLLECTION";

  case 3:

    return "HK_SHAPE_BV_TREE";

  case 4:

    return "HK_SHAPE_SPHERE";

  case 5:

    return "HK_SHAPE_TRIANGLE";

  case 6:

    return "HK_SHAPE_BOX";

  case 7:

    return "HK_SHAPE_CAPSULE";

  case 8:

    return "HK_SHAPE_CONVEX_VERTICES";

  case 9:

    return "HK_SHAPE_MULTI_SPHERE";

  case 10:

    return "HK_SHAPE_LIST";

  case 0xb:

    return "HK_SHAPE_TRIANGLE_COLLECTION";

  case 0xc:

    return "HK_SHAPE_MULTI_RAY";

  case 0xd:

    return "HK_SHAPE_HEIGHT_FIELD";

  case 0xe:

    return "HK_SHAPE_SAMPLED_HEIGHT_FIELD";

  case 0xf:

    return "HK_SHAPE_TRI_PATCH";

  case 0x10:

    return "HK_SHAPE_SPHERE_REP";

  case 0x11:

    return "HK_SHAPE_BV";

  case 0x12:

    return "HK_SHAPE_PLANE";

  case 0x13:

    return "HK_SHAPE_MOPP";

  case 0x15:

    return "HK_SHAPE_TRANSFORM";

  case 0x16:

    return "HK_SHAPE_PHANTOM_CALLBACK";

  case 0x17:

    return "HK_SHAPE_UTILITY_CONVEX_SWEEP";

  case 0x18:

    return "HK_SHAPE_USER0";

  case 0x19:

    return "HK_SHAPE_USER1";

  case 0x1a:

    return "HK_SHAPE_USER2";

  case 0x1b:

    return "HK_SHAPE_USER3";

  case 0x1c:

    return "HK_SHAPE_USER4";

  case 0x1d:

    return "HK_SHAPE_USER5";

  case 0x1e:

    return "HK_SHAPE_USER6";

  case 0x1f:

    return "HK_SHAPE_USER7";

  case 0xffffffff:

    return "HK_SHAPE_ALL";

  }

}
