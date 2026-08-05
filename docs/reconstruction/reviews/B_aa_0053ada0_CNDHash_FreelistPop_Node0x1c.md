# Review B (skeptical / adversarial): `aa_0053ada0` CNDHash_FreelistPop_Node0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053ada0` |
| **VA** | `0x0053ada0` |
| **Canonical name** | `CNDHash_FreelistPop_Node0x1c` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path B |
| **Counterpart** | `reviews/A_aa_0053ada0_CNDHash_FreelistPop_Node0x1c.md` |
| **Live tools** | Independent `force_decompile` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Allocates one node via `operator_new(0x1c)` | **Falsified** — slab 24×0x1c freelist |
| 2 | 700 bytes = exactly 24 nodes | **Partial** — 24×0x1c=672; 700 is padded alloc |
| 3 | `piVar2[0xa8]=0` is count field | **Falsified** — last-next null at dword index 0xa8 |
| 4 | Returns node in EAX clearly | **Attack partial** — decompiler void; inserts treat result as node* |
| 5 | Same freelist as u64 inventory hash | **Falsified** — u64 uses `00419bd0` / 0x28 nodes |

---

## 2. Surviving contract

Slab freelist pop for **0x1c** nodes; empty → aligned slab of 24; vector of slabs may grow via `004073a0`.

**Verdict:** **accept-with-gaps.** Accept A.
