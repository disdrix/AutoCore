# Review A (reconstruction fidelity): `aa_0059db80` CVOGObjective_ProbeEligibilityCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059db80` |
| **VA** | `0x0059db80`–`0x0059dc40` |
| **Canonical name (Ghidra)** | `FUN_0059db80` |
| **Proposed name** | `CVOGObjective_ProbeEligibilityCode_Inferred` |
| **Review date** | `2026-08-05` (MEGA-091 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0059db80_CVOGObjective_ProbeEligibilityCode_Inferred.md` |
| **System** | `missions-progression` (partition parent `0x0059dc50` eligibility gate) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Objective **thiscall** nested eligibility / tracker-category probe:

1. Default code = `*(objective+0x120)`; if `-1`, `*(*(objective+0x14c)+0xfc)`.
2. Inline pending CNDHash lookup at `character+0x55c` by key `*(objective+0x10)`.
3. Pending miss → return default.
4. Walk evaluators `[objective+0x158, +0x15c)`:
   - `vtbl+0x8(character, pendingValue*)`; if **false** and `vtbl+0x58()` ∉ `{0, −1}`, return that code.
5. Else return default.

Parent gate `FUN_0059dc50` fails when return `== -1`. Tracker UI matches return to widget `+0x110`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0059db80` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/locals) |
| Assembly | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Bytes | `read_memory` 192 B @ entry — hex seal + `CC` pad to `0x0059dc50` |
| Callers / xrefs | `get_function_callers` (4) + `get_xrefs_to` (4 UNCONDITIONAL_CALL) |
| Parent call site | `disassemble_function` `FUN_0059dc50` @ `0x0059dc75` `CMP EAX,-1` |
| UI callers | decompile `FUN_008a5240` / `008a2670` / `008a2df0` (category vs `+0x110`) |
| Sibling contrast | dualed `CVOGObjective_MatchTargetEvaluators` (`+0x40`); `CVOGCharacter_IsObjectiveReady` (`+0x8` AND) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0059db80` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledgers, dual of other VAs.

---

## 3. Signature

```c
int __thiscall CVOGObjective_ProbeEligibilityCode_Inferred(
    void *objective /* ECX */,
    void *character /* stack */);
// RET 4; EAX = code
```

| Item | Evidence |
|---|---|
| Convention | `MOV EBX,ECX` entry; stack load `[ESP+0x14]` after 4 pushes; all exits `RET 4` (`c2 04 00`) |
| Body size | 193 B (`0xC1`); pad `CC` before `FUN_0059dc50` |
| Return type | int EAX (not void; Ghidra signature noise rejected) |
| Direct callees | none (leaf re: named); virtual only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Default `+0x120` / fallback `def+0xfc` | **Yes** |
| Inline hash mask/bucket/chain by `obj+0x10` | **Yes** |
| Pending miss → return default | **Yes** |
| Eval walk `[+0x158,+0x15c)` | **Yes** |
| `+0x8` false ∧ `+0x58`∉{0,−1} → return override | **Yes** |
| Exhausted / empty → default | **Yes** |
| Three `RET 4` epilogues | **Yes** |

### Layout (sealed)

| Off | Role |
|----:|------|
| `obj+0x10` | id / hash key |
| `obj+0x120` | default code |
| `obj+0x14c` | def* → `+0xfc` fallback |
| `char+0x55c` | pending CNDHash* |
| `obj+0x158`/`+0x15c` | evaluator** range |
| eval `+0x8` / `+0x58` | progress eval / code override |

### Call-site samples

| Site | ECX / arg | Follow-on |
|---|---|---|
| `0x0059dc75` `FUN_0059dc50` | ECX=objective ESI; push character EDI | `CMP EAX,-1` → ineligible |
| `0x008a546d` `FUN_008a5240` | thiscall on objective; `DAT_00d1b6d8` char | store as category; match UI `+0x110` |
| `0x008a2703` `FUN_008a2670` | same global char | category vs widget `+0x110` |
| `0x008a3029` `FUN_008a2df0` | same | category vs `*piVar9+0x110` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + body bounds | **High** | bytes + disasm + decompile identical |
| Pending hash at `char+0x55c` | **High** | mission family + inline CNDHash shape |
| Eval slots `+0x8` / `+0x58` | **High** | `CALL [EDX+8]` / `CALL [EDX+0x58]` |
| Role = nested eligibility/category probe | **High** | parent −1 gate + UI category consumers |
| Name `CVOGObjective_*_Inferred` | **High (role)** / product English **Open** | |
| Reject Named_VOG_DEBUG_STOP identity | **High** | string only on unrelated hash paths |
| Distinct from MatchTarget / IsObjectiveReady | **High** | different slots / ABI / return shape |
| Product code enum English | **Open** | `_Inferred` hygiene |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps (do not block dual seal)

1. Product/PDB method name and English for code fields (`+0x120`, `def+0xfc`, `+0x58`).
2. Full evaluator implementer matrix for `+0x8`/`+0x58`.
3. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — control flow, ABI (`thiscall` **RET 4**), pending-hash probe, evaluator override path, and caller contracts sealed statically. Product English for the returned code remains open → `_Inferred`.
