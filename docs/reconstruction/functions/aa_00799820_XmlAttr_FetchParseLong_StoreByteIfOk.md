# Function record: XmlAttr_FetchParseLong_StoreByteIfOk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799820` |
| **Canonical name** | `XmlAttr_FetchParseLong_StoreByteIfOk` |
| **Ghidra name** | `FUN_00799820` |
| **Address** | `0x00799820` |
| **Body range** | `0x00799820`–`0x0079984b` (44 bytes; cdecl `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | XML / mission-def attribute parse |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI sealed; full attr-name census open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00799820_XmlAttr_FetchParseLong_StoreByteIfOk.md`, `reviews/B_aa_00799820_XmlAttr_FetchParseLong_StoreByteIfOk.md` (2026-07-29 W21-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00799820`
- Prior scaffold chain name `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_00799820` — **do not use** as product identity (one of many parents)

## Purpose

**Fetch named XML attribute as long; on success store low byte to `*out`.** Wrapper over sealed `XmlAttr_FetchAndParseLong` (`0x00799460`).

## Signature

```c
void XmlAttr_FetchParseLong_StoreByteIfOk(
    void *node,
    const wchar_t *attrName,
    uint8_t *outByte,
    int base);  // radix for wcstol
// cdecl
```

## Algorithm

1. `ok = XmlAttr_FetchAndParseLong(node, attrName, &tmpLong, base)`.
2. If `ok`: `*outByte = (uint8_t)tmpLong`.
3. Else: leave `*outByte` unchanged.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00799820_FUN_00799820.md`
- Annotated: `docs/reconstruction/raw/aa_00799820_FUN_00799820.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/XmlAttr_FetchParseLong_StoreByteIfOk.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00799820.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00799820_FUN_00799820.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00569560-00799820-w21g-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | ≥6 functions / ≥16 xrefs — mission objective XML deserializers (e.g. Collect `L"slot"` @ `this+8`, UseItem SerializeXml chain, MissionDef parse helpers) |
| **Callees** | `FUN_00799460` = `XmlAttr_FetchAndParseLong` (dual sealed) |

## Confidence

| Claim | Level |
|---|---|
| Fetch+parse then conditional byte store | **High** |
| Low-byte only (not full long) | **High** (bytes: `mov dl,[esp]; mov [ecx],dl`) |
| Failed fetch does not write out | **High** |
| `param_4` is base/radix | **High** (through callee to `wcstol`) |
| Per-site attr product names | **Open** (caller-owned) |
| Runtime / differential | Open |

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00799460` | `XmlAttr_FetchAndParseLong` | sole callee |
| `0x00798bb0` | attr → wide text | next level down |
