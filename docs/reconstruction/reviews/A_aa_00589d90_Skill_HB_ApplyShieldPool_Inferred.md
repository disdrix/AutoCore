# Review A (reconstruction fidelity): `aa_00589d90` Skill_HB_ApplyShieldPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589d90` |
| **VA** | `0x00589d90`–`0x00589e5c` inclusive (**205 B** / `0xCD`) |
| **Canonical name** | `Skill_HB_ApplyShieldPool_Inferred` |
| **Ghidra name** | `FUN_00589d90` |
| **Prior scaffold** | `FUN_00589d90` clean twin (retained); no `Named_CalleeOf_*` scaffold present |
| **Review date** | `2026-08-05` (MEGA-007 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md` |
| **System** | skills-abilities |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `get_function_by_address` + parent/sibling decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Skill HB **shield-pool apply** leaf used by HB tick/apply parents:

```text
Skill_HB_ApplyShieldPool_Inferred(fallbackHost, preferredHost, amount) -> int delta
  resolve preferred (vtbl+0x19c → MI component) else +0xAC else fallbackHost
  pool = component->vtbl+0x1d4
  delta = amount in [-1,1] ? (int)(maxShield * amount) : (int)amount
  new = clamp(cur + delta, 0, max); store pool+0x144; return new-cur or 0
```

Partition hint `Skill_HB_ApplyShieldPool` matches sealed behavior; product symbol open → `_Inferred`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (resolve / fraction / clamp / return delta) |
| Full body | `disassemble_function` 68 insns + `read_memory` body + pad `CC` |
| Constants | `read_memory` `0x00aaa668` → `-1.0f`; `0x00a0f2a0` → `1.0f` |
| Call sites | `get_assembly_context` @ `0061b88f` / `006185fb` / `0061be96` |
| Field plate | matches `Vehicle_SetCurrentShield` (`+0x144` / `+0x148`) |
| Parents | `FUN_0061b6f0`, `FUN_00618270` decompiles (HB period × shield float) |
| Siblings | heat `00589bc0`, HP `00589c70` (contrast only) |

---

## 3. Signature (sealed)

```c
// cdecl; bare RET; EAX = applied delta
int Skill_HB_ApplyShieldPool_Inferred(
    int *fallbackHost,    /* [ESP+4]  */
    int *preferredHost,   /* [ESP+8]  */
    float amount);        /* [ESP+0xC] */
```

| Formal | Source | Conf |
|---|---|---|
| fallbackHost | stack `[ESP+4]`; used when preferred path fails | **Confirmed** |
| preferredHost | stack `[ESP+8]` → ESI early; primary resolve | **Confirmed** |
| amount | stack `[ESP+0xC]` → `MOVSS XMM0,[ESP+0x10]` after PUSH ESI | **Confirmed** |
| return | **EAX** int (`SUB EAX,ESI` delta or `XOR EAX,EAX`) | **Confirmed** |
| cleanup | bare **`RET`**; callers **`ADD ESP,0xC`** | **Confirmed** |
| thiscall | **no** — no ECX this in prologue | **Confirmed** |
| direct callees | **none** (virtual `CALL [EAX+imm]` only) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Preferred null test | `TEST ESI,ESI` / fall to param_1 | **Confirmed** |
| vtbl+0x19c resolve | `CALL [EAX+0x19c]` | **Confirmed** |
| MI component LEA | `LEA ECX,[EDX+EAX+4]` from `*( *(obj+4)+4 )` | **Confirmed** |
| Secondary `+0xAC` | `MOV ECX,[ESI+0xac]` | **Confirmed** |
| Fallback re-resolve | same `0x19c` + LEA path | **Confirmed** |
| Pool `vtbl+0x1d4` | `CALL [EAX+0x1d4]` | **Confirmed** |
| Fraction gate `[-1,1]` | `COMISS` vs `DAT_00aaa668` then `g_flOne` | **Confirmed** |
| Fraction mul | `CVTSI2SS max; MULSS amount; CVTTSS2SI` | **Confirmed** |
| Absolute trunc | `CVTTSS2SI EAX,XMM0` when outside band | **Confirmed** |
| Clamp [0,max] | probe/max tests; `XOR EAX,EAX` floor | **Confirmed** |
| Store current | `MOV [EDX+0x144],EAX` | **Confirmed** |
| Return delta | `SUB EAX,ESI` if changed else 0 | **Confirmed** |
| Decompile ≡ raw CF | live MEGA-007 re-verify | **Confirmed** |

---

## 5. Callers (evidence)

| Caller | Site | Usage note |
|---|---|---|
| `FUN_0061b6f0` | `0x0061b88f` | HB tick when shield float `this+0x144` ≠ 0; amount = period(`+0x6c4`) × field; packages via `FUN_00578270` stack leftover + PUSH EAX; **ADD ESP,0xC** |
| `FUN_00618270` | `0x006185fb` | Peer apply path; same period×`+0x144` packaging | 
| *(unbound)* | `0x0061be96` | `PUSH` trio then `CALL`; Ghidra has no enclosing function |

Parent gate (evidence only): `if ((float)param_1[0x51] != g_flZero)` at `0061b6f0` — index `0x51` = byte offset **0x144** on skill HB object (shield *amount field*, not pool current).

---

## 6. Naming decision

| Candidate | Decision |
|---|---|
| `Skill_HB_ApplyShieldPool_Inferred` | **accept** — apply + clamp + return delta on shield pool fields; parent is skill HB tick; product symbol open → `_Inferred` |
| `Skill_HB_ApplyShieldPool` (no suffix) | deferred — no string/RTTI on VA |
| `Vehicle_SetCurrentShield` | **reject** — that is `0x00419140` (set absolute, void, thiscall) |
| HP apply / heat apply | **reject** — different VAs / virtuals / callees |
| `Named_CalleeOf_0061b6f0_*` | **reject** — not used; no scaffold to retire |

---

## 7. Gaps

1. Product / PDB English for this helper.
2. English names for `vtbl+0x19c` and `vtbl+0x1d4`.
3. Bound owner of orphan site `0x0061be96`.
4. Full type of packaging helper `FUN_00578270` (out of OWN scope).
5. Runtime / bit-exact / differential (Terminal false; no Launcher).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed (cdecl RET + ADD ESP,0xC) | **Pass** |
| Shield field plate +0x144/+0x148 | **Pass** |
| Fraction band [-1,1] constants | **Pass** |
| Distinct from heat/HP siblings | **Pass** |
| Clean uses meaningful names | **Pass** |
