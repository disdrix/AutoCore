# Review A (reconstruction fidelity): `aa_008ae130` Client_UpdateMissionJournal

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae130` |
| **VA** | `0x008ae130` |
| **Canonical name** | `Client_UpdateMissionJournal` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + assembly) |
| **Counterpart** | `reviews/B_aa_008ae130_Client_UpdateMissionJournal.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (residual dual; supersedes 2026-07-23 id-vector gap) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Rebuild the mission **journal** UI when dialog state is **3** (journal view). Walks the character mission tree at `char+0x50c`, partitions each mission id into **Active** vs **New** local dword vectors via hash probe at `char+0x540`, then constructs `"Active Missions:"` / `"New Missions:"` panels with `0x510` multi-select entry widgets.

**Does not** grant, complete, abandon, or fail missions. UI rebuild only.

**Calling convention:** MSVC `__thiscall` plate; dialog context primarily in `EBX` / decompiler `unaff_EBX` (state at dword `[0x192]` = `+0x648`).

| Slot | Role | Evidence |
|------|------|----------|
| `this` / unused plate | May be unused vs EBX dialog host | Decompiler surfaces both; body uses `unaff_EBX` |
| `EBX` dialog ctx | State, chrome, child vector | `[0x192]==3` gate; vcalls; `[0x1ca..]` push |
| Return | `void` | Fall-through after cleanup |

**Side effects:** Allocates temporary id vectors + UI widgets; optional free of name temp; restores `ExceptionList`. No network, no mission hash mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008ae130_Client_UpdateMissionJournal.md` |
| Annotated | `docs/reconstruction/raw/aa_008ae130_Client_UpdateMissionJournal.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UpdateMissionJournal.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ae130_Client_UpdateMissionJournal.md` |
| Prior dual | A/B 2026-07-23 (accept-with-gaps; id-vector residual open) |
| Live re-decompile | Ghidra MCP `batch_decompile` @ `0x008ae130` (2026-07-29) — **≡ raw body** |
| Callees | `FUN_00568200`, `CVOGReaction_FailMissionNotify` `0x004149d0`, `FUN_00829ec0`, `FUN_0053fff0` |
| Assembly | `get_assembly_context` at `0x008ae2f0`..`0x008ae350`, `0x008ae51a` |
| Caller | Sole: `Client_ShowNpcMissionDialogUI` `0x009438f0` (xref `0x00943982`) |

**Not performed:** `disassemble_bytes` bulk, Launcher, live journal UI golden, bit-exact layout diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Requires dialog state == 3 (`[0x192]` / `+0x648`) | **High** | Early gate |
| Requires `DAT_00d1b6d8` client singleton | **High** | AND gate |
| Walk source `char+0x50c` tree/header | **High** | Init + end compare |
| Mission id at tree node `+0x10` | **High** | `LEA ESI,[node+0x10]`; hash key |
| Hash table `char+0x540` probe by id | **High** | Loop body |
| Active vs New partition (hash hit ∧ `[node+0x8]!=0` → Active; else New) | **High** | Assembly 0x008ae31e–0x008ae32f |
| Id append via `CVOGReaction_FailMissionNotify` = Vector_PushDword | **High** | Callee body + call site ECX |
| `FUN_00568200` = iterator++ on `ESP+0x14` | **High** | Callee body + `LEA ECX,[ESP+0x14]` |
| Panels titled `"Active Missions:"` / `"New Missions:"` | **High** | String literals |
| Entry widgets size `0x510` via `FUN_00829ec0` | **High** | `operator_new(0x510)` + ctor; XML `i_d_npc_2d_btn_mselect.xml` |
| Widget id base `0x9c4f` sequential | **High** CF | Literal; English “control id family” open |
| FailMissionNotify does **not** fail missions here | **High** | Body is push only |
| Hash node `+0x8` = live instance / payload ptr | **Probable** | Null → New bucket; product name open |
| SEH / ExceptionList framing | **High** | Present; not mission-semantic |
| Register `unaff_EBX` dialog context | **High** | Decompiler + vcalls |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| State==3 gate + client singleton | **Yes** |
| Init chrome / optional NPC name header | **Yes** |
| Layout y base from `[0x1b8]` | **Yes** |
| Zero two id vectors + SEH state 2 | **Yes** |
| Tree walk `+0x50c` until iterator == header | **Yes** |
| Per node: hash probe `+0x540` | **Yes** |
| Partition push Active vs New | **Yes** (assembly seals branch lost as flat call in decompile) |
| Iterator++ via `FUN_00568200` | **Yes** (misnamed in older clean as id-collect) |
| Active panel + per-id entries | **Yes** |
| New panel + child vector push `[0x1ca..]` | **Yes** |
| Free temp vectors | **Yes** |
| No mission grant/fail/network | **Yes** |

### 4.1 Decisive assembly (id partition + iterator)

```
; per node (iterator @ [ESP+0x14], id key @ node+0x10 → ESI)
hash probe char+0x540
CMP EAX, EBP                 ; miss?
JZ  new_vec
CMP [EAX+0x8], EBP           ; payload null?
LEA ECX, [ESP+0x24]          ; Active vector object
JNZ push
new_vec:
LEA ECX, [ESP+0x34]          ; New vector object
push:
PUSH ESI
CALL CVOGReaction_FailMissionNotify   ; Vector_PushDword(this, &id)
LEA ECX, [ESP+0x14]
CALL FUN_00568200                     ; iterator++
; loop while iterator != char+0x50c header
```

Stack vector layout (FailMissionNotify uses `this+4/+8/+0xc`):

| Vector | `this` | begin | end | cap |
|--------|--------|-------|-----|-----|
| Active | `ESP+0x24` | `ESP+0x28` | `ESP+0x2c` | `ESP+0x30` |
| New | `ESP+0x34` | `ESP+0x38` | `ESP+0x3c` | `ESP+0x40` |

### 4.2 Widget ids

| Panel | Control id |
|-------|------------|
| Active entry `i` | `i + 0x9c4f` |
| New entry `i` | `activeCount + 0x9c4f + i` |

---

## 5. Gaps (remaining)

1. Product English for hash node `+0x8` (live instance vs other payload).
2. Full UI vtable slot names (`+0xa8`, `+0x74`, `+0x43c`, …).
3. Runtime journal rebuild / layout golden.
4. Bit-exact SEH and float layout constants vs retail EXE.

**Verdict:** Journal rebuild CF + id-vector residual **faithful and sealed static**. **accept-with-gaps** (not complete).
