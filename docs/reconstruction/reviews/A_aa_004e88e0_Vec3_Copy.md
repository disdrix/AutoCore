# Review A (reconstruction fidelity): `aa_004e88e0` Vec3_Copy

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e88e0` |
| **VA** | `0x004e88e0` |
| **Body** | `0x004e88e0`–`0x004e8904` (37 bytes) |
| **Canonical name** | `Vec3_Copy` |
| **Review date** | `2026-07-29` (W17-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e88e0_Vec3_Copy.md` |
| **System** | `math` / vector |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf helper: copy **exactly three** consecutive floats (XYZ) from `src` to `dst`. Not a basis transform, normalize, or float4 copy.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e88e0_FUN_004e88e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e88e0_FUN_004e88e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vec3_Copy.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e88e0_FUN_004e88e0.md` |

---

## 3. Byte seal (`read_memory` @ `0x004e88e0`, 37-byte body)

```
8B 44 24 08        mov  eax, [esp+8]       ; src
F3 0F 10 00        movss xmm0, [eax]
F3 0F 10 48 04     movss xmm1, [eax+4]
F3 0F 10 50 08     movss xmm2, [eax+8]
8B 44 24 04        mov  eax, [esp+4]       ; dst
F3 0F 11 00        movss [eax], xmm0
F3 0F 11 48 04     movss [eax+4], xmm1
F3 0F 11 50 08     movss [eax+8], xmm2
C3                 ret
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__cdecl`, two stack pointers | **High** | `[esp+8]` then `[esp+4]`; bare `ret` |
| `param_1`=dst, `param_2`=src | **High** | stores only through second load |
| Exactly 3 components | **High** | offsets 0/+4/+8 only; no +0xC |
| SSE scalar float path | **High** | `F3 0F 10` / `F3 0F 11` |
| Leaf | **High** | no `call`/`jmp` out |
| Not transform | **High** | pure load/store |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load src[0..2] | **Yes** |
| Store dst[0..2] | **Yes** |
| No fourth component | **Yes** |
| No callees | **Yes** |

---

## 5. Caller usage (context only)

Named parents pass stack/local float3 or float4 bases and use this for **position-only** copies (e.g. FindFirstObjectInRadius waypoint XYZ, NPC interact icon positions, respawn special-event pose).

---

## 6. Gaps

1. Product/PDB symbol string for helper name — open (`Vec3_Copy` INFERRED).
2. Runtime / bit-exact differential — open.
3. Exhaustive caller semantic catalog — not required for leaf seal.

**Verdict:** **accept**
