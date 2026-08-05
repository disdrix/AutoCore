# Review A (reconstruction fidelity): `aa_005d9ea0` Drive_CollisionListener_PrepBodyContact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9ea0` |
| **VA** | `0x005d9ea0`–`0x005da093` |
| **Canonical name** | `Drive_CollisionListener_PrepBodyContact` |
| **Ghidra name** | `FUN_005d9ea0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-K) |
| **Counterpart** | `reviews/B_aa_005d9ea0_Drive_CollisionListener_PrepBodyContact.md` |
| **System** | drive / collision / client FX+SFX |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; caller Contact ×2 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-body contact prep for `CollisionListener::contact`:

1. Parent-walk body → host.
2. Resolve type-1 GO (flag bit5 + vtbl+0x1C8); materials type 3/4.
3. On new body cache miss: optional sound if enable and `|impact|>1`.
4. If type-3 nested GO: material pack + optional sound + `PlayCollisionEffect(..., allowCreate=0)`; set out flag.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.md` (+ W25-K append) |
| Annotated | `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PrepBodyContact.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d9ea0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d9ea0_FUN_005d9ea0.md` |
| Caller | `Drive_CollisionListener_Contact` sites `005da4d8` / `005da4f3` |
| Sibling duals | PlayCollisionEffect W23-G; Contact W22-I |
| Live | body 500 B; `C2 14 00`; gate 1.0f |

---

## 3. Signature (sealed)

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PrepBodyContact(
    void* this, void* ctx, int* body, float* impact,
    uint8_t enable, uint8_t* outPlayed);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX; cache @ +0xc | **High** |
| ctx | Stack[0x4]; to sound/FX | **High** (English **Med**) |
| body | Stack[0x8]; chain head | **High** |
| impact | Stack[0xc]; ABS magnitude | **High** |
| enable | Stack[0x10] low byte | **High** |
| outPlayed | Stack[0x14]; set 1 on FX | **High** |
| cleanup | `RET 0x14` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Parent walk `[3]` → host`[8]` | **Yes** | **High** |
| Pair type==1 + bit5 + vtbl+0x1C8 | **Yes** | **High** |
| Pair type==3 / ==4 materials | **Yes** | **High** |
| Body cache `this+0xc` | **Yes** | **High** |
| Sound gate enable + \|imp\|>1 | **Yes** | **High** |
| Nested type==3 GO path | **Yes** | **High** |
| PlayCollisionEffect allowCreate=0 | **Yes** | **High** |
| outPlayed=1 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue:
```
83ec0c 53 8b5c2418 55 894c240c ...
```

Epilogue:
```
5f5e5d5b 83c40c c21400
```

Threshold `0x00af4364` = `00 00 80 3F` (1.0f).

---

## 6. Gaps

- Product English for pair types 1/3/4 and nested `+0x38==3`.
- ctx exact type (cookie vs float payload).
- enable producers beyond Contact CF.
- Nested callee depth owned on their plates.
- Runtime / bit-exact.
