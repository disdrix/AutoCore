# Review A (reconstruction fidelity): `aa_004e8ad0` Quat_ExtractRight_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8ad0` |
| **VA** | `0x004e8ad0` |
| **Body span** | `004e8ad0` – ~`004e8b58` (leaf; single BB) |
| **Canonical name** | `Quat_ExtractRight_Inferred` |
| **Ghidra name** | `FUN_004e8ad0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004e8ad0_Quat_ExtractRight_Inferred.md` |
| **System** | `physics` / `input-drive-control` (shared math leaf) |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure **unit-quaternion → local +X (right) basis axis** extractor.

```
// param_1 = const float quat[4]   // XYZW (indices 0..3)
// param_2 = float out[4]          // XYZ right direction; W forced 0
void Quat_ExtractRight_Inferred(float *quat, float *outRight);
```

Closed form (unit quat → rotation-matrix **column 0**):

```
out.x = 1 − 2(y² + z²)
out.y = 2(xy + zw)
out.z = 2(xz − yw)
out.w = 0
```

**Not** forward (+Z) — that is sibling `FUN_004e8a40` @ `0x004e8a40`.  
**Not** up (+Y) — that is sibling `FUN_004e8b60` @ `0x004e8b60`.

Leaf: **no calls**, cyclomatic complexity **1**, stack args only (not `__thiscall`).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004e8ad0_FUN_004e8ad0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_004e8ad0_FUN_004e8ad0.annotated.md` | Scaffold (still valid CF) |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e8ad0.cpp` | CF ≡ raw |
| Named alias clean | `reconstructed-exact/Named_CalleeOf_CVOGHBAICreatureBase_DecideHeading_004e8ad0.cpp` | Parent-seed rename only |
| Function record | `docs/reconstruction/functions/aa_004e8ad0_FUN_004e8ad0.md` | Strengthened this pass |
| Verified physics | `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md` | Prior math seal (2026-07-15) |
| Live decompile | Ghidra MCP `decompile_function` @ `0x004e8ad0` | **≡ raw** |
| Live `read_memory` | `0x00a0f2a0`, `0x00a10e74`, body @ `0x004e8ad0` | Constants + SSE loads sealed |
| Globals audit | `audit_globals_in_function` | Only `g_flOne`, `g_flLevelUpUiBase_Inferred` |
| Callers | `get_function_xrefs` (22 sites) | Drive / AI / camera / net |
| Sibling roles | verified `fn_004e8ad0_basisExtract.md` + MoveToTarget `0x4fc650` | R/F/U columns |

**Not performed:** Launcher, runtime golden, bit-exact binary diff. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature: two `float*`, cdecl/stack (`[ebp+8]`, `[ebp+0xc]`) | **High** | Prologue `mov eax,[ebp+8/0xc]`; decompile |
| Input layout **XYZW** (x=`[0]`, y=`[1]`, z=`[2]`, w=`[3]`) | **High** | Loads + matrix identity |
| Output is **right (+X)** matrix column 0 | **High** | Closed form + identity check `(0,0,0,1)→(1,0,0,0)` |
| Formula: `out.x = 1 − 2(y²+z²)` | **High** | Live decompile |
| Formula: `out.y = 2(xy + zw)` | **High** | Live |
| Formula: `out.z = 2(xz − yw)` | **High** | Live (`z*x − y*w`) |
| `out.w = 0.0` always | **High** | Final store |
| `g_flOne` @ `0x00a0f2a0` = **1.0f** | **High** | `read_memory` → `00 00 80 3f` |
| `g_flLevelUpUiBase_Inferred` @ `0x00a10e74` = **2.0f** | **High** | `read_memory` → `00 00 00 40` (quat factor; UI plate is misnomer here) |
| No normalize of input or output | **High** | Leaf; no length/sqrt |
| Leaf / no callees / single BB | **High** | Signature tool: `call_count=0`, `basic_block_count=1` |
| Sibling forward `0x004e8a40` / up `0x004e8b60` | **High** | Verified sibling set |
| Product English name | **Probable** (`_Inferred`) | No string/RTTI; math role sealed |
| Callers use chassis/body quat @ `rb+0x30` or entity transform | **High** (site CF elsewhere) | MoveToTarget / PushDriveAxes / camera |
| Non-unit quat yields non-unit axis | **High** (math) | Retail does not re-normalize |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Load y,z,x,w from `param_1` | **Yes** |
| Load TWO from `0xa10e74`, ONE from `0xa0f2a0` | **Yes** |
| `*out = ONE − (z*z + y*y) * TWO` | **Yes** |
| `out[2] = (z*x − y*w) * TWO` | **Yes** |
| `out[1] = (x*y + z*w) * TWO` | **Yes** |
| `out[3] = 0` | **Yes** |
| return (no branches) | **Yes** |
| No invent normalize / up / forward / thiscall | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void FUN_004e8ad0(float *param_1, float *param_2)
{
  float fVar1;  // y
  float fVar2;  // z
  float fVar3;  // x
  float fVar4;  // w
  float fVar5;  // 2.0

  fVar5 = g_flLevelUpUiBase_Inferred;   // 2.0 @ 0xa10e74
  fVar1 = param_1[1];                   // y
  fVar2 = param_1[2];                   // z
  fVar3 = *param_1;                     // x
  fVar4 = param_1[3];                   // w
  *param_2     = g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred;
  param_2[2]   = (fVar2 * fVar3 - fVar1 * fVar4) * fVar5;
  param_2[1]   = (fVar3 * fVar1 + fVar2 * fVar4) * fVar5;
  param_2[3]   = 0.0;
  return;
}
```

### 4.2 Constants (`read_memory` this pass)

| Address | LE bytes | float32 | Role |
|---|---|---:|---|
| `0x00a0f2a0` | `00 00 80 3f` | **1.0** | diagonal `1 − 2(…)` |
| `0x00a10e74` | `00 00 00 40` | **2.0** | quaternion scale factor |

### 4.3 Instruction seal (body head)

```text
55 8B EC           push ebp; mov ebp,esp
83 E4 F0           and esp,-16
8B 45 08           mov eax,[ebp+8]          ; quat*
F3 0F 10 48 04     movss xmm1,[eax+4]       ; y
F3 0F 10 40 08     movss xmm0,[eax+8]       ; z
F3 0F 10 10        movss xmm2,[eax]         ; x
F3 0F 10 58 0C     movss xmm3,[eax+0xc]     ; w
8B 45 0C           mov eax,[ebp+0xc]        ; out*
F3 0F 10 35 …      movss xmm6,[0x00a0f2a0]  ; 1.0
…                  (mul/add for 2*(y²+z²))
F3 0F 10 25 …      movss xmm4,[0x00a10e74]  ; 2.0
…
```

### 4.4 Hand checks

| Input quat `(x,y,z,w)` | Right out |
|---|---|
| Identity `(0,0,0,1)` | `(1,0,0,0)` |
| 90° about +Y `(0, √½, 0, √½)` | `(0,0,−1,0)` |

Matches local **+X right**, **+Z forward**, **+Y up** (see sibling set).

---

## 5. Callers (live xrefs, 22 sites)

| Call site | Function | Role (High / Probable) |
|---|---|---|
| `0x004fc7d2` | `FUN_004fc650` (`MoveToTarget3DPoint`) | Lateral = `dot(right, dir)` for steer |
| `0x0091a707` | `FUN_0091a5f0` (`Client_Camera_ApplyLookOffset`) | Camera right basis |
| `0x005d0af1` | `CVOGHBAICreatureBase_DecideHeading` | AI heading / right axis |
| `0x004f9b7d` | `CVOGPlayerVehicle_UpdateTurretAiming` | Turret aim frame |
| `0x0053eb08`, `0x0053eb1d` | `FUN_0053e820` | Net/orient path (2 sites) |
| `0x0053f7d8`, `0x0053f7fc` | `FUN_0053f1f0` | Related (2 sites) |
| `0x004c717c` | `FUN_004c6d80` | Creature/graphics |
| `0x004c7e1a` | `FUN_004c7bd0` | Creature/graphics |
| `0x004ca4fb` | `FUN_004ca150` | Creature/graphics |
| `0x005957a1` | `FUN_00595230` | — |
| `0x005bd061` | `FUN_005bc3c0` | — |
| `0x005cf90e` | `FUN_005cf560` | — |
| `0x006156fb` | `FUN_00615020` | — |
| `0x00851baf` | `FUN_00851630` | UI/client |
| `0x0085a449` | `FUN_00859bc0` | UI/client |
| `0x009169f7` | `FUN_009168d0` | Client |
| `0x00930418` | `FUN_00930360` | Client |
| `0x0094f571` | `FUN_0094f2e0` | Client |
| `0x0091808a`, `0x00918238` | `FUN_00917cd0` | Client (2 sites) |

Primary RE consumers already documented: MoveToTarget, camera look, AI DecideHeading, turret aiming. Forward sibling often paired at same call sites (e.g. MoveToTarget also calls `0x004e8a40`).

---

## 6. Gaps / open

1. Retail product symbol (string/RTTI) — none; keep `_Inferred`.
2. Full English roles for every non-drive/camera xref (addr inventory sealed; product names open).
3. Runtime golden on identity / yaw samples (math sealed statically).
4. Whether any caller feeds non-unit quat intentionally (body does not normalize).
5. Clean plate still uses Ghidra `FUN_*` / misnamed `g_flLevelUpUiBase_Inferred` — CF correct; rename polish optional.

**Verdict:** **accept-with-gaps** — dual **CF + constants + matrix column identity + caller inventory** sealed; package **not complete** (product name, runtime, full caller English).
