# Review A (reconstruction fidelity): `aa_004b7150` NDSpecialFX_DeactivateClear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7150` |
| **VA** | `0x004b7150`–`0x004b7320` (464 B / `0x1D0`) |
| **Canonical name** | `NDSpecialFX_DeactivateClear_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b7150` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-H) |
| **Counterpart** | `reviews/B_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX lifecycle |
| **Verdict** | **accept** — CF + ABI + layout gates sealed |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/callees + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

SpecialFX **host deactivate/clear**:

- Flush staged multi-target hits if `+0x3c` buffer present.
- Optional physics detach for owned children with `+0x90e bit7`.
- Mark all owned children destroy-pending (`+0x90e bit0`), unlink.
- Clear lists; stop sound payloads by name.

Evidence: shares `+0x3c` layout with dualed `NDSpecialFX_FlushStagedMultiHits_Inferred`; callers include FX destroy path `FUN_004b8ed0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b7150` |
| Entry/exit bytes | `read_memory` @ `0x004b7150`, `0x004b7300` |
| Callers | `FUN_004b8ed0`, `FUN_004fcc40`, `FUN_00516930`, `FUN_005a8ec0` |
| Parent dual | `A_aa_004b6980_NDSpecialFX_FlushStagedMultiHits_Inferred` |
| Sound dual | `A_aa_007203b0_CSoundManager_MarkStopByName_Inferred` |
| Raw / annotated / clean | W23-H updated |

**Not performed:** Launcher, runtime golden, bit-exact.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b7150`–`004b7320` | **Confirmed** | `get_function_by_address` |
| ECX this + plain `ret` | **Confirmed** | entry `8B F1`; exit `C3` |
| Flush when `+0x3c != 0` | **Confirmed** | decomp + sibling dual |
| Own list `+0x204`; flags `+0x90e` | **Confirmed** | decomp |
| Sound stop list `+0x1f8` | **Confirmed** | calls sealed MarkStopByName |
| Role = deactivate/clear (not spawn) | **High** | CF is teardown-only |
| Product method name | **Inferred** | `_Inferred` |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Multi-hit flush gate | Yes |
| Phys detach loop | Yes |
| Mark destroy + unlink | Yes |
| `FUN_004b6e00(0)` | Yes |
| Clear +0x1ec | Yes |
| Stop sounds + clear +0x1f8 | Yes |
| Walk +0x21c | Yes |
| Void return | Yes |

---

## 5. Gaps

1. Retail / PDB symbol.
2. Product types of list payloads.
3. Full dual of `FUN_004b6e00` / `FUN_00590f00` / `FUN_0058e300`.
4. Runtime golden.

**Verdict:** **accept** — sealed deactivate/clear CF, ABI, and layout gates; product name inferred.
