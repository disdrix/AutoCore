# Review A (reconstruction fidelity): `aa_005172d0` Object_SetSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_005172d0` |
| **VA** | `0x005172d0` |
| **Canonical name** | `Object_SetSelectedTarget` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005172d0_Object_SetSelectedTarget.md` |
| **System** | object / combat-target / HB |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set the entity’s **selected combat/target pointer** at **`entity+0xA0`**. On real change (and only when world + global HB list exist): dirty net mask bit **4**, purge **`CVOGHBPlayerTargetingLink`** heartbeat actions from **`entity+0xB0`**, store the new pointer, and if the new target is non-null and not self, allocate a **paired** HB pair (self-side PlayerTargetingLink + target-side base HB), cross-link partners at **`+0x24`**, and enqueue both on **`world+0xE4EC`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (scaffold) | `docs/reconstruction/raw/aa_005172d0_FUN_005172d0.md` |
| Raw (canonical) | `docs/reconstruction/raw/aa_005172d0_Object_SetSelectedTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_005172d0_Object_SetSelectedTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetSelectedTarget.cpp` |
| Function record | `docs/reconstruction/functions/aa_005172d0_Object_SetSelectedTarget.md` |
| Live tools | Ghidra `decompile_function`, `read_memory` (300 B), `get_function_pcode`, `analyze_function_complete`, `get_function_callers`, callees `0x00512090` / `0x00604d40` / `0x00604db0` / `0x005121d0` / `0x004e2600` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI **`__thiscall`**: ECX = entity, stack arg = new target, **`ret 4`** | **High** | Bytes end `C2 04 00`; pcode ECX register offset 4; stack arg at `[esp+0x1c]` after frame setup |
| Body range **`005172d0`–`005173f9`** (`int3` pad at `005173fa`) | **High** | `get_function_by_address` + hex length |
| Early-out if `newTarget == *(entity+0xA0)` | **High** | `cmp edi,[esi+0xa0]` / `je` exit |
| Gate: `entity+0xA4 != 0` **and** `*(world+0xE4EC) != 0` else **silent no-op** (does **not** write `+0xA0`) | **High** | Two `je` exits before any store |
| `entity+0xA0` = selected target pointer (DWORD) | **High** | Read/compare/write; callers pass entity pointers / 0 |
| `entity+0xA4` = world/map context holding HB list | **High** | Load then `+0xE4EC` enqueue path; same pattern as other HB callers |
| `world+0xE4EC` = `CVOGHBList*` | **High** | `CVOGHBList_Enqueue` this |
| `entity+0x14` = `NetObject*`; dirty **`NetObject_SetMaskBits(net, 4, 0)`** if non-null | **High** | `push 0; push 4; call` |
| **List purge this = `entity+0xB0`** (decomp false-omitted ECX) | **High** | Bytes at `0x00517333`: `8B 8E B0 00 00 00` then push predicate |
| Predicate `FUN_005121d0`: RTTI → **`CVOGHBPlayerTargetingLink`**, destroy via vtbl+0x18(1,0), return 1 to remove | **High** | Live decompile of `0x005121d0` |
| List walk/remove helper `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`) with args `(predicate, 0, 0)` | **High** | Call site pushes + plate on helper |
| Early store `+0xA0 = new` **only if old `+0xA0 != 0`**, then always store after purge | **High** | Asm `cmp [esi+0xa0],0` / conditional mov / unconditional mov after call |
| Dual HB only if `new != 0 && new != entity` | **High** | `cmp edi,0` / `cmp edi,esi` exits |
| Alloc size **`0x28`** ×2 via `operator_new` | **High** | `push 0x28` twice |
| Self-side ctor **`FUN_00512090(self)`** → base ctor then vtbl **`PTR_FUN_009cdfd4`** (PlayerTargetingLink family) | **High** | Callee decompile + RTTI on destroy predicate |
| Target-side ctor **`FUN_00604d40(newTarget)`**: `CVOGHBBase_ctor`, vtbl `009cdfb0`, attach owner, flags/period **2 / −1000 / 1000**, `Start` | **High** | Callee decompile (constants sealed on callee, not re-owned) |
| **`FUN_00604db0` cross-link both ways**: `selfLink.partner(+0x24)=targetLink` then `targetLink.partner=selfLink` (unless `+0x18` equal when partner non-null) | **High** | Asm: `push edi; mov ecx,ebx; call`; `push ebx; mov ecx,edi; call` — decomp dropped 2nd args |
| Enqueue order: **self link first**, then **target link** | **High** | Two sequential `CVOGHBList_Enqueue` |
| Clear target: `newTarget==0` still purges links + stores 0; **no** new HB pair | **High** | Branch before allocs |
| Self-target: store self at `+0xA0`, purge, **no** HB pair | **High** | `cmp edi,esi` |
| Product C++ method name | **Tentative** | No string; name **inferred** from RTTI + field role |
| Clean ≡ asm control flow (after `+0xB0` / cross-link seal) | **High** | Refined clean fixes scaffold omissions |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| SEH frame / save EBX ESI EDI | **Yes** |
| `new == [this+0xA0]` → ret | **Yes** |
| null world or null `world+0xE4EC` → ret (no write) | **Yes** |
| optional net dirty mask 4 | **Yes** |
| early write if old non-null | **Yes** |
| `CNDDoubleList…(this+0xB0, pred, 0, 0)` | **Yes** (raw scaffold omitted `+0xB0` ECX) |
| store `+0xA0 = new` | **Yes** |
| dual new/cross-link/enqueue iff new≠0 ∧ new≠self | **Yes** |
| `ret 4` | **Yes** |

### Byte seal (key sites from `read_memory` @ `0x005172d0`)

```
005172ee  3B BE A0 00 00 00     cmp edi, [esi+0xA0]
005172fa  8B 86 A4 00 00 00     mov eax, [esi+0xA4]
0051730a  39 98 EC E4 00 00     cmp [eax+0xE4EC], ebx
00517316  8B 4E 14              mov ecx, [esi+0x14]
0051731d  53 6A 04              push 0; push 4   ; NetObject_SetMaskBits
0051732d  89 BE A0 00 00 00     mov [esi+0xA0], edi   ; early (predicated)
00517333  8B 8E B0 00 00 00     mov ecx, [esi+0xB0]   ; list this
0051733b  68 D0 21 51 00        push FUN_005121d0
00517345  89 BE A0 00 00 00     mov [esi+0xA0], edi   ; always after purge
... dual alloc/ctor/link/enqueue ...
005173f8  C2 04 00              ret 4
```

---

## 5. Algorithm (authoritative)

```
// __thiscall Object_SetSelectedTarget(entity, newTarget)
if (newTarget == entity->selectedTarget)  // +0xA0
    return;
world = entity->world;                    // +0xA4
if (world == null || world->hbList == null)  // +0xE4EC
    return;  // selectedTarget UNCHANGED

if (entity->netObject)                    // +0x14
    NetObject_SetMaskBits(netObject, 4, 0);

if (entity->selectedTarget != null)
    entity->selectedTarget = newTarget;   // early write

CNDDoubleList_InvokePredicateAndRemove(
    entity->hbActionList,                 // +0xB0
    IsPlayerTargetingLinkAndDestroy,      // 0x005121d0
    ctx=0, stopFlagArg=0);

entity->selectedTarget = newTarget;       // always

if (newTarget != null && newTarget != entity) {
    selfLink  = new(0x28) ? CVOGHBPlayerTargetingLink_ctor(self=entity) : null;  // 0x00512090
    targetHb  = new(0x28) ? CVOGHBBase_Targeting_ctor(attach=newTarget) : null; // 0x00604d40
    LinkPartner(selfLink, targetHb);   // 0x00604db0: +0x24
    LinkPartner(targetHb, selfLink);
    CVOGHBList_Enqueue(world->hbList, selfLink);
    CVOGHBList_Enqueue(world->hbList, targetHb);
}
```

---

## 6. Call surface (not owned)

| Caller (sample) | Use |
|---|---|
| `CVOGHBAIBase_FindTargetToAttack` | Commit AI-selected target (or 0) |
| `Client_Input_DriveControlTick` | Client target updates while driving |
| `GhostCreature_UnpackUpdate` / `VehicleNet_UnpackGhostVehicle` | Net apply of remote target |
| `CVOGReaction_Dispatch` paths | Often clear with `0` |
| Other FUN_* combat/UI | 30 xrefs total |

---

## 7. Gaps / open

1. Product method name (no string); `Object_SetSelectedTarget` is **inferred**.
2. Exact product field names for `+0xA0` / `+0xA4` / `+0xB0` / `+0x14`.
3. Semantic meaning of net mask bit **value 4** (which ghost field).
4. Why early write before purge (reentrancy / callback observation) — behavior sealed, motive open.
5. Full behavior of partner link `+0x18` equality gate inside `FUN_00604db0` (callee-owned).
6. What the targeting HB **ticks** do after enqueue (not this body).
7. Runtime / bit-exact image diff not run.
8. Duplicate scaffold files under `FUN_005172d0` naming — prefer `Object_SetSelectedTarget` paths.

**Verdict:** **accept-with-gaps**
