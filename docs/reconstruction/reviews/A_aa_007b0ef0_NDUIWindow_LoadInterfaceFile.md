# Review A (reconstruction fidelity): `aa_007b0ef0` NDUIWindow_LoadInterfaceFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b0ef0` |
| **VA** | `0x007b0ef0` |
| **Body range** | `0x007b0ef0` – `0x007b121d` |
| **Canonical name** | `NDUIWindow_LoadInterfaceFile` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007b0ef0_NDUIWindow_LoadInterfaceFile.md` |
| **System** | client UI / NDUI (interface XML load path) |
| **Verdict** | **accept-with-gaps** — path build + locale suffix + `.xml` vtable fork **High**; helper/callee product names open |

---

## 1. Purpose

MSVC **`__thiscall`** path resolver + loader for an `NDUIWindow`:

1. Resolve an on-disk interface definition under `..\interface\` (optional locale stem suffix).
2. Invoke a virtual “bind path” slot (`vtbl+0x6c`) with the resolved path.
3. Case-insensitive extension check: if path ends in **`.xml`**, call **`vtbl+0x3a4(path, 0)`** (plate: **InitFromInterfaceXml**); else **`vtbl+0x3a0(path)`** (non-XML interface load).

Entry for mission dialog widgets (`i_d_npc_2d_wnd_*.xml`) and many other HUD panels. Sibling reload wrapper is `NDUIWindow_ReloadInterface` @ `0x00792980`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b0ef0_NDUIWindow_LoadInterfaceFile.md` |
| Annotated | `docs/reconstruction/raw/aa_007b0ef0_NDUIWindow_LoadInterfaceFile.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDUIWindow_LoadInterfaceFile.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b0ef0_NDUIWindow_LoadInterfaceFile.md` |
| Live decompile | Ghidra `decompile_function` `0x007b0ef0` (2026-07-29) |
| Live bytes | Ghidra `read_memory` path / locale strings |
| Xrefs | Ghidra `get_function_xrefs` / `get_xrefs_to` |
| Callees | Ghidra `get_function_callees` |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff, deep own-VA analysis of sibling `InitFromInterfaceXml` / Reload (other owners).

---

## 3. Signature / ABI

```c
void __thiscall NDUIWindow_LoadInterfaceFile(
    NDUIWindow* this,   // ECX → param_1
    char* fileName);    // stack — relative name e.g. "i_g_2d_wnd_....xml"; NULL → cached this[0xa1]
```

| Fact | Evidence | Confidence |
|---|---|---|
| `__thiscall` | Decompiler signature + `this` used as vtable base | **High** |
| `fileName` nullable | Early branch `param_2 == 0` | **High** |
| Cached name at **`this+0x284`** | `param_1[0xa1]` dword index → byte `0xa1*4` | **High** (offset) |
| Return `void` | Falls through to `return` after virtual load | **High** |

---

## 4. Sealed control flow

### 4.1 Path buffer setup — **High**

- Zero ~260-byte stack path (`local_208` / adjacent dwords; decompiler splits frame).
- Save `this` in `local_210` (restored after branches that clobber `param_1`).

### 4.2 Null filename → cached path — **High**

```text
if fileName == NULL:
  p = this[0xa1]          // char* at +0x284
  if p == NULL: return
  strcpy(pathBuf, p)      // no ../interface/ prefix on this arm
  goto LAB_load
```

### 4.3 Non-null: locale gate via `FUN_007a69d0()+0x2c` — **High** (structure)

```text
localeObj = FUN_007a69d0()
localeCode = *(int*)(localeObj + 0x2c)
```

| `localeCode` | Behavior |
|---:|---|
| **0** | Simple: `path = "..\\interface\\" + fileName` |
| **≠ 0** | Localized stem: strip 4-char extension, insert locale suffix, re-append extension; existence probe + fallback |

### 4.4 Path prefix string — **SEALED**

| Addr | Bytes / ASCII |
|---|---|
| `0x00afa148` | `2e 2e 5c 69 6e 74 65 72 66 61 63 65 5c 00` → **`..\interface\`** |

### 4.5 Locale suffix dwords — **SEALED**

Written as single dword stores at end of path stem (includes trailing NUL in the dword):

| Code | Global | Bytes | ASCII |
|---:|---|---|---|
| **1** | `DAT_00a96c64` | `5f 66 72 00` | **`_fr`** |
| **2** | `DAT_00a96c60` | `5f 64 65 00` | **`_de`** |
| **3** | `DAT_00a96c68` | `5f 75 6b 00` | **`_uk`** |
| other ≠0 | (no dword store in `if/else if/else if`) | — | stem only, then re-append ext |

Localized construction (decompiler-faithful):

1. Copy `..\interface\`.
2. `strncat(path, fileName, strlen(fileName) - 4)` — drop last 4 chars (e.g. `.xml`).
3. Append locale dword if code ∈ {1,2,3}.
4. `strncat(path, fileName + strlen - 4, 5)` — re-append extension (+NUL budget).
5. Optional existence probe (below).
6. If probe fails / policy says no: rebuild non-localized `..\interface\` + full `fileName`.

### 4.6 Existence / search fallback (locale ≠ 0) — **High** structure, **Probable** names

```text
cfg = FUN_007b6a20()
if (*(byte*)(cfg + 4) & 1):
  if PathFileExistsA(path): goto LAB_load
  stemOrAlt = FUN_007b6420()
  for entry = &DAT_00d1e574; entry < 0x00d1e7a4; entry += 0x1c:
    // SSO/std::string-like: if cap>0xf use heap ptr else inline
    // build local_104 = entry_str + stemOrAlt
    if PathFileExistsA(local_104): goto LAB_load   // note: pathBuf not rewritten here in decomp — gap
if FUN_007b66c0(cfg) == 0:
  rebuild path = "..\\interface\\" + fileName
```

Search table stride **`0x1c`**, range **`0x00d1e574` … `< 0x00d1e7a4`** sealed as constants from decompile.

### 4.7 Load fork — **SEALED**

```text
LAB_007b1175:
  (*this->vtbl + 0x6c)(path)           // bind / set interface path string

  // case-insensitive last-four check for ".xml"
  if ends_with_ci(path, ".xml"):
    (*this->vtbl + 0x3a4)(path, 0)     // InitFromInterfaceXml (plate)
  else:
    (*this->vtbl + 0x3a0)(path)        // non-XML interface loader
```

| Slot | Args | Plate / role | Confidence |
|---:|---|---|---|
| `+0x6c` | `(path)` | set/bind resolved path on window | **High** (offset) |
| `+0x3a4` | `(path, 0)` | XML init (`NDUIWindow_InitFromInterfaceXml` @ `0x007b3710` is sibling name in partition map) | **High** offset; **Probable** product name via plate |
| `+0x3a0` | `(path)` | non-XML interface init | **High** offset; name open |

Extension test uses `tolower` on four characters `0x2e,0x78,0x6d,0x6c` (`.xml`).

---

## 5. Callees (this unit only)

| Addr / import | Role in body | Confidence |
|---|---|---|
| `FUN_007a69d0` | locale / client config singleton; read `+0x2c` | **Probable** (locale code owner) |
| `FUN_007b6a20` | config object; flag byte `+4` bit0 | **Tentative** product name |
| `FUN_007b6420` | returns char* used in alt-path build | **Tentative** |
| `FUN_007b66c0` | bool: whether to fall back to non-localized | **Tentative** |
| `PathFileExistsA` | Win32 existence | **High** |
| `strncat` / `tolower` | CRT | **High** |
| `s____interface__00afa148` | `..\interface\` | **High** |
| `DAT_00a96c60/64/68` | `_de` / `_fr` / `_uk` | **High** |
| `DAT_00d1e574` | search-path table base | **High** (addr); layout **Probable** (std::string-ish + pad) |

---

## 6. Callers / xrefs (inventory, not deep-owned)

Direct **UNCONDITIONAL_CALL** sites (non-exhaustive of vtable DATA xrefs):

| Site | Function (Ghidra) |
|---|---|
| `0x0079298a` | `NDUIWindow_ReloadInterface` |
| `0x0079c431` | `FUN_0079c360` |
| `0x0085e61f` | `FUN_0085e590` (e.g. inventory template XML) |
| `0x0078c50f`, `0x00794c72`, `0x007faf51` | unnamed call sites |
| `0x00834768`, `0x00834dc8`, `0x00834fb8`, `0x008356a0` | dialog/UI family |
| `0x00862e78`, `0x0097bc2c`, `0x0097e1b3` | more UI |

Many **DATA** xrefs in `.rdata` (vtable slots / tables) — function is a common virtual/method target.

---

## 7. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null → cache / early out | **Yes** |
| Locale 0 simple concat | **Yes** |
| Locale ≠0 stem + suffix + ext + PathFileExists + fallback | **Yes** |
| `LAB_007b1175` + `+0x6c` + `.xml` fork `+0x3a4` / else `+0x3a0` | **Yes** |
| Clean vs raw deltas | Width renames only (`undefined` → `uint8_t` / `uint32_t`); **no CF change** |

Three-rep present (scaffold 2026-07-23); dual refresh 2026-07-29.

---

## 8. Confidence summary

| Claim | Level |
|---|---|
| Purpose: resolve `..\interface\` path + virtual load | **High** |
| Prefix string `..\interface\` @ `0x00afa148` | **High / Confirmed** |
| Locale suffixes `_fr` / `_de` / `_uk` for codes 1/2/3 | **High / Confirmed** |
| Locale code at `FUN_007a69d0()+0x2c` | **High** (read site); singleton name open |
| Cached filename at `this+0x284` (`[0xa1]`) | **High** |
| Vtable `+0x6c` / `+0x3a4(path,0)` / `+0x3a0(path)` | **High** |
| `.xml` case-insensitive gate | **High** |
| `+0x3a4` product name InitFromInterfaceXml | **Probable** (plate + sibling map) |
| Search-table entry layout / when `local_104` replaces primary path | **Open** (decomp aliasing) |
| Helper product names (`007a69d0`, `007b6a20`, `007b6420`, `007b66c0`) | **Open** |
| Runtime / bit-exact | **Open** |

---

## 9. Gaps

1. Exact stack-frame path buffer layout (decomp splits `local_20c` / `local_208` / dual-use after `FUN_007b6420`).
2. Whether successful `PathFileExistsA(local_104)` also copies `local_104` into the path passed to vtable slots (decomp jumps to `LAB` without an obvious copy — **risk**).
3. Product names for locale singleton and path-search helpers (other VAs).
4. Formal name of `vtbl+0x3a0` non-XML loader.
5. Full vtable owner class hierarchy for all DATA xrefs.
6. Runtime locale file presence under live client install.

**Verdict:** **accept-with-gaps**
