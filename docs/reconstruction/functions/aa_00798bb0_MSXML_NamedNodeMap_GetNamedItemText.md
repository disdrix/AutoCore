# Function record: MSXML_NamedNodeMap_GetNamedItemText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00798bb0` |
| **Canonical name** | `MSXML_NamedNodeMap_GetNamedItemText` |
| **Address** | `0x00798bb0` |
| **Body span** | `00798bb0` – `00798c9d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `msxml` / XML attribute helpers |
| **Completion status** | **Dual complete (accept-with-gaps)** — three-rep + A/B 2026-07-29 W17-G |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00798bb0`
- Prior auto-name: `Named_CalleeOf_Named_VOGMapText_00798bb0`
- Scaffold: `FUN_00798bb0.cpp`

## Purpose

Leaf MSXML helper: look up a **named attribute** on an `IXMLDOMNamedNodeMap`, read its **text**, and **`wcscpy`** into a caller-supplied wide buffer. Returns **1** on success, **0** on missing/fail. Shared by typed attribute parsers (`FUN_00798d00`…`FUN_007995a0`) and many XML asset loaders.

## Signature (caller + epilogue sealed)

```c
/* __cdecl; 3 stack args; returns char in AL */
char __cdecl MSXML_NamedNodeMap_GetNamedItemText(
    void *namedNodeMap,       /* IXMLDOMNamedNodeMap* */
    const wchar_t *attrName,  /* OLECHAR*; NULL → null BSTR */
    wchar_t *outText);        /* wcscpy dest; capacity caller-owned */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00798bb0_FUN_00798bb0.md` (live seal append 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_00798bb0_FUN_00798bb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MSXML_NamedNodeMap_GetNamedItemText.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00798bb0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00798bb0_MSXML_NamedNodeMap_GetNamedItemText.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00798bb0_MSXML_NamedNodeMap_GetNamedItemText.md`

## Callers / callees

**Callees:** `SysAllocString`, `SysFreeString`, `wcscpy`, `FUN_004048e0` (OOM).

**Callers (Ghidra sample):** `FUN_00798d00`, `FUN_00798d90`, `FUN_00798e50`, `FUN_00798f30`, `FUN_00799160`… typed wrappers; `FUN_0049db10`…`FUN_004a4fa0` asset/XML load family; `FUN_00547050`, `FUN_005ab170`, `FUN_007ac940`, `FUN_007add10`. ~55 xrefs.

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile | **High** |
| `__cdecl` + 3-arg + AL return | **High** (epilogue + callers) |
| `getNamedItem` @ `+0x1c` / `get_text` @ `+0x68` / `Release` @ `+0x08` | **High** (layout match + CF) |
| Interface product name MSXML NamedNodeMap | **High / Probable** |
| Out buffer size policy | **Open** (no bounds here) |
| Runtime / differential | **Open** |
