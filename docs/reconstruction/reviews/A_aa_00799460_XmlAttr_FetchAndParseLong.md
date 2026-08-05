# Review A (reconstruction fidelity): `aa_00799460` XmlAttr_FetchAndParseLong

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799460` |
| **VA** | `0x00799460` |
| **Canonical name** | `XmlAttr_FetchAndParseLong` (structural) |
| **Ghidra name** | `FUN_00799460` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00799460_XmlAttr_FetchAndParseLong.md` |
| **System** | XML / NDUI / mission-def attribute parse |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Fetch a named XML attribute as text, then parse it as a C long.**

1. Call `FUN_00798bb0(node, attrName, local_80[64])` — COM/XML attr → wide buffer (returns `char` success).
2. If success: `wcstol(local_80, &endPtr, base=param_4)` → store in `*param_3`.
3. Return the **fetch success flag** (not a separate parse-ok). Failed fetch skips `wcstol` and leaves `*param_3` untouched.

```c
char FUN_00799460(undefined4 node, undefined4 attrName, long *outValue, int base)
{
  wchar_t buf[64];
  wchar_t *end;
  char ok = FUN_00798bb0(node, attrName, buf);
  if (ok) *outValue = wcstol(buf, &end, base);
  return ok;
}
```

Stack: `sub esp, 0x84` for 64 wchar buffer + end pointer — matches decompile `local_80[64]` / `local_84`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00799460_*`, `reconstructed-exact/FUN_00799460.cpp` |
| Named alias | `Named_CalleeOf_Named_VOGMapText_00799460.cpp` |
| Function record | `functions/aa_00799460_FUN_00799460.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00799460` (2026-07-29) |
| Bytes | `read_memory` 96 B — `call FUN_00798bb0`; `test bl`; `call [wcstol IAT]`; `mov [ecx],eax` |
| Callee decompile | `FUN_00798bb0` @ `0x00798bb0` (SysAllocString + vtbl+0x1c attr get + wcscpy) |
| Callers | Many: MissionDef ensure, NDUIWindow_ApplyXmlNodeAttributes, map/text loaders, FX scripts, etc. (`get_xrefs_to` ≥30) |

**Not performed:** full caller base-radix census, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate on `FUN_00798bb0` non-zero | **Confirmed** | |
| 64 wchar stack scratch | **High** | `0x80` bytes + endptr slot |
| `wcstol` only on fetch success | **Confirmed** | |
| `*out = long` result | **Confirmed** | |
| `param_4` is **radix/base** to `wcstol` | **High** | third formal of `wcstol` |
| Return = fetch success, **not** parse completeness | **High** | endptr unused for gate |
| Failed fetch does not write `*out` | **Confirmed** | |
| Product attr names per call site | **Open** | caller-owned |
| `FUN_00798bb0` full COM contract | **Open** | residual dual |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Fetch via 00798bb0 into stack buf | Yes |
| if ok → wcstol → *out | Yes |
| return ok | Yes |

### Recovered CF

```c
// char XmlAttr_FetchAndParseLong(IXmlNode* node, const wchar_t* attr, long* out, int base)
char ok = XmlAttr_FetchWide(node, attr, stackBuf64);
if (ok) *out = wcstol(stackBuf64, &end, base);
return ok;
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller (sample) | `FUN_00547920` MissionDef_EnsureXmlLoaded | mission id / numeric attrs |
| Caller (sample) | `NDUIWindow_ApplyXmlNodeAttributes` | UI XML ints |
| Caller (sample) | `FUN_004a4fa0` / map text family | Named_VOGMapText chain |
| Callee | `FUN_00798bb0` | attr → wide text |
| Callee | `wcstol` | base-N parse |

---

## 6. Gaps / open

1. Dual/refine `FUN_00798bb0` (BSTR alloc, vtbl offsets).
2. Which sites pass base 10 vs 0 vs 16.
3. Whether empty-string fetch success yields `0` long always acceptable.
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — fetch+parse pipeline High; attr product names Open.
