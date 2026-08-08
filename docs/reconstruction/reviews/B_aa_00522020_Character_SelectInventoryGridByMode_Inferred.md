# Review B (skeptical / adversarial): `aa_00522020` Character_SelectInventoryGridByMode (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Agent** | MEGA-045 OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00522020_Character_SelectInventoryGridByMode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Mutates inventory / places items | Any store / call | **Falsified** — pure loads + returns |
| 2 | Decompiler `void` / no return | EAX at RET | **Falsified** — EAX holds grid* or 0; analyze warned `undefined` |
| 3 | cdecl / stack this | ECX loads for all hit paths | **Falsified** — **thiscall**; `RET 4` cleans mode only |
| 4 | Modes are 0/1/2 sequential | Subtract chain | **Falsified** — modes **1 / 3 / 5** only (1+2+2) |
| 5 | Mode 1 returns mid* itself | Path is mid then `+0x2B0` | **Falsified** — returns grid under mid |
| 6 | Modes 3/5 null-check like mode 1 | Extra TEST on 3/5 | **Falsified** — direct MOV; null ptr may return |
| 7 | Covers invType 2/4 | Fall-through | **Falsified as cover** — returns **0** for non-{1,3,5} |
| 8 | Many callers / vtbl slot | xrefs | **Falsified** — **1** UNCONDITIONAL_CALL only |
| 9 | Scaffold `Named_CalleeOf_Client_ConfirmEquip…` is product name | Semantics | **Reject as canonical** — retired; selector is domain name |
| 10 | Product method English sealed | String/RTTI on VA | **Gap** — `_Inferred` required |
| 11 | Locker/trade English machine-local | Labels from this body alone | **Not sealed here** — depends on cross-dual invType map; offsets sealed |

---

## 2. Residual risks

| Risk | If wrong | Mitigation |
|---|---|---|
| Non-Character ECX | Wrong grids | Sole caller equip path uses character host |
| Mode arg not invType | Wrong product enum | Matches DropResponse/Grab 1/3/5 offsets |
| Locker vs bank English swap | Mislabel only | Port uses offsets; rename later |
| Mode 1 null mid silent 0 | Caller treats as no-space | Matches parent `grid==0` branch |

---

## 3. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / ABI / RET 4 | **High** | Wrong port calling convention |
| Mode set {1,3,5} | **High** | Wrong switch cases |
| Cargo / +CBC / +CE0 loads | **High** | Wrong grid field |
| Product English | **Open** | Registry rename |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```
// __thiscall Character* this; ret 4
// stack[0] = int mode
// EAX = InventoryGrid* or 0
InventoryGrid* Character_SelectInventoryGridByMode_Inferred(ch, mode);
// mode==1: mid=*(ch+0x250); if mid: return *(mid+0x2B0); else 0
// mode==3: return *(ch+0xCBC)
// mode==5: return *(ch+0xCE0)
// else: 0
// leaf — no callees
```

**Verdict:** **accept-with-gaps.**
