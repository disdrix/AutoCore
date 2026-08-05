# Review A (reconstruction fidelity): `aa_004dbef0` CVOGReaction_RegisterObjectHashEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbef0` |
| **VA** | `0x004dbef0`–`0x004dc02a` |
| **Canonical name** | `FUN_004dbef0` (proposed: `CVOGReaction_RegisterObjectHashEntry_Inferred`) |
| **Prior names** | `Named_CalleeOf_CVOGReaction_SpawnObject_004dbef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004dbef0_CVOGReaction_RegisterObjectHashEntry_Inferred.md` |
| **System** | client world object hash / spawn-link |
| **Evidence pass** | Live Ghidra `batch_decompile` + `disassemble_function` (ABI-critical) + callees `0x004e23d0`/`0x004e3170`/`0x004e7d30`/`0x004bb1c0` decompile (2026-07-29) |
| **Verdict** | **accept-with-gaps** (CF/ABI sealed; descriptor English + hash product name open) |

---

## 1. Purpose

Host method: **remove any existing 64-bit-key hash entry for an object's TFID, allocate a 0x28-byte link descriptor, resolve optional target, store descriptor on the object, insert into host object hash**.

Used when spawning objects, creating creatures, rebinding after mission complete (`FUN_004de9f0`), and peer reaction paths.

Steps (assembly-sealed; decompiler **drops host `this`**):

1. `host = ECX`; `obj = arg0`.
2. `tfidLo/Hi = obj+0x160 / +0x164` (standard object COID/TFID halves).
3. Table = `*(host+0xe8f4)`. Walk `FUN_004e23d0(tfidLo, tfidHi)`; if node payload `node+0xc != 0`, **remove** via `FUN_004e3170` (CNDHash-family remove; strings `HashError:remove…`).
4. `operator_new(0x28)` zero-init 10 dwords → descriptor `desc`.
5. Fill:
   - `desc+0x00..+0x0c` ← `obj+0x160..+0x16c` (full 16-byte id block)
   - `desc+0x10 = 0`
   - `desc+0x18 = arg2` (link/target lo)
   - `desc+0x1c = arg3` (link/target hi)
   - `desc+0x20 = arg4` (flags; callers pass `-1`)
6. `desc+0x14 = FUN_004bb1c0(0, arg2, arg3)` with **ECX = *(host+0xe4e8)** — resolve context; wraps `CVOGReaction_ResolveObjectTarget` then vfunc `+0x1e8` (0 if unresolved).
7. Store `*(obj+0x11c) = desc`.
8. If `obj+0xa4 != 0`: double-call object vfunc `+0x1cc`; on non-null, `FUN_00493e90(*(host+0xe898), *(ret+8))` (queue/push related).
9. Insert into hash: `FUN_004e7d30` this=`*(host+0xe8f4)` (reloaded), key=`desc+0/4`, value=`desc`, soft=`0`. On non-zero HRESULT-style fail → `operator_delete(desc)` (noreturn path in decompiler; listing continues to epilog after delete).

**Does not** spawn mesh/physics, set position, or own mission state.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004dbef0_FUN_004dbef0.md` |
| Annotated | `docs/reconstruction/raw/aa_004dbef0_FUN_004dbef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004dbef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004dbef0_FUN_004dbef0.md` |
| Live listing | `disassemble_function` `0x004dbef0` — **`RET 0x14`**, `MOV EDI,ECX` |
| Callers | `CVOGReaction_SpawnObject`, `CVOGSpawnPoint_CreateCreature`, `FUN_004de9f0`, `FUN_004dd940`, `FUN_004de760`, `FUN_0080af70` |
| Related duals | `A_aa_004bae70_CVOGReaction_ResolveObjectTarget`; `A_aa_004de550_CVOGReaction_SpawnObject` |

**Not performed:** `disassemble_bytes`, runtime hash dumps, product PDB names.

---

## 3. Signature (assembly-sealed — decompiler incomplete)

```c
// __thiscall  ECX = host (reaction/map root with +0xe8f4 hash, +0xe4e8 resolve ctx, +0xe898 queue)
// stack cleaned by callee: ret 0x14  (5 dwords)
void CVOGReaction_RegisterObjectHashEntry_Inferred(
    void *host,          // this ECX
    void *obj,           // stack+4  — CVOGObject* (often MI subobject this)
    uint32_t unused,     // stack+8  — callers pass 0; body never reads
    uint32_t linkLo,     // stack+0xc — resolve / desc+0x18
    uint32_t linkHi,     // stack+0x10 — resolve / desc+0x1c
    int32_t  flags);     // stack+0x14 — desc+0x20; typically -1
```

Key listing facts:

```text
004dbef0  PUSH EBX
004dbef1  MOV EBX, [ESP+8]          ; obj
004dbefe  MOV EDI, ECX              ; host
004dbf06  MOV ESI, [EDI+0xe8f4]     ; object hash table
...
004dbfd3  MOV [EBX+0x11c], ESI      ; store desc on object
...
004dc014  CALL FUN_004e7d30         ; insert
004dc02a  RET 0x14
```

Raw decompile shows only stack params and invents `FUN_004e23d0(iVar5,param_1[0x59],…)` without showing table this — prefer listing for table ECX.

---

## 4. Descriptor layout (0x28)

| Off | Source | Role |
|---|---|---|
| +0x00 | obj+0x160 | key lo (TFID/COID) |
| +0x04 | obj+0x164 | key hi |
| +0x08 | obj+0x168 | id block dword2 |
| +0x0c | obj+0x16c | id block dword3 |
| +0x10 | 0 | cleared |
| +0x14 | Resolve+vfunc path | target-related payload / 0 |
| +0x18 | arg2 | link lo |
| +0x1c | arg3 | link hi |
| +0x20 | arg4 | flags (−1 common) |
| +0x24 | 0 | cleared at alloc |

Object slot **`+0x11c`** holds live descriptor pointer after success path store (even if insert later fails and deletes — store happens before insert).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall host + `RET 0x14` (5 stack args) | **High** | listing |
| arg1 unused (always 0 at known sites) | **High** | no body read |
| TFID key at obj `+0x160/+0x164` | **High** | project-wide COID pattern |
| Remove-if-present then insert | **High** | 004e23d0 + 004e3170 + 004e7d30 |
| Hash table host `+0xe8f4` | **High** | load ESI / reload EDI field |
| Resolve ctx host `+0xe4e8` | **High** | ECX before 004bb1c0 |
| Store desc at obj `+0x11c` | **High** | `MOV [EBX+0x11c],ESI` |
| Optional gfx/queue when `+0xa4` | **High** CF; English **Open** | vfunc +0x1cc / 00493e90 |
| Product name “RegisterObjectHashEntry” | **Inferred** | structural |
| Insert fail deletes desc | **High** | TEST EAX; delete; listing does not show second store clear |

---

## 6. Surviving contract

```
RegisterObjectHashEntry(host, obj, _unused0, linkLo, linkHi, flags=-1):
  table = host.objectHash (+0xe8f4)
  if existing payload for (obj.tfidLo, obj.tfidHi): table.remove(...)
  desc = new 0x28 zeroed
  desc.id = obj.id16
  desc.link = (linkLo, linkHi, flags)
  desc.target = ResolveThenVfunc1e8(host.resolveCtx, 0, linkLo, linkHi)
  obj.descSlot(+0x11c) = desc
  maybeQueueGfx(host, obj)
  if table.insert(desc.tfid, desc) fails: delete desc
```

---

## 7. Gaps / open

1. Product names for `FUN_004e7d30` / table at `+0xe8f4` / descriptor type.
2. Semantic of `+0x14` post-`vfunc+0x1e8` (handle vs object vs null-ok).
3. Whether insert-fail leaves stale `obj+0x11c` (store-before-insert order).
4. arg1 historical meaning (padding vs forgotten flag).

**Verdict:** **accept-with-gaps**
