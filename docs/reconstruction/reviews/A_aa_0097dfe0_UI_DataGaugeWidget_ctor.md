# Review A (reconstruction fidelity): `aa_0097dfe0` UI_DataGaugeWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097dfe0` |
| **VA** | `0x0097dfe0` |
| **Canonical name** | `UI_DataGaugeWidget_ctor` |
| **Ghidra / plate alias** | `UI_CooldownGaugeWidget_ctor` |
| **Former name** | `FUN_0097dfe0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (UI gauge widget ctor) |
| **Counterpart** | `reviews/B_aa_0097dfe0_UI_DataGaugeWidget_ctor.md` |
| **System** | client UI / quickbar cooldown gauge |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Constructs a **data/cooldown gauge** UI widget used heavily by quickbar builders (`QuickBar_BuildItemButtonWidgets`, `QuickBar_BuildSkillButtonWidgets`) and other UI factories. Ghidra plate associates it with **`i_d_qb_2d_btn_quickbar_cooldown.xml`** and object extent **`0x4bc`**.

Thin ctor: base UI construct `FUN_00863f10(this)`, install gauge vtable, seed a few tail fields.

**Not** the per-frame cooldown math (`QuickBar_UpdateSkillSlotCooldownGauge` / overlay updaters are separate VAs).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `batch_decompile` `0x0097dfe0` |
| Prologue | `read_memory` @ `0x0097dfe0`: SEH `LAB_009b4a8a`; `mov esi,[esp+0x14]` this; `call FUN_00863f10`; `movss` from `DAT_00d1e504` |
| Globals | `audit_globals_in_function` — `DAT_00d1e504` (2 xrefs), `PTR_FUN_00a62454` |
| Xrefs | many UI callers (QuickBar build ×2, `FUN_0088ac20`, `FUN_0088c450`, `FUN_00892ed0` ×3, `FUN_008b27f0`, `FUN_008c7c60` ×3, …) |
| Three-rep | `raw/aa_0097dfe0_*`, `reconstructed-exact/FUN_0097dfe0.cpp` |
| Function record | `functions/aa_0097dfe0_FUN_0097dfe0.md` |

---

## 3. Signature (ABI)

```c
// thiscall: ECX / first arg = widget this (size 0x4bc at factories)
// returns this

void * UI_DataGaugeWidget_ctor(void *this);
// Ghidra: UI_CooldownGaugeWidget_ctor
```

---

## 4. Control flow (sealed)

```
SEH setup (LAB_009b4a8a)
FUN_00863f10(this)                 // base UI widget ctor

this+0x4a8 = DAT_00d1e504          // shared default (movss/mov from global)
*this      = PTR_FUN_00a62454      // gauge vtable (after base)
this+0x4b4 = 0x0f                  // 15
this+0x4ac = 0
this+0x4b0 = 1                     // byte/bool enable-style
this+0x4b8 = 4

return this
```

---

## 5. Layout / constants (sealed)

| Offset | Init | Notes |
|---:|---|---|
| `+0x00` | `PTR_FUN_00a62454` | gauge vtable (overrides base) |
| `+0x4a8` | `DAT_00d1e504` | default scalar/param (global, 2 xrefs — tight) |
| `+0x4ac` | `0` | |
| `+0x4b0` | `1` | byte |
| `+0x4b4` | `0x0f` (15) | |
| `+0x4b8` | `4` | |
| extent | **`0x4bc`** | plate / factory new size |

Base fields below `+0x4a8` come from `FUN_00863f10` (out of own-only scope).

---

## 6. Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Callers | QuickBar item/skill button builders; several UI `FUN_008*` factories | multi-use widget |
| Callee | `FUN_00863f10` | base widget ctor |
| Globals | `DAT_00d1e504`, `PTR_FUN_00a62454` | |

---

## 7. Decompiler hazards

1. **Naming: Data vs Cooldown** — user/canonical `UI_DataGaugeWidget_ctor` vs Ghidra `UI_CooldownGaugeWidget_ctor`. Evidence (quickbar cooldown XML, build-skill/item callers) favors **cooldown gauge** product role; keep dual name with alias.
2. **`DAT_00d1e504` type** — decomp shows dword assign; prologue uses `movss` path in bytes (`f30f1005…`) → **float-ish** global. Treat as 4-byte payload until typed.
3. **No math in ctor** — do not invent fill/cooldown formulas here.

---

## 8. Confidence

| Area | Level |
|---|---|
| Role: UI gauge widget ctor for quickbar cooldown UI | **High** |
| Tail field inits `+0x4a8..+0x4b8` | **High** |
| Vtable `PTR_FUN_00a62454` | **High** |
| Size `0x4bc` | **High** (plate + factory pattern) |
| Canonical English Data vs Cooldown | **Medium** (alias both) |
| Meaning of constants 15 / 4 / `DAT_00d1e504` | **Medium–Low** |
| Base ctor `FUN_00863f10` | **Out of scope** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — trivial sealed initializer; residual is semantic names for tail constants and base class body.
