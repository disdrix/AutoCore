# Dual A/B report — W35-S OWN `aa_0096eec0` + `aa_00996bc0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-S  
**Scope:** VAs `0x0096eec0`, `0x00996bc0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee/caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096eec0` Host34_NestedHash0xC_Singleton_Ctor_Inferred | **accept-with-gaps** — ABI/0x34 layout/NestedHash@0/singleton/once-init/map-register sealed; product English + handler body open |
| `aa_00996bc0` Host54_NestedHash0xC_At28_Ctor_Inferred | **accept-with-gaps** — ABI/0x54 layout/prefix/NestedHash@+0x28/flag+0x50 sealed; product English + unwritten +0x18 open |

---

## VA `0x0096eec0` — sealed facts

1. **Body:** `0x0096eec0`–`0x0096ef6a` exclusive (**170 B** / `0xAA`; pad `CC`).
2. **ABI:** stack **`self*`** placement ctor; **`RET 0x4`**; returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - **`DAT_00d1f04c = self`** (singleton publish).
   - **`FUN_0043fdf0(self)`** — `NestedHash_Ctor_Sentinel0xC_Inferred` at base (W34-F).
   - **`self+0x28 = 1`**, **`+0x2c = 0`**, **`+0x30 = 0`**.
   - Once-init **`DAT_00d1f7e8` bit0**: set **`DAT_00d1f7e4 = &PTR_FUN_00a9ef54`**, **`_atexit(LAB_009c3370)`**.
   - Map insert (bytes): tree **`*DAT_00d1f050 + 0x58`**, key **`0x00d1f7e4`**, value **`{LAB_0096ed30, 0}`** via **`FUN_0043bd40`**.
4. **Size:** sole caller **`operator_new(0x34)`** → host span **0x34**.
5. **Classification:** worker.
6. **Callers (1):** `FUN_0075f7f0` @ `0x0075fa2f` — stores `param_2[0x1d5]`.
7. **Callees:** `FUN_0043fdf0`, `_atexit`, `FUN_0043bd40`.
8. **Name:** `Host34_NestedHash0xC_Singleton_Ctor_Inferred` (Ghidra `FUN_0096eec0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
9. **Decompile ≢ bytes** on map-register setup (tree/key dropped); **bytes win**. NestedHash/flags/epilogue decompile ≡ bytes.  
   Full hex: raw W35-S append (170 B).

### Gaps

- Product/PDB English for host + map value type.  
- Unowned `FUN_0043bd40` full node contract.  
- `LAB_0096ed30` body (code site; not a defined function).  
- Runtime meaning of trailing fields.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host34_NestedHash0xC_Singleton_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096eec0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096eec0_FUN_0096eec0.md` |
| Function named | `docs/reconstruction/functions/aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0096eec0.md` |

---

## VA `0x00996bc0` — sealed facts

1. **Body:** `0x00996bc0`–`0x00996c1e` exclusive (**94 B** / `0x5E`; pad `CC`).
2. **ABI:** stack **`self*`** placement ctor; **`RET 0x4`**; returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - Zero **`+0x00/+0x04/+0x08`**, byte **`+0x0c = 0`**, **`+0x10 = 8`**, **`+0x14 = 0`**.
   - **`+0x18` intentionally unwritten**.
   - Zero **`+0x1c/+0x20/+0x24`**.
   - **`FUN_0043fdf0(self+0x28)`** — NestedHash0xC nested at **+0x28**.
   - **`self+0x50 = 1`**.
4. **Size:** host `FUN_00989cf0` places at **`host+0x14`**, CS at **`host+0x68`** → span **0x54**.
5. **Classification:** worker.
6. **Callers (1):** `FUN_00989cf0` @ `0x00989d1e`.
7. **Callees:** `FUN_0043fdf0` only.
8. **Name:** `Host54_NestedHash0xC_At28_Ctor_Inferred` (Ghidra `FUN_00996bc0`; **Inferred**).
9. **Decompile ≡ bytes** for stores and `RET 4` (dword* index `+0x14` → byte `+0x50`).  
   Full hex: raw W35-S append (94 B).

### Gaps

- Product English for prefix / capacity-8.  
- Intent of unwritten `+0x18`.  
- Outer host `FUN_00989cf0` product role.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00996bc0_FUN_00996bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00996bc0_FUN_00996bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host54_NestedHash0xC_At28_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00996bc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00996bc0_FUN_00996bc0.md` |
| Function named | `docs/reconstruction/functions/aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00996bc0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096eec0` | Port as **placement ctor** (stack this, **RET 4**). Alloc **0x34**. NestedHash0xC at **+0**. Publish singleton `DAT_00d1f04c`. Once-init type-token `DAT_00d1f7e4` + atexit. Register `{LAB_0096ed30,0}` into `*DAT_00d1f050+0x58` keyed by `0x00d1f7e4`. Do **not** invent ECX-thiscall or drop map registration. |
| `00996bc0` | Port as **placement ctor** (stack this, **RET 4**). Span **0x54**. Prefix zeros + **cap 8** at +0x10; **do not write +0x18**. NestedHash0xC at **+0x28**; flag **+0x50=1**. Embed at outer **+0x14**. |
| Pair with | W34-F `NestedHash_Ctor_Sentinel0xC_Inferred` (`0x0043fdf0`); W34-F peer host path `NestedHash_Ctor_Sentinel0x30` via same `FUN_0075f7f0`; unowned `FUN_0043bd40` / `LAB_0096ed30`. |

Shared: both are **NestedHash0xC hosts** (W34-F shell). Differ by embed offset (**+0** vs **+0x28**), span (**0x34** vs **0x54**), and side effects (singleton/type-token/map vs pure prefix+hash).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes wave35 partition W35-S high-mention NestedHash0xC hosts (`FUN_0096eec0` / `FUN_00996bc0` from W34-F caller list).
