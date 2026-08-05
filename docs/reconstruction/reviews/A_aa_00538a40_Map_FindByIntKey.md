# Review A (reconstruction fidelity): `aa_00538a40` Tree find (int key)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538a40` |
| **VA** | `0x00538a40` |
| **Canonical name** | `FUN_00538a40` |
| **Inferred role** | MSVC-style **map find** by signed `int` key (lower_bound walk + equality → end) |
| **Domain label** | Tree find for **reward-region / mission-staging map** (callers pass map @ `char+0x508`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction (A≡B decompile + full-body `read_memory`) |
| **Counterpart** | `reviews/B_aa_00538a40_Map_FindByIntKey.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — CF + ABI + node geometry sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` leaf on a **map object** (`this`): search for an **exact** signed-int key and write the matching **node pointer** (or the map **end/head sentinel**) through an out-parameter.

1. Load head = `*(this+4)`; start at root = `head[1]` (parent of head).
2. While node `isnil` byte at `+0x49` is clear:
   - if `node.key (+0x10) < *pKey` → go **right** (`node[2]`);
   - else → set **candidate** = node, go **left** (`node[0]`).
3. If candidate is still head → `*ppOut = head` (end / miss).
4. Else if `*pKey < candidate.key` → `*ppOut = head` (miss; first greater key rejected).
5. Else → `*ppOut = candidate` (**exact hit**: walk ensures `key ≥ node.key`, gate ensures `key ≥ node.key` wait: gate is `key < node` → end, so hit when `key ≥ node.key`; combined with walk candidate property `node.key ≥ key` ⇒ **equality**).

No inserts, no payload reads, no callees.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00538a40_FUN_00538a40.md` |
| Annotated | `docs/reconstruction/raw/aa_00538a40_FUN_00538a40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00538a40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00538a40_FUN_00538a40.md` |
| Decompile A | Ghidra `decompile_function` @ `0x00538a40` |
| Decompile B | Ghidra `force_decompile` — **byte-identical CF to A** |
| Decompile C | Ghidra `batch_decompile` — **identical** |
| Body image | Ghidra `read_memory` @ `0x00538a40` length **96** (full body through dual `ret 8`) |
| Sibling shape | `StdMap_LowerBoundByIntKey_INFERRED` @ `0x004054f0` (same walk; **isnil @ +0x1d**, key at dword `[3]`) |
| Callers (xrefs) | `FUN_0052c700`, `FUN_0052d8b0`, `FUN_0052dac0`, `CVOGReaction_GiveMission` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, binary diff.

---

## 3. ABI (sealed)

```c
/* __thiscall | ret 8 | ECX = map* */
void Map_FindByIntKey(
    void *this,           /* ECX: map header */
    void **ppOutNode,     /* stack +4: out iterator / node* */
    const int *pKey);     /* stack +8: key pointer */
```

| Slot | Role | Evidence |
|---|---|---|
| `ECX` | Map object | Entry uses `ECX+4`; callers `LEA ECX,[reg+0x508]` |
| Stack `+4` | Out node* | Written on both exit paths; `ret 8` |
| Stack `+8` | `int* pKey` | Loaded via `EDI` after prolog; `*EDI` compared to `node+0x10` |
| Return | **void** (result only via `*ppOutNode`) | EAX ends as out-pointer address, not node |
| Stack cleanup | `ret 8` (both exits) | Hex ends `C2 08 00` ×2 |

---

## 4. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Leaf (no callees) | `analyze_function_complete` callees empty; no `CALL` in body hex | **High** |
| Map head at `this+4` | `MOV EDX,[ECX+4]` | **High** |
| Root = `head[1]` (parent) | `MOV EAX,[EDX+4]` | **High** |
| isnil flag node `+0x49` | `CMP BYTE PTR [EAX+0x49],0` | **High** |
| Key at node `+0x10` (signed) | `CMP [EAX+10h],ESI`; `CMP ECX,[EDX+10h]` + signed `JL`/`JGE` | **High** |
| left `+0`, right `+8` | go-right `MOV EAX,[EAX+8]`; go-left `MOV EAX,[EAX]` | **High** |
| Exact-match semantics | Walk = lower_bound; final `key < node.key` → end | **High** |
| Miss writes head sentinel | Miss path stores head into `*ppOut` | **High** |
| Hit writes candidate node* | Hit path stores spilled candidate | **High** |
| A≡B≡C decompile | force + batch match primary | **High** |
| Domain: reward-region map helper | Callers `FUN_0052dac0` / `FUN_0052c700` use map @ `+0x508` | **High** (role via callers; not self-named) |
| Product / export name | No string/RTTI this unit | **Open** |
| STL typedef exactness (`std::map<int,T>`) | Shape matches MSVC tree; type args not in this fn | **Probable** shape / **Open** typedef |

---

## 5. Node / map geometry (this unit)

```
Map (this)
  +0x00  (unused here)
  +0x04  head / end sentinel node*

Node (MSVC-like red-black / tree node)
  +0x00  left*
  +0x04  parent*     // head.parent == root
  +0x08  right*
  +0x10  key (int32, signed compare)
  +0x49  isnil (char; non-zero = nil/sentinel child)
  // value payload not accessed by this function
```

Callers (OWN boundary: **roles only**, sealed elsewhere) treat:

- Map object often at **`Character+0x508`**
- End sentinel alias **`Character+0x50c`** (= `*(map+4)` / head stored adjacently)
- Value / reward-region blob at **`node+0x18`** (read by `FUN_0052dac0` after this find)

---

## 6. Control flow: clean ≡ raw ≡ memory

| Stage | Match |
|---|---|
| head = `*(this+4)` | **Yes** |
| empty if root isnil | **Yes** |
| key < → right; else candidate+left | **Yes** |
| candidate==head → out=head | **Yes** |
| key < candidate.key → out=head | **Yes** |
| else out=candidate | **Yes** |
| dual `ret 8` | **Yes** |
| No invented side effects | **Yes** |

---

## 7. Callers (OWN boundary: how `this` is bound)

| Site | Function | Map `this` | Use of out node |
|---|---|---|---|
| `0x0052dad6` | `FUN_0052dac0` | `LEA ECX,[ESI+0x508]` | vs `+0x50c`; hit → `node+0x18` reward region* |
| `0x0052c71b` / `0x0052c767` | `FUN_0052c700` | `LEA EBX,[ESI+0x508]` | miss→insert; hit→overwrite payload |
| `0x0052d8da` | `FUN_0052d8b0` | (same map family) | clear/walk by key or full clear |
| `0x005329af` | `CVOGReaction_GiveMission` | `LEA ECX,[EBP+0x508]` | prior-state / staging presence vs `+0x50c` |

---

## 8. Gaps / open questions

1. **Product English** for the helper (`Map_Find` vs `lower_bound` export name).
2. Full node size / color bit / padding between key `+0x10` and value `+0x18` (sibling units seal value base; color not in this fn).
3. Whether every caller map is Character-owned staging only (all sealed call sites use `+0x508` pattern; other maps unproven).
4. Runtime / bit-exact / binary diff still open.
5. Decompiler often **drops** map `this` at call sites (shows `FUN_00538a40(out,&key)` only) — prefer asm for `ECX`.

---

## 9. Verdict

### **accept-with-gaps**

**Accept because:** Three decompiles agree; 96-byte body from `read_memory` seals ABI (`ret 8`), isnil `+0x49`, key `+0x10`, left/right links, and exact-find final gate. Callers consistently use it as tree find on the mission staging / reward-region map. Product name and full STL typedef remain open only.
