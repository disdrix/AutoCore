# Review A (reconstruction fidelity): `aa_0051b2a0` Object_LazyFillMatColorVecFromMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b2a0` |
| **VA** | `0x0051b2a0`–`0x0051b302` exclusive |
| **Canonical name** | `Object_LazyFillMatColorVecFromMesh_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (lazy mat-color bank fill) |
| **Counterpart** | `reviews/B_aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` |
| **System** | object / mesh material colors |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` `0x0051b2a0` + `read_memory` body + callers + callee `FUN_00519280` decompile (strings). No `disassemble_bytes`. No ledgers / Launcher.

---

## 1. Purpose

Shared virtual method: **lazily populate** a per-object material-color vector (element stride **0x10**) from the object’s mesh material list when the bank is empty. Forwards four stack dwords as color overrides into `FUN_00519280`, which queries `"MatDiffuse"`, `"MatAmbient"`, `"MatEmissive"`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b2a0_FUN_0051b2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b2a0_FUN_0051b2a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LazyFillMatColorVecFromMesh_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051b2a0_Object_LazyFillMatColorVecFromMesh_Inferred.md` |
| Live Ghidra | decompile + read_memory + assembly context |
| Callee | `FUN_00519280` @ `0x00519280` (Mat* strings) |
| Sibling caller | `FUN_004c5480` (dual-bank path) |

---

## 3. Signature

```c
void __thiscall Object_LazyFillMatColorVecFromMesh_Inferred(
    void *self, uint32_t c0, uint32_t c1, uint32_t c2, uint32_t c3);
// RET 0x10
```

| Item | Evidence |
|---|---|
| Body size | 98 B; range `0051b2a0`–`0051b302` |
| Empty test | `[ECX+0x148]==0` OR `(([ECX+0x14C]-[ECX+0x148])>>4)==0` |
| Probe | `CALL [vtbl+0x1CC]` |
| Fill | `FUN_00519280(probe+8, this+0x144, c0..c3)` |
| Epilogue | `RET 0x10` |

---

## 4. Control flow (sealed)

```
if vector@+0x148 non-empty: return
probe = this->vtbl+0x1CC()
if probe==0 or *(probe+8)==0: return
FUN_00519280(*(probe+8), this+0x144, c0,c1,c2,c3)
return
```

---

## 5. Machine bytes (`read_memory` @ `0x0051b2a0`)

```
51                   PUSH ECX
8B 81 48 01 00 00    MOV  EAX, [ECX+0x148]
85 C0 56             TEST EAX / PUSH ESI
8D B1 44 01 00 00    LEA  ESI, [ECX+0x144]
74 0E                JZ   empty
8B 56 08 2B D0       MOV  EDX,[ESI+8] / SUB EDX,EAX
C1 FA 04             SAR  EDX,4
89 54 24 04 75 3D    store count / JNZ already_filled
8B 01 FF 90 CC 01 00 00   vcall +0x1CC
… null checks …
E8 86 DF FF FF       CALL FUN_00519280
83 C4 18 5E 59 C2 10 00
```

---

## 6. Confirmations

| # | Claim | Status |
|---|---|---|
| 1 | thiscall + 4 stack args + RET 0x10 | **Confirmed** |
| 2 | Stride-16 empty vector guard | **Confirmed** |
| 3 | Bank host at this+0x144 | **Confirmed** (`LEA ESI`) |
| 4 | Mesh list via vtbl+0x1CC then +8 | **Confirmed** |
| 5 | Material-color fill via FUN_00519280 | **Confirmed** (callee Mat* strings) |
| 6 | Decompile CF ≡ image CF | **Confirmed** |

---

## 7. Residual gaps

- Product name for virtual slot / color bank type.
- Exact type of vtbl+0x1CC return (gfx mesh wrapper).
- Whether c0..c3 are one float4 or four independent channels (forwarded opaque).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Lazy-fill contract, ABI, offsets, and callee linkage sealed. Product English open → **accept-with-gaps**.
