# Review A (reconstruction fidelity): `aa_007b6c70` NDXml_LoadDocumentFromPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6c70` |
| **VA** | `0x007b6c70` |
| **Canonical name** | `NDXml_LoadDocumentFromPath` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (MSXML path load / resource bridge) |
| **Counterpart** | `reviews/B_aa_007b6c70_NDXml_LoadDocumentFromPath.md` |
| **System** | `client-xml` / UI+script document load (callers: interface, special FX, mission dialogs) |
| **Verdict** | **accept-with-gaps** (CF sealed High; COM product English + search-path contents open) |

---

## 1. Purpose

Load a filesystem (or resource-keyed) XML document into a pre-created **MSXML `IXMLDOMDocument`** for a path-owning loader object (`this`):

1. Null-guard `pXmlDom` and `pszPath` → `false`.
2. Optional path resolve when `*(byte*)(this+4) & 1`:
   - `PathFileExistsA(pszPath)` → skip to load stage.
   - Else basename via `FUN_007b6420` (strrchr `\` / `/` + 1), prefix each entry of search-path table `DAT_00d1e574`…`0x00d1e7a4` (stride `0x1c` = MSVC `std::string`, SSO via capacity `+0x14 > 0xf`), re-probe `PathFileExistsA` on concatenated buffer `local_154[260]`.
   - If no hit: `FUN_007b66c0(this)` — requires `*(byte*)(this+4) & 2`; basename + virtual `*(this+0xc)->vtbl+0x14`; fail → `false`.
3. Build resource key string (`FUN_007b6420` basename → `FUN_00989e00`), **`NDResource_LoadByKey(&res, key, 0, 0)`**.
4. **LoadByKey `< 0` (null resource):**
   - If `(short)local_2c == -1` (`VARIANT_TRUE`) → `true` (shared stack / dead-on-init residual; see B).
   - Else `pXmlDom->vtbl+0xf0` = **`get_parseError`**, dump `IXMLDOMParseError` fields, `Release` error object → fall through `false`.
5. **LoadByKey `≥ 0`:**
   - `NDResource_AcquireInnerObject()` → inner; `piIface = *(IUnknown**)(inner+4)`.
   - If iface non-null: **`IUnknown::Release` (`vtbl+8`)** — **documented crash site PC `0x007B6DB0`** when vtable/stale.
   - Optional CS on resource (`res+0x38`): decrement ref at `res+0x10`.
   - Optional cache side-path via `DAT_00d1f050+0x68` / `+0x64` → `FUN_00744ea0`.
   - If iface non-null: pack **`VARIANT` `vt=0x0d` (`VT_UNKNOWN`)** around iface (ATL-style stack helper `PTR_LAB_00a95b44` / `PTR_FUN_00a95b48`), call **`pXmlDom->vtbl+0xe8` = `load(VARIANT, VARIANT_BOOL*)`**, `VariantClear`, return via **`FUN_007b6e8d`** (HRESULT + parse-error re-dump; true when load `VARIANT_BOOL == VARIANT_TRUE` / HRESULT ok).
   - If iface null after acquire: fall through **`false`**.

Callers (2 xrefs, Ghidra): **`NDXml_OpenTaggedDocument` @ `0x00799a3b`**, **`FUN_0049f9a0` @ `0x0049fac6`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b6c70_NDXml_LoadDocumentFromPath.md` |
| Annotated | `docs/reconstruction/raw/aa_007b6c70_NDXml_LoadDocumentFromPath.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_LoadDocumentFromPath.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b6c70_NDXml_LoadDocumentFromPath.md` |
| Sibling plates (context only) | `NDResource_LoadByKey` `0x00423ac0`, `NDResource_AcquireInnerObject` `0x00745ee0`, `NDXml_OpenTaggedDocument` `0x007999c0` |
| Live Ghidra | `decompile_function` `0x007b6c70`; callees `0x007b6420`, `0x007b66c0`, `0x007b6e8d`; `analyze_function_complete` / `get_function_xrefs` |
| Callees in body | `PathFileExistsA`, `FUN_007b6420` (basename), `FUN_007b66c0` (flag-bit2 fallback), `FUN_00989e00` (string key), `NDResource_LoadByKey`, `NDResource_AcquireInnerObject`, `Enter/LeaveCriticalSection`, `FUN_00744ea0`, `VariantClear`, `FUN_007b6e8d`, `FUN_007a4480` (log), `SysFreeString` |

---

## 3. Signature

```c
// MSVC __thiscall  (ECX = this)
bool __thiscall NDXml_LoadDocumentFromPath(
    void *this,      // path-loader / NDXml helper; flags at +4, vtable obj* at +0xc
    void *pXmlDom,   // IXMLDOMDocument* (COM)
    char *pszPath    // filesystem path (NUL-terminated)
);
// Returns: true on successful document load / special VARIANT_TRUE path; false on nulls, resolve fail, load fail, null COM payload
```

---

## 4. Control flow (sealed)

```
if !pXmlDom || !pszPath: return false

if (this+4) & 1:                          // search-path mode
  if PathFileExistsA(pszPath): goto LOAD
  base = Basename(pszPath)                 // FUN_007b6420
  for entry in DAT_00d1e574 .. 0xd1e7a4 step 0x1c:
    concat(entry.cstr, base) → local_154
    if PathFileExistsA(local_154): goto LOAD
  if !FUN_007b66c0(this): return false     // requires (this+4)&2 + vtbl+0x14 lookup
else:
  if !FUN_007b66c0(this): return false     // same fallback when bit0 clear

LOAD:
  key = string_from(Basename(pszPath))
  rc = NDResource_LoadByKey(&res, key, 0, 0)
  if rc < 0:                               // only negative = hard miss
    if (short)outBool == VARIANT_TRUE(-1): return true   // see residual
    err = pXmlDom->get_parseError()        // vtbl+0xf0
    if err: log url/line/pos/reason; Release; return false
  else:
    inner = NDResource_AcquireInnerObject()  // thiscall on res (decomp omits this)
    iface = inner ? *(inner+4) : null
    if iface: iface->Release()             // CRASH PC 0x007B6DB0 if stale
    // optional CS: res.refCount ( +0x10 ) --
    // optional DAT_00d1f050 cache FUN_00744ea0
    if !iface: return false
    VARIANT v; v.vt = VT_UNKNOWN(0xd); v.punk = iface
    hr = pXmlDom->load(v, &outBool)        // vtbl+0xe8
    VariantClear(&v)
    return FUN_007b6e8d(hr, ...)           // true iff VARIANT_TRUE / HRESULT ok
```

### CF stage table (clean ≡ raw ≡ live Ghidra)

| Stage | Match |
|---|---|
| Null guards | Yes |
| Bit0 search-path loop + PathFileExistsA | Yes |
| Bit2 fallback `FUN_007b66c0` before LOAD label only when path not found / bit0 off | Yes |
| LoadByKey `<0` vs `≥0` (not `==0` fail) | Yes |
| get_parseError `+0xf0` + dump + Release | Yes |
| AcquireInner → `*(+4)` → Release `+8` | Yes |
| Resource CS `+0x38` / ref `+0x10` / CS body `+0x20` | Yes |
| VT_UNKNOWN VARIANT + `load` `+0xe8` + VariantClear + `FUN_007b6e8d` | Yes |
| Null iface → false | Yes |

---

## 5. Layout / constants (this unit)

| Item | Value | Confidence |
|---|---|---|
| `this+4` bit 0 | Enable path-exists + search-table probe | **High** |
| `this+4` bit 2 | Enable `FUN_007b66c0` virtual resolve (`this+0xc` vtbl+0x14) | **High** (callee body) |
| Search table | `DAT_00d1e574` … `< 0x00d1e7a4`, stride `0x1c` → **20** string slots | **High** |
| SSO gate | capacity dword at entry+0x14 `> 0xf` → heap ptr at entry+0 | **High** (MSVC string) |
| Path buffer | `local_154[260]` (MAX_PATH-ish) | **High** |
| Resource out | `local_28` from LoadByKey | **High** |
| Resource ref | `res+0x10` decremented after acquire; CS flag `res+0x38`, CS `res+0x20` | **High** |
| Inner COM | `*(AcquireInner()+4)` as `IUnknown*` | **High** |
| `VARIANT.vt` | `0x0d` = `VT_UNKNOWN` | **High** |
| DOM `load` | `pXmlDom` vtbl **`+0xe8`** | **High** (MSXML slot; name Probable) |
| DOM `get_parseError` | vtbl **`+0xf0`** | **High** / name **Probable** |
| ParseError getters | `+0x20` url BSTR, `+0x24` reason BSTR, `+0x2c` line, `+0x30` linepos/filepos; `+8` Release | **High** offsets; English **Probable** |
| `VARIANT_TRUE` | `(short)-1` on success out-bool | **High** |
| Crash PC | `0x007B6DB0` = `CALL [vtable+8]` Release | **High** (plate + body) |

### `FUN_007b6e8d` return contract (callee of success path)

| Condition | Result |
|---|---|
| `unaff_ESI` (HRESULT) `< 0` | Log `"Failed to load XML file %s, failed with code %d"` |
| `(short)local_2c != -1` | Re-dump parseError → **`false`** |
| else | **`return -1 < HRESULT`** (true on `S_OK`-class) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Purpose: path → resource → MSXML load | **High** | Plate + callees + format strings |
| Signature thiscall `(this, IXMLDOMDocument*, char*)` | **High** | Ghidra + OpenTaggedDocument caller |
| Null / resolve / load CF | **High** | Live decompile ≡ three-rep |
| LoadByKey only `<0` is hard error | **High** | Matches LoadByKey returns -1/0/1 |
| VT_UNKNOWN + load + VARIANT_BOOL | **High** | `vt=0xd`, out short -1 |
| Release-before-load crash site | **High** CF; **Probable** product root cause (stale iface) |
| Search table 20× `std::string` | **High** bounds/stride; contents **Tentative** (BSS zero in static read) |
| `FUN_007b6420` = basename | **High** | Live decompile strrchr |
| English names for every vtbl slot | **Probable** | MSXML standard layout |
| ATL helper `PTR_FUN_00a95b48` exact type | **Tentative** | Variant packer only |
| Bit-exact / runtime | Open | Not run |

---

## 7. Gaps

1. Runtime contents of `DAT_00d1e574` search roots (interface dirs, locale, etc.).
2. Full English type of `this` (NDXml loader vs thin helper) and `this+0xc` interface.
3. Whether Release-before-`load` is intentional refcount transfer into VARIANT or a use-after-Release latent (crash only when already stale).
4. Deadness of `(short)local_2c == -1` on the LoadByKey-fail arm (initialized 0; no writer before check).
5. Product name of `FUN_00744ea0` / `DAT_00d1f050` cache path.
6. Bit-exact / differential vs retail image.

**Verdict:** **accept-with-gaps**
