# Review A (reconstruction fidelity): `aa_00518cf0` Skill_LookupActiveCastBinding

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518cf0` |
| **VA** | `0x00518cf0` |
| **Canonical name** | `Skill_LookupActiveCastBinding` |
| **Review date** | `2026-07-23` (dual residual strengthen `2026-07-29`; ABI/ECX re-seal same day) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00518cf0_Skill_LookupActiveCastBinding.md` |
| **Residual scratch** | `reviews/a_00518cf0.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Read-only lookup of the **active-cast binding** for a skill id. Fills a **16-byte TFID** out-buffer from the binding map node value (`node+0x18…+0x24`), or copies the invalid TFID sentinel `g_abTfidInvalid_9CDF88` (`0x009cdf88` = `(-1,-1,0,0)`) when unbound. Map shell is lazy-got via leave-FUN `FUN_00518c20` (`owner+0x68`); find is `FUN_0051c150` (int key @ `node+0x10`). **Entry ECX** is the map owner (same host as the getter’s `this`). Shared cast-lock query used by LocalCastValidate, RequestCast, ResolveCastTarget sticky gate, status-effect paths, and related helpers.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00518cf0_Skill_LookupActiveCastBinding.md` |
| Annotated | `docs/reconstruction/raw/aa_00518cf0_Skill_LookupActiveCastBinding.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_LookupActiveCastBinding.cpp` |
| Function record | `docs/reconstruction/functions/aa_00518cf0_Skill_LookupActiveCastBinding.md` |
| Fresh re-decompile | Ghidra `0x00518cf0` (2026-07-29 residual) |
| Body bytes | `read_memory` `0x00518cf0` len 0x80 — epilogues `C2 08 00` (ret 8) both arms |
| Pcode | Ghidra basic/high @ body; call chain `00518d00` → `00518d07` → `00518d0e` |
| Sentinel memory | `read_memory` `0x009cdf88` / `0x00a15870` |
| Map getter dual | `reviews/A\|B_aa_00518c20_FUN_00518c20.md` (leave-FUN) |
| Find helper | `FUN_0051c150` live decompile |
| Callers | 8 functions / 9 UNCONDITIONAL_CALL sites (xref list re-verified) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack formals `(pOutTfid16, nSkillId)` | **Confirmed** | Stack[+4]/[+8]; void return |
| `__stdcall` stack cleanup | **Confirmed** | both exits `ret 8` @ `0x00518d3d` / `0x00518d65` (byte residual) |
| Entry **ECX = mapOwner** | **Confirmed** | prologue `mov esi, ecx`; both `FUN_00518c20` use ESI |
| Map owner **product type** | **Open** | register role sealed; type shared leave-FUN open |
| Lookup by skill id (map key) | **Confirmed** | `FUN_0051c150` key @ `node+0x10`; callers pass `skill+0x5fc` / packet skill id |
| Find hit = exact key match | **Confirmed** | lower_bound + `key <= skillId` keep filter ≡ equality |
| Hit: copy 4 dwords `node+0x18…+0x24` → out | **Confirmed** | decompile + `add ecx,0x18` dword block |
| Out layout = **TFID16** (not larger bind struct) | **Confirmed** | residual seal; consumers use TFID compare helpers |
| Miss: copy `g_abTfidInvalid_9CDF88` | **Confirmed** | body loads `0x009cdf88…0x009cdf94` only |
| Sentinel bytes `FFFFFFFF FFFFFFFF 00000000 00000000` | **Confirmed** | `read_memory` |
| End test `it != *(map+4)` (`_Myhead`) | **Confirmed** | `cmp ecx,[eax+4]` |
| Map via `FUN_00518c20` (`owner+0x68`, 0xC header) | **Confirmed** | 2 call sites; sibling dual |
| Decompiler multi-arg `FUN_00518c20(pTmp,key)` | **Noise Confirmed** | stack pushes are for following `FUN_0051c150` |
| `FUN_0051c150` = map find (not insert) | **Confirmed** | callee body |
| Read-only (no map mutate) | **Confirmed** | callees get+find only |
| Creates / always-binds | **Falsified** | lookup only |
| `DAT_00a15870` is the active-cast map | **Falsified** | twin invalid TFID constant; same static bytes |
| Body fill uses `A15870` | **Falsified** | fill = `9CDF88` only |
| Callers use `A15870` for NotEquals/Equals | **High** | ResolveCastTarget / RequestCast residual |
| Shared by validate / request / sticky / status / summon | **Confirmed** | 8 callers / 9 sites |
| Cast-again HB policy lives in **callers** | **High** | plate overstates body responsibility |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ body bytes

| Stage | Match |
|---|---|
| Preserve entry ECX as mapOwner (ESI) | Yes (bytes) |
| Get map (`FUN_00518c20` ×2) | Yes (noise on first site args in decompiler) |
| Find by skillId (`FUN_0051c150`) | Yes |
| Hit: 16-byte value copy | Yes |
| Miss: invalid sentinel copy (`9CDF88` only) | Yes |
| `ret 8` both arms | Yes |
| No invent insert / cast start / HB start | Yes |

### Recovered CF (noise-corrected)

```c
// Entry: ECX = mapOwner (product type OPEN)
//        Stack[+4] = pOutTfid, Stack[+8] = nSkillId
// Exit:  ret 8  (__stdcall)
void Skill_LookupActiveCastBinding(/*ECX mapOwner,*/ void *pOutTfid, int nSkillId)
{
  pMap = FUN_00518c20(mapOwner);          // 0x00518d00, again 0x00518d0e
  FUN_0051c150(pMap, &it, &nSkillId);     // exact find; key @ node+0x10
  if (it != *(int *)(pMap + 4)) {
    *(u32*)(pOut+0x0) = *(u32*)(it+0x18);
    *(u32*)(pOut+0x4) = *(u32*)(it+0x1c);
    *(u32*)(pOut+0x8) = *(u32*)(it+0x20);
    *(u32*)(pOut+0xc) = *(u32*)(it+0x24);
  } else {
    copy16(pOut, g_abTfidInvalid_9CDF88);
  }
}
```

---

## 5. Callers (inventory)

| Caller | Site(s) | Role |
|---|---|---|
| `Skill_LocalCastValidate` | `0x0051a83d` | unbound → free power/CD/range ladder; site sets ECX=`this` |
| `Client_RequestCastSkill` | `0x009416e4`, `0x00941762` | unbound → cast-again HB / FX |
| `Client_Skill_ResolveCastTarget` | `0x0093b759` | sticky form: **bound** → silent invalid list |
| `Client_StanceOrGadgetActivatePath` | `0x0093a4de` | cast-again gate |
| `Skill_ApplyStatusEffectLocal` | `0x0051ab1c` | local status path |
| `Client_RecvSkillStatusEffect` | `0x00811496` | S2C 0x2031 |
| `FUN_00521650` / summon HB | `0x005216a7` | summon path |
| `FUN_00525cc0` | `0x00525d4a` | packet-side helper |

---

## 6. Gaps / open

1. Product type of map **owner** (entry ECX / `+0x68` / twin `+0x6c` host) — leave-FUN sibling residual. **Register sealed.**
2. Product name for `FUN_0051c150` (map find) and `FUN_0058d9c0` (node factory).
3. Full node schema beyond key `+0x10` + TFID `+0x18…+0x24` (Clear may compare more fields — separate unit).
4. Runtime capture / bit-exact image diff.
5. Dual invalid globals always equal at runtime (static image match only).

**Gaps closed this residual chain:** out-struct = TFID16; `DAT_00a15870` map-identity **falsified**; `__stdcall ret 8` **Confirmed**; entry ECX mapOwner **Confirmed**.

**Verdict:** **accept-with-gaps**
