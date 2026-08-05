# Review B (skeptical / adversarial): `aa_004bb970` ClonedObjectList_TakeByCoid (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bb970_ClonedObjectList_TakeByCoid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Creates a new clone | No allocator; resolves existing via `FUN_004bcda0` | **Falsified** |
| 2 | Pure lookup no side effects | Clears `+0xd0..+0xdc` links + vector erase | **Falsified as pure** — **take/detach** |
| 3 | Fails open on bad host | Multiple early 0 + NDError logs | **Falsified** |
| 4 | Type list optional | Null typelist → log + 0 | **Falsified as optional** |
| 5 | Loot-only | 7 xrefs | **Falsified as sole** |
| 6 | Mode flag is quantity | Selects char gate `+0xc/+0xd` only | **Falsified** |
| 7 | Product PDB name known | Inferred from strings | **Gap** |

---

## 2. Confidence

| Area | Confidence | Risk if wrong |
|---|---|---|
| COID resolve + return object | **High** | Loot miss |
| Detach side effects | **High** | Dangling list links |
| String class family | **High** | — |
| Per-field link roles | **Probable** | Leak / double-free |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
// thiscall, ret 0x0C
Object* ClonedObjectList_TakeByCoid(Host* this, uint modeByte, uint coidLo, uint coidHi);
// null on gate/resolve/typelist failure; else object with aux links cleared
```

**Verdict:** take/detach role **survives**. **accept-with-gaps.**
