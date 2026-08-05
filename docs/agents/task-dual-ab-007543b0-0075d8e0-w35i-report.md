# Dual A/B report — W35-I OWN `aa_007543b0` + `aa_0075d8e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-I  
**Scope:** VAs `0x007543b0`, `0x0075d8e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-I).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007543b0` Palantir_BaseCtor | **accept-with-gaps** — stack-self ABI / globals / layout / Palantir class sealed (204 B); nested `FUN_0075d470` dual open |
| `aa_0075d8e0` NDResourceCache_CompleteDtor | **accept-with-gaps** — full 223 B teardown + `DAT_00d1f050` clear sealed (Ghidra body end wrong); nested callees residual |

---

## VA `0x007543b0` — sealed facts

1. **Body:** `0x007543b0`–`0x0075447C` exclusive (**204 B** / `0xCC`; pad `CC` then `FUN_00754480`).
2. **ABI:** **stack=`Palantir* self`** (`MOV ESI,[esp+0x18]`); **`RET 4`**; **EAX=self**. Not ECX-thiscall.
3. **Semantics (base ctor):**
   - `DAT_00d1f058 = self` (host singleton publish).
   - Install vtbl `PTR_FUN_00a9f76c` (Palantir; same family as complete dtor).
   - Flags `+0x04=0`, `+0x05=1`, `+0x06=0`; copy `DAT_00d1f01c`/`DAT_00d1f020` to `+0x08`/`+0x0C`; zero `+0x14..+0x20`.
   - `CoInitializeEx(NULL, 2)` — `COINIT_APARTMENTTHREADED`.
   - `+0x24=-1`; zero `+0x28`/`+0x2C`.
   - `FUN_0075d470(self+0x30)` — NDResourceCache/AssManager host ctor (publishes `DAT_00d1f050`).
   - `DAT_00d1f1fc = self+0xA0`; zero StringVecShell triad.
   - `basic_string` ctor at `+0xB4` with `"."` (`0x00a2e610`).
   - Tail: `+0xD0=1`, `+0xD1=0`, `+0xD4=0`.
4. **Classification:** worker — placement ctor.
5. **Callers (1):** `FUN_007a26c0` @ `0x007a26dc` — extended host ctor; **overwrites** vtbl to `PTR_FUN_00a97170` after return.
6. **Callees:** IAT `CoInitializeEx`, `FUN_0075d470`, IAT `basic_string` ctor.
7. **Name:** `Palantir_BaseCtor` (Ghidra `FUN_007543b0`; **Inferred** + product evidence). Reject scaffold Client_InitInstance chain name.
8. **Pair:** complete dtor `Palantir_CompleteDtor` @ `0x00754320` (W34-K).
9. **Decompile ≢ bytes** on ABI display (`undefined (void)`); **bytes win**. Full hex: raw W35-I append.

### Gaps

- Nested dual for `FUN_0075d470`.  
- `+0x10` subobject only destroyed in complete dtor (not constructed here).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007543b0_Palantir_BaseCtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007543b0_Palantir_BaseCtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.md` |
| Annotated | `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_BaseCtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007543b0.cpp` |
| Function | `docs/reconstruction/functions/aa_007543b0_FUN_007543b0.md` |
| Function named | `docs/reconstruction/functions/aa_007543b0_Palantir_BaseCtor.md` |
| Scratch | `docs/reconstruction/tmp/a_007543b0.md` |

---

## VA `0x0075d8e0` — sealed facts

1. **Body (bytes):** `0x0075d8e0`–`0x0075d9BF` exclusive (**223 B** / `0xDF`; pad `CC` then next @ `0x0075d9c0`).
2. **Ghidra body end `0x0075d955` is wrong** — false **noreturn** on `operator_delete` (`0x00489822`) truncates decompiler and function range. **Bytes win.**
3. **ABI:** **stack=`NDResourceCache* self`** (`MOV EBP,[esp+0x1c]`); **`RET 4`**; void. **Does not** `operator_delete(self)`.
4. **Semantics (complete dtor):**
   - `FUN_0075d6f0` — NestedHash entry teardown (ESI=self).
   - If `self+0x6c` (AssPreloader*): `FUN_00971050` (retire never-loaded; product `assPreloader.cpp`), `FUN_00971180`, `operator_delete`, null slot.
   - Std tree at `+0x58`: `FUN_0043c220` erase-all, free head, null head/size.
   - `DeleteCriticalSection(self+0x3c)`; clear flag `+0x54`.
   - `FUN_0040d9c0` OwnedPtrTable_Clear at `+0x28`.
   - Free optional block `+0x14`; null `+0x14..+0x1C`.
   - `FUN_00415e90` list tidy at `+0x04`; free list head; null `+0x08`.
   - **`DAT_00d1f050 = 0`**.
5. **Classification:** worker.
6. **Callers:** `Palantir_CompleteDtor` @ `0x0075437c` (arg `this+0x30`); Unwind `@009afd03`, `@009afd3f`.
7. **Callees:** `FUN_0075d6f0`, `FUN_00971050`, `FUN_00971180`, `operator_delete`, `FUN_0043c220`, `DeleteCriticalSection`, `FUN_0040d9c0`, `FUN_00415e90`.
8. **Name:** `NDResourceCache_CompleteDtor` (Ghidra `FUN_0075d8e0`; **Inferred** — `DAT_00d1f050` host + AssManager-shaped layout + AssPreloader product path).
9. **Pair ctor:** `FUN_0075d470` (unowned dual).
10. **Decompile ≢ bytes** — stops after first nested free; **bytes win**. Full hex: raw W35-I append.

### Gaps

- Nested duals for `FUN_0075d6f0` / `FUN_00971180` / tree host.  
- Pair ctor `FUN_0075d470` dual open.  
- Exact MSVC demangle / NDResourceCache vs AssManager product English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075d8e0_NDResourceCache_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075d8e0_NDResourceCache_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResourceCache_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075d8e0_FUN_0075d8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0075d8e0_NDResourceCache_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_0075d8e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007543b0` | Port as **Palantir placement base ctor**: stack self, `RET 4`, return self. Publish `DAT_00d1f058`; vtbl `00a9f76c`; `CoInitializeEx(0,2)`; construct cache host at `+0x30`; publish path shell `+0xA0` as `DAT_00d1f1fc`; `basic_string(self+0xB4, ".")`. Do **not** use ECX-thiscall. Extended ctor may replace vtbl after. |
| `0075d8e0` | Port as **NDResourceCache complete dtor** (not scalar): stack self, `RET 4`, no free self. Teardown NestedHash → AssPreloader → tree → CS → OwnedPtrTable → list; clear **`DAT_00d1f050`**. Embedded at **Palantir+0x30**. Do **not** trust Ghidra/decompiler truncated body. |

Shared layout / globals (closes W34-K nested residual for `+0x30`):

| Offset / global | Role |
|-----------------|------|
| `Palantir+0x00` | vtbl (`PTR_FUN_00a9f76c` in base ctor / dtor phase) |
| `Palantir+0x30` | NDResourceCache host → ctor `FUN_0075d470` / dtor **`FUN_0075d8e0`** |
| `Palantir+0xA0` | `StringVecShell` path list (`DAT_00d1f1fc`) |
| `Palantir+0xB4` | `basic_string` |
| `DAT_00d1f058` | Palantir host singleton* (set in base ctor; cleared in complete dtor) |
| `DAT_00d1f1fc` | published path-list shell* |
| `DAT_00d1f050` | NDResourceCache host* (set in nested ctor; cleared in **`0075d8e0`**) |
| Cache `+0x3c` | `CRITICAL_SECTION` |
| Cache `+0x6c` | `AssPreloader*` |

Closes high-mention residual: Palantir base ctor + nested cache complete dtor under AssManager/Palantir teardown (pair with W34-K `Palantir_CompleteDtor`).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ force_decompile on truncated dtor). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence — Palantir from vtbl peer; NDResourceCache/AssPreloader from globals + log path.  
- Avoided bare `undefined4` in clean (used `uint8_t` / explicit structs).
