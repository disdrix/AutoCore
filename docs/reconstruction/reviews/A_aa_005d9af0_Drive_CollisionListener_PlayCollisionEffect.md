# Review A (reconstruction fidelity): `aa_005d9af0` Drive_CollisionListener_PlayCollisionEffect

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9af0` |
| **VA** | `0x005d9af0`–`0x005d9e94` |
| **Canonical name** | `Drive_CollisionListener_PlayCollisionEffect` |
| **Ghidra name** | `FUN_005d9af0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-G) |
| **Counterpart** | `reviews/B_aa_005d9af0_Drive_CollisionListener_PlayCollisionEffect.md` |
| **System** | drive / collision / client FX |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers Contact + `005d9ea0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CollisionListener::PlayCollisionEffect`:

1. Reject null game object.
2. Resolve clonebase FX (`go+0xA8`, gate `+0x88`).
3. Optionally lazy-create FxMaster on listener `+4` when `allowCreate!=0`.
4. Load event variant; sample GO vtbl+0x1C8 ×2.
5. Set three float3 FX params (keys 1–3) via `FUN_004b7550`.
6. Play via GO vtbl+0xF8 + `FUN_004b7e50(0,0,0)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.md` (+ 2026-07-29 W23-G append) |
| Annotated | `docs/reconstruction/raw/aa_005d9af0_FUN_005d9af0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PlayCollisionEffect.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d9af0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d9af0_FUN_005d9af0.md` |
| Callers | `FUN_005da0a0`, `FUN_005d9ea0` |
| Live | string @ `0x009db524`; body 932 B; `C2 14 00`; prologue `mov ebx,ecx` / `mov edi,[ebp+14]` |

---

## 3. Signature (sealed)

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PlayCollisionEffect(
    void* this, float* vec3_a, uint32_t a1, uint32_t a2,
    int* gameObject, int8_t allowCreate);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ebx; FxMaster @ +4 | **High** |
| vec3_a | [ebp+8] three movss | **High** |
| a1 / a2 | [ebp+c] / [ebp+10] | **Medium** (wired, English open) |
| gameObject | [ebp+14]; null check | **High** |
| allowCreate | [ebp+18] | **High** |
| cleanup | `RET 0x14` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Null go early return | **Yes** | **High** |
| Profiler string enter/leave | **Yes** | **High** |
| clonebase go+0xA8 / gate +0x88 | **Yes** | **High** |
| Lazy FxMaster new(8)+ctor+LoadMaster | **Yes** | **High** |
| LoadEventVariant both branches | **Yes** | **High** |
| vtbl+0x1C8 ×2 | **Yes** | **High** |
| SetParamFloat3 ×3 keys 1..3 | **Yes** | **High** |
| vtbl+0xF8 + FUN_004b7e50 | **Yes** | **High** |
| allowCreate==0 skips create | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue:
```
558bec83e4f06aff68fa719a0064a100000000506489250000000083ec485356578b7d1485ff8bd90f8463030000...6824b59d00...
```

Epilogue region (`0x005d9e70`):
```
... c21400
```

String `0x009db524`: `CollisionListener::PlayCollisionEffect`.

---

## 6. Gaps

- stack1/stack2 product English.
- Full float transform algebra bit-exact (2.0f / 1.0f sealed; matrix residual).
- Nested callee depth owned on their plates.
- Runtime / bit-exact EXE.
