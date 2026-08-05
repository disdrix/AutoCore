# Review A (reconstruction fidelity): `aa_009197a0` Client_FindFirstObjectInRadius

| Field | Value |
|---|---|
| **Stable ID** | `aa_009197a0` |
| **VA** | `0x009197a0` |
| **Canonical name** | `Client_FindFirstObjectInRadius` (INFERRED; prior scaffold `FUN_009197a0` / misleading `Named_VOG_DEBUG_STOP_009197a0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| **System** | `interaction-activation` (also used from mission complete path) |
| **Verdict** | **accept-with-gaps** — radius helper + 15f callers **sealed**; not true nearest-by-distance |

---

## 1. Purpose

Client-side **world-object pick helper**: given a **radius** (float), return a **resolved world object\*** within that radius of the local player, or `null`.

Priority:

1. **Auto-patrol waypoint** (`DAT_00d1ad10` list non-empty) via `Client_EvalAutoPatrolWaypoint` — if waypoint position is **strictly inside** `radius` (dist² **&lt;** radius²) and `Object_ResolveFromTFID` succeeds → return that object **without** scanning the world hash.
2. Else **VOG hash traversal** (`*(DAT_00d1b644 + 0xe8f4)`): lock, walk nodes, optional predicate, resolve TFID, accept **first** object with dist² **&lt;** radius² to player position.

**Not** a min-distance nearest-neighbor. Hash order (or waypoint preference) decides which in-range object wins.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.md` (+ 2026-07-29 residual) |
| Annotated | `docs/reconstruction/raw/aa_009197a0_FUN_009197a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FindFirstObjectInRadius.cpp` |
| Function record | `docs/reconstruction/functions/aa_009197a0_Client_FindFirstObjectInRadius.md` |
| Live decompile | Ghidra `decompile_function` `0x009197a0` — body ≡ raw |
| Live bytes | Ghidra `read_memory` entry + epilogue (`RET 4`) |
| Call-site asm | Ghidra `get_assembly_context` @ `00927b2f`, `0081002e`, `0092133d` |
| Callers API | `get_function_callers` → PollBoundActions / RecvCompleteDynamicObjective / FUN_009210e0 |
| Callees API | EvalAutoPatrolWaypoint, FUN_004e88e0, Object_ResolveFromTFID, FUN_007a4480 |
| System map | `systems/interaction-activation.md` flow D (Activate ~15f) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Stack float `radius` | All callers `PUSH 0x41700000` immediately before `CALL 0x009197a0` |
| Epilogue `RET 4` | Bytes at body end: `C2 04 00` (`read_memory` near `0x009199ec`) |
| Return `Object*` in EAX | Post-call `MOV EDI/ESI/EAX, EAX` at all three sites |
| Convention | **`__stdcall`**, single 4-byte stack arg (float bits) |

```c
void * __stdcall Client_FindFirstObjectInRadius(float radius);
```

### 3.2 Call-site radius **15.0f** — **SEALED**

| Call site | Parent | Imm push |
|---|---|---|
| `0x00927b2f` | `Client_Input_PollBoundActions` `0x00925d60` | `PUSH 0x41700000` (= **15.0f**) |
| `0x0081002e` | `Client_RecvCompleteDynamicObjective` `0x0080ff00` | `PUSH 0x41700000` |
| `0x0092133d` | `FUN_009210e0` `0x009210e0` | `PUSH 0x41700000` |

No other production callers (`get_function_callers` / xrefs). Function itself accepts **any** radius; **all live call sites use 15f**.

### 3.3 Player origin — **SEALED** (static)

```
// DAT_00d1b6d8 = local character / identity base
// adj this = *( *(DAT_00d1b6d8+4) + 4 ) + 4 + DAT_00d1b6d8
// float4* = vtbl[+0x1a0]()
// fStack_30..24 = *float4 (xyzw copy)
// FUN_004e88e0(&xyz_copy, &float4) → copies first 3 floats only
```

Hash-loop distance uses **`fStack_30 / 2c / 28`** (xyz of that float4) vs **`obj+0x80 / +0x84 / +0x88`**.

Waypoint path compares `Client_EvalAutoPatrolWaypoint` out-pos vs the FUN_004e88e0 xyz copy (same origin).

`FUN_004e88e0` body (fresh decompile): pure 3-float copy — not a matrix transform.

### 3.4 Distance test — **SEALED**

```
accept when:  (dx*dx + dy*dy + dz*dz) < (radius * radius)
// coded as continue-while: null || (radius² <= dist²)
```

No `sqrt`. Squared compare only. Boundary: **strict** (equal to radius² **fails** accept — continues / falls through).

### 3.5 Auto-patrol short-circuit — **SEALED** CF

Enter hash scan if **any** of:

| Condition | Meaning |
|---|---|
| `*(DAT_00d1ad10 + 0x11c) == 0` | No waypoint vector begin |
| `(end - begin) >> 2 < 1` | Empty / &lt;1 entry (`+0x120` end) |
| After `Client_EvalAutoPatrolWaypoint(mgr, &tfid, &pos)`: `radius² ≤ dist²(wp, player)` | Waypoint too far |
| `Object_ResolveFromTFID(&tfid) == null` | Waypoint TFID not in world |

Else (waypoint in range + resolved): **skip hash**, return that object.

### 3.6 VOG hash traversal — **SEALED** structure (pattern)

| Field | Offset / path |
|---|---|
| Hash root ptr | `*(DAT_00d1b644 + 0xe8f4)` |
| Traversal lock | `root + 0x1d` (byte; set 1 before walk, clear 0 after) |
| First node | `root + 0x14` |
| Next node | `node + 0x20` |
| TFID* | `*(node + 0xc)` |
| Asserts | `"HashError:TraversalLock..."` / `"HashError:TraverseToNext..."` + `"VOG_DEBUG_STOP"` via `FUN_007a4480` |

Same TraversalLock pattern as other VOG hash walkers (inventory/mission). **Not** a unique “debug stop” function — prior `Named_VOG_DEBUG_STOP_*` alias is a string-hit misnomer.

### 3.7 Optional entry predicate — **Probable** (typed open)

When decompiler field `pTfid[1].dwCoidHi != 0` (type confusion on TFID overlay — likely an adjacent object/vptr field on the hash payload):

```
ctx = adj of *(DAT_00d1b6d8 + 0x250)   // may be 0
if (! (*(bool(**)())(*(int*)field + 0x64))(ctx) ) continue;  // skip entry
```

Then `Object_ResolveFromTFID(pTfid)` + radius test.

Exact C++ type of the field / vfunc+0x64 English name remains **open**.

### 3.8 Side effects — **SEALED**

| Effect | Notes |
|---|---|
| Hash lock byte `+0x1d` | Set/clear around walk |
| Possibly `Client_EvalAutoPatrolWaypoint` AutoPatrol C2S `0x20B3` | **Callee** may send if its own gates fire — **not** this unit’s packet |
| No UseObject / no sector opcode in **this** body | Callers decide send |

---

## 4. Callers (product use)

| Parent | How return is used |
|---|---|
| `Client_Input_PollBoundActions` | Activate UseObject fallback after gather miss → target for `Client_SendUseObject` / IfInteractable |
| `Client_RecvCompleteDynamicObjective` | Find world object near player with `clone+0x34 ==` objective key → optional `Client_SendUseObject` |
| `FUN_009210e0` | Fallback after gather; ESI = result then tip/UI path (return may be lightly used) |

---

## 5. Confidence

| Claim | Level |
|---|---|
| ABI `float` + `RET 4` + Object* EAX | **High** |
| All callers push **15.0f** | **High** |
| First-in-radius, **not** true nearest | **High** |
| Waypoint prefer then hash | **High** |
| Player vtbl+0x1a0 float4 origin | **High** |
| Object pos `+0x80/84/88` | **High** |
| Hash lock / list offsets | **High** (pattern + strings) |
| Predicate field / vfunc+0x64 name | **Tentative** |
| PDB/product symbol | **Open** (INFERRED name) |
| Runtime / bit-exact | **Open** |

---

## 6. Gaps (carry to B + report)

1. Predicate overlay (`pTfid[1].dwCoidHi`) real type / vfunc+0x64 identity.
2. Whether hash walk order is insertion / bucket order (product “nearest” UI may still feel random).
3. `FUN_009210e0` post-return use depth (outside OWN scope).
4. Runtime live pick confirmation.
5. English/PDB name.
