# Review A (reconstruction fidelity): `aa_007a6910` Locale_StringTable_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6910` |
| **VA** | `0x007a6910` |
| **Canonical name** | `Locale_StringTable_ctor_Inferred` (was `FUN_007a6910`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007a6910_Locale_StringTable_ctor_Inferred.md` |
| **System** | locale / string-table (cross-cutting UI + chat) |
| **Verdict** | **accept** on CF / layout init / vtable / ring alloc; product class name **Inferred** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Constructor** for the process-wide **locale / language string-table** object (singleton storage `DAT_00d1f660` via `Locale_GetInstance_Inferred` @ `0x007a69d0`).

Initializes:

| Offset | Init | Role (High from sibling duals) |
|---|---|---|
| `+0x00` | `PTR_FUN_00a96f88` | vtable (slot0 → scalar dtor `FUN_00424810` → `FUN_007a6890`) |
| `+0x2c` | `0` | locale code (en default; 1/2/3 = fr/de/uk consumers) |
| `+0xc0` | `0` | ring write index (wraps at 10 in localize path) |
| `+0xbc` | `1` | mode / flag dword |
| `+0xc4` (byte) | `0x2c` (`','`) | delimiter byte used by pack paths |
| `+0x04`…`+0x28` | 10× `operator_new__(0x100)` zeroed | ring string buffers |
| `+0x6c`… | 10× capacity `0x100` | parallel size slots |
| `+0x58`… / pack ptrs | zeroed 5×(count + 2 ptrs) | language-pack tables |

Returns **`this`** (construction-by-pointer).

Does **not** load PAK/INI files, parse VOG.ini, or localize strings (those are other VAs).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_007a6910_*`, `FUN_007a6910.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x007a6910` (2026-07-29) |
| Live body bytes | `read_memory` `0x007a6910` length 160 |
| Callers | `FUN_007a69d0` (singleton), `FUN_008cd200` |
| Sibling duals | `A_aa_007a69d0_Locale_GetInstance_Inferred.md`, dtor/leaf in this batch |
| Vtable probe | `read_memory` `0x00a96f88` → first slot `0x00424810` (scalar deleting dtor) |

**Not performed:** full language-pack load duals; runtime; bit-exact; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = ctor for locale string-table object | **High** | singleton cold path + vtable + ring layout match localize consumers |
| Vtable stamp `PTR_FUN_00a96f88` | **Confirmed** | bytes `c74500 886fa900` |
| 10 ring buffers × `0x100` bytes, zero-filled | **Confirmed** | loop + `rep stosd`/`stosb` |
| `this+0x2c = 0` locale code default | **Confirmed** | store + GetLocale leaf |
| `this+0xc0 = 0` ring index | **Confirmed** | store; localize wraps at 10 |
| Returns `this` | **Confirmed** | decompile |
| Product class name | **Open / Inferred** | no RTTI string in body |
| Scaffold LoadVogIni exclusive | **Over-narrow** | singleton is process-wide |
| Clean ≡ raw ≡ live CF | **Confirmed** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Stamp vtable | **Yes** |
| Zero locale / ring index / set flag + comma byte | **Yes** |
| 10× alloc 0x100 + zero + store ptr/size | **Yes** |
| Zero 5 language-pack slots | **Yes** |
| Return this | **Yes** |
| No file I/O | **Yes** |

### Recovered CF (compressed)

```c
LocaleStringTable *Locale_StringTable_ctor_Inferred(LocaleStringTable *this)
{
    this->vfptr = &PTR_FUN_00a96f88;
    this->localeCode = 0;          // +0x2c
    this->ringIndex = 0;           // +0xc0
    this->flag_bc = 1;             // +0xbc
    *(uint8_t *)((char*)this + 0xc4) = 0x2c;

    for (int i = 0; i < 10; ++i) {
        this->ringCap[i] = 0x100;                 // @ +0x6c
        void *p = operator_new__(0x100);
        this->ringBuf[i] = p;                     // @ +0x4
        memset(p, 0, 0x100);
    }
    // zero 5× language pack pointer pairs + counts (@ +0x58 / +0x94 area)
    return this;
}
```

---

## 5. Assembly notes (`read_memory` head)

```
007a6910  53 55                 push ebx / ebp
007a6912  8b6c240c              mov  ebp, [esp+0xc]   ; this (stack formal)
…
007a691a  c74500 886fa900       mov  dword [ebp], 0x00a96f88
007a6921  89452c                mov  [ebp+0x2c], eax  ; 0
007a6924  8985c0000000          mov  [ebp+0xc0], eax
007a692a  c785bc000000 01000000 mov  dword [ebp+0xbc], 1
007a6934  c685c4000000 2c       mov  byte  [ebp+0xc4], 0x2c
; then 10× push 0x100 / call operator_new__ / rep stos zero
```

Convention: **stack `this`** (not ECX) — matches MSVC ctor for return-this / placement style used by singleton `push &DAT_00d1f660; call`.

---

## 6. Gaps

1. Product class / method name.
2. Exact semantics of `+0xbc` flag and five pack tables (filled by other VAs).
3. Second caller `FUN_008cd200` role (may construct non-singleton instance — residual).

**Verdict:** **accept** — sealed ctor CF, vtable, ring buffer init, default locale 0, object layout anchors used by GetInstance / GetLocaleCode / localize.
