# Annotated low-level: Skill_ValidateTargetForSkill (`aa_00553650`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **VA** | `0x00553650` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00553650_Skill_ValidateTargetForSkill.md` (capture 2026-07-23; asm pass 2026-07-29) |
| **Status** | **human-refined** (assembly-backed ABI; dual A/B **accept** — residual 2026-07-29: all callers + outFlags orthogonality) |

---

## 1. Corrected signature

```c
// thiscall: ECX = skill runtime
// MSVC stdcall-style RET 8 (two stack formals)
int /*bool low AL*/ __thiscall Skill_ValidateTargetForSkill(
    void* this,            // skill runtime (has handler at +0x5F0)
    void* pTargetObj,      // target entity/object (NOT "pSkill")
    void* bNotifyHBFlag);  // low byte used; 0 or 1 at known call sites
// returns AL: 1 = valid/accept, 0 = rejected
```

| Formal | Decompiler name | Corrected role | Evidence |
|---|---|---|---|
| `this` (ECX) | this | **Skill runtime** | Handler load `this+0x5F0`; call sites pass skill / `param_1+9` skill blob |
| stack0 | `pSkill` | **Target object** | Passed as first handler arg; TFID read from it at callers; list mgr at `+0xB0` |
| stack1 | `pTarget` | **Notify/HB flag** (low byte) | Packed into listener ctx at `+9`; sites use `0` or `1` |

Plate “`(skill, targetObj)`” matches **roles** once formals are swapped from the decompiler names.

---

## 2. Body (assembly-faithful)

```c
// 1) Primary handler gate (third arg always 0 here)
handler = *(void**)(this + 0x5F0);
rc = handler->vtbl[0x44/4](pTargetObj, this, 0);

if (rc == 1) {
    return 0;   // reject — no listener walk
}

// 2) Accept path: walk target's HB list with skill-HB predicate
ctx.target   = pTargetObj;          // +0
ctx.skill    = this;                // +4
ctx.result   = 1;                   // +8  default accept
ctx.notifyHB = (uint8_t)bNotifyHBFlag; // +9

listMgr = *(void**)((uint8_t*)pTargetObj + 0xB0);
FUN_004e2600(/*this=*/listMgr,
             /*predicate=*/Skill_ValidateTarget_HBSkillListener, // 0x005532E0
             /*ctx=*/&ctx,
             /*flag=*/0);

return (int)ctx.result;  // AL = ctx.result (listener may clear to 0)
```

---

## 3. Return polarity (**Confirmed**)

| Path | Wrapper `AL` | Callers |
|---|---:|---|
| Handler returns **1** | **0** (reject) | Skip cast / skip attach |
| Handler ≠ 1, no listener reject | **1** (accept) | Proceed |
| Listener sets `ctx.result=0` | **0** | Reject after HB probe |

**Caller evidence (Confirmed):**

| Call site | Parent | Test | On nonzero |
|---|---|---|---|
| `0x005789F3` | `CVOGHBSkillBase_ctor` | `(char)rc != 0` | AttachOwner + arm period |
| `0x0057C976` / `0x0057CA3C` | `CVOGReaction_Dispatch` case **0xC** | `TEST AL` / `JZ` skip | cast / TFID collect |
| `0x005D1882` | `NPC_TryCastSkillFromSet` | `(char)rc != 0` after resolve+range | `CastSkillOnTarget` |
| `0x00606EB6` | `Outpost_CastSkillsForFaction` | `(char)rc != 0` | Append TFID + cast |
| `0x00607285` / `0x006074F2` | `Outpost_CastSkillsForBeaconShare` | `TEST AL` / `JZ` | Append TFID + cast |

Wrapper polarity matches plate: **1 = valid, 0 = rejected**.  
Earlier scaffold that inverted plate vs body was **wrong** (assumed handler `1` = valid without callers).

**outFlags:** this unit writes none. NPC path may have filled ResolveTargetList flags earlier; those bits are orthogonal to this bool gate.

### Handler vtbl+0x44 result codes (from listener + gate)

| Handler EAX | Meaning (as used here) | Confidence |
|---:|---|---|
| `1` | Reject / invalid target | **Confirmed** (gate + listener) |
| `2` | Accept; may notify HB via vtbl+0x18 | **High** (listener only) |
| other ≠1 | Pass primary gate; HB walk may still fail | **High** |

---

## 4. Field map

| Offset | Object | Role |
|---|---|---|
| `skill+0x5F0` | skill runtime | Pointer to handler / element object with vtable |
| handler vtbl `+0x44` | method | Target legality: `(target, skill, hbOrZero)` |
| `target+0xB0` | target entity | Listener / HB list manager (`FUN_004e2600` this) |
| HB `+0x1C` | list node payload | Must be `1` for listener to consider |
| HB `+0x20` | `CVOGHBSkillBase` | Skip if nonzero (busy/disabled **Probable**) |

---

## 5. Side effects

1. Virtual call on skill handler (`+0x5F0` / vtbl `+0x44`) with `(target, skill, 0)`.
2. On non-reject: `FUN_004e2600` thiscall on `target+0xB0` with predicate `Skill_ValidateTarget_HBSkillListener`.
3. Listener may re-call same handler with **HB** as third arg; on result `2` + flag, `hb->vtbl+0x18(1,0)`.
4. List nodes matching predicate may be unlinked/destroyed by `FUN_004e2600` (generic list util).
5. No direct stores to skill fields in the wrapper itself.

**Not** a user-facing “error toast” on reject — that plate sentence is **rejected**. Reject is silent return 0.

---

## 6. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| Formal names `pSkill`/`pTarget` | stack0=**target**, stack1=**flag** | **Confirmed** (asm + callers) |
| Two-arg handler call | Three-arg `(target, skill, 0)` | **Confirmed** |
| `FUN_004e2600` free args | thiscall `target+0xB0` | **Confirmed** |
| `LAB_005532e0` | `Skill_ValidateTarget_HBSkillListener` | **Confirmed** (created + string/RTTI) |
| Plate “feedback on reject” | Listener walk on **accept** path | **Confirmed** |
| Plate “1 if valid” | **Holds** for wrapper `AL` | **Confirmed** (callers) |
| `CONCAT31(...,1)` | Return **ctx.result** byte (default 1) | **Confirmed** |

---

## 7. Related residual / renamed

| VA | Name | Evidence |
|---|---|---|
| `0x005532E0` | `Skill_ValidateTarget_HBSkillListener` | Sole predicate; RTTI `CVOGHBSkillBase`; string `"Skill found with no base class: %d"` |
| `0x00606D70` | `Outpost_CastSkillsForFaction` | `"Invalid outpost skill cast for skill %d, map: %s"`; calls ValidateTarget |
| `0x006070E0` | `Outpost_CastSkillsForBeaconShare` | same string; beacon-ratio caller |

Still open: concrete C++ type of `skill+0x5F0` handler; exact CNDDoubleList product method name (beyond `_Inferred`); HB vtbl+0x18 identity.  
**Sealed residual:** unbound xrefs → Dispatch case 0xC + BeaconShare second site; outFlags non-writer.

---

## 8. Open questions

1. Catalog of handler implementations at vtbl+0x44 (per skill family).
2. Exact semantics of HB `vtbl+0x18(1,0)` on accept with notify flag.
3. Whether player quick-bar path ever calls this unit (currently NPC / outpost / reaction type 0xC / skill-HB ctor).
