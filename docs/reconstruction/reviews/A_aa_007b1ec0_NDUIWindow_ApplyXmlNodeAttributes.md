# Review A (reconstruction fidelity): `aa_007b1ec0` NDUIWindow_ApplyXmlNodeAttributes

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b1ec0` |
| **VA** | `0x007b1ec0` |
| **Body** | `0x007b1ec0`–`0x007b3058` |
| **Canonical name** | `NDUIWindow_ApplyXmlNodeAttributes` |
| **Prior scaffold** | plate-named in Ghidra; raw/annotated/clean present (2026-07-23) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md` |
| **System** | client UI / `libND` (`NDUIWindow.cpp`) |
| **Verdict** | **accept-with-gaps** — ABI, attribute dispatch table, reset path, and callers sealed; product English for many field offsets / helper FUN_* open |

---

## 1. Purpose

MSVC **`__thiscall`** method on `CNDUIWindow` that walks the **MSXML attribute list** of one interface XML node and applies recognized attributes to `this` (virtual setters, direct field stores, or helper parsers). Optional **full reset** when `skipReset==0`. Nested **`INCLUDE`** re-enters load via vtbl `+0x3a4`. Unknown attribute names fall through to subclass hook vtbl `+0x3a8`.

**Not** a network path, not paint/tick, not the document open (`NDXml_*` / `InitFromInterfaceXml`).

Source anchor (log path string):

`C:\vog\1_code\vog_14_117_branch\libND\NDUIWindow.cpp` @ `0x00a96818`.

RTTI class name nearby: `.?AVCNDUIWindow@@` @ `0x00afe1b4`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md` |
| Annotated | `docs/reconstruction/raw/aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDUIWindow_ApplyXmlNodeAttributes.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md` |
| Live decompile | Ghidra `decompile_function` `0x007b1ec0` (2026-07-29) |
| Live bytes | `read_memory` prologue `0x007b1ec0` (+64), epilogue `0x007b3040` (+32) |
| Call-site asm | `get_assembly_context` @ `007b37cd`, `00792bb3`, `00793194`, `00793262`, `00793334` |
| Callers / callees | `get_function_callers` / `get_function_callees` |
| Strings | UTF-16 attr names cluster ~`0x00a9651c`–`0x00a967e4`; log msgs `0x00a967f4` / `0x00a96850` |
| Related (context only) | `NDUIWindow_InitFromInterfaceXml` `0x007b3710` (sole named parent; not owned here) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff, full helper FUN_* duals.

---

## 3. Signature / ABI — **SEALED**

| Fact | Evidence | Confidence |
|---|---|---|
| `this` in **ECX** → **ESI** | prologue `8B F1` after SEH/frame; callers `MOV ECX,EBP/ESI` | **High** |
| Three stack dwords | epilogue **`C2 0C 00`** (`RET 12`) | **High** |
| SEH | `push -1; push LAB_009b1cff; fs:[0]` — bytes `6A FF 68 FF 1C 9B 00 …` | **High** |
| Void return | terminal restore ExceptionList + `RET 0xC`; no EAX contract | **High** |
| Convention | MSVC **`__thiscall`**, 3 stack args | **High** |

```c
// 0x007b1ec0  RET 0x0C
void __thiscall NDUIWindow_ApplyXmlNodeAttributes(
    CNDUIWindow* this,           // ECX
    IXMLDOMNode* /*COM*/ node, // stack+0x04 — null OK
    char* interfacePath,         // stack+0x08 — optional; strdup → this+0x284 when full-init
    int skipReset);              // stack+0x0C — 0 = free/reset fields first + post-pass
```

### Call-site push patterns (right-to-left)

| Site | Parent | ECX | pushes (param_2,3,4) |
|---|---|---|---|
| `0x007b37cd` | `NDUIWindow_InitFromInterfaceXml` | `EBP` = window | node in `ESI`, path in `EBX`, flag in `EAX` (`[ESP+0x38]`) |
| `0x00792bb3` | `FUN_00792b50` | `ESI` = new child | `node`, **`0`**, **`0`** |
| `0x00793194` | `FUN_00793130` | `ESI` | `node`, **`0`**, **`0`** |
| `0x00793262` | `FUN_00793200` | `ESI` | `node`, **`0`**, **`0`** |
| `0x00793334` | `FUN_007932d0` | `ESI` | `node`, **`0`**, **`0`** |

Child-factory sites always pass **`skipReset=0`** and null path. Init passes its own second arg as the flag and the interface path string for logging/store.

---

## 4. Control flow (sealed outline)

```
SEH frame (LAB_009b1cff)
if (skipReset == 0):
    free/null: this[0x9d], [0x9f], [0xa0], [0xa2]     // heap string-ish slots
    zero: [0x68..0x6a], [0xa2], +0xd6, [0x54..0x55],
          [0x6b..0x6d], +0x1c9, +0x1ca
    [0x70] = DAT_00d1e818;  [0x71] = DAT_00d1e81c     // BSS defaults (zeros in static image)
    free 11 ptrs this[0x117 .. 0x121]
    [0x75]=0; [0x73]=0; byte[0x72]=0
    [0x76]=g_flOne; [0x74]=g_flOne                    // 1.0f @ 0x00a0f2a0

if (node == null) goto post
else:
    HRESULT = node.vtbl+0x44 (...)   // get_attributes (MSXML COM)
    if fail or empty → log + goto post
    map.vtbl+0x30 → length / enum setup
    for each attribute:
        get name BSTR; if name starts with L'#' (0x23) → skip value path partially
        else cascade wcscmp(name, L"<ATTR>"):
            [attribute table §5]
        Release attr COM
    Release map; goto post

post (LAB_007b2f5b):
if (skipReset == 0):
    this.vtbl+0x10c()
    pair* = this.vtbl+0x120() → copy 2 dwords → this[0x5a], this[0x5b]
    if (interfacePath): free this[0xa1]; strdup path → this[0xa1]  // byte off +0x284
SysFreeString(local); SEH pop; return
```

Log strings (ASCII):

| VA | Text |
|---|---|
| `0x00a967f4` | `"Interface lacking child nodes %s"` |
| `0x00a96850` | `"Interface file no attribs %s"` |
| `0x00a96818` | `NDUIWindow.cpp` path |

Both funnel through `FUN_0076cec0` + `vog_LogMessage`.

---

## 5. Attribute dispatch table — **SEALED** (names + primary effect)

Wide (UTF-16) names; cluster confirmed via `list_strings` / `read_memory` near `0x00a965xx`–`0x00a967e4`.

| Attribute | Effect in this unit | Confidence |
|---|---|---|
| `TOOLTIP` | value BSTR → `FUN_007ab0f0` | **High** |
| `TOOLTIP_STYLE` | `swscanf` int → `this[0x48]` (`+0x120`) | **High** |
| `INCLUDE` | wide→ansi (`FUN_0040d230`/`FUN_00402d50`); **`vtbl+0x3a4`**(path); save/restore `DAT_00d1794c` | **High** |
| `NAME` | **`vtbl+0x6c`**(ansi name) | **High** |
| `WINDOW_ID` | parse int → **`vtbl+0x74`** | **High** |
| `GAME_ID` | parse int → **`vtbl+0x7c`** | **High** |
| `IGNORES_MOUSE` | `true`→1 else 0 → **`vtbl+0x300`** | **High** |
| `WORD_WRAP` | bool → **`vtbl+0x1c4`** | **High** |
| `MOVEABLE` | `true` → byte `this+0xc5` | **High** |
| `CAN_BE_MOVEABLE` | `true` → byte `this+0xc6` | **High** |
| `STICKY` | `true` → byte `this+0xc4` (`param_1+0x31`) | **High** |
| `HYPERLINK_ROLLOVERS` | `true` → byte `this+0xda` | **High** |
| `TEXT_ALIGN` | `left/center/right/justify` → 0..3, or int in range → **`vtbl+0x1e4`** | **High** |
| `TEXT_FONT` | child attr `FONT` via `FUN_00799460`; int 0..13 → **`vtbl+0x1b0`** | **High** |
| `TEXT_SCALE` | `%f` → `this[0x4c]` (`+0x130`) | **High** |
| `MAX_TEXT_LENGTH` | int → **`vtbl+0x1d0`** | **High** |
| `TRANSITION` | int → **`vtbl+0xec`(val, 1)**; sticky “seen” flag in frame | **High** |
| `UNITS` | 0..3 → combo of bytes `+0xd6`, `+0x1c9`, `+0x1ca` | **High** |
| `BORDER` | bool → `this[0x77]` (`+0x1dc`) | **High** |
| `BORDER_THICKNESS` | int → `this[0x78]` (`+0x1e0`) | **High** |
| `BORDER_COLOR` | `FUN_007a8f80(attr, this+0x79)` | **High** |
| `ANCHOR` | `FUN_007a8b00` → `this+0x6c`, `+0x6d` | **High** |
| `TEXT_PADDING` | `FUN_007a8b00` → `this+0x6e`, `+0x6f` | **High** |
| `POSITION` | `FUN_007a9cc0(this, attr)` | **High** |
| `GEO` | `FUN_007ac940(this)` | **High** |
| `TEXT` | **`vtbl+0x268`**; optional `DAT_00d1794c` host hooks; `FUN_007add10` | **High** (control) / **Probable** (host) |
| `TEXTURE` | `FUN_007aa150(this, attr)` | **High** |
| `WINDOW_DEFINITION` | `FUN_007b1220(this, attr)` | **High** |
| `BG_COLOR` | `FUN_007ac5d0(this, attr, 0)` | **High** |
| `FG_COLOR` | `FUN_007ac5d0(this, attr, 1)` | **High** |
| `TRIM_COLOR` | nested child attrs `R/G/B/A` → pack color → **`vtbl+0x15c`(2, …)**; defaults `DAT_00d1e7d0`..`d3` | **High** |
| `TEXT_TRANSITION` | `FUN_007a9af0(this, attr)` | **High** |
| `SUB_TEXTURE` | `FUN_007ad9c0()` | **High** (call) |
| `SOUND` | `FUN_007a94d0(attr, …)` | **High** |
| **else** | **`vtbl+0x3a8`(attr, …)** subclass/unknown hook | **High** |

Name prefix **`#`** (`*(short*)name == 0x23`): skips the main cascade (treated as non-product attr / comment-style).

### `UNITS` encoding (sealed)

| Value | `+0xd6` | `+0x1c9` | `+0x1ca` |
|---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 |
| 2 | 0 | 1 | 0 |
| 3 | 0 | 1 | 1 |

---

## 6. Virtual slots used (this unit)

| Vtbl off | Role (from use) |
|---:|---|
| `+0x6c` | Set NAME |
| `+0x74` | Set WINDOW_ID |
| `+0x7c` | Set GAME_ID |
| `+0xec` | Set TRANSITION (val, 1) |
| `+0x10c` | Post-init hook (full reset path) |
| `+0x120` | Query size/pair → `this[0x5a..0x5b]` |
| `+0x15c` | Apply TRIM_COLOR (mode 2) |
| `+0x1b0` | Set TEXT_FONT index |
| `+0x1c4` | Set WORD_WRAP |
| `+0x1d0` | Set MAX_TEXT_LENGTH |
| `+0x1e4` | Set TEXT_ALIGN enum |
| `+0x268` | TEXT prelude |
| `+0x300` | Set IGNORES_MOUSE |
| `+0x3a4` | INCLUDE / nested interface load |
| `+0x3a8` | Unknown attribute extension |

Callee helpers (direct CALL, not owned here):  
`FUN_00402d50`, `FUN_0040d230`, `FUN_0076cec0`, `FUN_00799460`, `FUN_007a8b00`, `FUN_007a8f80`, `FUN_007a94d0`, `FUN_007a9af0`, `FUN_007a9cc0`, `FUN_007aa150`, `FUN_007ab0f0`, `FUN_007ac5d0`, `FUN_007ac940`, `FUN_007ad9c0`, `FUN_007add10`, `FUN_007b1220`, `operator_new[]`/`delete[]`, `swscanf`, `wcscmp`, `SysFreeString`, `free`, `vog_LogMessage`.

---

## 7. Decompiler artifacts (do not port)

1. **`_DAT_00000000` “float subtract”** after many `swscanf(L"%d;%d" / L"%f;%f")` — broken dual-out parse; second conversion is discarded. **Ignore** for reconstruction; keep only the intended destination store/virtual call.
2. **Garbage wide literals** on stack (`L"쒃謄…"`) — decompiler noise on uninitialized/`operator_delete` paths; not product strings.
3. **`unaff_ESI` / stack-var confusion** inside the attr loop — control structure (name compare cascade) is still reliable from nested `wcscmp` + known string anchors.
4. **`param_2` typed as `BSTR`** in Ghidra — actually a **COM interface pointer** (vtbl calls at `+0x44`, `+0x30`, etc.). Treat as `IXMLDOMNode*` / MSXML node.

Clean scaffold currently mirrors raw (including noise). Prefer the sealed tables in this dual over literal `_DAT_00000000` when implementing AutoCore.

---

## 8. Confidence summary

| Claim | Confidence |
|---|---|
| Role = apply MSXML attrs to `CNDUIWindow` | **High** |
| Name + `NDUIWindow.cpp` ownership | **High** |
| ABI: thiscall, 3 stack args, `RET 0xC` | **High** |
| `skipReset==0` free/reset + post vtbl hooks | **High** |
| Full attr name list + primary side effects | **High** |
| INCLUDE → vtbl `+0x3a4` nested load | **High** |
| Unknown attrs → vtbl `+0x3a8` | **High** |
| Field English labels beyond attr names | **Probable / Open** |
| Exact MSXML IID / COM slot product names | **Tentative** (offsets sealed by use) |
| Helper FUN_* internal semantics | **Open** (owned by those VAs) |
| Bit-for-bit / runtime | **Open** |

---

## 9. Gaps / open

1. Product names for freed slots `[0x9d]/[0x9f]/[0xa0]/[0xa2]` and the 11-wide table at `[0x117]`.
2. Semantics of post pair `[0x5a]/[0x5b]` from vtbl `+0x120` (size vs position vs cached metrics).
3. Full contracts of color/geo/position helpers (`FUN_007ac5d0`, `FUN_007a9cc0`, …) — separate units.
4. Whether `DAT_00d1794c` is always the “current load context” host (set by Init; saved across INCLUDE).
5. Clean `.cpp` still carries decompiler noise; optional readability pass without behavior change.

**Verdict:** Attribute dispatch + ABI + reset/post paths sealed for porting. Residual helper bodies and some field English. **accept-with-gaps.**
