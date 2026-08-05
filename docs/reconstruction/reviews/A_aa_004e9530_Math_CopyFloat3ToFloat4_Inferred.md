# Review A (reconstruction fidelity): `aa_004e9530` Math_CopyFloat3ToFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9530` |
| **VA** | `0x004e9530` |
| **Body span** | `004e9530` – `004e9569` (leaf; single BB) |
| **Canonical name** | `Math_CopyFloat3ToFloat4_Inferred` |
| **Ghidra name** | `FUN_004e9530` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live bytes; decompiler W is artifact) |
| **Counterpart** | `reviews/B_aa_004e9530_Math_CopyFloat3ToFloat4_Inferred.md` |
| **System** | shared math leaf (FX / vehicle / camera / AI) |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Stack-arg **float3 → float4 pack copy**:

```c
// param_1 = dst float[4]; param_2 = src float[3+]  (stack [ebp+8], [ebp+0xc])
// NOT a normalizer. Sibling full float4 copy: FUN_004e96e0 @ 0x004e96e0
float *Math_CopyFloat3ToFloat4_Inferred(float *dst, const float *src);
```

Machine behavior (SSE `movss`):

```
dst.x = src.x
dst.y = src.y
dst.z = src.z
dst.w = *uninitialized stack local*   // local_14 / [esp+0xc] never written
// EAX at ret = dst*  (leftover from last load of param_1)
```

**Critical correction vs parent notes:** `A_aa_004b7e50` listed this as “vector normalize / basis for position” — **false**. Body has **no** length, sqrt, rsqrt, or scale. Pure component copy (+ dirty W).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004e9530_FUN_004e9530.md` | decompile outline ≡ CF for xyz; W as local_14 |
| Annotated | `docs/reconstruction/raw/aa_004e9530_FUN_004e9530.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e9530.cpp` | Scaffold ≡ raw |
| Named alias | `Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming_004e9530.cpp` | Parent-seed only |
| Function record | `docs/reconstruction/functions/aa_004e9530_FUN_004e9530.md` | Scaffold |
| Live decompile | Ghidra `batch_decompile` @ `0x004e9530` | Matches raw |
| Live `read_memory` | body @ `0x004e9530` length 64 | **Authoritative for W source** |
| Live pcode | `get_function_pcode` basic | STORE w from stack[-0x14] |
| Sibling | `FUN_004e96e0` live decompile | Full float4 copy (all four src components) |
| Callers | analyze: **27** named callers / **35** xrefs | drive, FX, turret, camera, AI, UI |

**Not performed:** Launcher, runtime golden, bit-exact. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack args: `dst*`, `src*` (`[ebp+8]`, `[ebp+0xc]`) | **High** | Prolog + loads |
| Copies **src.x,y,z → dst.x,y,z** via `movss` | **High** | bytes seal |
| **Not** normalize / not basis extract | **High** | no math ops in body |
| `dst.w` comes from **uninitialized** stack local (`local_14` / `[esp+0xc]` after `sub esp,0x10`) | **High** (artifact) | bytes: `movss xmm0,[esp+0xc]` then store to `dst+0xc`; never written earlier |
| Product intends W=0 always | **Tentative** | no xorps; callers may ignore W |
| EAX returns `dst*` | **High** | last `mov eax,[ebp+8]` before stores; RET uses leftover EAX |
| Leaf / no callees | **High** | analyze |
| Sibling `0x004e96e0` is full float4 copy | **High** | live decompile copies src[3]→dst[3] |
| Product English name | **Probable** (`_Inferred`) | no string |
| Exclusive “turret helper” | **Falsified** | 35 xrefs |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| align stack; sub 0x10 | **Yes** (bytes; decompiler abstracts) |
| load src x,y,z | **Yes** |
| store dst x,y,z | **Yes** |
| store dst w from stack local | **Yes** (raw `local_14`; bytes confirm uninit) |
| no normalize branch | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void FUN_004e9530(undefined4 *param_1, undefined4 *param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_14;   // never assigned in decompile

  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = local_14;
  return;
}
```

### 4.2 Instruction seal (`read_memory` this pass)

```text
55                 push ebp
8B EC              mov  ebp, esp
83 E4 F0           and  esp, -16
83 EC 10           sub  esp, 0x10
8B 45 0C           mov  eax, [ebp+0xC]      ; src*
F3 0F 10 00        movss xmm0, [eax]        ; x
F3 0F 10 48 04     movss xmm1, [eax+4]      ; y
F3 0F 10 50 08     movss xmm2, [eax+8]      ; z
8B 45 08           mov  eax, [ebp+8]        ; dst*  (EAX survives to RET)
F3 0F 11 00        movss [eax], xmm0
F3 0F 10 44 24 0C  movss xmm0, [esp+0xC]    ; UNINIT stack slot → W
F3 0F 11 48 04     movss [eax+4], xmm1
F3 0F 11 50 08     movss [eax+8], xmm2
F3 0F 11 40 0C     movss [eax+0xC], xmm0    ; dst.w = trash/stack
8B E5              mov  esp, ebp
5D                 pop  ebp
C3                 ret
```

Hex: `558bec83e4f083ec108b450cf30f1000f30f104804f30f1050088b4508f30f1100f30f1044240cf30f114804f30f115008f30f11400c8be55dc3`

### 4.3 Sibling contrast

| VA | Role |
|---|---|
| `0x004e9530` (this) | float3→float4; **W uninit stack** |
| `0x004e96e0` | full float4 copy (`dst[3]=src[3]`) |
| `0x004e8a40` / `0x004e8ad0` / `0x004e8b60` | quat basis extractors (different family) |

---

## 5. Callers (live; partial English)

**35** xrefs / **27** caller functions including:

| Function | Role (High / Probable) |
|---|---|
| `FUN_004b7e50` | FX host process list — position pack |
| `FUN_004b75d0` | NDSpecialFX param map transforms |
| `CVOGPlayerVehicle_UpdateTurretAiming` | turret aim frame |
| `FUN_004f8430`, `FUN_004f5c30`, `FUN_004fa0f0`, `FUN_00500560` | vehicle / drive-adjacent |
| `FUN_004d4da0`, `FUN_004d2c60`, `FUN_004c7bd0` | creature / map |
| `FUN_00921f70`, `FUN_00916090`, `FUN_00851630`, `FUN_00859bc0` | client / UI / camera-ish |
| `ClientSpecialEvent_Respawn_Update` | respawn |
| … | many others |

Primary RE note: used wherever a **float3** must land in a **float4** slot; **not** length-1 normalize.

---

## 6. Gaps / open

1. Whether any production path **depends on W** (likely ignore; stack trash is real).
2. Product helper name (none in strings).
3. Full English roles for all 27 callers.
4. Parent dual `A_aa_004b7e50` mislabel “normalize” should be treated as **stale** relative to this seal.
5. Runtime / bit-exact not run; clean still scaffold.

**Verdict:** **accept-with-gaps** — dual **CF + bytes + non-normalize identity + sibling contrast + caller inventory** sealed; W product intent and English name open.
