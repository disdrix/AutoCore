# Review B (skeptical / adversarial): `aa_005706d0` InventoryGrid_SetDirtyFlag (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005706d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005706d0_InventoryGrid_SetDirtyFlag_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This places / stamps footprint | No loops, no COID writes | **Falsified** |
| 2 | Always propagates dirty bit | Only if `grid+0x24 != 0` | **Falsified as always** |
| 3 | `FUN_00512670` this is the grid | Bytes load ECX from `[grid+0x24]` | **Falsified** — object child |
| 4 | Clears dirty flag | Stores **1** at `+0x21` | **Falsified** |
| 5 | Stack args / ret N | `ret` only | **Falsified** |
| 6 | Only PlaceItemFootprint caller | 4 xrefs | **Falsified as sole** — still place-family primary |
| 7 | Product name final | Inferred | **Gap** |

---

## 2. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| Set `+0x21=1` | **High** | Stale UI |
| Conditional `00512670` on `+0x24` | **High** | Missed net dirty |
| Not a placer | **High** | Wrong ownership |
| Clearer of flag | **Open** | Lifecycle |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
void InventoryGrid_SetDirtyFlag(Grid* grid /*ECX*/);
// grid[+0x21] = 1;
// if (obj = grid[+0x24]) Object_PropagateDirtyBit0x20000(obj);
```

**Verdict:** **accept-with-gaps.**

---

## WQ8R-J reconfirm (2026-08-04)

Adversarial table re-checked against live bytes/decompile/xrefs. No claim flipped. Surviving contract unchanged. Verdict remains **accept-with-gaps**.
