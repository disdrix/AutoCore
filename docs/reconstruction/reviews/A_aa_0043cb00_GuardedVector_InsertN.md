# Review A (reconstruction fidelity): `aa_0043cb00` GuardedVector_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cb00` |
| **VA** | `0x0043cb00`–`0x0043cdfe` (**769 B**) |
| **Canonical name** | `GuardedVector_InsertN` (**Inferred**) |
| **Ghidra name** | `FUN_0043cb00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-A) |
| **Counterpart** | `reviews/B_aa_0043cb00_GuardedVector_InsertN.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 769 B) + callers/callees; sole caller `0043c7e0`; callees ce10/c830/cef0/d300/d390 + SEH cleanup |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `N` copies of `*fill` at absolute index `insert_at` in a ring/deque header using shorter-side policy (front via push_front, back via push_back), then assign the insert window with sealed `GuardedVector_RingFillRange`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.md` (+ 2026-07-29 W29-A append) |
| Annotated | `docs/reconstruction/raw/aa_0043cb00_FUN_0043cb00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cb00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043cb00_FUN_0043cb00.md` |
| Named record | `docs/reconstruction/functions/aa_0043cb00_GuardedVector_InsertN.md` |
| Live | decompile ≡ raw CF tree; full body hex; sole xref from Resize grow |
| Context | parent `GuardedVector_Resize` grow; fill leaf sealed W28-D RingFillRange |

---

## 3. Signature (sealed)

```c
// ECX=N; stdcall-ish 4 stack args; RET 0x10
void GuardedVector_InsertN(uint32_t n /*ECX*/,
                           GuardedVectorHeader* container,
                           GuardedVectorHeader* seed,
                           int32_t insert_at,
                           uint32_t* fill);
```

| Slot | Source | Conf |
|---|---|---|
| N | **ECX** (`MOV EDI, ECX`) | **High** |
| container | Stack[+4] (`MOV ESI, [ebp+8]`) | **High** |
| insert_at | Stack[+0xc] (`MOV EBX, [ebp+10]`) | **High** |
| fill* | Stack[+0x10] | **High** |
| cleanup | `RET 0x10` @ `0x0043cdfe` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
prefix = insert_at - begin
suffix = size - prefix
if prefix < suffix:
  if prefix < N:  ce10 excess+copies; RingFill; ret
  else:           ce10 N; d390; RingFill
else:
  if suffix < N:  c830 excess+copies; RingFill; ret
  else:           c830 N; d300; RingFill
```

| Stage | Match | Conf |
|---|---|---|
| 4-way shorter-side tree | **Yes** | **High** |
| ECX=N / RET 0x10 ABI | **Yes** | **High** |
| Sole-caller end-insert arm | **Yes** (suffix=0) | **High** |
| Nested construct free | shape only | **Medium** |
| SEH cleanup islands | present in bytes | **High** (handler path) |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
55 8B EC 6A FF 68 00 D6 9B 00 64 A1 00 00 00 00 …
83 EC 14 53 8B 5D 10 56 8B 75 08 … 8B F9   ; EBX=insert_at, ESI=container, EDI=ECX(N)
```

Epilogue @ `0x0043cdfe`: `C2 10 00`.  
Body length **769 B** (`0x0043cb00`–`0x0043cdfe`).  
RingFill sites: `0x0043cbdd`, `0x0043cd1c`, `0x0043cde6` → `0x0043cef0`.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural).
- Nested construct free packing inside unowned `FUN_0043ce10` / `FUN_0043c830` (W29-B).
- Exact dual-iterator packs into `FUN_0043d300` / `FUN_0043d390` on non-end arms.
- Front-biased arms not exercised by sole known caller.
- Runtime / bit-exact / differential.

---

## 7. Verdict

ABI (ECX=N / RET 0x10), shorter-side insert CF, family layout, and sole-caller end-insert path sealed from live decompile + full body bytes. Nested construct free residual → **accept-with-gaps**.
