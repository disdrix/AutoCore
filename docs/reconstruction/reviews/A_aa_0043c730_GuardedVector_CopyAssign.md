# Review A (reconstruction fidelity): `aa_0043c730` GuardedVector_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c730` |
| **VA** | `0x0043c730`–`0x0043c7d6` (**167 B**) |
| **Canonical name** | `GuardedVector_CopyAssign` (**Inferred**) |
| **Ghidra name** | `FUN_0043c730` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-G) |
| **Counterpart** | `reviews/B_aa_0043c730_GuardedVector_CopyAssign.md` |
| **System** | STL / guarded container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; sole caller + helper shape |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unlocked **copy-assign** of a ring/vector container:

1. If dest == source → return.
2. If source size (`+0x10`) == 0 → clear dest (`FUN_0040d9c0`, ESI=dest).
3. Else if source.size ≤ dest.size → prep (`FUN_0043ce90`) + fit (`FUN_0043c8c0`).
4. Else → prep + grow/copy (`FUN_0043cec0`).

Parent wrapper `GuardedVector_AssignTo` optionally takes CS then calls this with EAX=src, EDI=dst.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c730_FUN_0043c730.md` (+ 2026-07-29 W26-G append) |
| Annotated | `docs/reconstruction/raw/aa_0043c730_FUN_0043c730.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_CopyAssign.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c730.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c730_FUN_0043c730.md` |
| Named record | `docs/reconstruction/functions/aa_0043c730_GuardedVector_CopyAssign.md` |
| Live | decompile ≡ raw; `read_memory` 167 B; sole xref `FUN_0043c5f0` |
| Context | decompile helpers `0040d9c0` / `0043ce90` / `0043c8c0` / `0043cec0` (shape only; not owned) |

---

## 3. Signature (sealed)

```c
// Custom register ABI; no stack formals; plain RET after ADD ESP,8
void GuardedVector_CopyAssign(/*EAX*/ void* source, /*EDI*/ void* dest);
```

| Slot | Source | Conf |
|---|---|---|
| source | **EAX** (`MOV EBX,EAX` at entry) | **High** |
| dest | **EDI** (compared to EBX; sole caller loads dest into EDI) | **High** |
| cleanup | `ADD ESP,8; RET` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if EDI == EAX: return
if [EAX+0x10] == 0:
  ESI=EDI; FUN_0040d9c0(); return
if [EAX+0x10] <= [EDI+0x10]:
  FUN_0043ce90(); FUN_0043c8c0(...); return
FUN_0043ce90(); FUN_0043cec0(...);
```

| Stage | Match | Conf |
|---|---|---|
| Self-assign no-op | **Yes** | **High** |
| Empty → clear dest | **Yes** | **High** |
| size ≤ dest → fit | **Yes** | **High** |
| else grow | **Yes** | **High** |
| Offsets +0x0c / +0x10 | **Yes** | **High** |
| Nested free arithmetic | shape only | **Probable** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
83 EC 08 53 8B D8 3B FB 0F 84 8E 00 00 00 8B 53 10 85 D2 56 75 0F …
```

Body length **167 B** to last `C3` @ `0x0043c7d6`; pad `CC` after.

---

## 6. Gaps

- Product/PDB class name (`GuardedVector` structural from W25-R parent).
- Element type / exact free paths inside unowned fit/grow helpers.
- Runtime / bit-exact / differential.

---

## 7. Verdict

ABI, self/empty/fit/grow CF, and header offsets sealed from live decompile + bytes + sole caller. Nested helper free residual → **accept-with-gaps**.
