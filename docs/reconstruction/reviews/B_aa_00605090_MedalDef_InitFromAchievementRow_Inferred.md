# Review B (skeptical / adversarial): `aa_00605090` MedalDef_InitFromAchievementRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00605090` |
| **VA** | `0x00605090` |
| **Canonical name** | `MedalDef_InitFromAchievementRow_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00605090_MedalDef_InitFromAchievementRow_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | param_5 is a fifth string | No load of stack slot; parent pushes 0 | **Falsified** used arg |
| 2 | Stores wide strings directly | Always W→MBCS via `00403450` then char* setters | **Falsified** wide store |
| 3 | Leaves old strings if overwrite | Setters free previous non-null before assign | **Falsified** leak on reuse (fresh new is null from Zero) |
| 4 | param_6 → +0x0c and param_7 → +0x10 | Body: param_7→`00604f90`(+0xc), param_6→`00605010`(+0x10) | **Attack fails** — crossed vs naive left-to-right |
| 5 | Returns HRESULT | `MOV AL,1` success bool | **Falsified** HRESULT |
| 6 | Inserts into hash itself | Insert is `FUN_0051e4d0` in parent | **Falsified** insert role |
| 7 | Decompiler “unreachable free” = dead product code | SEH unwind edges for temp buffers | **Agree** not product branches |

---

## 2. Live ≡ raw

```
*this = id
×4: GetACP → WideCharToMultiByte temp → setter
this+0x14 = param_8; this+0x18 = param_9
AL=1; ret 0x20
```

Crossed wide args confirmed by listing pushes vs setter order.

---

## 3. Surviving contract

```
// MedalDef* this (0x1c), eight stack args, ret 0x20
// id + four ACP strings + two trailing dwords from tAchievement row
// stack arg #4 (0-based among the eight) unused
```

**Verdict:** **accept-with-gaps.**
