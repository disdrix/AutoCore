# Review A (reconstruction fidelity): `aa_004b18f0` ObjectMotion_SyncChildPoseHF_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b18f0` |
| **VA** | `0x004b18f0`–`0x004b1a56` (358 B / `0x166`) |
| **Canonical name** | `ObjectMotion_SyncChildPoseHF_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b18f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-F) |
| **Counterpart** | `reviews/B_aa_004b18f0_ObjectMotion_SyncChildPoseHF_Inferred.md` |
| **System** | client object motion / reaction slot child pose |
| **Verdict** | **accept-with-gaps** — CF + ABI + HF/constants sealed; nested matrix helper English + basis triple runtime open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Optional **child world-pose sync** after motion integrate / emitter spawn:

- Gate on stack **flag ≠ 0**.
- Nested matrix setup on `*(slot+8)+0x34` (`FUN_00973820` / `FUN_00973690(0.75,…)` / `FUN_006a3db0` → `+0x37`).
- Copy slot `+0x10/+0x18/+0x2c` → child.
- Heightfield Y via sealed `CVOGMap_SampleHeightfieldY`; slope-scale basis triple; add slot pos; lift Y by ≈**0.04**.

Evidence: caller `ObjectMotion_SlotTick_Inferred` (W26-H) invokes after `ObjectMotion_IntegrateStep_Inferred` when `slot[2]≠0`; second call site `FUN_005bc120` @ `0x005bc335`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b18f0` |
| Bounds | `get_function_by_address` → `004b18f0`–`004b1a56` |
| Entry/exit bytes | `read_memory` @ `0x004b18f0`, `0x004b1a40` |
| Constants | `0x3f400000=0.75`, `DAT_00aaa8f4≈0.04`, `DAT_00afdef0`, `DAT_00b03530` triple image 0 |
| Callers | `FUN_004b4620` @ `0x004b48f7`; `FUN_005bc120` @ `0x005bc335` |
| Peer dual | `ObjectMotion_SlotTick_Inferred` (W26-H); `CVOGMap_SampleHeightfieldY` |
| Raw / annotated / clean | W27-F updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of nested matrix helpers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b18f0`–`004b1a56` (358 B) | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 4`** (`C2 04 00`) | **Confirmed** | epilogue `read_memory` |
| Flag early-out | **Confirmed** | `test edi,edi; jz` |
| Child = `*(slot+8)` pose writes | **Confirmed** | decomp ≡ raw |
| Heightfield = `FUN_004cd220` | **Confirmed** | named peer |
| Y lift ≈0.04 / 0.75 imm | **Confirmed** | `read_memory` / imm |
| Basis triple runtime value | **Open** | image static 0 |
| Nested matrix helper English | **Open** | not OWN |
| Product method name | **Inferred** | `_Inferred` |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Flag gate | Yes |
| Matrix helpers order | Yes |
| Byte write child+0x37 | Yes |
| Three-dword slot→child copy | Yes |
| HF sample slot XZ | Yes |
| Basis load / scale / add | Yes |
| Y += DAT_00aaa8f4 | Yes |
| Epilogue ret 4 | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `ObjectMotion_SlotTick_Inferred` | `0x004b48f7` | after integrate; push flag; `mov ecx,esi` |
| `FUN_005bc120` | `0x005bc335` | emitter / reaction path |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product English of `FUN_00973820` / `FUN_00973690` / `FUN_006a3db0` and fields `+0x10/+0x18/+0x2c/+0x34/+0x37`.
3. Runtime fill of `DAT_00b03530` triple (image zero — divide uses Y).
4. Runtime golden for FPU path.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, HF peer, and constants; nested matrix English + basis runtime residual.
