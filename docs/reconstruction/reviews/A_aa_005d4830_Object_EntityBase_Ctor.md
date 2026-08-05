# Review A (reconstruction fidelity): `aa_005d4830` Object_EntityBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4830` |
| **VA** | `0x005d4830`–`0x005d48e4` |
| **Canonical name** | `Object_EntityBase_Ctor` |
| **Ghidra name** | `FUN_005d4830` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-E) |
| **Counterpart** | `reviews/B_aa_005d4830_Object_EntityBase_Ctor.md` |
| **System** | object core / entity base ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers `FUN_005c82a0` / `FUN_005dbfa0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **most-derived / base constructor** for the entity base parent of sealed `Object_EntityMidBase_Ctor`:

1. If `mostDerivedFlag != 0`: vb cookies `DAT_009dd760` @ `+4`, `DAT_009dac4c` @ `+0x44`; `Object_SharedBase_Ctor` at **`this+0xe0`**.
2. Always: `FUN_0053cdc0(this, 0)`; `FUN_00581330(this+0x40, 0)`.
3. Zero `+0xbc`, `+0xc0`.
4. OR flags **0x40** then **0x20** at `*(vtbl_or_vb[+4])+0x180+this`.
5. Return `this` (EAX).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d4830_FUN_005d4830.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_005d4830_FUN_005d4830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EntityBase_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d4830.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d4830_FUN_005d4830.md` |
| Child dual | `Object_EntityMidBase_Ctor` (`0x005c82a0`, W23-K) |
| SharedBase | `Object_SharedBase_Ctor` (`0x00518940`) |
| Live | decompile ≡ raw; `read_memory` 181 B body; epilogue `C2 04 00` |

---

## 3. Signature (sealed)

```c
// stack formal ×1; ECX = this; EAX = this; RET 4
void* __thiscall Object_EntityBase_Ctor(void* self, int mostDerivedFlag);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX → ESI | **High** |
| mostDerivedFlag | Stack[0x4] | **High** |
| return | EAX = ESI | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH frame (LAB_009a709a)
if mostDerived:
  [this+4]=DAT_009dd760; [this+0x44]=DAT_009dac4c
  Object_SharedBase_Ctor(this+0xe0)
FUN_0053cdc0(this, 0)
FUN_00581330(this+0x40, 0)
[this+0xbc]=0; [this+0xc0]=0
flags(vb+0x180) |= 0x40; |= 0x20
return this
```

| Stage | Match | Conf |
|---|---|---|
| mostDerived dual cookies | Yes (imm32 seal) | **High** |
| SharedBase @ +0xe0 | Yes (`8D 8E E0 00 00 00`) | **High** |
| 0053cdc0 @ this | Yes (`8B CE`) | **High** |
| 00581330 @ +0x40 | Yes (`8D 4E 40`) — decomp omitted adjust | **High** |
| flag ORs 0x40/0x20 | Yes | **High** |
| Child mid-base chain | Yes (W23-K) | **High** |

---

## 5. Gaps

- Product C++ class English / RTTI name.
- Full field dictionary for `+0xbc`/`+0xc0` and subobject layouts of `0053cdc0` / `00581330`.
- Nested sub-ctor dual seals residual.
- Runtime / bit-exact.

---

## 6. Verdict

CF/ABI/offsets/flags/callers sealed from decompile+bytes; product English + nested duals open → **accept-with-gaps**.
