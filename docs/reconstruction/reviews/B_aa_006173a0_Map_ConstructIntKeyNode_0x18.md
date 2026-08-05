# Review B (skeptical / adversarial): `aa_006173a0` Map_ConstructIntKeyNode_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_006173a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full map insert / rebalance | Body is only new+stores; no size++, no rotations | **Falsified** merge with `005d20b0` |
| 2 | Node size other than 0x18 | `PUSH 0x18` + stores up through `+0x15` | **Falsified** |
| 3 | isnil left uninitialized | `MOV byte [EAX+0x15], 0` | **Falsified** |
| 4 | `__cdecl` (caller cleans) | `RET 0x14` cleans 20 B | **Falsified** cdecl |
| 5 | Truly `void` return | EAX holds node through RET; insert cores use return | **Falsified** void; **survives** as pointer return |
| 6 | Color always black | Callers pass color (insert uses 0 red); field is param | **Falsified** constant-black |
| 7 | Unique to one map instance | 14 xrefs across insert helpers | **Falsified** exclusive ownership |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body and `read_memory` hex. Callee list = `operator_new` only. Caller count 14 matches xrefs.

---

## 3. Surviving contract

```
// RET 0x14
// node = operator_new(0x18)
// if node: left, parent, right, key, mapped, color, isnil=0
// return node* (EAX)
```

**Gaps kept:** product C++ name; proof every caller is int/int (layout yes; typedef open).

**Verdict:** **accept-with-gaps**.
