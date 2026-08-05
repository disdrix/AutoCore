# Review A (reconstruction fidelity): `aa_005da0a0` Drive_CollisionListener_Contact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005da0a0` |
| **VA** | `0x005da0a0`–`0x005dab25` |
| **Canonical name** | `Drive_CollisionListener_Contact` |
| **Ghidra name** | `FUN_005da0a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-I) |
| **Counterpart** | `reviews/B_aa_005da0a0_Drive_CollisionListener_Contact.md` |
| **System** | drive / collision / vehicle damage |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller `FUN_005dab30` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CollisionListener::contact` — core phys contact callback:

1. Resolve hosts + game objects from body A/B chains.
2. Material-type==1 special path with tick debounce (500 ms).
3. Type 0xe hooks; rate-limit via `this+0x10` (0.5 s).
4. Per-body prep (`FUN_005d9ea0` ×2).
5. Impact energy (`|v|·3.6)² · mass · 2.5e-7`, clamp 350; optional damage.
6. Type 0x12 gates; FX; Logic-UI opcode **0x29** when `|impact|>1`.
7. Bidirectional `Drive_CollisionListener_DoVehicleCollision`.
8. AL=0 → caller marks contact event disabled.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_Contact.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005da0a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005da0a0_FUN_005da0a0.md` |
| Sibling | `Drive_CollisionListener_DoVehicleCollision` `0x005d9290` |
| Caller | `FUN_005dab30` `0x005dab30` |
| Live | decompile ≡ raw; body 2693 B; prologue ECX save; `C2 10 00`; string contact |

---

## 3. Signature (sealed)

```c
// __thiscall RET 0x10; AL = uint8_t
uint8_t Drive_CollisionListener_Contact(
    void* this, uint32_t ctx, float* impact, int* bodyA, int* bodyB);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → `[esp+0x24]`; rate @ +0x10 | **High** |
| ctx | Stack[0x4] (`event+0x14`) | **High** |
| impact | Stack[0x8] (`event+0x1c`) | **High** |
| bodyA/B | Stack[0xC]/[0x10] | **High** |
| return | AL; 0 reject else keep | **High** |
| cleanup | `RET 0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Profiler string enter/leave | **Yes** | **High** |
| Parent-walk A/B → host[8] | **Yes** | **High** |
| Pair-list type==1 + bit5 + vtbl+0x1c8 | **Yes** | **High** |
| Material type1 exclusive path + debounce 500 | **Yes** | **High** |
| Type 0xe → FUN_004faf80 | **Yes** | **High** |
| Rate 0.5s via this+0x10 | **Yes** (this residual filled) | **High** |
| FUN_005d9ea0 both sides | **Yes** | **High** |
| Missing GO → return 1 | **Yes** | **High** |
| Energy 3.6 / 2.5e-7 / clamp 350 | **Yes** (floats sealed) | **High** |
| UI opcode 0x29 if \|impact\|>1 | **Yes** | **High** |
| Bidirectional FUN_005d9290 | **Yes** | **High** |
| LAB_005dab08 return 0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue (thiscall + SEH + stack 0x188):
```
558bec83e4f06aff680f729a0064a100000000506489250000000081ec88010000535657894c2424...
```

Epilogue region (`0x005dab00`):
```
...ffffffff e8e3231900 ... 32c0 ... c21000
```
`xor al,al` path + `RET 0x10`.

Constants: see raw append table (1.0 / 0.5 / 3.6 / ~2.5e-7 / 350 / 500).

---

## 6. Gaps

- Product English for clonebase types **0xe / 0x12 / 3**.
- Full contact-event struct beyond caller offsets 0x08/0x0c/0x14/0x1c/0x20.
- Nested callee contracts (`FUN_005d9ea0`, `FUN_005d9af0`, `FUN_005dab60`) owned elsewhere.
- Decompiler this residual documented; not a CF mismatch.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/name/constants sealed; product type English open.
