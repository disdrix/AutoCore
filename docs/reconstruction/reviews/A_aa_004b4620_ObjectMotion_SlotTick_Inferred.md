# Review A (reconstruction fidelity): `aa_004b4620` ObjectMotion_SlotTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4620` |
| **VA** | `0x004b4620`–`0x004b490d` (749 B / `0x2ED`) |
| **Canonical name** | `ObjectMotion_SlotTick_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b4620` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W26-H) |
| **Counterpart** | `reviews/B_aa_004b4620_ObjectMotion_SlotTick_Inferred.md` |
| **System** | client object motion / reaction slot |
| **Verdict** | **accept-with-gaps** — CF + ABI + constants + integrate linkage sealed; nested helper English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Per-slot **outer tick** for an object-motion / reaction entity:

- Profiler `*(DAT_00d17958+0x13c)++`.
- Early **0** on host gate (`+0x98c` bit `0x40` with `+0x7f9`/`+0x7fa`).
- **Radius pull** when slot leaves host sphere (`host+0x980`): target `+0x880..888`, Y damp `0.4`/`−0.5`, normalize, scale `≈0.99`, optional heightfield Y.
- Duration `slot[0x5c] −= dt`; secondary timer when `host+0x7fb`.
- Nested sealed `ObjectMotion_IntegrateStep_Inferred` (`FUN_004b1100`) after `FUN_004b2b90`.
- Return **1** keep / **0** remove (sole caller `FUN_005bb5e0` unlinks on 0).

Evidence: sole caller of dualed integrate at `0x004b48e8`; W24-C named this site as entity/slot tick feed.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b4620` |
| Bounds | `get_function_by_address` → `004b4620`–`004b490d` |
| Entry/exit bytes | `read_memory` @ `0x004b4620`, `0x004b48e0` |
| Constants | `0x00a0f720=0.4`, `0x00aaa6cc=−0.5`, `0x009c8354≈0.99` |
| Callers | `FUN_005bb5e0` @ `0x005bb611` |
| Peer dual | `ObjectMotion_IntegrateStep_Inferred` (W24-C) |
| Raw / annotated / clean | W26-H updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of every nested helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b4620`–`004b490d` (749 B) | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 8`** (`C2 08 00`) | **Confirmed** | epilogue `read_memory` |
| Return AL 0 / 1 | **Confirmed** | early `32 C0` / success `B0 01` |
| `param_2` is int flag (bit-cast float) | **Confirmed** | first use `(int)param_2` |
| Radius constants 0.4 / −0.5 / ≈0.99 | **Confirmed** | `read_memory` |
| Nested integrate = `FUN_004b1100` | **Confirmed** | callees + W24-C dual |
| Heightfield = `FUN_004cd220` | **Confirmed** | named peer |
| Product method name | **Inferred** | `_Inferred` |
| Nested helper English (`004b0f80`/`2b90`/`18f0`) | **Open** | out of OWN |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Profiler ++ | Yes |
| Host early abort | Yes |
| Radius outside sphere test | Yes |
| Pull / Y damp / normalize / 0.99 | Yes |
| Heightfield Y bit4 path | Yes |
| Duration countdown + `004b0f80(1)` | Yes |
| Secondary timer `+0x7fb` | Yes |
| `004b2b90` → `004b1100` → optional `004b18f0` | Yes |
| Clear byte `+0x240` / return 1 | Yes |
| Epilogue ret 8 | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_005bb5e0` | `0x005bb611` | list at host`+0xa24`; return 0 → unlink + delete node |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product class of motion slot (reaction entity? FX particle slot?).
3. Full dual of `FUN_004b0f80` / `FUN_004b2b90` / `FUN_004b18f0` / `FUN_0076f5f0`.
4. Runtime golden for radius pull FPU path.

**Verdict:** **accept-with-gaps** — sealed outer-tick CF, ABI, constants, and integrate linkage; nested helper product names open.
