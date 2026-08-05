# Review A (reconstruction fidelity): `aa_008faaf0` CDlgCharSheet2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008faaf0` |
| **VA** | `0x008faaf0` |
| **Canonical name** | `CDlgCharSheet2d_CreateChildWidgets` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B; decompiler blocked) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md` |
| **System tag** | `client-ui` / character sheet (unknown system index) |
| **Verdict** | **accept-with-gaps** (role + XML asset set + construct pattern **High**; full CF / host-offset map residual) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live 2026-07-29) | **FAILED** — `Low-level Error: Overlapping input varnodes` (force_decompile same) |
| Ghidra `get_function_signature` | 671 insns, 69 BB, cyclomatic ~32, 30 calls, 30 string refs |
| Ghidra `analyze_function_complete` | signature, callees, DATA xref, completeness ~34 (decomp unavailable) |
| Image (`read_memory`) | prolog @ `0x008faaf0`..+~0xc0; vtable DATA @ `0x00a35b30` |
| Clean | `docs/reconstruction/reconstructed-exact/CDlgCharSheet2d_CreateChildWidgets.cpp` |
| Raw / annotated | `docs/reconstruction/raw/aa_008faaf0_*` |
| Function record | `docs/reconstruction/functions/aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md` |

---

## 2. Purpose (sealed High on role)

**Client 2D character-sheet dialog child construction** (`CreateChildWidgets` virtual): allocate/attach NDUI children and load `i_d_c_2d_*` / `i_d_tabs_c_2d_*` XML chrome for experience/credits, attribute panes + add buttons + tooltips, name/level/race/class/clan, tab icon, close button; may call `Client_MaybeShowFirstTimeTip`.

Not a network/send path; not attribute-spend game logic (spend handlers are separate). UI tree build only.

---

## 3. Evidence

### 3.1 Signature / callees (High)

| Fact | Value |
|---|---|
| Prototype | `void __fastcall CDlgCharSheet2d_CreateChildWidgets(void *this)` — `this` in **ECX** |
| Size | 671 instructions, 69 basic blocks, ~30 calls |
| Callees (unique) | `FUN_00792600`, `operator_new`, `FUN_0040ddd0`, `FUN_007b5dd0`, `FUN_008a05a0`, `Client_MaybeShowFirstTimeTip` |
| Xrefs | **DATA only** `0x00a35b30` → dword `0x008faaf0` (virtual method; no direct CALL sites) |

### 3.2 Image prolog (`read_memory` @ `0x008faaf0`) — construct pattern High

```text
; SEH frame (push -1 / handler 0x009ba9be / fs:[0])
MOV  ESI, ECX                    ; this
CALL FUN_00792600                ; base/list init (sibling CreateChildWidgets pattern)
PUSH 0x488                       ; 1160 — NDUI child size
CALL operator_new
... null-check ...
CALL FUN_0040ddd0                ; child ctor (push 0, child*)
MOV  [ESI+0x1478], EAX           ; first child host slot
CALL [vtbl+0xA8]                 ; parent attach (this, child)
MOV  ECX, [ESI+0x1478]
PUSH "i_d_tabs_c_2d_wnd_icon.xml" ; 0x00a361f0
CALL [child.vtbl+0x28]           ; load XML
...
PUSH "i_d_tabs_c_2d_wnd_icon_cover.xml" ; 0x00a361cc
CALL [this.vtbl+0x404]           ; sibling load path
; further operator_new(0x488)+ctor, attach, XML loads
PUSH "i_d_c_2d_wnd_bg_character.xml"    ; 0x00a361ac
CALL [child.vtbl+0x28]
... CALL [vtbl+0xFC] ...
MOV  [ESI+0x1464], ...           ; another host slot
```

Bytes (entry through first attach): `6A FF 68 BE A9 9B 00 … 8B F1 E8 … 68 88 04 00 00 E8 … 89 86 78 14 00 00 FF 92 A8 00 00 00 … 68 F0 61 A3 00 FF 50 28`.

| Mapping | Confidence |
|---|---|
| `__fastcall` / `ESI = this` | **High** (image) |
| Entry calls `FUN_00792600` | **High** |
| Child size `0x488` + `operator_new` + `FUN_0040ddd0` | **High** |
| Host store `this+0x1478` (first recovered child) | **High** |
| Parent vcall `vtbl+0xA8` attach | **High** |
| Child XML load via `vtbl+0x28` | **High** |
| Secondary load path `this.vtbl+0x404` | **High** |
| Host store `this+0x1464` (second recovered) | **High** (image mid-body) |
| Full ordered map of every host offset ↔ XML | **Medium / residual** (decomp blocked; 30 XMLs) |

### 3.3 XML string set (High — `get_function_signature` + `search_strings`)

Character sheet / tabs asset family (complete set from function string refs):

| Group | XML |
|---|---|
| Tab chrome | `i_d_tabs_c_2d_wnd_icon.xml`, `i_d_tabs_c_2d_wnd_icon_cover.xml` |
| Identity | `i_d_c_2d_wnd_title.xml`, `i_d_c_2d_wnd_name.xml`, `i_d_c_2d_wnd_level_race_class.xml`, `i_d_c_2d_wnd_clan.xml`, `i_d_c_2d_wnd_bg_level_race_class.xml`, `i_d_c_2d_wnd_bg_character.xml` |
| Experience | `i_d_c_2d_wnd_label_experience.xml`, `i_d_c_2d_wnd_bg_experience.xml`, `i_d_c_2d_wnd_experience.xml`, `i_d_c_2d_wnd_experience_wide.xml` |
| Credits | `i_d_c_2d_wnd_label_credits.xml`, `i_d_c_2d_wnd_credits.xml`, `i_d_c_2d_wnd_credits_wide.xml` |
| Attributes | `i_d_c_2d_wnd_bg_attribs.xml`, `i_d_c_2d_wnd_attribute_points.xml`, `i_d_c_2d_wnd_attrib_{combat,theory,tech,perception}.xml` |
| Attrib add | `i_d_c_2d_btn_attrib_{combat,theory,tech,perception}_add.xml` |
| Tooltips | `i_d_c_2d_wnd_tooltip_attrib_{combat,theory,tech,perception}.xml` |
| Close | `i_d_c_2d_btn_close.xml` |

(Also present in string table near assets: `i_d_c_2d_wnd_geo.xml` — confirm in-body use if CF recovered.)

### 3.4 Immediate values (Probable / partial)

From signature: control-like ids **40000..40004**, small indices **1..12**, sizes **0x488 (1160)** and **200**, flags/bitmasks **32/64**, tip-adjacent small ints **20/27** (tip ids are 0..0x31 per `Client_MaybeShowFirstTimeTip` plate — exact tip id used here **not image-sealed** without call-site decode).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Named CreateChildWidgets for 2D char sheet | **High** | Ghidra name + XML family |
| `__fastcall` void(this*) | **High** | signature + ECX→ESI |
| Virtual method (DATA `0x00a35b30` only) | **High** | xref |
| UI construct only (no C2S / no spend logic) | **High** | callees + strings; no packet helpers |
| `FUN_00792600` then repeated new(0x488)/ctor/attach/XML | **High** | image prolog + callee list |
| Host slots include `+0x1478`, `+0x1464` | **High** | image stores |
| Full 30-string construction order | **Medium** | partial image walk; decomp blocked |
| Every child host offset map | **Tentative** | residual |
| Exact `Client_MaybeShowFirstTimeTip` tip id(s) | **Tentative** | callee present; imm not sealed to call |
| English product layout of all panes | **Medium** | strings name them; layout residual |

---

## 5. Control flow: clean ≡ raw (structural)

| Stage | Match |
|---|---|
| Scaffold documents decompiler block + role + string set | **Yes** |
| Clean body is full CF rewrite | **No** — intentional structural stub |
| Image prolog ≡ annotated “FUN_00792600 + new + tip + close” narrative | **Partial** — prolog sealed; tip/close order not fully walked |

Clean plate correctly flags **NOT control-flow complete**. Dual accepts structural three-rep; does **not** claim bit-exact CF.

---

## 6. Gaps (do not overclaim)

1. Ghidra decompiler recovery or full manual asm walk for 69 blocks.
2. Complete host-offset ↔ child/XML table beyond `+0x1478` / `+0x1464`.
3. Exact `Client_MaybeShowFirstTimeTip` tip id and call conditions.
4. Vtable base + slot offset English (only DATA address `0x00a35b30` sealed).
5. Runtime / bit-exact / screenshot parity.
6. Role of immediates 40000–40004 (control ids Probable).

**Verdict:** **accept-with-gaps**
