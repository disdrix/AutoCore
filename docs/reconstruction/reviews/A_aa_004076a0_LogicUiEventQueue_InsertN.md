# Review A (reconstruction fidelity): `aa_004076a0` LogicUiEventQueue_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_004076a0` |
| **VA** | `0x004076a0`–`0x00407991` |
| **Canonical name** | `LogicUiEventQueue_InsertN` |
| **Ghidra name** | `FUN_004076a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-B) |
| **Counterpart** | `reviews/B_aa_004076a0_LogicUiEventQueue_InsertN.md` |
| **System** | client-logic-ui / event queue |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers `FUN_004068f0` / `FUN_00406840` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **vector insert-N** for Logic-UI event elements (stride **0x138**):

1. POD-construct `valueSrc` into stack buffer `local_164[312]` via `FUN_00408880`.
2. If `count == 0` → return.
3. Size/capacity via `(end−begin)/0x138` and `(cap−begin)/0x138`.
4. Max-size guard vs `0x00D20D20` → `FUN_00418130`.
5. If `capacity < size + count`: 1.5× grow (or exact need), `operator_new`, move/fill/move, `operator_delete`, rebind begin/end/cap.
6. Else in-place near-end or mid-range shift + fill.

Callers: `LogicUiEventQueue_InsertOne_GrowPath` (`count=1`) and `FUN_00406840` (append path).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004076a0_FUN_004076a0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004076a0_FUN_004076a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_InsertN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004076a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004076a0_FUN_004076a0.md` |
| Parent dual | `LogicUiEventQueue_InsertOne_GrowPath` (`0x004068f0`, W22-I) |
| Twin pattern | `UiToastVector_InsertN` (`0x00403980`, stride 0x98) |
| Live | decompile ≡ raw; `read_memory` 754 B body; epilogue `C2 0C 00` |

---

## 3. Signature (sealed)

```c
// stack formals ×3; ECX = queue*; return void; RET 0xC
void LogicUiEventQueue_InsertN(void* q, void* at, uint32_t count, const void* valueSrc);
```

| Formal | Source | Conf |
|---|---|---|
| queue | ECX → ESI; fields +4/+8/+0xC | **High** |
| insertAt | Stack[0x4] | **High** |
| count | Stack[0x8] | **High** |
| valueSrc | Stack[0xC] → construct | **High** |
| cleanup | `RET 0xC` (all paths) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
FUN_00408880(valueBuf, valueSrc)   // 0x138 POD
cap = begin ? (cap_end-begin)/0x138 : 0
if count==0: return
if max - size < count: throw FUN_00418130
if cap < size+count:
  grow 1.5x or exact; new/move/fill/delete/rebind
elif (end-at)/0x138 < count:
  near-end in-place
else:
  mid in-place
```

| Stage | Match | Conf |
|---|---|---|
| Stack value construct 0x138 | **Yes** | **High** |
| count==0 early return | **Yes** | **High** |
| Stride 0x138 magic + lea | **Yes** | **High** |
| Max `0x00D20D20` / throw | **Yes** | **High** |
| 1.5× growth policy | **Yes** | **High** |
| Realloc rebind begin/end/cap | **Yes** | **High** |
| In-place near-end + mid | **Yes** | **High** |
| Callers InsertOne + 00406840 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 754 B @ `0x004076a0`; SEH prologue `55 8B EC 6A FF 68 00 E3 9B 00 …`; magic `B8 D3 20 0D D2`; max imm `BA 20 0D D2 00`; epilogues `C2 0C 00`.

---

## 6. Gaps

- Product English for owning queue type (session field vs standalone).
- Full 0x138 event record field map (not this unit).
- Nested helper duals (`00409a70` / `00406970` / `00409a90` / `00409ac0` / `00408880`) residual.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/stride/growth sealed; layout English + nested helpers residual.
