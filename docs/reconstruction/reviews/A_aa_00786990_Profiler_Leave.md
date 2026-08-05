# Review A (reconstruction fidelity): `aa_00786990` Profiler_Leave

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786990` |
| **VA** | `0x00786990` |
| **Canonical name** | `Profiler_Leave` (Probable; prior scaffold `FUN_00786990`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (profiler scope pop / leave) |
| **Counterpart** | `reviews/B_aa_00786990_Profiler_Leave.md` |
| **System** | client instrumentation / profile scope (paired with enter `0x00786a00`; **not** mission logic) |
| **Path context** | Callee of `CVOGCharacter_SearchAutoMissions` `0x00532b60` (early-out + normal exit bookends) |
| **Verdict** | **accept-with-gaps** (CF + ABI + layout sealed; product English / divisor source open) |

---

## 1. Purpose

**Pop one nested profiler scope** on the global profiler object (`DAT_00afa27c`):

1. If profiler **disabled** (`*(char*)(this+0x175) == 0`) → no-op return.
2. Resolve **per-thread slot index** via `FUN_007866e0(this)` (array of 12-byte entries at `this+0x4c`).
3. Load **current scope node** from `slot[index].current` (`entry+0x8`).
4. Point `ESI` at the node's **timer block** (`node+0x4`) and call `FUN_00780690` (QPC delta → accumulate + last/max/avg/count).
5. Scale full accumulator: `__alldiv(accum64, divisor64)` → add into **`node+0x28`** (lifetime hierarchical total).
6. If **`node+0x8` (parent)** non-null → write parent back as `slot[index].current` (stack pop).

**Not mission logic.** SearchAutoMissions only uses this as instrumentation bookend after `Profiler_Enter("CVOGCharacter::SearchAutoMissions")`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00786990_FUN_00786990.md` |
| Annotated | `docs/reconstruction/raw/aa_00786990_FUN_00786990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00786990.cpp` (+ alias `Profiler_Leave` plate) |
| Function record | `docs/reconstruction/functions/aa_00786990_FUN_00786990.md` |
| Live decompile | Ghidra MCP `decompile_function` `0x00786990` — CF ≡ raw scaffold |
| Live assembly | Ghidra `disassemble_function` `0x00786990` (full body) |
| Enter sibling | `disassemble_function` / `batch_decompile` `0x00786a00` |
| Timer accumulate | `disassemble_function` `0x00780690` |
| Thread-slot helper | `batch_decompile` `0x007866e0` |
| Xrefs | `get_function_xrefs` — 8 sites |
| Call-site framing | `get_assembly_context` SearchAutoMissions leave sites + thunk `0x00480160` |
| Profile string | `read_memory` `0x009cff4c` → `"CVOGCharacter::SearchAutoMissions\0"` |

**Not performed:** `disassemble_bytes` bulk, Launcher, live QPC capture, bit-exact image diff. **OWN VA only** — callees documented for framing, not dualed here.

---

## 3. Signature (assembly-backed)

```c
// MSVC: ECX = profiler manager* at entry; no stack formals; RET
void __fastcall Profiler_Leave(void *profiler /* ECX */);
// Equivalent production use: thiscall on *DAT_00afa27c with zero stack args.
```

| Slot | Role | Evidence |
|---|---|---|
| Entry `ECX` | Profiler manager (`DAT_00afa27c`) | `MOV EBX,ECX` @ `0x00786991`; all live sites `MOV ECX,[0x00afa27c]` before call |
| Return | void | `RET` @ `0x007869f0` |
| `ESI` (internal) | Timer block for `FUN_00780690` | `MOV ESI,[EDI+4]` before call @ `0x007869ae` |

Decompiler label `__fastcall` matches ECX-this; **not** a character pointer (SearchAutoMissions character lives in `EBP`).

---

## 4. Layout (sealed from leave + enter + accumulate)

### 4.1 Profiler manager (`this` / `DAT_00afa27c`)

| Offset | Field | Evidence |
|---|---|---|
| `+0x4c` | Thread-slot array base (`ThreadSlot*`) | Leave load; enter store; `FUN_007866e0` walk |
| `+0x50` | Thread-slot end (used as size: `(end-base)/0xc`) | `FUN_007866e0` only |
| `+0x58` | `CRITICAL_SECTION` | `FUN_007866e0` Enter/Leave |
| `+0x175` | Enable flag (`char`) | Leave `CMP [EBX+0x175],0`; enter same polarity inverted |

### 4.2 Thread slot entry (`0xC` bytes)

| Offset | Field | Evidence |
|---|---|---|
| `+0x00` | `DWORD threadId` | `FUN_007866e0` match `GetCurrentThreadId` |
| `+0x08` | **current scope node\*** | Leave read/write; enter write |

Index math: `LEA EAX,[idx+idx*2]` then `*4` → `idx * 0xC`.

### 4.3 Profile scope node

| Offset | Field | Evidence |
|---|---|---|
| `+0x04` | Timer sample block\* | `MOV ESI,[EDI+4]`; re-load for `__alldiv` |
| `+0x08` | **Parent node\*** (stack link) | `MOV EDI,[EDI+8]`; null → skip restore |
| `+0x28` | Hierarchical total (`int`, += scaled sample) | `ADD [EDI+0x28],EAX` after `__alldiv` |
| `+0x3c` | Nest/ref counter (enter path) | `FUN_00785e00` / create path only |

### 4.4 Timer sample block (`ESI` for `FUN_00780690`)

| Offset | Field | Evidence (leave + `0x00780690`) |
|---|---|---|
| `+0x00/+0x04` | QPC start (lo/hi) | Subtract from `QueryPerformanceCounter` |
| `+0x08/+0x0c` | Accumulated ticks (lo/hi) | `ADD/ADC`; leave feeds `__alldiv` num |
| `+0x10/+0x14` | Divisor / frequency (lo/hi) | Leave + accumulate denom |
| `+0x18/+0x1c` | Running average (lo/hi) | accumulate only |
| `+0x20` | Sample count | `ADD [ESI+0x20],1` |
| `+0x24` | Last scaled sample | accumulate |
| `+0x28` | Max scaled sample | accumulate |

---

## 5. Control flow (sealed — live assembly)

```
Profiler_Leave(profiler /*ECX*/):
  if *(char*)(profiler + 0x175) == 0:
    return

  idx = FUN_007866e0(profiler)           // per-thread slot (create on miss)
  node = *(profiler->slots + idx*0xC + 8)
  timer = *(node + 4)
  FUN_00780690()                         // ESI=timer: QPC delta → accum/last/max/avg/count

  scaled = __alldiv(timer->accum64, timer->divisor64)   // 64/64 → 32 in EAX
  *(int*)(node + 0x28) += scaled

  parent = *(node + 8)
  if parent != 0:
    idx = FUN_007866e0(profiler)
    *(profiler->slots + idx*0xC + 8) = parent
  return
```

### 5.1 Decisive assembly (own body)

```
00786990  PUSH EBX
00786991  MOV EBX, ECX
00786993  CMP byte ptr [EBX+0x175], 0
0078699a  JZ  RET_PATH
0078699e  PUSH EBX
0078699f  CALL FUN_007866e0
007869a4  MOV ECX, [EBX+0x4c]
007869a7  LEA EAX, [EAX+EAX*2]
007869aa  MOV EDI, [ECX+EAX*4+8]     ; current node
007869ae  MOV ESI, [EDI+4]           ; timer block
007869b4  CALL FUN_00780690
007869b9  MOV EAX, [EDI+4]
007869bc..cb  push divisor hi/lo, accum hi/lo
007869cc  CALL __alldiv (0x006a3f00)
007869d1  ADD [EDI+0x28], EAX
007869d4  MOV EDI, [EDI+8]           ; parent
007869d7  TEST EDI, EDI
007869d9  JZ  epilogue
007869db  PUSH EBX / CALL FUN_007866e0
007869ea  MOV [slot+8], EDI          ; pop
007869f0  RET
```

### 5.2 Pair with enter (`0x00786a00`) — framing only

| Step | Enter | Leave |
|---|---|---|
| Enable gate | `+0x175 == 0` → return 0 | `+0x175 == 0` → return |
| Thread slot | `FUN_007866e0` | same |
| Current node | read then **lookup/create named child** (`FUN_00786470`) | read then **pop parent** |
| Timing | `FUN_00785e00` start stamp / zero counters | `FUN_00780690` stop + `node+0x28` |
| Stack formal | name `char*` (`RET 4`) | none (`RET`) |

SearchAutoMissions sites (both):

```
MOV ECX, [0x00afa27c]
CALL Profiler_Leave   ; @ 0x00532bb1 early wrapper-null path
                      ; @ 0x00532d0e normal unlock path
```

Enter site uses same global + push `"CVOGCharacter::SearchAutoMissions"` @ `0x009cff4c`.

---

## 6. Callers (xrefs, limit 100)

| Site | Function | Role |
|---|---|---|
| `0x00532bb1`, `0x00532d0e` | `CVOGCharacter_SearchAutoMissions` | Mission auto-grant profile bookends |
| `0x0051b504`, `0x0051b536` | `FUN_0051b350` | `"ServerCreateFromPacket"` scope leave |
| `0x00520e0b`, `0x00520f1e` | `FUN_00520dc0` | `"CVOGCharacter::CleanupDraggingObject"` leave |
| `0x00727659` | `FUN_00727440` | (other scoped path) |
| `0x00480160` | thunk | `MOV ECX,[DAT_00afa27c]; JMP Profiler_Leave` |

All inspected sites load **`DAT_00afa27c`** into `ECX` before call/jmp.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = global profiler, not character | **High** | assembly + all xrefs |
| Enable gate `+0x175` | **High** | leave + enter |
| Thread slots `+0x4c`, stride `0xC`, current at `+8` | **High** | leave math + `FUN_007866e0` |
| `FUN_00780690` uses ESI=timer (`node+4`) | **High** | explicit `MOV ESI` |
| `node+0x28 += scaled(accum/div)` | **High** | `ADD` after `__alldiv` |
| Parent pop via `node+8` | **High** | TEST + store |
| No-op when disabled | **High** | early JZ |
| Product name `Profiler_Leave` | **Probable** | behavior sealed; no PDB |
| Divisor = `QueryPerformanceFrequency` units | **Probable** | pattern; writer of `+0x10/+0x14` not fully walked this unit |
| Exact unit of `node+0x28` (µs/ms/ticks) | **Tentative** | depends on divisor init |
| Parent-null leave leaves current unchanged | **High** (static) | JZ skips store |

---

## 8. Surviving contract (port)

```
// Optional client instrumentation only — omit in server sim if no profiler host.
void Profiler_Leave(Profiler* p /* = *g_profiler @ DAT_00afa27c */):
  if (!p || !p->enabled) return;          // +0x175
  slot = ensure_thread_slot(p);           // FUN_007866e0
  node = slot->current;                   // +8
  stop_and_accumulate(node->timer);       // FUN_00780690
  node->hierarchicalTotal += scale(node->timer->accum, node->timer->divisor);
  if (node->parent) slot->current = node->parent;
```

**Port note:** Safe to no-op entirely; SearchAutoMissions / CreateFromPacket / CleanupDragging behavior does not depend on profiler side effects beyond nested current-node bookkeeping for other profiled scopes.

---

## 9. Open residual

1. Product English for manager / node / timer types (PDB / RTTI).
2. Who writes timer divisor at `+0x10/+0x14` (likely QPF once at init).
3. Semantic unit of hierarchical total `node+0x28`.
4. Full `FUN_007866e0` array-append CF when creating new thread (helper `FUN_00480ca0`) — framing only.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — leave CF dual-ready; mission path only *uses* this as profile pop.
