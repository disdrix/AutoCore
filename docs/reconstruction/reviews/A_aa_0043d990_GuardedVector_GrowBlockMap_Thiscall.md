# Review A (reconstruction fidelity): `aa_0043d990` GuardedVector_GrowBlockMap_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d990` |
| **VA** | `0x0043d990`–`0x0043dae3` (**340 B**) |
| **Canonical name** | `GuardedVector_GrowBlockMap_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043d990` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-A) |
| **Counterpart** | `reviews/B_aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 340 B) + callers/callees; twin compare `0x0043c9b0` |
| **Verdict** | **accept** |

---

## 1. Purpose

Grow the deque **block-pointer map** so push can place one more page. Geometric map growth, rebalance existing pointers, zero free slots, install new map. **ECX thiscall** entry; `begin_blk = begin >> 2`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d990_FUN_0043d990.md` (+ 2026-07-29 W30-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043d990_FUN_0043d990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowBlockMap_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d990.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d990_FUN_0043d990.md` |
| Named record | `docs/reconstruction/functions/aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` |
| Live | decompile ≡ raw CF; full body hex; ECX→EBX entry; RET 0x4; post-delete commit sealed by bytes |

**This pass:**

- Ghidra `decompile_function` @ `0x0043d990`
- Ghidra `read_memory` full body through `C2 04 00`
- Ghidra `get_function_callers` / `get_function_callees`
- Context decompile of callers `FUN_0043d670`, `FUN_0043e3d0` (grow gate only; not owned)
- **Not performed:** Launcher, runtime golden, bit-exact image diff, `disassemble_bytes`

---

## 3. Signature (sealed)

```c
// ECX=container; stdcall 1 arg; RET 0x4
void GuardedVector_GrowBlockMap_Thiscall(uint32_t min_grow /*stack*/,
                                         GuardedVectorHeader* self /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** → `MOV EBX,ECX` | **High** |
| min_grow | Stack formal → EDI | **High** |
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
| ECX ABI + RET 0x4 | **Yes** | **High** |
| Geometric growth + floor 8 | **Yes** | **High** |
| Overflow throw | **Yes** | **High** |
| Both rebalance arms | **Yes** | **High** |
| Post-delete commit | **Yes** (bytes correct decompile) | **High** |
| Twin of `0x0043c9b0` | **Yes** (ABI differs only) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
83 EC 0C          ; SUB ESP, 0xC
53                ; PUSH EBX
8B D9             ; MOV EBX, ECX   ; thiscall → EBX working this
8B 43 08          ; MOV EAX, [EBX+8]
B9 FF FF FF 0F    ; MOV ECX, 0x0FFFFFFF
…
C1 ED 02          ; SHR EBP, 2     ; begin >> 2
```

Epilogue:

```
01 7B 08          ; ADD [EBX+8], EDI
8B 4C 24 08       ; MOV ECX, [ESP+8]  ; neu
5F                ; POP EDI
89 4B 04          ; MOV [EBX+4], ECX
5B                ; POP EBX
83 C4 0C          ; ADD ESP, 0xC
C2 04 00          ; RET 0x4
```

Body length **340 B**. Full hex in raw W30-A append.

---

## 6. Callers

| Caller | Role |
|---|---|
| `FUN_0043d670` | push-style; grow when end aligns + map full; `FUN_0043d990(1)` |
| `FUN_0043e3d0` | front-style; same grow gate; `FUN_0043d990(1)` |

---

## 7. Gaps

- Product/PDB English (`GuardedVector_*` family structural; retail message says deque).
- Runtime / bit-exact golden for both rebalance arms under live allocators.
- Parent push units `0043d670` / `0043e3d0` not dualed here (unowned).

Body CF residual: **none**.

---

## 8. Verdict

ABI, growth policy, overflow, map rebalance, zeroing, and commit sealed from live decompile + full-body `read_memory` + exclusive push callers → **accept**.
