# Review B (skeptical / adversarial): `aa_007b6c70` NDXml_LoadDocumentFromPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b6c70_NDXml_LoadDocumentFromPath.md` |
| **Verdict** | **accept-with-gaps** on CF; residual COM lifetime + search-path contents + fail-arm VARIANT check |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always opens path with raw `pszPath` only | Bit0 path: `PathFileExistsA` + 20-slot prefix table before load | **Falsified** exclusive raw-path |
| 2 | LoadByKey fail (`0`) treated as error | Body tests **`iVar9 < 0` only**; `0`/`1` both enter success/Release arm | **Falsified** — matches LoadByKey plate note |
| 3 | Returns false whenever resource missing | Fail arm can return **true** if `(short)local_2c == -1` | **Overstated** always-false; but `local_2c` init **0** → branch likely **dead** statically |
| 4 | Success always returns true | Success goes through **`FUN_007b6e8d`**: false on bad HRESULT / non-`VARIANT_TRUE` + parseError dump | **Falsified** unconditional true |
| 5 | `vtbl+0xe8` is createElement / arbitrary | Out-param short + VariantClear + `"Failed to load XML"` in helper | **Survives** as **`load`** (**Probable** English) |
| 6 | `vtbl+0xf0` is load | Used with parseError field getters + format `"XML parse error"` | **Falsified** as load; **`get_parseError` Probable** |
| 7 | Crash is inside MSXML `load` | Plate + body: first **`iface->Release` (`+8`)** after Acquire; PC `0x007B6DB0` | **Falsified** load-as-crash; **Release site High** |
| 8 | Release then load is impossible | Live order Release → later VARIANT/`load` with same `piVar14` | **Survives as CF**; lifetime correctness **Tentative** (AddRef elsewhere / VARIANT ownership) |
| 9 | No fallback without filesystem hit | `FUN_007b66c0` when bit2 set uses `this+0xc` vtbl+0x14 | **Falsified** FS-only model |
| 10 | Basename helper unknown | `FUN_007b6420` decomp: `strrchr` `\`/`/` | **Falsified** unknown — **basename High** |
| 11 | Three-rep diverges from Ghidra | Live `decompile_function` 2026-07-29 ≡ raw/annotated/clean body | **Falsified** divergence |
| 12 | Many callers | Xrefs **2**: OpenTaggedDocument, FUN_0049f9a0 | **Falsified** “hub” claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null guards + bit0 search loop + LOAD join | **High** | Wrong path resolve in port |
| LoadByKey `<0` only hard-fail | **High** | Drop valid zero-init resources / miss Release arm |
| AcquireInner → `*(+4)` → Release crash PC | **High** | Wrong crash triage |
| VT_UNKNOWN + `load` + `FUN_007b6e8d` | **High** | Broken document inject |
| `VARIANT_TRUE == (short)-1` | **High** | Invert success |
| Fail-arm `local_2c == -1` live meaning | **Low** | Dead code vs shared SEH frame artifact |
| Release-before-use lifetime safe | **Low–Tentative** | UAF if refcount not elevated |
| Search-path string contents | **Low** (static BSS zeros) | Wrong interface root prefixes |
| `this` concrete C++ type name | **Tentative** | Mis-owned port field |
| Bit-exact | Open | Image drift |

---

## 3. Cross-check against live decompile (2026-07-29)

```
null(pXmlDom|pszPath) → false
if flags&1:
  PathFileExists(path) → LOAD
  else for 20× string@DAT_00d1e574: exists(prefix+basename) → LOAD
  else FUN_007b66c0(flags&2 + vtbl) or false
else: FUN_007b66c0 or false
LOAD:
  LoadByKey(basename key)
  if rc<0: maybe true if outBool==VARIANT_TRUE; else parseError dump → false
  else:
    inner=AcquireInner; iface=*(inner+4)
    if iface: Release()            // CRASH if stale
    optional CS ref-- ; optional cache FUN_00744ea0
    if !iface: false
    VARIANT vt=VT_UNKNOWN; load(v,&outBool); VariantClear
    return FUN_007b6e8d (HRESULT + parseError / VARIANT_TRUE)
```

Clean ≡ raw ≡ live Ghidra CF. Three-rep already present; dual only.

**Callers:**

| Caller | Site | Role |
|---|---|---|
| `NDXml_OpenTaggedDocument` | `0x00799a3b` | Primary tagged open (UI `"XML"`, FX tags); copies path to `this+0x10` then load |
| `FUN_0049f9a0` | `0x0049fac6` | Legacy / secondary path load |

No additional static xrefs within `limit=100`.

### Adversarial notes on decompiler hazards

| Hazard | Assessment |
|---|---|
| `NDResource_AcquireInnerObject()` shown with no `this` | **thiscall on `local_28` resource**; decomp elides ECX — **do not invent free function** |
| `Release()` shown with no args | COM stdcall/thiscall on `piVar14`; **ECX/stack this is the iface** |
| `FUN_007b6e8d` uses `unaff_ESI` / `unaff_EBP` | SEH/outline helper tied to caller frame — contract from its body, not a free bool util |
| Path concat uses `&stack0xfffffeab` | Decomp artifact for `local_154` write cursor after prefix copy — CF still prefix+basename |

---

## 4. Surviving contract for AutoCore

```
// Client-only MSXML document load from path/resource key
bool NDXml_LoadDocumentFromPath(loader, IXMLDOMDocument* dom, const char* path):
  if !dom || !path: return false
  resolved = path
  if loader.flags & SEARCH_FS:
    if !PathFileExists(path):
      base = basename(path)
      for prefix in g_XmlSearchPaths[20]:  // DAT_00d1e574, stride 0x1c
        if PathFileExists(prefix + base): resolved = that; break
      else if !VirtualResolve(loader): return false   // flags&2, vtbl+0x14
  else if !VirtualResolve(loader): return false

  res = NDResource_LoadByKey(basename(path), ...)
  if res == null:                 // LoadByKey returns -1
    log parseError if any; return false
  // NOTE: init-fail (LoadByKey returns 0) still enters acquire/Release path

  inner = AcquireInnerObject(res)
  iface = inner ? inner->comAt4 : null
  if iface: iface->Release()      // known AV when COM stale (mission turn-in stacks)
  // drop resource ref under optional CS
  if !iface: return false

  VARIANT v = { VT_UNKNOWN, iface }
  VARIANT_BOOL ok = FALSE
  HRESULT hr = dom->load(v, &ok)
  VariantClear(&v)
  return (ok == VARIANT_TRUE) && SUCCEEDED(hr)   // via FUN_007b6e8d semantics

// Port notes:
// - Do not treat LoadByKey==0 as hard fail (matches retail gate)
// - Crash triage: Release @ resource inner+4, not necessarily load()
// - Server AutoCore may skip MSXML and parse via managed Xml; preserve path-resolve + key rules if reusing client assets
```

---

## 5. Open questions (residual only)

1. Runtime fill of `DAT_00d1e574` search prefixes (when / by whom).
2. Intentionality of **Release before `load`** (transfer into VARIANT vs latent UAF).
3. Whether LoadByKey-fail `(short)local_2c == -1` is dead, SEH shared, or ever live.
4. Concrete C++ type for `this` and the `this+0xc` resolver object.
5. Product name / role of `FUN_00744ea0` when `DAT_00d1f050+0x68` set.
6. Runtime capture on mission turn-in AV (iface/vtable at `0x007B6DB0`).
7. Bit-exact / image diff.

**Verdict:** **accept-with-gaps** on CF; COM lifetime + search-path contents remain open
