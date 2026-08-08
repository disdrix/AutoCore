# Review A (reconstruction fidelity): `aa_004912c0` Env_DayCycle_ApplySkyBlendAndLight_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004912c0` |
| **VA** | `0x004912c0`–`0x0049146a` exclusive (**426 B**) |
| **Canonical name** | `Env_DayCycle_ApplySkyBlendAndLight_Inferred` |
| **Ghidra symbol** | `FUN_004912c0` |
| **Review date** | `2026-08-04` (WQ9G-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md` |
| **System** | environment / sky / day-cycle |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` (body, floats, epilogue) + callers/xrefs + dualed callee plates. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Sole env day-cycle consumer of dualed `WorldClock_GetSkyBlendAmount_Inferred` and `WorldClock_GetQuarterPhase01_Inferred`. Applies stored sky blend to SkyBox materials and remaps quarter phase by clock mode into light-curve inputs.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-F re-verify) | `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004912c0_FUN_004912c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Env_DayCycle_ApplySkyBlendAndLight_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004912c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md` |
| Live body / epilogue | `read_memory` @ `0x004912c0`, `0x00491450` → **`C2 04 00`** |
| Floats | `g_flOne` @ `0x00a0f2a0` = 1.0; `DAT_00aaa6c0` ≈ 1/3; `DAT_00aaa684` ≈ 2/3 |
| Dualed leaves | `aa_00553cd0`, `aa_00553dd0` (WQ9F-J / prior dual) |
| Material strings | via `FUN_00490af0` / `FUN_00490820`: `SkyBox*`, `fBlendAmount`, `DiffuseTexture` |
| Caller | `FUN_00942e20` @ `0x00942e75` (`xref_count=1`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 426 B; `mov esi,ecx`; **`ret 4`** | **Confirmed** | bounds + epilogue bytes |
| ECX = env host | **Confirmed** | field uses `+0xb8/+0x180/+0x90/+0x94/...` |
| Stack arg present, unread in body | **High** | `ret 4` + caller push; no stack load in CF |
| Sky blend from `00553cd0` → `00490af0` | **Confirmed** | call order + dual plate |
| Mode@clock+0x154 cases 0..3 with 1/3,2/3 | **Confirmed** | switch + constant bytes |
| Dirty `+0x90` clear after blend≥1 texture path | **Confirmed** | CF + `mov byte [esi+0x90],0` |
| Product env/clock class English | **Tentative** | `_Inferred` |
| Light helper semantics | **Open** | undualed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Default blend 1.0 if no clock / no light host | Yes |
| GetSkyBlend + GetQuarterPhase + mode remap | Yes |
| Light apply trio | Yes |
| Secondary vtbl sink @ +0x188 | Yes |
| Material dirty + optional texture + clear flag | Yes |
| `ret 4` | Yes (bytes; decomp plate often omits) |

---

## 5. Naming

| Candidate | Ruling |
|---|---|
| `FUN_004912c0` | Scaffold only |
| `Env_DayCycle_ApplySkyBlendAndLight_Inferred` | **Accept** — role High via dualed getters + SkyBox strings; English Inferred |
| Skill / combat tick names | **Reject** — no combat xrefs; env frame caller only |

---

## 6. Gaps

1. Product / PDB env host and clock mode field names.  
2. Writers of clock `+0x15c` / `+0x154`.  
3. Light helpers + secondary object dual open.  
4. Dead stack dt product intent.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
