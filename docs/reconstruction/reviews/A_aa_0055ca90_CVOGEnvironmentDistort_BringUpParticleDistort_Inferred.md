# Review A (reconstruction fidelity): `aa_0055ca90` CVOGEnvironmentDistort_BringUpParticleDistort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ca90` |
| **VA** | `0x0055ca90`–`0x0055cc42` exclusive (**434 B** / `0x1B2`) |
| **Canonical name** | `CVOGEnvironmentDistort_BringUpParticleDistort_Inferred` |
| **Prior scaffold** | `FUN_0055ca90`; plate-ish `Gfx_NDParticleDistortBlendNormal` |
| **Review date** | `2026-08-04` (W37-J dual seal) |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W37-J Path A) |
| **Counterpart** | `reviews/B_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md` |
| **System** | client / VOGEnvironmentSector / CVOGEnvironmentDistort |
| **Dual status** | **Present (first dual seal)** — closes W33-T residual “product English for nested FUN_0055ca90” **partially** (structural + strings sealed; child class English open) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs + callee decompile. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Post-ctor **particle-distort child bring-up** for owned **`CVOGEnvironmentDistort`** (env`+0xC8`, size **0xA0**): allocate/bind 0x198 particle child at host`+0x90`, set particle params, load **Particle_Distort.dds** + **NDParticleDistortBlendNormal.fx**, bind **NormalMapTexture**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` @ `0x0055ca90` ≡ 2026-07-23 raw CF |
| Bytes | `read_memory` full **434 B** through `ADD ESP,0x20; RET` + `CC` pad |
| Bounds | exclusive end **`0x0055cc42`**; next `FUN_0055cc50` @ `0x0055cc50` |
| Host RTTI | enable wrapper W33-T: ctor vtbl `009d26ac` → COL → **`.?AVCVOGEnvironmentDistort@@`** |
| Caller | sole CODE `0x0055cc5f` in `CVOGEnvironmentDistort_Enable_Inferred` |
| Peer | `FUN_005b3420` Reflect child @ +0x158 (same 0x198 factory; no Particle_Distort strings) |
| Particle ctor | `FUN_00968a50` (W37-I partition) |
| Raw / clean | `aa_0055ca90_*`, named clean |

**Not performed:** Launcher, runtime enable, parent ledgers.

---

## 3. Algorithm (sealed)

1. SEH `LAB_009a4975`; snapshot `DAT_00d1f058→+0x2c→+0x80/+0x84`.
2. `operator_new(0x198)` + `FUN_00968a50` → **host+0x90**.
3. child`+0x195` \|= **0x40**; child`+4` = host.
4. Params (ECX=child): `0075b3b0(0.2f)`, `0075b390(500.f)`, `0075bf40(0xff808000)`, clear +0x180, `0075b450`, clear +0xEC, set +0x48/+0xCC.
5. Vcall child vtbl[+0x18](&snapshot).
6. child`+0x108`=0; child`+0x190`=1; host`+0x8C` ← child`+0x44`.
7. Binder scope: `Particle_Distort.dds` → `NDParticleDistortBlendNormal.fx` → `NormalMapTexture`/`0xff808000`.

Constants: `0x3e4ccccd`=**0.2f**, `0x43fa0000`=**500.0f**, `0xff808000` ARGB.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 434 B / plain ret / void | **Confirmed** | bytes |
| thiscall ECX=host | **Confirmed** | `MOV ESI,ECX` |
| Sole enable-path caller | **Confirmed** | xref |
| Host = CVOGEnvironmentDistort | **High** | RTTI on enable/ctor chain (W33-T) |
| Child size 0x198 + ctor `00968a50` | **Confirmed** | |
| Product strings dds/fx/param | **Confirmed** | body immediates |
| Float/color constants | **Confirmed** | |
| Child class product English | **Open** | vtbl `00aa22a8` residual |
| Binder object identity | **Open** | stack/host plumbing |
| Runtime / differential | **Open** | |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CVOGEnvironmentDistort_BringUpParticleDistort_Inferred` | **Accept** — host class Confirmed + particle-distort strings + sole Enable callee |
| `Gfx_NDParticleDistortBlendNormal` | **Reject** as sole id (misses host + dds) |
| Named_CalleeOf_Drive_NDRiver_fx | **Reject** |

---

## 6. Gaps / open

1. Product English for 0x198 particle child class.
2. Semantic name of host+0x8C field (mirror of child+0x44).
3. Full material-binder object contract (unowned callees).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, strings, constants, sole caller, host class linkage; child class English residual.
