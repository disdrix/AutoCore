# Review A (reconstruction fidelity): `aa_0058d8e0` Skill_HB_ApplyMultiArgEffect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d8e0` |
| **VA** | `0x0058d8e0`–`0x0058d95d` |
| **Canonical name (Ghidra)** | `FUN_0058d8e0` |
| **Proposed name** | `Skill_HB_ApplyMultiArgEffect_Inferred` |
| **Review date** | `2026-08-05` (MEGA-009 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **skill-HB multi-arg combat effect** wrapper: null-check an object, build a **single-target TFID list** from `object+0x160` plus the global null terminator (`DAT_009d4d28..`), then call dualed **`Skill_ApplyMultiTargetHits_Inferred`** (`0x0058c850`). Returns total damage.

Not target gather, not heat/HP/shield delta leaves, not the multi-hit core itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0058d8e0` |
| Complete analyze | `analyze_function_complete` (worker; 1 callee; 4 xrefs) |
| Bytes | `read_memory` 128 B @ entry; 32 B @ `0x009d4d28` |
| Disasm | `disassemble_function` (full body; **not** `disassemble_bytes`) |
| Meta | `get_function_by_address` body `0058d8e0`–`0058d95d` |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` → 4 sites |
| Call-site | `get_assembly_context` @ `0061b8f9`, `0061866e`, `0061e922`, `0061ea7b` |
| Parent | `decompile_function` `FUN_0061b6f0` + dual record `CVOGHBSkill_SharedOnHeartBeat_Inferred` |
| Callee dual | `Skill_ApplyMultiTargetHits_Inferred` (W20-Q) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0058d8e0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, dual of `FUN_00618270` / orphan region.

---

## 3. Signature

```c
int Skill_HB_ApplyMultiArgEffect_Inferred(
    void *combatSource,         // param_1
    void *objectWithTfidAt160,  // param_2 (null-checked)
    void *damageEffectBlob,     // param_3
    uint32_t unusedParam4,      // param_4 (forwarded; multi-hit unused)
    void *rollTable,            // param_5
    int rollSeedIndex);         // param_6
// __cdecl; bare ret; EAX = damage sum
```

| Item | Evidence |
|---|---|
| Convention | bare `ret` (`c3`) both exits; callers `ADD ESP,0x18` |
| 6 formals | stack layout + 6 pushes at parent; multi-hit also 6-arg cdecl |
| Body size | `0x7E` = 126 B inclusive; pad `CC CC` before `0x0058d960` |
| Offset `+0x160` | `add eax, 0x160` then 4 dword loads |
| Terminator | loads `DAT_009d4d28..34` = `ffffffff ffffffff 00000000 00000000` |
| Sole callee | `CALL 0x0058c850` + `ADD ESP,0x18` |
| Return | EAX pass-through from multi-hit; early path EAX = param_2 (=0) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null `param_2` → early bare ret | Yes |
| Copy 16 B from `param_2+0x160` | Yes |
| Append 16 B null TFID from globals | Yes |
| Call multi-hit with `(p1, &list, p3, p4, p5, p6)` | Yes |
| Clean 0x18 + free locals + bare ret | Yes |
| Decompile CF ≡ 2026-07-23 raw | Yes (live re-verify append) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 126 B / bare ret / cdecl 6 | **High** | disasm + bytes + callers |
| Single-target TFID list wrapper | **High** | +0x160 copy + terminator sealed |
| Forwards to dualed multi-hit apply | **High** | sole CALL `0058c850` |
| Parent gate bit0 @ skill `+0x648` | **High** | assembly context @ `0061b8f9` |
| Return = damage sum | **High** | multi-hit returns int; orphan sites FILD EAX |
| Product English name | **Tentative** | `_Inferred`; partition hint matches role |
| param_1/param_2 product roles | **Probable** | parent pack sealed; English residual |
| Full orphan-site parent CF | **Open** | no Ghidra function on 2 xrefs |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Exact product English for combat-source vs hittee object roles.  
3. Dual of sibling pulse `FUN_00618270` and orphan region containing `0061e922`/`0061ea7b` (not OWN).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/list-build/callee/4 xrefs High; product English and residual parent packing English open.
