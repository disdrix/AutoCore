# Review A (reconstruction fidelity): `aa_0048eb10` PalantirEnv_TearDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048eb10` |
| **VA** | `0x0048eb10`–`0x0048eb99` exclusive (**137 B** / `0x89`) |
| **Canonical name** | `PalantirEnv_TearDefaultLights_Inferred` |
| **Prior scaffold** | `FUN_0048eb10` |
| **Review date** | `2026-07-29` (W34-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` |
| **System** | client / Palantir env default lights |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + `get_function_xrefs` + `read_memory_bytes`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Rebuild-safe **tear** of Palantir env default lights at `+0x104` / `+0x108`, with optional Reflect residual notify via `+0xC4` → `FUN_005b3580`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x0048eb10` ≡ 2026-07-23 raw CF |
| Bytes | full body hex; `56 8B F1` … `5E C3`; jmp `005b3580` |
| Bounds | Ghidra body `0048eb10`–`0048eb98`; exclusive end **`0048eb99`** |
| Callers | RebuildDefaultLights; Sector dtor `00492be0`; orphan `0091e1d7` (env via `+0xE894`) |
| Related | W32-R rebuild; W33-T Reflect enable/slots; light size 0x94 |
| Raw / clean | `aa_0048eb10_*`, `PalantirEnv_TearDefaultLights_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 137 B / bare RET / thiscall | **Confirmed** | bytes |
| Slots +0x104 / +0x108 / +0xC4 | **Confirmed** | peers + bytes |
| Manager this = env+4 | **Confirmed** | `mov ecx,[esi+4]` before 0074e* |
| Asymmetric dir path (0074e0d0 first) | **Confirmed** | decompile + bytes |
| Reflect tail ECX=child | **Confirmed** | `mov ecx,[esi+0xC4]` before jmp |
| 0074e* product English | **Open** | residual |
| Runtime / differential | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
tear hemi +0x104 (unregister, dtor1, null)
tear dir  +0x108 (clear attach0, unregister, dtor1, null)
if +0xC4: FUN_005b3580(reflect); return
```

| Stage | Match |
|---|---|
| Two light slots then optional Reflect | Yes |
| Dir-only 0074e0d0(0) | Yes |
| Bare ret void | Yes |

---

## 5. Gaps / open

1. Product English for manager ops `FUN_0074e260` / `FUN_0074e0d0`.
2. Orphan call site `0x0091e1d7` function bounds.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, light slots, Reflect tail, primary callers; manager product residual.
