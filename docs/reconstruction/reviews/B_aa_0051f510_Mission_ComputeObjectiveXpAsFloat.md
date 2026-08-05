# Review B (skeptical / adversarial): `aa_0051f510` Mission_ComputeObjectiveXpAsFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-I) |
| **Counterpart** | `reviews/A_aa_0051f510_Mission_ComputeObjectiveXpAsFloat.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only on own VA (+ minimal callee/global bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **is** the grant XP path / applies bias | **Falsified** — no load of `0x00aaa6d0`; no AddExperience; sole xref is toast |
| 2 | `__fastcall` with ECX formal on entry | **Falsified** — formal is stack `[esp+4]`; ECX only set for callee; **`ret 4`** |
| 3 | Returns int in EAX | **Falsified** — success uses `fild`; fail uses `fld`; FPU return |
| 4 | Fail returns integer 0 without float load | **Falsified** — `fld [g_flZero]` |
| 5 | Call target is not Mission_ComputeObjectiveXp | **Falsified** — rel32 seals `0x0059dde0` |
| 6 | Wrapper skips `+0x14c` (relies only on callee) | **Falsified** — body compares `[ecx+0x14c]` before call |
| 7 | Multiple code callers / advancement path | **Falsified** — single unconditional call from toast |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Presentation-only role | **High** | Wrongly port grant/bias into toast path |
| ABI stack + ret 4 + ST0 | **High** | Stack smash / wrong return channel |
| Zero fail via g_flZero | **High** | NaN / garbage float UI |
| Callee identity | **High** | Wrong XP formula surface |

---

## 3. Cross-check against raw + bytes

```
if !obj || !obj->missionDef(+0x14c):  ST0 = 0.0f; ret 4
else: ST0 = (float)Mission_ComputeObjectiveXp(obj); ret 4
```

Clean must **not** invent bias, AddExperience, or register-formal ABI.

---

## 4. Surviving contract for AutoCore

```c
// Port of Mission_ComputeObjectiveXpAsFloat (presentation only)
// stack pObjective; ret 4; return float
float Mission_ComputeObjectiveXpAsFloat(void* pObjective) {
  if (!pObjective || !*(void**)((char*)pObjective + 0x14c))
    return 0.0f;
  return (float)Mission_ComputeObjectiveXp(pObjective);
}
// Grant path: call int calc + apply g_flMissionXpRoundBias separately.
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, float return, guards, callee, presentation-only role sealed → **accept**.
