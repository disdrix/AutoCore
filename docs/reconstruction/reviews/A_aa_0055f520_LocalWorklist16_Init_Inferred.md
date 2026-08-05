# Review A (reconstruction fidelity): `aa_0055f520` LocalWorklist16_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f520` |
| **VA** | `0x0055f520`–`0x0055f588` |
| **Body** | **105 bytes** (`0x69`) |
| **Canonical name** | `LocalWorklist16_Init_Inferred` |
| **Ghidra name** | `FUN_0055f520` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-R) |
| **Counterpart** | `reviews/B_aa_0055f520_LocalWorklist16_Init_Inferred.md` |
| **System** | allocator / local worklist init (stride 0x10) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Initialize a **local worklist / stack alloc descriptor** (`ECX`) for **16-byte elements**:

1. Compute size: machine `align16(count*16)`; decompiler bare `count*16` (equivalent for normal counts).
2. Zero `[0]`/`[1]`; seed `[2]=0x80000000`.
3. If arena remaining `<` size: vcall `vtbl+0x24(size)`; else bump `arena[2]+=size`, `arena[3]-=size`.
4. Stamp `[0]=[3]=slab`, `[4]=count`, `[2]=count|0x80000000`; return desc.

Prep twin of `LocalWorklist16_Release_Inferred`; used by `Phys_CommitPairListStorage` (W27-M).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.md` (+ 2026-07-29 W28-R append) |
| Annotated | `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist16_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f520.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055f520_FUN_0055f520.md` |
| Named record | `docs/reconstruction/functions/aa_0055f520_LocalWorklist16_Init_Inferred.md` |
| Live | decompile ≡ raw CF; prologue `53 8B 5C 24 08...` + epilogue `8B C6 5E 5B C2 04 00` |
| Caller dual | W27-M `Phys_CommitPairListStorage` (init→iterators→release) |

---

## 3. Signature (sealed)

```c
// thiscall; ECX = desc; stack count; ret 4; returns desc
int * LocalWorklist16_Init_Inferred(int *desc /*ECX*/, unsigned count);
```

| Formal | Source | Conf |
|---|---|---|
| desc | ECX (`MOV ESI,ECX`) | **High** |
| count | `[esp+8]` after push EBX (`MOV EBX,[esp+8]`) | **High** |
| return | EAX = ESI (desc) | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
size = align16(count*16)
desc[0]=0; desc[1]=0; desc[2]=0x80000000
if arena[3] < size:
  slab = arena->vtbl[0x24](size)
else:
  slab = arena[2]; arena[2]+=size; arena[3]-=size
desc[0]=desc[3]=slab; desc[4]=count; desc[2]=count|0x80000000
return desc
```

| Stage | Match | Conf |
|---|---|---|
| Size / arena branch | **Yes** | **High** |
| High-bit stamp | **Yes** | **High** |
| thiscall + ret 4 | **Yes** | **High** |
| Align16 (machine) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry `0x0055f520`: `53 8B 5C 24 08 8B C3 C1 E0 04 83 C0 0F 56 8B F1 24 F0`.
- Global load `8B 0D 60 50 B0 00` → `DAT_00b05060`.
- Vcall path: `FF 52 24` (`vtbl+0x24`).
- Exit: `8B C6 5E 5B C2 04 00` then `CC` pad.
- Body **105 B**.

---

## 6. Gaps

- Product English for `DAT_00b05060` allocator.
- Product type name of stack descriptor.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, stride-16 init role vs pair-list callers sealed. Machine align16 folded into clean. Naming **INFERRED**. → **accept**.
