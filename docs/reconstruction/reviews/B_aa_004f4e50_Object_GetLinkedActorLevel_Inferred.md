# Review B (skeptical / adversarial): `aa_004f4e50` Object_GetLinkedActorLevel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f4e50_Object_GetLinkedActorLevel_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Has real switch jumptable | WARNING is decompiler noise on vcall | **Survives** as two ifs + return 0 |
| 2 | Handles type 0xe vehicle directly | Only 0x12/0x14 on **linked** object | **Survives** |
| 3 | Returns float XP | EAX from vcall+0x27c (level int pattern) | **Falsified** float |
| 4 | Always non-zero | Default 0 | **Falsified** always-nonzero |
| 5 | Reads this+0xb0 without VB | Uses vbtable adjust | **Falsified** flat offset |

---

## 2. Live ≡ raw

CF sealed. Role sealed via OnDeath level arg slot.

---

## 3. Surviving contract

```
// ECX=host* → EAX = level of linked 0x12/0x14 actor, else 0
```

**Verdict:** **accept-with-gaps**.
