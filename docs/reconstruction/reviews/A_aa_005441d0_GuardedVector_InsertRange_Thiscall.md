# Review A (reconstruction fidelity): `aa_005441d0` GuardedVector_InsertRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_005441d0` |
| **VA** | `0x005441d0`–`0x00544587` exclusive (**951 B**) |
| **Canonical name** | `GuardedVector_InsertRange_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_005441d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-I) |
| **Counterpart** | `reviews/B_aa_005441d0_GuardedVector_InsertRange_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (entry/exit + call site) + `analyze_function_complete`; sole caller `FUN_00545190`; callees W31-I push pair + ring assign |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert range `[first, last)` of dword elements into a GuardedVector at absolute `insert_at` using shorter-side room (thiscall push_front / push_back) then ring assign.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.md` (+ 2026-07-29 W32-I append) |
| Annotated | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005441d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005441d0_FUN_005441d0.md` |
| Named record | `docs/reconstruction/functions/aa_005441d0_GuardedVector_InsertRange_Thiscall.md` |
| Live | decompile ≡ raw CF; `RET 0x1C`; `MOV ESI,ECX`; 1 caller / 4 callees |

---

## 3. Signature (sealed)

```c
// ECX=dest container; 7 stack formals; RET 0x1C
void GuardedVector_InsertRange_Thiscall(GuardedVectorHeader* dest /*ECX*/,
                                        /* insert_at + first/last pair + residual */);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **ECX** (`MOV ESI,ECX`) | **High** |
| cleanup | `RET 0x1C` at epilogue | **High** |
| insert_at / range | stack formals used as abs indices | **High** |
| 7th stack formal | copy-ctor pushes extra src | **Medium** |

---

## 4. Control flow (clean ≡ raw)

```
prefix = insert_at - begin
suffix = size - prefix
n      = last - first

if prefix < suffix:          // front-biased
  if prefix < n:  push_front source window + dest prefix; assign; return
  else:           push_front n from dest; shuffle; assign source
else:                        // back-biased
  if suffix < n:  push_back source rem + dest suffix; assign; return
  else:           push_back n from dest; backward shuffle; assign source
```

| Stage | Match | Conf |
|---|---|---|
| Shorter-side 4-arm tree | **Yes** (decompile ≡ raw) | **High** |
| PushFront_Thiscall `0043e3d0` | **Yes** | **High** |
| PushBack_Thiscall `0043d670` | **Yes** | **High** |
| Forward assign `0043ec50` | **Yes** | **High** |
| Backward assign `0043ebb0` | **Yes** | **High** |
| Layout +4/+8/+c/+10 | **Yes** | **High** |
| Sole caller full-range @0 | **Yes** (`FUN_00545190`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: `55 8B EC 6A FF 68 70 41 9A 00 … 83 EC 20 8B 55 0C 53 56 8B F1` — SEH + **thiscall** (`MOV ESI,ECX`).  
Exit: `83 C4 40 5F 5E 64 89 0D … 5B 8B E5 5D C2 1C 00 CC` — **`RET 0x1C`**.  
Caller @ `005451d0`: zero dest `+4..+10`, push end/begin iterators + insert 0 + dest, `MOV ECX,ESI`, `CALL`.

---

## 6. Gaps

- Product/PDB class English.
- Precise naming of stack formal #0 vs residual 7th push.
- Nested product names for `0043ec50` / `0043ebb0`.
- Runtime / bit-exact.

---

## 7. Verdict

CF/ABI/layout/callee polarity sealed against raw + bytes + sole caller. Residuals are product English and exact 7-stack map → **accept-with-gaps**.
