# Review A (reconstruction fidelity): `aa_0052b420` CVOGCharacter_IsMissionTurnInReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b420` |
| **VA** | `0x0052b420` |
| **Canonical name** | `CVOGCharacter_IsMissionTurnInReady` |
| **Ghidra name** | `FUN_0052b420` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** on last-objective / active-hash / readiness gates; **accept-with-gaps** on product names of `FUN_0052a020` + evaluator type enum |

---

## 1. Purpose

Client **turn-in readiness** predicate used by `Client_ShowNpcMissionDialogUI` (and interact helpers) to decide claim/chrome path:

1. Select the mission’s **last objective** from def array.
2. Require that objective id is present in the character’s **active-objectives hash** with non-null payload.
3. Require objective-complete eval (`FUN_0052a020(..., flag=1)`).
4. If an NPC object is supplied, require every type-**3** evaluator on that last objective targets this NPC’s clonebase id; otherwise skip the NPC filter.

Returns **bool** (`AL`). **No stores.** Does not send packets.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_0052b420` @ `0x0052b420` (≡ raw CF) |
| Image bytes | `read_memory` `0x0052b420`–`0x0052b4d8` (`ret 8`; ECX+0x548) |
| Call-site framing | `read_memory` @ ShowNpc `0x00943a30`, `FUN_004d5c10` x2, `FUN_008a8770` `0x008a9370` |
| Raw | `docs/reconstruction/raw/aa_0052b420_FUN_0052b420.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b420_FUN_0052b420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_IsMissionTurnInReady.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| Callee (owned elsewhere) | `FUN_0052a020` @ `0x0052a020` live decompile |
| Primary caller dual | `A/B_aa_009438f0_Client_ShowNpcMissionDialogUI` |
| Layout | `docs/missionState.md` — char `+0x548` active objectives; mission `+0x130`/`+0x13c`; obj `+0x10`/`+0x158`/`+0x15c` |
| System map | `docs/reconstruction/systems/missions-progression.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=`CVOGCharacter*`; stack mission def, optional NPC | **High** | locals storage + `ret 8` + call sites |
| Last objective = `*(objectives + count*4 - 4)` | **High** | LEA `[base+edx*4-4]`; count byte `@mission+0x130`; array `@+0x13c` |
| Active hash = `char+0x548`; key = `obj+0x10` | **High** | `mov eax,[ecx+0x548]`; missionState |
| Bucket walk: mask `@hash+8`, buckets `@hash+0x10`, node key `+0x10`, next `+0xc` | **High** | body + image |
| Active payload gate: `node+0x8 != 0` | **High** | early return 0 if null |
| Miss / empty chain → 0 | **High** | |
| Complete gate: `FUN_0052a020(this=char, lastObj, flag=1)` | **High** | push `1`, push obj; ECX preserved as char; callee body uses `+0x55c` / vtbl+8 |
| NPC null → skip evaluator filter; return 1 after complete | **High** | `test ebp,ebp` / `param_3==0` |
| Type probe vtbl **+0x50**; type **3** only filtered | **High** | image `call [edx+0x50]` / `cmp eax,3` |
| Type-3 target id `@eval+0x18` vs NPC clonebase `@entity(+0xac)+0x34` | **High** | image cmp; same entity chain as ShowNpc/HandleButton |
| Any type-3 with **wrong** target → 0; all pass / no type-3 → 1 | **High** | fail break sets `BL=0` |
| Empty evaluator range `[+0x158,+0x15c)` → 1 (after complete) | **High** | skip loop |
| Body store-free bool only | **High** | |
| Clean ≡ raw ≡ live Ghidra CF | **High** | re-decompile 2026-07-29 |
| Product name `FUN_0052a020` | **Tentative** | complete-eval spine sealed; name open |
| Full evaluator type enum beyond 3 | **Open** | only 3 special-cased here |

---

## 4. Sealed readiness gates

```
IsMissionTurnInReady(char* this, MissionDef* mission, Object* npcOpt) -> bool
  // G1 — last objective
  lastObj = *(MissionObjective**)( *(mission+0x13c) + (uint8)(mission+0x130)*4 - 4 )

  // G2 — active-objectives hash hit with payload
  node = CNDHash_bucket_walk( *(this+0x548), key=*(lastObj+0x10) )
  if node==0 or *(node+0x8)==0: return false

  // G3 — last objective complete (strict eval mode)
  if !FUN_0052a020(this, lastObj, /*flag*/ 1): return false

  // G4 — optional NPC type-3 interact filter
  if npcOpt != 0 and [lastObj+0x158, lastObj+0x15c) non-empty:
    for each eval* in range:
      if eval->vtbl[+0x50]() == 3
         and *(eval+0x18) != NPC_clonebase_id(npcOpt):  // entity chain +0xac → +0x34
        return false
  return true
```

**Caller contracts (framing sealed):**

| Caller | ECX (this) | mission | npc |
|---|---|---|---|
| `Client_ShowNpcMissionDialogUI` `0x00943a43` | `*(client+0xe98)` | mission def | NPC object |
| `FUN_004d5c10` (2 sites) | character from resolve | mission id ptr / def | interact target |
| `FUN_008a8770` `0x008a938f` | `DAT_00d1b6d8` | `*(obj+0x14c)` mission | **0** (skip G4) |

ShowNpc: `turnIn=1` → chrome `dialog+0x510=1` and claim flag `dialog+0x64c=1` via `FUN_008aa760`.

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Last-obj LEA | **Yes** |
| Hash bucket + chain + key match | **Yes** |
| `node+8` payload gate | **Yes** |
| `FUN_0052a020(...,1)` | **Yes** |
| NPC filter type-3 / target cmp | **Yes** |
| Six return-0 / success paths | **Yes** |
| Invented clamps / stores | **None** |

---

## 6. Gaps / open questions

1. Product name for `FUN_0052a020` (objective complete-all-evaluators).
2. Full evaluator type enum (only type **3** branched here; sibling UI also uses 6/0xc).
3. Product type name of entity field `+0x34` (treated as clonebase / interact target id).
4. Runtime / bit-diff vs retail EXE.

**Verdict:** Last-objective + active-hash + readiness gates **sealed High**. Overall **accept** on CF contract; **accept-with-gaps** only for callee/product naming.
