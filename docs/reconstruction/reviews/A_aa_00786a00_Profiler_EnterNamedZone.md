# Review A (reconstruction fidelity): `aa_00786a00` Profiler_EnterNamedZone (FUN_00786a00)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786a00` |
| **VA** | `0x00786a00` |
| **Canonical name** | `FUN_00786a00` (Probable: `Profiler_EnterNamedZone`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live assembly seals) |
| **Counterpart** | `reviews/B_aa_00786a00_Profiler_EnterNamedZone.md` |
| **System** | client instrumentation / shared by `missions-progression` (SearchAutoMissions path) |
| **Dual status** | **Present** (A + B; first full dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Profiler named-zone enter** on the global profiler object:

1. If enable flag `*(profiler + 0x175) == 0`, return `0` (no-op; `RET 4`).
2. Resolve **per-thread slot index** via `FUN_007866e0(profiler)` (TID walk / create; CS at `profiler+0x58`; slots stride `0xc` at `profiler+0x4c`).
3. Load **current zone** (stack top) from `*(base + idx*0xc + 8)`.
4. **Lookup or create** child zone by name under that current zone: `FUN_00786470(this=currentZone, name)` → zone node*.
5. **Start QPC timing** on the zone: `FUN_00785e00` with `EAX = zone` (increments nest count, zeros timer fields, stamps `QueryPerformanceCounter`).
6. Re-resolve thread index; **push** zone into slot `+0x8`.
7. Return zone node* (or `0` when disabled).

Paired leave is `FUN_00786990` (pop + accumulate elapsed into zone totals) — **not** owned by this dual.

**Calling convention:** MSVC `__thiscall` — `ECX = profiler*`, stack0 = `const char* name`, callee cleans with **`RET 4`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `ECX` | Profiler singleton (`DAT_00afa27c` at all 4 call sites) | `MOV ESI,ECX`; sites `MOV ECX,[0x00afa27c]` |
| stack0 | Zone name C-string | `PUSH imm32` of string VA before call |
| return `EAX` | Zone node* or `0` | `MOV EAX,EDI` / early `XOR EAX,EAX` |

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00786a00_FUN_00786a00.md` |
| Annotated | `docs/reconstruction/raw/aa_00786a00_FUN_00786a00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00786a00.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00786a00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00786a00_FUN_00786a00.md` |
| Live decompile | Ghidra MCP `decompile_function` @ `0x00786a00` (2026-07-29) |
| Live assembly | Ghidra `disassemble_function` @ `0x00786a00` |
| Call-site asm | `get_assembly_context` on xrefs `00532b85`, `00727634`, `0051b376`, `00520de8` |
| String seal | `read_memory` `@0x009cff4c` → `"CVOGCharacter::SearchAutoMissions"` |
| Callees | `batch_decompile` `0x007866e0`, `0x00786470`, `0x00785e00`, sibling leave `0x00786990` |
| Xrefs | 4 callers: `CVOGCharacter_SearchAutoMissions`, `FUN_00520dc0`, `FUN_0051b350`, `FUN_00727440` |

**Not performed:** `disassemble_bytes` bulk, Launcher, runtime QPC capture, bit-exact diff. Sibling leave dual not in this OWN VA.

---

## 3. Decisive framing (assembly-backed)

### 3.1 Full body (authoritative)

```
00786a00  PUSH ESI
00786a01  MOV ESI, ECX
00786a03  CMP byte ptr [ESI+0x175], 0
00786a0a  JNZ  LAB_enter
00786a0c  XOR EAX, EAX
00786a0e  POP ESI
00786a0f  RET 4

LAB_enter:
00786a12  PUSH EDI
00786a13  PUSH ESI
00786a14  CALL FUN_007866e0          ; idx = EnsureThreadSlot(profiler)
00786a19  MOV ECX, [ESI+0x4c]        ; slot vector base
00786a1c  MOV EDX, [ESP+0xc]         ; name
00786a20  LEA EAX, [EAX+EAX*2]
00786a23  LEA EAX, [ECX+EAX*4]       ; base + idx*12
00786a26  MOV EAX, [EAX+0x8]         ; parent/current zone*
00786a29  PUSH EDX
00786a2a  MOV ECX, EAX
00786a2c  CALL FUN_00786470          ; zone = FindOrCreateChild(parent, name)
00786a31  MOV EDI, EAX
00786a33  CALL FUN_00785e00          ; StartZoneTimer(zone)  ; EAX still zone
00786a38  PUSH ESI
00786a39  CALL FUN_007866e0
00786a3e  MOV ECX, [ESI+0x4c]
00786a41  LEA EAX, [EAX+EAX*2]
00786a44  LEA EAX, [ECX+EAX*4]
00786a47  MOV [EAX+0x8], EDI         ; push zone onto thread stack top
00786a4a  MOV EAX, EDI
00786a4c  POP EDI
00786a4d  POP ESI
00786a4e  RET 4
```

### 3.2 Decompiler residual (must not trust alone)

| Decompiler claim | Live correction | Confidence |
|---|---|---|
| First `FUN_007866e0` return discarded | **Used** to index `slot+0x8` for parent zone | **High** |
| `FUN_00786470(param_2)` with `this = profiler` | **`this = *(slot+0x8)`** (current zone), stack = name | **High** |
| `FUN_00785e00()` free / no arg | **`EAX = zone`** on entry (timer start on node) | **High** |
| Body is mission logic | **Instrumentation only** — SearchAutoMissions just wraps enter/leave around grant scan | **High** |

### 3.3 SearchAutoMissions call site (path context)

```
00532b7a  MOV ECX, [0x00afa27c]     ; profiler*
00532b80  PUSH 0x9cff4c             ; "CVOGCharacter::SearchAutoMissions"
00532b85  CALL 0x00786a00           ; enter
...
00532ba3  MOV ECX, [0x00afa27c]
00532bb1  CALL 0x00786990           ; leave (early null-wrapper path)
```

`read_memory` `@0x009cff4c`: ASCII `CVOGCharacter::SearchAutoMissions\0`.

Other sealed names at call sites:
| Site | String VA | Text |
|------|-----------|------|
| `0x00532b85` | `0x009cff4c` | `CVOGCharacter::SearchAutoMissions` |
| `0x00520de8` | `0x009cf0b0` | `CVOGCharacter::CleanupDraggingObject` |
| `0x0051b376` | `0x009cee68` | `ServerCreateFromPacket` |
| `0x00727634` | `0x00aa91ac` | `UpdateSounds::updateSoundRegions()` |

All use `ECX = [DAT_00afa27c]`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Enable gate `profiler+0x175` (byte, zero = off) | **High** | `CMP byte / JNZ` |
| Thread slots at `+0x4c`, stride `0xc`, current zone at `+0x8` | **High** | `LEA` scale + store |
| `FUN_00786470` this = current zone, not profiler | **High** | `MOV ECX,EAX` from slot load |
| Return zone* / 0 | **High** | Both RET paths |
| Global `DAT_00afa27c` is profiler this | **High** | 4/4 sites |
| Name string is only stack formal | **High** | `RET 4` |
| Hierarchical child map under parent zone | **High** (callee body) | `FUN_00786470` map @ parent `+0x1c/+0x20` |
| English class name “Profiler” | **Probable** | Structure matches zone profiler; no type string in this VA |
| Exact zone node layout beyond timer/nest | **Tentative** | Partial from callees |
| Runtime enable default / shipping builds | **Open** | Flag state not proven here |

---

## 5. Control flow: clean ≡ assembly (after dual fix)

| Stage | Match |
|---|---|
| Gate +0x175 → return 0 | Yes |
| EnsureThreadSlot → load parent @ slot+8 | Yes (annotated/clean corrected; raw decompiler elided parent load) |
| FindOrCreateChild(parent, name) | Yes |
| StartZoneTimer(zone) | Yes |
| Push zone to slot+8; return zone | Yes |

**Raw file** preserves original Ghidra pseudocode (authoritative capture; do not overwrite body). Annotated + clean carry assembly-corrected dataflow.

---

## 6. Gaps / open

1. Full zone-node field map (`+0x4` timer object, nest `+0x3c`, accum `+0x28`, parent link used by leave).
2. Whether `FUN_007866e0` ever reallocates between the two calls in-path (re-lookup is defensive).
3. Shipping `+0x175` default; effect when profiling off (always 0 — call sites ignore return).
4. Sibling leave dual (`aa_00786990`) and map helpers not sealed here.

**Verdict:** **accept-with-gaps**
