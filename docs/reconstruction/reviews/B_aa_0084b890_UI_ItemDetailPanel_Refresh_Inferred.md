# Review B (skeptical / adversarial): `aa_0084b890` UI_ItemDetailPanel_Refresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084b890` |
| **VA** | `0x0084b890` |
| **Canonical name** | `UI_ItemDetailPanel_Refresh_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0084b890_UI_ItemDetailPanel_Refresh_Inferred.md` |
| **System** | client UI / inventory item detail |
| **Live tools** | Ghidra `decompile_function`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — stages/ABI/constants sealed; do not over-claim product names or bit-exact |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Direct CALL site list empty ⇒ dead code | DATA xref vtbl `0x00a697e4`; live body large | **Falsified** dead — **virtual** method |
| 2 | `float *param_1` means float buffer API | `mov ebp,ecx`; gate dword ptr; child vfuncs | **Falsified** — panel `this*`; float* is decompiler fiction |
| 3 | `param_1[0x146] != 0.0` is float compare | Machine `cmp dword [ebp+0x518],0` | **Falsified** — **pointer null check** |
| 4 | Function only loads broken DDS | Many layout/text/tooltip/gauge stages | **Falsified** as DDS-only |
| 5 | Alias `UI_overlay_broken` is product name | Single texture string; panel does full refresh | **Not sealed** as product — string-weak only |
| 6 | Deg constant is 57.3 (single `180/π`) | `DAT_00aaa99c` bits → ≈114.59 = **2×(180/π)**? Wait: 180/π≈57.3; 360/π≈114.59 | **Sealed as ≈114.59** — may be full-turn scale or 2×; product formula residual |
| 7 | Percent uses raw 0–1 without clamp | `if (DAT_00aaa7ac < local) local = DAT_00aaa7ac` with 100.0 | **Falsified** missing clamp |
| 8 | Always shows percent | Guarded by `DAT_00d1791c` | **Falsified** always-on |
| 9 | Network / skill cast entry | No bitstream; UI vfuncs + tooltip | **Falsified** |
| 10 | Named clean is bit-exact full port | Stage summary; scaffold holds full decomp temps | **Agree residual** — not bit-exact claim |
| 11 | Runtime verified | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX panel | **Confirmed** | Wrong ABI |
| Gate +0x518 object* | **Confirmed** | Null-deref mis-model |
| Vtbl dispatch only | **Confirmed** | Miss callers in static search |
| Strings + tooltip callee | **Confirmed** | Wrong subsystem tag |
| Scale floats | **Confirmed** | Wrong layout metrics |
| Percent clamp 100 | **Confirmed** | UI overflow |
| Acos×DAT_00aaa99c gauge | **High** | Wrong angle units if 114.59 formula misread |
| Child English names | **Low–Med** | Docs only |
| Product class name | **Low** | Rename churn |
| Full body bit-exact | **Open** | 4.5KB surface |

### Note on 114.59

`180/π ≈ 57.2958`, `360/π ≈ 114.5916`. Memory matches **360/π** (or 2× rad→deg). Review A’s “180/π” shorthand is **slightly wrong**; sealed value is **≈114.5916**. Product may feed acos of a special domain (e.g. already half-range). **Do not invent formula beyond constant×acos.**

---

## 3. Cross-check

```
raw decompile ≡ live decompile (W22-K).
Prologue: 55 8B EC 83 E4 F8 81 EC 40 01 00 00 53 55 56 57 8B E9
Gate:     83 BD 18 05 00 00 00  0F 84 B3 11 00 00
Epilogue: … 5F 5E 5D 5B 8B E5 5D C3
Xref:     00a697e4 DATA only
Callee:   UI_BuildItemTooltipStats @ 00847ad0 present
Float:    aaa7ac=100.0; aaa99c≈114.59; scales ~1/1600 and ~1/1200
```

### Over-claim traps

* Treating decompiler `float *` indices as IEEE loads for object slots.
* Claiming PDB name `UI_ItemDetailPanel_Refresh` without RTTI.
* Claiming every vfunc ordinal English from sibling duals without this-body proof.
* Claiming bit-exact from stage-level named clean.

---

## 4. Surviving contract for AutoCore

```
UI_ItemDetailPanel_Refresh (thiscall):
  if (this->object@+0x518 == null) return;
  // layout + paint bound item into child widgets
  // optional broken overlay DDS
  // optional percent (mode flag DAT_00d1791c) clamped to 100
  // UI_BuildItemTooltipStats(...)
  // optional acos gauges * ~114.59
  // COID table may set mode flag
  // footer by item type

AutoCore must NOT:
  - search only code xrefs (miss vtbl)
  - treat unit as float-array API
  - skip null object gate
  - assume always-broken overlay or always-percent
  - claim full bit-exact without runtime/diff
```

**Port tests (static-derived):**

* Null `+0x518` → no child writes / early return.
* Mode flag off → no `%.01f%%` sprintf path.
* Subtype short ≠ 8 → overlay vfunc `+0x1a0` with 0.
* Gauge path requires nested object from vfunc `+0x1e0` non-null.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Virtual item panel refresh | **Agree High** |
| Gate +0x518 Confirmed | **Agree** |
| Constants sealed | **Agree** (fix deg as 360/π value, not 180/π label) |
| accept-with-gaps | **Agree** |
| Product name Probable | **Agree** — keep `_Inferred` |

---

## 6. Open questions

1. RTTI / class name for vtbl containing `0x0084b890`.
2. Who writes `this+0x518` and when.
3. Exact domain of acos input at nested `+0xdc` (why ×114.59).
4. Full vfunc ordinal dictionary for NDUI widget base.
5. Live UI open → refresh hit confirmation.

**Verdict:** **accept-with-gaps** — adversarial pass keeps stage/ABI/constant seals; blocks DDS-only naming, float-buffer misread, and bit-exact overclaim.
