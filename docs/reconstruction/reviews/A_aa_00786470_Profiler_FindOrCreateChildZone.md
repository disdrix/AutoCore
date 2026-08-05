# Review A (reconstruction fidelity): `aa_00786470` Profiler_FindOrCreateChildZone

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786470` |
| **VA** | `0x00786470` |
| **Canonical name** | `FUN_00786470` (Probable: `Profiler_FindOrCreateChildZone`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (named child zone map) |
| **Counterpart** | `reviews/B_aa_00786470_Profiler_FindOrCreateChildZone.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Sole caller: enter `0x00786a00` @ `0x00786a2c` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lookup or insert a named child profiler zone** under a **parent zone node** (`this`):

1. Build `std::string` from `name` (stack formal).
2. `FUN_00430ce0` — map **lower_bound** on parent’s child map (map object at `this+0x1c`, red-black sentinel/header at `this+0x20`).
3. If iterator is not end **and** key not strictly less than name → **hit**: return mapped value at **map-node `+0x28`** (existing zone*).
4. If miss (iterator == end / key ordering says insert):  
   - `operator_new(0x5c)` + `FUN_00786280(node, name)` construct zone  
   - `FUN_004406e0` — push pointer into a contiguous child-ptr vector (register ABI)  
   - `FUN_004309c0(this+0x1c)` — **map insert** of `(name → zone*)`  
   - return new zone*
5. SEH / string dtors clean temps.

Paired with enter’s `FUN_00785e00` (start timer on returned zone) — **not** owned here.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00786470_FUN_00786470.md` |
| Annotated | `docs/reconstruction/raw/aa_00786470_FUN_00786470.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00786470.cpp` |
| Function record | `docs/reconstruction/functions/aa_00786470_FUN_00786470.md` |
| Live decompile | Ghidra `batch_decompile` @ `0x00786470` (2026-07-29) ≡ raw |
| Map lower_bound | `batch_decompile` `0x00430ce0` (string-key tree walk) |
| Map insert | `batch_decompile` `0x004309c0` |
| Ptr vector push | `batch_decompile` `0x004406e0` |
| Zone ctor | `batch_decompile` `0x00786280` |
| Caller asm | `get_assembly_context` @ `0x00786a2c` |
| Xrefs | `get_bulk_xrefs` — **1** site (enter only) |

**Not performed:** `disassemble_bytes`, Launcher, full STL node layout bit-exact. **OWN VA.**

---

## 3. Signature (assembly-backed)

```c
// MSVC thiscall: ECX = parent Zone*; stack0 = const char* name; RET 4 (caller enter uses RET 4 on whole enter, this callee cleans its own formal per thiscall)
void * __thiscall Profiler_FindOrCreateChildZone(Zone *parent /* ECX */, const char *name /* stack0 */);
```

| Slot | Role | Evidence |
|---|---|---|
| `ECX` / `param_1` | **Parent zone**, not profiler | Enter: `MOV EAX,[slot+8]`; `MOV ECX,EAX`; `CALL 0x00786470` |
| stack0 | Zone name C-string | Enter: `PUSH EDX` (name) |
| return `EAX` | Zone node* | Enter: `MOV EDI,EAX` then start timer |

---

## 4. Layout (parent zone + map)

| Offset (parent) | Field | Evidence |
|---|---|---|
| `+0x1c` | `std::map` / tree root object (insert target) | `FUN_004309c0(param_1 + 0x1c)` |
| `+0x20` | Map end / header sentinel pointer | Compare `local_88` / `pvVar3` to `*(param_1+0x20)` |

| Map node (hit path) | Field | Evidence |
|---|---|---|
| `+0x0c` | Key `basic_string` | `operator<` vs lookup string |
| `+0x28` | Mapped **zone\*** | `pvVar3 = *(hit + 0x28)` |

| New zone | Value | Evidence |
|---|---|---|
| Alloc | `0x5C` | `operator_new(0x5c)` same as thread-root |
| Ctor | `FUN_00786280(..., name)` | Name stored; timer via `FUN_00780730` |

---

## 5. Control flow (sealed)

```
FindOrCreateChildZone(parent, name):
  key = string(name)
  it = map_lower_bound(parent.childrenMap /* +0x1c */, key)   // FUN_00430ce0
  if it == end || key < it->key:   // miss (decompiler: end OR operator< true → use end)
    zone = new Zone(name)          // 0x5c + FUN_00786280
    vector_push(parent.childPtrs, zone)  // FUN_004406e0
    map_insert(parent.childrenMap, key, zone)  // FUN_004309c0
    return zone
  else:
    return it->value               // *(node + 0x28)
```

### 5.1 Caller framing (enter only)

```
00786a26  MOV EAX, [slot + 8]     ; parent = current zone
00786a29  PUSH EDX                ; name
00786a2a  MOV ECX, EAX
00786a2c  CALL FUN_00786470
00786a31  MOV EDI, EAX            ; zone
00786a33  CALL FUN_00785e00       ; StartZoneTimer(zone) via EAX
```

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` = parent zone (slot current) | **High** | Live asm at enter |
| Name string formal | **High** | PUSH + string ctors |
| Map @ `+0x1c`, end @ `+0x20` | **High** | Insert arg + end compares |
| Hit returns `*(it+0x28)` | **High** | Explicit load |
| Miss allocates `0x5C` + ctor | **High** | Body |
| Same name reuses existing child | **High** | Hit path no new |
| Product English “FindOrCreate” | **Probable** | Behavior |
| Exact MSVC map node padding | **Tentative** | STL version variance |
| `FUN_004406e0` target vector offset on parent | **Med** | Register ABI; children list role High, base offset not fully sealed in this unit |
| Parent pointer field wiring in ctor | **Med** | Leave uses zone`+8` parent; ctor param wiring decompiler-muddy |

---

## 7. Surviving contract (port)

```
// Client instrumentation only.
Zone* Profiler_FindOrCreateChildZone(Zone* parent, const char* name);
// Hierarchical names under current stack top; enter then StartZoneTimer + push.
```

Safe to no-op entire enter path on server.

---

## 8. Open residual

1. Full zone node field map beyond map/timer/nest/parent used by enter/leave.
2. Child pointer vector base offset on zone.
3. Whether map allows multi-insert same key (insert helper returns existing on equal).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — find-or-create spine dual-ready for enter.
