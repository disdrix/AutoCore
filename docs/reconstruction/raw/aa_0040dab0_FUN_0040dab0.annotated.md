# Annotated low-level: FUN_0040dab0 → Math_RoundFloatToInt_MissionXpBias_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0040dab0` |
| VA | `0x0040dab0`–`0x0040dad7` (**40 B** / `0x28`) |
| System | missions-progression (shared float→int utility; primary dual parent = mission reward toast) |
| Date | 2026-08-05 (MEGA-119 dual refresh) |
| Ghidra name | `FUN_0040dab0` |
| Canonical name | `Math_RoundFloatToInt_MissionXpBias_Inferred` |
| Prior scaffolds (retired) | `Mission_Bulk_0040dab0` (keyword bulk misname) |

## Machine-level notes

- Source: raw capture + MEGA-119 live re-verify (`decompile_function` ≡ raw CF; `disassemble_function` + `read_memory` seal ABI).
- **ABI:** stack `float` @ `[ESP+4]`; return **EAX** (`CVTTSS2SI`); plain **`RET`** (`C3`) ×2 — not thiscall; ECX unused.
- **Bias:** `g_flMissionXpRoundBias` @ `0x00aaa6d0` = **0.5001f** (`8e 06 00 3f`).
- **Semantics:** signed round half-away-from-zero:
  - `param < 0` → `(int)(param - bias)` trunc toward zero after subtract
  - `param >= 0` → `(int)(param + bias)` trunc toward zero after add
- **COMISS/JBE:** `XMM1=0`; jump-if-below-or-equal → nonnegative path (add).
- Leaf: no callees. Pad `CC` from `0x0040dad8`.

## Pseudocode (annotated)

```c
// Math_RoundFloatToInt_MissionXpBias_Inferred
// Stack float; EAX int; plain RET. Shared by mission reward toast and other UI/math consumers.
int Math_RoundFloatToInt_MissionXpBias_Inferred(float value)
{
  // g_flMissionXpRoundBias @ 0x00aaa6d0 == 0.5001f
  if (value < 0.0f) {
    return (int)(value - g_flMissionXpRoundBias); // CVTTSS2SI after SUBSS
  }
  return (int)(value + g_flMissionXpRoundBias);   // CVTTSS2SI after ADDSS
}
```

## Callers (sealed set)

| Caller | Role |
|---|---|
| `Client_ShowMissionRewardChatToast` `0x008ac540` @ `0x008ac624` | float XP from `Mission_ComputeObjectiveXpAsFloat` → int for `"Awarded %d"` + floater |
| `FUN_0087d810` (×8) | multi-site float→int |
| `FUN_00503780` (×4) | multi-site float→int |
| `FUN_0056a680` @ `0x0056a744` | item scaled cycle int (also inlines ±bias for threshold) |
| `FUN_0049aa60`, `FUN_005d9290`, `FUN_0054cb10` | other float→int consumers |
| Orphan xrefs `0x009005dd`, `0x0090063a`, `0x008a45e3` | call sites without recovered host fn |

## Open questions

- Product English name of the shared helper (no plate string).
- Host functions for the three orphan call sites.
- Runtime / bit-exact / differential (deferred; no Launcher).
