# Dual A/B report — W24-E OWN `aa_005d4830` + `aa_00406840`

**Date:** 2026-07-29
**Agent:** OWN-ONLY dual W24-E
**Scope:** VAs `0x005d4830`, `0x00406840` only. Dual A/B + artifacts.
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d4830` Object_EntityBase_Ctor | **accept-with-gaps** — ABI/CF/subobject offsets/flags/callers sealed; product English + nested sub-ctor duals open |
| `aa_00406840` LogicUiEventQueue_Resize | **accept** — resize CF + EAX/newCount + RET 0x138 + stride 0x138 + callers sealed |

---

## VA `0x005d4830` — sealed facts

1. **Body:** `0x005d4830`–`0x005d48e4` (181 B; `RET 0x4`).
2. **ABI:** **ECX**=this*; stack `mostDerivedFlag`; **EAX**=this.
3. **Semantics:** Entity **base** ctor under sealed `Object_EntityMidBase_Ctor`.
4. **mostDerived:** vb cookies `DAT_009dd760` @ `+4`, `DAT_009dac4c` @ `+0x44`; `Object_SharedBase_Ctor` at **`this+0xe0`**.
5. **Always:** `FUN_0053cdc0(this, 0)`; `FUN_00581330(this+0x40, 0)`; zero `+0xbc`/`+0xc0`; OR flags **0x40|0x20** at `vb+0x180`.
6. **Callers (2):** `Object_EntityMidBase_Ctor` @ `0x005c82f4`; `FUN_005dbfa0` @ `0x005dbff4`.
7. **Name:** `Object_EntityBase_Ctor` (Ghidra `FUN_005d4830`; **Inferred**).
8. **Decompile ≡ bytes** for CF; decomp this-adjust for `00581330` corrected from bytes.

### Gaps

- Product C++ class English (no RTTI this pass).
- Nested `FUN_0053cdc0` / `FUN_00581330` dual seals.
- Field dictionary English for `+0xbc`/`+0xc0`.
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d4830_Object_EntityBase_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d4830_Object_EntityBase_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d4830_FUN_005d4830.md` |
| Annotated | `docs/reconstruction/raw/aa_005d4830_FUN_005d4830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EntityBase_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d4830.cpp` |
| Function | `docs/reconstruction/functions/aa_005d4830_FUN_005d4830.md` |
| Function named | `docs/reconstruction/functions/aa_005d4830_Object_EntityBase_Ctor.md` |
| Scratch | `docs/reconstruction/tmp/a_005d4830.md` |

---

## VA `0x00406840` — sealed facts

1. **Body:** `0x00406840`–`0x004068e7` (168 B; `RET 0x138` ×2).
2. **ABI:** **ECX**=queue*; **EAX**=newCount; stack **0x138-byte value by-value**; void.
3. **Semantics:** MSVC-style **`vector::resize(n, value)`** for Logic-UI events (stride **0x138**).
4. **Shrink:** `FUN_00407640` erase `[begin+n*0x138, end)` when `n < size`.
5. **Grow:** `LogicUiEventQueue_InsertN(queue, end, n-size, &value)` when `n > size`.
6. **Nop:** `n == size`.
7. **Callers (2):** both clear — `FUN_00801c50` @ `0x00801e8b` (`xor eax,eax`); `FUN_00946c00` @ `0x009470a0` (`xor eax,eax`).
8. **Name:** `LogicUiEventQueue_Resize` (Ghidra `FUN_00406840`; **Inferred**).
9. **Family:** pairs with sealed `LogicUiEventQueue_InsertN` / `InsertOne_GrowPath`.
10. **Decompile ≡ bytes** for CF; InsertN thiscall ECX restored.

### Gaps

- Full 0x138 event record layout (family residual).
- `FUN_00407640` dual residual (role sealed).
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406840_LogicUiEventQueue_Resize.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00406840_LogicUiEventQueue_Resize.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00406840_FUN_00406840.md` |
| Annotated | `docs/reconstruction/raw/aa_00406840_FUN_00406840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_Resize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406840.cpp` |
| Function | `docs/reconstruction/functions/aa_00406840_FUN_00406840.md` |
| Function named | `docs/reconstruction/functions/aa_00406840_LogicUiEventQueue_Resize.md` |
| Scratch | `docs/reconstruction/tmp/a_00406840.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d4830` | Entity base under MidBase — preserve construct order (SharedBase@+0xe0 when mostDerived; 0053cdc0@+0; 00581330@+0x40); re-apply flags 0x40\|0x20 at vb+0x180. |
| `00406840` | Logic-UI queue resize — preserve stride 0x138, EAX=newCount, by-value fill POD, shrink-via-erase / grow-via-InsertN; clear uses n=0. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).
- Dual A (fidelity) + B (adversarial) both filed per VA.
- This report: `docs/agents/task-dual-ab-005d4830-00406840-w24e-report.md`
