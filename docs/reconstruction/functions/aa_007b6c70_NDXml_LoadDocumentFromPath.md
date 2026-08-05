# Function record: NDXml_LoadDocumentFromPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6c70` |
| **Canonical name** | `NDXml_LoadDocumentFromPath` |
| **Address** | `0x007b6c70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-xml` (UI / script / special-FX document load) |
| **Completion status** | **Partial** — three-rep + dual A/B **accept-with-gaps** (2026-07-29); CF High; COM lifetime + search-path contents open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Resolve a filesystem path (optional search-prefix table + virtual fallback), load a document resource via **`NDResource_LoadByKey`**, take the inner COM payload, and feed it as a **`VT_UNKNOWN` VARIANT** into **MSXML `IXMLDOMDocument::load`**. On failure, dump **`get_parseError`** fields through the shared log helper.

Documented crash site for mission turn-in AVs: **`0x007B6DB0`** = `IUnknown::Release` (`vtbl+8`) on the COM pointer at **`*(AcquireInnerObject()+4)`** when the interface/vtable is stale.

## Signature (decompiler-derived)

```c
// MSVC __thiscall
bool __thiscall NDXml_LoadDocumentFromPath(
    void *this,      // loader; flags byte at +4 (bit0=FS search, bit2=virtual resolve)
    void *pXmlDom,   // IXMLDOMDocument*
    char *pszPath    // path string
);
```

## Control-flow summary

1. Null `pXmlDom` / `pszPath` → `false`.
2. If `(this+4)&1`: `PathFileExistsA`; else walk **`DAT_00d1e574`…`0xd1e7a4`** (stride `0x1c`, 20× MSVC string) prefixing basename (`FUN_007b6420`).
3. If still unresolved: **`FUN_007b66c0`** (requires `(this+4)&2`, `*(this+0xc)` vtbl+0x14) or `false`.
4. Basename → string key → **`NDResource_LoadByKey`** (only **`<0`** hard-fails into parseError arm).
5. Success arm: **AcquireInner** → `*(inner+4)` → **Release** → optional resource ref-- under CS → **VARIANT VT_UNKNOWN** → **`load` vtbl+0xe8** → **`FUN_007b6e8d`** bool.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b6c70_NDXml_LoadDocumentFromPath.md`
- Annotated: `docs/reconstruction/raw/aa_007b6c70_NDXml_LoadDocumentFromPath.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDXml_LoadDocumentFromPath.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007b6c70_NDXml_LoadDocumentFromPath.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007b6c70_NDXml_LoadDocumentFromPath.md`

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Caller | `NDXml_OpenTaggedDocument` | site `0x00799a3b` |
| Caller | `FUN_0049f9a0` | site `0x0049fac6` |
| Callee | `PathFileExistsA` | shlwapi |
| Callee | `FUN_007b6420` | basename (`strrchr` `\`/`/`) |
| Callee | `FUN_007b66c0` | flag-bit2 virtual path resolve |
| Callee | `FUN_00989e00` | string construct key |
| Callee | `NDResource_LoadByKey` | `0x00423ac0` |
| Callee | `NDResource_AcquireInnerObject` | `0x00745ee0` |
| Callee | `FUN_007b6e8d` | load HRESULT / VARIANT_BOOL → bool + parseError |
| Callee | `VariantClear` | oleaut32 |
| Callee | `FUN_007a4480` | log |
| Callee | `FUN_00744ea0` | optional cache (`DAT_00d1f050`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (≡ three-rep) | **High** |
| LoadByKey only `<0` is hard error | **High** |
| VT_UNKNOWN + DOM load (`+0xe8`) + get_parseError (`+0xf0`) | **High** offsets / **Probable** English |
| Release-before-load crash PC `0x007B6DB0` | **High** |
| Parameter semantic names | **Probable** |
| Search-path table contents / loader C++ type | **Tentative** |
| COM lifetime after Release | **Tentative** |
| Types (full MSXML interfaces) | **Probable** |
| Runtime / bit-exact | Open |

## Dual-review verdict

**accept-with-gaps** (A+B, 2026-07-29). No ledgers updated (OWN-ONLY).
