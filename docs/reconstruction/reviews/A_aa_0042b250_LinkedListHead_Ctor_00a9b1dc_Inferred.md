# Review A (reconstruction fidelity): `aa_0042b250` LinkedListHead_Ctor_00a9b1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b250` |
| **VA** | `0x0042b250` |
| **Canonical name** | `LinkedListHead_Ctor_00a9b1dc_Inferred` (structural) |
| **Ghidra name** | `FUN_0042b250` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0042b250_LinkedListHead_Ctor_00a9b1dc_Inferred.md` |
| **System** | net / TNL unpack helpers (Damage, ByteBuffer) |
| **Live tools** | `batch_decompile` 0x0042b250; callers Damage/TNL unpack |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tiny constructor** for a 3-dword list/head object (`__fastcall` ECX = this):

| Off | Init |
|---|---|
| `+0x00` | vtbl **`PTR_LAB_00a9b1dc`** |
| `+0x04` | **0** (chain head / first node*) |
| `+0x08` | **0** |

No allocation, no free. Sibling **`FUN_0042b270`** reinstalls the same vtbl and **zeroes** every node in the `+4` chain (next at node`[2]`).

**Callers:** `EMSG_Sector_Damage_Unpack` (`0x00636f00`), `TNL_ByteBuffer_UnpackData` (`0x00637750`), `FUN_006374f0` / `00637990`, plus multiple `0059e*` / `005a*` unpack helpers. Used as base init for small net wrapper objects (parent duals often `operator_new(0x18)` then this ctor before richer fields).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_0042b250_*`, `reconstructed-exact/FUN_0042b250.cpp` |
| Function record | `functions/aa_0042b250_FUN_0042b250.md` |
| Clear twin | `0x0042b270` |
| Parent duals | `A_aa_00636f00_*`, `A_aa_00637750_*` |
| Live | 3 stores only; no ret-imm |

**Three-rep:** present. Clean ≡ raw ≡ live.

---

## 3. Signature

```c
// __fastcall  ECX = head*
void LinkedListHead_Ctor(ListHead *this);
// *this = &PTR_LAB_00a9b1dc; this->head = 0; this->pad = 0;
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Vtbl store `00a9b1dc` | **Confirmed** |
| Zeros +4 and +8 | **Confirmed** |
| No heap | **Confirmed** |
| Pairs with clear `0042b270` | **High** |
| Used under Damage/TNL unpack | **Confirmed** |
| Product class name | **Tentative** |
| Whether later overwritten with BitStream vtbl | **Open** (parents may re-stamp) |

---

## 5. Gaps

1. Full vtbl method set at `00a9b1dc`.
2. Exact product type of the 0x18 wrappers that embed this head.
3. Runtime open.

**Verdict:** **accept-with-gaps**
