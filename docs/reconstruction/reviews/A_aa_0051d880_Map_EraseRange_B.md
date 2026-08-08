# Review A (reconstruction fidelity): `aa_0051d880` Map_EraseRange_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d880` |
| **VA** | `0x0051d880`–`0x0051d933` (**180 B**) |
| **Canonical name** | `Map_EraseRange_B` |
| **Ghidra name** | `FUN_0051d880` |
| **Review date** | `2026-08-04` (WQ9D-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051d880_Map_EraseRange_B.md` |
| **System** | STL / map-set (WQ-009 skill residual helper) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` (full body + pad) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Twin** of `Map_EraseRange` (`0x0051c7c0`): MSVC map/set **range erase**, `isnil@+0x29`, partial path via `Map_EraseNode`.

**Discriminator:** full-clear free-subtree **`FUN_0051be90`** (not `FUN_0051bbc0`). Separate map instantiation (value size / dtor) despite identical node header isnil offset.

Only static caller recovered: map host complete dtor `FUN_0051e180` (full erase then delete head).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051d880` (2026-08-04) |
| Bytes | 180 B; `ret 0x0c`; isnil `+0x29` |
| Free subtree | live `FUN_0051be90` |
| Twin | `Map_EraseRange` / `0x0051c7c0` |
| Caller | `FUN_0051e180` only |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 180 B; `ret 0x0c` | **Confirmed** | bytes |
| Same CF as Map_EraseRange | **Confirmed** | live ≡ twin aside from free VA |
| Free `FUN_0051be90` | **Confirmed** | rel call |
| Partial `Map_EraseNode` | **Confirmed** | call + `mov ecx,edi` |
| isnil@+0x29 | **Confirmed** | immediates |
| Name `Map_EraseRange_B` | **High** | structural twin discriminator |
| K/V / product English | Open | |
| Runtime | Open | |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Full clear + free 0051be90 + reset | **Yes** |
| Partial successor + Map_EraseNode | **Yes** |
| `*out` + ret 12 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Twin of sealed Map_EraseRange | **Yes** |
| Distinct free-subtree | **Yes** |
| Chain-of-caller product name | **No** (dtor-only surface) |

**Decision:** promote **`Map_EraseRange_B`** — keep separate from `Map_EraseRange`.

---

## 6. Gaps

1. Why MSVC emitted a second instantiation (value type / size).
2. Free-subtree `FUN_0051be90` dual (not OWN).
3. Map host class English for `FUN_0051e180`.
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
