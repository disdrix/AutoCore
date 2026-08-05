# Review B (skeptical / adversarial): `aa_004d9b50` CVOGSectorMap_RemoveCharacter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9b50` |
| **VA** | `0x004d9b50` |
| **Canonical name** | `CVOGSectorMap_RemoveCharacter_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md` |
| **System** | sector-map |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decrements `+0xe818` level index | Body never touches `+0xe818` — that is `004d3310` | **Falsified** |
| 2 | Always rebuilds set | Gated by `+0xf6` | **Falsified** always |
| 3 | Frees character object | Only erases pointer from vector; no dtor on element | **Falsified** destroy |
| 4 | Grows capacity | Only memmove shrink of end; grow is Add path | **Falsified** grow |
| 5 | Set size==1 always fires | Nested resolve may be null | **Falsified** always-fire |
| 6 | Unrelated to AddCharacter vector | Same `+0xe75c/+0xe760` | **Agree** same vector |

---

## 2. Live ≡ raw

```
Live ≡ raw: lower_bound/erase on +0xe75c vector;
optional +0xf6 set rebuild + sole-remaining notify;
SEH frame around temp set.
```

---

## 3. Surviving contract

```
// Remove character* from SectorMap vector; optional reindex when +0xf6.
// Does not itself adjust +0xe818 (caller may call 004d3310 after count probe).
```

**Verdict:** **accept-with-gaps.**
