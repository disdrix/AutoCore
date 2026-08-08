# Review A (reconstruction fidelity): `aa_005787a0` Skill_HB_RescheduleStatus_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005787a0` |
| **VA** | `0x005787a0`–`0x0057882d` inclusive (**142 B** / `0x8E`) |
| **Canonical name (Ghidra)** | `FUN_005787a0` |
| **Proposed name** | `Skill_HB_RescheduleStatus_Inferred` |
| **Review date** | `2026-08-05` (MEGA-004 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_005787a0_Skill_HB_RescheduleStatus_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent dual** | `CVOGHBSkill_SharedOnHeartBeat_Inferred` (`0x0061b6f0`) — residual leaf |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** — CF/ABI/RET4/RTTI/offsets/callers sealed; product field English + runtime open |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. Own VA only. No parent ledgers. No Launcher.

---

## 1. Purpose

Shared **skill HB reschedule + optional creature status gate/apply**:

1. If `short@this+0x2e == 0` → pure `CVOGHBBase_RescheduleAfterFire`.
2. Else resolve skill target TFID → `CVOGCreature` cast; if missing or creature `short@+0x12c < required` → `this.vtbl+0x40()` (stop) + write status **0x10** out (no AfterFire).
3. Else `creature.vtbl+0xb0(required)` then AfterFire.

Used as first step of dualed SharedOnHeartBeat and as standalone OnHB / vtbl method for thinner skill classes.

Not heat/HP/shield apply (those are sibling leaves `00589bc0`/`00589c70`/`00589d90`); not fire-tail FX (`00578b30`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x005787a0` — **≡** raw scaffold CF |
| Full analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/vars) |
| Assembly listing | `disassemble_function` — full body with operands |
| Bytes | `read_memory` `0x005787a0` length 142 — matches listing |
| Meta | `get_function_by_address` body `005787a0`–`0057882d` |
| Callers | `get_function_callers` (5 named) |
| Xrefs | `get_function_xrefs` (UNCONDITIONAL_CALL + DATA vtbl) |
| Call-site ctx | `get_assembly_context` parent `0061b6fd` + thin OnHB tails |
| RTTI | `read_memory` `0x00af8d0c` / `0x00af8e10` → Creature / ClonedObjectBase |
| Status dword | `read_memory` `DAT_00af31e8` = **0x10**; `DAT_00af4bd0` = **0x10** |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, dual of callees.

---

## 3. Signature

```c
uint32_t * __thiscall Skill_HB_RescheduleStatus_Inferred(
    void *thisHb, uint32_t *pOutStatus);
// ret 4; EAX = pOutStatus
```

---

## 4. Sealed residuals

### 4.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| ECX → ESI this | `PUSH ESI; MOV ESI,ECX` @ `005787a0` |
| Stack out-param only | fail: `[ESP+8]` after one push; success: `[ESP+0xc]` after ESI+EDI |
| Both exits `RET 4` | `C2 04 00` @ `00578814` and `0057882b` |
| EAX = pOutStatus | `MOV EAX,EDI` / fail path leaves EAX=out |
| Body size | `005787a0`–`0057882d` = **142 B** |

### 4.2 Status gate — **SEALED**

| Fact | Evidence |
|---|---|
| Required short `this+0x2e` | `CMP word ptr [ESI+0x2e],0` / `MOV CX,[ESI+0x2e]` |
| Zero → skip creature path | `JZ 00578803` → AfterFire |
| Creature compare `+0x12c` | `CMP word ptr [EAX+0x12c],CX` |
| Fail on null or `creature < required` | `TEST/JZ` + `JL` → `00578817` |
| Fail writes `*pOut = [DAT_00af31e8]` | `MOV ECX,[00af31e8]; MOV [EAX],ECX` |
| Fail value **0x10** | `read_memory` `af31e8` → `10 00 00 00` |
| Fail calls `this.vtbl+0x40` | `MOV EAX,[ESI]; CALL [EAX+0x40]` |
| Fail **skips** AfterFire | no call to `00508350` on fail path |

### 4.3 Resolve + apply — **SEALED role**

| Fact | Evidence |
|---|---|
| TFID `+0x658/+0x65c/+0x660` | loads before ResolveObjectTarget |
| Manager `+0x688` → ctx `+0xe4e8` | `MOV EAX,[ESI+688]; MOV ECX,[EAX+e4e8]` |
| Resolve `0x004bae70` | `CALL 0x004bae70` |
| Cast to Creature RTTI | push `af8d0c` / `af8e10`; strings `.?AVCVOGCreature@@` / `.?AVCVOGClonedObjectBase@@` |
| Apply `creature.vtbl+0xb0(required)` | `PUSH ECX; MOV ECX,EAX; CALL [EDX+0xb0]` |
| AfterFire `0x00508350` | success/zero path only |

### 4.4 Call graph — **SEALED**

| Kind | Targets |
|---|---|
| Callers (named) | `0061b6f0`, `0061c940`, `0061d400`, `00621980`, `00622a70` |
| Extra CALL xrefs | `0061f90a`, `00624d2c`, `00626b6d`, `00626b88`, `00626ba7` |
| DATA vtbl | many `009d0xxx` / `009e5310` |
| Callees | ResolveObjectTarget, RTDynamicCast, vtbl+0xb0, vtbl+0x40, RescheduleAfterFire |

### 4.5 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw scaffold 2026-07-23 | baseline CF |
| Live re-decompile 2026-08-05 | **≡** raw branches |
| Assembly / bytes | **≡**; ABI corrections applied in clean |

---

## 5. Naming

| Name | Status |
|---|---|
| `Skill_HB_RescheduleStatus_Inferred` | **Structural inferred** (reschedule + status gate/apply) |
| `FUN_005787a0` | scaffold alias retained |
| PDB / product English | **Open** (`_Inferred`) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body / RET 4 / thiscall | **High** | disasm + bytes + meta |
| Offset map absolute | **High** | assembly immediates |
| RTTI Creature cast | **High** | type_info strings |
| Fail → stop + status 0x10 | **High** | fail path sealed |
| Role under SharedOnHB | **High** | parent dual + call-site |
| `vtbl+0xb0` product verb | **Inferred** | apply/set status structural |
| `+0x2e` / `+0x12c` English | **Open** | no plate/string |
| Runtime | **Open** | no Launcher |

---

## 7. Gaps

1. Product design English for required short / creature field / `vtbl+0xb0`.
2. Exact Stop contract of `this.vtbl+0x40` (shared base vs override).
3. Whether `DAT_00af31e8` and `DAT_00af4bd0` / default period 16 are intentional aliases.
4. Complete RTTI census of DATA vtbl hosts installing this slot.
5. Runtime / bit-exact / differential — open.

---

## 8. AutoCore port notes

- Port as **thiscall RET 4** helper: optional creature status gate then `RescheduleAfterFire`.
- Fail path must **not** call AfterFire; must write status **0x10** so SharedOnHB skips effect cascade.
- Use absolute offsets; do not trust Ghidra `CVOGHBBase` array overlay past base size.
- Keep distinct from heat/HP/shield apply leaves and fire-tail FX.

**Verdict:** **accept-with-gaps**
