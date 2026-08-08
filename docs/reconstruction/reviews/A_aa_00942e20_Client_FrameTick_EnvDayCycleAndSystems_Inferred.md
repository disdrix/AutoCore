# Review A (reconstruction fidelity): `aa_00942e20` Client_FrameTick_EnvDayCycleAndSystems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00942e20` |
| **VA** | `0x00942e20`–`0x009430f0` exclusive (**720 B** / `0x2D0`) |
| **Canonical name** | `Client_FrameTick_EnvDayCycleAndSystems_Inferred` |
| **Ghidra symbol** | `FUN_00942e20` |
| **Review date** | `2026-08-04` (WQ9H-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` |
| **System** | client frame / environment day-cycle parent |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `disassemble_function` + `read_memory` (entry/epilogue, floats, strings) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Parent frame of dualed `Env_DayCycle_ApplySkyBlendAndLight_Inferred`: main-client per-frame path that clamps dt, drives env day-cycle sky blend when world root is live, then runs fog/system/list/primary ticks and a one-shot load-time debug print.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9H-G append) | `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FrameTick_EnvDayCycleAndSystems_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00942e20.cpp` |
| Live body / RET | `disassemble_function` + `read_memory` @ `0x009430ef` → **`C3`** |
| Floats | `DAT_00a0f70c`=0.2f; `DAT_00af9120`=0.01f; `DAT_00af911c`=1.0f |
| Dualed child | `aa_004912c0` Env_DayCycle_ApplySkyBlendAndLight (WQ9G-F) |
| Caller | `FUN_0094b520` @ `0x0094b865` (`xref_count=1`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 720 B; bare **`RET`** | **Confirmed** | bounds + epilogue `C3` |
| **EDI** = host (register this) | **Confirmed** | entry `MOV EAX,EDI`; body uses EDI throughout |
| Return 0 success / 1 gate fail | **Confirmed** | early `MOV EAX,1` / final `XOR EAX,EAX` |
| dt clamp to 0.2f | **Confirmed** | `COMISS` vs `DAT_00a0f70c` bytes |
| Sky blend: ECX=`*([host+0xe04]+0xe894)`, push dt, `CALL 004912c0` | **Confirmed** | disasm `0x00942e6e`–`0x00942e75` |
| Sole caller main frame `FUN_0094b520` | **Confirmed** | xrefs + context |
| Product host/class English | **Tentative** | `_Inferred` |
| Undualed helper English | **Open** | many callees |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate fail → 1 | Yes |
| dt = min(time+0x30, 0.2) | Yes |
| Optional env day-cycle apply | Yes (ECX path sealed by disasm) |
| System/fog/list/primary sequence | Yes |
| One-shot load-time OutputDebugStringA | Yes |
| return 0 | Yes |

---

## 5. Naming

| Candidate | Ruling |
|---|---|
| `FUN_00942e20` | Scaffold only |
| `Env_DayCycle_ApplySkyBlendAndLight` (this VA) | **Reject** — that is child `0x004912c0` |
| Combat / skill frame | **Reject** — env + fog + load-time strings; parent of sky blend |
| `Client_FrameTick_EnvDayCycleAndSystems_Inferred` | **Accept** — role High via caller + dualed child + strings; English Inferred |

---

## 6. Gaps

1. Product / PDB client host class name.  
2. Gate `FUN_0092e510` and most undualed callees.  
3. Exact type of `host+0xe04` world root vs env at `+0xe894`.  
4. List element type at `host+0xd24`.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
