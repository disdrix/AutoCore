# Review A (reconstruction fidelity): `aa_0052c700` Mission staging map store

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052c700` |
| **VA** | `0x0052c700` |
| **Canonical name** | `FUN_0052c700` (product English open) |
| **Inferred role** | Character mission **staging / offer map store** (12-dword payload) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + assembly) |
| **Counterpart** | `reviews/B_aa_0052c700_MissionStagingStore.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — layout sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` on **character**: upsert a **12-dword staging payload** into the character’s `std::map`-like tree at **`this+0x508`**, keyed by mission id.

1. `LEA map, [char+0x508]`; `lower_bound` (`FUN_00538a40`) by key.
2. If iterator == end sentinel `*(char+0x50c)`: build `{key, payload[12]}` on stack and **insert** (`FUN_00539cb0`).
3. Else: **overwrite** existing node payload at `node+0x18` with 12 dwords (`REP MOVSD`, `ECX=0xC`).
4. Re-`lower_bound`; set **`payload[+0x28] = key`** (dword index 10).
5. **Return** `node+0x18` (payload base) in `EAX`.

Used by `Client_RecvNpcMissionDialog` (offer COIDs), `CVOGCharacter_CheckMissionPrerequisites` (NPC/AutoAssign prep before GiveMission), thin wrapper `FUN_004cf100`, interact path `FUN_004d5c10`, and empty-slot factory `FUN_0052dac0`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052c700_FUN_0052c700.md` |
| Annotated | `docs/reconstruction/raw/aa_0052c700_FUN_0052c700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0052c700.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052c700_FUN_0052c700.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0052c700` (2026-07-29) — CF ≡ 2026-07-23 raw |
| Body image | Ghidra `read_memory` @ `0x0052c700` length 128 — seals map base, copy count, ret payload*, force key |
| Callers | `0x00536540`, `0x00815070`, `0x004cf100`, `0x004d5c10`, `0x0052dac0` |
| Sibling clear | `FUN_0052d8b0` @ `0x0052d8b0` (walks same map; size `+0x510`) |
| Map helpers | `FUN_00538a40` lower_bound; `FUN_00539cb0` insert |
| WAD names | `Mission.NPC` / `Mission.AutoAssign` via Prerequisites dual + `Mission.cs` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall(Character* this, u32 key, u32* payload12) → payload*` | Asm: `MOV ESI,ECX`; `RET 8`; ends `ADD EAX,0x18` | **High** |
| Map object base `char+0x508` | `LEA EBX,[ESI+0x508]` before both tree calls | **High / Confirmed** |
| End sentinel `char+0x50c` | `CMP EAX,[ESI+0x50c]` | **High / Confirmed** |
| Size field `char+0x510` | Clear path `FUN_0052d8b0` zeros it | **High** (sibling) |
| Copy **exactly 12 dwords** | `MOV ECX,0xC` + `F3 A5` both paths | **High / Confirmed** |
| Payload at `node+0x18` | `LEA EDI,[EAX+0x18]` hit path; return `+0x18` | **High / Confirmed** |
| Force `payload[+0x28] = key` | `MOV [EAX+0x28],EBP` after payload base in EAX | **High / Confirmed** |
| Key also at `node+0x10` | lower_bound compares `node[4]` | **High** |
| Node isnil @ `+0x49` | tree walks in `FUN_00538a40` / clear | **High** |
| Miss → insert via `FUN_00539cb0` | CF + asm call | **High** |
| Hit → in-place overwrite | CF + asm | **High** |
| Product English name | No string/RTTI this pass | **Open** |

---

## 4. Sealed 12-dword payload layout (`node+0x18`, size `0x30`)

| Index | Off | Width | Dialog `RecvNpcMissionDialog` | Prerequisites award | Notes |
|------:|----:|---|---|---|---|
| 0..7 | `+0x00`..`+0x1C` | 8×`i32` | Packet entry 8× item **COID** (init `−1`, then `REP MOVSD` 8) | All `0xFFFFFFFF` | Clear sibling walks 4× pairs as resolve targets |
| 8 | `+0x20` | `i32` | left `−1` | **`missionDef+0x88` = `Mission.NPC`** | Giver / NPC CBID on award path |
| 9 | `+0x24` | `i32` | left `−1` | **`missionDef+0xfc` = `Mission.AutoAssign`** (`i16` stored as dword) | Auto-assign field |
| 10 | `+0x28` | `u32` | scratch `−1`, then **forced = key** | set to `missionId`, then **forced = key** | **Always mission key after this function** |
| 11 | `+0x2C` | `u32`/`u8` | `0` | `0` | Some callers later write a **flag byte** here (`FUN_0052dac0` consumers) |

### Caller fill summary

```
// RecvNpcMissionDialog (offer stage)
scratch[0..7]  = entry.itemCoid[8];
scratch[8..10] = -1;
scratch[11]    = 0;
FUN_0052c700(this=char, key=*missionDef, scratch);
// post: payload[+0x28] == key

// CheckMissionPrerequisites (award prep)
prep[0..7]  = -1;
prep[8]     = def->NPC;        // +0x88
prep[9]     = def->AutoAssign; // +0xfc
prep[10]    = missionId;
prep[11]    = 0;
FUN_0052c700(this=char, key=missionId, prep);
GiveMission(...);

// FUN_0052dac0 create-if-missing
empty[0..10] = -1; empty[11] = 0;
return FUN_0052c700(this, key, empty);  // returns payload*
```

---

## 5. Map / node geometry (sealed)

```
Character
  +0x508  map header (this for FUN_00538a40 / FUN_00539cb0)
  +0x50c  end / sentinel node*
  +0x510  element count (cleared by FUN_0052d8b0)

Node (MSVC-like red-black)
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x10  key (mission id)          // lower_bound compares node[4]
  +0x18  MissionStagingPayload[12] // 0x30 bytes
  +0x40  == payload[+0x28] (key mirror after store)
  +0x49  isnil char
```

---

## 6. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| lower_bound on map `+0x508` | **Yes** (asm LEA; decomp drops map this — corrected in clean) |
| miss vs `+0x50c` → insert | **Yes** |
| hit → copy to `node+0x18` | **Yes** |
| 12-dword `REP MOVSD` | **Yes** |
| force key @ payload `+0x28` | **Yes** (decomp as `node+0x40`) |
| return payload* | **Yes** (decomp said `void` — **corrected**) |
| No invented eligibility | **Yes** |

---

## 7. Callers (OWN boundary: roles only)

| VA | Name | Role re this unit |
|---|---|---|
| `0x00815070` | `Client_RecvNpcMissionDialog` | Stage offers: 8 COIDs + zeros |
| `0x00536540` | `CVOGCharacter_CheckMissionPrerequisites` | Prep NPC/AutoAssign before GiveMission |
| `0x0052dac0` | (lookup/create) | Return existing payload or create empty 12-dword |
| `0x004cf100` | thin | `FUN_0052c700(*def, tableBlob)` |
| `0x004d5c10` | interact/offer | Stages via this + patches payload fields |

---

## 8. Gaps / open questions

1. **Product English** for `FUN_0052c700` / map type name (shape sealed).
2. Whether COID[8] are required items vs rewards (consumer of staging, not this store).
3. Semantics of payload `[11]` flag beyond “byte written by interact path”.
4. Full `pair` / MSVC node padding between key `+0x10` and value `+0x18` (4 bytes) — layout effect sealed, field name open.
5. Runtime / bit-exact / binary diff still open.
6. Formal name of `FUN_00538a40` / `FUN_00539cb0` (lower_bound / insert roles **High**).

---

## 9. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; assembly seals map base `+0x508`, 12-dword copy, payload at `+0x18`, forced key at `+0x28`, and non-void return of payload*. Dual caller fills (dialog COIDs vs prereq NPC/AutoAssign) agree on the same 12-dword frame. Product name only residual naming gap.
