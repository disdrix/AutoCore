# Review A (reconstruction fidelity): `aa_0043c9b0` GuardedVector_GrowBlockMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c9b0` |
| **VA** | `0x0043c9b0`–`0x0043cafd` (**334 B**) |
| **Canonical name** | `GuardedVector_GrowBlockMap` (**Inferred**) |
| **Ghidra name** | `FUN_0043c9b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-B) |
| **Counterpart** | `reviews/B_aa_0043c9b0_GuardedVector_GrowBlockMap.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 334 B) + `analyze_function_complete`; callers `0043c830`/`0043ce10`; overflow `00436860` → `"deque<T> too long"` |
| **Verdict** | **accept** |

---

## 1. Purpose

Grow the deque **block-pointer map** so push_front / push_back can place one more element. Geometric map growth, rebalance existing pointers, zero free slots, install new map.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.md` (+ 2026-07-29 W28-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043c9b0_FUN_0043c9b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c9b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c9b0_FUN_0043c9b0.md` |
| Named record | `docs/reconstruction/functions/aa_0043c9b0_GuardedVector_GrowBlockMap.md` |
| Live | decompile ≡ raw CF; full body hex; EBX entry; RET 0x4; post-delete commit sealed by bytes |

---

## 3. Signature (sealed)

```c
// EBX=container; stdcall 1 arg; RET 0x4
void GuardedVector_GrowBlockMap(uint32_t min_grow);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EBX** (`MOV EAX,[EBX+8]`) | **High** |
| min_grow | Stack[+4] → EDI | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
cap = [EBX+8]
if 0x0FFFFFFF-cap < min_grow → FUN_00436860 ("deque<T> too long")
geo = max(cap/2, 8); if min_grow < geo && no overflow → min_grow = geo
begin_blk = [EBX+0xc] >> 2
neu = operator_new((cap+min_grow)*4)
memmove rebalance map (two arms: min_grow < begin_blk vs else)
zero new/unused slots
if old slots: operator_delete(old)   // falls through — not noreturn
[EBX+8] += min_grow; [EBX+4] = neu; RET 0x4
```

| Stage | Match | Conf |
|---|---|---|
| EBX ABI + RET 0x4 | **Yes** | **High** |
| Geometric growth + floor 8 | **Yes** | **High** |
| Overflow throw string | **Yes** | **High** |
| Both rebalance arms | **Yes** | **High** |
| Post-delete commit | **Yes** (bytes correct decompile) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
8B 43 08          ; MOV EAX, [EBX+8]
83 EC 0C          ; SUB ESP, 0xC
B9 FF FF FF 0F    ; MOV ECX, 0x0FFFFFFF
…
```

Epilogue @ `0x0043caf0` region:

```
01 7B 08          ; ADD [EBX+8], EDI
89 4B 04          ; MOV [EBX+4], ECX
5F 83 C4 0C C2 04 00  ; POP EDI; ADD ESP,0xC; RET 0x4
```

Body length **334 B**. Full hex captured in live pass (W28-B).

---

## 6. Gaps

- Product/PDB English (`GuardedVector_*` family structural; retail message says deque).
- Runtime / bit-exact golden for both rebalance arms under live allocators.

Body CF residual: **none**.

---

## 7. Verdict

ABI, growth policy, overflow, map rebalance, zeroing, and commit sealed from live decompile + full-body `read_memory` + exclusive push callers → **accept**.
