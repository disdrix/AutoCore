# Review A (reconstruction fidelity): `aa_007866e0` Profiler_EnsureThreadSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_007866e0` |
| **VA** | `0x007866e0` |
| **Canonical name** | `FUN_007866e0` (Probable: `Profiler_EnsureThreadSlot`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (per-thread profiler slot index) |
| **Counterpart** | `reviews/B_aa_007866e0_Profiler_EnsureThreadSlot.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Callee of enter `0x00786a00` (×2) and leave `0x00786990` (×2) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve (or create) the per-thread slot index** on the profiler manager:

1. `GetCurrentThreadId()`.
2. `EnterCriticalSection(profiler + 0x58)`.
3. Linear walk of the thread-slot vector at `profiler+0x4c` … `profiler+0x50` with **stride `0xC`**: if entry `+0` matches TID → `LeaveCriticalSection` and **return index**.
4. On miss: allocate root zone node `operator_new(0x5c)` + `FUN_00786280(node, "Hermann")`; inline start-timer on that node (nest `+0x3c`++, zero timer sample fields, `QueryPerformanceCounter` into start); append slot via `FUN_00480ca0` (vector embed ≈ `profiler+0x48`, element packs TID + current zone); **return `count - 1`** (new last index).
5. Always leave CS before return on create path.

**Not mission logic.** Pure TLS-ish bookkeeping for the named-zone enter/leave stack.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007866e0_FUN_007866e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007866e0_FUN_007866e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007866e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007866e0_FUN_007866e0.md` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x007866e0` (2026-07-29) — CF ≡ raw |
| Root-zone string | `read_memory` @ `0x00a9adc4` → `"Hermann\0"` |
| Zone ctor (framing) | `batch_decompile` `0x00786280` |
| Slot append (framing) | `batch_decompile` `0x00480ca0` (vector push stride `0xC`) |
| Timer ctor (divisor) | `decompile_function` `0x00780730` — QPF/`1000000` (µs scale) |
| Callers | `get_bulk_xrefs` — only enter/leave sites |
| Parent duals | `A/B_aa_00786a00_*`, `A/B_aa_00786990_*` (slot layout seal) |

**Not performed:** `disassemble_bytes` bulk, Launcher, live multi-thread race capture. **OWN VA** — callees framed only.

---

## 3. Signature (assembly / caller-backed)

```c
// Stack formal: profiler* (callers PUSH profiler then CALL).
// Return: EAX = thread-slot index (0-based).
int Profiler_EnsureThreadSlot(Profiler *profiler /* stack0 */);
```

| Slot | Role | Evidence |
|---|---|---|
| stack0 / `param_1` | Profiler manager (`DAT_00afa27c` at enter/leave) | Enter: `PUSH ESI` (`ESI`=profiler) before both calls |
| return `EAX` | Index into `+0x4c` array | Caller: `LEA EAX,[EAX+EAX*2]` then `*4` → `idx*0xC` |
| CS | `profiler + 0x58` | `EnterCriticalSection` / `LeaveCriticalSection` |

Decompiler labels free `int FUN_007866e0(int)` — matches stack this-passing style used by enter/leave (not ECX-this here).

---

## 4. Layout (sealed)

### 4.1 Profiler manager (`param_1`)

| Offset | Field | Evidence |
|---|---|---|
| `+0x4c` | Thread-slot **begin** | Walk base; empty ⇒ size 0 |
| `+0x50` | Thread-slot **end** | Size = `(end-begin)/0xC` |
| `+0x54` | Capacity end (via append helper) | `FUN_00480ca0` vector `+0xc` if base is `+0x48` |
| `+0x58` | `CRITICAL_SECTION` | Enter/Leave around walk + create |

### 4.2 Thread slot entry (`0xC` bytes)

| Offset | Field | Evidence |
|---|---|---|
| `+0x00` | `DWORD threadId` | Compare to `GetCurrentThreadId` |
| `+0x08` | Current zone node* | Written/read by enter/leave (not written inside hit path here) |

Create path sets current zone to new `"Hermann"` root via `FUN_00480ca0` packing (with `local_10` zone + `local_18` TID).

### 4.3 Root zone on first thread sighting

| Item | Value | Evidence |
|---|---|---|
| Alloc size | `0x5C` | `operator_new(0x5c)` |
| Name | `"Hermann"` @ `0x00a9adc4` | `read_memory` + decompile string |
| Ctor | `FUN_00786280` | Builds map + timer (`FUN_00780730` QPF/1e6) |
| Nest / timer start | Same field ops as `FUN_00785e00` | Inline on create path |

---

## 5. Control flow (sealed)

```
Profiler_EnsureThreadSlot(profiler):
  tid = GetCurrentThreadId()
  EnterCriticalSection(profiler + 0x58)
  n = (profiler->slotEnd - profiler->slotBegin) / 0xC   // 0 if begin==0
  for i in 0..n-1:
    if slot[i].threadId == tid:
      LeaveCriticalSection(...)
      return i
  // miss:
  root = new Zone(0x5c); FUN_00786280(root, "Hermann")
  // inline StartZoneTimer(root)
  AppendSlot(profiler, {tid, ..., root})   // FUN_00480ca0
  n = (end - begin) / 0xC
  LeaveCriticalSection(...)
  return n - 1
```

Live decompile CF matches raw scaffold (while scan + create + return size−1).

---

## 6. Callers (xrefs)

| Site | Function | Role |
|---|---|---|
| `0x00786a14`, `0x00786a39` | `Profiler_EnterNamedZone` | Ensure index before parent load / after push prep |
| `0x0078699f`, `0x007869dc` | `Profiler_Leave` | Ensure index before current load / parent restore |

No other xrefs in bulk query.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CS at `+0x58`; vector `+0x4c/+0x50`; stride `0xC` | **High** | Body + enter/leave math |
| Return = index (hit or new last) | **High** | Hit `return iVar4`; create `return size-1` |
| Match field = TID at entry `+0` | **High** | Direct compare |
| First-seen thread creates `"Hermann"` root zone | **High** | String seal + ctor |
| English product name | **Probable** | Behavior; no PDB |
| Exact `FUN_00480ca0` element layout (`+4` field) | **Med** | Helper uses register ABI; pack order framed |
| Null ctor / OOM paths | **Tentative** | `operator_new` null → `local_14=0` then deref risk unsealed |
| Multi-thread races outside CS | **Open** | CS only around this helper |

---

## 8. Surviving contract (port)

```
// Optional client instrumentation. Server can no-op enter/leave entirely.
int Profiler_EnsureThreadSlot(Profiler* p);
// Returns index into p->threadSlots[stride 0xC]; creates root "Hermann" zone on first TID.
```

---

## 9. Open residual

1. Product class name of manager / zone.
2. Slot field at `+0x04` (if any) full semantics.
3. Whether `"Hermann"` is author watermark vs intentional root label.
4. Runtime proof of CS coverage under concurrent enter/leave.
5. Bit-exact / image diff.

**Verdict:** **accept-with-gaps** — slot ensure CF dual-ready; used only as index factory for enter/leave.
