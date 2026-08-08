# Review A (reconstruction fidelity): `aa_0040dab0` Math_RoundFloatToInt_MissionXpBias_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **VA** | `0x0040dab0`–`0x0040dad7` inclusive (**40 B** / `0x28`) |
| **Canonical name** | `Math_RoundFloatToInt_MissionXpBias_Inferred` |
| **Ghidra name** | `FUN_0040dab0` |
| **Prior scaffold** | `Mission_Bulk_0040dab0` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-119 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` |
| **System** | missions-progression (shared math utility) |
| **Verdict** | **accept** |

**Tools:** Ghidra HTTP `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **float → int** round helper: add or subtract `g_flMissionXpRoundBias` (0.5001f) by sign, then `CVTTSS2SI` trunc toward zero. Used by mission reward toast to turn scaled float XP into the integer shown in `"Awarded %d"` / combat floater; also shared by non-toast consumers.

```text
Math_RoundFloatToInt_MissionXpBias_Inferred(value) -> int
  if value < 0:  return trunc(value - 0.5001f)
  else:          return trunc(value + 0.5001f)
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (if-neg sub / else add + cast) |
| Full body | `disassemble_function` + `read_memory` 40 B |
| Bias dword | `read_memory` @ `0x00aaa6d0` → `8e06003f` = **0.5001f** |
| Parent toast | dualed `Client_ShowMissionRewardChatToast` site `0x008ac624` |
| Float wrapper | dualed `Mission_ComputeObjectiveXpAsFloat` `0x0051f510` feeds toast path |
| Prior clean | `Mission_Bulk_0040dab0` / `FUN_0040dab0` scaffolds (body already correct) |

---

## 3. Signature (sealed)

```c
// stack float; EAX = int; plain RET (C3); ECX unused
int Math_RoundFloatToInt_MissionXpBias_Inferred(float value);
```

| Formal | Source | Conf |
|---|---|---|
| value | stack `[ESP+4]` via `MOVSS XMM0, …` | **Confirmed** |
| return | `EAX` via `CVTTSS2SI` both exits | **Confirmed** |
| cleanup | plain `RET` (`C3`) ×2 | **Confirmed** |
| thiscall | **no** — ECX unused | **Confirmed** |
| callees | none | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| `XORPS XMM1,XMM1` zero | bytes | **Confirmed** |
| Load stack float | `MOVSS [ESP+4]` | **Confirmed** |
| `COMISS` / `JBE` nonnegative branch | bytes | **Confirmed** |
| Neg path: `SUBSS` bias → `CVTTSS2SI` → `RET` | bytes | **Confirmed** |
| Pos path: `ADDSS` bias → `CVTTSS2SI` → `RET` | bytes | **Confirmed** |
| Bias VA `0x00aaa6d0` | both memory operands | **Confirmed** |
| Body end `0x0040dad7`; pad `CC` | `read_memory` | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf utility (math) |
| External callers | **20** UNCONDITIONAL_CALL |
| Primary dual parent | `Client_ShowMissionRewardChatToast` @ `0x008ac624` |
| Other hosts | `FUN_0087d810`×8, `FUN_00503780`×4, `FUN_0056a680`, `FUN_0049aa60`, `FUN_005d9290`, `FUN_0054cb10`, 3 orphan sites |
| Callees | none |
| Shared constant | `g_flMissionXpRoundBias` (also inlined by grant / item cycle) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| SSE algorithm sealed | **Yes** |
| Bias constant sealed | **Yes** |
| Toast XP int consumer | **Yes** |
| Product demangle string | **No** |
| Toast-only exclusivity | **No** (multi-caller) |

**Decision:** promote **`Math_RoundFloatToInt_MissionXpBias_Inferred`**. Retire **`Mission_Bulk_0040dab0`**. Reject grant-authority / toast-only names.

---

## 7. Gaps

- Product English name of the shared helper.
- Host functions for orphan call sites `0x009005dd`, `0x0090063a`, `0x008a45e3`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/bias/call graph with only low-priority product-name residual → **accept**.
