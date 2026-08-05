# Review A (reconstruction fidelity): `aa_004f4e50` Object_GetLinkedActorLevel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4e50` |
| **VA** | `0x004f4e50` |
| **Canonical name** | `Object_GetLinkedActorLevel_Inferred` |
| **Ghidra name** | `FUN_004f4e50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004f4e50_Object_GetLinkedActorLevel_Inferred.md` |
| **System** | `missions-progression` / combat |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Resolve a **linked actor** from `this+vb+0xb0` and return its **level-like** vcall `vtbl+0x27c`:

```text
// ECX = object* (vehicle/victim host)
obj = *(this + *(*(this+4)+4) + 0xb0)   // pointer field @ base+0xb0
kind = *(obj[0x2a] + 0x38)              // template type @ def+0x38
if (kind == 0x12):                      // creature
  mid = vcall(obj, vtbl+0x1d8)()
  return vcall(mid_base, vtbl+0x27c)()  // level
if (kind == 0x14):
  mid = vcall(obj, vtbl+0x1dc)()
  return vcall(mid_base, vtbl+0x27c)()
return 0
```

OnDeath vehicle path (`kind 0xe` victim): `iStack_7c = FUN_004f4e50()` used as level arg to `CalculateAndAwardKillXP` and credits distance checks (`level_delta < 0xb`).

Ghidra jumptable warnings on the `+0x27c` indirects — treated as single virtual call (not switch tables).

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | host object* with field `base+0xb0` |
| **EAX** | level (int) or **0** |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `analyze_function_complete` |
| Callers | `OnDeathAwardKillXp` `004daa9f`; `FUN_00515520` ×2 |
| Type codes | **0x12** creature, **0x14** other (char/player family); **0** else |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Field `base+0xb0` object* | **High** |
| Type test def+0x38 | **High** |
| Dual paths 0x12 / 0x14 | **High** |
| Terminal vtbl **+0x27c** | **High** (same as other level sites in OnDeath) |
| Mid vtbl **+0x1d8 / +0x1dc** identity | **Probable** (owner/controller getters) |
| English name | **Probable** |

---

## 5. Gaps

1. Exact meaning of `+0xb0` link (pilot? owner? target?).
2. Type **0x14** product name.
3. Null-deref if `+0xb0` null (no guard in decompile).

**Verdict:** **accept-with-gaps**.
