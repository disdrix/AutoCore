# Review B (skeptical / adversarial): `aa_00786a00` Profiler_EnterNamedZone (FUN_00786a00)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786a00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00786a00_Profiler_EnterNamedZone.md` |
| **System** | client instrumentation (SearchAutoMissions callee) |
| **Dual status** | **Present** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** on enter spine + ABI; **reject** listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is mission search / auto-grant logic | **Falsified** — only enable-gate, thread slot, zone map, QPC start, push; no mission table |
| 2 | `FUN_00786470` takes profiler as `this` (raw decompiler shape) | **Falsified** — live `MOV ECX, [slot+0x8]` then `CALL 0x00786470` |
| 3 | First `FUN_007866e0` return is dead | **Falsified** — indexes parent zone load before child lookup |
| 4 | Free function with string-only ABI (`FUN_00786a00("…")` as C free) | **Misleading** — still **`thiscall`**; all sites load `DAT_00afa27c` into `ECX` before PUSH name |
| 5 | `RET` without stack cleanup / cdecl | **Falsified** — **`RET 4`** both paths |
| 6 | Enable flag is word/dword at `+0x175` | **Falsified** — **`CMP byte ptr [ESI+0x175], 0`** |
| 7 | Slot stride is 4 or 8 | **Falsified** — `LEA EAX,[EAX+EAX*2]` + `LEA …*4` ⇒ **12 (`0xc`)** |
| 8 | Writes zone at slot base / `+0` | **Falsified** — store **`[base + idx*0xc + 8]`** only |
| 9 | `FUN_00785e00` is unrelated / no operand | **Misleading** — **`EAX` holds zone** into timer start (nest++, clear counters, QPC stamp) |
| 10 | Unique to SearchAutoMissions | **Falsified** — **4 xrefs** (also CleanupDraggingObject, ServerCreateFromPacket, UpdateSounds) |
| 11 | Return value drives SearchAutoMissions CF | **Falsified at call site** — Search ignores return; early leave via `FUN_00786990` on null wrapper |
| 12 | Package is bit-exact / runtime complete | **Fail** — static dual only |

---

## 2. Decisive dataflow (assembly)

```
Profiler_EnterNamedZone(profiler, name):
  if *(u8*)(profiler + 0x175) == 0:
    return 0
  idx = EnsureThreadSlot(profiler)          // FUN_007866e0
  parent = *( *(profiler+0x4c) + idx*12 + 8 )
  zone = FindOrCreateChildZone(parent, name) // FUN_00786470 thiscall
  StartZoneTimer(zone)                       // FUN_00785e00 via EAX
  idx = EnsureThreadSlot(profiler)
  *( *(profiler+0x4c) + idx*12 + 8 ) = zone  // push
  return zone
```

Live decompile CF shape (if/return/calls) matches raw **count**, but **dataflow for parent `this`** is wrong in frozen raw pseudocode — assembly is the seal.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Instrumentation-only (not mission CF) | **High** | Port mission logic into profiler |
| Parent zone = slot+8, not profiler | **High** | Broken hierarchy / wrong map root |
| `RET 4` thiscall + name | **High** | Stack imbalance |
| Gate `+0x175` byte | **High** | Always-on/off wrong |
| Slot stride 0xc / top at +8 | **High** | Corrupt thread table |
| Global this `DAT_00afa27c` | **High** | Wrong object |
| QPC timer start semantics | **High** (callee) | Skew leave accum |
| Exact product name / class | **Probable** | Naming only |
| Nested re-enter same name behavior | **Open** | Map hit returns existing child @+0x28 path in callee |
| Runtime / differential | **Open** | Residual |

---

## 4. Offset / ABI attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x175` enable | Invented? | **No** — `CMP byte [ESI+0x175],0` |
| `+0x4c` vector | Invented? | **No** — `MOV ECX,[ESI+0x4c]` ×2 |
| Stride 0xc | Invented? | **No** — `*2+*4` LEA pair |
| Field +8 current zone | Invented? | **No** — load then store same offset |
| Profiler as 86470 this | From decompiler? | **Rejected** — ECX overwritten from slot |
| String-only free call | From clean comments? | **Rejected** — ECX load at every site |
| Mission side effects inside | From parent name? | **Rejected** — no mission callees |
| Single caller | Inventory xref_count=4 | **Confirmed multi** |

---

## 5. Surviving contract for AutoCore

```
// Client-only instrumentation. Safe to no-op on server ports.
void* Profiler_EnterNamedZone(Profiler* p, const char* name);  // NULL if disabled
// Must pair with Profiler_Leave (FUN_00786990) on same thread when enabled.
// SearchAutoMissions (and peers) use DAT_00afa27c + literal scope strings only.
```

**Porting rule:** Do **not** treat this VA as part of auto-mission eligibility. Do **not** implement from raw decompiler alone — parent zone `this` for the map lookup is mandatory.

---

## 6. Open questions

1. Default value of `+0x175` in retail vs debug images.
2. Whether leave dual `aa_00786990` should share one system doc under `client::profiler`.
3. Thread-slot `+0x0` TID / `+0x4` payload layout (owned by `FUN_007866e0`).

**Verdict:** **accept-with-gaps**
