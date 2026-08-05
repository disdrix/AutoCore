# Review B (skeptical / adversarial): `aa_00413be0` List_IterateNext_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00413be0_List_IterateNext_u64.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `List_IterateNext` `0x004022a0` (byte-identical) | Sibling skim | **Falsified** — key width + node offsets differ |
| 2 | Key at `node+4` (32-bit layout) | Import IterateNext notes | **Falsified** — key at `+8/+0xc` |
| 3 | Next at `node+8` | 32-bit layout | **Falsified** — next at `+0x10` |
| 4 | Sets TraversalLock itself | Missing lock in caller | **Falsified** — requires `+0x28`; returns `0x80070005` if clear |
| 5 | Clears lock on each step | Unlock confusion | **Falsified** — only LeaveCS; flag stays 1 |
| 6 | Return 0 means done | Polarity flip | **Falsified** — 0 = have item; 1 = end |
| 7 | Always EnterCS (blocking) | Ignore TryEnter | **Falsified** — TryEnter; fail → `0x80070005` |
| 8 | Name is string-proven | Registry inflation | **Not sealed** — **Probable** `_u64` from layout; Ghidra `FUN_*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 64-bit out key | **High** | Truncated COID → miss resolve |
| next `+0x10` | **High** | Walk corruption |
| Return polarity 0/1 | **High** | Infinite loop / skip all |
| Not locked → E_ACCESSDENIED | **High** | Silent empty iteration if ignored |
| Universal "TFID" label | **Med** | Other u64 keys possible |
| Product name | **Med** | Doc |

---

## 3. Cross-check vs 32-bit sibling

| | `0x004022a0` IterateNext | `0x00413be0` this |
|---|---|---|
| Key | `*(node+4)` → 1 dword out | `*(node+8)`, `*(node+0xc)` → 2 dwords |
| Next | `*(node+8)` | `*(node+0x10)` |
| Head | `list+0x1c` | same |
| Lock gate | `+0x28` + TryEnter | same |
| Returns | 0 / 1 / `0x80070005` | same |

Insert twin `0x00573040` writes the **u64** layout — seals this iterator's node shape.

---

## 4. Surviving contract

```
// Must call List_TraversalLock first
r = List_IterateNext_u64(list, &cursor, &keyLoHi[2])
// r==0 → use keyLoHi; r==1 → stop; r==0x80070005 → lock/contention error
// Caller unlock: if list+0x28: clear; LeaveCS(list+4)
```

**Port tests:** do not use 32-bit next/key offsets; do not treat non-zero as always "done" without distinguishing `0x80070005` if error matters.

**Verdict:** **accept-with-gaps** — sibling-mix and polarity attacks **fail**.
