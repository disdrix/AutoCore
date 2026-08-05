# Review A (reconstruction fidelity): `aa_004c9120` Object_CacheAIProfileFields_TypeMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9120` |
| **VA** | `0x004c9120`–`0x004c92e3` (452 B) |
| **Canonical name** | `Object_CacheAIProfileFields_TypeMask_Inferred` |
| **Ghidra name** | `FUN_004c9120` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-H) |
| **Counterpart** | `reviews/B_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` |
| **System** | Host AI profile / object cache |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; thunk bytes; sealed map callees |
| **Verdict** | **accept** |

---

## 1. Purpose

Cache AI profile definition fields onto a mid-object `this`, then exact-find the profile key in the host AI profile map and store a type bitmask when present.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.md` (+ W27-H append) |
| Annotated | `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CacheAIProfileFields_TypeMask_Inferred.cpp` |
| Clean twin | `FUN_004c9120.cpp` |
| Function | `docs/reconstruction/functions/aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` |
| Live | decompile ≡ raw; prologue `83EC08568BF1`; epilogue `5E83C408C3` |
| Map callees | W26-N `Host_AIProfileMap_GetOrReset`; W26-O `Map_LowerBoundFindByIntKey_Isnil65` |
| Thunks | `read_memory` @ `0x004ccec0`, `0x0053baa0` |

---

## 3. Signature (sealed)

```c
void __fastcall FUN_004c9120(int param_1 /* ECX this */);
```

| Formal | Role | Conf |
|---|---|---|
| param_1 / ECX | mid-object this | **High** |
| return | void | **High** |
| frame | `SUB ESP,8` / `ADD ESP,8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| `FUN_005c8eb0(this-0x3F0)` | **Yes** (bytes LEA) | **High** |
| Profile chain → `+0x3c` | **Yes** | **High** |
| Field copy table (10 slots) | **Yes** | **High** |
| Key `+0x4dc` + map get/find | **Yes** | **High** |
| Hit → bitmask `@-0x300` | **Yes** | **High** |
| Miss → no store | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body **452 B** hex:

```
83ec08568bf18d8e10fcffffe87ffd0f008b8604fbffff8b48048b9431acfbffff8b423c8b88c0040000898ef0fcffff8b9604fbffff8b42048b8c30acfbffff8b513c8b82d00400008986f8fcffff8b8e04fbffff8b51048b8432acfbffff8b483c0fbf91ee040000899650fcffff8b8604fbffff8b48048b9431acfbffff8b423c8b88d8040000898e20fcffff8b9604fbffff8b42048b8c30acfbffff8b513c0fb782f00400006689863efcffff8b8e04fbffff8b51048b8432acfbffff8b483c668b91f20400006689963cfcffff8b8604fbffff8b48048b9431acfbffff8b423c668b88f404000066898e40fcffff8b9604fbffff8b42048b8c30acfbffff8b513c0fb782f604000066898642fcffff8b8e04fbffff8b51048b8432acfbffff8b483c0fbf9112050000f30f2ac2f30f11865cfdffff8b8604fbffff8b48048b9431acfbffff8b423c0fbf8810050000f30f2ac1f30f118660fdffff8b9604fbffff8b42048b8c30acfbffff8b513c8b82dc0400008d4c2404518b0dfc41b0008d54240c526a0089442410e8de7507008bc8e8972a00008b0dfc41b0006a00e8ca7507008b4c24083b480474108a4910b801000000d3e0898600fdffff5e83c408c3
```

---

## 6. Gaps

- Product English per profile field.
- Full MI class / vbtable product names.
- `FUN_005c8eb0` not OWN dual.
- Runtime open.

---

## 7. Verdict

CF/ABI/offsets/map wiring/thunk entry sealed. Structural `_Inferred` name only — no invented product class. → **accept**.
