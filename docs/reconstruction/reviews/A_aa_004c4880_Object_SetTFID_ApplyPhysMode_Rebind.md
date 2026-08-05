# Review A (reconstruction fidelity): `aa_004c4880` Object_SetTFID_ApplyPhysMode_Rebind

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4880` |
| **VA** | `0x004c4880`–`0x004c48f1` |
| **Canonical name** | `Object_SetTFID_ApplyPhysMode_Rebind` |
| **Ghidra name** | `FUN_004c4880` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-F) |
| **Counterpart** | `reviews/B_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` |
| **System** | object / TFID / phys rebind |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers/callees; sibling TFID units |
| **Verdict** | **accept** |

---

## 1. Purpose

Apply a **TFID_16** onto an object and refresh phys linkage:

1. Store 16 bytes at `this+0x108`.
2. If phys child `this+8` non-null, write mode **0xB** or **10** at `phys+0x28` from invalid-TFID predicate.
3. Call `FUN_00560e90` / `WorldObj_RebindActivate_Inferred` so the world manager rebinds the phys object.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.md` (+ 2026-07-29 W26-F append) |
| Annotated | `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetTFID_ApplyPhysMode_Rebind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4880.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4880_FUN_004c4880.md` |
| Named record | `docs/reconstruction/functions/aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` |
| Live | decompile ≡ raw; `read_memory` 114 B; epilogue `C2 04 00` |
| Sibling | `FUN_004c4440` TFID_16 / `FUN_004c4620` mode leaf |
| Callee dual | `A/B_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |

---

## 3. Signature (sealed)

```c
// thiscall; 1 stack formal; void; RET 4
void Object_SetTFID_ApplyPhysMode_Rebind(int this, uint32_t src_tfid[4]);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| src_tfid | Stack[0x4] after pushes | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
copy src[0..3] → this+0x108..+0x114
phys = *(this+8)
if phys == 0: return
if (tfid.lo & tfid.hi) == ~0 && (char)tfid.w2 == 0:
  *(phys+0x28) = 0xB
else:
  *(phys+0x28) = 10
FUN_00560e90(phys, 1)   // manager recovered in bytes
return
```

| Stage | Match | Conf |
|---|---|---|
| 16 B TFID store | **Yes** | **High** |
| Null phys early-out | **Yes** | **High** |
| Mode 0xB vs 10 predicate | **Yes** (≡ 004c4620) | **High** |
| Rebind call | **Yes** | **High** |
| thiscall RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (114 B):
```
8b44240456578b388d91080100008bf2893e8b7804897e048b7808897e088b400c89460c8b410885c074428b3223720483feff7506807a08007409c740280a000000eb07c740280b000000518bc4c600018b51048b41088b52048b8c0aa80000008b89a4e4000050e8a3c509005f5ec20400
```

Epilogue: `5F 5E C2 04 00`. Call at `0x004c48e8` → `0x00560e90`.

---

## 6. Gaps

- Product enum names for phys modes 10 / 0xB.
- Manager pointer product type (chain `+0xA8`/`+0xE4A4`).
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, TFID layout, mode predicate, and rebind linkage are sealed against live decompile, full-body bytes, and sibling evidence. Naming is evidence-backed inference (TFID_16 + sealed callee). → **accept**.
