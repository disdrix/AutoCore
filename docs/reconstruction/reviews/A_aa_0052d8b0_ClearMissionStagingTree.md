# Review A (reconstruction fidelity): `aa_0052d8b0` Clear mission staging tree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052d8b0` |
| **VA** | `0x0052d8b0`–`0x0052da2f` (body 384 bytes) |
| **Canonical name** | `FUN_0052d8b0` (product English open) |
| **Inferred role** | Character mission **staging map clear** (single key or full tree) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + image) |
| **Counterpart** | `reviews/B_aa_0052d8b0_ClearMissionStagingTree.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — CF + map layout sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` on **character**: clear the mission **staging map** at **`this+0x508`** (end sentinel `+0x50c`, size `+0x510`).

1. **`missionId == -1`**: inorder-walk **all** nodes from begin (`*header`) to end (`header`); optionally destroy resolved world objects per 4 payload pairs when `destroyFlag != 0`; then **bulk free** every node and reset empty tree (size = 0).
2. **`missionId != -1`**: `lower_bound` / exact find (`FUN_00538a40` on map `+0x508`); if hit, optional destroy on that node’s 4 pairs, then **erase one node** (`FUN_00538780`) and return.
3. When `destroyFlag == 0` (all current xrefs): walk/erase **map only** — no `ResolveObjectTarget` / delete-cue work.

Sibling of **`FUN_0052c700`** (staging map **upsert** of 12-dword payload).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052d8b0_FUN_0052d8b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052d8b0_FUN_0052d8b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0052d8b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052d8b0_FUN_0052d8b0.md` |
| Sibling store dual | `reviews/A_aa_0052c700_MissionStagingStore.md` |
| Fresh decompile | Ghidra `decompile_function` / `force_decompile` @ `0x0052d8b0` (2026-07-29) |
| Body image | Ghidra `read_memory` entry / mid / epilogue — seals map `+0x508`, payload `+0x18`, loop 4, `ret 8` |
| Call-site asm | `get_assembly_context` on all 8 xrefs |
| Callees | batch decompile: `FUN_00538a40`, `FUN_00538780`, `FUN_00537ef0`, `FUN_005875c0`, `FUN_004d4790` |
| Resolve dual | `A_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Signature (assembly-sealed)

```c
// __thiscall  ECX = Character*
// stack: flag, missionId   cleaned by ret 0x0008
void FUN_0052d8b0(
    Character *this,
    char destroyFlag,   // 0 = map-only clear (all live xrefs); non-0 = also resolve+delete staged objects
    int missionId);     // -1 = clear entire tree; else erase one key
```

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall` + `RET 8` | Entry `MOV EBX,ECX`; epilogue `C2 08 00` | **High / Confirmed** |
| Arg order `(flag, missionId)` | Call sites `PUSH missionId; PUSH flag; MOV ECX,char` | **High / Confirmed** |
| Map object `char+0x508` | `LEA ECX,[EBX+0x508]` before lower_bound **and** erase | **High / Confirmed** |
| End sentinel `char+0x50c` | `MOV EAX,[EBX+0x50C]` / `CMP` vs walk end | **High / Confirmed** |
| Size `char+0x510` | Empty/reset: `MOV dword [map+8], 0` (`map` = `+0x508`) | **High / Confirmed** |
| Payload walk `node+0x18`, **4** pairs | `LEA EDI,[EBP+0x18]`; counter `MOV [esp+..],4`; step `+8` | **High / Confirmed** |
| Find uses `FUN_00538a40` | Call after `LEA ECX,[EBX+0x508]` | **High** |
| Single erase `FUN_00538780` | After optional destroy when `missionId != -1` | **High** |
| Full clear free loop | After full walk: left-spine free + `FUN_00537ef0` on right + `operator_delete`; then header reset | **High** (decomp truncated by false noreturn) |

---

## 4. Control flow (sealed)

```
if (missionId == -1)
  it = begin = *header                // header @ char+0x50c
else
  it = lower_bound(map@+0x508, key)   // FUN_00538a40; miss → end

if (it == end) {
  if (missionId != -1) return;        // single-key miss
  // else fall through to empty/full clear
} else {
  do {
    // payload base = node + 0x18
    for (i = 0; i < 4; ++i) {
      pair = (lo, hi) at payload + 8*i
      if (destroyFlag != 0
          && sectorMap = *(adj+0xa8) != 0
          && obj = ResolveObjectTarget(ctx=*(sectorMap+0xe4e8), bGlobal=1, lo, hi)) {
        FUN_005875c0(this=char+0xcc4, &obj);  // unlink from char-side list
        FUN_004d4790(obj);                    // queue world-object delete
      }
    }
    if (missionId != -1) {
      map.erase(it);                          // FUN_00538780
      return;                                 // (via empty-check that returns when id!=-1)
    }
    it = inorder_successor(it);               // MSVC RB next; isnil @ +0x49
  } while (it != end);
}

// full clear only (missionId == -1):
// free all nodes from root; then
header->parent = header->left = header->right = header;
size = 0;
```

### Decompiler hazards corrected

| Decomp artifact | Reality (image) |
|---|---|
| `FUN_00538a40(local,&key)` missing map `this` | `ECX = char+0x508` |
| `FUN_00538780(&param_2, node)` missing map `this` | `ECX = char+0x508` |
| `ResolveObjectTarget(1,lo,hi)` missing `this` | `ECX = *(sectorMap + 0xe4e8)` |
| Full clear ends at `operator_delete` noreturn | Loop: free right via `FUN_00537ef0`, delete node, follow left; then header reset + `ret 8` |
| Map “at `+0x50c`” only | **End** is `+0x50c`; **map object** is `+0x508` |

---

## 5. Node / payload geometry (shared with upsert)

```
Character
  +0x508  map object (this for lower_bound / erase / clear helpers)
  +0x50c  end / header node*
  +0x510  element count

Node (MSVC-like red-black)
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x10  key (mission id)
  +0x18  MissionStagingPayload[12] = 0x30 bytes
         payload[0..7] walked as 4× (lo,hi) for ResolveObjectTarget when destroyFlag
  +0x49  isnil
```

Compatible with sibling dual: upsert copies **12 dwords** at `+0x18`; clear’s destroy path only reads **first 8 dwords** as 4 pairs.

---

## 6. Callers (8 xrefs; arg pattern sealed)

| Site VA | Caller | this | flag | missionId |
|---|---|---|---:|---|
| `0x005329ee` | `CVOGReaction_GiveMission` | char | `0` | `*missionDef` |
| `0x00534833` | `CVOGReaction_CompleteObjective` | char | `0` | `*missionDef` / key on stack |
| `0x00530d9b` | `FUN_005307e0` (HandleEndQuest family) | char | `0` | `-1` |
| `0x0081509b` | `Client_RecvNpcMissionDialog` | `DAT_00d1b6d8` char | `0` | `-1` |
| `0x0080ff0e` | `Client_RecvCompleteDynamicObjective` | local char `+0xe98` | `0` | `-1` |
| `0x004d5c96` | `FUN_004d5c10` (interact/offer) | char | `0` | `-1` |
| `0x0052f306` | `FUN_0052f260` (character dtor path) | char | `0` (EBX) | `-1` |
| `0x005371e9` | `FUN_00536920` (character ctor path) | char | `0` (EBX) | `-1` (EDI fill) |

**Observation:** every live xref passes **`destroyFlag = 0`**. The resolve+delete branch is real code, currently **unreached** from these sites.

---

## 7. Callees (roles)

| VA | Name | Role re this unit |
|---|---|---|
| `0x00538a40` | map lower_bound/find | Keyed entry when `missionId != -1` |
| `0x00538780` | map erase (iterator) | Remove one staging node |
| `0x00537ef0` | recursive subtree free | Full-clear helper (right/children) |
| `0x004bae70` | `CVOGReaction_ResolveObjectTarget` | Optional object* from staged pair (`bGlobal=1`) |
| `0x005875c0` | list unlink by ptr | `this = char+0xcc4`; drop resolved obj from list |
| `0x004d4790` | queue object delete | World-object delete cue (string-backed role High) |
| `operator_delete` | free node | After erase / full clear |

---

## 8. Gaps / open questions

1. **Product English** for `FUN_0052d8b0` / map typedef (shape sealed).
2. Whether payload pairs are **TFID** vs dual-dword **COID** packing (resolve takes lo/hi; dialog fill is 8×i32 COID — pair meaning path-qualified).
3. Why **`destroyFlag` exists** with zero live callers at `!= 0` (indirect/unlisted? dead? server-only path not in image?).
4. Formal names of `FUN_00538780` / `FUN_00537ef0` / `FUN_005875c0` (roles High).
5. Exact equality path of `FUN_00538a40` vs pure lower_bound (sibling: lower_bound + `key <= k` ⇒ exact) — **High** from sibling dual; not re-proven byte-by-byte this pass beyond call.
6. Runtime / bit-exact / binary diff open.

---

## 9. Verdict

### **accept-with-gaps**

**Accept because:** Image seals `thiscall`+`ret 8`, map base `+0x508`, end `+0x50c`, size `+0x510`, payload walk at `+0x18` with **4** pairs, single-key erase vs full free+reset, and all 8 call-site arg patterns. Sibling upsert dual agrees on map geometry. Product name and destroyFlag live use remain open.
