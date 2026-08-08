# Review A (reconstruction fidelity): `aa_004e9720` CVOGPhysicsUtils_FindClearSpawnPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9720` |
| **VA** | `0x004e9720`–`0x004e9a9b` |
| **Canonical name (Ghidra)** | `FUN_004e9720` |
| **Proposed name** | `CVOGPhysicsUtils_FindClearSpawnPosition_Inferred` |
| **Review date** | `2026-08-05` (R13-027 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` |
| **System** | interaction-activation (partition parent `0x005eb790` query-collect ctor) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**cdecl** physics helper that **probes for a collision-clear spawn/placement position** using a **sphere query-collect** object (parent dual `VOGPhysics_QueryCollect_Ctor_Inferred` @ `0x005eb790`):

1. Alloc 0x10 / tag `0x22` sphere shape; construct via `FUN_006c7fa0` (`PhysicsShape_Sphere_CtorFromRadius_Inferred`) with radius = **param_4**.
2. Build query-params block (`FUN_005eb8d0`) carrying shape + **param_6** filter/cookie + copy of input float4.
3. Alloc 0xD0 / tag `0x2C` query-collect; construct via parent **`FUN_005eb790`**.
4. Release shape refcount (dtor path if 0).
5. Register query on host physics: `FUN_0055ff20(*(param_1 + 0xE4A4), query)`.
6. Init hit triad vtbl `PTR_FUN_009ccbb4`, count 0, cap `0x80000010`.
7. Seed **out float4** = **in float4**; lift Y by `param_4 + DAT_00a0f298` (`0.5f`).
8. **Retry loop** (`param_7` as unsigned char countdown, `JA`):
   - `FUN_005eb130(query, out)` set probe pose.
   - `vcall(query, +0x30)(hit_triad)` collect.
   - If count == 0 → mark success (`found_clear`), force exit countdown.
   - Else clear triad; draw two ushort randoms via `FUN_007a4330` (decomp name `CVOGReaction_RandomUnitScalar`); scatter **X/Z** by `(u16 * scale − 1.0f) * param_3` with scale `_DAT_009cc4a8` ≈ `1/32768`; tiny Y nudge `param_3 * DAT_00aaa664` (~1e-4); re-sample height `FUN_004cd220(host, x, z) + param_4 + 0.5f` into out.Y.
9. If still blocked **and** `param_8 == 0` → restore out = original in.
10. Unregister `FUN_00560020`; release query refcount; destroy hit triad (`FUN_004eacc0`); free shape heap if owned.
11. **Return `AL = found_clear`** (true when a zero-hit probe succeeded).

Primary product path: `CVOGSpawnPoint_CreateCreature` / `CreateTemplateVehicle` fail with `"Couldn't find a spawn position for …"` when return is false. Role sealed by CF + caller strings; product method English open → **`_Inferred`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e9720` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals/completeness) |
| Assembly | `disassemble_function` full body — **not** `disassemble_bytes` |
| Bytes | `read_memory` 128 B @ entry + epilogue @ `0x004e9a80` |
| Constants | `read_memory` `0x00a0f298` / `0x00a0f2a0` / `0x00a0f518` / `0x009cc4a8` / `0x00aaa664` / vtbl `0x009ccbb4` |
| Callers / xrefs | `get_function_callers` (4) + `get_xrefs_to` (4 UNCONDITIONAL_CALL) |
| Call-site ABI | `get_assembly_context` on `005230ed`, `00564351`, `00565251`, `005cc917` |
| Parent dual | `A_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred` (call site `004e97fb`) |
| Shape dual | `A_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred` |
| Caller context | clean `CVOGSpawnPoint_CreateCreature` / `CreateTemplateVehicle` fail strings |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004e9720` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of residual callees (`0055ff20` / `00560020` / `005eb130` / `004cd220` / `004eacc0` / `005eb8d0`).

---

## 3. Signature

```c
bool __cdecl CVOGPhysicsUtils_FindClearSpawnPosition_Inferred(
    void *host /* [EBP+0x8]  — object with physics @ +0xE4A4; this for height sample */,
    float *in_pos /* [EBP+0xC]  — float4 xyzw */,
    float scatter_radius /* [EBP+0x10] — XZ random scale (spawn +0x9C) */,
    float sphere_radius /* [EBP+0x14] — sphere shape radius + Y lift pad */,
    float *out_pos /* [EBP+0x18] — float4 result */,
    uint32_t query_cookie /* [EBP+0x1C] — stored into query-params (often 0x14) */,
    unsigned char max_attempts /* [EBP+0x20] — loop countdown */,
    unsigned char keep_last_on_fail /* [EBP+0x24] — if 0 and still blocked, restore in */);
// bare RET; EAX/AL = found_clear
```

| Item | Evidence |
|---|---|
| Convention | `PUSH EBP; MOV EBP,ESP; AND ESP,0xFFFFFFF0; … RET` (no `RET n`) |
| Caller cleanup | all 4 sites `ADD ESP,0x20` after CALL → **8 stack dwords / cdecl** |
| Return | `SETZ BL` from still-blocked flag; `MOV AL,BL` before epilogue |
| Body size | **892 B** (`0x37C`); pad `CC` from `0x004e9a9c` |
| Parent ctor site | `CALL 0x005eb790` @ `0x004e97fb` (ECX=0xD0 alloc; stack=params) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame + stack align | **Yes** |
| Sphere alloc/ctor (`006c7fa0`, radius=param_4) | **Yes** |
| Query-params setup (`005eb8d0`) + float4 copy of in | **Yes** |
| Query-collect alloc 0xD0 + parent ctor `005eb790` | **Yes** |
| Shape release-on-zero-refcount | **Yes** |
| Register via `*(host+0xE4A4)` → `0055ff20` | **Yes** — **asm corrects decompiler** (param_1 used) |
| Hit triad init vtbl `009ccbb4` / cap `0x80000010` | **Yes** |
| Seed out + Y lift `radius + 0.5f` | **Yes** (`DAT_00a0f298`) |
| Loop: set pose → vcall+0x30 → empty=success else scatter+height | **Yes** |
| Random scale `_DAT_009cc4a8`; one=`0x00a0f2a0`; w-nudge zero=`0x00a0f518` | **Yes** (`read_memory`) |
| Height `FUN_004cd220` is **thiscall on host** | **Yes** — asm `MOV ECX,[EBP+8]; CALL 004cd220` |
| Restore-on-fail when `param_8==0` | **Yes** |
| Unregister `00560020` + query release + triad dtor + free | **Yes** |
| Return `!still_blocked` in AL | **Yes** |

### Decompiler corrections (required)

1. **`param_1` is live**, not dead: used as host for `+0xE4A4` physics register/unregister and as **ECX** for `FUN_004cd220`.
2. Random helper is **`FUN_007a4330`** (asm); decomp display name `CVOGReaction_RandomUnitScalar` is a Ghidra rename — treat as random ushort source, not reaction product API.
3. `g_flOne` / `g_flZero` in decomp map to `0x00a0f2a0` (=1.0f) / `0x00a0f518` (=0.0f).

### Constants sealed

| VA | Value | Role |
|---|---|---|
| `DAT_00a0f298` | `0.5f` | Y lift pad |
| `DAT_00a0f2a0` | `1.0f` | random unit bias |
| `DAT_00a0f518` | `0.0f` | W component scale |
| `_DAT_009cc4a8` | ≈ `1/32768` | ushort→[0,2) scale |
| `DAT_00aaa664` | ≈ `1e-4` | tiny Y nudge × scatter |
| Hit vtbl | `0x009ccbb4` | triad collector |

### Callers (4 UNCONDITIONAL_CALL)

| Site | Function | Notes |
|---|---|---|
| `0x00565251` | `CVOGSpawnPoint_CreateCreature` | fail string spawn position / radius |
| `0x00564351` | `CVOGSpawnPoint_CreateTemplateVehicle` | same pattern; sphere pad `5.0f` |
| `0x005230ed` | `FUN_00522f70` | `ADD ESP,0x20` |
| `0x005cc917` | `FUN_005cc7f0` | `ADD ESP,0x20` |

### Callees (named)

`FUN_006c7fa0`, `FUN_005eb8d0`, `FUN_005eb790` (parent), `FUN_0055ff20`, `FUN_005eb130`, `FUN_007a4330`, `FUN_004cd220`, `FUN_00560020`, `FUN_004eacc0`, plus allocator vcalls on `DAT_00b05060` (+0x10 alloc / +0x14 free).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + cdecl + bare RET + 8 stack args | **High** | disasm + 4× `ADD ESP,0x20` |
| Return bool = found clear placement | **High** | `SETZ` + caller fail strings |
| Sphere + query-collect probe role | **High** | shape dual + parent dual + vcall+0x30 |
| Host `+0xE4A4` physics register path | **High** | asm at `004e981e` / `004e9a17` |
| Scatter / height-resample retry | **High** | loop body sealed |
| Product class `CVOGPhysicsUtils::*` English | **Med** | family by sibling strings; **no** plate in this body → `_Inferred` |
| Exact meaning of `param_6` cookie `0x14` | **Low–Med** | stored into query-params only |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB method name (no embedded string in body).
2. Exact type of `host` beyond `+0xE4A4` physics and height-sample thiscall.
3. Semantic English of `param_6` query cookie / filter.
4. Residual duals: register/unregister, set-pose, height sample, triad dtor.
5. Runtime Confirmed / differential.

**Verdict:** **accept-with-gaps** — ABI/CF/callers/probe algorithm High; product English + cookie + residual callees open.
