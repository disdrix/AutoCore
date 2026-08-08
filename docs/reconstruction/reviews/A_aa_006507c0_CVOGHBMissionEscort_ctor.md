# Review A (reconstruction fidelity): `aa_006507c0` CVOGHBMissionEscort_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006507c0` |
| **VA** | `0x006507c0` |
| **Body** | `0x006507c0`–`0x006508c8` (**264 B** / `0x108`); pad `CC` |
| **Canonical name** | `CVOGHBMissionEscort_ctor` |
| **Review date** | `2026-08-04` (WQ9G-E dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006507c0_CVOGHBMissionEscort_ctor.md` |
| **System** | missions-progression / heartbeat |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, callers/xrefs, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — Escort identity + ctor CF/ABI/vtable/field seed sealed; reqHost English residual |

---

## 1. Purpose

`CVOGHBMissionEscort` constructor: base HB ctor, install Escort vtable, copy mission/match/range/zone fields from requirement host, attach owner, period **1000** ms, stamp client tick.

Primary factory: `FUN_0060c860` → `operator_new(0x78)` → this → `CVOGHBList_Enqueue` → `CVOGHBBase_Start`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `batch_decompile(0x006507c0)` 2026-08-04 |
| Body bounds | `get_function_by_address` → `006507c0`–`006508c8` |
| Entry/exit image | `read_memory` → SEH + `ret 8` |
| Vtable | `read_memory` `0x009e52c0`… methods as dualed OnHB |
| RTTI | COL `0x00ab1e9c` → TD `0x00af4a10` `.?AVCVOGHBMissionEscort@@` |
| OnHB dual | `A_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat` (ctor installs same vtable) |
| Factory | decompile `FUN_0060c860` |
| Raw / clean / record | `raw/`, `reconstructed-exact/`, `functions/aa_006507c0_*` |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class `CVOGHBMissionEscort` | **High** | RTTI TD string |
| Ctor role (vtable install + field seed) | **High** | decomp + bytes |
| ABI `__thiscall` / `ret 8` / returns this | **Confirmed** | exit `C2 08 00`; `mov eax,esi` |
| Vtable `PTR_FUN_009e52c4` | **Confirmed** | imm store |
| OnHB @ vtable+0x0C = `006508d0` | **Confirmed** | dword read + prior dual |
| Default TFID pad `{−1,−1,0,0}` @ +0x38 | **Confirmed** | DAT image |
| Period 1000 @ +0x08; tag `0x0b` @ +0x1C | **Confirmed** | imm stores |
| Field map vs OnHB dual | **High** | offsets align |
| Factory `FUN_0060c860` + alloc 0x78 | **High** | caller decomp |
| Second call site `00613e62` | **High** (bytes) / **Open** (enclosing FUN) | function gap |
| Product field English | **Probable** | shared with OnHB residual |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor + vtable install | **Yes** |
| Nested world/slot + TFID pad | **Yes** |
| reqHost seed + FUN_0060c3c0 | **Yes** |
| SetPeriod + AttachOwner + period overwrite | **Yes** |
| Stamp tick + return this | **Yes** |

---

## 5. Gaps

1. Product English for full reqHost field dictionary (partial via OnHB).
2. Enclosing function for call site `0x00613e62` (Ghidra gap after Kill_Precheck).
3. Deep C++ types for ownerCtx/reqHost.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — identity + ctor CF/ABI sealed; residual English/open second factory.
