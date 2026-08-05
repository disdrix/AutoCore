# Review A (reconstruction fidelity): `aa_0043e080` GuardedVector_InsertN_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e080` |
| **VA** | `0x0043e080`–`0x0043e37d` (**766 B**) |
| **Canonical name** | `GuardedVector_InsertN_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043e080` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-F) |
| **Counterpart** | `reviews/B_aa_0043e080_GuardedVector_InsertN_Thiscall.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 766 B) + callers/callees; sole caller `0043d940`; callees d670/e3d0/e910/ebb0/ec50 + SEH |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `N` copies of `*fill` at absolute `insert_at` under **thiscall** (ECX=container) using shorter-side policy: front via `GuardedVector_PushFront_Thiscall`, back via `GuardedVector_PushBack_Thiscall`, then range fill/move helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.md` (+ 2026-07-29 W32-F append) |
| Annotated | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e080.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e080_FUN_0043e080.md` |
| Named record | `docs/reconstruction/functions/aa_0043e080_GuardedVector_InsertN_Thiscall.md` |
| Live | decompile ≡ raw CF tree; full body hex; sole xref from resize grow |
| Context | twin W29-A InsertN; push pair sealed W31-I |

---

## 3. Signature (sealed)

```c
// ECX=container; stack (seed, insert_at, N, fill*); RET 0x10
void GuardedVector_InsertN_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                    GuardedVectorHeader* seed,
                                    int32_t insert_at,
                                    uint32_t n,
                                    const uint32_t* fill);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX`) | **High** |
| seed | Stack[+4] (`[ebp+8]` → local_24) | **High** |
| insert_at | Stack[+8] (`MOV EDI,[ebp+0xc]`) | **High** |
| N | Stack[+0xc] (`MOV EBX,[ebp+0x10]`) | **High** |
| fill* | Stack[+0x10] (`[ebp+0x14]`) | **High** |
| cleanup | `RET 0x10` (multiple sites) | **High** |

Sole-caller `FUN_0043d940` bytes: push fill*, N, begin+size, container; ECX still container.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
prefix = insert_at - begin
suffix = size - prefix
if prefix < suffix:
  if prefix < N:  push_front excess+copies; e910; ret
  else:           push_front N; ec50; e910
else:
  if suffix < N:  push_back excess+copies; e910; ret
  else:           push_back N; ebb0; e910
```

| Stage | Match | Conf |
|---|---|---|
| 4-way shorter-side tree | **Yes** | **High** |
| ECX container / RET 0x10 | **Yes** | **High** |
| Thiscall push pair (not EAX) | **Yes** | **High** |
| Sole-caller end-insert arm | **Yes** (suffix=0 path) | **High** |
| Nested e910/ebb0/ec50 free | shape only | **Medium** |
| SEH cleanup islands | present in bytes | **High** (handler path) |

---

## 5. Machine bytes (`read_memory`)

Entry: `PUSH EBP; MOV EBP,ESP; … MOV ESI,ECX` — true thiscall.  
Epilogue sites: `C2 10 00`.  
Body length **766 B** (`0x0043e080`–`0x0043e37d`).  
Full hex sealed in raw W32-F append.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural).  
- Nested `FUN_0043e910` / `FUN_0043ebb0` / `FUN_0043ec50` free (unowned).  
- Front-biased arms not call-site exercised.  
- Runtime / bit-exact.

---

## 7. Verdict

Fidelity seals ABI, 4-arm CF, layout, and thiscall push polarity. Nested range helpers residual → **accept-with-gaps**.
