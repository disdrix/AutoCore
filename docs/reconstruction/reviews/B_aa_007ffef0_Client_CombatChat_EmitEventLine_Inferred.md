# Review B (skeptical / adversarial): `aa_007ffef0` Client_CombatChat_EmitEventLine_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_007ffef0_Client_CombatChat_EmitEventLine_Inferred.md` |
| **Agent** | WQ9D-I OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill cast / damage apply logic | **Falsified** — no packet send; only format + `FUN_008f8200` |
| 2 | `__thiscall` with ECX host | **Falsified** — entry loads `[esp+4]`; epilogue `ret 8` |
| 3 | Return value in EAX is meaningful | **Unproven / void role** — no live RET consumer sealed; decompiler void |
| 4 | `param_2` is a pure `TFID_16*` only | **Partially falsified as sole type** — overlay: two TFIDs + amount/flags + type dword; product struct open |
| 5 | Channel 0x12 is only “miss” | **Falsified as exclusive** — also dodge / resist / deflect plates |
| 6 | Heal amounts stored positive | **Falsified** — case 1 uses **negated** `dwCoidLo` |
| 7 | Always emits even for unrelated world combat | **Falsified** — multi-stage relevance + crew gates before format |
| 8 | `DAT_00a84270` is “Deflects An Attack” | **Falsified** — `read_memory` = `"for"` (adjacent string plate noise) |
| 9 | Product name is retail-known | **Unproven** — `_Inferred` |
| 10 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 11 | `DAT_00af921c` is exclusively combat options | **Open** — ChatLog dual labels month-name table at same VA; bit CF still real |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 / two stack args | **Confirmed** | Wrong port ABI |
| Chat-only role | **Confirmed** | Mis-place in skill sim |
| Channel map 0x10–0x16 | **Confirmed** | Wrong combat pane routing |
| Type 0..3 families | **Confirmed** | Wrong string assembly |
| `"XP"` / `"Hits"` / `"Saps"` / `"for"` | **Confirmed** | Locale key mismatch |
| Crew filter via `FUN_005749d0` | **Confirmed** | False suppress of convoy combat spam |
| Event blob product English | Open | Doc-only risk |
| Option global product | Open | Filter defaults |

---

## 3. Cross-check

```
aa_008f8200 CDlgChatLog_AppendChannelMessage:
  channels [0x10,0x18] → combat dual-pane; style "" when gm=0
aa_0040aff0 Object_CopyTfid16At228_Inferred:
  related TFID extract used ×4 in this unit
aa_005749d0 VehicleCrew_ContainsMember_Inferred:
  same +0xCB0 crew host pattern
FUN_0093ffb0:
  sole caller; builds floaters then FUN_007ffef0()
```

**Attack on “case 3 is currency not XP”:** `read_memory DAT_00a43258` = `XP\0` — sealed.

**Attack on “shielded uses different amount field”:** raw compares `param_2[2].dwCoidHi == dwCoidLo` then strcat `"(Shielded)"` and channel `0x16`.

---

## 4. Residual risks

- Decompiler sticky TFID typing may hide true struct name.
- Self-dodge early-out depends on exact flag byte; port must match raw field.
- `DAT_00af921c` bit semantics vs month table — do not invent options UI until disambiguated.

**Verdict:** **accept-with-gaps** — no CF reject.
