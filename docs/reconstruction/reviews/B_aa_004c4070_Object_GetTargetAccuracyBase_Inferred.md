# Review B (skeptical / adversarial): `aa_004c4070` Object_GetTargetAccuracyBase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-O) |
| **Counterpart** | `reviews/A_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |
| **Verdict** | **accept** (CF + thr sealed; naming remains inferred) |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **is** the full TargetAccuracy float formula | **Falsified** — DebugDump applies level band **after** this int return |
| 2 | `vtbl+0x1DC` is a pure bool `IsVehicle` | **Partially false** — return is **object*** (DebugDump derefs `+0x250`); this unit only tests **nonzero** |
| 3 | Vehicle thr is 101 or 0x65 | **Falsified** — thr is **1** or **-100** (`(−bool & 0x65) − 100`) |
| 4 | Always returns the clamp sum | **Falsified** — when `score ≤ thr` returns thr (vehicle floor at 1 when score≤1) |
| 5 | Contributes to NonCreatureCastAutoHit FLOAT_ADD score | **Falsified under high pcode** (that unit) — call return discarded; pure int helper |
| 6 | Offsets could be `+0x13c` / other quartet members | **Falsified for this unit** — bytes use **`0x13e` / `0x146` only** |
| 7 | `stdcall` with stack arg | **Falsified** — ECX this; bare ret |
| 8 | Name “GetTargetAccuracyBase” is PDB-proven | **Unproven** — product string is on consumer; name **Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clamp constants 200 / 250 | **High** | Combat balance wrong |
| Offsets +0x13e / +0x146 | **High** | Read wrong stats |
| thr encode 1 / -100 | **High** | Vehicle vs creature accuracy floor |
| max(score, thr) semantics | **High** | Silent floor at 1 for low vehicle scores |
| Product field English | **Low / open** | Docs only |
| vtbl+0x1DC English | **Inferred** | Wrong virtual if ported by name only |

---

## 3. Cross-check against raw + bytes

```
score = min(min(*(i16*)(self+0x13e), 200) + *(i16*)(self+0x146), 250)
thr   = (ProbeVehicleObject(self) != null) ? 1 : -100
return max(score, thr)
```

Clean must preserve **double compute** of clamp on score-return path and **second** virtual call on thr-return path if claiming instruction-level fidelity; a modernized `max` single-pass is behaviorally equal if probe is pure.

**Side-effect residual:** if `vtbl+0x1DC` is impure, collapsing to one call could change behavior — **not sealed pure**. Prefer keep dual call for exact ports; single call OK if probe proven pure.

---

## 4. Surviving contract for AutoCore

```c
// Port of Object_GetTargetAccuracyBase_Inferred
int Object_GetTargetAccuracyBase(Object* self) {
  int base = self->stat_i16_0x13e; // product name TBD
  if (base > 200) base = 200;
  int score = base + self->stat_i16_0x146;
  if (score > 250) score = 250;

  void* veh = self->GetVehicleOrNull(); // vtbl+0x1DC after MI adjust
  int thr = veh ? 1 : -100;
  return score > thr ? score : thr;
}
// Do NOT fold DebugDump level-band into this helper.
// Skill paths that ignore the return must remain ignore — do not invent FPU use.
```

---

## 5. Open questions

1. Exact product names for `+0x13e` / `+0x146`.
2. Whether any live path depends on dual probe side effects.
3. Full discarded-return call-site list beyond NonCreatureCastAutoHit.
4. Runtime golden vs retail client dump of TargetAccuracy — open.

**Verdict:** **accept**
