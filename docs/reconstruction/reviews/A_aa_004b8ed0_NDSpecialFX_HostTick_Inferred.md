# Review A (reconstruction fidelity): `aa_004b8ed0` NDSpecialFX_HostTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **VA** | `0x004b8ed0`–`0x004b9240` (880 B / `0x370`) |
| **Canonical name** | `NDSpecialFX_HostTick_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b8ed0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W24-C) |
| **Counterpart** | `reviews/B_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| **System** | client-fx / NDSpecialFX lifecycle |
| **Verdict** | **accept-with-gaps** — CF + ABI + gates sealed; nested free residual + product name open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

SpecialFX **host tick**:

- Rate-limit / type-switch gate on stamp `+0xd0` and event type `+0x28`.
- Liveness probe `FUN_004b7330`; fail → sealed `NDSpecialFX_DeactivateClear_Inferred` + return **1**.
- Active: update param-map transforms; camera-distance cull; tick live owned children via sealed `CVOGObject_Tick`; free destroy-pending under profile `"Destroy"`.
- Residual lists `+0x1e0` / `+0x210` / `+0x21c`; notify `FUN_004b6910`; return **0**.

Evidence: shared `+0x204` / `+0x90e` layout with dualed DeactivateClear; sole known caller of `CVOGObject_Tick`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b8ed0` |
| Entry/exit bytes | `read_memory` @ `0x004b8ed0`, `0x004b8f00`, `0x004b9220` |
| Cull constant | `DAT_009cb2b0` ≈ 1e-6 |
| Callers | `FUN_004ba290`, `004fc400`, `00516de0`, `005a9040`, `0097b540` |
| Peer duals | `NDSpecialFX_DeactivateClear_Inferred`, `CVOGObject_Tick` |
| Raw / annotated / clean | W24-C updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of every nested list free helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b8ed0`–`004b9240` | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 4`** | **Confirmed** | epilogue `C2 04 00` |
| Return AL 0 / 1 | **Confirmed** | `32 C0` / `B0 01` paths |
| Rate gate `cmp 0x1388` / `jbe` ≡ `< 0x1389` | **Confirmed** | `read_memory` @ `0x004b8f00` |
| Type switch on `+0x28` | **Confirmed** | decomp + jump table setup |
| DeactivateClear on fail path | **Confirmed** | call + W23-H dual |
| Child tick = `CVOGObject_Tick` | **Confirmed** | W23-H dual + sole caller note |
| Cull float `DAT_009cb2b0` ≈ 1e-6 | **Confirmed** | `read_memory` |
| Product method name | **Inferred** | `_Inferred` |
| operator_delete residual edges exact | **Probable** | decomp noreturn warnings |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH + counter +0x154 | Yes |
| Rate gate vs +0xd0 | Yes |
| Type switch / case 4 re-enter | Yes |
| Stamp +0xd0 on active | Yes |
| Liveness `FUN_004b7330` | Yes |
| DeactivateClear → return 1 | Yes |
| UpdateParamMapTransforms | Yes |
| Camera / cull gate | Yes |
| Own-list tick / Destroy free | Yes |
| Residual lists + notify | Yes |
| Active return 0 | Yes |
| Epilogue ret 4 | Yes |

---

## 5. Callers

| Caller | Sites | Notes |
|---|---|---|
| `FUN_004ba290` | `0x004ba2a9` | |
| `FUN_004fc400` | `0x004fc441` | |
| `FUN_00516de0` | ×3 | |
| `FUN_005a9040` | ×2 | |
| `FUN_0097b540` | `0x0097b653` | |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product English of event type enum at `+0x28`.
3. Full dual of `FUN_004b7330` / `FUN_004b6a80` / `FUN_004b6910` list residual.
4. Exact semantics of `DAT_00b03e64` override on cull.
5. Runtime golden.

**Verdict:** **accept-with-gaps** — sealed host-tick CF, ABI, rate/type gates, and deactivate linkage; product name + nested free residual open.
