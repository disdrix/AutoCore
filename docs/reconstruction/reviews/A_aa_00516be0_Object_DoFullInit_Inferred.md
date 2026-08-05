# Review A (reconstruction fidelity): `aa_00516be0` Object_DoFullInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516be0` |
| **VA** | `0x00516be0` |
| **Canonical name** | `Object_DoFullInit_Inferred` |
| **Ghidra name** | `FUN_00516be0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (A) |
| **Counterpart** | `reviews/B_aa_00516be0_Object_DoFullInit_Inferred.md` |
| **System** | object / load-init |
| **Dual status** | **Written this pass** (W24-G) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Object **full-init** helper used from load (`CLoadNode::_initFull`) and create/init paths (including a stage near string **`DoFullInit Anim`**).

Sequence:

1. `related = this->vtbl[+0x1d4]()` (related/body/parent handle — prior art).
2. If `related == null` **or** `*(related + 0x2ac) == 0`, call `this->vtbl[+0x100]()`.
3. Always call `this->vtbl[+0x48]()`.
4. If clonebase type `*(this[0x2a] + 0x38)` is **not** `0x12` and **not** `0x14`, call `Object_RefreshActiveSkillEffects_Inferred(this, 1)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00516be0_*`, `reconstructed-exact/FUN_00516be0.cpp`, `Object_DoFullInit_Inferred.cpp` |
| Function records | `functions/aa_00516be0_*` |
| Ghidra | decompile, `read_memory`, callers, callees, xrefs |
| Nested seal | `Object_RefreshActiveSkillEffects_Inferred` (`aa_00516a00`) |
| Caller context | `CLoadNode::_initFull` review; `FUN_005d5140` decompile |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds / 80 B meta | **High** | Function meta + hex |
| ECX this, void, `pop esi; ret` | **High** | Bytes |
| Gate: null related **or** `+0x2ac==0` → `+0x100` | **High** | Decompile ≡ bytes |
| Always `vtbl+0x48` | **High** | Fall-through after label |
| Skip skill refresh for types 0x12 / 0x14 | **High** | `cmp eax,12h/14h` |
| `FUN_00516a00(1)` unrestricted refresh | **High** | `push 1` + sealed callee |
| Name “DoFullInit” | **High** role / **Medium** product | Caller string + `_initFull` |
| Virtual product names | **Tentative** | Slots only |
| Type 0x12/0x14 English | **Probable** | Prior interact docs |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| related via `+0x1d4` (double call when non-null) | Yes (decompiler/bytes both call twice when testing flag) |
| skip `+0x100` when `related+0x2ac != 0` | Yes |
| always `+0x48` | Yes |
| type gate → `FUN_00516a00(1)` | Yes |
| No invented null this check | Yes |

---

## 5. Gaps / open

1. Product names for `vtbl+0x1d4` / `+0x100` / `+0x48` and flag `related+0x2ac`.
2. Why 0x12/0x14 skip skill refresh (alternate path?).
3. Full set of classes installing this in vtables.
4. Runtime / bit-exact / diff.
5. Exact MI `this` adjustment at some callers is caller-owned.

**Verdict:** **accept-with-gaps**
