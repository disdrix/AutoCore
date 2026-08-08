# Review B (skeptical / adversarial): `aa_0060c3c0` MissionReqHost_LazyFillMatchRefFromSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c3c0` |
| **VA** | `0x0060c3c0` |
| **Canonical name** | `MissionReqHost_LazyFillMatchRefFromSkill_Inferred` |
| **Review date** | `2026-08-05` (R11-010) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0060c3c0_MissionReqHost_LazyFillMatchRefFromSkill_Inferred.md` |
| **System** | skills-abilities / missions-progression |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0060c3c0` only | Scaffold OK; under-describes sealed role |
| Escort member / `this` = escort HB | **Reject** — call site `MOV ECX,EDI` with EDI=reqHost; escort stores reqHost at `+0x6c` then calls |
| Target-list builder / TFID gather | **Reject** — callee is materialize dual (`0x630` clone), not `Skill_ResolveTargetList` |
| Permanent skill cache owner | **Reject** — always `operator_delete` on success path |
| Cast / apply skill effects | **Reject** — no cast/apply callees; harvest two fields only |
| Rank from phantom `in_EAX` high half | **Reject** — image loads rank from `[ESI+0x14]` |
| `operator_delete` noreturn / fatal | **Reject** — continues to `POP ESI; RET` |
| Product demangle proven | **Reject** — open; keep `_Inferred` |
| `MissionReqHost_LazyFillMatchRefFromSkill_Inferred` | **Accept** — role-aligned with escort field map; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler `__fastcall(int param_1)` is complete ABI | **Fails** — thiscall ECX; no stack cleanup beyond callee ADD ESP |
| Second arg of Resolve is garbage EAX high word | **Fails** — `MOV AX,[ESI+0x14]` before push |
| Always overwrites `+0x44` | **Fails** — gate skips when `!= -1` |
| On map miss zeros `+0x44`/`+0x48` | **Fails** — null path jumps to exit with no stores |
| Keeps skill runtime (no free) | **Fails** — `PUSH EAX; CALL operator_delete; ADD ESP,4` |
| Multiple callers / shared utility fan-out | **Fails** — sole xref `00650835` |
| `puVar1[0x53]` is index 0x53 of unrelated table | **Fails as misread** — dword index → byte `0x14c`; matches dualed skill template id |
| Partition “skills-abilities” means this is cast core | **Fails as overclaim** — system tag from materialize callee; consumer is escort reqHost seed |
| Wave parent `0x006507c0` is only structural parent | **Holds as sole live caller** — also partition parent |

---

## 3. Cross-check against raw + bytes

```text
PUSH ESI
MOV  ESI,ECX
CMP  [ESI+0x44],-1
JNZ  exit
MOV  AX,[ESI+0x14]          ; rank
MOV  ECX,[ESI+0x10]         ; skillId
PUSH EAX
PUSH ECX
CALL 0054c570               ; ResolveSkillTargets
ADD  ESP,8
TEST EAX,EAX
JZ   exit
MOV  EDX,[EAX+0x14c]
MOV  [ESI+0x44],EDX
CMP  byte [EAX+0x22],0
PUSH EAX
SETNZ CL
MOV  [ESI+0x48],CL
CALL 00489822               ; operator_delete
ADD  ESP,4
exit:
POP  ESI
RET
```

Caller `FUN_006507c0` @ `0x00650835`:
```text
MOV  ECX,EDI                ; reqHost
MOV  [ESI+0x6c],EDI
CALL 0060c3c0
MOV  EAX,[ESI+0x6c]
MOV  ECX,[EAX+0x44] → [ESI+0x2c]
MOV  DL,[EAX+0x48]  → [ESI+0x30]
```

Clean must **not** invent cast/TFID gather, permanent skill ownership, escort-`this`, or product demangle.

---

## 4. Agreement with Review A

- CF + ABI + harvest offsets + free: **agree Confirmed**
- Name with `_Inferred`: **agree**
- Gaps (PDB English, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Lazy fill reqHost match-ref from temporary skill clone
void LazyFillMatchRefFromSkill(ReqHost host)
{
    if (host.TargetMatchRef != -1) return;
    var skill = MaterializeSkillRuntime(host.SkillId, host.Rank);
    if (skill == null) return;
    host.TargetMatchRef = skill.TemplateOrMatchId;   // +0x14c
    host.MatchByObjRefMode = skill.IsTemplatePath;   // +0x22 != 0
    Free(skill);
}
// Native: thiscall ECX=host; sole site escort ctor before copying to HB +0x2c/+0x30
```

**Port note:** do not keep the 0x630 runtime; do not call from cast paths expecting target lists. Pair with dualed materialize `0054c570` and dualed escort ctor `006507c0`.

**Verdict:** **accept-with-gaps** — agree with A; adversarial claims above falsified.
