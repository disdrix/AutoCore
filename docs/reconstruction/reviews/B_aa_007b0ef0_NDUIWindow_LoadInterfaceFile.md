# Review B (skeptical / adversarial): `aa_007b0ef0` NDUIWindow_LoadInterfaceFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b0ef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b0ef0_NDUIWindow_LoadInterfaceFile.md` |
| **Verdict** | **accept-with-gaps** — seal path/locale/vtable fork; attack over-naming of helpers and alt-path side effects |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Loads from absolute / install root without prefix | Body always seeds `0x00afa148` = `..\interface\` on non-null filename (locale 0 and ≠0) | **Falsified** for non-null arm |
| 2 | Locale 0 also inserts `_fr`/`_de`/`_uk` | Locale branch only when `*(FUN_007a69d0()+0x2c) != 0` | **Falsified** |
| 3 | Locale code 1 = German | `DAT_00a96c64` bytes `5f 66 72 00` = **`_fr`**; code 2 = `_de`; code 3 = `_uk` | **Falsified** mapping |
| 4 | Extension test is case-sensitive / strcmp | Four `tolower` compares to `.` `x` `m` `l` | **Falsified** — CI |
| 5 | Always XML load | Non-`.xml` takes `vtbl+0x3a0` not `+0x3a4` | **Falsified** |
| 6 | XML path: single arg only | `+0x3a4(path, 0)` — second imm **0** | **Falsified as unary** |
| 7 | Null filename always succeeds | Null + `this[0xa1]==0` → early `return` | **Falsified** |
| 8 | Null filename still prefixes `..\interface\` | Null arm strcpy of cache only | **Falsified** |
| 9 | This function parses XML | Only path resolve + virtual dispatch; XML parse is callee of `+0x3a4` | **Falsified** |
| 10 | Single caller (`ReloadInterface`) | ≥12 UNCONDITIONAL_CALL + many DATA xrefs | **Falsified** |
| 11 | `PathFileExists` failure always aborts load | Failure falls through rebuild / still hits `LAB_007b1175` load | **Falsified** as hard fail |
| 12 | `local_104` hit definitely becomes the vtable path | Decomp `goto LAB` without visible copy into `local_208` | **Not sealed** — genuine gap |
| 13 | `+0x3a4` **is** symbol `NDUIWindow_InitFromInterfaceXml` | Plate + partition map name; this body only shows slot offset | **Probable only** — name not byte-proven inside this VA |
| 14 | `__cdecl` | `this` in ECX pattern / thiscall decompile | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `..\interface\` prefix @ `0x00afa148` | **High** | Wrong asset root → all UI missing |
| Locale dword map 1=`_fr` 2=`_de` 3=`_uk` | **High** | Wrong localized UI files |
| Locale code source `+0x2c` off singleton | **High** (offset); name open | Wrong gate if singleton misidentified later |
| `this+0x284` cache | **High** | Reload-with-null breaks |
| `vtbl+0x6c` then `+0x3a4`/`+0x3a0` | **High** | Wrong virtual wire-up |
| `.xml` CI gate | **High** | Non-XML panels take wrong slot |
| Alt-path table `0x00d1e574` stride `0x1c` | **High** (constants) | Search path miss |
| Alt-path success copies into primary buf | **Open** | Load wrong / empty path |
| Helper FUN names | **Open** | Doc only |
| Runtime pack layout vs `..\interface\` | **Open** | Shipping path differences |

---

## 3. Cross-check: decompile vs constants

```text
0x00afa148:  "..\\interface\\"
0x00a96c60:  "_de\0"     // locale code 2
0x00a96c64:  "_fr\0"     // locale code 1
0x00a96c68:  "_uk\0"     // locale code 3
```

Localized stem math (length):

```text
strncat(..., fileName, strlen(fileName) - 4)   // drop last 4 of name
// optional dword locale suffix
strncat(..., fileName + strlen - 4, 5)         // put extension back
```

Matches “insert `_fr` before `.xml`” product behavior (e.g. `foo_fr.xml` under `..\interface\`).

Load fork (own VA only):

```text
LAB_007b1175:
  vcall this,+0x6c  (path)
  if tolower_tail == ".xml":
    vcall this,+0x3a4 (path, 0)
  else:
    vcall this,+0x3a0 (path)
```

---

## 4. Clean ≡ raw?

| Check | Result |
|---|---|
| CF / call order | **Match** |
| Early outs | **Match** |
| Locale branches | **Match** |
| Clean modernization? | **No** — width typedefs only |
| Scaffold risk | Clean still carries decomp stack alias mess (`local_20c` as both buffer and `FUN_007b6420` return) — **do not treat clean as clarified semantics** for alt-path |

---

## 5. What would reverse the seal?

- Image where `0x00afa148` is not `..\interface\` or locale dwords differ.
- Body that skips `+0x3a4` for `.xml` or passes non-zero second arg.
- Cache field not at dword index `0xa1` after type recovery proves different layout.
- Live pack that never uses relative `..\interface\` (would not change code constants, only deploy layout).

None observed on static `autoassault.exe` decompile + `read_memory` for this VA’s constants.

---

## 6. Surviving contract for AutoCore

```text
NDUIWindow_LoadInterfaceFile(this, fileNameOrNull):
  if fileNameOrNull is null:
    use this->cachedName (+0x284); if null return
  else:
    if localeCode==0:
      path = "..\\interface\\" + fileName
    else:
      path = "..\\interface\\" + stem + optional(_fr|_de|_uk) + ext
      optionally probe PathFileExists + search table; may rebuild non-localized
  this->vtbl[0x6c/4](path)
  if path ends with ".xml" (CI):
    this->vtbl[0x3a4/4](path, 0)
  else:
    this->vtbl[0x3a0/4](path)
```

Client-only UI asset load. No network. No mission/inventory logic beyond “panels that call this.”

---

## 7. Gaps (aligned with A)

1. Confirm whether `PathFileExistsA(local_104)` success rewrites the buffer passed to `+0x6c` / load slots.  
2. Product names for `FUN_007a69d0` / `007b6a20` / `007b6420` / `007b66c0`.  
3. Formal name of `vtbl+0x3a0`.  
4. Stack frame clarity (decomp dual-use of `local_20c`).  
5. Runtime verification under each locale code.

**Verdict:** **accept-with-gaps**
