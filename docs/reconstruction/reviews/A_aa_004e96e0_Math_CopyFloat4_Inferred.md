# Review A (reconstruction fidelity): `aa_004e96e0` Math_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e96e0` |
| **VA** | `0x004e96e0` |
| **Body** | `0x004e96e0`–`0x004e9715` (54 bytes) |
| **Canonical name** | `Math_CopyFloat4_Inferred` |
| **Review date** | `2026-07-29` (W17-O dual A/B seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e96e0_Math_CopyFloat4_Inferred.md` |
| **System** | shared math leaf |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Sibling cross-check: `0x004e9530` Math_CopyFloat3ToFloat4_Inferred.

---

## 1. Purpose

Stack-arg **full float4 copy**: `dst[0..3] = src[0..3]` via SSE `movss`. Returns `dst*` in EAX. Leaf. **Not** normalize / basis / quat.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e96e0_FUN_004e96e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_CopyFloat4_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e96e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e96e0_Math_CopyFloat4_Inferred.md` |

---

## 3. Byte seal (`read_memory` @ `0x004e96e0`, 54 B)

```
55 8B EC                         push ebp; mov ebp, esp
8B 45 0C                         mov eax, [ebp+0xC]      ; src
F3 0F 10 40 0C                   movss xmm0, [eax+0xC]   ; src.w
F3 0F 10 08                      movss xmm1, [eax]       ; src.x
F3 0F 10 50 04                   movss xmm2, [eax+4]     ; src.y
F3 0F 10 58 08                   movss xmm3, [eax+8]     ; src.z
8B 45 08                         mov eax, [ebp+8]        ; dst (EAX retained to ret)
83 E4 F0                         and esp, -16
F3 0F 11 08                      movss [eax], xmm1
F3 0F 11 50 04                   movss [eax+4], xmm2
F3 0F 11 58 08                   movss [eax+8], xmm3
F3 0F 11 40 0C                   movss [eax+0xC], xmm0
8B E5 5D C3                      mov esp, ebp; pop ebp; ret
```

| Claim | Confidence | Evidence |
|---|---|---|
| cdecl stack `dst*`, `src*` | **High** | `[ebp+8]`, `[ebp+0xC]`; bare `ret` |
| Copies **all four** floats from src | **High** | four load + four store `movss` |
| W from **src+0xC** (not dirty stack) | **High** | `movss xmm0,[eax+0xC]` then store |
| EAX returns dst* | **High** | last `mov eax,[ebp+8]` before stores |
| Leaf / no callees | **High** | body has no `call` / `E8` |
| Not normalize | **High** | no mul/sqrt/rsqrt |
| Sibling `0x004e9530` is float3→float4 dirty W | **High** | prior dual A/B |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load src.xyzw | **Yes** |
| Store dst.xyzw | **Yes** |
| No branch | **Yes** |
| Return dst* | **Yes** (clean documents; decompiler may show void) |

Prior scaffold typed args as `uint32_t*` without return — CF equivalent; plate upgraded to `float*` + return.

---

## 5. Gaps / open

1. Product/PDB English name (INFERRED).
2. Overlap/aliasing contract if dst≡src (element order via XMM temps is safe for full 16-byte non-overlapping; self-copy ok via temps).
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
