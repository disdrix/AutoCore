# Review B (skeptical / adversarial): `aa_0092d730` Client_CycleWorldSelectIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092d730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0092d730_Client_CycleWorldSelectIndex_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Picks nearest object by distance | No distance math; pure index walk | **Falsified** |
| 2 | Always lands on a new object | Full-list local-only → early return without rebind | **Falsified** as always-change |
| 3 | `+0xe08` is object* raw | Layout `*(vtbl_adj)+4+obj` embed, not plain object* | **Sealed** as embedded ptr |
| 4 | Index is int32 | `byte` at `+0x4f8` only | **Falsified** as dword index |
| 5 | ECX thiscall | EAX client in prologue | **Falsified** |
| 6 | Only PollBoundActions | 4 distinct callers | **Falsified** |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX client; `+0x4f8` u8 index | **High** | Wrong select state |
| Skip `+0xe98` local | **High** | Self-target loop |
| Vector at world `+0xe75c` | **High** | Wrong list |
| `+0xe08` embedded bind | **High** | Crash on use |
| Product name of list | **Open** | Doc |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// custom: EAX = Client*
void Client_CycleWorldSelectIndex(Client* client /*EAX*/);
```

- Increments and wraps a u8 cursor over world object* vector.
- Skips local character; binds `client+0xe08` or clears it.

---

## 4. Verdict

**accept-with-gaps** — not a distance picker; index cycle sealed.
