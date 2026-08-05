# Review A (reconstruction fidelity): `aa_005c82a0` Object_EntityMidBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c82a0` |
| **VA** | `0x005c82a0`–`0x005c83a1` |
| **Canonical name** | `Object_EntityMidBase_Ctor` |
| **Ghidra name** | `FUN_005c82a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-K) |
| **Counterpart** | `reviews/B_aa_005c82a0_Object_EntityMidBase_Ctor.md` |
| **System** | object core / entity mid-base ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers Vehicle/`CVOGCreature` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **entity mid-base constructor** shared by creature and vehicle:

1. If `mostDerivedFlag != 0`: vb cookies + `Object_SharedBase_Ctor(this+0x110)`.
2. Always: `FUN_005d4830(this, 0)`.
3. Install mid-base vtbls + vb adjustor `-0x10c`.
4. Default fields `+0xD0..+0xF8` (500 at `+0xE4`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.md` (+ W23-K append) |
| Annotated | `docs/reconstruction/raw/aa_005c82a0_FUN_005c82a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EntityMidBase_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c82a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c82a0_Object_EntityMidBase_Ctor.md` |
| SharedBase | `aa_00518940` (embed +0x110) |
| Live | decompile ≡ raw; 257 B body; `C2 04 00` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 0x4; EAX=this
uint32_t* Object_EntityMidBase_Ctor(uint32_t* self, int mostDerivedFlag);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX → ESI | **High** |
| mostDerivedFlag | Stack[0x4] | **High** |
| cleanup | `RET 0x4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if mostDerived:
  vb cookies; SharedBase(this+0x110)
FUN_005d4830(0)
install vtbls + vb adjustor -0x10c
default +0xD0..+0xF8
return this
```

| Stage | Match | Conf |
|---|---|---|
| mostDerived gate | **Yes** | **High** |
| SharedBase @ +0x110 | **Yes** | **High** |
| Parent FUN_005d4830 flag 0 | **Yes** | **High** |
| adjustor -0x10c | **Yes** | **High** |
| +0xE4 = 500 | **Yes** | **High** |
| Creature + Vehicle parents | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 257 B hex in raw append. Call rel32: `0x00518940`, `0x005d4830`. Imm 500 = `F4 01 00 00` at `+0xE4` store.

---

## 6. Gaps

- Product C++ class English (no RTTI this pass).
- Field dictionary English beyond init values.
- Parent `FUN_005d4830` full layout (not owned).

**Residual gaps non-blocking for CF/ABI.** Verdict **accept-with-gaps**.
