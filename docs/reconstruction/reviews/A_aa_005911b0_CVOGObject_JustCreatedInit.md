# Review A (reconstruction fidelity): `aa_005911b0` CVOGObject_JustCreatedInit

| Field | Value |
|---|---|
| **Stable ID** | `aa_005911b0` |
| **VA** | `0x005911b0`–`0x00593233` (8324 B / `0x2083`) |
| **Canonical name** | `CVOGObject_JustCreatedInit` (structural; product/PDB open) |
| **Ghidra name** | `FUN_005911b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W22-H) |
| **Counterpart** | `reviews/B_aa_005911b0_CVOGObject_JustCreatedInit.md` |
| **System** | client object / physics-gfx spawn finalize |
| **Verdict** | **accept-with-gaps** — phase CF + ABI + gates sealed; flag dictionary / deep physics formulas residual |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/callees + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Just-created** finalize for a client world object (`this`):

- Apply pending pose/orientation onto gfx body.
- Optional skybox particle rebind, ragdoll bind, rigidbody construction (incl. multi-body), `addEntity`.
- Mode `1` (batch) vs `0` (tick deferred); return **1** done / **0** abort.

Evidence: profiler root `"Just created"`; callers batch-set `@+0x910 bit0` after mode=1.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function records | `functions/aa_005911b0_FUN_005911b0.md`, `…_CVOGObject_JustCreatedInit.md` |
| Raw | `raw/aa_005911b0_FUN_005911b0.md` (+ W22-H live seal) |
| Annotated | `raw/aa_005911b0_FUN_005911b0.annotated.md` |
| Clean phase | `reconstructed-exact/CVOGObject_JustCreatedInit.cpp` |
| Clean full | `reconstructed-exact/FUN_005911b0.cpp` |
| Live decompile | full ~924 lines @ `0x005911b0` |
| Entry/exit bytes | `read_memory` @ `0x005911b0`, `0x0059320b` |
| Callers | `FUN_00594290`, `FUN_00595230` |
| Constant | `DAT_00aaa638` = ≈1/65535 |

**Not performed:** Launcher, runtime golden, bit-exact, deep dual of each nested callee.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `005911b0`–`00593233` | **Confirmed** | `get_function_by_address` |
| `__thiscall` + stack `char` + **`ret 4`** | **Confirmed** | epilogue `C2 04 00`; `mov al,1` |
| Return **1** at `LAB_0059320b` | **Confirmed** | decomp + bytes |
| Return **0** on early `FUN_004a7a20` path | **Confirmed** | decomp |
| Done-latch `@+0x910 bit0` early → return 1 | **Confirmed** | `param_1[0x244]` byte &1; caller ORs bit |
| Profiler `"Just created"` root | **Confirmed** | first call |
| Nested phases skybox/ragdoll/rigidbody/addEntity | **Confirmed** | strings + `FUN_0076cf00` |
| Mode semantics batch=1 / tick=0 | **High** | sole callers |
| `DAT_00aaa638` = 1/65535 | **Confirmed** | `read_memory` float |
| Full flag dictionary `@+0x90c..` | **Tentative** | partial from decomp gates |
| Every RB formula bit-exact | **Open** | large body; phase-sealed only |
| Product class name | **Inferred** | CVOG object family |
| Clean full ≡ live line-for-line | **High** for scaffold mirror; phase twin is contract-only |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist (phase)

| Stage | Match |
|---|---|
| SEH + profile open | Yes |
| Latch skip → ret 1 | Yes |
| mode0 soft-skip → ret 0 | Yes |
| Pending→active pos copy | Yes |
| Gfx pose / skybox / FX | Yes (flag-gated) |
| Ragdoll once | Yes |
| Rigidbody + addEntity | Yes (flag-gated) |
| Epilogue ret 1 | Yes |

---

## 5. Callers

| Caller | Site | Mode | Notes |
|---|---|---|---|
| `FUN_00594290` | `0x005942a4` | **1** | batch; then `@+0x910 \|= 1` |
| `FUN_00595230` | `0x00595d07` | **0** | if 0 return, tick aborts |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Exhaustive bit dictionary for soft flags.
3. Line-level audit of multi-RB impulse math (decomp present, not dual-sealed as separate units).
4. Runtime golden.

**Verdict:** **accept-with-gaps** — sealed as Just-created finalize with ABI, latch, mode, phase map; residual detail in nested physics.
