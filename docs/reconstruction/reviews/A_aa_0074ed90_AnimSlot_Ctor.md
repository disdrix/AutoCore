# Review A (reconstruction fidelity): `aa_0074ed90` AnimSlot_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ed90` |
| **VA** | `0x0074ed90` |
| **Body** | `0x0074ed90`–`0x0074ee31` (162 bytes) |
| **Canonical name** | `AnimSlot_Ctor` (Ghidra `FUN_0074ed90`; **Inferred**) |
| **Review date** | `2026-07-29` (W24-R dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0074ed90_AnimSlot_Ctor.md` |
| **System** | client visual / animation slot |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`).

---

## 1. Purpose

**Leaf default constructor** for a **0x78-byte** animation slot. Initializes timing/mode defaults used by `AnimSlot_SetTime` and load paths (`Object_LoadOrReplaceAnimSlot`, graphics asset type `0x41`, etc.).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074ed90_FUN_0074ed90.md` (+ W24-R live append) |
| Annotated | `docs/reconstruction/raw/aa_0074ed90_FUN_0074ed90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_Ctor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0074ed90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074ed90_FUN_0074ed90.md` |
| Live decompile | `decompile_function` @ `0x0074ed90` ≡ raw CF |
| Machine | `read_memory` @ `0x0074ed90` (body) + `g_flOne` @ `0x00a0f2a0` |
| Callers | 10 functions / 12 xrefs |
| Parent duals | `A_aa_0074e910_AnimSlot_SetTime`, `A_aa_005828b0_Object_LoadOrReplaceAnimSlot` |

---

## 3. Byte seal (`read_memory` @ `0x0074ed90`)

```
; SEH setup ...
8B C1           mov  eax, ecx            ; slot
33 C9           xor  ecx, ecx
89 48 04 ...    zero dwords +0x04..
0F 57 C0        xorps xmm0,xmm0
F3 0F 11 40 10  movss [eax+0x10], xmm0
F3 0F 10 0D A0 F2 A0 00  movss xmm1, [g_flOne]
...
F3 0F 11 48 3C  movss [eax+0x3c], xmm1  ; rate = 1.0
C6 40 4C 01     mov  byte [eax+0x4c], 1 ; mode wrap
83 CA FF        or   edx, -1
89 50 50        mov  [eax+0x50], edx
...
C3              ret
```

`g_flOne` bytes: `00 00 80 3f` = **1.0f**.

Full body hex (162 B):
```
6aff68c1fc9a0064a1000000005064892500000000518bc133c989480489480889480c0f57c0f30f11401089481889481c894820f30f100da0f2a00089482889482c89483083caff884855884856f30f114034f30f114038f30f11483cf30f114040f30f114044f30f114048c6404c01895050c640540189485889485c895060f30f114064895068f30f11406c8948708948748b4c240464890d0000000083c410c3
```

| Claim | Confidence | Evidence |
|---|---|---|
| ECX=object, no stack args | **High** | `mov eax,ecx`; bare `ret` after SEH pop |
| Leaf | **High** | no `call`; only global load |
| Size **0x78** | **High** | callers `operator_new(0x78)`; last store +0x74 |
| Rate +0x3c = 1.0 | **High** | `movss` from `g_flOne` |
| Mode +0x4c = 1 | **High** | `C6 40 4C 01` |
| Unwritten +0/+0x14/+0x24 | **High** | absent from store list |
| Role anim-slot ctor | **High** | sibling duals + load paths |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| SEH frame setup/teardown | **Yes** (present; no nested try) |
| Zero / float defaults | **Yes** |
| rate/mode/sentinels | **Yes** |
| No callees | **Yes** |
| No invented +0 vtable write | **Yes** |

---

## 5. Caller usage (context only)

| Caller | Use |
|---|---|
| `Object_LoadOrReplaceAnimSlot` | `new(0x78)` + ctor + path load + SetTime |
| `CVOGGraphicsBase_LoadNextChildAsset` case `0x41` | ctor + `FUN_0074ee40` load + dtor pair |
| `FUN_00504d40` | same alloc/ctor/load pattern on object slots |

---

## 6. Gaps

1. Product/PDB class spelling — open (`AnimSlot` structural).
2. Semantic English for unwritten +0x00/+0x14/+0x24 and `-1` sentinels — residual.
3. Runtime / bit-exact — open.

**Verdict:** **accept** (leaf CF fully sealed; residuals are naming/semantics only)
