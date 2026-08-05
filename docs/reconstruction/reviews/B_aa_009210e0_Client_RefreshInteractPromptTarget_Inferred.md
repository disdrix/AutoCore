# Review B (skeptical / adversarial): `aa_009210e0` Client_RefreshInteractPromptTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009210e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as Activate bound-action (`PollBoundActions`) | That path sends 0x2055/0x2072; this only ends in `FUN_008a81a0` | **Falsified** merge |
| 2 | Same as `Client_FindFirstObjectInRadius` | That is last-resort callee only; body is multi-stage cascade + tip + UI | **Falsified** merge |
| 3 | Radius 25f (click gate) | All imm radius = `0x41700000` (15f); 25f is pick hub | **Falsified** |
| 4 | dist² threshold is 15.0 not 225 | `DAT_00aaaca4` bytes `00 00 61 43` = 225.0f; compared to sum of squares | **Falsified** linear-15 misread |
| 5 | Truly zero stack args | `RET 4` + caller `PUSH ESI` | **Survives** as unused formal / stdcall cleanup |
| 6 | Updates `DAT_00d1d888` itself | Body only reads it; no store to that global | **Falsified** writer claim |
| 7 | Mode 6 is living interactables | Living is mode **3** on `Skill_GatherTargetsInArea`; mode **6** is `FUN_0058cd60` broadphase sibling | **Falsified** mode swap |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23. Callers = `{FUN_009216e0}` only. Callees match complete analysis. Global float and null TFID confirmed via `read_memory`.

---

## 3. Surviving contract

```
// gate prompt host
// prefer d1d888 if not self && dist² ≤ 225
// else mode6@15 resolve; tip3 on candidate
// else mode3@15 → (flag) mode7 filterA=0x14 → FindFirst(15)
// FUN_008a81a0(host) with ESI=object
// RET 4 (unused client* formal)
```

**Gaps kept:** product names; whether timer always fires in all game modes.

**Verdict:** **accept-with-gaps**.
