# Review B (skeptical / independent): `aa_0051c880` Map_EraseNode_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c880` |
| **VA** | `0x0051c880` |
| **Canonical name** | `Map_EraseNode_Isnil1d_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051c880_Map_EraseNode_Isnil1d_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051c880` only | Scaffold; under-describes |
| Collapse into `Map_EraseNode` / `Map_EraseNode_B` | **Reject** — isnil@+0x1d / color@+0x1c; different successor/rotate VAs |
| Identity with `Map_EraseRange_Isnil1d_Inferred` | **Reject** — range wrapper vs single-node erase |
| Skill-cast / product host name | **Reject** — no skill string; map helper only |
| `Map_EraseNode_Isnil1d_Inferred` | **Accept** — structural STL + isnil discriminator |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function ends at `operator_delete` (decomp noreturn) | **Fails** — bytes show size-- / `*out` / `ret 8` fall-through |
| isnil is +0x29 like Map_EraseNode | **Fails** — entry `cmp [eax+0x1d],0`; color `+0x1c` |
| Dead / unused | **Fails** — sole caller Map_EraseRange_Isnil1d partial loop |
| thiscall wrong / more stack args | **Fails** — `ret 8` + ECX→EBP map this |
| Ghidra body end `0x0051cb06` authoritative | **Fails** — `ret` @ `0x0051cb33`; exclusive end `0x0051cb36` |

---

## 3. Agreement with Review A

- Single-node erase + throw string: **agree Confirmed**
- Post-delete size--/`*out`/`ret 8`: **agree Confirmed** (bytes)
- Name + isnil discriminator: **agree High**
- Gaps (product English, runtime): **agree open**

---

## 4. Residual risks

- Parent merge must **not** alias this VA to `Map_EraseNode` (`0x0051cb40`).
- Decompiler false-noreturn on `operator_delete` is a family-wide trap — always prefer epilogue bytes.
- Ghidra function end metadata may lag; seal from `read_memory` of `C2 08 00`.

**Verdict:** **accept-with-gaps**
