# Review A (reconstruction fidelity): `aa_005bc3c0` Emitter_UpdateTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc3c0` |
| **VA** | `0x005bc3c0`–`0x005bdce6` exclusive |
| **Body** | **6438** bytes / `0x1926` |
| **Canonical name** | `Emitter_UpdateTick_Inferred` |
| **Ghidra name** | `FUN_005bc3c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-I) |
| **Counterpart** | `reviews/B_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` |
| **System** | client::fx / emitter |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/xrefs + HostTick site |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-frame **emitter host update** for NDSpecialFX HostTick list `+0x1E0`:

1. Bump tick counters; optional object-death pose snapshot.
2. Hard-stop / primary countdown early-outs (return keep=1).
3. Early remove conditions (return keep=0).
4. Pose refresh (object phys / skybox-UI / attachment quat paths).
5. Offset compose, motion integrate, optional interval spawn via `Emitter_SpawnOnIntervalTick`.
6. Clear first-frame flag; return keep=1 on fallthrough.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | full body @ `0x005bc3c0` (~690 lines) |
| Bounds | `get_function_by_address` → `005bc3c0`–`005bdce5` (inclusive end byte of `ret 0x0C`) |
| Entry / exit bytes | `read_memory` @ `0x005bc3c0`, `0x005bdce0` |
| Constants | `DAT_00a10e74`=2.0, `DAT_00aaa668`=-1.0, `DAT_00af3f70`=-10.0 |
| Caller | HostTick @ `0x004b90ef` (bytes push3 + `mov ecx,payload` + call) |
| Child dual | `Emitter_SpawnOnIntervalTick_Inferred` W26-I |
| Raw / annotated / clean | W28-I updated |

**Not performed:** Launcher, runtime golden, full nested-helper duals, bit-exact recompile.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = emitter*; stack float* dt, int host_field_2c, int camera_or_world;
// RET 0x0C; return 0=remove, 1=keep
uint32_t Emitter_UpdateTick_Inferred(int *emitter, float *dt, int a, int b);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (HostTick `mov ecx, payload`) | **High** |
| dt | Stack arg0 | **High** |
| host_field_2c | Stack arg1 (`[esi+0x2c]`) | **High** |
| camera_or_world | Stack arg2 | **High** |
| cleanup | `RET 0x0C` | **High** |
| keep polarity | AL/EAX 0\|1 vs HostTick | **High** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| Counter bump | **Yes** | **High** |
| Stop flag +0x7ff → keep | **Yes** | **High** |
| Countdown +0x810 → keep | **Yes** | **High** |
| Early kill → 0 | **Yes** | **High** |
| Pose branches (object/skybox/attach) | **Yes** | **High** (structure); **Medium** (every expression) |
| Interval spawn child when empty list | **Yes** | **High** |
| Exit clear +0x7fe; return 1 | **Yes** | **High** |
| Sole HostTick caller | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 6438 B / ret 0x0C | **Confirmed** | `read_memory` |
| Keep 0/1 HostTick contract | **Confirmed** | caller decompile + site |
| Emitter family + string | **Confirmed** | `"Emitter found at 0,0,0…"` |
| Interval child linkage | **Confirmed** | W26-I |
| Product English | **Inferred** | `_Inferred` |
| Clean line-exact all math | **Medium** | staged clean; raw authority |
| Runtime | **Open** | |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Full product flag dictionary for `+0x989` / `+0x98a` / `+0x98d`.
3. Nested helpers not dualed here (`FUN_005b83e0`, `FUN_005bb1f0`, …).
4. Staged clean is CF map, not full expression dump — raw remains authority for bit-level port.
5. Runtime multi-path golden.

**Verdict:** **accept-with-gaps** — ABI + keep contract + stage CF + family sealed; full pose-expression bit-exact and product English residual.
