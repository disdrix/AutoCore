# Review A (reconstruction fidelity): `aa_005245d0` CVOGCharacter_FindActiveObjectiveIdForPick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005245d0` |
| **VA** | `0x005245d0` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForPick` |
| **Prior names** | `FUN_005245d0`; scaffold `…ForInteractAlt`; assert-string alias risk |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |
| **System** | `interaction-activation` (also mission active-objectives) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` on **character**: given a **world object** pointer, walk the character’s **active objectives** hash at `char+0x548` and return the **objective id** (`*(instance+0x10)`) of the **first** objective whose evaluators match that object via `FUN_0059da10` (evaluator `vtable+0x44`). Null object → **0**. Exhaust / no match → **0**.

Primary product contexts: pick/hover paths (`Client_InteractClickPickTarget`, `FUN_00925820`, `FUN_00490070`) — often as a **truthy gate** or select cue; return is still an **id**, not a pure bool.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (scaffold) | `docs/reconstruction/raw/aa_005245d0_FUN_005245d0.md` |
| Raw (named) | `docs/reconstruction/raw/aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |
| Annotated | `docs/reconstruction/raw/aa_005245d0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_FindActiveObjectiveIdForPick.cpp` |
| Function record | `docs/reconstruction/functions/aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |
| Helper | `FUN_0059da10` / `0x0059da10` (eval **+0x44**; not dualed this pass) |
| Sibling walker | `0x00524520` → `FUN_0059d9c0` (`vtable+0x40`) |
| Contrast matcher | `Client_FindObjectiveMatchingTarget` `0x00525bd0` (returns **def\***, `vtable+0x38`, pending gate `+0x55c`) |
| Live decompile | Ghidra `0x005245d0`, `0x0059da10`, sibling `0x00524520`/`0x0059d9c0` (2026-07-29) |
| Xrefs | Ghidra complete analysis → 3 call sites |

---

## 3. Control flow (authoritative raw / live)

```
FUN_005245d0(character this, worldObject param_2):
  if param_2 == 0: return 0
  hash = *(character + 0x548)
  assert/set traversal lock hash+0x1d = 1
  node = 0; result = 0
  do:
    hash = *(character + 0x548)
    assert lock still set
    node = (node == 0) ? *(hash + 0x14) : *(node + 0x14)
    objInst = (node == 0) ? 0 : *(node + 8)
    if objInst == 0: goto unlock
    // thiscall: ECX = objInst; stack = (character, worldObject)
    if FUN_0059da10(character, worldObject) == 0: continue
    result = *(objInst + 0x10)
    break
  unlock: *( *(character+0x548) + 0x1d ) = 0
  return result
```

`FUN_0059da10` (live, reference):

```
this = objective instance
it = *(this+0x158); end = *(this+0x15c)
while it != end:
  if (**(*it + 0x44))(param_2, param_3) != 0: return 1
  it++
return 0
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall (Character*, Object*) → u32` | **High** | Ghidra thiscall; param_2 null gate |
| Null world object → 0 | **High** | First branch |
| Hash root `char+0x548` = active objectives | **High** | Shared with sibling / FindObjectiveMatchingTarget / registry |
| Traversal lock byte `hash+0x1d` | **High** | Same HashError / VOG_DEBUG_STOP pattern |
| Chain: first `hash+0x14`, next `node+0x14`, payload `node+8` | **High** | Identical to sibling `00524520` and `00525bd0` |
| Match helper `FUN_0059da10` with **this = objective** | **High** | Parallel to sibling; ECX = payload before call; helper reads `this+0x158` |
| Evaluator range `[obj+0x158, obj+0x15c)` | **High** | Helper body |
| Match slot **vtable+0x44** (not +0x40 / +0x38) | **High** | Helper live decompile |
| Return value = `*(objInst+0x10)` objective id | **High** | Store after match |
| Return 0 on exhaust / no match | **High** | `uVar2` init 0 + unlock path |
| First hash-order match wins | **High** | Break on first non-zero match |
| **Not** a pure boolean | **High** | Same return shape as sibling id finder |
| No pending-count gate at `+0x55c` | **High** | Absent (contrast `00525bd0`) |
| Name `…ForPick` | **Probable** | Caller roles; retail symbol not recovered |
| Character ECX provenance at every call site | **Probable / Open** | Sites decompile with one formal visible |
| Runtime pick/hover capture | **Open** | Static only this pass |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gate | **Yes** |
| Lock / traverse / unlock | **Yes** (clean keeps both assert paths) |
| Payload `node+8` | **Yes** |
| Call match helper per instance | **Yes** |
| Return `+0x10` or 0 | **Yes** |
| Clean `FUN_0059da10(obj, char, world)` arity | **Yes (intent)** — raw call-site under-types thiscall |

Prior scaffold `FUN_005245d0.cpp` / thin `…ForInteractAlt.cpp` superseded by named clean for product reading.

---

## 6. Contrast with related matchers (fidelity)

| Unit | Hash | Match | Returns | Extra gate |
|---|---|---|---|---|
| Sibling `0x00524520` | `+0x548` | `0059d9c0` → **`+0x40`** | **id** `@+0x10` | none |
| **This** `0x005245d0` | `+0x548` | `0059da10` → **`+0x44`** | **id** `@+0x10` | none |
| `FindObjectiveMatchingTarget` `0x00525bd0` | `+0x548` walk | inline eval **`+0x38`** | **def\*** | pending `+0x55c` count ≥ 1 |

Do **not** merge these three in ports.

---

## 7. Callers (all 3 xrefs)

| Site | Role |
|---|---|
| `Client_InteractClickPickTarget` `0x009247b0` | `FUN_005245d0(picked)` OR `FUN_00524520(selected)` → IfInteractable |
| `FUN_00925820` | match → `FUN_0093e120` select only; sibling match → select + IfInteractable |
| `FUN_00490070` | pick candidate filter (type 1/3) after sibling fails |

---

## 8. Gaps / open

1. Per-call-site ECX character provenance.
2. Which requirement types implement non-trivial `vtable+0x44`.
3. Runtime: multi-active objectives → first-wins order on pick/hover.
4. Helper `0059da10` full dual / rename left out of unit scope (OWN ONLY `005245d0`).

**Verdict:** Control flow and return semantics are **High**. Name is **Probable**. Residual is **caller this-pointer** and **eval implementers**, not the walk itself. **accept-with-gaps.**
