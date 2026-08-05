// =============================================================================
// XmlAttr_FetchParseLong_StoreByteIfOk
// -----------------------------------------------------------------------------
// Purpose:  Fetch a named XML attribute, parse as C long (via sealed
//           XmlAttr_FetchAndParseLong), and on success store the low byte
//           into *outByte. Failed fetch leaves *outByte untouched.
//
// Address:  0x00799820  (autoassault.exe, image base 0x400000)
// Body:     0x00799820–0x0079984b (44 bytes; cdecl ret)
// Stable:   aa_00799820
// System:   XML / mission-def / NDUI attribute helpers
// Ghidra:   FUN_00799820
//
// ABI:      __cdecl
//             (void *node, const wchar_t *attrName, uint8_t *outByte, int base)
//
// Exactness: CF mirrors raw + live decompile; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W21-G).
// =============================================================================

#include <cstdint>

// Sealed dual aa_00799460
char XmlAttr_FetchAndParseLong(void *node, const void *attrName, long *outValue, int base);

/* XmlAttr_FetchParseLong_StoreByteIfOk — plate-faithful CF.

   Parameters:
     node:     XML / COM node
     attrName: wide attribute name
     outByte:  destination byte (only written on fetch success)
     base:     radix passed through to wcstol (e.g. 0xA = 10)

   Algorithm:
     1) ok = FetchAndParseLong(node, attrName, &tmpLong, base)
     2) if ok: *outByte = (uint8_t)tmpLong

   Known caller pattern:
     Collect_DeserializeXml: (node, L"slot", this+8, 10)
*/

void XmlAttr_FetchParseLong_StoreByteIfOk(
    void *node,
    const void *attrName,
    uint8_t *outByte,
    int base)
{
    char ok;
    uint8_t local_tmp[4];

    ok = XmlAttr_FetchAndParseLong(node, attrName, (long *)local_tmp, base);
    if (ok != '\0') {
        *outByte = local_tmp[0];
    }
}
