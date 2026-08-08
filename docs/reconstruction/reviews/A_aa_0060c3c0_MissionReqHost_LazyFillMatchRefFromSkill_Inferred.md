# Review A (reconstruction fidelity): `aa_0060c3c0` MissionReqHost_LazyFillMatchRefFromSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c3c0` |
| **VA** | `0x0060c3c0` |
| **Body** | `0x0060c3c0`–`0x0060c3fc` exclusive (**60 B** / `0x3C`); pad `CC` |
| **Canonical name** | `MissionReqHost_LazyFillMatchRefFromSkill_Inferred` |
| **Review date** | `2026-08-05` (R11-010 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0060c3c0_MissionReqHost_LazyFillMatchRefFromSkill_Inferred.md` |
| **System** | skills-abilities / missions-progression |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/harvest/free sealed; product English residual |

---

## 1. Purpose

Mission **reqHost** helper: if match-ref field `+0x44` is still the unset sentinel **−1**, materialize a temporary ranked skill runtime from `skillId@+0x10` + `rank@+0x14`, copy template/match id and template-mode flag into the host, free the temporary. Used by escort HB ctor before seeding `escort.targetMatchRef` / `matchByObjRefMode`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x0060c3c0)` 2026-08-05 |
| Body bounds / mnemonics | `analyze_function_complete` + `disassemble_function` |
| Image bytes | `read_memory` 64 B @ `0x0060c3c0` → ends `83 C4 04 5E C3 CC…` |
| Call site | parent disasm `0x00650825`–`0x00650846` (`MOV ECX,EDI; CALL`) |
| Callee dual | `A_aa_0054c570_CVOGReaction_ResolveSkillTargets` |
| Skill field dual | `aa_00620480` SkillDef `+0x22` / `+0x14c` |
| Escort consumer | `CVOGHBMissionEscort_ctor` clean field map |
| Raw / clean / record | `raw/`, `reconstructed-exact/`, `functions/aa_0060c3c0_*` |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 60 B; plain `RET`; pad `CC` | **Confirmed** | image |
| ABI `__thiscall` ECX=reqHost; no stack args | **Confirmed** | entry `MOV ESI,ECX`; caller `MOV ECX,EDI` |
| Gate `CMP [ESI+0x44],-1` / early out | **Confirmed** | asm |
| Args to Resolve: skillId `+0x10`, rank word `+0x14` | **Confirmed** | `MOV ECX,[ESI+0x10]; MOV AX,[ESI+0x14]; PUSH EAX; PUSH ECX` |
| Callee `0x0054c570` cdecl (`ADD ESP,8`) | **Confirmed** | |
| Null path leaves `+0x44` untouched (−1) | **Confirmed** | `TEST EAX; JZ exit` before stores |
| Store `skill+0x14c` → `reqHost+0x44` | **Confirmed** | `MOV EDX,[EAX+0x14c]; MOV [ESI+0x44],EDX` |
| Store `(skill+0x22!=0)` → `reqHost+0x48` | **Confirmed** | `CMP byte [EAX+0x22],0; SETNZ CL; MOV [ESI+0x48],CL` |
| `operator_delete` then returns | **Confirmed** | `ADD ESP,4; POP ESI; RET` — decomp warning false |
| Sole caller escort ctor | **Confirmed** | 1 xref `00650835` |
| Name role (lazy match-ref fill) | **High** | escort field map + skill duals |
| Product/PDB symbol English | **Open** | keep `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `+0x44 == -1` | **Yes** |
| Push skillId + rank; call materialize | **Yes** |
| Null early out | **Yes** |
| Harvest `+0x14c` / `+0x22` | **Yes** |
| Free temporary; return | **Yes** (clean drops false “no-return”) |

Decompiler CF ≡ scaffold raw; ABI/arity corrected in clean via asm.

---

## 5. Sealed contract

```text
// __thiscall  ECX = reqHost
void MissionReqHost_LazyFillMatchRefFromSkill_Inferred(void* reqHost)
{
  if (*(int32*)(reqHost + 0x44) != -1) return;
  skill = CVOGReaction_ResolveSkillTargets(*(int*)(reqHost+0x10),
                                           (int)*(uint16*)(reqHost+0x14));
  if (!skill) return;
  *(uint32*)(reqHost + 0x44) = *(uint32*)(skill + 0x14c);
  *(uint8*)(reqHost + 0x48)  = (*(uint8*)(skill + 0x22) != 0);
  operator_delete(skill);
}
```

Escort ctor post-condition (consumer, not this body):
`escort+0x2c = reqHost+0x44`; `escort+0x30 = reqHost+0x48`.

---

## 6. Gaps

1. Product/PDB English for reqHost class and field dictionary.
2. Full product name for skill `+0x14c` beyond dualed “template id”.
3. Runtime capture / bit-exact / differential.

**Verdict:** **accept-with-gaps** — leaf CF/ABI/harvest sealed; English residual.
