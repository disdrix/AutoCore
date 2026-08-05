# Review B (skeptical / adversarial): `aa_008bf070` LootUi_MaybeNotifyNonType4 (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bf070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008bf070_LootUi_MaybeNotifyNonType4_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always runs notify on loot | Four independent gates | **Falsified** |
| 2 | Type-4 is included | Explicit `==4` early out | **Falsified** |
| 3 | Portable cdecl(item, host) | EAX item + ESI host register | **Falsified as portable** |
| 4 | Mutates inventory grid | Only two UI callees | **Falsified** |
| 5 | Many parents | Sole lootpickup xref | **Survives** |
| 6 | Global names known | `DAT_00d1a8f0` / `DAT_00d1a8dd` unlabeled | **Gap** |

---

## 2. Surviving contract

```
// EAX=item, ESI=uiHost
// if global_a8f0 && item && type!=4 && !global_a8dd:
//   FUN_004104f0(uiHost+0x510); FUN_008bee80();
```

**Verdict:** gate CF **survives**. **accept-with-gaps.**
