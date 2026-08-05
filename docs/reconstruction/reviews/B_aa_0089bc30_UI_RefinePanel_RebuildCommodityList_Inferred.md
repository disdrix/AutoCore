# Review B (skeptical / adversarial): `aa_0089bc30` UI_RefinePanel_RebuildCommodityList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089bc30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0089bc30_UI_RefinePanel_RebuildCommodityList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Single list walk for all modes | Reverse uses inventory list + RTTI; forward uses hash iter | **Falsified** as single-walk |
| 2 | Always clears catalog dirty bit | Only forward path after while | **Falsified** |
| 3 | Accepts any clone type | Forward requires `+0x38==0x1a`; reverse requires commodity cast + `+0x4d0!=-1` | **Falsified** as unfiltered |
| 4 | This is the row widget binder | Binder is `FUN_0089a260`; this is **enumeration** | **Falsified** as binder |
| 5 | Multiple independent callers | Sole xref `FUN_0089c6c0` | **Falsified** |
| 6 | `__thiscall` ECX this | Caller `PUSH EDI` stack this | **Sealed as stack this** |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual reverse/forward enumeration | **High** | Wrong list source |
| Type `0x1a` filter | **High** | Wrong catalog slice |
| `FUN_0089a260` per row | **High** | Missing UI rows |
| Dirty clear only on forward | **High** | Stale reverse UI |
| Type English "commodity" | **Probable** | Doc only |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
void UI_RefinePanel_RebuildCommodityList(RefineUiHost* host /*stack*/);
```

- No-op if globals or `host+0x568/0x56c` null.
- Reverse (`+0x538`): inventory commodities with product key; flag always 1 into row helper.
- Forward: hash walk type `0x1a` + `FUN_00522060` qty; clear dirty at `*(DAT_00d1b570+0xf14)+0x1d`.

---

## 4. Verdict

**accept-with-gaps** — dual enumeration sealed; keep row helper name open.
