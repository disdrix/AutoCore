# Review A (reconstruction fidelity): `aa_0043ea60` GuardedVector_GrowBlockMap_Stride2

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ea60` |
| **VA** | `0x0043ea60`–`0x0043ebac` (**333 B**) |
| **Canonical name** | `GuardedVector_GrowBlockMap_Stride2` (**Inferred**) |
| **Ghidra name** | `FUN_0043ea60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-A) |
| **Counterpart** | `reviews/B_aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` |
| **System** | STL / guarded ring-deque container (stride-2 pages) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 333 B) + callers/callees; compare `0x0043c9b0` / `0x0043d990` |
| **Verdict** | **accept** |

---

## 1. Purpose

Grow the deque **block-pointer map** for a ring whose page index is **`begin >> 1`** (2 elements per map page). Geometric growth, rebalance, zero free slots, install new map. **EBX** register this.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ea60_FUN_0043ea60.md` (+ 2026-07-29 W30-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043ea60_FUN_0043ea60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap_Stride2.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ea60.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ea60_FUN_0043ea60.md` |
| Named record | `docs/reconstruction/functions/aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` |
| Live | decompile ≡ raw CF; full body hex; EBX entry; `D1 ED`; RET 0x4; commit sealed |

**This pass:**

- Ghidra `decompile_function` @ `0x0043ea60`
- Ghidra `read_memory` full body through `C2 04 00`
- Ghidra `get_function_callers` / `get_function_callees`
- Context decompile of callers `FUN_0043e970`, `FUN_0043e9e0` (grow gate `&1` / `>>1`; not owned)
- **Not performed:** Launcher, runtime golden, bit-exact, `disassemble_bytes`

---

## 3. Signature (sealed)

```c
// EBX=container; stdcall 1 arg; RET 0x4
void GuardedVector_GrowBlockMap_Stride2(uint32_t min_grow);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EBX** (`MOV EAX,[EBX+8]` entry) | **High** |
| min_grow | Stack formal → EDI | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
cap = [EBX+8]
if 0x0FFFFFFF-cap < min_grow → FUN_00436860
geo = max(cap/2, 8); if min_grow < geo && no overflow → min_grow = geo
begin_blk = [EBX+0xc] >> 1          // STRIDE-2 (vs >>2 family)
neu = operator_new((cap+min_grow)*4)
memmove rebalance + zero
if old: operator_delete(old)        // falls through
[EBX+8] += min_grow; [EBX+4] = neu; RET 0x4
```

| Stage | Match | Conf |
|---|---|---|
| EBX ABI + RET 0x4 | **Yes** | **High** |
| Geometric growth + floor 8 | **Yes** | **High** |
| Overflow throw | **Yes** | **High** |
| `begin >> 1` | **Yes** (`D1 ED`) | **High** |
| Both rebalance arms | **Yes** | **High** |
| Post-delete commit | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
8B 43 08          ; MOV EAX, [EBX+8]   ; EBX already = this
83 EC 0C          ; SUB ESP, 0xC
B9 FF FF FF 0F    ; MOV ECX, 0x0FFFFFFF
…
D1 ED             ; SHR EBP, 1         ; begin >> 1
```

Epilogue:

```
8B 4C 24 04       ; MOV ECX, [ESP+4]   ; neu
01 7B 08          ; ADD [EBX+8], EDI
89 4B 04          ; MOV [EBX+4], ECX
5F                ; POP EDI
83 C4 0C          ; ADD ESP, 0xC
C2 04 00          ; RET 0x4
```

Body length **333 B**. Full hex in raw W30-A append.

---

## 6. Callers

| Caller | Role |
|---|---|
| `FUN_0043e970` | push-style; gate `(begin+size)&1==0` && `cap <= (size+2)>>1`; `FUN_0043ea60(1)` |
| `FUN_0043e9e0` | sibling push path; same grow gate |

---

## 7. Gaps

- Product/PDB English; element POD width (parents allocate `0x10` pages with `>>1` addressing → likely 2×8-byte).
- Runtime / bit-exact golden.
- Parent push units not dualed here.

Body CF residual: **none**.

---

## 8. Verdict

ABI, stride-2 head extract, growth policy, rebalance, and commit sealed → **accept**.
